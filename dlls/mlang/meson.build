src = files(
    'mlang.c',
) 

rc = files(
    'mlang.rc',
)

extra_args = [
    '-I../include/msvcrt',
    '-D_UCRT',
    '-D__WINESRC__',
]

res = gen_rc_res.process(rc, extra_args : extra_args)

idl0 = files(
    '../../include/mimeole.idl',
    '../../include/mlang.idl',
)

idls = files(
    'mlang_classes.idl',
)

idl_c = gen_idl_c.process(idls, extra_args : extra_args)
idl_h = gen_idl_h.process([idl0, idls], extra_args : extra_args)

deps = [
    'uuid',
    'ole32',
    'gdi32',
    'advapi32',
    'oleaut32',
    'winecrt0',
    'ucrtbase',
    'kernel32',
    'ntdll',
]

dlls += {
    'mlang' : {
        'idl_c' : idl_c,
        'idl_h' : idl_h,
        'res' : res,
        'extra_args' : extra_args,
        'src' : src,
        'obj' : [],
        'deps' : deps,
    }
}
