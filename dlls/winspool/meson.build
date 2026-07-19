u_src = files(
    'cups.c',
)

w_src = files(
    'info.c',
    'wspool.c',
)

rc = files(
    'winspool.rc',
)

rc_extra_args = [
    '-I../include/msvcrt',
    '-D_UCRT',
    '-D__WINESRC__',
]

res = gen_rc_res.process(rc, extra_args : rc_extra_args)

deps = [
    'user32',
    'gdi32',
    'advapi32',
    'compstui',
    'winecrt0',
    'ucrtbase',
    'kernel32',
    'ntdll',
]

dlls += {
    'winspool' : {
        'idl_h' : [],
        'idl_c' : [],
        'src' : w_src,
        'res' : res,
        'extra_args' : rc_extra_args,
        'obj' : [],
        'deps' : deps,
        'so' : {
            'src' : u_src,
            'deps' : [cups, libdl],
            'link' : ['ntdll_so'],
        },
        'drv' : true,
    },
}
