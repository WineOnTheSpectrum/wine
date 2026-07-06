u_src = files(
    'schannel_gnutls.c',
)

u_extra_args = [
    '-DWINE_UNIX_LIB', '-D__WINESRC__',
]

w_src = files(
    'lsa.c',
    'negotiate.c',
    'schannel.c',
    'secur32.c',
    'thunks.c',
    'wrapper.c',
)

w_extra_args = [
    '-I../include/msvcrt',
    '-D_UCRT',
    '-D__WINESRC__',
]

deps = [
    'advapi32',
    'crypt32',
    'winecrt0',
    'ucrtbase',
    'kernel32',
    'ntdll',
]

secur32_so_64 = shared_library('secur32_so_64', [u_src],
    include_directories : [
        config_h_inc,
	incdir,
    ],
    c_args : u_extra_args,
    dependencies : [gnutls, libdl],
    link_with : [ntdll_so_64],
    native : true,
    build_by_default : not meson.is_cross_build(),
)

dlls += {
    'secur32' : {
        'idl_c' : [],
        'idl_h' : [],
        'res' : [],
        'extra_args' : w_extra_args,
        'src' : w_src,
        'obj' : [],
        'deps': deps,
    }
}
