rc = files(
    'version.rc',
)

rc_extra_args = [
    '-I../include/msvcrt',
    '-I../libs/tomcrypt/src/headers',
    '-D_UCRT', '-DLTC_NO_PROTOTYPES', '-DLTC_SOURCE',
    '-D__WINESRC__',
]

res = gen_rc_res.process(rc, extra_args : rc_extra_args)

w_src = files(
    'bcrypt_main.c',
)

u_src = files(
    'gnutls.c',
)

u_extra_args = [
    '-DWINE_UNIX_LIB', '-D__WINESRC__',
    '-DLTC_NO_PROTOTYPES', '-DLTC_SOURCE',
]

deps = [
    'tomcrypt',
    'advapi32',
    'winecrt0',
    'ucrtbase',
    'kernel32',
    'ntdll',
]

dlls += {
    'bcrypt' : {
        'idl_c' : [],
        'idl_h' : [],
        'res' : res,
        'extra_args' : rc_extra_args,
        'src' : w_src,
        'obj' : [],
        'deps': deps,
        'so' : {
            'src' : u_src,
            'extra_args' : u_extra_args,
            'link' : ['ntdll_so'],
            'deps' : [],
        },
    }
}
