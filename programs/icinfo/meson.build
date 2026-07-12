src = files( 
    'icinfo.c',
)

flags = [
    '-mconsole', '-municode',
]

exes += {
    'icinfo' : {
        'src' : src,
        'flags' : flags,
        'res' : [],
        'deps' : [
            'msvfw32',
        ],
    }
}
