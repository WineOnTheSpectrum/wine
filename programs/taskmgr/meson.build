src = files(
    'about.c',
    'affinity.c',
    'applpage.c',
    'column.c',
    'dbgchnl.c',
    'debug.c',
    'endproc.c',
    'graph.c',
    'graphctl.c',
    'optnmenu.c',
    'perfdata.c',
    'perfpage.c',
    'priority.c',
    'proclist.c',
    'procpage.c',
    'run.c',
    'taskmgr.c',
    #'taskmgr.svg', 
    'trayicon.c',
)

rc = files(
    'taskmgr.rc',
)

res = gen_rc_res.process(rc)

flags = [
    '-mwindows',
]

exes += {
    'taskmgr' : {
        'src' : src,
        'flags' : flags,
        'res' : res,
        'deps' : [
            'shell32',
            'shlwapi',
            'comctl32',
            'user32',
            'gdi32',
            'advapi32',
        ],
    }
}
