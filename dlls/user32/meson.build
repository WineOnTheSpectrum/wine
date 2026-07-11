rc = files(
    'user32.rc',
)

extra_args = [
    '-I../include',
    '-I../include/msvcrt',
    '-I../libs/png',
    '-D_UCRT',
    '-D_USER32_',
    '-D__WINESRC__', '-D__WINE_PE_BUILD',
]

res = gen_rc_res.process(rc, extra_args : extra_args)

src = files(
    'button.c',
    'class.c',
    'clipboard.c',
    'combo.c',
    'cursoricon.c',
    'dde_client.c',
    'dde_misc.c',
    'dde_server.c',
    'defdlg.c',
    'defwnd.c',
    'desktop.c',
    'dialog.c',
    'edit.c',
    'exticon.c',
    'hook.c',
    'icontitle.c',
    'input.c',
    'listbox.c',
    'lstr.c',
    'mdi.c',
    'menu.c',
    'message.c',
    'misc.c',
    'msgbox.c',
    'nonclient.c',
    'property.c',
    'resource.c',
    'scroll.c',
    'static.c',
    'sysparams.c',
    'text.c',
    'uitools.c',
    'user_main.c',
    'win.c',
    'winhelp.c',
    'winproc.c',
    'winstation.c',
    'wsprintf.c',
)

deps = [
    'png',
    'zlib',
    'gdi32',
    'sechost',
    'advapi32',
    'kernelbase',
    'win32u',
    'uuid',
    'winecrt0',
    'ucrtbase',
    'kernel32',
    'ntdll',
    'imm32', # delay?
    'combase', # delay?
]

dlls += {
    'user32' : {
        'idl_c' : [],
        'idl_h' : [],
        'res' : res,
        'extra_args' : extra_args,
        'src' : src,
        'obj' : [],
        'deps' : deps,
    }
}
