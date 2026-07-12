src = files(
    'shutdown.c',
    'wineboot.c',
)
	
rc = files(
    'wineboot.rc',
)

res = gen_rc_res.process(rc)

man = files(
    'wineboot.man.in',
)
	
flags = [
    '-mconsole',
]

exes += {
    'wineboot' : {
        'src' : src,
        'flags' : flags,
        'res' : res,
        'deps' : [
            'uuid',
            'advapi32',
            'ws2_32',
            'kernelbase',
            'shell32',
            'shlwapi',
            'version',
            'user32',
            'gdi32',
            'setupapi',
            'newdev',
        ],
    }
}
