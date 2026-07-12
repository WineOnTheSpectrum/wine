src = files(
    'main.c',
)

flags = [
    '-mconsole', '-municode',
]

exes += {
    'whoami' : {
        'src' : src,
        'flags' : flags,
        'res' : [],
        'deps' : [
            'secur32',
            'advapi32',
        ],
    }
}
