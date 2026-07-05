rc = files(
    'version.rc',
)

rc_extra_args = [
    '-I../include/msvcrt',
    '-I../libs/tomcrypt/src/headers',
    '-D_UCRT', '-DLTC_NO_PROTOTYPES', '-DLTC_SOURCE',
]

res = gen_rc_res.process(rc, extra_args : rc_extra_args)

w_src = files(
    'bcrypt_main.c',
)

u_src = files(
    'gnutls.c',
)

u_extra_args = [
    '-DWINE_UNIX_LIB', '-DLTC_NO_PROTOTYPES', '-DLTC_SOURCE',
]

deps = [
    'tomcrypt',
    'advapi32',
    'winecrt0',
    'ucrtbase',
    'kernel32',
    'ntdll',
]

bcrypt_so_64 = shared_library('bcrypt_so_64', [u_src],
    include_directories : [
        config_h_inc,
	incdir,
    ],
    c_args : u_extra_args,
    link_with : [ntdll_so_64],
    native : true,
    build_by_default : not meson.is_cross_build(),
)

dlls += {
    'bcrypt' : {
        'idl_h' : [],
        'res' : res,
        'extra_args' : rc_extra_args,
        'src' : src,
        'deps': deps,
    }
}
