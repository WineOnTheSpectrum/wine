rc = files(
    'version.rc',
)

extra_args = [
    '-I../include/msvcrt',
    '-D_MSVCR_VER=0', '-D_ADVAPI32_',
]

res = gen_rc_res.process(rc, extra_args : extra_args)

idls = files(
    '../../include/iads.idl',
)

idl_h = gen_idl_h.process(idls, extra_args : extra_args)

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
    'winecrt0',
    'ucrtbase', #XXX should be msvcrt
    'kernel32',
    'ntdll',
    'rpcrt4', # delay?
    'user32', # delay?
]

dlls += {
    'advapi32' : {
        'idl_c' : [],
        'idl_h' : idl_h,
        'res' : res,
        'extra_args' : extra_args,
        'src' : src,
        'obj' : [],
        'deps' : deps,
    }
}
