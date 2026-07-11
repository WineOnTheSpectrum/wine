rc = files(
    'oleaut32.rc',
)

extra_args = [
    '-I../include/msvcrt',
    '-D_UCRT',
    '-D_OLEAUT32_',
    '-D__WINESRC__',
]

extra_dll_args = [
    '-DENTRY_PREFIX=OLEAUTPS_', '-DPROXY_DELEGATION', '-DWINE_REGISTER_DLL',
    '-DPROXY_CLSID=CLSID_PSFactoryBuffer',
]

res = gen_rc_res.process(rc, extra_args : extra_args + extra_dll_args)

idls = files(
    'oleaut32_oaidl.idl',
    'oleaut32_ocidl.idl',
    '../../include/wincodec.idl',
)

idl_c = gen_idl_c.process(idls, extra_args : extra_args + extra_dll_args)
idl_h = gen_idl_h.process(idls, extra_args : extra_args + extra_dll_args)
idl_p = gen_idl_p_c.process(idls, extra_args : extra_args + extra_dll_args)
idl_r = gen_idl_rres.process(idls, extra_args : extra_args + extra_dll_args)

oleaut32_dlldata_c = custom_target('oleaut32_dlldata.c',
    input : idls,
    output : 'oleaut32_dlldata.c',
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
    ] + extra_args + extra_dll_args + [
        '@INPUT0@',
        '@INPUT1@',
    ],
)

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
        'idl_c' : [idl_c, idl_p, idl_r, oleaut32_dlldata_c],
        'idl_h' : idl_h,
        'res' : res,
        'extra_args' : extra_args + extra_dll_args,
        'src' : src,
        'obj' : [],
        'deps' : deps,
    }
}
