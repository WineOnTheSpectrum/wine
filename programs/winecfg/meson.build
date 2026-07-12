src = files(
    'about.c',
    'appdefaults.c',
    'audio.c',
    'drive.c',
    'driveui.c',
    'libraries.c',
    #'logo.svg',
    'main.c',
    'theme.c',
    'winecfg.c',
    #'winecfg.svg',
    'x11drvdlg.c',
)
    
rc = files(
    'winecfg.rc',
)

res = gen_rc_res.process(rc)

man = files(
    'winecfg.man.in',
)
	
flags = [
    '-mwindows', '-municode',
]

exes += {
    'winecfg' : {
        'src' : src,
        'flags' : flags,
        'res' : res,
        'deps' : [
            'uuid',
            'comdlg32',
            'comctl32',
            'shell32',
            'ole32',
            'winmm',
            'shlwapi',
            'uxtheme',
            'user32',
            'gdi32',
            'advapi32',
        ],
    }
}
