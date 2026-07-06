bison_srcs = gen_bison.process(
    'parser.y',
    'ppy.y',
)

flex_srcs = gen_flex.process(
    'parser.l',
    'ppl.l',
)

src = [
    'genres.c',
    'newstruc.c',
    'po.c',
    'utils.c',
    'wpp.c',
    'wrc.c',
    bison_srcs,
    flex_srcs,
]

wrc_bin = executable('wrc', src,
    include_directories : [config_h_inc, '.', incdir],
    c_args : [datadir_define] + extra_flags_tools,
    native : true,
)
