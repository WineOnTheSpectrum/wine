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

#include "waylanddrv.h"

void wayland_data_device_init(void)
{
    struct wayland_data_device *data_device = &process_wayland.data_device;

    data_device->wl_data_device =
        wl_data_device_manager_get_data_device(process_wayland.wl_data_device_manager,
                                               process_wayland.seat.wl_seat);
}

void wayland_data_device_deinit(void)
{
    struct wayland_data_device *data_device = &process_wayland.data_device;

    if (wl_data_device_get_version(data_device->wl_data_device) < 2)
        wl_data_device_destroy(data_device->wl_data_device);
    else
        wl_data_device_release(data_device->wl_data_device);

    data_device->wl_data_device = NULL;
}
