idl0 = files(
    '../../include/iads.idl',
)

idls = files(
    'plugplay.idl',
    'svcctl.idl',
)

src = files(
    'security.c',
    'service.c',
    'trace.c',
)

extra_args = [
    '-I../include/msvcrt',
    '-D_UCRT',
    '-D__WINESRC__',
]

idl_c = gen_idl_c.process(idls, extra_args : extra_args)
idl_h = gen_idl_h.process([idl0, idls], extra_args : extra_args)

deps = [
    'kernelbase',
    'winecrt0',
    'ucrtbase',
    'kernel32',
    'ntdll',
    'rpcrt4', # delay?
]

dlls += {
    'sechost' : {
        'idl_h' : idl_h,
        'idl_c' : idl_c,
        'res' : [],
        'extra_args' : extra_args,
        'src' : src,
        'obj' : [],
        'deps' : deps,
    }
}
