src = [
    'dx10guid.c',
    'dx8guid.c',
    'dx9guid.c',
    'dxguid.c'
]

idls = files(
    '../../include/dcommon.idl',
    '../../include/d2d1_1.idl',
    '../../include/d2d1_2.idl',
    '../../include/d2d1_3.idl',
    '../../include/d2d1effectauthor.idl',
    '../../include/d2d1effects_1.idl',
    '../../include/d2d1effects_2.idl',
    '../../include/d2d1effects.idl',
    '../../include/d2d1.idl',
    '../../include/d3d10_1.idl',
    '../../include/d3d10effect.idl',
    '../../include/d3d10.idl',
    '../../include/d3d10sdklayers.idl',
    '../../include/d3d10shader.idl',
    '../../include/d3d11_1.idl',
    '../../include/d3d11_2.idl',
    '../../include/d3d11_3.idl',
    '../../include/d3d11_4.idl',
    '../../include/d3d11.idl',
    '../../include/d3d11on12.idl',
    '../../include/d3d11sdklayers.idl',
    '../../include/d3d12.idl',
    '../../include/d3d12sdklayers.idl',
    '../../include/d3d12shader.idl',
    '../../include/d3d12video.idl',
    '../../include/d3d9on12.idl',
    '../../include/d3dcommon.idl',
    '../../include/d3dx11core.idl',
    '../../include/dxgi1_2.idl',
    '../../include/dxgi1_3.idl',
    '../../include/dxgi1_4.idl',
    '../../include/dxgi1_5.idl',
    '../../include/dxgi1_6.idl',
    '../../include/dxgicommon.idl',
    '../../include/dxgidebug.idl',
    '../../include/dxgiformat.idl',
    '../../include/dxgi.idl',
    '../../include/dxgitype.idl',
    '../../include/dxva2api.idl',

    '../../include/strmif.idl',
)

idl_h = gen_idl_h.process(idls)

dxguid_32 = static_library('dxguid_32', [headers, idl_h, src],
    include_directories : incdir,
    c_args : extra_flags_32,
    pic : true,
    native : false,
    build_by_default : meson.is_cross_build(),
)

dxguid_64 = static_library('dxguid_64', [headers, idl_h, src],
    include_directories : incdir,
    c_args : extra_flags_64,
    native : false,
    build_by_default : meson.is_cross_build(),
)
