rc = files(
    'rsrc.rc',
)

extra_args = [
    '-I../include/msvcrt',
    '-D_MSVCR_VER=0',
    '-D_CRTIMP=',
]

res = gen_rc_res.process(rc, extra_args : extra_args)

w_src1 = files(
    'concurrency.c',
    'console.c',
    'cpp.c',
    'ctype.c',
    'data.c',
    'dir.c',
    'environ.c',
    'errno.c',
    'except.c',
    'except_arm.c',
    'except_arm64.c',
    'except_arm64ec.c',
    'except_i386.c',
    'except_x86_64.c',
    'exception_ptr.c',
    'exit.c',
    'file.c',
    'handler4.c',
    'heap.c',
    'locale.c',
    'lock.c',
    'main.c',
    'math.c',
    'mbcs.c',
    'misc.c',
    'process.c',
    'scanf.c',
    'string.c',
    'thread.c',
    'time.c',
    'undname.c',
    'wcs.c',
)

w_src2 = files(
    'crt_gccmain.c',
    'crt_main.c',
    'crt_winmain.c',
    'crt_wmain.c',
    'crt_wwinmain.c',
    'iob.c',
    'mathf.c',
    'onexit.c',
    'sincos.c',
)

deps = [
    'musl',
    'ntdll',
    'winecrt0',
    'advapi32',
    'user32',
    'kernel32',
]

msvcrt_w2_af_64 = static_library('msvcrt_w2_af_64', [w_src2],
    include_directories : [
        config_h_inc, incdir, '.',
        '../../include/msvcrt',
    ],
    c_args : ['-D_MSVCR_VER=0', '-D_CRTIMP='] + extra_flags_64,
    native : false,
    build_by_default : meson.is_cross_build(),
)

dlls += {
    'msvcrt' : {
        'idl_c' : [],
        'idl_h' : [],
        'res' : res,
        'extra_args' : extra_args,
        'src' : w_src1,
        'obj' : msvcrt_w2_af_64,
        'deps' : deps,
    }
}
