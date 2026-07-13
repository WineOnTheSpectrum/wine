src = files(
    'protocol.c',
    'service.c',
    'socket.c',
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
    'mswsock',
    'ws2_32',
    'iphlpapi',
    'winecrt0',
    'ucrtbase',
    'kernel32',
    'ntdll',
]

dlls += {
    'wsock32' : {
        'idl_c' : [],
        'idl_h' : [],
        'res' : res,
        'extra_args' : extra_args,
        'src' : src,
        'obj' : [],
        'deps' : deps,
    }
}
