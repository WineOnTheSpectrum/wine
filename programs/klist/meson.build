src = files( 
    'main.c',
)

rc = files(
    'klist.rc',
)

res = gen_rc_res.process(rc)

flags = [
    '-mconsole', '-municode',
]

exes += {
    'klist' : {
        'src' : src,
        'flags' : flags,
        'res' : res,
        'deps' : [
            'secur32',
            'advapi32',
            'user32',
        ],
    }
}
