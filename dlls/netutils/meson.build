src = files(
    'main.c',
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
    'netutils' : {
        'idl_h' : [],
        'res' : [],
        'extra_args' : extra_args,
        'src' : src,
        'deps' : deps,
    }
}
