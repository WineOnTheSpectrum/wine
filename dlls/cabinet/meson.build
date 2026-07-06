src = files(
    'cabinet_main.c',
    'fci.c',
    'fdi.c',
)

rc = files(
    'cabinet.rc',
)

extra_args = [
    '-I../libs/zlib',
    '-I../include/msvcrt',
    '-D_UCRT',
    '-DFAR=', '-DZ_SOLO',
]

res = gen_rc_res.process(rc, extra_args : extra_args)

deps = [
    'zlib',
    'winecrt0',
    'ucrtbase',
    'kernel32',
    'ntdll',
]

dlls += {
    'cabinet' : {
        'idl_c' : [],
        'idl_h' : [],
        'res' : res,
        'extra_args' : extra_args,
        'src' : src,
        'obj' : [],
        'deps' : deps,
    }
}
