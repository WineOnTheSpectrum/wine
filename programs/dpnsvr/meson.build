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
    'dpnsvr' : {
        'src' : src,
        'flags' : flags,
        'res' : res,
        'deps' : [],
    }
}
