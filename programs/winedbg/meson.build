src = files(
    'be_arm.c',
    'be_arm64.c',
    'be_i386.c',
    'be_x86_64.c',
    'break.c',
    'crashdlg.c',
    'display.c',
    'expr.c',
    'gdbproxy.c',
    'info.c',
    'memory.c',
    'source.c',
    'stack.c',
    'symbol.c',
    'tgt_active.c',
    'tgt_minidump.c',
    'tgt_module.c',
    'types.c',
    'winedbg.c',
)

ys = files(
    'dbg.y',
)
bison_c = gen_bison.process(ys)

ls = files(
    'debug.l',
)
lex_c = gen_flex.process(ls)

rc = files(
    'winedbg.rc',
)
res = gen_rc_res.process(rc)

man = files(
    'winedbg.man.in',
)

flags = [
    '-mconsole',
]

exes += {
    'winedbg' : {
        'src' : [bison_c, lex_c, src],
        'flags' : flags,
        'res' : res,
        'deps' : [
            'capstone',
            'dbghelp',
            'advapi32',
            'comdlg32',
            'shell32',
            'comctl32',
            'user32',
            'gdi32',
            'ws2_32',
        ],
    }
}
