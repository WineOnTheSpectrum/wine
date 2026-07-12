src = files(
    'main.c',
)

flags = [
    '-mconsole', '-municode',
]

exes += {
    'systeminfo' : {
        'src' : src,
        'flags' : flags,
        'res' : [],
        'deps' : [
            'oleaut32',
            'ole32',
            'advapi32',
        ],
    }
}
