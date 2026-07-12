src = files(
    'gui.c',
    'main.c',
    'send.c',
    'util.c',
    #'winetest.svg',
)

rc = files(
    'winetest.rc',
)
res = gen_rc_res.process(rc)

#EXTRA_TARGETS = build.res build.nfo

flags = [
    '-mconsole',
]

exes += {
    'winetest' : {
        'src' : src,
        'flags' : flags,
        'res' : res,
        'deps' : [
            'uuid',
            'comctl32',
            'version',
            'user32',
            'gdi32',
            'advapi32',
            'wsock32',
            'msvcrt',
            'ole32',
        ],
    }
}
