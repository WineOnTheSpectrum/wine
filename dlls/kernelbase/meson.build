mc = files(
    'winerror.mc',
)

winerror_res = gen_mc_res.process(mc)
winerror_pot = gen_mc_pot.process(mc)

rc = files(
    'kernelbase.rc',
)

rc_extra_args = [
    '-I../dlls/kernelbase',
    '-I../include/msvcrt',
    '-D_MSVCR_VER=0', '-DWINBASEAPI=', '-DWINADVAPI=', '-DWINUSERAPI=', '-DWINSHLWAPI=',
    '-D__WINESRC__', '-D__WINE_PE_BUILD',
]

res = gen_rc_res.process(rc, extra_args : rc_extra_args)

src = files(
    'console.c',
    'debug.c',
    'file.c',
    'loader.c',
    'locale.c',
    'main.c',
    'memory.c',
    'path.c',
    'process.c',
    'registry.c',
    'security.c',
    'string.c',
    'sync.c',
    'thread.c',
    'version.c',
    'volume.c',
)

dlls += {
    'kernelbase' : {
        'src' : src,
        'res' : [res, winerror_res],
        'idl_h': [],
        'idl_c': [],
        'obj' : [],
        'extra_args' : rc_extra_args,
        'deps' : [
            'uuid',
            'ntdll',
            'winecrt0',
        ],
    }
}
