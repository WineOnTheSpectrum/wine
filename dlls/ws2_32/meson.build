src_w = files(
    'async.c',
    'inaddr.c',
    'protocol.c',
    'socket.c',
)

src_u = files(
    'unixlib.c',
)

rc = files(
    'version.rc',
)

extra_args = [
    '-I../include/msvcrt',
    '-D_UCRT',
    '-D_WS2_32_',
    '-D__WINESRC__',
]

res = gen_rc_res.process(rc, extra_args : extra_args)

deps = [
    'advapi32',
    'user32',
    'winecrt0',
    'ucrtbase',
    'kernel32',
    'ntdll',
    'dnsapi', # delay?
    'iphlpapi', # delay?
]

ws2_32_so_64 = shared_library('ws2_32', [src_u],
    name_prefix : '',
    include_directories : [
        config_h_inc,
	incdir,
    ],
    c_args : [
        '-D_WS2_32_',
        '-DWINE_UNIX_LIB', '-D__WINESRC__',
    ] + datadir_define + dllpath_define,
    native : true,
    link_with : [ntdll_so_64],
    dependencies : [libdl, pthread],
    build_by_default : not meson.is_cross_build(),
)

dlls += {
    'ws2_32' : {
        'idl_c' : [],
        'idl_h' : [],
        'res' : res,
        'extra_args' : extra_args,
        'src' : src_w,
        'obj' : [],
        'deps' : deps,
    }
}
