src = files(
    'classinfo.c',
    'client.c',
    'dochost.c',
    'events.c',
    'frame.c',
    'ie.c',
    'ieframe_main.c',
    'iehtmlwnd.c',
    'iexplore.c',
    'intshcut.c',
    'navigate.c',
    'oleobject.c',
    'persist.c',
    'shellbrowser.c',
    'shelluihelper.c',
    'urlhist.c',
    'view.c',
    'webbrowser.c',
)
    #'ietoolbar.svg',

rc = files(
    'ieframe.rc',
)

extra_args = [
    '-I../include',
    '-I../include/msvcrt',
    '-D_UCRT',
    '-D__WINESRC__',
]

res = gen_rc_res.process(rc, extra_args : extra_args)

idl0 = files(
    '../../include/mshtmhst.idl',
    '../../include/hlink.idl',
    '../../include/htiface.idl',
    '../../include/htiframe.idl',
    '../../include/shdeprecated.idl',
    '../../include/docobjectservice.idl',
    '../../include/mshtml.idl',
    '../../include/dimm.idl',
    '../../include/ieautomation.idl',
    '../../include/urlhist.idl',
    '../../include/perhist.idl',
)

idls = files(
    'ieframe_v1.idl',
)

idl_c = gen_idl_c.process(idls, extra_args : extra_args)
idl_h = gen_idl_h.process([idl0, idls], extra_args : extra_args)

deps = [
    'uuid',
    'urlmon',
    'shell32',
    'comctl32',
    'shlwapi',
    'oleaut32',
    'ole32',
    'user32',
    'gdi32',
    'advapi32',
    'winecrt0',
    'ucrtbase',
    'kernel32',
    'ntdll',
]

manifest = files(
    'ieframe.manifest',
)

dlls += {
    'ieframe' : {
        'idl_c' : idl_c,
        'idl_h' : idl_h,
        'res' : res,
        'extra_args' : extra_args,
        'src' : src,
        'obj' : [],
        'deps' : deps,
        'manifest' : manifest,
    }
}
