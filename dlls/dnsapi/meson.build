src_w = files(
    'main.c',
    'name.c',
    'query.c',
    'record.c',
)

src_u = files(
    'libresolv.c',
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
    #'netapi32',
    'winecrt0',
    'ucrtbase',
    'kernel32',
    'ntdll',
]

dnsapi_so_64 = shared_library('dnsapi_so_64', [src_u],
    include_directories : [
        config_h_inc,
	incdir,
    ],
    c_args : [
        '-DWINE_UNIX_LIB',
    ] + datadir_define + dllpath_define,
    native : true,
    link_with : [ntdll_so_64],
    dependencies : [libdl, pthread],
    build_by_default : not meson.is_cross_build(),
)

dlls += {
    'dnsapi' : {
        'idl_h' : [],
        'res' : res,
        'extra_args' : extra_args,
        'src' : src_w,
        'deps' : deps,
    }
}
