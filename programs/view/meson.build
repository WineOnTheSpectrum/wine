src = files(
    'view.c',
)

rc = files(
    'view.rc',
)

res = gen_rc_res.process(rc)

flags = [
    '-mwindows', '-municode',
]

exes += {
    'view' : {
        'src' : src,
        'flags' : flags,
        'res' : res,
        'deps' : [
            'comdlg32',
            'user32',
            'gdi32',
            'comctl32',
        ],
    }
}
