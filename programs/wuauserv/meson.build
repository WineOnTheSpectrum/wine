src = files(
    'main.c',
)

flags = [
    '-mconsole',
]

exes += {
    'wuauserv' : {
        'src' : src,
        'flags' : flags,
        'res' : [],
        'deps' : [
            'advapi32',
        ],
    }
}
