src = files(
    'main.c',
)

rc = files(
    'robocopy.rc',
)

res = gen_rc_res.process(rc)

flags = [
    '-mconsole', '-municode',
]

exes += {
    'robocopy' : {
        'src' : src,
        'flags' : flags,
        'res' : res,
        'deps' : [],
    }
}
