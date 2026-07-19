src_w = files(
    'main.c',
    'name.c',
    'query.c',
    'record.c',
)

src_u = files(
    'libresolv.c',
)

rc = files(
    'version.rc',
)

extra_args = [
    '-I../include/msvcrt',
    '-D_UCRT',
    '-D__WINESRC__',
]

res = gen_rc_res.process(rc, extra_args : extra_args)

deps = [
    'winecrt0',
    'ucrtbase',
    'kernel32',
    'ntdll',
    'netapi32', # delay?
]

dlls += {
    'dnsapi' : {
        'idl_c' : [],
        'idl_h' : [],
        'res' : res,
        'extra_args' : extra_args,
        'src' : src_w,
        'obj' : [],
        'deps' : deps,
        'so' : {
            'src' : src_u,
            'extra_args' : [],
            'link' : [
                'ntdll_so',
            ],
            'deps': [
                libdl,
                pthread,
            ],
        },
    }
}
