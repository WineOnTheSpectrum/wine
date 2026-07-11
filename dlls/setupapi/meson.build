src = files(
    'devinst.c',
    'dialog.c',
    'dirid.c',
    'diskspace.c',
    'fakedll.c',
    'install.c',
    'misc.c',
    'parser.c',
    'query.c',
    'queue.c',
    'setupcab.c',
    'stringtable.c',
    'stubs.c',
)

rc = files(
    'setupapi.rc',
)

extra_args = [
    '-I../include/msvcrt',
    '-D_UCRT',
    '-D_SETUPAPI_',
]

idls = files(
    '../../include/atliface.idl',
)

idl_h = gen_idl_h.process(idls, extra_args : extra_args)

res = gen_rc_res.process(rc, extra_args : extra_args)

deps = [
    'uuid',
    'advapi32',
    'rpcrt4',
    'kernelbase',
    'cabinet',
    'shell32',
    'ole32',
    'comdlg32',
    'user32',
    'version',
    'winecrt0',
    'ucrtbase',
    'kernel32',
    'ntdll',
    'wintrust', # delay?
]

dlls += {
    'setupapi' : {
        'idl_c' : [],
        'idl_h' : idl_h,
        'res' : res,
        'extra_args' : extra_args,
        'src' : src,
        'obj' : [],
        'deps' : deps,
    }
}
