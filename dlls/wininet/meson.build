mc = files(
    'winineterror.mc',
)

extra_args = [
    '-I../include/msvcrt',
    '-I../libs/zlib',
    '-D_UCRT', '-D_WININET_INTERNAL_',
    '-DFAR=', '-DZ_SOLO',
]

rc = files(
    'wininet.rc',
)

res1 = gen_mc_res.process(mc, extra_args : extra_args)
pot1 = gen_mc_pot.process(mc, extra_args : extra_args)
res2 = gen_rc_res.process(rc, extra_args : extra_args)

src = files(
    'cookie.c',
    'dialogs.c',
    'ftp.c',
    'gopher.c',
    'http.c',
    'internet.c',
    'netconnection.c',
    'urlcache.c',
    'utility.c',
)

deps = [
    'zlib',
    'mpr',
    'shlwapi',
    'shell32',
    'user32',
    'ws2_32',
    'advapi32',
    'secur32',
    'crypt32',
    'cryptui',
    'dhcpcsvc',
    'iphlpapi',
    'winecrt0',
    'ucrtbase',
    'kernel32',
    'ntdll',
]

dlls += {
    'wininet' : {
        'idl_c' : [],
        'idl_h' : [],
        'res' : [res1, res2],
        'extra_args' : extra_args,
        'src' : src,
        'obj' : [],
        'deps' : deps,
    }
}
