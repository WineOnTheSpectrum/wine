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

winewayland_u_af_64 = static_library('winewayland_u_64', [headers, wayland_h, wayland_c, src],
    include_directories : [config_h_inc, incdir, '.'],
    c_args : ['-DWINE_UNIX_LIB', '-Idlls/winewayland.drv/winewayland.drv.so.p'] + extra_flags_64,
    native : true,
    pic : true,
    build_by_default : true,
)

winewayland_u_o_64 = winewayland_u_af_64.extract_all_objects(recursive : true)

winewayland_so_64 = shared_library('winewayland', [],
    name_prefix : '',
    objects : [winewayland_u_o_64],
    c_args : ['-Wl,-Bsymbolic', '-Wl,-z,defs'],
    dependencies : [waylandclient, waylandegl, xkbcommon, xkbregistry, pthread, libm],
    link_with : [ntdll_so_64, win32u_so_64],
    native : true,
    build_by_default : true,
)

winewayland_w_af_64 = static_library('winewayland_w_af_64', [headers, w_src],
    include_directories : [config_h_inc, incdir, '.'],
    c_args : ['-Idlls/winewayland.drv/winewayland_w_af_64.a.p'] + extra_args + extra_flags_64,
    native : false,
    pic : true,
    build_by_default : true,
)

winewayland_w_o_64 = winewayland_w_af_64.extract_all_objects(recursive : true)

winewayland_drv_64 = custom_target('winewayland_drv_64',
    input : [
        'winewayland.drv.spec',
        winewayland_w_o_64,
        res,
        winecrt0_64,
        ucrtbase_64,
        kernel32_64,
        ntdll_64,
    ],
    output : 'winewayland.drv',
    command : [
        winegcc_bin,
        '-o', '@OUTPUT@',
        '--wine-objdir', '.',
        '-b', 'x86_64-w64-mingw32',
        '-Wl,--wine-builtin',
        '-shared',
        '@INPUT@',
    ],
    build_by_default : meson.is_cross_build(),
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
