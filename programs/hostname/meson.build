src = files( 
    'hostname.c',
)

rc = files(
    'hostname.rc',
)

res = gen_rc_res.process(rc)

flags = [
    '-mconsole', '-municode',
]

exes += {
    'hostname' : {
        'src' : src,
        'flags' : flags,
        'res' : res,
        'deps' : [
            'user32',
        ],
    }
}
