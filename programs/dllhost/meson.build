src = files( 
    'dllhost.c',
)

flags = [
    '-mwindows', '-municode',
]

exes += {
    'dllhost' : {
        'src' : src,
        'flags' : flags,
        'res' : [],
        'deps' : [
            'ole32',
            'uuid',    
        ],
    }
}
