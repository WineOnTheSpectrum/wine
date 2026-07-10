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
    '-D__WINE_PE_BUILD',
]

idls = files(
    'atsvc.idl',
)

idl_c = gen_idl_c.process(idls, extra_args : extra_args)
idl_h = gen_idl_h.process(idls, extra_args : extra_args)

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

netapi32_w_af2_64 = static_library('netapi32_w_af2_64', [headers, src_w, idl_h, idl_c],
    include_directories : [incdir, '.'],
    c_args : extra_flags_64 + extra_args,
    native : false,
    build_by_default : meson.is_cross_build(),
)

netapi32_w_o2_64 = netapi32_w_af2_64.extract_all_objects(recursive : true)

dlls += {
    'netapi32' : {
        'idl_c' : idl_c,
        'idl_h' : idl_h,
        'res' : [],
        'extra_args' : extra_args,
        'src' : src_w,
        'obj' : netapi32_w_o2_64,
        'deps' : deps,
    }
}
