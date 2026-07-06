rc = files(
    'oleaut32.rc',
)

extra_args = [
    '-I../include/msvcrt',
    '-D_UCRT',
    '-D_OLEAUT32_',
]

extra_dll_args = [
    '-DENTRY_PREFIX=OLEAUTPS_', '-DPROXY_DELEGATION', '-DWINE_REGISTER_DLL',
    '-DPROXY_CLSID=CLSID_PSFactoryBuffer',
]

res = gen_rc_res.process(rc, extra_args : extra_args + extra_dll_args)

idls = files(
    'oleaut32_oaidl.idl',
    'oleaut32_ocidl.idl',
)

idl_c = gen_idl_c.process(idls)
idl_h = gen_idl_h.process(idls)

src = files(
    'connpt.c',
    'dispatch.c',
    'hash.c',
    'oleaut.c',
    'olefont.c',
    'olepicture.c',
    'olepropframe.c',
    'recinfo.c',
    'safearray.c',
    'thunks.c',
    'typelib.c',
    'usrmarshal.c',
    'varformat.c',
    'variant.c',
    'vartype.c',
)

deps = [
    'uuid',
    'ole32',
    'rpcrt4',
    'user32',
    'gdi32',
    'advapi32',
    'comctl32',
    'urlmon',
    'windowscodecs',
    'winecrt0',
    'ucrtbase',
    'kernel32',
    'ntdll',
]

dlls += {
    'oleaut32' : {
        'idl_c' : idl_c,
        'idl_h' : idl_h,
        'res' : res,
        'extra_args' : extra_args,
        'src' : src,
        'obj' : [],
        'deps' : deps,
    }
}
