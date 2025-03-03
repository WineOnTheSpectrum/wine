src = [
    'import.c',
    'main.c',
    'parser.c',
    'relay.c',
    'res16.c',
    'res32.c',
    'spec16.c',
    'spec32.c',
    'utils.c'
]

winebuild_bin = executable('winebuild', src,
    include_directories : [config_h_inc, incdir],
    c_args : extra_flags_tools,
    dependencies: libdl,
    native : true,
)
