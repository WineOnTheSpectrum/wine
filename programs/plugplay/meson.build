src = files( 
    'main.c',
)

idl = files(
    'plugplay.idl',
)

idl_h = gen_idl_h.process(idl)

flags = [
    '-mconsole', '-municode',
]

exes += {
    'plugplay' : {
        'src' : [idl_h, src],
        'flags' : flags,
        'res' : [],
        'deps' : [
            'advapi32',
            'rpcrt4',
            'user32',
        ],
    }
}
