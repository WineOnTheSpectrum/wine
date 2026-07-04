# Build core dlls completely in one go
subdir('winecrt0')
subdir('ntdll')
subdir('kernelbase')
subdir('kernel32')
subdir('win32u')
subdir('winspool.drv')

# Populate lists of files for dlls that depend on other dlls
dlls = {}

subdir('user32')
subdir('advapi32')
subdir('ucrtbase')
subdir('gdi32')
subdir('sechost')
subdir('imm32')
subdir('combase')
subdir('ole32')
subdir('oleaut32')
subdir('comctl32')
subdir('rpcrt4')
subdir('msvcrt')
subdir('bcrypt')
subdir('crypt32')
subdir('secur32')
subdir('cryptnet')
subdir('shell32')
subdir('wininet')
subdir('coml2')
subdir('oleacc')
subdir('mpr')
subdir('version')
subdir('msacm32')
subdir('winmm')
subdir('shcore')
subdir('userenv')
subdir('cabinet')
subdir('dbghelp')
subdir('imagehlp')
subdir('setupapi') #
subdir('comdlg32') #
subdir('mlang')
subdir('shlwapi') #
subdir('cryptui') #
subdir('wintrust')
subdir('advpack')
subdir('urlmon')
subdir('propsys')
subdir('windowscodecs')
subdir('uxtheme')

#subdir('dhcpcsvc')
#subdir('shdocvw')
#subdir('gdiplus')
#subdir('iphlpapi')
#subdir('ws2_32')

#subdir('msvcrtd')

# Build all library deps first
foreach dllname, contents : dlls

    set_variable('@0@_af_64'.format(dllname), static_library('@0@_af_64'.format(dllname),
        [headers] + contents['idl_h'] + contents['src'],
        include_directories : [incdir, '.'],
        c_args : extra_flags_64 + contents['extra_args'],
        native : false,
        build_by_default : meson.is_cross_build(),
    ))
    
    set_variable('@0@_o_64'.format(dllname),
        get_variable('@0@_af_64'.format(dllname)).extract_all_objects(recursive : true)
    )
    
    set_variable('@0@_64'.format(dllname), custom_target('@0@_64'.format(dllname),
        input : '@0@/@0@.spec'.format(dllname),
        output : 'lib@0@_64.a'.format(dllname),
        command : [
          winebuild_bin,
          '-w', '--implib', '-o', '@OUTPUT@',
          '--without-dlltool',
          '-b', 'x86_64-w64-mingw32',
          '--export',
          '@INPUT@',
        ],
        depends : winebuild_bin,
        build_by_default : meson.is_cross_build(),
    ))

endforeach

# Uncomment when enough dlls are populated
#
## Build and link all dlls
#foreach dllname, contents : dlls
#
#    deps_64 = []
#    foreach dll : contents['deps']
#        deps_64 += get_variable('@0@_64'.format(dll))
#    endforeach
#
#    custom_target('@0@_64.dll'.format(dllname),
#        output : '@0@_64.dll'.format(dllname),
#        input : [
#            '@0@/@0@.spec'.format(dllname), get_variable('@0@_o_64'.format(dllname)),
#        ] + contents['res'] + deps_64,
#        command : [
#        winegcc_bin,
#            '-o', '@OUTPUT@',
#            '--wine-objdir', '.',
#            '-b', 'x86_64-w64-mingw32',
#            '-Wl,--wine-builtin',
#            '-shared',
#            '@INPUT@',
#        ],
#        depends : winegcc_bin,
#        build_by_default : meson.is_cross_build(),
#    )
#
#endforeach
