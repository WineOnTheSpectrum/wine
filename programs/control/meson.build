src = files(
    'control.c',
)

rc = files(
    'control.rc',
)

res = gen_rc_res.process(rc)

flags = [
    '-mwindows', '-municode',
]

exes += {
    'control' : {
        'src' : src,
        'flags' : flags,
        'res' : res,
        'deps' : [
            'shell32',
            'user32',
            'comctl32',
        ],
    }
}
