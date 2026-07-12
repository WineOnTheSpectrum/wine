src = files(
    'main.c',
)

flags = [
    '-mconsole', '-municode',
]

exes += {
    'winemsibuilder' : {
        'src' : src,
        'flags' : flags,
        'res' : [],
        'deps' : [
            'msi',
            'ole32',
        ],
    }
}
