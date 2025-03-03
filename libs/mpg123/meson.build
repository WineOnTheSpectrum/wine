src = [
    'src/compat/compat.c',
    'src/compat/compat_str.c',
    'src/libmpg123/dct64.c',
    'src/libmpg123/dither.c',
    'src/libmpg123/equalizer.c',
    'src/libmpg123/format.c',
    'src/libmpg123/frame.c',
    'src/libmpg123/icy.c',
    'src/libmpg123/icy2utf8.c',
    'src/libmpg123/id3.c',
    'src/libmpg123/index.c',
    'src/libmpg123/layer1.c',
    'src/libmpg123/layer2.c',
    'src/libmpg123/layer3.c',
    'src/libmpg123/lfs_wrap.c',
    'src/libmpg123/libmpg123.c',
    'src/libmpg123/ntom.c',
    'src/libmpg123/optimize.c',
    'src/libmpg123/parse.c',
    'src/libmpg123/readers.c',
    'src/libmpg123/stringbuf.c',
    'src/libmpg123/synth.c',
    'src/libmpg123/synth_8bit.c',
    'src/libmpg123/synth_real.c',
    'src/libmpg123/synth_s32.c',
    'src/libmpg123/tabinit.c'
]

# EXTRAINCL = -I$(srcdir)/src -I$(srcdir)/src/compat $(MPG123_PE_CFLAGS)
# EXTRADEFS = -DOPT_GENERIC_DITHER -DREAL_IS_FLOAT -DNO_CATCHSIGNAL

static_library('mpg123_32', [headers, src],
    include_directories : [incdir, 'src', 'src/compat'],
    c_args : extra_flags_32 + ['-D_UCRT', '-DOPT_GENERIC_DITHER', '-DREAL_IS_FLOAT', '-DNO_CATCHSIGNAL'],
    pic : true,
    native : false,
    build_by_default : meson.is_cross_build(),
)

static_library('mpg123_64', [headers, src],
    include_directories : [incdir, 'src', 'src/compat'],
    c_args : extra_flags_64 + ['-D_UCRT', '-DOPT_GENERIC_DITHER', '-DREAL_IS_FLOAT', '-DNO_CATCHSIGNAL'],
    native : false,
    build_by_default : meson.is_cross_build(),
)
