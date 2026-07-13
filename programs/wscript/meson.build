src = files(
    'arguments.c',
    'host.c',
    'main.c',
)

idl = files(
    'ihost.idl',
    '../../include/activscp.idl',
)

idl_h = gen_idl_h.process(idl)

flags = [
    '-mwindows', '-municode',
]

exes += {
    'wscript' : {
        'src' : [idl_h, src],
        'flags' : flags,
        'res' : res,
        'deps' : [
            'uuid',
            'shell32',
            'oleaut32',
            'ole32',
            'user32',
            'advapi32',
        ],
    }
}
