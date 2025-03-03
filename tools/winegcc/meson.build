src = [
    'utils.c',
    'winegcc.c'
]

winegcc_bin = executable('winegcc', src,
    include_directories : [config_h_inc, incdir],
    c_args : extra_flags_tools,
    native : true,
)
