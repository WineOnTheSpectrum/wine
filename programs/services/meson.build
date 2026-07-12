src = files(
    'rpc.c',
    'services.c',
    'utils.c',
)

idl = files(
    'svcctl.idl',
)

idl_h = gen_idl_h.process(idl)

flags = [
    '-mwindows',
]

exes += {
    'services' : {
        'src' : [idl_h, src],
        'flags' : flags,
        'res' : [],
        'deps' : [
            'rpcrt4',
            'advapi32',
            'userenv',
            'setupapi',
        ],
    }
}
