src = files(
    'buffer.c',
    'dialog.c',
    'draw.c',
    'main.c',
    'metric.c',
    'msstyles.c',
    'property.c',
    'scrollbar.c',
    'stylemap.c',
    'system.c',
    'uxini.c',
    'window.c',
)

rc = files(
    'version.rc',
)

extra_args = [
    '-I../include/msvcrt',
    '-I../dlls/uxtheme',
    '-D_UCRT',
    '-D_UXTHEME_',
]

res = gen_rc_res.process(rc, extra_args : extra_args)

deps = [
    'user32',
    'gdi32',
    'advapi32',
    'winecrt0',
    'ucrtbase',
    'kernel32',
    'ntdll',
    #XXX 'msimg32', # delay?
]

dlls += {
    'uxtheme' : {
        'idl_c' : [],
        'idl_h' : [],
        'res' : res,
        'extra_args' : extra_args,
        'src' : src,
        'obj' : [],
        'deps' : deps,
    }
}
