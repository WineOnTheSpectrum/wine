msrc = 'main.c'
psrc = [
    'preloader.c',
    'preloader_mac.c'
]

executable('wine', msrc,
    include_directories : [config_h_inc, incdir],
    c_args : '-fPIC',
    link_args : ['-Wl,--export-dynamic', '-pie'],
    dependencies : [libdl, pthread],
    native : true,
)

# TODO link as freestanding, see https://github.com/mesonbuild/meson/issues/8126
executable('wine-preloader', psrc,
    include_directories : [config_h_inc, incdir],
    c_args : '-fPIC',
    # WINEPRELOADER_LDFLAGS
    # FIXME: hard-coded -Ttext= address?
    link_args : ['-nostartfiles', '-nodefaultlibs', '-static', '-Wl,-Ttext=0x7d7d00000000'],
    dependencies : [libdl, pthread],
    native : true,
)
