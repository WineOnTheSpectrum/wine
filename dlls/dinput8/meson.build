src = files( 
    '../dinput/ansi.c',
    '../dinput/config.c',
    '../dinput/data_formats.c',
    '../dinput/device.c',
    '../dinput/dinput.c',
    '../dinput/dinput_main.c',
    '../dinput/joystick_hid.c',
    '../dinput/keyboard.c',
    '../dinput/mouse.c',
)

rc = files(
#    '../dinput/dinput.rc',
    'version.rc',
)

extra_args = [
    '-I../include',
    '-I../include/msvcrt',
    '-D_UCRT',
    '-D__WINESRC__',
    '-DDIRECTINPUT_VERSION=0x0800',
]

res = gen_rc_res.process(rc, extra_args : extra_args)

idl0 = files(
    'dinput8.idl',
)

idl_h = gen_idl_h.process(idl0, extra_args : extra_args)
idl_c = gen_idl_c.process(idl0, extra_args : extra_args)

deps = [
    'dxguid',
    'uuid',
    'comctl32',
    'ole32',
    'user32',
    'advapi32',
    'hid',
    'setupapi',
    'winecrt0',
    'ucrtbase',
    'kernel32',
    'ntdll',
]

dlls += {
    'dinput8' : {
        'idl_c' : idl_c,
        'idl_h' : idl_h,
        'res' : res,
        'extra_args' : extra_args,
        'src' : src,
        'obj' : [],
        'deps' : deps,
    }
}
