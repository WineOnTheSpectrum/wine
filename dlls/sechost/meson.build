idls = files(
    'plugplay.idl',
    'svcctl.idl',
)

idl_h = gen_idl_h.process(idls)

src = files(
    'security.c',
    'service.c',
    'trace.c',
)

deps = [
    'kernelbase',
    'rpcrt4',
    'winecrt0',
    'ucrtbase',
    'kernel32',
    'ntdll',
]

dlls += {
    'sechost' : {
        'idl_h' : idl_h,
        'res' : [],
        'extra_args' : [],
        'src' : src,
        'deps' : deps,
    }
}
