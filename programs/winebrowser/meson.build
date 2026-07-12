src = files(
    'main.c',
)
	
flags = [
    '-mwindows', '-municode',
]

exes += {
    'winebrowser' : {
        'src' : src,
        'flags' : flags,
        'res' : [],
        'deps' : [
            'urlmon',
            'oleaut32',
            'shell32',
            'user32',
            'advapi32',
        ],
    }
}
