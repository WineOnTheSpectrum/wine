src = files(
    'callback.c',
    'hlpfile.c',
    'macro.c',
    'string.c',
    'winhelp.c',
    #'winhelp.svg',
)

ls = files(
    'macro.lex.l',
)
flex_c = gen_flex.process(ls)

rc = files(
    'winhlp32.rc',
)

res = gen_rc_res.process(rc)

flags = [
    '-mwindows',
]

exes += {
    'winhlp32' : {
        'src' : [flex_c, src],
        'flags' : flags,
        'res' : [],
        'deps' : [
            'user32',
            'gdi32',
            'shell32',
            'comctl32',
            'comdlg32',
        ],
    }
}
