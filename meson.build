project('wine', 'c')

#add_global_arguments('-DWINE_NO_INLINE_STRING', language : 'c', native : true)
add_global_arguments('-DINCLUDEDIR="\"/usr/local/include\""', language : 'c', native : true)
add_global_arguments('-DBINDIR="\"/usr/local/bin\""', language : 'c', native : true)
add_global_arguments('-DLIBDIR="\"/usr/local/lib\""', language : 'c', native : true)

#add_global_arguments('-DWINE_NO_INLINE_STRING', language : 'c', native : false)
add_global_arguments('-DINCLUDEDIR="\"/usr/local/include\""', language : 'c', native : false)
add_global_arguments('-DBINDIR="\"/usr/local/bin\""', language : 'c', native : false)
add_global_arguments('-DLIBDIR="\"/usr/local/lib\""', language : 'c', native : false)

datadir_define = [
    '-DDATADIR="/usr/local/share"',
]

dllpath_define = [
    '-DSYSTEMDLLPATH="/usr/local/share/dll"',
]

extra_flags_tools = [
    '-DCC="gcc -m64"',
    '-DCPP="cpp"',
    '-DCXX="g++ -m64"',
    '-DLD="ld"',
    '-D__WINESRC__', '-DWINE_UNIX_LIB',
]

extra_dll_flags_32 = [
    '-nodefaultlibs',
    '-Wl,--image-base,0x7b000000', # FIXME this address is specific to a dll
]

extra_dll_flags_64 = [
    '-nodefaultlibs',
    '-Wl,--image-base,0x174000000', # FIXME this address is specific to a dll
]

extra_flags_32 = [
  '-m32',
  '-D__WINESRC__', '-D_WIN32',
  '-fno-builtin', '-ffunction-sections', '-fvisibility=hidden', '-gdwarf-4', '-mabi=ms',
]

extra_flags_64 = [
#  '-Wall',
  '-fno-strict-aliasing',
#  '-Wdeclaration-after-statement',
#  '-Wempty-body',
#  '-Wignored-qualifiers',
#  '-Winit-self',
#  '-Wno-packed-not-aligned',
#  '-Wshift-overflow=2',
#  '-Wstrict-prototypes',
#  '-Wtype-limits',
#  '-Wunused-but-set-parameter',
#  '-Wvla',
#  '-Wwrite-strings',
#  '-Wpointer-arith',
#  '-Wlogical-op',
#  '-Wabsolute-value',
#  '-Wformat-overflow',
#  '-Wnonnull',
  '-D__WINESRC__', '-D__WINE_PE_BUILD',
  '-fno-builtin', '-ffunction-sections', '-fvisibility=hidden', '-mcx16', '-mcmodel=small', '-gdwarf-4',
]

cdata = configuration_data()

## See https://mesonbuild.com/Configuration.html and https://mesonbuild.com/Machine-files.html
# https://mesonbuild.com/Reference-manual_returned_compiler.html#compilerhas_header

cc = meson.get_compiler('c', native : true)
mingw_cc = meson.get_compiler('c', native : false)

cdata.set('EXEEXT', '""')
cdata.set('HAVE_ARPA_INET_H', cc.has_header('arpa/inet.h'))
cdata.set('HAVE_ARPA_NAMESER_H', cc.has_header('arpa/nameser.h'))
cdata.set('HAVE_ASM_TERMBITS_H', cc.has_header('asm/termbits.h'))
cdata.set('HAVE_ASM_TYPES_H', cc.has_header('asm/types.h'))
cdata.set('HAVE_ASM_USER_H', cc.has_header('asm/user.h'))
cdata.set('HAVE_ATOMIC_EXCHANGE_N', 1)
cdata.set('HAVE_CAPI20_H', cc.has_header('capi20.h'))
cdata.set('HAVE_CLOCK_GETTIME', cc.has_function('clock_gettime'))
cdata.set('HAVE_CL_CL_H', cc.has_header('CL/cl.h'))
cdata.set('HAVE_CUPS_CUPS_H', cc.has_header('cups/cups.h'))
cdata.set('HAVE_CUPS_PPD_H', cc.has_header('cups/ppd.h'))
cdata.set('HAVE_DLADDR1', cc.has_function('dladdr1'))
cdata.set('HAVE_DLINFO', cc.has_function('dlinfo'))
cdata.set('HAVE_EGL_EGL_H', cc.has_header('EGL/egl.h'))
cdata.set('HAVE_ELF_H', cc.has_header('elf.h'))
cdata.set('HAVE_EPOLL_CREATE', cc.has_function('epoll_create'))
cdata.set('HAVE_EPOLL_PWAIT2', cc.has_function('epoll_pwait2'))
cdata.set('HAVE_FFMPEG', false)
cdata.set('HAVE_FREETYPE', false)
cdata.set('HAVE_FSTATFS', cc.has_function('fstatfs'))
cdata.set('HAVE_FT2BUILD_H', cc.has_header('freetype2/ft2build.h'))
cdata.set('HAVE_FT_TRUETYPEENGINETYPE', false)
cdata.set('HAVE_FUTIMENS', cc.has_function('futimens'))
cdata.set('HAVE_FUTIMES', cc.has_function('futimes'))
cdata.set('HAVE_FUTIMESAT', cc.has_function('futimesat'))
cdata.set('HAVE_GETADDRINFO', cc.has_function('getaddrinfo'))
cdata.set('HAVE_GETATTRLIST', cc.has_function('getattrlist'))
cdata.set('HAVE_GETAUXVAL', cc.has_function('getauxval'))
cdata.set('HAVE_GETIFADDRS', cc.has_function('getifaddrs'))
cdata.set('HAVE_GETRANDOM', cc.has_function('getrandom'))
cdata.set('HAVE_GETTEXT_PO_H', cc.has_header('gettext-po.h'))
cdata.set('HAVE_GNUTLS_CIPHER_INIT', cc.has_function('gnutls_cipher_init'))
cdata.set('HAVE_GPHOTO2_PORT', false)
cdata.set('HAVE_GSSAPI_GSSAPI_EXT_H', cc.has_header('gssapi/gssapi_ext.h'))
cdata.set('HAVE_GSSAPI_GSSAPI_H', cc.has_header('gssapi/gssapi.h'))
cdata.set('HAVE_IFADDRS_H', cc.has_header('ifaddrs.h'))
cdata.set('HAVE_INTTYPES_H', cc.has_header('inttypes.h'))
cdata.set('HAVE_KQUEUE', cc.has_function('kqueue'))
cdata.set('HAVE_KRB5_KRB5_H', cc.has_header('krb5/krb5.h'))
cdata.set('HAVE_LIBAVCODEC_AVCODEC_H', cc.has_header('libavcodec/avcodec.h'))
cdata.set('HAVE_LIBAVCODEC_BSF_H', cc.has_header('libavcodec/bsf.h'))
cdata.set('HAVE_LIBAVFORMAT_AVFORMAT_H', cc.has_header('libavformat/avformat.h'))
cdata.set('HAVE_LIBAVUTIL_AVUTIL_H', cc.has_header('libavutil/avutil.h'))
cdata.set('HAVE_LIBGETTEXTPO', cc.find_library('gettextpo', required: false).found())
cdata.set('HAVE_LIBPROCSTAT', cc.find_library('procstat', required: false).found())
cdata.set('HAVE_LIBPROCSTAT_H', cc.has_header('libprocstat.h'))
cdata.set('HAVE_LIBUDEV_H', cc.has_header('libudev.h'))
cdata.set('HAVE_LIBUNWIND', cc.find_library('unwind', required: false).found())
cdata.set('HAVE_LIBWAYLAND_EGL', false)
cdata.set('HAVE_LIBXSHAPE', false)
cdata.set('HAVE_LIBXXSHM', false)
cdata.set('HAVE_LINK_H', cc.has_header('link.h'))
cdata.set('HAVE_LINUX_CAPI_H', cc.has_header('linux/capi.h'))
cdata.set('HAVE_LINUX_CDROM_H', cc.has_header('linux/cdrom.h'))
cdata.set('HAVE_LINUX_FILTER_H', cc.has_header('linux/filter.h'))
cdata.set('HAVE_LINUX_GETHOSTBYNAME_R_6', false)
cdata.set('HAVE_LINUX_HDREG_H', cc.has_header('linux/hdreg.h'))
cdata.set('HAVE_LINUX_HIDRAW_H', cc.has_header('linux/hidraw.h'))
cdata.set('HAVE_LINUX_INPUT_H', cc.has_header('linux/input.h'))
cdata.set('HAVE_LINUX_IOCTL_H', cc.has_header('linux/ioctl.h'))
cdata.set('HAVE_LINUX_IPX_H', cc.has_header('linux/ipx.h'))
cdata.set('HAVE_LINUX_IRDA_H', cc.has_header('linux/irda.h'))
cdata.set('HAVE_LINUX_MAJOR_H', cc.has_header('linux/major.h'))
cdata.set('HAVE_LINUX_PARAM_H', cc.has_header('linux/param.h'))
cdata.set('HAVE_LINUX_RTNETLINK_H', cc.has_header('linux/rtnetlink.h'))
cdata.set('HAVE_LINUX_SERIAL_H', cc.has_header('linux/serial.h'))
cdata.set('HAVE_LINUX_TYPES_H', cc.has_header('linux/types.h'))
cdata.set('HAVE_LINUX_UCDROM_H', cc.has_header('linux/ucdrom.h'))
cdata.set('HAVE_LINUX_VIDEODEV2_H', cc.has_header('linux/videodev2.h'))
cdata.set('HAVE_LINUX_WIRELESS_H', cc.has_header('linux/wireless.h'))
cdata.set('HAVE_LWP_H', cc.has_header('lwp.h'))
cdata.set('HAVE_MACHINE_CPU_H', cc.has_header('machine/cpu.h'))
cdata.set('HAVE_MACHINE_SYSARCH_H', cc.has_header('machine/sysarch.h'))
cdata.set('HAVE_MACH_MACH_H', cc.has_header('mach/mach.h'))
cdata.set('HAVE_MACH_O_LOADER_H', cc.has_header('mach-o/loader.h'))
cdata.set('HAVE_MNTENT_H', cc.has_header('mntent.h'))
cdata.set('HAVE_MTLDEVICE_REGISTRYID', false)
cdata.set('HAVE_NETDB_H', cc.has_header('netdb.h'))
cdata.set('HAVE_NETINET6_IP6_VAR_H', cc.has_header('netinet6/ip6_var.h'))
cdata.set('HAVE_NETINET_ICMP6_H', cc.has_header('netinet/icmp6.h'))
cdata.set('HAVE_NETINET_ICMP_VAR_H', cc.has_header('netinet/icmp_var.h'))
cdata.set('HAVE_NETINET_IF_ETHER_H', cc.has_header('netinet/if_ether.h'))
cdata.set('HAVE_NETINET_IN_H', cc.has_header('netinet/in.h'))
cdata.set('HAVE_NETINET_IN_PCB_H', cc.has_header('netinet/in_pcb.h'))
cdata.set('HAVE_NETINET_IN_SYSTM_H', cc.has_header('netinet/in_systm.h'))
cdata.set('HAVE_NETINET_IP_H', cc.has_header('netinet/ip.h'))
cdata.set('HAVE_NETINET_IP_ICMP_H', cc.has_header('netinet/ip_icmp.h'))
cdata.set('HAVE_NETINET_IP_VAR_H', cc.has_header('netinet/ip_var.h'))
cdata.set('HAVE_NETINET_TCP_FSM_H', cc.has_header('netinet/tcp_fsm.h'))
cdata.set('HAVE_NETINET_TCP_H', cc.has_header('netinet/tcp.h'))
cdata.set('HAVE_NETINET_TCP_VAR_H', cc.has_header('netinet/tcp_var.h'))
cdata.set('HAVE_NETINET_UDP_H', cc.has_header('netinet/udp.h'))
cdata.set('HAVE_NETINET_UDP_VAR_H', cc.has_header('netinet/udp_var.h'))
cdata.set('HAVE_NETIPX_IPX_H', cc.has_header('netipx/ipx.h'))
cdata.set('HAVE_NET_IF_ARP_H', cc.has_header('net/if_arp.h'))
cdata.set('HAVE_NET_IF_DL_H', cc.has_header('net/if_dl.h'))
cdata.set('HAVE_NET_IF_H', cc.has_header('net/if.h'))
cdata.set('HAVE_NET_IF_TYPES_H', cc.has_header('net/if_types.h'))
cdata.set('HAVE_NET_ROUTE_H', cc.has_header('net/route.h'))
cdata.set('HAVE_OPENCL_OPENCL_H', cc.has_header('OpenCL/opencl.h'))
cdata.set('HAVE_OSS_SYSINFO_NUMAUDIOENGINES',
    cc.has_member('struct oss_sysinfo', 'numaudioengines', prefix : '#include <sys/soundcard.h>')
)
cdata.set('HAVE_PCAP_PCAP_H', cc.has_header('pcap/pcap.h'))
cdata.set('HAVE_PIPE2', cc.has_function('pipe2'))
cdata.set('HAVE_PORT_CREATE', cc.has_function('port_create'))
cdata.set('HAVE_PORT_H', cc.has_header('port.h'))
cdata.set('HAVE_POSIX_FADVISE', cc.has_function('posix_fadvise'))
cdata.set('HAVE_POSIX_FALLOCATE', cc.has_function('posix_fallocate'))
cdata.set('HAVE_PRCTL', cc.has_function('prctl'))
cdata.set('HAVE_PTHREAD_GETTHREADID_NP', cc.has_function('pthread_getthreadid_np'))
cdata.set('HAVE_PTHREAD_NP_H', cc.has_header('pthread_np.h'))
cdata.set('HAVE_PWD_H', cc.has_header('pwd.h'))
cdata.set('HAVE_REQUEST_SENSE', false)
cdata.set('HAVE_RESOLV', false)
cdata.set('HAVE_RESOLV_H', cc.has_header('resolve.h'))
cdata.set('HAVE_RES_GETSERVERS', cc.has_function('res_getservers'))
cdata.set('HAVE_SCHED_GETCPU', cc.has_function('sched_getcpu'))
cdata.set('HAVE_SCHED_H', cc.has_header('sched.h'))
cdata.set('HAVE_SCHED_SETAFFINITY', cc.has_function('sched_setaffinity'))
cdata.set('HAVE_SCHED_YIELD', cc.has_function('sched_yield'))
cdata.set('HAVE_SCSIREQ_T_CMD',
    cc.has_member('scsireq_t', 'cmd', prefix : '#include <sys/scsiio.h>')
)
cdata.set('HAVE_SCSI_SCSI_H', cc.has_header('scsi/scsi.h'))
cdata.set('HAVE_SCSI_SCSI_IOCTL_H', cc.has_header('scsi/scsi_ioctl.h'))
cdata.set('HAVE_SCSI_SG_H', cc.has_header('scsi/sg.h'))
cdata.set('HAVE_SDL_H', cc.has_header('SDL.h'))
cdata.set('HAVE_SETPROCTITLE', cc.has_function('setproctitle'))
cdata.set('HAVE_SETPROGNAME', cc.has_function('setprogname'))
cdata.set('HAVE_SG_IO_HDR_T_INTERFACE_ID',
    cc.has_member('sg_io_hdr_t', 'interface_id', prefix : '#include <scsi/sg.h>')
)
cdata.set('HAVE_SIGINFO_T_SI_FD',
    cc.has_member('siginfo_t', 'si_fd', prefix : '#include <signal.h>')
)
cdata.set('HAVE_SIGPROCMASK', cc.has_function('sigprocmask'))
cdata.set('HAVE_STDINT_H', cc.has_header('stdint.h'))
cdata.set('HAVE_STDIO_H', cc.has_header('stdio.h'))
cdata.set('HAVE_STDLIB_H', cc.has_header('stdlib.h'))
cdata.set('HAVE_STRINGS_H', cc.has_header('strings.h'))
cdata.set('HAVE_STRING_H', cc.has_header('string.h'))
cdata.set('HAVE_STRUCT_ICMP6STAT_ICP6S_ERROR',
    cc.has_member('struct icmp6stat', 'icp6s_error', prefix : '#include <netinet/icmp6.h>')
)
cdata.set('HAVE_STRUCT_ICMPSTAT_ICPS_ERROR',
    cc.has_member('struct icmpstat', 'icps_error', prefix : '#include <netinet/ip_icmp.h>')
)
cdata.set('HAVE_STRUCT_IFREQ_IFR_HWADDR',
    cc.has_member('struct ifreq', 'ifr_hwaddr', prefix : '#include <net/if.h>')
)
cdata.set('HAVE_STRUCT_IN6_PKTINFO_IPI6_ADDR',
    cc.has_member('struct in6_pktinfo', 'ipi6_addr', prefix : '#include <netinet/in.h>')
)
cdata.set('HAVE_STRUCT_IP6STAT_IP6S_TOTAL',
    cc.has_member('struct ip6stat', 'ip6s_total', prefix : '#include <netinet6/ip6_var.h>')
)
cdata.set('HAVE_STRUCT_IPSTAT_IPS_TOTAL',
    cc.has_member('struct ipstat', 'ips_total', prefix : '#include <netinet/ip_var.h>')
)
cdata.set('HAVE_STRUCT_IP_STATS_IPS_TOTAL',
    cc.has_member('struct ip_stats', 'ips_total', prefix : '#include <netinet/ip_var.h>')
)
cdata.set('HAVE_STRUCT_MTGET_MT_BLKNO',
    cc.has_member('struct mtget', 'mt_blkno', prefix : '#include <sys/mtio.h>')
)
cdata.set('HAVE_STRUCT_MTGET_MT_BLKSIZ',
    cc.has_member('struct mtget', 'mt_blksiz', prefix : '#include <sys/mtio.h>')
)
cdata.set('HAVE_STRUCT_MTGET_MT_GSTAT',
    cc.has_member('struct mtget', 'mt_gstat', prefix : '#include <sys/mtio.h>')
)
cdata.set('HAVE_STRUCT_SOCKADDR_IN6_SIN6_SCOPE_ID',
    cc.has_member('struct sockaddr_in6', 'sin6_scope_id', prefix : '#include <netinet/in.h>')
)
cdata.set('HAVE_STRUCT_SOCKADDR_UN_SUN_LEN',
    cc.has_member('struct sockaddr_un', 'sun_len', prefix : '#include <sys/un.h>')
)
cdata.set('HAVE_STRUCT_STAT_ST_ATIM',
    cc.has_member('struct stat', 'st_atim', prefix : '#include <sys/stat.h>')
)
cdata.set('HAVE_STRUCT_STAT_ST_ATIMESPEC',
    cc.has_member('struct stat', 'st_atimespec', prefix : '#include <sys/stat.h>')
)
cdata.set('HAVE_STRUCT_STAT_ST_BIRTHTIM',
    cc.has_member('struct stat', 'st_birthtim', prefix : '#include <sys/stat.h>')
)
cdata.set('HAVE_STRUCT_STAT_ST_BIRTHTIME',
    cc.has_member('struct stat', 'st_birthtime', prefix : '#include <sys/stat.h>')
)
cdata.set('HAVE_STRUCT_STAT_ST_BIRTHTIMESPEC',
    cc.has_member('struct stat', 'st_birthtimespec', prefix : '#include <sys/stat.h>')
)
cdata.set('HAVE_STRUCT_STAT_ST_CTIM',
    cc.has_member('struct stat', 'st_ctim', prefix : '#include <sys/stat.h>')
)
cdata.set('HAVE_STRUCT_STAT_ST_CTIMESPEC',
    cc.has_member('struct stat', 'st_ctimespec', prefix : '#include <sys/stat.h>')
)
cdata.set('HAVE_STRUCT_STAT_ST_MTIM',
    cc.has_member('struct stat', 'st_mtim', prefix : '#include <sys/stat.h>')
)
cdata.set('HAVE_STRUCT_STAT_ST_MTIMESPEC',
    cc.has_member('struct stat', 'st_mtimespec', prefix : '#include <sys/stat.h>')
)
cdata.set('HAVE_STRUCT_STAT___ST_BIRTHTIM',
    cc.has_member('struct stat', '__st_birthtim', prefix : '#include <sys/stat.h>')
)
cdata.set('HAVE_STRUCT_STAT___ST_BIRTHTIME',
    cc.has_member('struct stat', '__st_birthtime', prefix : '#include <sys/stat.h>')
)
cdata.set('HAVE_STRUCT_SYSINFO_MEM_UNIT',
    cc.has_member('struct sysinfo', 'mem_unit', prefix : '#include <sys/sysinfo.h>')
)
cdata.set('HAVE_STRUCT_SYSINFO_TOTALRAM',
    cc.has_member('struct sysinfo', 'totalram', prefix : '#include <sys/sysinfo.h>')
)
cdata.set('HAVE_STRUCT_TCPSTAT_TCPS_CONNATTEMPT',
    cc.has_member('struct tcpstat', 'tcps_connattempt', prefix : '#include <netinet/tcp_var.h>')
)
cdata.set('HAVE_STRUCT_TCP_STATS_TCPS_CONNATTEMPT',
    cc.has_member('struct tcp_stats', 'tcps_connattempt', prefix : '#include <netinet/tcp_var.h>')
)
cdata.set('HAVE_STRUCT_UDPSTAT_UDPS_IPACKETS',
    cc.has_member('struct udpstat', 'udps_ipackets', prefix : '#include <netinet/udp_var.h>')
)
cdata.set('HAVE_STRUCT___RES_STATE__U__EXT_NSCOUNT6',
    cc.has_member('struct __res_state', '_u._ext.nscount6', prefix : '#include <resolv.h>')
)
cdata.set('HAVE_SYNC_ADD_AND_FETCH', 1)
cdata.set('HAVE_SYNC_BOOL_COMPARE_AND_SWAP', 1)
cdata.set('HAVE_SYSCALL_H', cc.has_header('syscall.h'))
cdata.set('HAVE_SYSINFO', cc.has_function('sysinfo'))
cdata.set('HAVE_SYS_ATTR_H', cc.has_header('sys/attr.h'))
cdata.set('HAVE_SYS_AUXV_H', cc.has_header('sys/auxv.h'))
cdata.set('HAVE_SYS_CDIO_H', cc.has_header('sys/cdio.h'))
cdata.set('HAVE_SYS_CONF_H', cc.has_header('sys/conf.h'))
cdata.set('HAVE_SYS_EPOLL_H', cc.has_header('sys/epoll.h'))
cdata.set('HAVE_SYS_EVENT_H', cc.has_header('sys/event.h'))
cdata.set('HAVE_SYS_EXTATTR_H', cc.has_header('sys/extattr.h'))
cdata.set('HAVE_SYS_FILIO_H', cc.has_header('sys/filio.h'))
cdata.set('HAVE_SYS_INOTIFY_H', cc.has_header('sys/inotify.h'))
cdata.set('HAVE_SYS_IPC_H', cc.has_header('sys/ipc.h'))
cdata.set('HAVE_SYS_LINK_H', cc.has_header('sys/link.h'))
cdata.set('HAVE_SYS_MODEM_H', cc.has_header('sys/modem.h'))
cdata.set('HAVE_SYS_MOUNT_H', cc.has_header('sys/mount.h'))
cdata.set('HAVE_SYS_MTIO_H', cc.has_header('sys/mtio.h'))
cdata.set('HAVE_SYS_PARAM_H', cc.has_header('sys/param.h'))
cdata.set('HAVE_SYS_PRCTL_H', cc.has_header('sys/prctl.h'))
cdata.set('HAVE_SYS_PTRACE_H', cc.has_header('sys/ptrace.h'))
cdata.set('HAVE_SYS_QUEUE_H', cc.has_header('sys/queue.h'))
cdata.set('HAVE_SYS_RANDOM_H', cc.has_header('sys/random.h'))
cdata.set('HAVE_SYS_RESOURCE_H', cc.has_header('sys/resource.h'))
cdata.set('HAVE_SYS_SCSIIO_H', cc.has_header('sys/scsiio.h'))
cdata.set('HAVE_SYS_SHM_H', cc.has_header('sys/shm.h'))
cdata.set('HAVE_SYS_SIGNAL_H', cc.has_header('sys/signal.h'))
cdata.set('HAVE_SYS_SOCKETVAR_H', cc.has_header('sys/socketvar.h'))
cdata.set('HAVE_SYS_SOCKIO_H', cc.has_header('sys/sockio.h'))
cdata.set('HAVE_SYS_STATFS_H', cc.has_header('sys/statfs.h'))
cdata.set('HAVE_SYS_STATVFS_H', cc.has_header('sys/statvfs.h'))
cdata.set('HAVE_SYS_STAT_H', cc.has_header('sys/stat.h'))
cdata.set('HAVE_SYS_STRTIO_H', cc.has_header('sys/strtio.h'))
cdata.set('HAVE_SYS_SYSCALL_H', cc.has_header('sys/syscall.h'))
cdata.set('HAVE_SYS_SYSCTL_H', cc.has_header('sys/sysctl.h'))
cdata.set('HAVE_SYS_SYSINFO_H', cc.has_header('sys/sysinfo.h'))
cdata.set('HAVE_SYS_THR_H', cc.has_header('sys/thr.h'))
cdata.set('HAVE_SYS_TIMES_H', cc.has_header('sys/times.h'))
cdata.set('HAVE_SYS_TYPES_H', cc.has_header('sys/types.h'))
cdata.set('HAVE_SYS_UCONTEXT_H', cc.has_header('sys/ucontext.h'))
cdata.set('HAVE_SYS_UIO_H', cc.has_header('sys/uio.h'))
cdata.set('HAVE_SYS_UN_H', cc.has_header('sys/un.h'))
cdata.set('HAVE_SYS_USER_H', cc.has_header('sys/user.h'))
cdata.set('HAVE_SYS_UTSNAME_H', cc.has_header('sys/utsname.h'))
cdata.set('HAVE_SYS_VFS_H', cc.has_header('sys/vfs.h'))
cdata.set('HAVE_SYS_VNODE_H', cc.has_header('sys/vnode.h'))
cdata.set('HAVE_SYS_XATTR_H', cc.has_header('sys/xattr.h'))
cdata.set('HAVE_TCDRAIN', cc.has_function('tcdrain'))
cdata.set('HAVE_THR_KILL2', cc.has_function('thr_kill2'))
cdata.set('HAVE_UDEV',  cc.find_library('udev', required: false).found())
cdata.set('HAVE_UNISTD_H', cc.has_header('unistd.h'))
cdata.set('HAVE_UTIME_H', cc.has_header('utime.h'))
cdata.set('HAVE_VALGRIND_MEMCHECK_H', cc.has_header('valgrind/memcheck.h'))
cdata.set('HAVE_VALGRIND_VALGRIND_H', cc.has_header('valgrind/valgrind.h'))
cdata.set('HAVE_WINE_PRELOADER', false)
cdata.set('HAVE_X11_EXTENSIONS_SHAPE_H', false)
cdata.set('HAVE_X11_EXTENSIONS_XF86VMODE_H', false)
cdata.set('HAVE_X11_EXTENSIONS_XF86VMPROTO_H', false)
cdata.set('HAVE_X11_EXTENSIONS_XFIXES_H', false)
cdata.set('HAVE_X11_EXTENSIONS_XINERAMA_H', false)
cdata.set('HAVE_X11_EXTENSIONS_XINPUT2_H', false)
cdata.set('HAVE_X11_EXTENSIONS_XRANDR_H', false)
cdata.set('HAVE_X11_EXTENSIONS_XRENDER_H', false)
cdata.set('HAVE_X11_EXTENSIONS_XSHM_H', false)
cdata.set('HAVE_XEVENT_XCOOKIE', false)
cdata.set('HAVE_XICCALLBACK_CALLBACK', false)
cdata.set('HAVE_XKBCOMMON_XKBCOMMON_H', false)
cdata.set('HAVE_XKBCOMMON_XKBREGISTRY_H', false)
cdata.set('HAVE_XRENDERCREATELINEARGRADIENT', false)
cdata.set('HAVE_XRENDERSETPICTURETRANSFORM', false)
cdata.set('HAVE_XRRGETPROVIDERRESOURCES', false)
cdata.set('HAVE___BUILTIN_POPCOUNT', false)
cdata.set('HAVE___CLEAR_CACHE', false)
cdata.set('MAJOR_IN_MKDEV',
    cc.has_header_symbol('sys/mkdev.h', 'major') and
    cc.has_header_symbol('sys/mkdev.h', 'minor') and
    cc.has_header_symbol('sys/mkdev.h', 'makedev')
)
cdata.set('MAJOR_IN_SYSMACROS',
    cc.has_header_symbol('sys/sysmacros.h', 'major') and
    cc.has_header_symbol('sys/sysmacros.h', 'minor') and
    cc.has_header_symbol('sys/sysmacros.h', 'makedev')
)
cdata.set('PACKAGE_BUGREPORT', '"wine-devel@winehq.org"')
cdata.set('PACKAGE_NAME', '"Wine"')
cdata.set('PACKAGE_STRING', '"Wine 10.2"')
cdata.set('PACKAGE_TARNAME', '"wine"')
cdata.set('PACKAGE_URL', '"https://www.winehq.org"')
cdata.set('PACKAGE_VERSION', '"10.2"')
cdata.set('SONAME_LIBCUPS', false)
cdata.set('SONAME_LIBDBUS_1', false)
cdata.set('SONAME_LIBEGL', '"libEGL.so.1"')
cdata.set('SONAME_LIBFONTCONFIG', '"libfontconfig.so.1"')
cdata.set('SONAME_LIBFREETYPE', '"libfreetype.so.6"') # dependency(['freetype', 'freetype2'], required : false).name()) # FIXME
cdata.set('SONAME_LIBGL', '"libGL.so.1"')
cdata.set('SONAME_LIBGLESV2', false)
cdata.set('SONAME_LIBGNUTLS', '"libgnutls.so.30"')
cdata.set('SONAME_LIBGSSAPI_KRB5', '"libgssapi_krb5.so.2"')
cdata.set('SONAME_LIBKRB5', '"libkrb5.so.3"')
cdata.set('SONAME_LIBMOLTENVK', false)
cdata.set('SONAME_LIBNETAPI', '"libnetapi.so.1"')
cdata.set('SONAME_LIBODBC', '"libodbc.so"')
cdata.set('SONAME_LIBOSMESA', '"libOSMesa.so.8"')
cdata.set('SONAME_LIBSDL2', '"libSDL2-2.0.so.0"')
cdata.set('SONAME_LIBV4L2', false)
cdata.set('SONAME_LIBVULKAN', '"libvulkan.so.1"')
cdata.set('SONAME_LIBX11', '"libX11.so.6"')
cdata.set('SONAME_LIBXCOMPOSITE', false)
cdata.set('SONAME_LIBXCURSOR', false)
cdata.set('SONAME_LIBXEXT', '"libXext.so.6"')
cdata.set('SONAME_LIBXFIXES', false)
cdata.set('SONAME_LIBXI', false)
cdata.set('SONAME_LIBXINERAMA', false)
cdata.set('SONAME_LIBXRANDR', false)
cdata.set('SONAME_LIBXRENDER', '"libXrender.so.1"')
cdata.set('SONAME_LIBXXF86VM', false)
cdata.set('STDC_HEADERS', 1)
cdata.set('XATTR_ADDITIONAL_OPTIONS', false)
cdata.set('_FILE_OFFSET_BITS', false)
cdata.set('_GNU_SOURCE', 1)
cdata.set('_LARGE_FILES', false)
cdata.set('_TIME_BITS', false)
cdata.set('__MINGW_USE_VC2005_COMPAT', false)

configure_file(input : 'include/config.h.in',
               output : 'config.h',
               configuration : cdata)

config_h_inc = include_directories(['.', 'include/wine'])
incdir = include_directories(['include'])

libm = cc.find_library('m', required: true)
libdl = cc.find_library('dl', required: true)
pthread = cc.find_library('pthread', required: true)
unwind = cc.find_library('unwind', required: true)
freetype2 = dependency('freetype2', version : '>=2', required : true, native : true)
cups = dependency('cups', required : true, native : true)
gnutls = dependency('gnutls', required : true, native : true)

bison_prog = find_program('bison')
gen_bison = generator(bison_prog,
    output : ['@BASENAME@.tab.h', '@BASENAME@.tab.c'],
    arguments : ['@INPUT@', '--defines=@OUTPUT0@', '-o', '@OUTPUT1@'],
)

flex_prog = find_program('flex')
gen_flex = generator(flex_prog,
    output : '@BASENAME@.c',
    arguments : ['-o', '@OUTPUT@', '@INPUT@'],
)

subdir('tools')

gen_idl_h = generator(widl_bin,
    output : '@BASENAME@.h',
    arguments : [
        '-o', '@OUTPUT@',
        '-m64',
        '--nostdinc',
        '-Ldlls/\\*',
        '-I@0@/include'.format(meson.global_source_root()),
        '-I@BUILD_DIR@',
        '-D__WINESRC__',
        '@INPUT@',
    ],
)

gen_idl_c = generator(widl_bin,
    output : '@BASENAME@_c.c',
    arguments : [
        '-o', '@OUTPUT@',
        '-b', 'x86_64-w64-mingw32',
        '--nostdinc',
        '-Ldlls/\\*',
        '-I@0@/include'.format(meson.global_source_root()),
        '-I@BUILD_DIR@',
        '-D__WINESRC__',
        '@INPUT@',
    ],
)

subdir('include')

gen_idl_tres = generator(widl_bin,
    output : '@BASENAME@_t.res',
    arguments : [
        '-o', '@OUTPUT@',
        '-b', 'x86_64-w64-mingw32',
        '--nostdinc',
        '-I@0@/include'.format(meson.global_source_root()),
        '-I@BUILD_DIR@',
        '-D_UCRT', '-D__WINESRC__',
        '@INPUT@',
    ],
)

gen_tres_tlb = generator(winegcc_bin,
    output : '@BASENAME@.tlb',
    arguments : [
        '-o', '@OUTPUT@',
        '--wine-objdir', '@BUILD_DIR@',
        '-b', 'x86_64-w64-mingw32',
        '-Wl,--wine-builtin',
        '-shared',
        '-Wb,--data-only',
        '@INPUT@',
    ],
)

gen_rc_res = generator(wrc_bin,
    output : '@BASENAME@.res',
    arguments : [
        '-u', '-o', '@OUTPUT@',
        '--nostdinc',
	'--po-dir=po',
        '-I@BUILD_DIR@',
        '-I@BUILD_DIR@/../lib@BASENAME@_af_64.a.p',
        '-I@0@/include'.format(meson.global_source_root()),
        '-I@0@/include/msvcrt'.format(meson.global_source_root()),
        '@EXTRA_ARGS@',
	'-D__WINESRC__',
        '@INPUT@',
    ],
)

gen_mc_res = generator(wmc_bin,
    output : '@BASENAME@.res',
    arguments : [
        '-u', '-o', '@OUTPUT@',
	'@INPUT@',
	'--po-dir=po',
    ],
)

gen_mc_pot = generator(wmc_bin,
    output : '@BASENAME@.pot',
    arguments : [
        '-u', '-o', '@OUTPUT@',
	'@INPUT@',
	'--po-dir=po',
    ],
)

subdir('server')
subdir('loader')
subdir('libs')
subdir('dlls')
#subdir('programs')
