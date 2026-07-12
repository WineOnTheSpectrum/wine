src = files(
    'main.c',
)

rc = files(
    'chcp.rc',
)

res = gen_rc_res.process(rc)

flags = [
    '-mconsole', '-municode',
]

coms += {
    'chcp' : {
        'src' : src,
        'flags' : flags,
        'res' : res,
        'deps' : [
            'kernelbase',
        ],
    }
}
