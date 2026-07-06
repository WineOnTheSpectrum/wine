src_w = files(
    'nbcmdqueue.c',
    'nbnamecache.c',
    'nbt.c',
    'netapi32.c',
    'netbios.c',
)

src_u = files(
    'unixlib.c',
)

extra_args = [
    '-I../include/msvcrt',
    '-D_UCRT',
    '-D__WINESRC__',
]

idls = files(
    'atsvc.idl',
)

idl_c = gen_idl_c.process(idls)
idl_h = gen_idl_h.process(idls)

deps = [
    'rpcrt4',
    'iphlpapi',
    'ws2_32',
    'advapi32',
    'dnsapi',
    'netutils',
    'winecrt0',
    'ucrtbase',
    'kernel32',
    'ntdll',
]

netapi32_so_64 = shared_library('netapi32_so_64', [src_u],
    include_directories : [
        config_h_inc,
	incdir,
    ],
    c_args : [
        '-DWINE_UNIX_LIB', '-D__WINESRC__',
    ] + datadir_define + dllpath_define,
    native : true,
    link_with : [ntdll_so_64],
    dependencies : [libdl, pthread],
    build_by_default : not meson.is_cross_build(),
)

dlls += {
    'netapi32' : {
        'idl_c' : idl_c,
        'idl_h' : idl_h,
        'res' : [],
        'extra_args' : extra_args,
        'src' : src,
        'deps' : deps,
    }
}
