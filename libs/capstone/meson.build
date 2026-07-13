src = files(
    'MCInst.c',
    'MCInstrDesc.c',
    'MCRegisterInfo.c',
    'Mapping.c',
    'SStream.c',
    'arch/AArch64/AArch64BaseInfo.c',
    'arch/AArch64/AArch64Disassembler.c',
    'arch/AArch64/AArch64InstPrinter.c',
    'arch/AArch64/AArch64Mapping.c',
    'arch/AArch64/AArch64Module.c',
    'arch/ARM/ARMDisassembler.c',
    'arch/ARM/ARMInstPrinter.c',
    'arch/ARM/ARMMapping.c',
    'arch/ARM/ARMModule.c',
    'arch/X86/X86ATTInstPrinter.c',
    'arch/X86/X86Disassembler.c',
    'arch/X86/X86DisassemblerDecoder.c',
    'arch/X86/X86InstPrinterCommon.c',
    'arch/X86/X86IntelInstPrinter.c',
    'arch/X86/X86Mapping.c',
    'arch/X86/X86Module.c',
    'cs.c',
    'utils.c'
)

# EXTRADEFS = -DCAPSTONE_HAS_ARM -DCAPSTONE_HAS_ARM64 -DCAPSTONE_HAS_X86 -DNDEBUG

capstone_32 = static_library('capstone_32', [headers, src],
    include_directories : [incdir, 'include', '../../include/msvcrt'],
    c_args : extra_flags_32 + [
      '-DCAPSTONE_HAS_X86',
      '-DNDEBUG',
      '-D_UCRT',
      '-D_WIN32',
    ],
    pic : true,
    native : false,
    build_by_default : meson.is_cross_build(),
)

capstone_64 = static_library('capstone_64', [headers, src],
    include_directories : [incdir, 'include', '../../include/msvcrt'],
    c_args : extra_flags_64 + [
      '-DCAPSTONE_HAS_X86',
      '-DNDEBUG',
      '-D_UCRT',
      '-D__WINE_PE_BUILD',
    ],
    native : false,
    build_by_default : meson.is_cross_build(),
)
