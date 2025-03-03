src = [
    'image/decode/JXRTranscode.c',
    'image/decode/decode.c',
    'image/decode/postprocess.c',
    'image/decode/segdec.c',
    'image/decode/strInvTransform.c',
    'image/decode/strPredQuantDec.c',
    'image/decode/strdec.c',
    'image/encode/encode.c',
    'image/encode/segenc.c',
    'image/encode/strFwdTransform.c',
    'image/encode/strPredQuantEnc.c',
    'image/encode/strenc.c',
    'image/sys/adapthuff.c',
    'image/sys/image.c',
    'image/sys/strPredQuant.c',
    'image/sys/strTransform.c',
    'image/sys/strcodec.c',
    'jxrgluelib/JXRGlue.c',
    'jxrgluelib/JXRGlueJxr.c',
    'jxrgluelib/JXRGluePFC.c',
    'jxrgluelib/JXRMeta.c'
]

# FIXME: add flags.
# EXTRAINCL = $(JXR_PE_CFLAGS)
# EXTRADEFS = -DDISABLE_PERF_MEASUREMENT

static_library('jxr_32', [headers, src],
    include_directories : incdir,
    c_args : extra_flags_32 + ['-DDISABLE_PERF_MEASUREMENT'],
    pic : true,
    native : false,
    build_by_default : meson.is_cross_build(),
)

static_library('jxr_64', [headers, src],
    include_directories : incdir,
    c_args : extra_flags_64 + ['-DDISABLE_PERF_MEASUREMENT'],
    native : false,
    build_by_default : meson.is_cross_build(),
)
