src = files(
    'main.c',
)

flags = [
    '-mconsole', '-municode',
]

exes += {
    'winmgmt' : {
        'src' : src,
        'flags' : flags,
        'res' : [],
        'deps' : [
            'advapi32',
        ],
    }
}
