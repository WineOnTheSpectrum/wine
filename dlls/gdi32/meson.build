rc = files(
    'gdi32.rc',
)

extra_args = [
    '-D_GDI32_',
]

res = gen_rc_res.process(rc, extra_args : extra_args)

src = files(
    'dc.c',
    'emfdc.c',
    'enhmetafile.c',
    'icm.c',
    'metadc.c',
    'metafile.c',
    'objects.c',
    'opengl.c',
    'text.c',
    'uniscribe/bidi.c',
    'uniscribe/bracket.c',
    'uniscribe/breaking.c',
    'uniscribe/direction.c',
    'uniscribe/indic.c',
    'uniscribe/indicsyllable.c',
    'uniscribe/linebreak.c',
    'uniscribe/mirror.c',
    'uniscribe/opentype.c',
    'uniscribe/shape.c',
    'uniscribe/shaping.c',
    'uniscribe/usp10.c',
)

deps = [
    'user32',
    'advapi32',
    'win32u',
    'winspool',
    'winecrt0',
    'ucrtbase',
    'kernel32',
    'ntdll',
]

dlls += {
    'gdi32' : {
        'idl_h' : [],
        'res' : res,
        'extra_args' : extra_args,
        'src' : src,
        'deps' : deps,
    }
}
