src = files(
    'cache.c',
    'name.c',
    'sxs.c',
)

idls = files(
    '../../include/winsxs.idl',
    '../../include/msxml2.idl',
)

extra_args = [
    '-I../include/msvcrt',
    '-D_UCRT',
]

idl_h = gen_idl_h.process(idls, extra_args : extra_args)

deps = [
    'oleaut32',
    'ole32',
    'winecrt0',
    'ucrtbase',
    'kernel32',
    'ntdll',
]

dlls += {
    'sxs' : {
        'idl_c' : [],
        'idl_h' : idl_h,
        'res' : [],
        'extra_args' : extra_args,
        'src' : src,
        'obj' : [],
        'deps' : deps,
    }
}
