src = files(
    'coff.c',
    'cpu_arm.c',
    'cpu_arm64.c',
    'cpu_i386.c',
    'cpu_x86_64.c',
    'dbghelp.c',
    'dwarf.c',
    'elf_module.c',
    'image.c',
    'macho_module.c',
    'minidump.c',
    'module.c',
    'msc.c',
    'path.c',
    'pe_module.c',
    'source.c',
    'stabs.c',
    'stack.c',
    'storage.c',
    'symbol.c',
    'type.c',
)

rc = files(
    'version.rc',
)

extra_args = [
    '-I../libs/zlib',
    '-I../include/msvcrt',
    '-D_UCRT', '-D_IMAGEHLP_SOURCE_',
    '-DFAR=', '-DZ_SOLO',
]

res = gen_rc_res.process(rc, extra_args : extra_args)

deps = [
    'kernelbase',
    'zlib',
    'winecrt0',
    'ucrtbase',
    'kernel32',
    'ntdll',
]

dlls += {
    'dbghelp' : {
        'idl_c' : [],
        'idl_h' : [],
        'res' : res,
        'extra_args' : extra_args,
        'src' : src,
        'deps' : deps,
    }
}
