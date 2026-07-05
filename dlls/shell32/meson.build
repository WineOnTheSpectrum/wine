rc = files(
    'shell32.rc',
)

extra_args = [
    '-I../include/msvcrt',
    '-D_MSVCR_VER=0', '-D_SHELL32_',
]

res = gen_rc_res.process(rc, extra_args : extra_args)

idls = files(
    'shell32_classes.idl',
    'shell32_tlb.idl',
)

idl_c = gen_idl_c.process(idls)
idl_h = gen_idl_h.process(idls)

src = files(
    'appbar.c',
    'assoc.c',
    'autocomplete.c',
    'brsfolder.c',
    'changenotify.c',
    'classes.c',
    'clipboard.c',
    'control.c',
    'cpanelfolder.c',
    'dataobject.c',
    'dde.c',
    'debughlp.c',
    'dialogs.c',
    'dragdrophelper.c',
    'ebrowser.c',
    'enumidlist.c',
    'folders.c',
    'iconcache.c',
    'new_menu.c',
    'pidl.c',
    'recyclebin.c',
    'shell32_main.c',
    'shelldispatch.c',
    'shellitem.c',
    'shelllink.c',
    'shellole.c',
    'shellord.c',
    'shellpath.c',
    'shellreg.c',
    'shellstring.c',
    'shfldr_desktop.c',
    'shfldr_fs.c',
    'shfldr_mycomp.c',
    'shfldr_netplaces.c',
    'shfldr_printers.c',
    'shlexec.c',
    'shlfileop.c',
    'shlfolder.c',
    'shlfsbind.c',
    'shlmenu.c',
    'shlview.c',
    'shlview_cmenu.c',
    'shpolicy.c',
    'systray.c',
)

deps = [
    'uuid',
    'shlwapi',
    'user32',
    'gdi32',
    'advapi32',
    'ole32',
    'oleaut32',
    'shdocvw',
    'version',
    'comctl32',
    'comdlg32',
    'gdiplus',
    'winecrt0',
    'ucrtbase',
    'kernel32',
    'ntdll',
]

dlls += {
    'shell32' : {
        'idl_c' : idl_c,
        'idl_h' : idl_h,
        'res' : res,
        'extra_args' : extra_args,
        'src' : src,
        'deps' : deps,
    }
}
