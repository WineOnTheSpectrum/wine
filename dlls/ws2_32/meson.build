src_w = files(
    'async.c',
    'inaddr.c',
    'protocol.c',
    'socket.c',
)

src_u = files(
    'unixlib.c',
)

rc = files(
    'version.rc',
)

extra_args = [
    '-I../include/msvcrt',
    '-D_UCRT',
    '-D_WS2_32_',
    '-D__WINESRC__',
]

res = gen_rc_res.process(rc, extra_args : extra_args)

deps = [
    'advapi32',
    'user32',
    'winecrt0',
    'ucrtbase',
    'kernel32',
    'ntdll',
    'dnsapi', # delay?
    'iphlpapi', # delay?
]

dlls += {
    'ws2_32' : {
        'idl_c' : [],
        'idl_h' : [],
        'res' : res,
        'extra_args' : extra_args,
        'src' : src_w,
        'obj' : [],
        'deps' : deps,
        'so': {
            'src': src_u,
            'extra_args': ['-D_WS2_32_'],
            'link' : ['ntdll_so'],
            'deps' : [libdl, pthread],
        },
    }
}
