src = files(
    #'formatbar.svg',
    'olecallback.c',
    'print.c',
    'registry.c',
    #'toolbar.svg',
    'wordpad.c',
    #'wordpad.svg',
    #'zoom.svg',
)

rc = files(
    'wordpad.rc',
)

res = gen_rc_res.process(rc)

idls = files(
    '../../include/richole.idl',
)

idl_h = gen_idl_h.process(idls)

flags = [
    '-mwindows',
]

exes += {
    'wordpad' : {
        'src' : [idl_h, src],
        'flags' : flags,
        'res' : res,
        'deps' : [
            'comdlg32',
            'uuid',
            'ole32',
            'shell32',
            'user32',
            'gdi32',
            'advapi32',
            'comctl32',
        ],
    }
}
