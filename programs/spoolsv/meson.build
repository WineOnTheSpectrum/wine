src = files(
    'main.c',
)

flags = [
    '-mwindows',
]

exes += {
    'spoolsv' : {
        'src' : src,
        'flags' : flags,
        'res' : [],
        'deps' : [
            'advapi32',
        ],
    }
}
