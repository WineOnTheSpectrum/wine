src = files(
    'wmcodecdspuuid.c'
)

idls = files(
    '../../include/strmif.idl',
)

idl_h = gen_idl_h.process(idls)

static_library('wmcodecdspuuid_32', [headers, idl_h, src],
    include_directories : incdir,
    c_args : extra_flags_32,
    pic : true,
    native : false,
    build_by_default : meson.is_cross_build(),
)

static_library('wmcodecdspuuid_64', [headers, idl_h, src],
    include_directories : incdir,
    c_args : extra_flags_64,
    native : false,
    build_by_default : meson.is_cross_build(),
)
