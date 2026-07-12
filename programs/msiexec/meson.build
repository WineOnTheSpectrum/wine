src = files( 
    'msiexec.c',
    #'msiexec.svg',
    'service.c',
)

rc = files(
    'rsrc.rc',
)

res = gen_rc_res.process(rc)

man = files(
    'msiexec.man.in',
)

flags = [
    '-mwindows',
]

exes += {
    'msiexec' : {
        'src' : src,
        'flags' : flags,
        'res' : res,
        'deps' : [
            'msi',
            'ole32',
            'advapi32',
            'user32',
            'comctl32',
        ],
    }
}
