src = files(
    'write.c',
)

rc = files(
    'write.rc',
)

res = gen_rc_res.process(rc)

flags = [
    '-mwindows',
]

exes += {
    'write' : {
        'src' : src,
        'flags' : flags,
        'res' : res,
        'deps' : [
            'user32',
            'gdi32',
            'shell32',
        ],
    }
}
