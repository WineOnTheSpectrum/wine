#i386_EXTRADLLFLAGS = -Wl,--image-base,0x7b800000
#x86_64_EXTRADLLFLAGS = -Wl,--image-base,0x178000000

rc = files(
    'version.rc',
)

rc_extra_flags = [
    '-I../include/msvcrt',
    '-D_MSVCR_VER=0', '-D_KERNEL32_', '-D_NORMALIZE_',
]

version_res = gen_rc_res.process(rc, extra_args : rc_extra_args)

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

kernel32_64 = static_library('kernel32_64', [headers, src],
    include_directories : incdir,
    c_args : extra_flags_64 + rc_extra_flags,
    native : false,
    build_by_default : meson.is_cross_build(),
)

kernel32_o_64 = kernel32_64.extract_all_objects(recursive : true)

custom_target('kernel32_64.dll',
    output : 'kernel32_64.dll',
    input : [
        'kernel32.spec', kernel32_o_64, version_res,
        kernelbase_64, ntdll_64, winecrt0_64,
    ],
    command : [
        winegcc_bin,
	'-o', '@OUTPUT@',
	'--wine-objdir', '.',
	'-b', 'x86_64-w64-mingw32',
	'-Wl,--wine-builtin',
	'-shared',
	'-nodefaultlibs',
	'-Wb,-F,KERNEL32.dll',
	'-Wl,--image-base,0x178000000',
	'@INPUT@'
    ],
    depends : winegcc_bin,
    build_by_default : meson.is_cross_build(),
)
