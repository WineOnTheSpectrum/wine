w_src = files(
    'arm64ec.c',
    'crt_dllmain.c',
    'crt_fltused.c',
    'debug.c',
    'delay_load.c',
    'dll_canunload.c',
    'dll_main.c',
    'dll_register.c',
    'exception.c',
    'exe16_entry.c',
    'register.c',
    'setjmp.c',
    'stub.c',
    'unix_lib.c',
)

u_src = files(
    'dll_entry.c',
    'dll_soinit.c',
    'exe_entry.c',
    'exe_main.c',
    'exe_wentry.c',
    'exe_wmain.c',
)

winecrt0_w_af_64 = static_library('winecrt0_w_af_64', [headers, w_src],
    include_directories : [
        incdir, '.',
        '../../include/msvcrt',
    ],
    c_args : ['-D_MSVCR_VER=0'] + extra_flags_64,
    native : false,
    build_by_default : meson.is_cross_build(),
)
winecrt0_w_o_64 = winecrt0_w_af_64.extract_all_objects(recursive : true)

winecrt0_u_af_64 = static_library('winecrt0_u_af_64', [headers, u_src],
    include_directories : [
        config_h_inc, incdir, '.',
    ],
    c_args : ['-DWINE_UNIX_LIB', '-D__WINESRC__'],
    native : true,
    pic : true,
    build_by_default : not meson.is_cross_build(),
)
winecrt0_u_o_64 = winecrt0_u_af_64.extract_all_objects(recursive : true)

winecrt0_w_64 = custom_target('winecrt0_w_64',
    input : [winecrt0_w_o_64],
    output : 'libwinecrt0_w_64.a',
    command : [
      winebuild_bin,
      '-w', '--staticlib', '-o', '@OUTPUT@',
      '-b', 'x86_64-w64-mingw32',
      '@INPUT@',
    ],
    depends : [
        winebuild_bin,
        winecrt0_w_af_64,
    ],
    build_by_default : meson.is_cross_build(),
)

winecrt0_u_64 = custom_target('winecrt0_u_64',
    input : [winecrt0_u_o_64],
    output : 'libwinecrt0_u_64.a',
    command : [
      winebuild_bin,
      '-w', '--staticlib', '-o', '@OUTPUT@',
      '-m64',
      '@INPUT@',
    ],
    depends : [
        winebuild_bin,
        winecrt0_u_af_64,
    ],
    build_by_default : not meson.is_cross_build(),
)

if meson.is_cross_build()
    winecrt0_64 = winecrt0_w_64
else
    winecrt0_64 = winecrt0_u_64
endif

# Can't combine libs from different trees yet
#winecrt0_64 = custom_target('winecrt0_64',
#    input : [winecrt0_w_o_64, winecrt0_u_o_64],
#    output : 'libwinecrt0_64.a',
#    command : [
#      winebuild_bin,
#      '-w', '--staticlib', '-o', '@OUTPUT@',
#      '-b', 'x86_64-w64-mingw32',
#      '@INPUT@',
#    ],
#    depends : winebuild_bin,
#    build_by_default : true,
#)
