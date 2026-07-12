src = files(
    'dialog.c',
    'group.c',
    'grpfile.c',
    'main.c',
    'program.c',
    'string.c',
)

rc = files(
    'progman.rc',
)

res = gen_rc_res.process(rc)

flags = [
    '-mwindows',
]

exes += {
    'progman' : {
        'src' : src,
        'flags' : flags,
        'res' : res,
        'deps' : [
            'shell32',
            'comdlg32',
            'user32',
            'gdi32',
        ],
    }
}
