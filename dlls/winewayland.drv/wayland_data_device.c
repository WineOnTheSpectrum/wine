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

struct data_device_format
{
    const char *mime_type;
    UINT clipboard_format;
    void *(*export)(void *data, size_t size, size_t *ret_size);
};

static HWND desktop_clipboard_hwnd;

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

static int poll_until(int fd, int events, ULONG end_time)
{
    struct pollfd pfd = { .fd = fd, .events = events };
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

/* Order is important. When selecting a mime-type for a clipboard format we
 * will choose the first entry that matches the specified clipboard format. */
static struct data_device_format supported_formats[] =
{
    {"text/plain;charset=utf-8", CF_UNICODETEXT, export_unicode_text},
    {NULL, 0, NULL},
};

static struct data_device_format *data_device_format_for_clipboard_format(UINT clipboard_format)
{
    struct data_device_format *format;

    for (format = supported_formats; format->mime_type; ++format)
    {
        if (format->clipboard_format == clipboard_format) return format;
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
    struct data_device_format *format =
        data_device_format_for_mime_type(mime_type);

    if (format) wayland_data_source_export(format, fd);
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

void wayland_data_device_init(void)
{
    struct wayland_data_device *data_device = &process_wayland.data_device;

    pthread_mutex_lock(&data_device->mutex);
    data_device->wl_data_device =
        wl_data_device_manager_get_data_device(process_wayland.wl_data_device_manager,
                                               process_wayland.seat.wl_seat);
    pthread_mutex_unlock(&data_device->mutex);
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
            data_device_format_for_clipboard_format(clipboard_format);
        if (format) wl_data_source_offer(source, format->mime_type);
    }

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

LRESULT WAYLAND_ClipboardWindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
    switch (msg)
    {
    case WM_NCCREATE:
        NtUserAddClipboardFormatListener(hwnd);
        desktop_clipboard_hwnd = hwnd;
        return TRUE;
    case WM_CLIPBOARDUPDATE:
        send_message_timeout(NtUserGetForegroundWindow(),
                             WM_WAYLAND_CLIPBOARD_UPDATE, 0, 0,
                             SMTO_ABORTIFHUNG, 5000, NULL);
        break;
    }

    return NtUserMessageCall(hwnd, msg, wparam, lparam, NULL,
                             NtUserDefWindowProc, FALSE);
}
