#i386_EXTRADLLFLAGS = -Wl,--image-base,0x7b800000
#x86_64_EXTRADLLFLAGS = -Wl,--image-base,0x178000000

rc = files(
    'version.rc',
)

extra_flags_msvc = [
    '-I../include/msvcrt',
    '-D_MSVCR_VER=0',
]

extra_flags = [
    '-D_KERNEL32_', '-D_NORMALIZE_',
]

res = gen_rc_res.process(rc, extra_args : extra_flags_msvc + extra_flags)

src = files(
    'atom.c',
    'comm.c',
    'computername.c',
    'console.c',
    'debugger.c',
    'file.c',
    'heap.c',
    'kernel_main.c',
    'locale.c',
    'lzexpand.c',
    'module.c',
    'path.c',
    'powermgnt.c',
    'process.c',
    'profile.c',
    'resource.c',
    'sync.c',
    'tape.c',
    'thread.c',
    'toolhelp.c',
    'version.c',
    'virtual.c',
    'volume.c',
)

dlls += {
    'kernel32' : {
        'src' : src,
        'res' : res,
        'extra_args' : extra_flags_msvc + extra_flags,
        'obj' : [],
        'idl_h' : [],
        'idl_c' : [],
        'deps' : [
            'kernelbase',
            'ntdll',
            'winecrt0',
        ],
    }
}
