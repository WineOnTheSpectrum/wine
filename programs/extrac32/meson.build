src = files( 
    'extrac32.c',
)

rc = files(
    'extrac32.rc',
)

res = gen_rc_res.process(rc)

flags = [
    '-mwindows', '-municode',
]

exes += {
    'extrac32' : {
        'src' : src,
        'flags' : flags,
        'res' : res,
        'deps' : [
            'shell32',
            'setupapi',
            'shlwapi',
            'user32',
            'comctl32',
        ],
    }
}
