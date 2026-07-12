src = files(
    'winevdm.c',
)

rc = files(
    'winevdm.rc',
)
res = gen_rc_res.process(rc)

flags = [
    '-mwindows',
]

exes += {
    'winevdm' : {
        'src' : src,
        'flags' : flags,
        'res' : res,
        'deps' : [
            'user32',
            'kernel',
        ],
    }
}
