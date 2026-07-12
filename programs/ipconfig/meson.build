src = files( 
    'ipconfig.c',
)

rc = files(
    'ipconfig.rc',
)

res = gen_rc_res.process(rc)

flags = [
    '-mconsole', '-municode',
]

exes += {
    'ipconfig' : {
        'src' : src,
        'flags' : flags,
        'res' : res,
        'deps' : [
            'iphlpapi',
            'ws2_32',
            'user32',
        ],
    }
}
