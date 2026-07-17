#UNIX_CFLAGS = $(EGL_CFLAGS) $(WAYLAND_CLIENT_CFLAGS) $(WAYLAND_EGL_CFLAGS) $(XKBCOMMON_CFLAGS) $(XKBREGISTRY_CFLAGS)
#UNIX_LIBS = -lwin32u $(WAYLAND_CLIENT_LIBS) $(WAYLAND_EGL_LIBS) $(XKBCOMMON_LIBS) $(XKBREGISTRY_LIBS) $(PTHREAD_LIBS) -lm

src = files( 
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

# XXX compile this?
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

winewayland_so_64 = shared_library('winewayland.drv', [headers, wayland_h, wayland_c, src],
    name_prefix : '',
    include_directories : [config_h_inc, incdir, '.'],
    c_args : ['-DWINE_UNIX_LIB', '-D__WINESRC__', '-Idlls/winewayland.drv/winewayland.drv.so.p'],
    dependencies : [egl, waylandegl, waylandclient, xkbcommon, xkbregistry, pthread, libm],
    link_with : [win32u_so_64, ntdll_so_64],
    native : true,
    build_by_default : true,
)

custom_target('winewayland_64_symlink',
    input : [],
    output : 'x86_64-windows',
    command : [
      sh,
      '-c',
      'cd dlls/winewayland.drv && ln -sf . x86_64-windows && cd ../..',
    ],
    build_by_default : meson.is_cross_build(),
)
