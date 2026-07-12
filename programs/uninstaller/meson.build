src = files(
    'main.c',
)

rc = files(
    'uninstaller.rc',
)

res = gen_rc_res.process(rc)

flags = [
    '-mwindows', '-municode',
]

exes += {
    'uninstaller' : {
        'src' : src,
        'flags' : flags,
        'res' : res,
        'deps' : [
            'advapi32',
            'shlwapi',
            'shell32',
            'user32',
            'gdi32',
            'comctl32',
        ],
    }
}
