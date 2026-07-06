src = files(
   'access.c', 
   'imagehlp_main.c',
   'integrity.c',
   'modify.c',
)

extra_args = [
    '-I../include/msvcrt',
    '-D_UCRT', '-D_IMAGEHLP_SOURCE_',
]

deps = [
    'dbghelp',
    'winecrt0',
    'ucrtbase',
    'kernel32',
    'ntdll',
]

dlls += {
    'imagehlp' : {
        'idl_c' : [],
        'idl_h' : [],
        'res' : [],
        'extra_args' : extra_args,
        'src' : src,
        'obj' : [],
        'deps' : deps,
    }
}
