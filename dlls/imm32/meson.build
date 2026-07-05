rc = files(
    'version.rc',
)

extra_args = [
    '-I../../include/msvcrt',
    '-D_UCRT',
]

res = gen_rc_res.process(rc, extra_args : extra_args)

src = files(
    'ime.c',
    'imm.c',
)

deps = [
    'user32',
    'gdi32',
    'advapi32',
    'kernelbase',
    'win32u',
    'ole32',
    'winecrt0',
    'ucrtbase',
    'kernel32',
    'ntdll',
]

dlls += {
    'imm32' : {
        'idl_c' : [],
        'idl_h' : [],
        'res' : res,
        'extra_args' : extra_args,
        'src' : src,
        'deps' : deps,
    }
}
