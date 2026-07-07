mc = files(
    'winerror.mc',
)

winerror_res = gen_mc_res.process(mc)
winerror_pot = gen_mc_pot.process(mc)

rc = files(
    'kernelbase.rc',
)

rc_extra_args = [
    '-D_MSVCR_VER=0', '-DWINBASEAPI=', '-DWINADVAPI=', '-DWINUSERAPI=', '-DWINSHLWAPI=',
]

kernelbase_res = gen_rc_res.process(rc, extra_args : rc_extra_args)

src = files(
    'console.c',
    'debug.c',
    'file.c',
    'loader.c',
    'locale.c',
    'main.c',
    'memory.c',
    'path.c',
    'process.c',
    'registry.c',
    'security.c',
    'string.c',
    'sync.c',
    'thread.c',
    'version.c',
    'volume.c',
)

kernelbase_af_64 = static_library('kernelbase_af_64', [headers, src],
    include_directories : [incdir, '.', '../../include/msvcrt'],
    c_args : extra_flags_64 + rc_extra_args,
    native : false,
    build_by_default : meson.is_cross_build(),
)

kernelbase_o_64 = kernelbase_af_64.extract_all_objects(recursive : true)

kernelbase_64 = custom_target('kernelbase_64',
    input : 'kernelbase.spec',
    output : 'libkernelbase_64.a',
    command : [
      winebuild_bin,
      '-w', '--implib', '-o', '@OUTPUT@',
      '--without-dlltool',
      '-b', 'x86_64-w64-mingw32',
      '--export',
      '@INPUT@',
    ],
    depends : [
        winebuild_bin,
        kernelbase_af_64,
    ],
    build_by_default : meson.is_cross_build(),
)

custom_target('kernelbase_64.dll',
    output : 'kernelbase_64.dll',
    input : [
        'kernelbase.spec', kernelbase_o_64, kernelbase_res, winerror_res,
        uuid_64, ntdll_64, winecrt0_64,
    ],
    command : [
	winegcc_bin,
	'-o', '@OUTPUT@',
	'--wine-objdir', '.',
	'-b', 'x86_64-w64-mingw32',
	'-Wl,--wine-builtin',
	'-shared',
	'-nodefaultlibs', '-nostartfiles', '-Wl,--image-base,0x174000000',
	'@INPUT@',
    ],
    depends : [
        winegcc_bin,
        kernelbase_64,
    ],
    build_by_default : meson.is_cross_build(),
)
