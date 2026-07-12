src = files( 
    'dism.c',
)

rc = files(
    'version.rc',
)

flags = [
    '-mconsole', '-municode',
]

res = gen_rc_res.process(rc)

exes += {
    'dism' : {
        'src' : [idl_h, src],
        'flags' : flags,
        'res' : res,
        'deps' : [],
    }
}
