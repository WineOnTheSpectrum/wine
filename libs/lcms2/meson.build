src = [
    'src/cmsalpha.c',
    'src/cmscnvrt.c',
    'src/cmserr.c',
    'src/cmsgamma.c',
    'src/cmsgmt.c',
    'src/cmshalf.c',
    'src/cmsintrp.c',
    'src/cmsio0.c',
    'src/cmsio1.c',
    'src/cmslut.c',
    'src/cmsmtrx.c',
    'src/cmsnamed.c',
    'src/cmsopt.c',
    'src/cmspack.c',
    'src/cmspcs.c',
    'src/cmsplugin.c',
    'src/cmssamp.c',
    'src/cmstypes.c',
    'src/cmsvirt.c',
    'src/cmswtpnt.c',
    'src/cmsxform.c'
]

# FIXME: add flags.
# EXTRAINCL = $(LCMS2_PE_CFLAGS)

static_library('lcms2_32', [headers, src],
    include_directories : [incdir, 'include'],
    c_args : extra_flags_32,
    pic : true,
    native : false,
    build_by_default : meson.is_cross_build(),
)

static_library('lcms2_64', [headers, src],
    include_directories : [incdir, 'include'],
    c_args : extra_flags_64,
    native : false,
    build_by_default : meson.is_cross_build(),
)
