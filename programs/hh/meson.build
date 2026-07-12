src = files( 
    'main.c',
    #'winhelp.svg',
)

rc = files(
    'hh.rc',
)

res = gen_rc_res.process(rc)

flags = [
    '-mwindows',
]

exes += {
    'hh' : {
        'src' : src,
        'flags' : flags,
        'res' : res,
        'deps' : [],
    }
}
