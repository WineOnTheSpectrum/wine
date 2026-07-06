src = files(
    'propstore.c',
    'propsys_main.c',
    'propvar.c',
)

extra_args = [
    '-I../include/msvcrt',
    '-D_UCRT',
    '-D_PROPSYS_',
]

idls = files(
    'propsys_classes.idl'
)

idl_c = gen_idl_c.process(idls)
idl_h = gen_idl_h.process(idls)

deps = [
    'ole32',
    'oleaut32',
    'uuid',
    'winecrt0',
    'ucrtbase',
    'kernel32',
    'ntdll',
]

dlls += {
    'propsys' : {
        'idl_c' : idl_c,
        'idl_h' : idl_h,
        'res' : [],
        'extra_args' : extra_args,
        'src' : src,
        'obj' : [],
        'deps' : deps,
    }
}
