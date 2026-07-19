#i386_EXTRADLLFLAGS = -Wl,--image-base,0x7bc00000
#x86_64_EXTRADLLFLAGS = -Wl,--image-base,0x170000000

#unix_loader_EXTRADEFS =',
#	-DBINDIR=\"${bindir}\"',
#	-DLIBDIR=\"${libdir}\"',
#	-DDATADIR=\"${datadir}\"',
#	-DSYSTEMDLLPATH=\"${system_dllpath}\"

rc = files(
    'version.rc',
)

extra_msvc = [
    '-I../include/msvcrt',
    '-I../libs/tomcrypt/src/headers',
    '-D_MSVCR_VER=0',
]

extra_args = [
    '-I../dlls/ntdll',
    '-DLTC_NO_PROTOTYPES', '-DLTC_SOURCE', '-D_NTSYSTEM_', '-D_ACRTIMP=', '-DWINBASEAPI=',
    '-D__WINESRC__',
]

version_res = gen_rc_res.process(rc, extra_args : extra_msvc + extra_args)

w_src = files(
    'actctx.c',
    'atom.c',
    'crypt.c',
    'debugbuffer.c',
    'env.c',
    'error.c',
    'exception.c',
    'handletable.c',
    'heap.c',
    'large_int.c',
    'loader.c',
    'locale.c',
    'math.c',
    'misc.c',
    'path.c',
    'printf.c',
    'process.c',
    'reg.c',
    'relay.c',
    'resource.c',
    'rtl.c',
    'rtlbitmap.c',
    'rtlstr.c',
    'sec.c',
    'signal_arm.c',
    'signal_arm64.c',
    'signal_arm64ec.c',
    'signal_i386.c',
    'signal_x86_64.c',
    'string.c',
    'sync.c',
    'thread.c',
    'threadpool.c',
    'time.c',
    'unwind.c',
    'version.c',
    'wcstring.c',
)

unix_src = files(
    'unix/cdrom.c',
    'unix/debug.c',
    'unix/env.c',
    'unix/file.c',
    'unix/loader.c',
    'unix/loadorder.c',
    'unix/process.c',
    'unix/registry.c',
    'unix/security.c',
    'unix/serial.c',
    'unix/server.c',
    'unix/signal_arm.c',
    'unix/signal_arm64.c',
    'unix/signal_i386.c',
    'unix/signal_x86_64.c',
    'unix/socket.c',
    'unix/sync.c',
    'unix/system.c',
    'unix/tape.c',
    'unix/thread.c',
    'unix/virtual.c',
    'unix/version.c', # FIXME generate from version string
)

dlls += {
    'ntdll' : {
        'src': w_src,
        'extra_args' : extra_msvc + extra_args,
        'idl_h' : [],
        'idl_c' : [],
        'obj' : [],
        'res' : version_res,
        'deps' : [
            'tomcrypt',
            'musl',
            'winecrt0',
        ],
        'so' : {
            'src' : unix_src,
            'extra_args' : datadir_define + dllpath_define + extra_args + ['-static-libgcc'],
            'deps' : [
                libdl,
                pthread,
                unwind,
            ],
            'link' : [],
        },
    }
}
