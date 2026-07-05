src = files(
    'asn.c',
    'crypt.c',
    'register.c',
    'softpub.c',
    'wintrust_main.c',
)

rc = files(
    'version.rc',
)

extra_args = [
    '-I../include/msvcrt',
    '-D_UCRT',
]

res = gen_rc_res.process(rc, extra_args : extra_args)

deps = [
    'crypt32',
    'user32',
    'advapi32',
    'cryptui', #
    'imagehlp', #
    'winecrt0',
    'ucrtbase',
    'kernel32',
    'ntdll',
]

dlls += {
    'wintrust' : {
        'idl_c' : [],
        'idl_h' : [],
        'res' : res,
        'extra_args' : extra_args,
        'src' : src,
        'deps' : deps,
    }
}
