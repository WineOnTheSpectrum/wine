src = files(
    'device.c',
)

flags = [
    '-mwindows', '-municode',
]

exes += {
    'winedevice' : {
        'src' : src,
        'flags' : flags,
        'res' : [],
        'deps' : [
            'advapi32',
            'ntoskrnl',
        ],
    }
}
