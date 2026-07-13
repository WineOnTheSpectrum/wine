src = files( 
    '../wscript/arguments.c',
    '../wscript/host.c',
    '../wscript/main.c',
)

idls = files(
    '../wscript/ihost.idl',
    '../../include/activscp.idl',
)

defs = [
    '-DCSCRIPT_BUILD'
]

flags = defs + [
    '-mconsole', '-municode',
]

idl_h = gen_idl_h.process(idls, extra_args : defs)

exes += {
    'cscript' : {
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
