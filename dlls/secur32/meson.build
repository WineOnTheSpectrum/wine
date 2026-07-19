u_src = files(
    'schannel_gnutls.c',
)

w_src = files(
    'lsa.c',
    'negotiate.c',
    'schannel.c',
    'secur32.c',
    'thunks.c',
    'wrapper.c',
)

w_extra_args = [
    '-I../include/msvcrt',
    '-D_UCRT',
    '-D__WINESRC__',
]

deps = [
    'advapi32',
    'crypt32',
    'winecrt0',
    'ucrtbase',
    'kernel32',
    'ntdll',
]

dlls += {
    'secur32' : {
        'idl_c' : [],
        'idl_h' : [],
        'res' : [],
        'extra_args' : w_extra_args,
        'src' : w_src,
        'obj' : [],
        'deps': deps,
        'so' : {
            'src' : u_src,
            'extra_args' : [],
            'link' : [
                'ntdll_so',
            ],
            'deps' : [
                gnutls,
                libdl,
            ],
        },
    }
}
