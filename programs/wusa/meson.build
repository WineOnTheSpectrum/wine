src = files(
    'main.c',
    'manifest.c',
)

flags = [
    '-mwindows', '-municode',
]

exes += {
    'wusa' : {
        'src' : src,
        'flags' : flags,
        'res' : [],
        'deps' : [
            'cabinet',
            'shlwapi',
            'ole32',
            'oleaut32',
            'advapi32',
            'shell32',
        ],
    }
}
