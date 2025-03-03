src = [
    'dxerr8.c'
]

dxerr8_32 = static_library('dxerr8_32', [headers, src],
    include_directories : incdir,
    c_args : extra_flags_32 + ['-D_MSVCR_VER=0'],
    pic : true,
    native : false,
    build_by_default : meson.is_cross_build(),
)

dxerr8_64 = static_library('dxerr8_64', [headers, src],
    include_directories : incdir,
    c_args : extra_flags_64 + ['-D_MSVCR_VER=0'],
    native : false,
    build_by_default : meson.is_cross_build(),
)
