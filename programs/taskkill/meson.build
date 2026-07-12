src = files(
    'taskkill.c',
)

rc = files(
    'taskkill.rc',
)

res = gen_rc_res.process(rc)

flags = [
    '-mconsole', '-municode',
]

exes += {
    'taskkill' : {
        'src' : src,
        'flags' : flags,
        'res' : [],
        'deps' : [
            'user32',
        ],
    }
}
