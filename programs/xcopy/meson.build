src = files(
    'xcopy.c',
)

rc = files(
    'xcopy.rc',
)

res = gen_rc_res.process(rc)

flags = [
    '-mconsole', '-municode',
]

exes += {
    'xcopy' : {
        'src' : src,
        'flags' : flags,
        'res' : res,
        'deps' : [
            'shell32',
            'user32',
        ],
    }
}
