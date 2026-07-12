src = files(
    'about.c',
    'childwnd.c',
    'edit.c',
    'framewnd.c',
    'hexedit.c',
    'listview.c',
    'main.c',
    'regedit.c',
    #'regedit.svg',
    'regproc.c',
    'treeview.c',

)

rc = files(
    'regedit.rc',
)

res = gen_rc_res.process(rc)

man = files(
    'regedit.man.in',
)

flags = [
    '-mwindows', '-municode',
]

exes += {
    'regedit' : {
        'src' : src,
        'flags' : flags,
        'res' : res,
        'deps' : [
            'advapi32',
            'shcore',
            'shlwapi',
            'shell32',
            'comdlg32',
            'comctl32',
            'user32',
            'gdi32',
        ],
    }
}
