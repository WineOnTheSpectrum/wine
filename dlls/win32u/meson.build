#EXTRADEFS = -D_WIN32U_
#MODULE    = win32u.dll
#UNIXLIB   = win32u.so
#IMPORTLIB = win32u
#IMPORTS   = ntdll
#UNIX_CFLAGS  = $(FREETYPE_CFLAGS) $(FONTCONFIG_CFLAGS)
#UNIX_LIBS    = $(CARBON_LIBS) $(APPKIT_LIBS) $(PTHREAD_LIBS) -lm
#
#EXTRADLLFLAGS = -nodefaultlibs

w_src = files(
    'main.c',
)

u_src = files(
    'bitblt.c',
    'bitmap.c',
    'brush.c',
    'class.c',
    'clipboard.c',
    'clipping.c',
    'cursoricon.c',
    'd3dkmt.c',
    'dc.c',
    'dce.c',
    'defwnd.c',
    'dib.c',
    'dibdrv/bitblt.c',
    'dibdrv/dc.c',
    'dibdrv/graphics.c',
    'dibdrv/objects.c',
    'dibdrv/opengl.c',
    'dibdrv/primitives.c',
    'driver.c',
    'emfdrv.c',
    'font.c',
    'freetype.c',
    'gdiobj.c',
    'hook.c',
    'imm.c',
    'input.c',
    'mapping.c',
    'menu.c',
    'message.c',
    'opentype.c',
    'painting.c',
    'palette.c',
    'path.c',
    'pen.c',
    'printdrv.c',
    'rawinput.c',
    'region.c',
    'scroll.c',
    'spy.c',
    'syscall.c',
    'sysparams.c',
    'systray.c',
    'vertical.c',
    'vulkan.c',
    'window.c',
    'winstation.c',
)

win32u_w_af_64 = static_library('win32u_w_af_64', [headers, w_src],
    include_directories : [config_h_inc, incdir, '.'],
    c_args : extra_flags_64 + ['-D_MSVCR_VER=0', '-D_WIN32U_'],
    native : false,
    build_by_default : meson.is_cross_build(),
)

win32u_w_o_64 = win32u_w_af_64.extract_all_objects(recursive : true)

win32u_64 = custom_target('win32u_64',
    input : ['win32u.spec', win32u_w_o_64],
    output : 'libwin32u_64.a',
    command : [
      winebuild_bin,
      '-w', '--implib', '-o', '@OUTPUT@',
      '-m64',
      '--export',
      '@INPUT@',
    ],
    depends : winebuild_bin,
    build_by_default : meson.is_cross_build(),
)

win32u_u_64 = static_library('win32u_u_64', [headers, u_src],
    include_directories : [config_h_inc, incdir, '.'],
    c_args : ['-D_WIN32U_', '-DWINE_UNIX_LIB'],
    dependencies : [freetype2, pthread, libm],
    native : true,
    build_by_default : not meson.is_cross_build(),
)

custom_target('win32u_64.dll',
    output : 'win32u_64.dll',
    input : [
        'win32u.spec', win32u_w_o_64,
        ntdll_64, winecrt0_64,
    ],
    command : [
	winegcc_bin,
	'-o', '@OUTPUT@',
	'--wine-objdir', '.',
	'-b', 'x86_64-w64-mingw32',
	'-Wl,--wine-builtin',
	'-shared',
	'-nodefaultlibs',
	'@INPUT@',
    ],
    depends : winegcc_bin,
    build_by_default : meson.is_cross_build(),
)
