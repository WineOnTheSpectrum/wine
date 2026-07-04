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

res = gen_rc_res.process(rc, extra_args : extra_args)

deps = [
    'uuid',
    'user32',
    'advapi32',
    'ole32',
    'msacm32',
    #'dinput8', XXX is this needed?
    'winecrt0',
    'ucrtbase',
    'kernel32',
    'ntdll',
]

dlls += {
    'winmm' : {
        'idl_h' : [],
        'res' : res,
        'extra_args' : extra_args,
        'src' : src,
        'deps' : deps,
    }
}
