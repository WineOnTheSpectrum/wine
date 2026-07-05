idls = files(
    'plugplay.idl',
    'svcctl.idl',
)

idl_c = gen_idl_c.process(idls)
idl_h = gen_idl_h.process(idls)

src = files(
    'security.c',
    'service.c',
    'trace.c',
)

extra_args = [
    '-I../include/msvcrt',
    '-D_UCRT',
]

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
        'idl_c' : idl_c,
        'res' : [],
        'extra_args' : extra_args,
        'src' : src,
        'deps' : deps,
    }
}
