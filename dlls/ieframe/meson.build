src = files(
    'classinfo.c',
    'client.c',
    'dochost.c',
    'events.c',
    'frame.c',
    'ie.c',
    'ieframe_main.c',
    'iehtmlwnd.c',
    #'ietoolbar.svg',
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

rc = files(
    'ieframe.rc',
)

extra_args = [
    '-I../include/msvcrt',
    '-D_UCRT',
]

res = gen_rc_res.process(rc, extra_args : extra_args)

idls = files(
    'ieframe_v1.idl',
)

idl_h = gen_idl_h.process(idls)

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

dlls += {
    'ieframe' : {
        'idl_h' : idl_h,
        'res' : res,
        'extra_args' : extra_args,
        'src' : src,
        'deps' : deps,
    }
}
