src = files(
    'userenv_main.c',
)

extra_args = [
    '-I../../include/msvcrt',
    '-D_UCRT',
    '-D_USERENV_',
]

deps = [
    'advapi32',
    'winecrt0',
    'ucrtbase',
    'kernel32',
    'ntdll',
]

dlls += {
    'userenv' : {
        'idl_c' : [],
        'idl_h' : [],
        'res' : [],
        'extra_args' : extra_args,
        'src' : src,
        'deps' : deps,
    }
}
