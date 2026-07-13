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
idl_s = gen_idl_s_c.process(idls)

flags = [
    '-mconsole', '-municode',
]

exes += {
    'rpcss' : {
        'src' : [idl_h, idl_s, src],
        'flags' : flags,
        'res' : [],
        'deps' : [
            'rpcrt4',
            'advapi32',
        ],
    }
}
