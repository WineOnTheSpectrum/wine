src = files(
    'tasklist.c',
)

rc = files(
    'tasklist.rc',
)

res = gen_rc_res.process(rc)

flags = [
    '-mconsole', '-municode',
]

exes += {
    'tasklist' : {
        'src' : src,
        'flags' : flags,
        'res' : [],
        'deps' : [
            'user32',
        ],
    }
}
