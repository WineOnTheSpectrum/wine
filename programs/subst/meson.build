src = files(
    'main.c',
)

flags = [
    '-mconsole', '-municode',
]

exes += {
    'subst' : {
        'src' : src,
        'flags' : flags,
        'res' : [],
        'deps' : [
            'shell32',
            'user32',
        ],
    }
}
