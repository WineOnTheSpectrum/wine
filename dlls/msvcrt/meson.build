rc = files(
    'rsrc.rc',
)

extra_args = [
    '-I../include/msvcrt',
    '-D_MSVCR_VER=0',
    '-D_CRTIMP=',
]

res = gen_rc_res.process(rc, extra_args : extra_args)

src = files(
    'concurrency.c',
    'console.c',
    'cpp.c',
    'crt_gccmain.c',
    'crt_main.c',
    'crt_winmain.c',
    'crt_wmain.c',
    'crt_wwinmain.c',
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
    'iob.c',
    'locale.c',
    'lock.c',
    'main.c',
    'math.c',
    'mathf.c',
    'mbcs.c',
    'misc.c',
    'onexit.c',
    'process.c',
    'scanf.c',
    'sincos.c',
    'string.c',
    'thread.c',
    'time.c',
    'undname.c',
    'wcs.c'
)

deps = [
    'musl',
    'ntdll',
    'winecrt0',
    'advapi32',
    'user32',
    'kernel32',
]

dlls += {
    'msvcrt' : {
        'idl_h' : [],
        'res' : res,
        'extra_args' : extra_args,
        'src' : src,
        'deps' : deps,
    }
}
