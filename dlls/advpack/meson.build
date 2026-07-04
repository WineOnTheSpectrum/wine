src = files( 
    'advpack.c',
    'files.c',
    'install.c',
    'reg.c',
)

extra_args = [
    '-I../include/msvcrt',
    '-D_UCRT',
]

deps = [
    'ole32',
    'setupapi',
    'version',
    'advapi32',
    'winecrt0',
    'ucrtbase',
    'kernel32',
    'ntdll',
]

dlls += {
    'advpack' : {
        'idl_h' : [],
        'res' : [],
        'extra_args' : extra_args,
        'src' : src,
        'deps' : deps,
    }
}
