src = files(
    'brush.c',
    'customlinecap.c',
    'font.c',
    'gdiplus.c',
    'graphics.c',
    'graphicspath.c',
    'image.c',
    'imageattributes.c',
    'matrix.c',
    'metafile.c',
    'pathiterator.c',
    'pen.c',
    'region.c',
    'stringformat.c',
)

rc = files(
    'gdiplus.rc',
)

extra_args = [
    '-I../include/msvcrt',
    '-D_UCRT',
]

res = gen_rc_res.process(rc, extra_args : extra_args)

deps = [
    'uuid',
    'shlwapi',
    'oleaut32',
    'user32',
    'gdi32',
    'mlang',
    'windowscodecs',
    'winecrt0',
    'ucrtbase',
    'kernel32',
    'ntdll',
]

dlls += {
    'gdiplus' : {
        'idl_c' : [],
        'idl_h' : [],
        'res' : res,
        'extra_args' : extra_args,
        'src' : src,
        'deps' : deps,
    }
}
