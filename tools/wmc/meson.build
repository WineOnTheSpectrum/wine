bison_srcs = gen_bison.process(
    'mcy.y',
)

src = [
    'lang.c',
    'mcl.c',
    'po.c',
    'utils.c',
    'wmc.c',
    'write.c',
    bison_srcs,
]

wmc_bin = executable('wmc', src,
    include_directories : [config_h_inc, '.', incdir],
    c_args : datadir_define,
    native : true,
)
