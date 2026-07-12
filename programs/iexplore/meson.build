src = files( 
    'main.c',
    #'iexplore.svg',
)

rc = files(
    'iexplore.rc',
)

res = gen_rc_res.process(rc)

flags = [
    '-mwindows', '-municode',
    '-Wl,--large-address-aware',
]

exes += {
    'iexplore' : {
        'src' : src,
        'flags' : flags,
        'res' : res,
        'deps' : [
            'ieframe',
            'advpack',
            'version',
            'user32',
        ],
    }
}
