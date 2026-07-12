src = files( 
    'appbar.c',
    'desktop.c',
    'explorer.c',
    'startmenu.c',
    'systray.c',
)

rc = files(
    'explorer.rc',
)

res = gen_rc_res.process(rc)

flags = [
    '-mwindows', '-municode',
]

exes += {
    'explorer' : {
        'src' : src,
        'flags' : flags,
        'res' : res,
        'deps' : [
            'rpcrt4',
            'user32',
            'gdi32',
            'advapi32',
            'win32u',
            'comctl32',
            'shell32',
            'oleaut32',
            'ole32',
            'shlwapi',
        ],
    }
}
