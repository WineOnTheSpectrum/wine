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

res = gen_rc_res.process(rc, extra_args : extra_args)

deps = [
    'uuid',
    'advapi32',
    'rpcrt4',
    'kernelbase',
    'cabinet',
    'shell32',
    #'wintrust', XXX avoid circular dependency
    'ole32',
    #'comdlg32', XXX add lib
    'user32',
    'version',
    'winecrt0',
    'ucrtbase',
    'kernel32',
    'ntdll',
]

dlls += {
    'setupapi' : {
        'idl_c' : [],
        'idl_h' : [],
        'res' : res,
        'extra_args' : extra_args,
        'src' : src,
        'deps' : deps,
    }
}
