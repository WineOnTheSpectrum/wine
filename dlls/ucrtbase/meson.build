rc = files(
    'version.rc',
)

extra_args = [
    '-I../dlls/ucrtbase',
    '-I../dlls/msvcrt',
    '-I../include/msvcrt',
    '-D_UCRT', '-D_CRTIMP=',
]

res = gen_rc_res.process(rc, extra_args : extra_args)

w_src1 = files(
    '../msvcrt/console.c',
    '../msvcrt/cpp.c',
    '../msvcrt/ctype.c',
    '../msvcrt/data.c',
    '../msvcrt/dir.c',
    '../msvcrt/environ.c',
    '../msvcrt/errno.c',
    '../msvcrt/except.c',
    '../msvcrt/except_arm.c',
    '../msvcrt/except_arm64.c',
    '../msvcrt/except_arm64ec.c',
    '../msvcrt/except_i386.c',
    '../msvcrt/except_x86_64.c',
    '../msvcrt/exception_ptr.c',
    '../msvcrt/exit.c',
    '../msvcrt/file.c',
    '../msvcrt/handler4.c',
    '../msvcrt/heap.c',
    '../msvcrt/locale.c',
    '../msvcrt/lock.c',
    '../msvcrt/main.c',
    '../msvcrt/math.c',
    '../msvcrt/mbcs.c',
    '../msvcrt/misc.c',
    '../msvcrt/process.c',
    '../msvcrt/scanf.c',
    '../msvcrt/string.c',
    '../msvcrt/thread.c',
    '../msvcrt/time.c',
    '../msvcrt/undname.c',
    '../msvcrt/wcs.c',
)

w_src2 = files(
    '../msvcrt/crt_gccmain.c',
    '../msvcrt/crt_main.c',
    '../msvcrt/crt_winmain.c',
    '../msvcrt/crt_wmain.c',
    '../msvcrt/crt_wwinmain.c',
    '../msvcrt/mathf.c',
    'printf.c',
    '../msvcrt/sincos.c',
)

deps = [
    'musl',
    'ntdll',
    'advapi32', # delay?
    'user32', # delay?
    'winecrt0',
    'kernel32',
    'ntdll',
]

ucrtbase_w2_af_64 = static_library('ucrtbase_w2_af_64', [headers, w_src2],
    include_directories : [
        incdir, '.',
    ],
    c_args : extra_args + extra_flags_64,
    native : false,
    build_by_default : meson.is_cross_build(),
)
ucrtbase_w2_o_64 = ucrtbase_w2_af_64.extract_all_objects(recursive : true)

dlls += {
    'ucrtbase' : {
        'idl_c' : [],
        'idl_h' : [],
        'res' : res,
        'extra_args' : extra_args,
        'src' : w_src1,
        'obj' : ucrtbase_w2_af_64,
        'deps' : deps,
    }
}
