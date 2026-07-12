src = files( 
    'netstat.c',
)

rc = files(
    'netstat.rc',
)

res = gen_rc_res.process(rc)

flags = [
    '-mconsole', '-municode',
]

exes += {
    'netstat' : {
        'src' : src,
        'flags' : flags,
        'res' : res,
        'deps' : [
            'iphlpapi',
            'user32',
            'ws2_32',
        ],
    }
}
