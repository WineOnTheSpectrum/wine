src = files(
    'driver.c',
    'filter.c',
    'format.c',
    'internal.c',
    'msacm32_main.c',
    'pcmconverter.c',
    'stream.c',
)

rc = files(
    'msacm32.rc',
)

extra_args = [
    '-I../include/msvcrt',
    '-D_UCRT',
]

res = gen_rc_res.process(rc, extra_args : extra_args)

deps = [
    #'winmm', XXX avoid circular dependency
    'user32',
    'advapi32',
    'winecrt0',
    'ucrtbase',
    'kernel32',
    'ntdll',
]

dlls += {
    'msacm32' : {
        'idl_c' : [],
        'idl_h' : [],
        'res' : res,
        'extra_args' : extra_args,
        'src' : src,
        'deps' : deps,
    }
}
