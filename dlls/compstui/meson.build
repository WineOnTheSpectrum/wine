src = files(
    'compstui_main.c',
)

rc = files(
    'compstui.rc'
)

extra_args = [
    '-I../include/msvcrt',
    '-D_UCRT',
    '-D__WINESRC__',
]

res = gen_rc_res.process(rc, extra_args : extra_args)

deps = [
    'comctl32',
    'user32',
    'winecrt0',
    'ucrtbase',
    'kernel32',
    'ntdll',
]

dlls += {
    'compstui' : {
        'idl_c' : [],
        'idl_h' : [],
        'res' : res,
        'extra_args' : extra_args,
        'src' : src,
        'obj' : [],
        'deps' : deps,
    }
}
