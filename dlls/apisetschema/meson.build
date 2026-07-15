spec = files(
    'apisetschema.spec'
)

custom_target('apisetschema_64.dll',
    input : spec,
    output : 'apisetschema.dll',
    command : [
        winegcc_bin,
        '-o', '@OUTPUT@',
        '--wine-objdir', '.',
        '-b', 'x86_64-w64-mingw32',
        '-Wl,--wine-builtin',
        '-shared',
        '-Wb,--data-only',
        '-I@BUILD_DIR@',
        '-I../include/msvcrt',
        '-D_UCRT',
        '-D__WINESRC__',
        '@INPUT@',
    ],
    build_by_default : meson.is_cross_build(),
)

custom_target('apisetschema_symlink',
    input : [],
    output : 'x86_64-windows',
    command : [
      sh,
      '-c',
      'cd dlls/apisetschema && ln -sf . x86_64-windows && cd ../..',
    ],
    build_by_default : meson.is_cross_build(),
)
