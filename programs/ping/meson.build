src = files( 
    'ping_main.c',
)

flags = [
    '-mconsole',
]

exes += {
    'ping' : {
        'src' : src,
        'flags' : flags,
        'res' : [],
        'deps' : [
            'ws2_32',
            'iphlpapi',
        ],
    }
}
