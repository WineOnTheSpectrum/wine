src = [
    'png.c',
    'pngerror.c',
    'pngget.c',
    'pngmem.c',
    'pngread.c',
    'pngrio.c',
    'pngrtran.c',
    'pngrutil.c',
    'pngset.c',
    'pngtrans.c',
    'pngwio.c',
    'pngwrite.c',
    'pngwtran.c',
    'pngwutil.c'
]

png_32 = static_library('png_32', [headers, src],
    include_directories : [incdir, '../../include/msvcrt', '../../libs/zlib'],
    c_args : extra_flags_32 + ['-D_UCRT', '-DFAR=', '-DZ_SOLO', '-DPNG_ARM_NEON_OPT=0'],
    pic : true,
    native : false,
    build_by_default : meson.is_cross_build(),
)

png_64 = static_library('png_64', [headers, src],
    include_directories : [incdir, '../../include/msvcrt', '../../libs/zlib'],
    c_args : extra_flags_64 + ['-D_UCRT', '-DFAR=', '-DZ_SOLO', '-DPNG_ARM_NEON_OPT=0'],
    native : false,
    build_by_default : meson.is_cross_build(),
)
