src = files(
    'main.c',
)

rc = files(
    'cryptui.rc',
)

extra_args = [
    '-I../include/msvcrt',
    '-D_UCRT',
    '-D__WINESRC__',
]

idls = files(
    '../../include/richole.idl',
    '../../include/hlink.idl',
)

idl_h = gen_idl_h.process(idls, extra_args : extra_args)

res = gen_rc_res.process(rc, extra_args : extra_args)

deps = [
    'uuid',
    'crypt32',
    'ole32',
    'comctl32',
    'comdlg32',
    'user32',
    'gdi32',
    'advapi32',
    'winecrt0',
    'ucrtbase',
    'kernel32',
    'ntdll',
    'wintrust', # delay?
    'urlmon', # delay?
]

dlls += {
    'cryptui' : {
        'idl_c' : [],
        'idl_h' : idl_h,
        'res' : res,
        'extra_args' : extra_args,
        'src' : src,
        'obj' : [],
        'deps' : deps,
    }
}
