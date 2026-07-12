src = files(
    'main.c',
)

rc = files(
    'wmic.rc',
)

res = gen_rc_res.process(rc)

flags = [
    '-mconsole', '-municode',
]

exes += {
    'wmic' : {
        'src' : src,
        'flags' : flags,
        'res' : res,
        'deps' : [
            'oleaut32',
            'ole32',
            'user32',
            'shell32',
        ],
    }
}
