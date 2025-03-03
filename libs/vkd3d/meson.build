src = [
    'libs/vkd3d-common/blob.c',
    'libs/vkd3d-common/debug.c',
    'libs/vkd3d-common/error.c',
    'libs/vkd3d-common/memory.c',
    'libs/vkd3d-common/utf8.c',
    'libs/vkd3d-shader/checksum.c',
    'libs/vkd3d-shader/d3d_asm.c',
    'libs/vkd3d-shader/d3dbc.c',
    'libs/vkd3d-shader/dxbc.c',
    'libs/vkd3d-shader/dxil.c',
    'libs/vkd3d-shader/fx.c',
    'libs/vkd3d-shader/glsl.c',
    'libs/vkd3d-shader/hlsl.c',
    'libs/vkd3d-shader/hlsl_codegen.c',
    'libs/vkd3d-shader/hlsl_constant_ops.c',
    'libs/vkd3d-shader/ir.c',
    'libs/vkd3d-shader/msl.c',
    'libs/vkd3d-shader/spirv.c',
    'libs/vkd3d-shader/tpf.c',
    'libs/vkd3d-shader/vkd3d_shader_main.c',
    'libs/vkd3d-utils/reflection.c',
    'libs/vkd3d-utils/vkd3d_utils_main.c',
    'libs/vkd3d/cache.c',
    'libs/vkd3d/command.c',
    'libs/vkd3d/device.c',
    'libs/vkd3d/resource.c',
    'libs/vkd3d/state.c',
    'libs/vkd3d/utils.c',
    'libs/vkd3d/vkd3d_main.c'
]

bison_srcs = gen_bison.process(
    'libs/vkd3d-shader/hlsl.y',
    'libs/vkd3d-shader/preproc.y',
)

flex_srcs = gen_flex.process(
    'libs/vkd3d-shader/hlsl.l',
    'libs/vkd3d-shader/preproc.l',
)

static_library('vkd3d_32', [headers, bison_srcs, flex_srcs, src],
    include_directories : [incdir, 'include', 'include/private', 'libs/vkd3d', 'libs/vkd3d-shader'],
    c_args : extra_flags_32 + [
	'-DWINE_NO_NAMELESS_EXTENSION',
	'-DLIBVKD3D_SOURCE',
	'-DLIBVKD3D_SHADER_SOURCE',
	'-DLIBVKD3D_UTILS_SOURCE',
    ],
    pic : true,
    native : false,
    build_by_default : meson.is_cross_build(),
)

static_library('vkd3d_64', [headers, bison_srcs, flex_srcs, src],
    include_directories : [incdir, 'include', 'include/private', 'libs/vkd3d', 'libs/vkd3d-shader'],
    c_args : extra_flags_64 + [
	'-DWINE_NO_NAMELESS_EXTENSION',
	'-DLIBVKD3D_SOURCE',
	'-DLIBVKD3D_SHADER_SOURCE',
	'-DLIBVKD3D_UTILS_SOURCE',
    ],
    native : false,
    build_by_default : meson.is_cross_build(),
)
