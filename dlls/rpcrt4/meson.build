rc = files(
    'version.rc',
)

extra_args = [
    '-I../include/msvcrt',
    '-D_UCRT', '-D_RPCRT4_', '-DMSWMSG',
    '-D__WINESRC__',
]

res = gen_rc_res.process(rc, extra_args : extra_args)

idl0 = files(
    'epm.idl',
)

idl1 = files(
    'ndr_types.idl',
)

idl_c = gen_idl_c.process([idl0, idl1], extra_args : extra_args)
idl_h = gen_idl_h.process([idl0, idl1], extra_args : extra_args)
idl_d = gen_idl_dlldata.process(idl1, extra_args : extra_args)
idl_p = gen_idl_p_c.process(idl1, extra_args : extra_args)

src = files(
    'cproxy.c',
    'cpsf.c',
    'cstub.c',
    'ndr_clientserver.c',
    'ndr_contexthandle.c',
    'ndr_es.c',
    'ndr_fullpointer.c',
    'ndr_marshall.c',
    'ndr_ole.c',
    'ndr_stubless.c',
    'ndr_typelib.c',
    'rpc_assoc.c',
    'rpc_async.c',
    'rpc_binding.c',
    'rpc_epmap.c',
    'rpc_message.c',
    'rpc_server.c',
    'rpc_transport.c',
    'rpcrt4_main.c',
    'thunks.c',
)

deps = [
    'uuid',
    'advapi32',
    'iphlpapi',
    'wininet',
    'secur32',
    'user32',
    'ws2_32',
    'ole32',
    'oleaut32',
    'winecrt0',
    'ucrtbase',
    'kernel32',
    'ntdll',
]

dlls += {
    'rpcrt4' : {
        'idl_c' : [idl_c, idl_p, idl_d],
        'idl_h' : idl_h,
        'res' : res,
        'extra_args' : extra_args,
        'src' : src,
        'obj' : [],
        'deps' : deps,
    }
}
