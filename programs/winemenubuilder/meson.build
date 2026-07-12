src = files(
    'winemenubuilder.c',
)

flags = [
    '-mwindows', '-municode',
]

exes += {
    'winemenubuilder' : {
        'src' : src,
        'flags' : flags,
        'res' : [],
        'deps' : [
            'uuid',
            'windowscodecs',
            'shell32',
            'shlwapi',
            'ole32',
            'user32',
            'advapi32',
        ],
    }
}
