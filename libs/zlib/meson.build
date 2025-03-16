src = [
    'adler32.c',
    'crc32.c',
    'deflate.c',
    'inffast.c',
    'inflate.c',
    'inftrees.c',
    'trees.c',
    'zutil.c'
]

zlib_32 = static_library('zlib_32', [headers, src],
    include_directories : incdir,
    c_args : extra_flags_32 + ['-DZ_SOLO'],
    pic : true,
    native : false,
    build_by_default : meson.is_cross_build(),
)

zlib_64 = static_library('zlib_64', [headers, src],
    include_directories : incdir,
    c_args : extra_flags_64 + ['-DZ_SOLO'],
    native : false,
    build_by_default : meson.is_cross_build(),
)
