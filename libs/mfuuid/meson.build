src = files(
    'mfplay.c',
    'mfuuid.c'
)

idls = files(
    '../../include/evr.idl',
    '../../include/evr9.idl',
    '../../include/mediaobj.idl',
    '../../include/strmif.idl',

    '../../include/mfd3d12.idl',
    '../../include/mfidl.idl',
    '../../include/mfmediaengine.idl',
    '../../include/mfobjects.idl',
    '../../include/mfplay.idl',
    '../../include/mfreadwrite.idl',
    '../../include/mftransform.idl',
)

idl_h = gen_idl_h.process(idls)

static_library('mfuuid_32', [headers, idl_h, src],
    include_directories : incdir,
    c_args : extra_flags_32,
    pic : true,
    native : false,
    build_by_default : meson.is_cross_build(),
)

static_library('mfuuid_64', [headers, idl_h, src],
    include_directories : incdir,
    c_args : extra_flags_64,
    native : false,
    build_by_default : meson.is_cross_build(),
)
