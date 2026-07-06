src = files(
    'dhcpcsvc.c',
)

extra_args = [
    '-I../include/msvcrt',
    '-D_UCRT',
]

deps = [
    'iphlpapi',
    'winecrt0',
    'ucrtbase',
    'kernel32',
    'ntdll',
]

dlls += {
    'dhcpcsvc' : {
        'idl_c' : [],
        'idl_h' : [],
        'res' : [],
        'extra_args' : extra_args,
        'src' : src,
        'obj' : [],
        'deps' : deps,
    }
}
