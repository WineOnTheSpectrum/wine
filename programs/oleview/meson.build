src = files( 
    'details.c',
    'interface.c',
    'oleview.c',
    'pane.c',
    'tree.c',
    'typelib.c',
)

rc = files(
    'oleview.rc',
)

res = gen_rc_res.process(rc)

flags = [
    '-mwindows',
]

exes += {
    'oleview' : {
        'src' : src,
        'flags' : flags,
        'res' : res,
        'deps' : [
            'uuid',
            'comdlg32',
            'comctl32',
            'shell32',
            'oleaut32',
            'ole32',
            'user32',
            'advapi32',
        ],
    }
}
