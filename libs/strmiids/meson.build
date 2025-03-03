src = [
    'evr.c',
    'strmiids.c'
]

static_library('strmiids_32', [headers, src],
    include_directories : incdir,
    c_args : extra_flags_32,
    pic : true,
    native : false,
    build_by_default : meson.is_cross_build(),
)

static_library('strmiids_64', [headers, src],
    include_directories : incdir,
    c_args : extra_flags_64,
    native : false,
    build_by_default : meson.is_cross_build(),
)
