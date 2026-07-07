#EXTRADEFS = -D_NTSYSTEM_ -D_ACRTIMP= -DWINBASEAPI=
#MODULE    = ntdll.dll
#UNIXLIB   = ntdll.so
#IMPORTLIB = ntdll
#IMPORTS   = $(TOMCRYPT_PE_LIBS) $(MUSL_PE_LIBS)
#EXTRAINCL = $(TOMCRYPT_PE_CFLAGS)
#UNIX_CFLAGS  = $(UNWIND_CFLAGS)
#UNIX_LIBS    = $(IOKIT_LIBS) $(COREFOUNDATION_LIBS) $(CORESERVICES_LIBS) $(RT_LIBS) $(PTHREAD_LIBS) $(UNWIND_LIBS) $(I386_LIBS) $(PROCSTAT_LIBS)
#
#EXTRADLLFLAGS = -nodefaultlibs
#i386_EXTRADLLFLAGS = -Wl,--image-base,0x7bc00000
#x86_64_EXTRADLLFLAGS = -Wl,--image-base,0x170000000

rc = files(
    'version.rc',
)

rc_extra_args = [
    '-I../include/msvcrt',
    '-I../libs/tomcrypt/src/headers',
    '-D_MSVCR_VER=0',
    '-DLTC_NO_PROTOTYPES', '-DLTC_SOURCE', '-D_NTSYSTEM_', '-D_ACRTIMP=', '-DWINBASEAPI=',
    '-D__WINESRC__', '-D__WINE_PE_BUILD',
]

version_res = gen_rc_res.process(rc, extra_args : rc_extra_args)

src = files(
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

ntdll_so_64 = shared_library('ntdll_so_64', [unix_src],
    include_directories : [
        config_h_inc,
	incdir,
    ],
    c_args : [
        '-DLTC_NO_PROTOTYPES', '-DLTC_SOURCE', '-D_NTSYSTEM_', '-D_ACRTIMP=', '-DWINBASEAPI=',
        '-DWINE_UNIX_LIB', '-D__WINESRC__',
        '-static-libgcc',
    ] + datadir_define + dllpath_define,
    native : true,
    dependencies : [libdl, pthread, unwind],
    build_by_default : not meson.is_cross_build(),
)

ntdll_af_64 = static_library('ntdll_artefacts_64', [src],
    include_directories : [
	incdir,
        '../../include/msvcrt',
        '../../libs/tomcrypt/src/headers',
    ],
    c_args : extra_flags_64 + rc_extra_args,
    native : false,
    build_by_default : meson.is_cross_build(),
)
ntdll_o_64 = ntdll_af_64.extract_all_objects(recursive : true)

ntdll_64 = custom_target('ntdll_64',
    input : 'ntdll.spec',
    output : 'libntdll_64.a',
    command : [
      winebuild_bin,
      '-w', '--implib', '-o', '@OUTPUT@',
      '--without-dlltool',
      '-b', 'x86_64-w64-mingw32',
      '--export',
      '@INPUT@',
    ],
    depends : [
        winebuild_bin,
        ntdll_af_64,
    ],
    build_by_default : meson.is_cross_build(),
)

custom_target('ntdll_64.dll',
    output : 'ntdll_64.dll',
    input : [
        'ntdll.spec', ntdll_o_64, version_res,
        tomcrypt_64, musl_64, winecrt0_64,
    ],
    command : [
        winegcc_bin,
	'-o', '@OUTPUT@',
	'--wine-objdir', '.',
	'-b', 'x86_64-w64-mingw32',
	'-Wl,--wine-builtin',
	'-shared',
        '-nodefaultlibs',
        '-Wl,--image-base,0x170000000',
	'@INPUT@'
    ] + extra_dll_flags_64,
    depends : [
        winegcc_bin,
        ntdll_64,
    ],
    build_by_default : meson.is_cross_build(),
)

#unix_loader_EXTRADEFS =',
#	-DBINDIR=\"${bindir}\"',
#	-DLIBDIR=\"${libdir}\"',
#	-DDATADIR=\"${datadir}\"',
#	-DSYSTEMDLLPATH=\"${system_dllpath}\"
