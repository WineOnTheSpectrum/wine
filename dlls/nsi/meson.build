src = files(
    'nsi.c',
)

extra_args = [
    '-I../include/msvcrt',
    '-D_UCRT',
]

deps = [
    'winecrt0',
    'ucrtbase',
    'kernel32',
    'ntdll',
]

dlls += {
    'nsi' : {
        'idl_c' : [],
        'idl_h' : [],
        'res' : [],
        'extra_args' : extra_args,
        'src' : src,
        'obj' : [],
        'deps' : deps,
    }
}
