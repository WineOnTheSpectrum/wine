src = [
    'src/add.c',
    'src/code.c',
    'src/decode.c',
    'src/gsm_create.c',
    'src/gsm_decode.c',
    'src/gsm_destroy.c',
    'src/gsm_encode.c',
    'src/gsm_option.c',
    'src/gsm_print.c',
    'src/long_term.c',
    'src/lpc.c',
    'src/preprocess.c',
    'src/rpe.c',
    'src/short_term.c',
    'src/table.c'
]

# FIXME: add flags.
# EXTRAINCL = $(GSM_PE_CFLAGS)
# EXTRADEFS = -DWAV49

static_library('gsm_32', [headers, src],
    include_directories : [incdir, 'inc'],
    c_args : extra_flags_32 + ['-DWAV49'],
    pic : true,
    native : false,
    build_by_default : meson.is_cross_build(),
)

static_library('gsm_64', [headers, src],
    include_directories : [incdir, 'inc'],
    c_args : extra_flags_64 + ['-DWAV49'],
    native : false,
    build_by_default : meson.is_cross_build(),
)
