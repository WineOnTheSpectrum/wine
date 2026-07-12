src = files(
    'main.c',
)

rc = files(
    'version.rc',
)

res = gen_rc_res.process(rc)

flags = [
    '-mwindows', '-municode',
]

exes += {
    'dpvsetup' : {
        'src' : src,
        'flags' : flags,
        'res' : res,
        'deps' : [],
    }
}
