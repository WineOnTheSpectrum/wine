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

res = gen_rc_res.process(rc, extra_args : extra_args + extra_dll_args)

idls = files(
    'oleacc_classes.idl',
)

idl_h = gen_idl_h.process(idls)

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
        'idl_h' : idl_h,
        'res' : res,
        'extra_args' : extra_args,
        'src' : src,
        'deps' : deps,
    }
}
