src = files( 
    'main.c',
)

mc = files(
    'fsutil.mc',
)

res = gen_mc_res.process(mc)

flags = [
    '-mconsole', '-municode',
]

exes += {
    'fsutil' : {
        'src' : src,
        'flags' : flags,
        'res' : res,
        'deps' : [
            'user32',
        ],
    }
}
