src1 = files(
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
    'wincodecs_common.c',
)

src2 = files(
    'uuid.c',
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
    '-D__WINESRC__',
]

extra_dll_args = [
    '-DENTRY_PREFIX=WIC_', '-DPROXY_DELEGATION',
]

res = gen_rc_res.process(rc, extra_args : extra_args)

idls = files(
    'windowscodecs_wincodec.idl',
)

idl_c = gen_idl_c.process(idls, extra_args : extra_args)
idl_h = gen_idl_h.process(idls, extra_args : extra_args)
idl_p = gen_idl_p_c.process(idls, extra_args : extra_args)
idl_r = gen_idl_rres.process(idls, extra_args : extra_args)
idl_d = gen_idl_dlldata.process(idls, extra_args : extra_args)

deps = [
    'tiff',
    'jpeg',
    'png',
    'zlib',
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

windowscodecs_w2_af_64 = static_library('windowscodecs_w2_af_64', [headers, src2],
    include_directories : [
        incdir, '.',
    ],
    c_args : extra_args + extra_flags_64,
    native : false,
    build_by_default : meson.is_cross_build(),
)

dlls += {
    'windowscodecs' : {
        'idl_c' : [idl_c, idl_p, idl_r, idl_d],
        'idl_h' : idl_h,
        'res' : res,
        'extra_args' : extra_args + extra_dll_args,
        'src' : src1,
        'obj' : windowscodecs_w2_af_64,
        'deps' : deps,
    }
}
