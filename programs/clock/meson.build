src = files(
    'main.c',
    'winclock.c',
)

rc = files(
    'clock.rc',
)

res = gen_rc_res.process(rc)

flags = [
    '-mwindows',
]

exes += {
    'clock' : {
        'src' : src,
        'flags' : flags,
        'res' : res,
        'deps' : [
            'comdlg32',
            'shell32',
            'user32',
            'gdi32',
            'comctl32',
        ],
    }
}
