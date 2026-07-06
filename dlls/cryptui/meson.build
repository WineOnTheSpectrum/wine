src = files(
    'main.c',
)

rc = files(
    'cryptui.rc',
)

extra_args = [
    '-I../include/msvcrt',
    '-D_UCRT',
]

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
    'wintrust', # delay?
    'urlmon', # delay?
    'winecrt0',
    'ucrtbase',
    'kernel32',
    'ntdll',
]

dlls += {
    'cryptui' : {
        'idl_c' : [],
        'idl_h' : [],
        'res' : res,
        'extra_args' : extra_args,
        'src' : src,
        'obj' : [],
        'deps' : deps,
    }
}
