src = files(
    'mlang.c',
) 

rc = files(
    'mlang.rc',
)

extra_args = [
    '-I../include/msvcrt',
    '-D_UCRT',
]

res = gen_rc_res.process(rc, extra_args : extra_args)

idls = files(
    'mlang_classes.idl',
)

idl_h = gen_idl_h.process(idls)

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
        'idl_h' : idl_h,
        'res' : res,
        'extra_args' : extra_args,
        'src' : src,
        'deps' : deps,
    }
}
