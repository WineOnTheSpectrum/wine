src = files(
    'epmp.c',
    'irotp.c',
    'rpcss_main.c',
)

idls = files(
    'epm.idl',
    'irot.idl',
    'irpcss.idl',
)

idl_h = gen_idl_h.process(idls)

flags = [
    '-mconsole', '-municode',
]

exes += {
    'rpcss' : {
        'src' : [idl_h, src],
        'flags' : flags,
        'res' : [],
        'deps' : [
            'rpcrt4',
            'advapi32',
        ],
    }
}
