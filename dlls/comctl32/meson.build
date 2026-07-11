rc = files(
    'comctl32.rc',
)

extra_args = [
    '-I../include/msvcrt',
    '-D_UCRT', '-D_COMCTL32_',
    '-D__WINESRC__', '-D__WINE_PE_BUILD',
]

res = gen_rc_res.process(rc, extra_args : extra_args)

idls = files(
    '../../include/commoncontrols.idl',
    '../../include/uiautomationcore.idl',
    '../../include/uiautomationclient.idl',
)

idl_h = gen_idl_h.process(idls, extra_args : extra_args)

src = files(
    'animate.c',
    'button.c',
    'combo.c',
    'comboex.c',
    'commctrl.c',
    'datetime.c',
    'dpa.c',
    'draglist.c',
    'dsa.c',
    'edit.c',
    'flatsb.c',
    'header.c',
    'hotkey.c',
    'imagelist.c',
    'ipaddress.c',
    'listbox.c',
    'listview.c',
    'monthcal.c',
    'nativefont.c',
    'pager.c',
    'progress.c',
    'propsheet.c',
    'rebar.c',
    'smoothscroll.c',
    'static.c',
    'status.c',
    'string.c',
    'syslink.c',
    'tab.c',
    'taskdialog.c',
    'toolbar.c',
    'tooltips.c',
    'trackbar.c',
    'treeview.c',
    'updown.c',
)

deps = [
    'uuid',
    'user32',
    'gdi32',
    'advapi32',
    'imm32',
    'kernelbase',
    'oleacc',
    'winmm',
    'uxtheme',
    'winecrt0',
    'ucrtbase',
    'kernel32',
    'ntdll',
]

dlls += {
    'comctl32' : {
        'idl_c' : [],
        'idl_h' : idl_h,
        'res' : res,
        'extra_args' : extra_args,
        'src' : src,
        'obj' : [],
        'deps' : deps,
    }
}
