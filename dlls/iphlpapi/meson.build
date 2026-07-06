src = files(
    'iphlpapi_main.c',
)

rc = files(
    'version.rc',
)

extra_args = [
    '-I../include/msvcrt',
    '-D_UCRT',
]

res = gen_rc_res.process(rc, extra_args : extra_args)

deps = [
    'advapi32',
    'dnsapi',
    'nsi',
    'uuid',
    'ws2_32',
    'winecrt0',
    'ucrtbase',
    'kernel32',
    'ntdll',
]

dlls += {
    'iphlpapi' : {
        'idl_c' : [],
        'idl_h' : [],
        'res' : res,
        'extra_args' : extra_args,
        'src' : src,
        'obj' : [],
        'deps' : deps,
    }
}
