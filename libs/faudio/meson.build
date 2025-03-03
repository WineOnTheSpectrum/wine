src = [
    'src/F3DAudio.c',
    'src/FACT.c',
    'src/FACT3D.c',
    'src/FACT_internal.c',
    'src/FAPOBase.c',
    'src/FAPOFX.c',
    'src/FAPOFX_echo.c',
    'src/FAPOFX_eq.c',
    'src/FAPOFX_masteringlimiter.c',
    'src/FAPOFX_reverb.c',
    'src/FAudio.c',
    'src/FAudioFX_reverb.c',
    'src/FAudioFX_volumemeter.c',
    'src/FAudio_internal.c',
    'src/FAudio_internal_simd.c',
    'src/FAudio_operationset.c',
    'src/FAudio_platform_win32.c'
]

# FIXME: do inl file??
#    'src/matrix_defaults.inl'

# FIXME: add flags.
# EXTRAINCL = $(FAUDIO_PE_CFLAGS)
# EXTRADEFS = -DFAUDIO_WIN32_PLATFORM -DHAVE_WMADEC -DNDEBUG

static_library('faudio_32', [headers, src],
    include_directories : [incdir, 'include'],
    c_args : extra_flags_32 + ['-DFAUDIO_WIN32_PLATFORM', '-DHAVE_WMADEC', '-DNDEBUG'],
    pic : true,
    native : false,
    build_by_default : meson.is_cross_build(),
)

static_library('faudio_64', [headers, src],
    include_directories : [incdir, 'include'],
    c_args : extra_flags_64 + ['-DFAUDIO_WIN32_PLATFORM', '-DHAVE_WMADEC', '-DNDEBUG'],
    native : false,
    build_by_default : meson.is_cross_build(),
)
