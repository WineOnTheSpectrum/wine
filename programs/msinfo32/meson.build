src = files( 
    'main.c',
)

rc = files(
    'msinfo32.rc',
)

res = gen_rc_res.process(rc)

flags = [
    '-mwindows', '-municode',
]

exes += {
    'msinfo32' : {
        'src' : src,
        'flags' : flags,
        'res' : res,
        'deps' : [
            'shell32',
            'user32',
            'comctl32',
        ],
    }
}
