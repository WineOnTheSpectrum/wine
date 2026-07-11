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
    '-D__WINESRC__', '-D__WINE_PE_BUILD',
]

idls = files(
    '../../include/mlang.idl',
    '../../include/wincodec.idl',
    '../../include/wincodecsdk.idl',
)

idl_h = gen_idl_h.process(idls, extra_args : extra_args)

res = gen_rc_res.process(rc, extra_args : extra_args)

deps = [
    'uuid',
    'shlwapi',
    'ole32',
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
        'idl_h' : idl_h,
        'res' : res,
        'extra_args' : extra_args,
        'src' : src,
        'obj' : [],
        'deps' : deps,
    }
}
