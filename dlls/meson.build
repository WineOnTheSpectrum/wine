# Build core dlls completely in one go
subdir('winecrt0')
subdir('ntdll')
subdir('kernelbase')
subdir('kernel32')
subdir('win32u')
subdir('winspool.drv')

# Populate lists of files for dlls that depend on other dlls
dlls = {}

# data only dlls
subdir('stdole2.tlb')
subdir('apisetschema')
subdir('tzres')

# regular dlls
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
subdir('hid')
subdir('dinput8')
subdir('winmm')
subdir('shcore')
subdir('userenv')
subdir('cabinet')
subdir('dbghelp')
subdir('imagehlp')
subdir('setupapi')
subdir('comdlg32')
subdir('mlang')
subdir('shlwapi')
subdir('cryptui')
subdir('wintrust')
subdir('advpack')
subdir('urlmon')
subdir('propsys')
subdir('windowscodecs')
subdir('msimg32')
subdir('uxtheme')
subdir('nsi')
subdir('ws2_32')
subdir('dnsapi')
subdir('netutils')
subdir('iphlpapi')
subdir('netapi32')
subdir('ieframe')
subdir('shdocvw')
subdir('gdiplus')
subdir('dhcpcsvc')
subdir('msvfw32')
subdir('loadperf')
subdir('sxs')
subdir('mspatcha')
subdir('odbccp32')
subdir('msi')
subdir('ntoskrnl')
subdir('hal')
subdir('newdev')
subdir('mswsock')
subdir('wsock32')

#subdir('msvcrtd')

# real mode dlls
dll16s = {}

subdir('kernel')
#subdir('gdi')
#subdir('user')

custom_target('dlls_symlink',
    input : [],
    output : 'x86_64-windows',
    command : [
      sh,
      '-c',
      'cd dlls && ln -sf . x86_64-windows && cd ..',
    ],
    build_by_default : meson.is_cross_build(),
)

# Build all 64 bit libraries
foreach dllname, contents : dlls

    set_variable('@0@_af_64'.format(dllname), static_library('@0@_af_64'.format(dllname),
        [headers] + contents['idl_h'] + contents['idl_c'] + contents['src'],
        include_directories : [incdir, '.'],
        c_args : contents['extra_args'] + extra_flags_64,
        native : false,
        pic : true,
        build_by_default : meson.is_cross_build(),
    ))
    
    set_variable('@0@_o_64'.format(dllname),
        get_variable('@0@_af_64'.format(dllname)).extract_all_objects(recursive : true)
    )
    
    set_variable('@0@_64'.format(dllname), custom_target('@0@_64'.format(dllname),
        input : ['@0@/@0@.spec'.format(dllname)] + contents['obj'],
        output : 'lib@0@_64.a'.format(dllname),
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
            get_variable('@0@_af_64'.format(dllname)),
        ],
        build_by_default : meson.is_cross_build(),
    ))

endforeach

# Build and link all 64 bit dlls
foreach dllname, contents : dlls

    deps_64 = []
    foreach dep : contents['deps']
        deps_64 += get_variable('@0@_64'.format(dep))
    endforeach

    custom_target('@0@_64.dll'.format(dllname),
        output : '@0@.dll'.format(dllname),
        input : [
            '@0@/@0@.spec'.format(dllname), get_variable('@0@_o_64'.format(dllname)),
        ] + contents['res'] + deps_64,
        command : [
            winegcc_bin,
            '-I../dlls/@0@'.format(dllname),
            '-o', '@OUTPUT@',
            '--wine-objdir', '.',
            '-b', 'x86_64-w64-mingw32',
            '-Wl,--wine-builtin',
            '-Wb,--dll-name,@0@'.format(dllname),
            '-shared',
            '@INPUT@',
        ],
        depends : [
            winegcc_bin,
            get_variable('@0@_64'.format(dllname)),
        ],
        build_by_default : meson.is_cross_build(),
    )

    # Only copy manifests that exist
    if 'manifest' in contents
        custom_target('@0@_64.manifest'.format(dllname),
            output : '@0@.manifest'.format(dllname),
            input : contents['manifest'],
            command : [
                sh,
                '-c',
                'cp @INPUT0@ @OUTPUT0@',
            ],
            build_by_default : meson.is_cross_build(),
        )
    endif

    # Only define tests that exist
    if 'test' in contents
        tdeps_64 = [ get_variable('@0@_af_64'.format(dllname)) ]
        foreach tdep : contents['test']['deps']
            tdeps_64 += get_variable('@0@_64'.format(tdep))
        endforeach

        set_variable('testexe_@0@_64'.format(dllname), executable('testexe-@0@_64'.format(dllname),
            [headers, contents['test']['src']],
            include_directories : [incdir, '.', '../include/msvcrt'],
            c_args : [ '-nostdinc', '-mconsole', '-DSTANDALONE', '-D_UCRT', '-D__WINESRC__'],
            link_with : tdeps_64 + [
                winecrt0_64, ucrtbase_64, kernel32_64, ntdll_64,
            ],
            native : false,
            build_by_default : meson.is_cross_build(),
        ))

        test('@0@_dll_64'.format(dllname), runtest,
            args: [
                '-T', '.',
                '-M', 'dlls/@0@.dll'.format(dllname),
                '-p', 'programs/winetest.exe',
                get_variable('testexe_@0@_64'.format(dllname)).full_path(),
            ],
            env: [
                'WINEDEBUG=warn+all',
            ],
            depends: get_variable('testexe_@0@_64'.format(dllname)),
        )
    endif

endforeach

# Build all real mode libraries for 64 bit
foreach dllname, contents : dll16s

    set_variable('@0@_af_64'.format(dllname), static_library('@0@_af_64'.format(dllname),
        [headers] + contents['idl_h'] + contents['idl_c'] + contents['src'],
        include_directories : [incdir, '.'],
        c_args : contents['extra_args'] + extra_flags_64_32,
        native : false,
        pic : true,
        build_by_default : meson.is_cross_build(),
    ))
    
    set_variable('@0@_o_64'.format(dllname),
        get_variable('@0@_af_64'.format(dllname)).extract_all_objects(recursive : true)
    )
    
    set_variable('@0@_64'.format(dllname), custom_target('@0@_64'.format(dllname),
        input : ['@0@/@0@.spec'.format(dllname)] + contents['obj'],
        output : 'lib@0@_64.a'.format(dllname),
        command : [
            winebuild_bin,
            '-w', '--implib', '-o', '@OUTPUT@',
            '--without-dlltool',
            '-b', 'x86_64-w64-mingw32',
            '-m16',
            '--export',
            '@INPUT@',
        ],
        depends : [
            winebuild_bin,
            get_variable('@0@_af_64'.format(dllname)),
        ],
        build_by_default : meson.is_cross_build(),
    ))

endforeach

## Build and link all real mode dlls for 64 bit
#foreach dllname, contents : dll16s
#
#    deps_64 = []
#    foreach dll : contents['deps']
#        deps_64 += get_variable('@0@_64'.format(dll))
#    endforeach
#
#    custom_target('@0@_64.dll'.format(dllname),
#        output : '@0@.dll'.format(dllname),
#        input : [
#            '@0@/@0@.spec'.format(dllname), get_variable('@0@_o_64'.format(dllname)),
#        ] + contents['res'] + deps_64,
#        command : [
#            winegcc_bin,
#            '-I../dlls/@0@'.format(dllname),
#            '-o', '@OUTPUT@',
#            '--wine-objdir', '.',
#            '-b', 'x86_64-w64-mingw32',
#            '-Wl,--wine-builtin',
#            '-Wb,--dll-name,@0@'.format(dllname),
#            '-m16',
#            '-shared',
#            '@INPUT@',
#        ],
#        depends : [
#            winegcc_bin,
#            get_variable('@0@_64'.format(dllname)),
#        ],
#        build_by_default : meson.is_cross_build(),
#    )
#
#endforeach
