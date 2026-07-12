src = files(
    'information.c',
    'main.c',
    'output.c',
)

rc = files(
    'dxdiag.rc',
)

res = gen_rc_res.process(rc)

flags = [
    '-mwindows', '-municode',
]

exes += {
    'dxdiag' : {
        'src' : src,
        'flags' : flags,
        'res' : res,
        'deps' : [
            'dxguid',
            'ole32',
            'oleaut32',
            'user32',
            'comctl32',
        ],
    }
}
