src = files(
    'gui.c',
    'main.c',
    'send.c',
    'util.c',
    #'winetest.svg',
)

rc = files(
    'winetest.rc',
)

idls = files(
    '../../include/mshtml.idl',
    '../../include/dimm.idl',
)

idl_h = gen_idl_h.process(idls)

git_cmd = run_command('git', 'rev-parse', 'HEAD', check: true)
git_hash = git_cmd.stdout().strip()


build_nfo = custom_target('build.nfo',
    input : [],
    output : 'build.nfo',
    command : [
        'sh', '-c',
        '@0@ -v 2> @OUTPUT0@'.format(meson.get_compiler('c', native : true).get_id()),
    ],
)

build_rc = custom_target('build.rc',
    input : build_nfo,
    output : 'build.rc',
    command : [
        'sh', '-c',
        'echo \'STRINGTABLE { 1 "@0@" }\' > @OUTPUT0@'.format(git_hash),
    ],
)

res = gen_rc_res.process([build_rc, rc], extra_args : ['-Iprograms/winetest'])

flags = [
    '-mconsole',
]

exes += {
    'winetest' : {
        'src' : [build_nfo, idl_h, src],
        'flags' : flags,
        'res' : res,
        'deps' : [
            'uuid',
            'comctl32',
            'version',
            'user32',
            'gdi32',
            'advapi32',
            'wsock32',
            'ole32',
        ],
    }
}
