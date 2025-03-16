src = files(
    'cryptnet_main.c',
)

extra_args = [
    '-I../include/msvcrt',
    '-D_UCRT',
]

deps = [
    'crypt32',
    'shell32',
    'ole32',
    'advapi32',
    'wininet',
    'winecrt0',
    'ucrtbase',
    'kernel32',
    'ntdll',
]

dlls += {
    'cryptnet' : {
        'idl_h' : [],
        'res' : [],
        'extra_args' : extra_args,
        'src' : src,
        'deps' : deps,
    }
}
