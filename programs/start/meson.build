src = files(
    'start.c',
)

rc = files(
    'start.rc',
)

res = gen_rc_res.process(rc)

flags = [
    '-mconsole', '-municode',
]

exes += {
    'start' : {
        'src' : src,
        'flags' : flags,
        'res' : res,
        'deps' : [
            'shell32',
            'user32',
        ],
    }
}
