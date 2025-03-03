src = [
    'glib.c',
    'src/midi/fluid_midi.c',
    'src/rvoice/fluid_adsr_env.c',
    'src/rvoice/fluid_chorus.c',
    'src/rvoice/fluid_iir_filter.c',
    'src/rvoice/fluid_lfo.c',
    'src/rvoice/fluid_rev.c',
    'src/rvoice/fluid_rvoice.c',
    'src/rvoice/fluid_rvoice_dsp.c',
    'src/rvoice/fluid_rvoice_event.c',
    'src/rvoice/fluid_rvoice_mixer.c',
    'src/sfloader/fluid_defsfont.c',
    'src/sfloader/fluid_samplecache.c',
    'src/sfloader/fluid_sffile.c',
    'src/sfloader/fluid_sfont.c',
    'src/synth/fluid_chan.c',
    'src/synth/fluid_event.c',
    'src/synth/fluid_gen.c',
    'src/synth/fluid_mod.c',
    'src/synth/fluid_synth.c',
    'src/synth/fluid_synth_monopoly.c',
    'src/synth/fluid_tuning.c',
    'src/synth/fluid_voice.c',
    'src/utils/fluid_conv.c',
    'src/utils/fluid_hash.c',
    'src/utils/fluid_list.c',
    'src/utils/fluid_ringbuffer.c',
    'src/utils/fluid_settings.c',
    'src/utils/fluid_sys.c'
]

# FIXME: add flags.
# EXTRADEFS = -DNDEBUG -DWITH_PROFILING
# EXTRAINCL = -I$(srcdir)/src \
#             -I$(srcdir)/src/bindings \
#             -I$(srcdir)/src/drivers \
#             -I$(srcdir)/src/midi \
#             -I$(srcdir)/src/rvoice \
#             -I$(srcdir)/src/sfloader \
#             -I$(srcdir)/src/synth \
#             -I$(srcdir)/src/utils \
#             $(FLUIDSYNTH_PE_CFLAGS)

static_library('fluidsynth_32', [headers, src],
    include_directories : [
      incdir,
      'include',
      'src',
      'src/bindings',
      'src/midi',
      'src/rvoice',
      'src/sfloader',
      'src/synth',
      'src/utils',
    ],
    c_args : extra_flags_32,
    pic : true,
    native : false,
    build_by_default : meson.is_cross_build(),
)

static_library('fluidsynth_64', [headers, src],
    include_directories : [
      incdir,
      'include',
      'src',
      'src/bindings',
      'src/midi',
      'src/rvoice',
      'src/sfloader',
      'src/synth',
      'src/utils',
    ],
    c_args : extra_flags_64,
    native : false,
    build_by_default : meson.is_cross_build(),
)
