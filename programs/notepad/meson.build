src = files( 
    'dialog.c', 
    'main.c',
    #'notepad.svg',
)

man = files(
    'notepad.man.in',
)

rc = files(
    'notepad.rc',
)

res = gen_rc_res.process(rc)

flags = [
    '-mwindows',
]

exes += {
    'notepad' : {
        'src' : src,
        'flags' : flags,
        'res' : res,
        'deps' : [
            'comdlg32',
            'shell32',
            'shlwapi',
            'user32',
            'gdi32',
            'advapi32',
            'comctl32',
        ],
    }
}
