src = files( 
    'find.c',
)

rc = files(
    'find.rc',
)

res = gen_rc_res.process(rc)

flags = [
    '-mconsole', '-municode',
]

exes += {
    'find' : {
        'src' : src,
        'flags' : flags,
        'res' : res,
        'deps' : [
            'user32',
        ],
    }
}
