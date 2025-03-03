idls = files(
    'dcom.idl',
    'irpcss.idl',
)

idl_h = gen_idl_h.process(idls)

src = files(
    'apartment.c',
    'combase.c',
    'errorinfo.c',
    'hglobalstream.c',
    'malloc.c',
    'marshal.c',
    'roapi.c',
    'rpc.c',
    'string.c',
    'stubmanager.c',
    'usrmarshal.c',
)

deps = [
    'advapi32',
    'ole32',
    'user32',
    'gdi32',
    'uuid',
    'rpcrt4',
    'oleaut32',
    'winecrt0',
    'ucrtbase',
    'kernel32',
    'ntdll',
]

dlls += {
    'combase' : {
        'idl_h' : idl_h,
        'res' : [],
        'extra_args' : [],
        'src' : src,
        'deps' : deps,
    }
}
