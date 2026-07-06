rc = files(
    'version.rc',
)

extra_args = [
    '-I../include/msvcrt',
    '-D_MSVCR_VER=0', '-D_ADVAPI32_',
]

res = gen_rc_res.process(rc, extra_args : extra_args)

src = files(
    'advapi.c',
    'cred.c',
    'crypt.c',
    'crypt_arc4.c',
    'crypt_des.c',
    'crypt_lmhash.c',
    'eventlog.c',
    'lsa.c',
    'registry.c',
    'security.c',
    'service.c',
    'wmi.c',
)

deps = [
    'kernelbase',
    'sechost',
    'rpcrt4', # delay?
    'user32', # delay?
    'winecrt0',
    'msvcrt',
    'kernel32',
    'ntdll',
]

dlls += {
    'advapi32' : {
        'idl_c' : [],
        'idl_h' : [],
        'res' : res,
        'extra_args' : extra_args,
        'src' : src,
        'deps' : deps,
    }
}
