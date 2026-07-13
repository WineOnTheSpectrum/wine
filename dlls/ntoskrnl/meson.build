src = files(
    'instr.c',
    'ntoskrnl.c',
    'pnp.c',
    'sync.c',
)

rc = files(
    'ntoskrnl.rc',
)

extra_args = [
    '-I../include/msvcrt',
    '-D_UCRT',
    '-D__WINESRC__',
]

res = gen_rc_res.process(rc, extra_args : extra_args)

idls = files(
    'plugplay.idl',
)

idl_h = gen_idl_h.process(idls, extra_args : extra_args)
idl_c = gen_idl_c.process(idls, extra_args : extra_args)

deps = [
    'advapi32',
    'hal',
    'msvcrt',
    'rpcrt4',
    'setupapi',
    'winecrt0',
    'ucrtbase',
    'kernel32',
    'ntdll',
]

dlls += {
    'ntoskrnl' : {
        'idl_c' : idl_c,
        'idl_h' : idl_h,
        'res' : res,
        'extra_args' : extra_args,
        'src' : src,
        'obj' : [],
        'deps' : deps,
    }
}
