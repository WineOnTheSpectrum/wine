src = files( 
    'ngen_main.c',
)

rc = files(
    'version.rc',
)

res = gen_rc_res.process(rc)

flags = [
    '-mconsole', '-municode',
]

exes += {
    'ngen' : {
        'src' : src,
        'flags' : flags,
        'res' : res,
        'deps' : [],
    }
}
