src = files(
    'hidd.c',
    'hidp.c',
)

rc = files(
    'version.rc',
)

extra_args = [
    '-I../include/msvcrt',
    '-D_UCRT',
    '-D__WINESRC', '-D__WINE_PE_BUILD',
]

res = gen_rc_res.process(rc, extra_args : extra_args)

deps = [
    'kernelbase',
    'winecrt0',
    'ucrtbase',
    'kernel32',
    'ntdll',
]

dlls += {
    'hid' : {
        'idl_c' : [],
        'idl_h' : [],
        'res' : res,
        'extra_args' : extra_args,
        'src' : src,
        'obj' : [],
        'deps' : deps,
    }
}
