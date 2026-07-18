idl0 = files(
    'dcom.idl',
    '../../include/ctxtcall.idl',
    '../../include/activation.idl',
    '../../include/inspectable.idl',
    '../../include/hstring.idl',
)

idl1 = files(
    'irpcss.idl',
    '../../include/roparameterizediid.idl',
    '../../include/restrictederrorinfo.idl',
)

extra_args = [
    '-I../include/msvcrt',
    '-D_UCRT',
    '-D__WINESRC__',
    '-DWINOLE32API=',
    '-D__WINE_PE_BUILD',
]

idl_c = gen_idl_c.process(idl1, extra_args : extra_args)
idl_h = gen_idl_h.process([idl0, idl1], extra_args : extra_args)

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
        'idl_c' : idl_c,
        'idl_h' : idl_h,
        'res' : [],
        'extra_args' : extra_args,
        'src' : src,
        'obj' : [],
        'deps' : deps,
    }
}
