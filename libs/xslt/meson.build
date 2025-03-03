src = [
    'libxslt/attributes.c',
    'libxslt/attrvt.c',
    'libxslt/documents.c',
    'libxslt/extensions.c',
    'libxslt/extra.c',
    'libxslt/functions.c',
    'libxslt/imports.c',
    'libxslt/keys.c',
    'libxslt/namespaces.c',
    'libxslt/numbers.c',
    'libxslt/pattern.c',
    'libxslt/preproc.c',
    'libxslt/security.c',
    'libxslt/templates.c',
    'libxslt/transform.c',
    'libxslt/variables.c',
    'libxslt/xslt.c',
    'libxslt/xsltlocale.c',
    'libxslt/xsltutils.c'
]

# FIXME: add flags.
# EXTLIB    = libxslt.a
# EXTRAINCL = $(XML2_PE_CFLAGS) $(XSLT_PE_CFLAGS)

static_library('xslt_32', [headers, src],
    include_directories : [incdir, 'libxslt', '../../libs/xml2/include'],
    c_args : extra_flags_32,
    pic : true,
    native : false,
    build_by_default : meson.is_cross_build(),
)

static_library('xslt_64', [headers, src],
    include_directories : [incdir, 'libxslt', '../../libs/xml2/include'],
    c_args : extra_flags_64,
    native : false,
    build_by_default : meson.is_cross_build(),
)
