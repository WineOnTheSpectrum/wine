/*
 * Wayland data device
 *
 * Copyright 2025 Alexandros Frantzis for Collabora Ltd
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
 */

#if 0
#pragma makedep unix
#endif

#include "config.h"

#include <errno.h>
#include <fcntl.h>
#include <poll.h>
#include <stdlib.h>
#include <unistd.h>

#include "waylanddrv.h"
#include "wine/debug.h"

WINE_DEFAULT_DEBUG_CHANNEL(clipboard);

#define WINEWAYLAND_TAG_MIME_TYPE "application/x.winewayland.tag"

struct data_device_format
{
    const char *mime_type;
    UINT clipboard_format;
    const WCHAR *register_name;
    void *(*export)(void *data, size_t size, size_t *ret_size);
    void *(*import)(void *data, size_t size, size_t *ret_size);
};

struct wayland_data_offer
{
    struct wl_data_offer *wl_data_offer;
    struct wl_array types;
};

static HWND desktop_clipboard_hwnd;
static const WCHAR rich_text_formatW[] = {'R','i','c','h',' ','T','e','x','t',' ','F','o','r','m','a','t',0};
static const WCHAR pngW[] = {'P','N','G',0};
static const WCHAR jfifW[] = {'J','F','I','F',0};
static const WCHAR gifW[] = {'G','I','F',0};
static const WCHAR image_svg_xmlW[] = {'i','m','a','g','e','/','s','v','g','+','x','m','l',0};

static HWND get_clipboard_hwnd(void)
{
    if (!desktop_clipboard_hwnd)
    {
        static const WCHAR clipboard_classnameW[] = {
            '_','_','w','i','n','e','_','c','l','i','p','b','o','a','r','d','_',
            'm','a','n','a','g','e','r','\0'};
        UNICODE_STRING clipboard_classnameU;
        RtlInitUnicodeString(&clipboard_classnameU, clipboard_classnameW);

        desktop_clipboard_hwnd =
            NtUserFindWindowEx(HWND_MESSAGE, NULL, &clipboard_classnameU, NULL, 0);
    }

    return desktop_clipboard_hwnd;
}

/* Normalize the MIME type string by skipping inconsequential characters,
 * such as spaces and double quotes, and convert to lower case. */
static const char *normalize_mime_type(const char *mime_type)
{
    char *new_mime_type;
    const char *cur_read;
    char *cur_write;
    size_t new_mime_len = 0;

    for (cur_read = mime_type; *cur_read != '\0'; ++cur_read)
    {
        if (*cur_read != ' ' && *cur_read != '"')
            new_mime_len++;
    }

    new_mime_type = malloc(new_mime_len + 1);
    if (!new_mime_type) return NULL;

    for (cur_read = mime_type, cur_write = new_mime_type; *cur_read != '\0'; ++cur_read)
    {
        if (*cur_read != ' ' && *cur_read != '"')
            *cur_write++ = tolower(*cur_read);
    }

    *cur_write = '\0';

    return new_mime_type;
}

static int poll_until(int fd, int events, ULONG end_time)
{
    struct pollfd pfd = { .fd = fd, .events = events & ~POLLHUP };
    ULONG now = NtGetTickCount();
    int ret = 0;

    while ((now = NtGetTickCount()) < end_time &&
           (ret = poll(&pfd, 1, end_time - now)) == -1 &&
           errno == EINTR)
    {
        continue;
    }

    if (ret <= 0 || !(pfd.revents & events))
    {
        TRACE("Failed polling ret=%d errno=%d revents=0x%x\n",
               ret, ret == -1 ? errno : 0, pfd.revents);
        return ret <= 0 ? ret : -1;
    }

    return ret;
}

static void write_all(int fd, const void *buf, size_t count)
{
    static const ULONG timeout = 500;
    size_t nwritten = 0;
    int flags;
    ULONG end_time;
    ssize_t ret;

    if (((flags = fcntl(fd, F_GETFL, 0)) < 0) ||
        (!(flags & O_NONBLOCK) && fcntl(fd, F_SETFL, flags | O_NONBLOCK) < 0))
    {
        TRACE("Failed to make data source send fd non-blocking, "
              "will not be able to properly enforce write timeout\n");
    }

    end_time = NtGetTickCount() + timeout;
    while (nwritten < count)
    {
        if (poll_until(fd, POLLOUT, end_time) <= 0) break;
        ret = write(fd, (const char*)buf + nwritten, count - nwritten);
        if (ret == -1 && errno != EINTR && errno != EAGAIN && errno != EWOULDBLOCK)
        {
            break;
        }
        else if (ret > 0)
        {
            nwritten += ret;
        }
    }

    if (nwritten < count)
    {
        WARN("Failed to write all clipboard data, had %zu bytes, wrote %zu bytes\n",
             count, nwritten);
    }
}

static void *read_all(int fd, size_t *size_out)
{
    static const ULONG receive_timeout = 500;
    size_t buffer_size = 4096;
    int total = 0;
    unsigned char *buffer;
    int nread;
    ULONG end_time;

    if (!(buffer = malloc(buffer_size)))
    {
        ERR("failed to allocate read buffer\n");
        goto out;
    }

    end_time = NtGetTickCount() + receive_timeout;
    do
    {
        if (poll_until(fd, POLLIN | POLLHUP, end_time) <= 0) goto out;

        nread = read(fd, buffer + total, buffer_size - total);
        if (nread == -1 && errno != EINTR)
        {
            TRACE("failed to read from fd (errno: %d)\n", errno);
            total = 0;
            goto out;
        }
        else if (nread > 0)
        {
            total += nread;
            if (total == buffer_size)
            {
                unsigned char *new_buffer;
                buffer_size *= 2;
                new_buffer = realloc(buffer, buffer_size);
                if (!new_buffer)
                {
                    ERR("failed to reallocate read buffer\n");
                    total = 0;
                    goto out;
                }
                buffer = new_buffer;
            }
        }
    } while (nread > 0);

    TRACE("read %d bytes\n", total);

out:
    if (total == 0 && buffer != NULL)
    {
        free(buffer);
        buffer = NULL;
    }
    *size_out = total;
    return buffer;
}

static void *export_unicode_text(void *data, size_t size, size_t *ret_size)
{
    DWORD byte_count;
    char *bytes;

    /* Wayland apps expect strings to not be zero-terminated, so avoid
     * zero-terminating the resulting converted string. */
    if (size >= sizeof(WCHAR) && ((WCHAR *)data)[size / sizeof(WCHAR) - 1] == 0)
        size -= sizeof(WCHAR);

    RtlUnicodeToUTF8N(NULL, 0, &byte_count, data, size);
    if (!(bytes = malloc(byte_count))) return NULL;
    RtlUnicodeToUTF8N(bytes, byte_count, &byte_count, data, size);

    *ret_size = byte_count;
    return bytes;
}

static void *export_data(void *data, size_t size, size_t *ret_size)
{
    *ret_size = size;
    return data;
}

static void *import_unicode_text(void *data, size_t size, size_t *ret_size)
{
    DWORD wsize;
    WCHAR *ret;

    RtlUTF8ToUnicodeN(NULL, 0, &wsize, data, size);
    if (!(ret = malloc(wsize + sizeof(WCHAR)))) return NULL;
    RtlUTF8ToUnicodeN(ret, wsize, &wsize, data, size);
    ret[wsize / sizeof(WCHAR)] = 0;

    *ret_size = wsize + sizeof(WCHAR);

    return ret;
}

static void *import_data(void *data, size_t size, size_t *ret_size)
{
    *ret_size = size;
    return data;
}

/* Order is important. When selecting a mime-type for a clipboard format we
 * will choose the first entry that matches the specified clipboard format. */
static struct data_device_format supported_formats[] =
{
    {"text/plain;charset=utf-8", CF_UNICODETEXT, NULL, export_unicode_text, import_unicode_text},
    {"text/rtf", 0, rich_text_formatW, export_data, import_data},
    {"image/tiff", CF_TIFF, NULL, export_data, import_data},
    {"image/png", 0, pngW, export_data, import_data},
    {"image/jpeg", 0, jfifW, export_data, import_data},
    {"image/gif", 0, gifW, export_data, import_data},
    {"image/svg+xml", 0, image_svg_xmlW, export_data, import_data},
    {"application/x-riff", CF_RIFF, NULL, export_data, import_data},
    {"audio/wav", CF_WAVE, NULL, export_data, import_data},
    {"audio/x-wav", CF_WAVE, NULL, export_data, import_data},
    {NULL, 0, NULL},
};

static BOOL string_array_contains(struct wl_array *array, const char *str)
{
    char **p;

    wl_array_for_each(p, array)
        if (!strcmp(*p, str)) return TRUE;

    return FALSE;
}

static struct data_device_format *data_device_format_for_clipboard_format(UINT clipboard_format,
                                                                          struct wl_array *types)
{
    struct data_device_format *format;

    for (format = supported_formats; format->mime_type; ++format)
    {
        if (format->clipboard_format == clipboard_format &&
            (!types || string_array_contains(types, format->mime_type)))
        {
            return format;
        }
    }

    return NULL;
}

static struct data_device_format *data_device_format_for_mime_type(const char *mime)
{
    struct data_device_format *format;

    for (format = supported_formats; format->mime_type; ++format)
    {
        if (!strcmp(mime, format->mime_type)) return format;
    }

    return NULL;
}

static ATOM register_clipboard_format(const WCHAR *name)
{
    ATOM atom;
    if (NtAddAtom(name, lstrlenW(name) * sizeof(WCHAR), &atom)) return 0;
    return atom;
}

/**********************************************************************
 *          wl_data_source handling
 */

static void wayland_data_source_export(struct data_device_format *format, int fd)
{
    struct get_clipboard_params params = { .data_only = TRUE };
    static const size_t buffer_size = 1024;
    HWND clipboard_hwnd = get_clipboard_hwnd();
    void *buffer, *exported = NULL;
    size_t exported_size;

    if (!clipboard_hwnd) return;
    if (!(buffer = malloc(buffer_size))) return;
    if (!NtUserOpenClipboard(clipboard_hwnd, 0))
    {
        TRACE("failed to open clipboard for export\n");
        free(buffer);
        return;
    }

    params.data = buffer;
    params.size = buffer_size;
    if (NtUserGetClipboardData(format->clipboard_format, &params))
    {
        exported = format->export(params.data, params.size, &exported_size);
    }
    else if (params.data_size)
    {
        /* If 'buffer_size' is too small, NtUserGetClipboardData writes the
         * minimum size in 'params.data_size', so we retry with that. */
        void *new_buffer = realloc(buffer, params.data_size);
        if (new_buffer)
        {
            buffer = new_buffer;
            params.data = new_buffer;
            if (NtUserGetClipboardData(format->clipboard_format, &params))
                exported = format->export(params.data, params.size, &exported_size);
        }
    }

    NtUserCloseClipboard();
    if (exported) write_all(fd, exported, exported_size);

    if (exported != buffer) free(exported);
    free(buffer);
}

static void data_source_target(void *data, struct wl_data_source *source,
                               const char *mime_type)
{
}

static void data_source_send(void *data, struct wl_data_source *source,
                             const char *mime_type, int32_t fd)
{
    struct data_device_format *format;
    const char *normalized;

    if ((normalized = normalize_mime_type(mime_type)) &&
        (format = data_device_format_for_mime_type(normalized)))
    {
        wayland_data_source_export(format, fd);
    }
    close(fd);
}

static void data_source_cancelled(void *data, struct wl_data_source *source)
{
    struct wayland_data_device *data_device = data;

    pthread_mutex_lock(&data_device->mutex);
    wl_data_source_destroy(source);
    if (source == data_device->wl_data_source)
        data_device->wl_data_source = NULL;
    pthread_mutex_unlock(&data_device->mutex);
}

static void data_source_dnd_drop_performed(void *data,
                                           struct wl_data_source *source)
{
}

static void data_source_dnd_finished(void *data, struct wl_data_source *source)
{
}

static void data_source_action(void *data, struct wl_data_source *source,
                               uint32_t dnd_action)
{
}

static const struct wl_data_source_listener data_source_listener =
{
    data_source_target,
    data_source_send,
    data_source_cancelled,
    data_source_dnd_drop_performed,
    data_source_dnd_finished,
    data_source_action,
};

/**********************************************************************
 *          wl_data_offer handling
 */

static void data_offer_offer(void *data, struct wl_data_offer *wl_data_offer,
                             const char *type)
{
    struct wayland_data_offer *data_offer = data;
    const char *normalized;
    const char **p;

    if ((normalized = normalize_mime_type(type)) &&
        (p = wl_array_add(&data_offer->types, sizeof *p)))
    {
        *p = normalized;
    }
}

static void data_offer_source_actions(void *data,
                                      struct wl_data_offer *wl_data_offer,
                                      uint32_t source_actions)
{
}

static void data_offer_action(void *data, struct wl_data_offer *wl_data_offer,
                              uint32_t dnd_action)
{
}

static const struct wl_data_offer_listener data_offer_listener =
{
    data_offer_offer,
    data_offer_source_actions,
    data_offer_action
};

static void wayland_data_offer_create(struct wl_data_offer *wl_data_offer)
{
    struct wayland_data_offer *data_offer;

    if (!(data_offer = calloc(1, sizeof(*data_offer))))
    {
        ERR("Failed to allocate memory for data offer\n");
        return;
    }

    data_offer->wl_data_offer = wl_data_offer;
    wl_array_init(&data_offer->types);
    wl_data_offer_add_listener(data_offer->wl_data_offer,
                               &data_offer_listener, data_offer);
}

static void wayland_data_offer_destroy(struct wayland_data_offer *data_offer)
{
    char **p;

    wl_data_offer_destroy(data_offer->wl_data_offer);
    wl_array_for_each(p, &data_offer->types)
        free(*p);
    wl_array_release(&data_offer->types);
    free(data_offer);
}

static int wayland_data_offer_get_import_fd(struct wayland_data_offer *data_offer,
                                            const char *mime_type)
{
    int data_pipe[2];

#if HAVE_PIPE2
    if (pipe2(data_pipe, O_CLOEXEC) == -1)
#endif
    {
        if (pipe(data_pipe) == -1)
        {
            ERR("failed to create clipboard data pipe\n");
            return -1;
        }
        fcntl(data_pipe[0], F_SETFD, FD_CLOEXEC);
        fcntl(data_pipe[1], F_SETFD, FD_CLOEXEC);
    }

    wl_data_offer_receive(data_offer->wl_data_offer, mime_type, data_pipe[1]);
    close(data_pipe[1]);

    /* Flush to ensure our receive request reaches the server. */
    wl_display_flush(process_wayland.wl_display);

    return data_pipe[0];
}

static void *import_format(int fd, struct data_device_format *format, size_t *ret_size)
{
    size_t size;
    void *data, *ret;

    if (!(data = read_all(fd, &size))) return NULL;
    ret = format->import(data, size, ret_size);
    if (ret != data) free(data);
    return ret;
}

/**********************************************************************
 *          wl_data_device handling
 */

static void wayland_data_device_destroy_clipboard_data_offer(struct wayland_data_device *data_device)
{
    if (data_device->clipboard_wl_data_offer)
    {
        struct wayland_data_offer *data_offer =
            wl_data_offer_get_user_data(data_device->clipboard_wl_data_offer);
        if (data_offer) wayland_data_offer_destroy(data_offer);
        data_device->clipboard_wl_data_offer = NULL;
    }
}

static void data_device_data_offer(void *data,
                                   struct wl_data_device *wl_data_device,
                                   struct wl_data_offer *wl_data_offer)
{
    wayland_data_offer_create(wl_data_offer);
}

static void data_device_enter(void *data, struct wl_data_device *wl_data_device,
                              uint32_t serial, struct wl_surface *wl_surface,
                              wl_fixed_t x_w, wl_fixed_t y_w,
                              struct wl_data_offer *wl_data_offer)
{
}

static void data_device_leave(void *data, struct wl_data_device *wl_data_device)
{
}

static void data_device_motion(void *data, struct wl_data_device *wl_data_device,
                               uint32_t time, wl_fixed_t x_w, wl_fixed_t y_w)
{
}

static void data_device_drop(void *data, struct wl_data_device *wl_data_device)
{
}

static void data_device_selection(void *data,
                                  struct wl_data_device *wl_data_device,
                                  struct wl_data_offer *wl_data_offer)
{
    struct wayland_data_device *data_device = data;
    struct wayland_data_offer *data_offer = NULL;
    HWND clipboard_hwnd = get_clipboard_hwnd();
    char **p;

    if (!clipboard_hwnd) return;

    if (!wl_data_offer ||
        !(data_offer = wl_data_offer_get_user_data(wl_data_offer)))
    {
        if (NtUserGetClipboardOwner() == clipboard_hwnd)
        {
            TRACE("null offer, clearing clipboard owned by native app\n");
            NtUserOpenClipboard(clipboard_hwnd, 0);
            NtUserEmptyClipboard();
            NtUserCloseClipboard();
        }
        else
        {
            /* We can't tell if the null data offer is triggered by a native
             * app or another win32 app shutting down while acting as the Wine
             * clipboard data source, so play it safe by assuming the second
             * case and becoming the new Wine clipboard data source. */
            TRACE("null offer, updating clipboard owned by win32 app\n");
            wayland_data_device_clipboard_update();
        }
        goto done;
    }

    /* If this offer contains the special winewayland tag mime-type, it was sent
     * by a winewayland process to notify external wayland clients about a Wine
     * clipboard update. */
    wl_array_for_each(p, &data_offer->types)
    {
        if (!strcmp(*p, WINEWAYLAND_TAG_MIME_TYPE))
        {
            TRACE("offer sent by winewayland, ignoring\n");
            wayland_data_offer_destroy(data_offer);
            data_offer = NULL;
            goto done;
        }
    }

    if (!NtUserOpenClipboard(clipboard_hwnd, 0))
    {
        TRACE("failed to open clipboard for selection\n");
        wayland_data_offer_destroy(data_offer);
        data_offer = NULL;
        goto done;
    }

    NtUserEmptyClipboard();

    /* For each mime type, mark that we have available clipboard data. */
    wl_array_for_each(p, &data_offer->types)
    {
        struct data_device_format *format = data_device_format_for_mime_type(*p);
        if (format)
        {
            struct set_clipboard_params params = {0};
            TRACE("Available clipboard format for %s => %u\n",
                  *p, format->clipboard_format);
            NtUserSetClipboardData(format->clipboard_format, 0, &params);
        }
    }

    NtUserCloseClipboard();

done:
    pthread_mutex_lock(&data_device->mutex);
    wayland_data_device_destroy_clipboard_data_offer(data_device);
    if (data_offer) data_device->clipboard_wl_data_offer = wl_data_offer;
    pthread_mutex_unlock(&data_device->mutex);
}

static const struct wl_data_device_listener data_device_listener =
{
    data_device_data_offer,
    data_device_enter,
    data_device_leave,
    data_device_motion,
    data_device_drop,
    data_device_selection,
};

void wayland_data_device_init(void)
{
    struct wayland_data_device *data_device = &process_wayland.data_device;
    struct data_device_format *format = supported_formats;

    pthread_mutex_lock(&data_device->mutex);
    data_device->wl_data_device =
        wl_data_device_manager_get_data_device(process_wayland.wl_data_device_manager,
                                               process_wayland.seat.wl_seat);
    wl_data_device_add_listener(data_device->wl_data_device, &data_device_listener,
                                data_device);
    pthread_mutex_unlock(&data_device->mutex);

    for (; format->mime_type; ++format)
    {
        if (format->clipboard_format == 0)
            format->clipboard_format = register_clipboard_format(format->register_name);
    }
}

void wayland_data_device_deinit(void)
{
    struct wayland_data_device *data_device = &process_wayland.data_device;

    pthread_mutex_lock(&data_device->mutex);
    if (wl_data_device_get_version(data_device->wl_data_device) < 2)
        wl_data_device_destroy(data_device->wl_data_device);
    else
        wl_data_device_release(data_device->wl_data_device);

    data_device->wl_data_device = NULL;
    pthread_mutex_unlock(&data_device->mutex);
}

void wayland_data_device_clipboard_update(void)
{
    struct wayland_data_device *data_device = &process_wayland.data_device;
    uint32_t enter_serial = process_wayland.keyboard.enter_serial;
    HWND clipboard_hwnd = get_clipboard_hwnd();
    struct wl_data_source *source;
    UINT clipboard_format = 0;

    TRACE("\n");

    if (!clipboard_hwnd) return;

    pthread_mutex_lock(&process_wayland.keyboard.mutex);
    enter_serial = process_wayland.keyboard.enter_serial;
    pthread_mutex_unlock(&process_wayland.keyboard.mutex);
    if (!enter_serial) return;

    if (!NtUserOpenClipboard(clipboard_hwnd, 0))
    {
        TRACE("failed to open clipboard for update\n");
        return;
    }

    source = wl_data_device_manager_create_data_source(process_wayland.wl_data_device_manager);
    if (!source)
    {
        ERR("failed to create data source\n");
        return;
    }

    while ((clipboard_format = NtUserEnumClipboardFormats(clipboard_format)))
    {
        struct data_device_format *format =
            data_device_format_for_clipboard_format(clipboard_format, NULL);
        if (format) wl_data_source_offer(source, format->mime_type);
    }

    /* Mark this data source with our special mime type, so we can detect it's
     * coming from us. */
    wl_data_source_offer(source, WINEWAYLAND_TAG_MIME_TYPE);

    wl_data_source_add_listener(source, &data_source_listener, data_device);
    pthread_mutex_lock(&data_device->mutex);
    if (data_device->wl_data_device)
        wl_data_device_set_selection(data_device->wl_data_device, source, enter_serial);
    /* Destroy any previous source only after setting the new source, to
     * avoid spurious 'selection(nil)' events. */
    if (data_device->wl_data_source)
        wl_data_source_destroy(data_device->wl_data_source);
    data_device->wl_data_source = source;
    pthread_mutex_unlock(&data_device->mutex);

    NtUserCloseClipboard();
}

void wayland_data_device_render_format(UINT clipboard_format)
{
    struct wayland_data_device *data_device = &process_wayland.data_device;
    struct wayland_data_offer *data_offer;
    struct data_device_format *format;
    int import_fd = -1;

    pthread_mutex_lock(&data_device->mutex);
    if (data_device->clipboard_wl_data_offer &&
        (data_offer = wl_data_offer_get_user_data(data_device->clipboard_wl_data_offer)) &&
        (format = data_device_format_for_clipboard_format(clipboard_format,
                                                          &data_offer->types)))
    {
        import_fd = wayland_data_offer_get_import_fd(data_offer, format->mime_type);
    }
    pthread_mutex_unlock(&data_device->mutex);

    if (import_fd >= 0)
    {
        struct set_clipboard_params params = {0};
        if ((params.data = import_format(import_fd, format, &params.size)))
        {
            NtUserSetClipboardData(format->clipboard_format, 0, &params);
            free(params.data);
        }
        close(import_fd);
    }
}

void wayland_data_device_destroy_clipboard(void)
{
    struct wayland_data_device *data_device = &process_wayland.data_device;

    pthread_mutex_lock(&data_device->mutex);
    wayland_data_device_destroy_clipboard_data_offer(data_device);
    pthread_mutex_unlock(&data_device->mutex);
}

LRESULT WAYLAND_ClipboardWindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
    switch (msg)
    {
    case WM_NCCREATE:
        NtUserAddClipboardFormatListener(hwnd);
        desktop_clipboard_hwnd = hwnd;
        return TRUE;
    case WM_CLIPBOARDUPDATE:
        if (NtUserGetClipboardOwner() == desktop_clipboard_hwnd) break;
        send_message_timeout(NtUserGetForegroundWindow(),
                             WM_WAYLAND_CLIPBOARD_UPDATE, 0, 0,
                             SMTO_ABORTIFHUNG, 5000, NULL);
        break;
    case WM_RENDERFORMAT:
        send_message_timeout(NtUserGetForegroundWindow(),
                             WM_WAYLAND_RENDER_FORMAT, wparam, 0,
                             SMTO_ABORTIFHUNG, 5000, NULL);
        break;
    case WM_DESTROYCLIPBOARD:
        send_message_timeout(NtUserGetForegroundWindow(),
                             WM_WAYLAND_DESTROY_CLIPBOARD, wparam, 0,
                             SMTO_ABORTIFHUNG, 5000, NULL);
        break;
    }

    return NtUserMessageCall(hwnd, msg, wparam, lparam, NULL,
                             NtUserDefWindowProc, FALSE);
}
