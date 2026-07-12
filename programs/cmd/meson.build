src = files(
    'batch.c',
    'builtins.c',
    'directory.c',
    #'wcmd.svg',
    'wcmdmain.c',
)

rc = files(
    'cmd.rc',
)

res = gen_rc_res.process(rc)

flags = [
    '-mconsole', '-municode',
]

exes += {
    'cmd' : {
        'src' : src,
        'flags' : flags,
        'res' : res,
        'deps' : [
            'shell32',
            'user32',
            'advapi32',
        ],
    }
}
