# version.rc contains define data about dll
rc = files(
    'version.rc',
)

version_res = gen_rc_res.process(rc)

src = files(
    'version.c'
)

version_af = static_library('version_artefacts', src, include_directories : incdir, native : false)
version_o = version_af.extract_all_objects(recursive : true)
custom_target('version.dll',
    output : 'version.dll',
    input : [
        'version.spec', version_o, version_res,
	#FIXME libkernelbase, libwinecrt0, libucrtbase, libkernel32, libntdll,
    ],
    command : [
	winegcc_bin,
	'-o', '@OUTPUT@',
	'--wine-objdir', '.',
	'-b', 'x86_64-w64-mingw32',
	'-Wl,--wine-builtin',
	'-shared',
	'@INPUT@',
    ],
    depends : winegcc_bin,
)

## x86_64-w64-mingw32-gcc -c -o dlls/version/x86_64-windows/version.o dlls/version/version.c -Idlls/version -Iinclude -Iinclude/msvcrt -D_UCRT \
##   -D__WINESRC__ -D__WINE_PE_BUILD -Wall -fno-strict-aliasing -Wdeclaration-after-statement \
##   -Wempty-body -Wignored-qualifiers -Winit-self -Wno-packed-not-aligned -Wshift-overflow=2 \
##   -Wstrict-prototypes -Wtype-limits -Wunused-but-set-parameter -Wvla -Wwrite-strings -Wpointer-arith \
##   -Wlogical-op -Wabsolute-value -ffunction-sections -Wno-misleading-indentation -Wformat-overflow \
##   -Wnonnull -mcx16 -mcmodel=small -gdwarf-4 -g -O2
## tools/wrc/wrc -u -o dlls/version/version.res --nostdinc -Idlls/version -Iinclude -Iinclude/msvcrt -D_UCRT -D__WINESRC__ \
##   dlls/version/version.rc
#
#
## tools/winegcc/winegcc -o dlls/version/x86_64-windows/version.dll --wine-objdir . -b x86_64-w64-mingw32 -Wl,--wine-builtin -shared \
##   dlls/version/version.spec dlls/version/x86_64-windows/version.o dlls/version/version.res \
##   dlls/kernelbase/x86_64-windows/libkernelbase.a dlls/winecrt0/x86_64-windows/libwinecrt0.a \
##   dlls/ucrtbase/x86_64-windows/libucrtbase.a dlls/kernel32/x86_64-windows/libkernel32.a \
##   dlls/ntdll/x86_64-windows/libntdll.a


# https://mesonbuild.com/Reference-manual_returned_generator.html
# https://mesonbuild.com/Reference-manual_functions.html#custom_target
