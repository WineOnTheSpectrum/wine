src = files( 
    'main.c',
)

flags = [
    '-mconsole', '-municode',
]

exes += {
    'msidb' : {
        'src' : src,
        'flags' : flags,
        'res' : [],
        'deps' : [
            'msi',
            'shlwapi',
        ],
    }
}
