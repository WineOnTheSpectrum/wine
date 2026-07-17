rc = files(
    'rsrc.rc',
)

extra_args = [
    '-I../include/msvcrt',
    '-D_UCRT',
    '-D__WINESRC__',
]


idls = files(
    'stdole2.idl',
)

idl0 = files(
    '../../include/shobjidl_core.idl',
    '../../include/objectarray.idl',
    '../../include/structuredquerycondition.idl',
    '../../include/propsys.idl',
    '../../include/comcat.idl',
    '../../include/shobjidl.idl',
    '../../include/shtypes.idl',
    '../../include/shldisp.idl',
    '../../include/servprov.idl',
    '../../include/docobj.idl',
    '../../include/msxml.idl',
    '../../include/urlmon.idl',
    '../../include/ocidl.idl',
    '../../include/exdisp.idl',
    '../../include/objidlbase.idl',
    '../../include/wtypes.idl',
    '../../include/unknwn.idl',
    '../../include/oleacc.idl',
    '../../include/oleidl.idl',
    '../../include/objidl.idl',
    '../../include/oaidl.idl',
    '../../include/propidl.idl',
    '../../include/strmif.idl',
)

res = gen_rc_res.process(rc, extra_args : extra_args)
idl_h = gen_idl_h.process(idl0, extra_args : extra_args)
idl_tres = gen_idl_tres.process(idls, extra_args : extra_args)

stdole2_tlb = custom_target('stdole2_tlb',
    input : [idl_h, res, idl_tres],
    output : 'stdole2.tlb',
    command : [
        winegcc_bin,
        '-o', '@OUTPUT@',
        '--wine-objdir', '.',
        '-b', 'x86_64-w64-mingw32',
        '-Wl,--wine-builtin',
        '-shared',
        '-Wb,--data-only',
        '-I../include',
        '-Idlls/stdole2.tlb/stdole2.tlb.p',
    ] + extra_args + [
        '@INPUT@',
    ],
    build_by_default : meson.is_cross_build(),
)
