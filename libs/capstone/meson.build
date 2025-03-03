src = [
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
]

# FIXME: add flags.
# EXTRAINCL = $(CAPSTONE_PE_CFLAGS)
# EXTRADEFS = -DCAPSTONE_HAS_ARM -DCAPSTONE_HAS_ARM64 -DCAPSTONE_HAS_X86 -DNDEBUG

static_library('capstone_32', [headers, src],
    include_directories : [incdir, 'include'],
    c_args : extra_flags_32 + [
      '-DCAPSTONE_HAS_X86',
      '-DNDEBUG'
    ],
    pic : true,
    native : false,
    build_by_default : meson.is_cross_build(),
)

static_library('capstone_64', [headers, src],
    include_directories : [incdir, 'include'],
    c_args : extra_flags_64 + [
      '-DCAPSTONE_HAS_X86',
      '-DNDEBUG'
    ],
    native : false,
    build_by_default : meson.is_cross_build(),
)
