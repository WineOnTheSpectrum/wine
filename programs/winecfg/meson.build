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

idls = files(
    '../../include/audioclient.idl',
    '../../include/audiopolicy.idl',
)

idl_h = gen_idl_h.process(idls)

man = files(
    'winecfg.man.in',
)
	
flags = [
    '-mwindows', '-municode',
]

exes += {
    'winecfg' : {
        'src' : [idl_h, src],
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
