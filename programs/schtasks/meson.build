src = files(
    'schtasks.c',
)

flags = [
    '-mconsole', '-municode',
]

exes += {
    'schtasks' : {
        'src' : src,
        'flags' : flags,
        'res' : [],
        'deps' : [
            'oleaut32',
            'ole32',
        ],
    }
}
