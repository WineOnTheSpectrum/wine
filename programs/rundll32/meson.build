src = files(
    'rundll32.c',
)

flags = [
    '-mwindows', '-municode',
]

exes += {
    'rundll32' : {
        'src' : src,
        'flags' : flags,
        'res' : [],
        'deps' : [
            'user32',
            'kernelbase',
        ],
    }
}
