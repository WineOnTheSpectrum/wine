src = files(
    'information.c',
    'main.c',
    'output.c',
)

rc = files(
    'dxdiag.rc',
)

res = gen_rc_res.process(rc)

idls = files(
    '../../include/msxml2.idl',
)

idl_h = gen_idl_h.process(idls)

flags = [
    '-mwindows', '-municode',
]

exes += {
    'dxdiag' : {
        'src' : [idl_h, src],
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
