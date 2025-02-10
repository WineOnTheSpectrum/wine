/*
 * In-process synchronization primitives
 *
 * Copyright (C) 2021-2022 Elizabeth Figura for CodeWeavers
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

#include "config.h"

#include <assert.h>
#include <stdint.h>
#include <stdio.h>

#include "ntstatus.h"
#define WIN32_NO_STATUS
#include "winternl.h"

#include "file.h"
#include "handle.h"
#include "request.h"
#include "thread.h"

#ifdef HAVE_LINUX_NTSYNC_H
# include <linux/ntsync.h>
#endif

#ifdef NTSYNC_IOC_EVENT_READ

#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <unistd.h>

struct linux_device
{
    struct object obj;      /* object header */
    struct fd *fd;          /* fd for unix fd */
};

static struct object *linux_device_object;

static void linux_device_dump( struct object *obj, int verbose );
static struct fd *linux_device_get_fd( struct object *obj );
static void linux_device_destroy( struct object *obj );
static enum server_fd_type inproc_sync_get_fd_type( struct fd *fd );

static const struct object_ops linux_device_ops =
{
    sizeof(struct linux_device),        /* size */
    &no_type,                           /* type */
    linux_device_dump,                  /* dump */
    no_add_queue,                       /* add_queue */
    NULL,                               /* remove_queue */
    NULL,                               /* signaled */
    NULL,                               /* satisfied */
    no_signal,                          /* signal */
    linux_device_get_fd,                /* get_fd */
    default_map_access,                 /* map_access */
    default_get_sd,                     /* get_sd */
    default_set_sd,                     /* set_sd */
    no_get_full_name,                   /* get_full_name */
    no_lookup_name,                     /* lookup_name */
    no_link_name,                       /* link_name */
    NULL,                               /* unlink_name */
    no_open_file,                       /* open_file */
    no_kernel_obj_list,                 /* get_kernel_obj_list */
    no_close_handle,                    /* close_handle */
    linux_device_destroy                /* destroy */
};

static const struct fd_ops inproc_sync_fd_ops =
{
    default_fd_get_poll_events,     /* get_poll_events */
    default_poll_event,             /* poll_event */
    inproc_sync_get_fd_type,        /* get_fd_type */
    no_fd_read,                     /* read */
    no_fd_write,                    /* write */
    no_fd_flush,                    /* flush */
    no_fd_get_file_info,            /* get_file_info */
    no_fd_get_volume_info,          /* get_volume_info */
    no_fd_ioctl,                    /* ioctl */
    default_fd_cancel_async,        /* cancel_async */
    no_fd_queue_async,              /* queue_async */
    default_fd_reselect_async       /* reselect_async */
};

static void linux_device_dump( struct object *obj, int verbose )
{
    struct linux_device *device = (struct linux_device *)obj;
    assert( obj->ops == &linux_device_ops );
    fprintf( stderr, "In-process synchronization device fd=%p\n", device->fd );
}

static struct fd *linux_device_get_fd( struct object *obj )
{
    struct linux_device *device = (struct linux_device *)obj;
    return (struct fd *)grab_object( device->fd );
}

static void linux_device_destroy( struct object *obj )
{
    struct linux_device *device = (struct linux_device *)obj;
    assert( obj->ops == &linux_device_ops );
    if (device->fd) release_object( device->fd );
    linux_device_object = NULL;
}

static enum server_fd_type inproc_sync_get_fd_type( struct fd *fd )
{
    return FD_TYPE_FILE;
}

static struct linux_device *get_linux_device(void)
{
    struct linux_device *device;
    int unix_fd;

    if (linux_device_object)
        return (struct linux_device *)grab_object( linux_device_object );

    unix_fd = open( "/dev/ntsync", O_CLOEXEC | O_RDONLY );
    if (unix_fd == -1)
    {
        file_set_error();
        return NULL;
    }

    if (!(device = alloc_object( &linux_device_ops )))
    {
        close( unix_fd );
        return NULL;
    }

    if (!(device->fd = create_anonymous_fd( &inproc_sync_fd_ops, unix_fd, &device->obj, 0 )))
    {
        release_object( device );
        return NULL;
    }
    allow_fd_caching( device->fd );

    linux_device_object = grab_object( device );
    make_object_permanent( linux_device_object );
    return device;
}

#endif


DECL_HANDLER(get_linux_sync_device)
{
#ifdef NTSYNC_IOC_EVENT_READ
    struct linux_device *device;

    if ((device = get_linux_device()))
    {
        reply->handle = alloc_handle_no_access_check( current->process, device, 0, 0 );
        release_object( device );
    }
#else
    set_error( STATUS_NOT_IMPLEMENTED );
#endif
}
