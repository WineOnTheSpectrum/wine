src = files(
    'bitmap.c',
    'bmpdecode.c',
    'bmpencode.c',
    'clipper.c',
    'clsfactory.c',
    'colorcontext.c',
    'colortransform.c',
    'converter.c',
    'ddsformat.c',
    'decoder.c',
    'encoder.c',
    'fliprotate.c',
    'gifformat.c',
    'icoformat.c',
    'imgfactory.c',
    'info.c',
    'libjpeg.c',
    'libpng.c',
    'libtiff.c',
    'main.c',
    'metadatahandler.c',
    'metadataquery.c',
    'palette.c',
    'pngformat.c',
    'propertybag.c',
    'proxy.c',
    'regsvr.c',
    'scaler.c',
    'stream.c',
    'ungif.c',
    'uuid.c',
    'wincodecs_common.c',
)


rc = files(
    'version.rc',
)

extra_args = [
    '-I../include/msvcrt',
    '-I../libs/tiff/libtiff',
    '-I../libs/jpeg',
    '-I../libs/png',
    '-D_UCRT',
    '-DENTRY_PREFIX=WIC_', '-DPROXY_DELEGATION', '-DWINE_REGISTER_DLL',
]

res = gen_rc_res.process(rc, extra_args : extra_args)

idls = files(
    'windowscodecs_wincodec.idl',
)

idl_h = gen_idl_h.process(idls)

deps = [
    'tiff',
    'jpeg',
    'png',
    'uuid',
    'ole32',
    'oleaut32',
    'propsys',
    'rpcrt4',
    'shlwapi',
    'user32',
    'gdi32',
    'advapi32',
    'winecrt0',
    'ucrtbase',
    'kernel32',
    'ntdll',
]

dlls += {
    'windowscodecs' : {
        'idl_h' : idl_h,
        'res' : res,
        'extra_args' : extra_args,
        'src' : src,
        'deps' : deps,
    }
}
