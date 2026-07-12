src = files(
    'wineconsole.c',
)
    
rc = files(
    'wineconsole.rc',
)

res = gen_rc_res.process(rc)

man = files(
    'wineconsole.man.in',
)
	
flags = [
    '-mwindows', '-municode',
]

exes += {
    'wineconsole' : {
        'src' : src,
        'flags' : flags,
        'res' : res,
        'deps' : [
            'advapi32',
            'comctl32',
            'user32',
            'gdi32',
        ],
    }
}
