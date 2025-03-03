src = [
    'wine.c',
]

executable('wine', src,
    include_directories : [config_h_inc, incdir],
    dependencies: libdl,
    c_args : extra_flags_tools,
    native : true,
)
