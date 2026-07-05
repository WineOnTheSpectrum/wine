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

src = files(
    '../msvcrt/console.c',
    '../msvcrt/cpp.c',
    '../msvcrt/crt_gccmain.c',
    '../msvcrt/crt_main.c',
    '../msvcrt/crt_winmain.c',
    '../msvcrt/crt_wmain.c',
    '../msvcrt/crt_wwinmain.c',
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
    '../msvcrt/mathf.c',
    '../msvcrt/mbcs.c',
    '../msvcrt/misc.c',
    'printf.c',
    '../msvcrt/process.c',
    '../msvcrt/scanf.c',
    '../msvcrt/sincos.c',
    '../msvcrt/string.c',
    '../msvcrt/thread.c',
    '../msvcrt/time.c',
    '../msvcrt/undname.c',
    '../msvcrt/wcs.c',
)

deps = [
    'musl',
    'ntdll',
    'advapi32',
    'user32',
    'winecrt0',
    'kernel32',
    'ntdll',
]

dlls += {
    'ucrtbase' : {
        'idl_c' : [],
        'idl_h' : [],
        'res' : res,
        'extra_args' : extra_args,
        'src' : src,
        'deps' : deps,
    }
}
