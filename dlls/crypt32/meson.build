rc = files(
    'crypt32.rc',
)

rc_extra_args = [
    '-I../include/msvcrt',
    '-D_UCRT', '-D_CRYPT32_',
    '-D__WINESRC__',
]

res = gen_rc_res.process(rc, extra_args : rc_extra_args)

u_src = files(
    'unixlib.c',
)

u_extra_args = [
    '-D_CRYPT32_',
    '-DWINE_UNIX_LIB', '-D__WINESRC__',
]

w_src = files(
    'base64.c',
    'cert.c',
    'chain.c',
    'collectionstore.c',
    'context.c',
    'crl.c',
    'ctl.c',
    'decode.c',
    'encode.c',
    'filestore.c',
    'main.c',
    'message.c',
    'msg.c',
    'object.c',
    'oid.c',
    'pfx.c',
    'proplist.c',
    'protectdata.c',
    'provstore.c',
    'regstore.c',
    'rootstore.c',
    'serialize.c',
    'sip.c',
    'store.c',
    'str.c',
)

crypt32_so_64 = shared_library('crypt32', [u_src],
    name_prefix : '',
    include_directories : [
        config_h_inc,
	incdir,
    ],
    c_args : u_extra_args,
    dependencies : [libdl],
    link_with : [bcrypt_so_64, ntdll_so_64],
    native : true,
    build_by_default : not meson.is_cross_build(),
)

deps = [
    'user32',
    'advapi32',
    'bcrypt',
    'cryptnet',
    'winecrt0',
    'ucrtbase',
    'kernel32',
    'ntdll',
]

dlls += {
    'crypt32' : {
        'idl_c' : [],
        'idl_h' : [],
        'res' : res,
        'extra_args' : rc_extra_args,
        'src' : w_src,
        'obj' : [],
        'deps': deps,
    }
}
