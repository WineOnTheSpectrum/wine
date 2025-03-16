#MODULE    = winspool.drv
#UNIXLIB   = winspool.so
#IMPORTLIB = winspool
#IMPORTS   = user32 gdi32 advapi32 compstui
#UNIX_CFLAGS  = $(CUPS_CFLAGS)
#UNIX_LIBS    = $(APPLICATIONSERVICES_LIBS)

rc = files(
    'winspool.rc',
)

rc_extra_args = [
    '-D_UCRT',
]

winspool_res = gen_rc_res.process(rc, extra_args : rc_extra_args)

u_src = files(
    'cups.c',
)

w_src = files(
    'info.c',
    'wspool.c',
)

winspool_w_af_64 = static_library('winspool_w_af_64', [headers, w_src],
    include_directories : [config_h_inc, incdir, '.'],
    c_args : extra_flags_64 + rc_extra_args,
    native : false,
    build_by_default : meson.is_cross_build(),
)

winspool_w_o_64 = winspool_w_af_64.extract_all_objects(recursive : true)

winspool_w_64 = custom_target('winspool_w_64',
    input : ['winspool.drv.spec'],
    output : 'libwinspool_w_64.a',
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

winspool_u_af_64 = static_library('winspool_u_64', [headers, u_src],
    include_directories : [config_h_inc, incdir, '.'],
    c_args : ['-DWINE_UNIX_LIB'],
    dependencies : [cups],
    native : true,
    build_by_default : not meson.is_cross_build(),
)

winspool_u_o_64 = winspool_u_af_64.extract_all_objects(recursive : true)

winspool_64 = custom_target('winspool_64',
    output : 'winspool_64.a',
    input : [
        'winspool.drv.spec',
    ],
    command : [
	winebuild_bin,
	'-w', '--implib', '-o', '@OUTPUT@',
	'--without-dlltool',
	'-b', 'x86_64-w64-mingw32',
	'--export',
	'@INPUT@',
    ],
    depends : winebuild_bin,
    build_by_default : meson.is_cross_build(),
)

winspool_so_64 = shared_library('winspool_so_64', [],
    objects : [winspool_u_o_64],
    link_with : [ntdll_so_64],
    dependencies : [libdl],
    native : true,
    build_by_default : not meson.is_cross_build(),
)
