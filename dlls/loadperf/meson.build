src = files(
    'loadperf_main.c',
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
    'loadperf' : {
        'idl_c' : [],
        'idl_h' : [],
        'res' : [],
        'extra_args' : extra_args,
        'src' : src,
        'obj' : [],
        'deps' : deps,
    }
}
