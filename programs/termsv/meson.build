src = files(
    'main.c',
)

flags = [
    '-mconsole', '-municode',
]

exes += {
    'termsv' : {
        'src' : src,
        'flags' : flags,
        'res' : [],
        'deps' : [
            'advapi32',
        ],
    }
}
