src = files(
    'memlockbytes.c',
    'stg_prop.c',
    'storage32.c',
)

extra_args = [
    '-I../include/msvcrt',
    '-D_UCRT',
    '-DWINOLE32API=',
]

deps = [
    'uuid',
    'winecrt0',
    'ucrtbase',
    'kernel32',
    'ntdll',
]

dlls += {
    'coml2' : {
        'idl_h': [],
        'res': [],
        'extra_args' : extra_args,
        'src' : src,
        'deps' : deps,
    }
}
