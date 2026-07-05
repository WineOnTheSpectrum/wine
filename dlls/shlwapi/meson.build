src = files(
    'assoc.c',
    'clist.c',
    'istream.c',
    'msgbox.c',
    'ordinal.c',
    'path.c',
    'reg.c',
    'regstream.c',
    'shlwapi_main.c',
    'stopwatch.c',
    'string.c',
    'thread.c',
    'url.c',
)

rc = files(
    'shlwapi.rc',
)

extra_args = [
    '-I../include/msvcrt',
    '-D_UCRT',
    '-D_SHLWAPI_',
]

res = gen_rc_res.process(rc, extra_args : extra_args)

deps = [
    'uuid',
    'shcore',
    'user32',
    'gdi32',
    'advapi32',
    'kernelbase',
    'userenv',
    'oleaut32',
    'ole32',
    'comctl32',
    'comdlg32',
    'mpr',
    'mlang',
    'urlmon', #XXX
    'shell32',
    'winmm',
    'winecrt0',
    'ucrtbase',
    'kernel32',
    'ntdll',
]

dlls += {
    'shlwapi' : {
        'idl_c' : [],
        'idl_h' : [],
        'res' : res,
        'extra_args' : extra_args,
        'src' : src,
        'deps' : deps,
    }
}
