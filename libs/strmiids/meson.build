src = files(
    'evr.c',
    'strmiids.c'
)

idls = files(
    '../../include/strmif.idl',
    '../../include/amstream.idl',
    '../../include/qedit.idl',
    '../../include/vmr9.idl',
    '../../include/mediaobj.idl',
    '../../include/mfobjects.idl',
    '../../include/videoacc.idl',
    '../../include/mfidl.idl',
    '../../include/evr.idl',
    '../../include/evr9.idl',
)

idl_h = gen_idl_h.process(idls)

static_library('strmiids_32', [headers, idl_h, src],
    include_directories : incdir,
    c_args : extra_flags_32,
    pic : true,
    native : false,
    build_by_default : meson.is_cross_build(),
)

static_library('strmiids_64', [headers, idl_h, src],
    include_directories : incdir,
    c_args : extra_flags_64,
    native : false,
    build_by_default : meson.is_cross_build(),
)
