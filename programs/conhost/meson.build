src = files(
    'conhost.c',
    'window.c',
)

rc = files(
    'conhost.rc',
)

res = gen_rc_res.process(rc)

flags = [
    '-mwindows', '-municode',
]

exes += {
    'conhost' : {
        'src' : src,
        'flags' : flags,
        'res' : res,
        'deps' : [
            'user32',
            'gdi32',
            'advapi32',
            'comctl32',
        ],
    }
}
