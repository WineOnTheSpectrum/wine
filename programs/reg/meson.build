src = files(
    'add.c',
    'copy.c',
    'delete.c',
    'export.c',
    'import.c',
    'query.c',
    'reg.c',
)

rc = files(
    'reg.rc',
)

res = gen_rc_res.process(rc)

flags = [
    '-mconsole', '-municode',
]

exes += {
    'reg' : {
        'src' : src,
        'flags' : flags,
        'res' : res,
        'deps' : [
            'advapi32',
            'user32',
        ],
    }
}
