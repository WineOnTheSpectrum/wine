src = files(
    'winefile.c',
    #'winefile.svg',
)

rc = files(
    'winefile.rc',
)

res = gen_rc_res.process(rc)

man = files(
    'winefile.man.in',
)

flags = [
    '-mwindows', '-municode',
]

exes += {
    'winefile' : {
        'src' : src,
        'flags' : flags,
        'res' : res,
        'deps' : [
            'uuid',
            'shell32',
            'comdlg32',
            'comctl32',
            'ole32',
            'mpr',
            'version',
            'user32',
            'gdi32',
            'advapi32',
            'shlwapi',
        ],
    }
}
