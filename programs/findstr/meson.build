src = files( 
    'main.c',
)

rc = files(
    'findstr.rc',
)

res = gen_rc_res.process(rc)

flags = [
    '-mconsole', '-municode',
]

exes += {
    'findstr' : {
        'src' : src,
        'flags' : flags,
        'res' : res,
        'deps' : [
            'user32',
        ],
    }
}
