u_src = files( 
    'display.c',
    'opengl.c',
    'vulkan.c',
    'wayland.c',
    'wayland_data_device.c',
    'wayland_keyboard.c',
    'wayland_output.c',
    'wayland_pointer.c',
    'wayland_surface.c',
    'wayland_text_input.c',
    'waylanddrv_main.c',
    'window.c',
    'window_surface.c',
)

w_src = files(
    'dllmain.c',
)

wayland_xml = files(
    'pointer-constraints-unstable-v1.xml',
    'relative-pointer-unstable-v1.xml',
    'text-input-unstable-v3.xml',
    'viewporter.xml',
    'wlr-data-control-unstable-v1.xml',
    'xdg-output-unstable-v1.xml',
    'xdg-shell.xml',
)

wayland_c = gen_wayland_xml_c.process(wayland_xml)
wayland_h = gen_wayland_xml_h.process(wayland_xml)

rc = files(
    'version.rc',
)

extra_args = [
    '-I../include/msvcrt',
    '-D_UCRT',
    '-D__WINESRC__',
]

res = gen_rc_res.process(rc, extra_args : extra_args)

dlls += {
    'winewayland' : {
        'idl_h' : [],
        'idl_c' : [],
        'src' : w_src,
        'res' : res,
        'extra_args' : extra_args,
        'obj' : [],
        'deps': [
            'winecrt0',
            'ucrtbase',
            'kernel32',
            'ntdll',
        ],
        'so' : {
            'src' : [wayland_h, wayland_c, u_src],
            'extra_args' : [],
            'deps' : [
                waylandclient,
                waylandegl,
                xkbcommon,
                xkbregistry,
                pthread,
                libm,
            ],
            'link' : [
                'ntdll_so',
                'win32u_so',
            ],
        },
        'drv' : true,
    }
}
