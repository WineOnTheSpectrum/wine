src = files(
    'regsvr32.c',
)

rc = files(
    'regsvr32.rc',
)

res = gen_rc_res.process(rc)

man = files(
    'regsvr32.man.in',
)

flags = [
    '-mwindows', '-municode',
]

exes += {
    'regsvr32' : {
        'src' : src,
        'flags' : flags,
        'res' : res,
        'deps' : [
            'ole32',
            'user32',
            'kernelbase',
        ],
    }
}
