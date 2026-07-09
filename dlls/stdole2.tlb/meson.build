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

res = gen_rc_res.process(rc, extra_args : extra_args)
idl_tres = gen_idl_tres.process(idls)

stdole2_tlb = custom_target('stdole2_tlb',
    input : [res, idl_tres],
    output : 'stdole2.tlb',
    command : [
        winegcc_bin,
        '-o', '@OUTPUT@',
        '--wine-objdir', '.',
        '-b', 'x86_64-w64-mingw32',
        '-Wl,--wine-builtin',
        '-shared',
        '-Wb,--data-only',
        '-I@BUILD_DIR@',
        '@INPUT@',
    ],
    build_by_default : meson.is_cross_build(),
)
