src = files(
    'dialog.c',
    'main.c',
    #'winemine.svg',
)

rc = files(
    'winemine.rc',
)

res = gen_rc_res.process(rc)

man = files(
    'winemine.man.in',
)

flags = [
    '-mwindows', '-municode',
]

exes += {
    'winemine' : {
        'src' : src,
        'flags' : flags,
        'res' : [],
        'deps' : [
            'user32',
            'gdi32',
            'advapi32',
            'comctl32',
            'shell32',
        ],
    }
}
