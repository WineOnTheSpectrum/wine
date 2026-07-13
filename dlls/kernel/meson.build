src = files(
    'atom.c',
    'dosmem.c',
    'error.c',
    'file.c',
    'fpu.c',
    'global.c',
    'instr.c',
    'int15.c',
    'int21.c',
    'int25.c',
    'int26.c',
    'int2f.c',
    'int31.c',
    'interrupts.c',
    'ioports.c',
    'kernel.c',
    'local.c',
    'ne_module.c',
    'ne_segment.c',
    'registry.c',
    'relay.c',
    'resource.c',
    'selector.c',
    'snoop.c',
    'syslevel.c',
    'task.c',
    'thunk.c',
    'utthunk.c',
    'vxd.c',
    'wowthunk.c',
)

rc = files(
    'version.rc',
)

extra_args = [
    '-I../include/msvcrt',
    '-D_UCRT',
    '-D__WINESRC__',
]

res = gen_rc_res.process(rc, extra_args : extra_args + ['-m16'])

deps = [
    'user32',
    'winecrt0',
    'ucrtbase',
    'kernel32',
    'ntdll',
]

dll16s += {
    'kernel' : {
        'idl_c' : [],
        'idl_h' : [],
        'res' : res,
        'extra_args' : extra_args,
        'src' : src,
        'obj' : [],
        'deps' : deps,
    }
}
