src = files( 
    'lodctr_main.c',
)

flags = [
    '-mconsole',
]

exes += {
    'lodctr' : {
        'src' : src,
        'flags' : flags,
        'res' : res,
        'deps' : [
            'loadperf',
        ],
    }
}
