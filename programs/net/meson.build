src = files( 
    'net.c',
)

rc = files(
    'net.rc',
)

res = gen_rc_res.process(rc)

flags = [
    '-mwindows', '-municode',
]

exes += {
    'net' : {
        'src' : src,
        'flags' : flags,
        'res' : res,
        'deps' : [
            'netapi32',
            'user32',
            'advapi32',
        ],
    }
}
