src = files(
    'svchost.c',
)

flags = [
    '-mwindows', '-municode',
]

exes += {
    'svchost' : {
        'src' : src,
        'flags' : flags,
        'res' : [],
        'deps' : [
            'advapi32',
        ],
    }
}
