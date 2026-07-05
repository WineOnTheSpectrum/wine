src = files(
    'shdocvw_main.c',
    'shlinstobj.c',
)

rc = files(
    'shdocvw.rc',
)

extra_args = [
    '-I../../include/msvcrt',
    '-D_UCRT',
]

res = gen_rc_res.process(rc, extra_args : extra_args)

idls = files(
    'shdocvw_v1.idl',
)

idl_c = gen_idl_c.process(idls)
idl_h = gen_idl_h.process(idls)

deps = [
    'uuid',
    'shlwapi',
    'advapi32',
    'version',
    'ole32',
    'oleaut32',
    'ieframe',
    'winecrt0',
    'ucrtbase',
    'kernel32',
    'ntdll',
]

dlls += {
    'shdocvw' : {
        'idl_c' : idl_c,
        'idl_h' : idl_h,
        'res' : res,
        'extra_args' : extra_args,
        'src' : src,
        'deps' : deps,
    }
}
