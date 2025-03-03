src = [
    'HTMLparser.c',
    'HTMLtree.c',
    'SAX.c',
    'SAX2.c',
    'buf.c',
    'catalog.c',
    'chvalid.c',
    'debugXML.c',
    'dict.c',
    'encoding.c',
    'entities.c',
    'error.c',
    'globals.c',
    'hash.c',
    'list.c',
    'parser.c',
    'parserInternals.c',
    'pattern.c',
    'relaxng.c',
    'threads.c',
    'tree.c',
    'uri.c',
    'valid.c',
    'xinclude.c',
    'xmlIO.c',
    'xmlmemory.c',
    'xmlreader.c',
    'xmlregexp.c',
    'xmlsave.c',
    'xmlschemas.c',
    'xmlschemastypes.c',
    'xmlstring.c',
    'xmlunicode.c',
    'xpath.c',
    'xpointer.c'
]

# FIXME: add flags.
# EXTRAINCL = $(XML2_PE_CFLAGS)
# EXTRADEFS = -DHAVE_VA_COPY

static_library('xml2_32', [headers, src],
    include_directories : [incdir, 'include'],
    c_args : extra_flags_32 + ['-DHAVE_VA_COPY'],
    pic : true,
    native : false,
    build_by_default : meson.is_cross_build(),
)

static_library('xml2_64', [headers, src],
    include_directories : [incdir, 'include'],
    c_args : extra_flags_64 + ['-DHAVE_VA_COPY'],
    native : false,
    build_by_default : meson.is_cross_build(),
)
