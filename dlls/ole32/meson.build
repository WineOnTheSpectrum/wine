rc = files(
    'ole32res.rc',
)

extra_args = [
    '-I../include/msvcrt',
    '-D_UCRT', '-D_OLE32_',
    '-DENTRY_PREFIX=OLE32_', '-DPROXY_CLSID=CLSID_PSFactoryBuffer', '-DWINE_REGISTER_DLL',
    '-D__WINESRC__',
]

res = gen_rc_res.process(rc, extra_args : extra_args)

idl0 = files(
    'dcom.idl',
)

idl1 = files(
    'ole32_objidl.idl',
    'ole32_oleidl.idl',
    'ole32_unknwn.idl',
)

idl2 = files(
    'irot.idl',
    '../../include/ctxtcall.idl',
    '../../include/inspectable.idl',
)

idl_h = gen_idl_h.process([idl0, idl1, idl2], extra_args : extra_args)
idl_p = gen_idl_p_c.process([idl0, idl1], extra_args : extra_args)

ole32_dlldata_c = custom_target('ole32_dlldata.c',
    input : [idl0, idl1],
    output : 'ole32_dlldata.c',
    command : [
        widl_bin,
        '-o', '@OUTPUT@',
        '-b', 'x86_64-w64-mingw32',
        '--dlldata-only',
        '--nostdinc',
        '-Ldlls/stdole2.tlb',
        '-Ldlls/*',
        '-I@0@/include'.format(meson.global_source_root()),
        '-I@0@/include/msvcrt'.format(meson.global_source_root()),
    ] + extra_args + [
        '@INPUT0@',
        '@INPUT1@',
        '@INPUT2@',
        '@INPUT3@',
    ],
)

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
        'idl_c' : [idl_p, ole32_dlldata_c],
        'idl_h' : idl_h,
        'res' : res,
        'extra_args' : extra_args,
        'src' : src,
        'obj' : [],
        'deps' : deps,
    }
}
