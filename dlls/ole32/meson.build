rc = files(
    'ole32res.rc',
)

extra_args = [
    '-I../include/msvcrt',
    '-D_UCRT', '-D_OLE32_',
    '-DENTRY_PREFIX=OLE32_', '-DPROXY_CLSID=CLSID_PSFactoryBuffer', '-DWINE_REGISTER_DLL',
]

res = gen_rc_res.process(rc, extra_args : extra_args)

idls = files(
    'dcom.idl',
    'irot.idl',
    'ole32_objidl.idl',
    'ole32_oleidl.idl',
    'ole32_unknwn.idl',
)

idl_c = gen_idl_c.process(idls)
idl_h = gen_idl_h.process(idls)

src = files(
    'antimoniker.c',
    'bindctx.c',
    'classmoniker.c',
    'clipboard.c',
    'comcat.c',
    'compobj.c',
    'compositemoniker.c',
    'datacache.c',
    'defaulthandler.c',
    'dictionary.c',
    'filelockbytes.c',
    'filemoniker.c',
    'ftmarshal.c',
    'git.c',
    'itemmoniker.c',
    'marshal.c',
    'moniker.c',
    'ole2.c',
    'ole2stubs.c',
    'ole32_main.c',
    'oleobj.c',
    'oleproxy.c',
    'pointermoniker.c',
    'stg_prop.c',
    'stg_stream.c',
    'storage32.c',
    'usrmarshal.c',
)

deps = [
    'uuid',
    'advapi32',
    'user32',
    'gdi32',
    'combase',
    'rpcrt4',
    'kernelbase',
    'coml2',
    'oleaut32',
    'winecrt0',
    'ucrtbase',
    'kernel32',
    'ntdll',
]

dlls += {
    'ole32' : {
        'idl_c' : idl_c,
        'idl_h' : idl_h,
        'res' : res,
        'extra_args' : extra_args,
        'src' : src,
        'deps' : deps,
    }
}
