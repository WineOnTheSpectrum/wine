src = files(
    'main.c',
)

rc = files(
    'timeout.rc',
)

res = gen_rc_res.process(rc)

flags = [
    '-mconsole', '-municode',
]

exes += {
    'timeout' : {
        'src' : src,
        'flags' : flags,
        'res' : res,
        'deps' : [
            'user32',
        ],
    }
}
