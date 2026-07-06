bison_srcs = gen_bison.process(
    'parser.y', '../wrc/ppy.y'
)

flex_srcs = gen_flex.process(
    'parser.l', '../wrc/ppl.l'
)

## FIXME: man page
# 'widl.man.in',

src = [
    'attribute.c',
    'client.c',
    'expr.c',
    'hash.c',
    'header.c',
    'proxy.c',
    'register.c',
    'server.c',
    'typegen.c',
    'typelib.c',
    'typetree.c',
    'utils.c',
    'widl.c',
    'write_msft.c',
    'write_sltg.c',
    bison_srcs,
    flex_srcs,
    '../wrc/wpp.c',
]

widl_bin = executable('widl', src,
    include_directories : [config_h_inc, '.', incdir, '../wrc'],
    c_args : extra_flags_tools,
    native : true,
)
