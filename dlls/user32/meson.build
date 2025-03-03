rc = files(
    'user32.rc',
)

extra_args = [
    '-I../libs/png',
    '-I../libs/zlib',
    '-D_USER32_',
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
    'uuid',
    'gdi32',
    'sechost',
    'advapi32',
    'kernelbase',
    'win32u',
    'imm32',
    'combase',
    'winecrt0',
    'ucrtbase',
    'kernel32',
    'ntdll',
]

dlls += {
    'user32' : {
        'idl_h' : [],
        'res' : res,
        'extra_args' : extra_args,
        'src' : src,
        'deps' : deps,
    }
}
