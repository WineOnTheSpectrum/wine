src = files(
    'cdlg32.c',
    'colordlg.c',
    'filedlg.c',
    'filedlg31.c',
    'filedlgbrowser.c',
    'finddlg.c',
    'fontdlg.c',
    'itemdlg.c',
    'printdlg.c',
    #'pd32_collate.svg',
    #'pd32_landscape.svg',
    #'pd32_nocollate.svg',
    #'pd32_portrait.svg',
)

rc = files(
    'comdlg32.rc',
)

extra_args = [
    '-I../include/msvcrt',
    '-D_UCRT',
    '-D_COMDLG32_',
]

res = gen_rc_res.process(rc, extra_args : extra_args)

idls = files(
    'comdlg32_classes.idl',
)

idl_c = gen_idl_c.process(idls)
idl_h = gen_idl_h.process(idls)

deps = [
    'uuid',
    'shell32',
    'comctl32',
    'winspool',
    'user32',
    'gdi32',
    'advapi32',
    'ole32',
    'winecrt0',
    'ucrtbase',
    'kernel32',
    'ntdll',
    'shlwapi', # delay?
]

manifest = files(
    'comdlg32.manifest',
)

dlls += {
    'comdlg32' : {
        'idl_c' : idl_c,
        'idl_h' : idl_h,
        'res' : res,
        'extra_args' : extra_args,
        'src' : src,
        'obj' : [],
        'deps' : deps,
        'manifest' : manifest,
    }
}
