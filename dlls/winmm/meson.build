src = files(
    'driver.c',
    'joystick.c',
    'lolvldrv.c',
    'mci.c',
    'mmio.c',
    'playsound.c',
    'time.c',
    'waveform.c',
    'winmm.c',
)

rc = files(
    'winmm.rc',
    'winmm_res.rc',
)

extra_args = [
    '-I../include/msvcrt',
    '-D_UCRT',
    '-D_WINMM_',
]

idls = files(
    '../../include/audioclient.idl',
    '../../include/audiopolicy.idl',
    '../../include/mmdeviceapi.idl',
)

idl_h = gen_idl_h.process(idls, extra_args : extra_args)

res = gen_rc_res.process(rc, extra_args : extra_args)

deps = [
    'uuid',
    'user32',
    'advapi32',
    'ole32',
    'msacm32',
    'winecrt0',
    'ucrtbase',
    'kernel32',
    'ntdll',
    'dinput8', # delay?
]

dlls += {
    'winmm' : {
        'idl_c' : [],
        'idl_h' : idl_h,
        'res' : res,
        'extra_args' : extra_args,
        'src' : src,
        'obj' : [],
        'deps' : deps,
    }
}
