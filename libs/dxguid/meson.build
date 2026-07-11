src = [
    'dx10guid.c',
    'dx8guid.c',
    'dx9guid.c',
    'dxguid.c'
]

dxguid_32 = static_library('dxguid_32', [headers, src],
    include_directories : incdir,
    c_args : extra_flags_32,
    pic : true,
    native : false,
    build_by_default : meson.is_cross_build(),
)

dxguid_64 = static_library('dxguid_64', [headers, src],
    include_directories : incdir,
    c_args : extra_flags_64,
    native : false,
    build_by_default : meson.is_cross_build(),
)
