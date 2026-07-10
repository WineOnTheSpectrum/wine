src = files(
    'client.c',
    'main.c',
    'propservice.c',
    'window.c',
)

rc = files(
    'oleacc.rc',
)

extra_args = [
    '-I../include/msvcrt',
    '-D_UCRT', '-D_OLEACC_',
]

extra_dll_args = [
    '-DENTRY_PREFIX=OLEACC_', '-DPROXY_DELEGATION', '-DWINE_REGISTER_DLL',
]

res = gen_rc_res.process(rc, extra_args : extra_dll_args)

idls = files(
    'oleacc_classes.idl',
)

idl_h = gen_idl_h.process(idls, extra_args : extra_dll_args)
idl_c = gen_idl_c.process(idls, extra_args : extra_dll_args)
idl_t = gen_idl_tres.process(idls, extra_args : extra_dll_args)
idl_r = gen_idl_rres.process(idls, extra_args : extra_dll_args)
idl_p = gen_idl_p_c.process(idls, extra_args : extra_dll_args)
idl_d = gen_idl_dlldata.process(idls, extra_args : extra_dll_args)

deps = [
    'uuid',
    'oleaut32',
    'ole32',
    'user32',
    'rpcrt4',
    'winecrt0',
    'ucrtbase',
    'kernel32',
    'ntdll',
]

dlls += {
    'oleacc' : {
        'idl_c' : [idl_c, idl_t, idl_r, idl_p, idl_d],
        'idl_h' : [stdole2_tlb, idl_h],
        'res' : res,
        'extra_args' : extra_args + extra_dll_args,
        'src' : src,
        'obj' : [],
        'deps' : deps,
    }
}
