src = files(
    'axinstall.c',
    'bindctx.c',
    'binding.c',
    'bindprot.c',
    'download.c',
    'file.c',
    'format.c',
    'ftp.c',
    'gopher.c',
    'http.c',
    'internet.c',
    'mimefilter.c',
    'mk.c',
    'protocol.c',
    'sec_mgr.c',
    'session.c',
    'umon.c',
    'umstream.c',
    'uri.c',
    'urlmon_main.c',
    'usrmarshal.c',
)

rc = files(
    'urlmon.rc',
)

extra_args = [
    '-I../include/msvcrt',
    '-D_UCRT',
    '-DENTRY_PREFIX=URLMON_',
    '-DPROXY_DELEGATION',
    '-DWINE_REGISTER_DLL',
    '-DPROXY_CLSID_IS="{0x79EAC9F1,0xBAF9,0x11CE,{0x8C,0x82,0x00,0xAA,0x00,0x4B,0xA9,0x0B}}"',
]

res = gen_rc_res.process(rc, extra_args : extra_args)

idls = files(
    'urlmon_urlmon.idl',
)

idl_c = gen_idl_c.process(idls, extra_args : extra_args)
idl_h = gen_idl_h.process(idls, extra_args : extra_args)

deps = [
    'uuid',
    'ole32',
    'oleaut32',
    'shell32',
    'rpcrt4',
    'shlwapi',
    'wininet',
    'user32',
    'advapi32',
    'winecrt0',
    'ucrtbase',
    'kernel32',
    'ntdll',
    'advpack', # delay?
]

dlls += {
    'urlmon' : {
        'idl_c' : idl_c,
        'idl_h' : idl_h,
        'res' : res,
        'extra_args' : extra_args,
        'src' : src,
        'obj' : [],
        'deps' : deps,
    }
}
