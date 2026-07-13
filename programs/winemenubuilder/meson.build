src = files(
    'winemenubuilder.c',
)

flags = [
    '-mwindows', '-municode',
]

idls = files(
    '../../include/wincodec.idl',
)

idl_h = gen_idl_h.process(idls)

exes += {
    'winemenubuilder' : {
        'src' : [idl_h, src],
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
