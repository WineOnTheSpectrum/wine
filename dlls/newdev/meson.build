src = files(
    'main.c',
)

extra_args = [
    '-I../include/msvcrt',
    '-D_UCRT',
]

deps = [
    'setupapi',
    'winecrt0',
    'ucrtbase',
    'kernel32',
    'ntdll',
]

dlls += {
    'newdev' : {
        'idl_c' : [],
        'idl_h' : [],
        'res' : res,
        'extra_args' : extra_args,
        'src' : src,
        'obj' : [],
        'deps' : deps,
    }
}
