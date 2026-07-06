src = files(
    'auth.c',
    'mpr_main.c',
    'multinet.c',
    'nps.c',
    'pwcache.c',
    'wnet.c',
)

rc = files(
    'mpr.rc',
)

extra_args = [
    '-I../include/msvcrt',
    '-D_UCRT',
]


res = gen_rc_res.process(rc, extra_args : extra_args)

deps = [
    'user32',
    'advapi32',
    'winecrt0',
    'ucrtbase',
    'kernel32',
    'ntdll',
]

dlls += {
    'mpr' : {
        'idl_c' : [],
        'idl_h' : [],
        'res' : res,
        'extra_args' : extra_args,
        'src' : src,
        'obj' : [],
        'deps' : deps,
    }
}
