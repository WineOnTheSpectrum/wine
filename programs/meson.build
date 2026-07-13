coms = {}
exes = {}
exe16s = {}
mod16s = {}

subdir('arp')
subdir('aspnet_regiis')
subdir('attrib')
subdir('cabarc')
subdir('cacls')
subdir('certutil')
subdir('chcp.com')
subdir('clock')
subdir('cmd')
subdir('conhost')
subdir('control')
subdir('cscript')
subdir('dism')
subdir('dllhost')
subdir('dplaysvr')
subdir('dpnsvr')
subdir('dpvsetup')
subdir('dxdiag')
subdir('eject')
subdir('expand')
subdir('explorer')
subdir('extrac32')
subdir('fc')
subdir('find')
subdir('findstr')
subdir('fsutil')
subdir('hh')
subdir('hostname')
subdir('icacls')
#subdir('icinfo')
subdir('iexplore')
subdir('ipconfig')
subdir('klist')
#subdir('lodctr')
subdir('makecab')
subdir('mofcomp')
subdir('mshta')
#subdir('msidb')
#subdir('msiexec')
#subdir('msinfo32')
subdir('net')
subdir('netsh')
subdir('netstat')
subdir('ngen')
subdir('notepad')
subdir('oleview')
subdir('ping')
subdir('plugplay')
subdir('pnputil')
subdir('powershell')
subdir('presentationfontcache')
subdir('progman')
subdir('reg')
subdir('regasm')
subdir('regedit')
subdir('regini')
subdir('regsvcs')
subdir('regsvr32')
subdir('robocopy')
subdir('rpcss')
subdir('rundll32')
subdir('rundll.exe16')
subdir('sc')
subdir('schtasks')
subdir('sdbinst')
subdir('secedit')
subdir('servicemodelreg')
subdir('services')
subdir('setx')
subdir('shutdown')
subdir('sort')
subdir('spoolsv')
subdir('start')
subdir('subst')
subdir('svchost')
subdir('systeminfo')
subdir('taskkill')
subdir('tasklist')
subdir('taskmgr')
subdir('termsv')
subdir('timeout')
subdir('uninstaller')
#subdir('unlodctr')
subdir('view')
subdir('wevtutil')
subdir('where')
subdir('whoami')
#subdir('wineboot')
subdir('winebrowser')
#subdir('winecfg')
subdir('wineconsole')
subdir('winedbg')
#subdir('winedevice')
subdir('winefile')
subdir('winemenubuilder')
subdir('winemine')
#subdir('winemsibuilder')
subdir('winepath')
#subdir('winetest')
#subdir('winevdm')
subdir('winhelp.exe16')
subdir('winhlp32')
subdir('winmgmt')
subdir('winoldap.mod16')
subdir('winver')
subdir('wmic')
subdir('wmplayer')
subdir('wordpad')
subdir('write')
subdir('wscript')
subdir('wuauserv')
subdir('wusa')
subdir('xcopy')

# Build and link all exes
foreach exename, contents : exes

    # Build all srcs as a library first
    set_variable('@0@_af_64'.format(exename), static_library('@0@_af_64'.format(exename),
        [headers] + contents['src'],
        include_directories : [incdir, '.', '@0@'.format(exename)],
        c_args : ['-I../include/msvcrt', '-D_UCRT'] + contents['flags'] + extra_flags_64,
        native : false,
        pic : true,
        build_by_default : meson.is_cross_build(),
    ))

    set_variable('@0@_o_64'.format(exename),
        get_variable('@0@_af_64'.format(exename)).extract_all_objects(recursive : true)
    )

    deps_64 = []
    foreach dep : contents['deps']
        deps_64 += get_variable('@0@_64'.format(dep))
    endforeach
    deps_64 += [winecrt0_64, ucrtbase_64, kernel32_64, ntdll_64]

    # Link exes
    custom_target('@0@_64.exe'.format(exename),
        output : '@0@_64.exe'.format(exename),
        input : [
            get_variable('@0@_o_64'.format(exename)),
        ] + contents['res'] + deps_64,
        command : [
            winegcc_bin,
            '-I../programs/@0@'.format(exename),
            '-o', '@OUTPUT@',
            '--wine-objdir', '.',
            '-b', 'x86_64-w64-mingw32',
            '-Wl,--wine-builtin',
        ] + contents['flags'] + [
            '@INPUT@',
        ],
        depends : [
            winegcc_bin,
            get_variable('@0@_af_64'.format(exename)),
        ],
        build_by_default : meson.is_cross_build(),
    )

endforeach
