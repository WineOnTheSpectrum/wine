src = files(
    'action.c',
    'alter.c',
    'appsearch.c',
    'assembly.c',
    'automation.c',
    'classes.c',
    'create.c',
    'custom.c',
    'database.c',
    'delete.c',
    'dialog.c',
    'distinct.c',
    'drop.c',
    'files.c',
    'font.c',
    'format.c',
    'handle.c',
    'insert.c',
    'install.c',
    'media.c',
    'msi.c',
    'msi_main.c',
    'msiquery.c',
    'package.c',
    'patch.c',
    'record.c',
    'registry.c',
    'script.c',
    'select.c',
    'source.c',
    'storages.c',
    'streams.c',
    'string.c',
    'suminfo.c',
    'table.c',
    'tokenize.c',
    'update.c',
    'upgrade.c',
    'where.c',
)

extra_args = [
    '-I../dlls/msi',
    '-I../include/msvcrt',
    '-D_UCRT',
    '-D__WINESRC__',
]

idl_server = files(
    'msiserver.idl',
)

idl_msi = files(
    'winemsi.idl',
)

idls = files(
    '../../include/fusion.idl',
    '../../include/activscp.idl',
    '../../include/mscoree.idl',
    '../../include/msxml2.idl',
)

ys = files(
    'cond.y',
    'sql.y',
)

rc = files(
    'msi.rc',
)

idl_flags = [
    '--prefix-server=s_',
]

res = gen_rc_res.process(rc, extra_args : extra_args) 
idl_h = gen_idl_h.process([idl_server, idl_msi, idls], extra_args : extra_args + idl_flags) 
idl_c = gen_idl_c.process(idl_msi, extra_args : extra_args + idl_flags)
idl_s = gen_idl_s_c.process(idl_msi, extra_args : extra_args + idl_flags)
idl_i = gen_idl_i_c.process(idl_server, extra_args : extra_args + idl_flags)
idl_t = gen_idl_tres.process(idl_server, extra_args : extra_args + idl_flags)
idl_r = gen_idl_rres.process(idl_server, extra_args : extra_args + idl_flags)

bison_c = gen_bison.process(ys)


deps = [
    'uuid',
    'urlmon',
    'wininet',
    'comctl32',
    'shell32',
    'shlwapi',
    'cabinet',
    'oleaut32',
    'ole32',
    'version',
    'user32',
    'gdi32',
    'advapi32',
    'rpcrt4',
    'sxs',
    'imagehlp',
    'mspatcha',
    'odbccp32',
    'wintrust',
    'crypt32',
    'winecrt0',
    'ucrtbase',
    'kernel32',
    'ntdll',
]

dlls += {
    'msi' : {
        'idl_c' : [idl_i, idl_c, idl_s, idl_t, idl_r],
        'idl_h' : idl_h,
        'res' : res,
        'extra_args' : extra_args,
        'src' : [src, bison_c],
        'obj' : [],
        'deps' : deps,
    }
}
