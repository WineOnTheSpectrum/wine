src = files(
    'winver.c',
)

rc = files(
    'version.rc',
)

res = gen_rc_res.process(rc)

flags = [
    '-mwindows',
]

exes += {
    'winver' : {
        'src' : src,
        'flags' : flags,
        'res' : res,
        'deps' : [
            'shell32',
            'comctl32',
        ],
    }
}
