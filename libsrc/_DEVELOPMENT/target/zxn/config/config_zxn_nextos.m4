divert(-1)

###############################################################
# NEXTOS USER CONFIGURATION
# rebuild the library if changes are made
#

# NEXTOS API 1.97F
# https://github.com/z88dk/techdocs/blob/master/targets/zx-next/nextos/
# https://github.com/z88dk/techdocs/blob/master/targets/zx-next/nextos/nextos_api.pdf

# NOTE:
#
# For most NextOS functions, the memory map must be set up
# as ROM2 in the bottom 16k, BANK 7 in the top 16k and PAGE 10 in
# mmu2.  This latter setting puts the system variables from BANK 5
# into the 16k-24k area.  System variables BANKM and BANK678 must
# accurately reflect the current banking arrangement.
#
# In addition, layer 2 write-only into
# the lower 16k must be disabled (port 0x123b, IO_LAYER_2_CONFIG)

# NextOS DOTN Commands
# stack location in divmmc ram

define(`__NEXTOS_DOTN_SP_DIVMMC', 0x4000)

# Filesystem Related

define(`__NEXTOS_DOS_VERSION', 0x0103)
define(`__NEXTOS_DOS_OPEN', 0x0106)
define(`__NEXTOS_DOS_CLOSE', 0x0109)
define(`__NEXTOS_DOS_ABANDON', 0x010c)
define(`__NEXTOS_DOS_REF_HEAD', 0x010f)
define(`__NEXTOS_DOS_READ', 0x0112)
define(`__NEXTOS_DOS_WRITE', 0x0115)
define(`__NEXTOS_DOS_BYTE_READ', 0x0118)
define(`__NEXTOS_DOS_BYTE_WRITE', 0x011b)
define(`__NEXTOS_DOS_CATALOG', 0x011e)
define(`__NEXTOS_DOS_FREE_SPACE', 0x0121)
define(`__NEXTOS_DOS_DELETE', 0x0124)
define(`__NEXTOS_DOS_RENAME', 0x0127)
define(`__NEXTOS_DOS_BOOT', 0x012a)
define(`__NEXTOS_DOS_SET_DRIVE', 0x012d)
define(`__NEXTOS_DOS_SET_USER', 0x0130)
define(`__NEXTOS_DOS_GET_POSITION', 0x0133)
define(`__NEXTOS_DOS_SET_POSITION', 0x0136)
define(`__NEXTOS_DOS_GET_EOF', 0x0139)
define(`__NEXTOS_DOS_GET_1346', 0x013c)
define(`__NEXTOS_DOS_SET_1346', 0x013f)
define(`__NEXTOS_DOS_FLUSH', 0x0142)
define(`__NEXTOS_DOS_SET_ACCESS', 0x0145)
define(`__NEXTOS_DOS_SET_ATTRIBUTES', 0x0148)
define(`__NEXTOS_DOS_SET_MESSAGE', 0x014e)

define(`__NEXTOS_IDE_VERSION', 0x00a0)
define(`__NEXTOS_IDE_SWAP_OPEN', 0x00d9)
define(`__NEXTOS_IDE_SWAP_CLOSE', 0x00dc)
define(`__NEXTOS_IDE_SWAP_OUT', 0x00df)
define(`__NEXTOS_IDE_SWAP_IN', 0x00e2)
define(`__NEXTOS_IDE_SWAP_EX', 0x00e5)
define(`__NEXTOS_IDE_SWAP_POS', 0x00e8)
define(`__NEXTOS_IDE_SWAP_MOVE', 0x00eb)
define(`__NEXTOS_IDE_SWAP_RESIZE', 0x00ee)
define(`__NEXTOS_IDE_PARTITION_FIND', 0x00b5)
define(`__NEXTOS_IDE_DOS_MAP', 0x00f1)
define(`__NEXTOS_IDE_DOS_UNMAP', 0x00f4)
define(`__NEXTOS_IDE_DOS_MAPPING', 0x00f7)
define(`__NEXTOS_IDE_SNAPLOAD', 0x00fd)

define(`__NEXTOS_IDE_PATH', 0x01b1)
define(`__nextos_rc_path_change', 0)
define(`__nextos_rc_path_get', 1)
define(`__nextos_rc_path_make', 2)
define(`__nextos_rc_path_delete', 3)

define(`__NEXTOS_IDE_CAPACITY', 0x01b4)
define(`__NEXTOS_IDE_GET_LFN', 0x01b7)

define(`__NEXTOS_IDE_BROWSER', 0x01ba)
define(`__nextos_browsercaps_none', 0)
define(`__nextos_browsercaps_copy', 0x01)
define(`__nextos_browsercaps_rename', 0x02)
define(`__nextos_browsercaps_mkdir', 0x04)
define(`__nextos_browsercaps_erase', 0x08)
define(`__nextos_browsercaps_remount', 0x10)
define(`__nextos_browsercaps_syscfg', 0x80)
define(`__nextos_browsercaps_all', 0x1f)

# Not Filesystem Related

define(`__NEXTOS_IDE_STREAM_OPEN', 0x0056)
define(`__NEXTOS_IDE_STREAM_CLOSE', 0x0059)
define(`__NEXTOS_IDE_STREAM_IN', 0x005c)
define(`__NEXTOS_IDE_STREAM_OUT', 0x005f)
define(`__NEXTOS_IDE_STREAM_PTR', 0x0062)

define(`__NEXTOS_IDE_BANK', 0x01bd)
define(`__nextos_rc_banktype_zx', 0)
define(`__nextos_rc_banktype_mmc', 1)
define(`__nextos_rc_bank_total', 0)
define(`__nextos_rc_bank_alloc', 1)
define(`__nextos_rc_bank_reserve', 2)
define(`__nextos_rc_bank_free', 3)

define(`__NEXTOS_IDE_BASIC', 0x01c0)
define(`__NEXTOS_IDE_WINDOW_LINEIN', 0x01c3)
define(`__NEXTOS_IDE_WINDOW_STRING', 0x01c6)
define(`__NEXTOS_IDE_INTEGER_VAR', 0x01c9)
define(`__NEXTOS_IDE_RTC', 0x01cc)
define(`__NEXTOS_IDE_DRIVER', 0x01cf)

# Legacy - Floppy Drive

define(`__NEXTOS_DOS_REF_XDPB', 0x0151)
define(`__NEXTOS_DOS_MAP_B', 0x0154)
define(`__NEXTOS_DD_INTERFACE', 0x0157)
define(`__NEXTOS_DD_INIT', 0x015a)
define(`__NEXTOS_DD_SETUP', 0x015d)
define(`__NEXTOS_DD_SET_RETRY', 0x0160)
define(`__NEXTOS_DD_READ_SECTOR', 0x0163)
define(`__NEXTOS_DD_WRITE_SECTOR', 0x0166)
define(`__NEXTOS_DD_CHECK_SECTOR', 0x0169)
define(`__NEXTOS_DD_FORMAT', 0x016c)
define(`__NEXTOS_DD_READ_ID', 0x016f)
define(`__NEXTOS_DD_TEST_UNSUITABLE', 0x0172)
define(`__NEXTOS_DD_LOGIN', 0x0175)
define(`__NEXTOS_DD_SEL_FORMAT', 0x0178)
define(`__NEXTOS_DD_ASK_1', 0x017b)
define(`__NEXTOS_DD_DRIVE_STATUS', 0x017e)
define(`__NEXTOS_DD_EQUIPMENT', 0x0181)
define(`__NEXTOS_DD_ENCODE', 0x0184)
define(`__NEXTOS_DD_L_XDPB', 0x0187)
define(`__NEXTOS_DD_L_DPB', 0x018a)
define(`__NEXTOS_DD_L_SEEK', 0x018d)
define(`__NEXTOS_DD_L_READ', 0x0190)
define(`__NEXTOS_DD_L_WRITE', 0x0193)
define(`__NEXTOS_DD_L_ON_MOTOR', 0x0196)
define(`__NEXTOS_DD_T_OFF_MOTOR', 0x0199)
define(`__NEXTOS_DD_L_OFF_MOTOR', 0x019c)

# System Use

define(`__NEXTOS_DOS_INITIALISE', 0x0100)
define(`__NEXTOS_DOS_INITIALIZE', 0x0100)
define(`__NEXTOS_IDE_INTERFACE', 0x00a3)
define(`__NEXTOS_IDE_INIT', 0x00a6)
define(`__NEXTOS_IDE_DRIVE', 0x00a9)
define(`__NEXTOS_IDE_SECTOR_READ', 0x00ac)
define(`__NEXTOS_IDE_SECTOR_WRITE', 0x00af)
define(`__NEXTOS_IDE_PARTITION_NEW', 0x00b8)
define(`__NEXTOS_IDE_PARTITION_INIT', 0x00bb)
define(`__NEXTOS_IDE_PARTITION_READ', 0x00c4)
define(`__NEXTOS_IDE_PARTITION_OPEN', 0x00cd)
define(`__NEXTOS_IDE_PARTITION_CLOSE', 0x00d0)
define(`__NEXTOS_IDE_PARTITIONS', 0x01a5)

# Error Codes - Recoverable Disk Errors

define(`__NEXTOS_RC_READY', 0)
define(`__NEXTOS_RC_WP', 1)
define(`__NEXTOS_RC_SEEK', 2)
define(`__NEXTOS_RC_CRC', 3)
define(`__NEXTOS_RC_NODATA', 4)
define(`__NEXTOS_RC_MARK', 5)
define(`__NEXTOS_RC_UNRECOG', 6)
define(`__NEXTOS_RC_UNKNOWN', 7)
define(`__NEXTOS_RC_DISKCHG', 8)
define(`__NEXTOS_RC_UNSUIT', 9)

# Error Codes - Non-Recoverable Disk Errors

define(`__NEXTOS_RC_BADNAME', 20)
define(`__NEXTOS_RC_BADPARAM', 21)
define(`__NEXTOS_RC_NODRIVE', 22)
define(`__NEXTOS_RC_NOFILE', 23)
define(`__NEXTOS_RC_EXISTS', 24)
define(`__NEXTOS_RC_EOF', 25)
define(`__NEXTOS_RC_DISKFULL', 26)
define(`__NEXTOS_RC_DIRFULL', 27)
define(`__NEXTOS_RC_RO', 28)
define(`__NEXTOS_RC_NUMBER', 29)
define(`__NEXTOS_RC_DENIED', 30)
define(`__NEXTOS_RC_NORENAME', 31)
define(`__NEXTOS_RC_EXTENT', 32)
define(`__NEXTOS_RC_UNCACHED', 33)
define(`__NEXTOS_RC_TOOBIG', 34)
define(`__NEXTOS_RC_NOTBOOT', 35)
define(`__NEXTOS_RC_INUSE', 36)

define(`__NEXTOS_RC_INVPARTITION', 56)
define(`__NEXTOS_RC_PARTEXIST', 57)
define(`__NEXTOS_RC_NOTIMP', 58)
define(`__NEXTOS_RC_PARTOPEN', 59)
define(`__NEXTOS_RC_NOHANDLE', 60)
define(`__NEXTOS_RC_NOTSWAP', 61)
define(`__NEXTOS_RC_MAPPED', 62)
define(`__NEXTOS_RC_NOXDPB', 63)
define(`__NEXTOS_RC_NOSWAP', 64)
define(`__NEXTOS_RC_INVDEVICE', 65)
define(`__NEXTOS_RC_CMDPHASE', 67)
define(`__NEXTOS_RC_DATAPHASE', 68)
define(`__NEXTOS_RC_NOTDIR', 69)

# NextOS ESXDOS API

define(`__ESX_DISK_FILEMAP', 0x85)
define(`__ESX_DISK_STRMSTART', 0x86)
define(`__ESX_DISK_STRMEND', 0x87)

define(`__ESX_M_DOSVERSION', 0x88)
define(`__ESX_M_GETSETDRV', 0x89)
define(`__ESX_M_TAPEIN', 0x8b)
define(`__ESX_M_TAPEOUT', 0x8c)
define(`__ESX_M_GETHANDLE', 0x8d)
define(`__ESX_M_GETDATE', 0x8e)
define(`__ESX_M_EXECCMD', 0x8f)
define(`__ESX_M_DRVAPI', 0x92)
define(`__ESX_M_GETERR', 0x93)
define(`__ESX_M_P3DOS', 0x94)
define(`__ESX_M_ERRH', 0x95)

define(`__ESX_F_OPEN', 0x9a)
define(`__ESX_F_CLOSE', 0x9b)
define(`__ESX_F_SYNC', 0x9c)
define(`__ESX_F_READ', 0x9d)
define(`__ESX_F_WRITE', 0x9e)
define(`__ESX_F_SEEK', 0x9f)
define(`__ESX_F_FGETPOS', 0xa0)
define(`__ESX_F_FSTAT', 0xa1)
define(`__ESX_F_FTRUNCATE', 0xa2)
define(`__ESX_F_OPENDIR', 0xa3)
define(`__ESX_F_READDIR', 0xa4)
define(`__ESX_F_TELLDIR', 0xa5)
define(`__ESX_F_SEEKDIR', 0xa6)
define(`__ESX_F_REWINDDIR', 0xa7)
define(`__ESX_F_GETCWD', 0xa8)
define(`__ESX_F_CHDIR', 0xa9)
define(`__ESX_F_MKDIR', 0xaa)
define(`__ESX_F_RMDIR', 0xab)
define(`__ESX_F_STAT', 0xac)
define(`__ESX_F_UNLINK', 0xad)
define(`__ESX_F_TRUNCATE', 0xae)
define(`__ESX_F_CHMOD', 0xaf)
define(`__ESX_F_RENAME', 0xb0)
define(`__ESX_F_GETFREE', 0xb1)

#
# END OF USER CONFIGURATION
###############################################################

divert(0)

dnl#
dnl# COMPILE TIME CONFIG EXPORT FOR ASSEMBLY LANGUAGE
dnl#

ifdef(`CFG_ASM_PUB',
`
PUBLIC `__NEXTOS_DOS_VERSION'
PUBLIC `__NEXTOS_DOS_OPEN'
PUBLIC `__NEXTOS_DOS_CLOSE'
PUBLIC `__NEXTOS_DOS_ABANDON'
PUBLIC `__NEXTOS_DOS_REF_HEAD'
PUBLIC `__NEXTOS_DOS_READ'
PUBLIC `__NEXTOS_DOS_WRITE'
PUBLIC `__NEXTOS_DOS_BYTE_READ'
PUBLIC `__NEXTOS_DOS_BYTE_WRITE'
PUBLIC `__NEXTOS_DOS_CATALOG'
PUBLIC `__NEXTOS_DOS_FREE_SPACE'
PUBLIC `__NEXTOS_DOS_DELETE'
PUBLIC `__NEXTOS_DOS_RENAME'
PUBLIC `__NEXTOS_DOS_BOOT'
PUBLIC `__NEXTOS_DOS_SET_DRIVE'
PUBLIC `__NEXTOS_DOS_SET_USER'
PUBLIC `__NEXTOS_DOS_GET_POSITION'
PUBLIC `__NEXTOS_DOS_SET_POSITION'
PUBLIC `__NEXTOS_DOS_GET_EOF'
PUBLIC `__NEXTOS_DOS_GET_1346'
PUBLIC `__NEXTOS_DOS_SET_1346'
PUBLIC `__NEXTOS_DOS_FLUSH'
PUBLIC `__NEXTOS_DOS_SET_ACCESS'
PUBLIC `__NEXTOS_DOS_SET_ATTRIBUTES'
PUBLIC `__NEXTOS_DOS_SET_MESSAGE'

PUBLIC `__NEXTOS_IDE_VERSION'
PUBLIC `__NEXTOS_IDE_SWAP_OPEN'
PUBLIC `__NEXTOS_IDE_SWAP_CLOSE'
PUBLIC `__NEXTOS_IDE_SWAP_OUT'
PUBLIC `__NEXTOS_IDE_SWAP_IN'
PUBLIC `__NEXTOS_IDE_SWAP_EX'
PUBLIC `__NEXTOS_IDE_SWAP_POS'
PUBLIC `__NEXTOS_IDE_SWAP_MOVE'
PUBLIC `__NEXTOS_IDE_SWAP_RESIZE'
PUBLIC `__NEXTOS_IDE_PARTITION_FIND'
PUBLIC `__NEXTOS_IDE_DOS_MAP'
PUBLIC `__NEXTOS_IDE_DOS_UNMAP'
PUBLIC `__NEXTOS_IDE_DOS_MAPPING'
PUBLIC `__NEXTOS_IDE_SNAPLOAD'

PUBLIC `__NEXTOS_IDE_PATH'
PUBLIC `__nextos_rc_path_change'
PUBLIC `__nextos_rc_path_get'
PUBLIC `__nextos_rc_path_make'
PUBLIC `__nextos_rc_path_delete'

PUBLIC `__NEXTOS_IDE_CAPACITY'
PUBLIC `__NEXTOS_IDE_GET_LFN'

PUBLIC `__NEXTOS_IDE_BROWSER'
PUBLIC `__nextos_browsercaps_none'
PUBLIC `__nextos_browsercaps_copy'
PUBLIC `__nextos_browsercaps_rename'
PUBLIC `__nextos_browsercaps_mkdir'
PUBLIC `__nextos_browsercaps_erase'
PUBLIC `__nextos_browsercaps_remount'
PUBLIC `__nextos_browsercaps_syscfg'
PUBLIC `__nextos_browsercaps_all'

PUBLIC `__NEXTOS_IDE_STREAM_OPEN'
PUBLIC `__NEXTOS_IDE_STREAM_CLOSE'
PUBLIC `__NEXTOS_IDE_STREAM_IN'
PUBLIC `__NEXTOS_IDE_STREAM_OUT'
PUBLIC `__NEXTOS_IDE_STREAM_PTR'

PUBLIC `__NEXTOS_IDE_BANK'
PUBLIC `__nextos_rc_banktype_zx'
PUBLIC `__nextos_rc_banktype_mmc'
PUBLIC `__nextos_rc_bank_total'
PUBLIC `__nextos_rc_bank_alloc'
PUBLIC `__nextos_rc_bank_reserve'
PUBLIC `__nextos_rc_bank_free'

PUBLIC `__NEXTOS_IDE_BASIC'
PUBLIC `__NEXTOS_IDE_WINDOW_LINEIN'
PUBLIC `__NEXTOS_IDE_WINDOW_STRING'
PUBLIC `__NEXTOS_IDE_INTEGER_VAR'
PUBLIC `__NEXTOS_IDE_RTC'
PUBLIC `__NEXTOS_IDE_DRIVER'

PUBLIC `__NEXTOS_DOS_REF_XDPB'
PUBLIC `__NEXTOS_DOS_MAP_B'
PUBLIC `__NEXTOS_DD_INTERFACE'
PUBLIC `__NEXTOS_DD_INIT'
PUBLIC `__NEXTOS_DD_SETUP'
PUBLIC `__NEXTOS_DD_SET_RETRY'
PUBLIC `__NEXTOS_DD_READ_SECTOR'
PUBLIC `__NEXTOS_DD_WRITE_SECTOR'
PUBLIC `__NEXTOS_DD_CHECK_SECTOR'
PUBLIC `__NEXTOS_DD_FORMAT'
PUBLIC `__NEXTOS_DD_READ_ID'
PUBLIC `__NEXTOS_DD_TEST_UNSUITABLE'
PUBLIC `__NEXTOS_DD_LOGIN'
PUBLIC `__NEXTOS_DD_SEL_FORMAT'
PUBLIC `__NEXTOS_DD_ASK_1'
PUBLIC `__NEXTOS_DD_DRIVE_STATUS'
PUBLIC `__NEXTOS_DD_EQUIPMENT'
PUBLIC `__NEXTOS_DD_ENCODE'
PUBLIC `__NEXTOS_DD_L_XDPB'
PUBLIC `__NEXTOS_DD_L_DPB'
PUBLIC `__NEXTOS_DD_L_SEEK'
PUBLIC `__NEXTOS_DD_L_READ'
PUBLIC `__NEXTOS_DD_L_WRITE'
PUBLIC `__NEXTOS_DD_L_ON_MOTOR'
PUBLIC `__NEXTOS_DD_T_OFF_MOTOR'
PUBLIC `__NEXTOS_DD_L_OFF_MOTOR'

PUBLIC `__NEXTOS_DOS_INITIALISE'
PUBLIC `__NEXTOS_DOS_INITIALIZE'
PUBLIC `__NEXTOS_IDE_INTERFACE'
PUBLIC `__NEXTOS_IDE_INIT'
PUBLIC `__NEXTOS_IDE_DRIVE'
PUBLIC `__NEXTOS_IDE_SECTOR_READ'
PUBLIC `__NEXTOS_IDE_SECTOR_WRITE'
PUBLIC `__NEXTOS_IDE_PARTITION_NEW'
PUBLIC `__NEXTOS_IDE_PARTITION_INIT'
PUBLIC `__NEXTOS_IDE_PARTITION_READ'
PUBLIC `__NEXTOS_IDE_PARTITION_OPEN'
PUBLIC `__NEXTOS_IDE_PARTITION_CLOSE'
PUBLIC `__NEXTOS_IDE_PARTITIONS'

PUBLIC `__NEXTOS_DOTN_SP_DIVMMC'

PUBLIC `__ESX_DISK_FILEMAP'
PUBLIC `__ESX_DISK_STRMSTART'
PUBLIC `__ESX_DISK_STRMEND'

PUBLIC `__ESX_M_DOSVERSION'
PUBLIC `__ESX_M_GETSETDRV'
PUBLIC `__ESX_M_TAPEIN'
PUBLIC `__ESX_M_TAPEOUT'
PUBLIC `__ESX_M_GETHANDLE'
PUBLIC `__ESX_M_GETDATE'
PUBLIC `__ESX_M_EXECCMD'
PUBLIC `__ESX_M_DRVAPI'
PUBLIC `__ESX_M_GETERR'
PUBLIC `__ESX_M_P3DOS'
PUBLIC `__ESX_M_ERRH'

PUBLIC `__ESX_F_OPEN'
PUBLIC `__ESX_F_CLOSE'
PUBLIC `__ESX_F_SYNC'
PUBLIC `__ESX_F_READ'
PUBLIC `__ESX_F_WRITE'
PUBLIC `__ESX_F_SEEK'
PUBLIC `__ESX_F_FGETPOS'
PUBLIC `__ESX_F_FSTAT'
PUBLIC `__ESX_F_FTRUNCATE'
PUBLIC `__ESX_F_OPENDIR'
PUBLIC `__ESX_F_READDIR'
PUBLIC `__ESX_F_TELLDIR'
PUBLIC `__ESX_F_SEEKDIR'
PUBLIC `__ESX_F_REWINDDIR'
PUBLIC `__ESX_F_GETCWD'
PUBLIC `__ESX_F_CHDIR'
PUBLIC `__ESX_F_MKDIR'
PUBLIC `__ESX_F_RMDIR'
PUBLIC `__ESX_F_STAT'
PUBLIC `__ESX_F_UNLINK'
PUBLIC `__ESX_F_TRUNCATE'
PUBLIC `__ESX_F_CHMOD'
PUBLIC `__ESX_F_RENAME'
PUBLIC `__ESX_F_GETFREE'

PUBLIC `__NEXTOS_RC_READY'
PUBLIC `__NEXTOS_RC_WP'
PUBLIC `__NEXTOS_RC_SEEK'
PUBLIC `__NEXTOS_RC_CRC'
PUBLIC `__NEXTOS_RC_NODATA'
PUBLIC `__NEXTOS_RC_MARK'
PUBLIC `__NEXTOS_RC_UNRECOG'
PUBLIC `__NEXTOS_RC_UNKNOWN'
PUBLIC `__NEXTOS_RC_DISKCHG'
PUBLIC `__NEXTOS_RC_UNSUIT'

PUBLIC `__NEXTOS_RC_BADNAME'
PUBLIC `__NEXTOS_RC_BADPARAM'
PUBLIC `__NEXTOS_RC_NODRIVE'
PUBLIC `__NEXTOS_RC_NOFILE'
PUBLIC `__NEXTOS_RC_EXISTS'
PUBLIC `__NEXTOS_RC_EOF'
PUBLIC `__NEXTOS_RC_DISKFULL'
PUBLIC `__NEXTOS_RC_DIRFULL'
PUBLIC `__NEXTOS_RC_RO'
PUBLIC `__NEXTOS_RC_NUMBER'
PUBLIC `__NEXTOS_RC_DENIED'
PUBLIC `__NEXTOS_RC_NORENAME'
PUBLIC `__NEXTOS_RC_EXTENT'
PUBLIC `__NEXTOS_RC_UNCACHED'
PUBLIC `__NEXTOS_RC_TOOBIG'
PUBLIC `__NEXTOS_RC_NOTBOOT'
PUBLIC `__NEXTOS_RC_INUSE'

PUBLIC `__NEXTOS_RC_INVPARTITION'
PUBLIC `__NEXTOS_RC_PARTEXIST'
PUBLIC `__NEXTOS_RC_NOTIMP'
PUBLIC `__NEXTOS_RC_PARTOPEN'
PUBLIC `__NEXTOS_RC_NOHANDLE'
PUBLIC `__NEXTOS_RC_NOTSWAP'
PUBLIC `__NEXTOS_RC_MAPPED'
PUBLIC `__NEXTOS_RC_NOXDPB'
PUBLIC `__NEXTOS_RC_NOSWAP'
PUBLIC `__NEXTOS_RC_INVDEVICE'
PUBLIC `__NEXTOS_RC_CMDPHASE'
PUBLIC `__NEXTOS_RC_DATAPHASE'
PUBLIC `__NEXTOS_RC_NOTDIR'
')

dnl#
dnl# LIBRARY BUILD TIME CONFIG FOR ASSEMBLY LANGUAGE
dnl#

ifdef(`CFG_ASM_DEF',
`
defc `__NEXTOS_DOS_VERSION' = __NEXTOS_DOS_VERSION
defc `__NEXTOS_DOS_OPEN' = __NEXTOS_DOS_OPEN
defc `__NEXTOS_DOS_CLOSE' = __NEXTOS_DOS_CLOSE
defc `__NEXTOS_DOS_ABANDON' = __NEXTOS_DOS_ABANDON
defc `__NEXTOS_DOS_REF_HEAD' = __NEXTOS_DOS_REF_HEAD
defc `__NEXTOS_DOS_READ' = __NEXTOS_DOS_READ
defc `__NEXTOS_DOS_WRITE' = __NEXTOS_DOS_WRITE
defc `__NEXTOS_DOS_BYTE_READ' = __NEXTOS_DOS_BYTE_READ
defc `__NEXTOS_DOS_BYTE_WRITE' = __NEXTOS_DOS_BYTE_WRITE
defc `__NEXTOS_DOS_CATALOG' = __NEXTOS_DOS_CATALOG
defc `__NEXTOS_DOS_FREE_SPACE' = __NEXTOS_DOS_FREE_SPACE
defc `__NEXTOS_DOS_DELETE' = __NEXTOS_DOS_DELETE
defc `__NEXTOS_DOS_RENAME' = __NEXTOS_DOS_RENAME
defc `__NEXTOS_DOS_BOOT' = __NEXTOS_DOS_BOOT
defc `__NEXTOS_DOS_SET_DRIVE' = __NEXTOS_DOS_SET_DRIVE
defc `__NEXTOS_DOS_SET_USER' = __NEXTOS_DOS_SET_USER
defc `__NEXTOS_DOS_GET_POSITION' = __NEXTOS_DOS_GET_POSITION
defc `__NEXTOS_DOS_SET_POSITION' = __NEXTOS_DOS_SET_POSITION
defc `__NEXTOS_DOS_GET_EOF' = __NEXTOS_DOS_GET_EOF
defc `__NEXTOS_DOS_GET_1346' = __NEXTOS_DOS_GET_1346
defc `__NEXTOS_DOS_SET_1346' = __NEXTOS_DOS_SET_1346
defc `__NEXTOS_DOS_FLUSH' = __NEXTOS_DOS_FLUSH
defc `__NEXTOS_DOS_SET_ACCESS' = __NEXTOS_DOS_SET_ACCESS
defc `__NEXTOS_DOS_SET_ATTRIBUTES' = __NEXTOS_DOS_SET_ATTRIBUTES
defc `__NEXTOS_DOS_SET_MESSAGE' = __NEXTOS_DOS_SET_MESSAGE

defc `__NEXTOS_IDE_VERSION' = __NEXTOS_IDE_VERSION
defc `__NEXTOS_IDE_SWAP_OPEN' = __NEXTOS_IDE_SWAP_OPEN
defc `__NEXTOS_IDE_SWAP_CLOSE' = __NEXTOS_IDE_SWAP_CLOSE
defc `__NEXTOS_IDE_SWAP_OUT' = __NEXTOS_IDE_SWAP_OUT
defc `__NEXTOS_IDE_SWAP_IN' = __NEXTOS_IDE_SWAP_IN
defc `__NEXTOS_IDE_SWAP_EX' = __NEXTOS_IDE_SWAP_EX
defc `__NEXTOS_IDE_SWAP_POS' = __NEXTOS_IDE_SWAP_POS
defc `__NEXTOS_IDE_SWAP_MOVE' = __NEXTOS_IDE_SWAP_MOVE
defc `__NEXTOS_IDE_SWAP_RESIZE' = __NEXTOS_IDE_SWAP_RESIZE
defc `__NEXTOS_IDE_PARTITION_FIND' = __NEXTOS_IDE_PARTITION_FIND
defc `__NEXTOS_IDE_DOS_MAP' = __NEXTOS_IDE_DOS_MAP
defc `__NEXTOS_IDE_DOS_UNMAP' = __NEXTOS_IDE_DOS_UNMAP
defc `__NEXTOS_IDE_DOS_MAPPING' = __NEXTOS_IDE_DOS_MAPPING
defc `__NEXTOS_IDE_SNAPLOAD' = __NEXTOS_IDE_SNAPLOAD

defc `__NEXTOS_IDE_PATH' = __NEXTOS_IDE_PATH
defc `__nextos_rc_path_change' = __nextos_rc_path_change
defc `__nextos_rc_path_get' = __nextos_rc_path_get
defc `__nextos_rc_path_make' = __nextos_rc_path_make
defc `__nextos_rc_path_delete' = __nextos_rc_path_delete

defc `__NEXTOS_IDE_CAPACITY' = __NEXTOS_IDE_CAPACITY
defc `__NEXTOS_IDE_GET_LFN' = __NEXTOS_IDE_GET_LFN

defc `__NEXTOS_IDE_BROWSER' = __NEXTOS_IDE_BROWSER
defc `__nextos_browsercaps_none' = __nextos_browsercaps_none
defc `__nextos_browsercaps_copy' = __nextos_browsercaps_copy
defc `__nextos_browsercaps_rename' = __nextos_browsercaps_rename
defc `__nextos_browsercaps_mkdir' = __nextos_browsercaps_mkdir
defc `__nextos_browsercaps_erase' = __nextos_browsercaps_erase
defc `__nextos_browsercaps_remount' = __nextos_browsercaps_remount
defc `__nextos_browsercaps_syscfg' = __nextos_browsercaps_syscfg
defc `__nextos_browsercaps_all' = __nextos_browsercaps_all

defc `__NEXTOS_IDE_STREAM_OPEN' = __NEXTOS_IDE_STREAM_OPEN
defc `__NEXTOS_IDE_STREAM_CLOSE' = __NEXTOS_IDE_STREAM_CLOSE
defc `__NEXTOS_IDE_STREAM_IN' = __NEXTOS_IDE_STREAM_IN
defc `__NEXTOS_IDE_STREAM_OUT' = __NEXTOS_IDE_STREAM_OUT
defc `__NEXTOS_IDE_STREAM_PTR' = __NEXTOS_IDE_STREAM_PTR

defc `__NEXTOS_IDE_BANK' = __NEXTOS_IDE_BANK
defc `__nextos_rc_banktype_zx' = __nextos_rc_banktype_zx
defc `__nextos_rc_banktype_mmc' = __nextos_rc_banktype_mmc
defc `__nextos_rc_bank_total' = __nextos_rc_bank_total
defc `__nextos_rc_bank_alloc' = __nextos_rc_bank_alloc
defc `__nextos_rc_bank_reserve' = __nextos_rc_bank_reserve
defc `__nextos_rc_bank_free' = __nextos_rc_bank_free

defc `__NEXTOS_IDE_BASIC' = __NEXTOS_IDE_BASIC
defc `__NEXTOS_IDE_WINDOW_LINEIN' = __NEXTOS_IDE_WINDOW_LINEIN
defc `__NEXTOS_IDE_WINDOW_STRING' = __NEXTOS_IDE_WINDOW_STRING
defc `__NEXTOS_IDE_INTEGER_VAR' = __NEXTOS_IDE_INTEGER_VAR
defc `__NEXTOS_IDE_RTC' = __NEXTOS_IDE_RTC
defc `__NEXTOS_IDE_DRIVER' = __NEXTOS_IDE_DRIVER

defc `__NEXTOS_DOS_REF_XDPB' = __NEXTOS_DOS_REF_XDPB
defc `__NEXTOS_DOS_MAP_B' = __NEXTOS_DOS_MAP_B
defc `__NEXTOS_DD_INTERFACE' = __NEXTOS_DD_INTERFACE
defc `__NEXTOS_DD_INIT' = __NEXTOS_DD_INIT
defc `__NEXTOS_DD_SETUP' = __NEXTOS_DD_SETUP
defc `__NEXTOS_DD_SET_RETRY' = __NEXTOS_DD_SET_RETRY
defc `__NEXTOS_DD_READ_SECTOR' = __NEXTOS_DD_READ_SECTOR
defc `__NEXTOS_DD_WRITE_SECTOR' = __NEXTOS_DD_WRITE_SECTOR
defc `__NEXTOS_DD_CHECK_SECTOR' = __NEXTOS_DD_CHECK_SECTOR
defc `__NEXTOS_DD_FORMAT' = __NEXTOS_DD_FORMAT
defc `__NEXTOS_DD_READ_ID' = __NEXTOS_DD_READ_ID
defc `__NEXTOS_DD_TEST_UNSUITABLE' = __NEXTOS_DD_TEST_UNSUITABLE
defc `__NEXTOS_DD_LOGIN' = __NEXTOS_DD_LOGIN
defc `__NEXTOS_DD_SEL_FORMAT' = __NEXTOS_DD_SEL_FORMAT
defc `__NEXTOS_DD_ASK_1' = __NEXTOS_DD_ASK_1
defc `__NEXTOS_DD_DRIVE_STATUS' = __NEXTOS_DD_DRIVE_STATUS
defc `__NEXTOS_DD_EQUIPMENT' = __NEXTOS_DD_EQUIPMENT
defc `__NEXTOS_DD_ENCODE' = __NEXTOS_DD_ENCODE
defc `__NEXTOS_DD_L_XDPB' = __NEXTOS_DD_L_XDPB
defc `__NEXTOS_DD_L_DPB' = __NEXTOS_DD_L_DPB
defc `__NEXTOS_DD_L_SEEK' = __NEXTOS_DD_L_SEEK
defc `__NEXTOS_DD_L_READ' = __NEXTOS_DD_L_READ
defc `__NEXTOS_DD_L_WRITE' = __NEXTOS_DD_L_WRITE
defc `__NEXTOS_DD_L_ON_MOTOR' = __NEXTOS_DD_L_ON_MOTOR
defc `__NEXTOS_DD_T_OFF_MOTOR' = __NEXTOS_DD_T_OFF_MOTOR
defc `__NEXTOS_DD_L_OFF_MOTOR' = __NEXTOS_DD_L_OFF_MOTOR

defc `__NEXTOS_DOS_INITIALISE' = __NEXTOS_DOS_INITIALISE
defc `__NEXTOS_DOS_INITIALIZE' = __NEXTOS_DOS_INITIALIZE
defc `__NEXTOS_IDE_INTERFACE' = __NEXTOS_IDE_INTERFACE
defc `__NEXTOS_IDE_INIT' = __NEXTOS_IDE_INIT
defc `__NEXTOS_IDE_DRIVE' = __NEXTOS_IDE_DRIVE
defc `__NEXTOS_IDE_SECTOR_READ' = __NEXTOS_IDE_SECTOR_READ
defc `__NEXTOS_IDE_SECTOR_WRITE' = __NEXTOS_IDE_SECTOR_WRITE
defc `__NEXTOS_IDE_PARTITION_NEW' = __NEXTOS_IDE_PARTITION_NEW
defc `__NEXTOS_IDE_PARTITION_INIT' = __NEXTOS_IDE_PARTITION_INIT
defc `__NEXTOS_IDE_PARTITION_READ' = __NEXTOS_IDE_PARTITION_READ
defc `__NEXTOS_IDE_PARTITION_OPEN' = __NEXTOS_IDE_PARTITION_OPEN
defc `__NEXTOS_IDE_PARTITION_CLOSE' = __NEXTOS_IDE_PARTITION_CLOSE
defc `__NEXTOS_IDE_PARTITIONS' = __NEXTOS_IDE_PARTITIONS

defc `__NEXTOS_DOTN_SP_DIVMMC' = __NEXTOS_DOTN_SP_DIVMMC

defc `__ESX_DISK_FILEMAP' = __ESX_DISK_FILEMAP
defc `__ESX_DISK_STRMSTART' = __ESX_DISK_STRMSTART
defc `__ESX_DISK_STRMEND' = __ESX_DISK_STRMEND

defc `__ESX_M_DOSVERSION' = __ESX_M_DOSVERSION
defc `__ESX_M_GETSETDRV' = __ESX_M_GETSETDRV
defc `__ESX_M_TAPEIN' = __ESX_M_TAPEIN
defc `__ESX_M_TAPEOUT' = __ESX_M_TAPEOUT
defc `__ESX_M_GETHANDLE' = __ESX_M_GETHANDLE
defc `__ESX_M_GETDATE' = __ESX_M_GETDATE
defc `__ESX_M_EXECCMD' = __ESX_M_EXECCMD
defc `__ESX_M_DRVAPI' = __ESX_M_DRVAPI
defc `__ESX_M_GETERR' = __ESX_M_GETERR
defc `__ESX_M_P3DOS' = __ESX_M_P3DOS
defc `__ESX_M_ERRH' = __ESX_M_ERRH

defc `__ESX_F_OPEN' = __ESX_F_OPEN
defc `__ESX_F_CLOSE' = __ESX_F_CLOSE
defc `__ESX_F_SYNC' = __ESX_F_SYNC
defc `__ESX_F_READ' = __ESX_F_READ
defc `__ESX_F_WRITE' = __ESX_F_WRITE
defc `__ESX_F_SEEK' = __ESX_F_SEEK
defc `__ESX_F_FGETPOS' = __ESX_F_FGETPOS
defc `__ESX_F_FSTAT' = __ESX_F_FSTAT
defc `__ESX_F_FTRUNCATE' = __ESX_F_FTRUNCATE
defc `__ESX_F_OPENDIR' = __ESX_F_OPENDIR
defc `__ESX_F_READDIR' = __ESX_F_READDIR
defc `__ESX_F_TELLDIR' = __ESX_F_TELLDIR
defc `__ESX_F_SEEKDIR' = __ESX_F_SEEKDIR
defc `__ESX_F_REWINDDIR' = __ESX_F_REWINDDIR
defc `__ESX_F_GETCWD' = __ESX_F_GETCWD
defc `__ESX_F_CHDIR' = __ESX_F_CHDIR
defc `__ESX_F_MKDIR' = __ESX_F_MKDIR
defc `__ESX_F_RMDIR' = __ESX_F_RMDIR
defc `__ESX_F_STAT' = __ESX_F_STAT
defc `__ESX_F_UNLINK' = __ESX_F_UNLINK
defc `__ESX_F_TRUNCATE' = __ESX_F_TRUNCATE
defc `__ESX_F_CHMOD' = __ESX_F_CHMOD
defc `__ESX_F_RENAME' = __ESX_F_RENAME
defc `__ESX_F_GETFREE' = __ESX_F_GETFREE

defc `__NEXTOS_RC_READY' = __NEXTOS_RC_READY
defc `__NEXTOS_RC_WP' = __NEXTOS_RC_WP
defc `__NEXTOS_RC_SEEK' = __NEXTOS_RC_SEEK
defc `__NEXTOS_RC_CRC' = __NEXTOS_RC_CRC
defc `__NEXTOS_RC_NODATA' = __NEXTOS_RC_NODATA
defc `__NEXTOS_RC_MARK' = __NEXTOS_RC_MARK
defc `__NEXTOS_RC_UNRECOG' = __NEXTOS_RC_UNRECOG
defc `__NEXTOS_RC_UNKNOWN' = __NEXTOS_RC_UNKNOWN
defc `__NEXTOS_RC_DISKCHG' = __NEXTOS_RC_DISKCHG
defc `__NEXTOS_RC_UNSUIT' = __NEXTOS_RC_UNSUIT

defc `__NEXTOS_RC_BADNAME' = __NEXTOS_RC_BADNAME
defc `__NEXTOS_RC_BADPARAM' = __NEXTOS_RC_BADPARAM
defc `__NEXTOS_RC_NODRIVE' = __NEXTOS_RC_NODRIVE
defc `__NEXTOS_RC_NOFILE' = __NEXTOS_RC_NOFILE
defc `__NEXTOS_RC_EXISTS' = __NEXTOS_RC_EXISTS
defc `__NEXTOS_RC_EOF' = __NEXTOS_RC_EOF
defc `__NEXTOS_RC_DISKFULL' = __NEXTOS_RC_DISKFULL
defc `__NEXTOS_RC_DIRFULL' = __NEXTOS_RC_DIRFULL
defc `__NEXTOS_RC_RO' = __NEXTOS_RC_RO
defc `__NEXTOS_RC_NUMBER' = __NEXTOS_RC_NUMBER
defc `__NEXTOS_RC_DENIED' = __NEXTOS_RC_DENIED
defc `__NEXTOS_RC_NORENAME' = __NEXTOS_RC_NORENAME
defc `__NEXTOS_RC_EXTENT' = __NEXTOS_RC_EXTENT
defc `__NEXTOS_RC_UNCACHED' = __NEXTOS_RC_UNCACHED
defc `__NEXTOS_RC_TOOBIG' = __NEXTOS_RC_TOOBIG
defc `__NEXTOS_RC_NOTBOOT' = __NEXTOS_RC_NOTBOOT
defc `__NEXTOS_RC_INUSE' = __NEXTOS_RC_INUSE

defc `__NEXTOS_RC_INVPARTITION' = __NEXTOS_RC_INVPARTITION
defc `__NEXTOS_RC_PARTEXIST' = __NEXTOS_RC_PARTEXIST
defc `__NEXTOS_RC_NOTIMP' = __NEXTOS_RC_NOTIMP
defc `__NEXTOS_RC_PARTOPEN' = __NEXTOS_RC_PARTOPEN
defc `__NEXTOS_RC_NOHANDLE' = __NEXTOS_RC_NOHANDLE
defc `__NEXTOS_RC_NOTSWAP' = __NEXTOS_RC_NOTSWAP
defc `__NEXTOS_RC_MAPPED' = __NEXTOS_RC_MAPPED
defc `__NEXTOS_RC_NOXDPB' = __NEXTOS_RC_NOXDPB
defc `__NEXTOS_RC_NOSWAP' = __NEXTOS_RC_NOSWAP
defc `__NEXTOS_RC_INVDEVICE' = __NEXTOS_RC_INVDEVICE
defc `__NEXTOS_RC_CMDPHASE' = __NEXTOS_RC_CMDPHASE
defc `__NEXTOS_RC_DATAPHASE' = __NEXTOS_RC_DATAPHASE
defc `__NEXTOS_RC_NOTDIR' = __NEXTOS_RC_NOTDIR
')

dnl#
dnl# COMPILE TIME CONFIG EXPORT FOR C
dnl#

ifdef(`CFG_C_DEF',
`
`#define' `__NEXTOS_DOS_VERSION'  __NEXTOS_DOS_VERSION
`#define' `__NEXTOS_DOS_OPEN'  __NEXTOS_DOS_OPEN
`#define' `__NEXTOS_DOS_CLOSE'  __NEXTOS_DOS_CLOSE
`#define' `__NEXTOS_DOS_ABANDON'  __NEXTOS_DOS_ABANDON
`#define' `__NEXTOS_DOS_REF_HEAD'  __NEXTOS_DOS_REF_HEAD
`#define' `__NEXTOS_DOS_READ'  __NEXTOS_DOS_READ
`#define' `__NEXTOS_DOS_WRITE'  __NEXTOS_DOS_WRITE
`#define' `__NEXTOS_DOS_BYTE_READ'  __NEXTOS_DOS_BYTE_READ
`#define' `__NEXTOS_DOS_BYTE_WRITE'  __NEXTOS_DOS_BYTE_WRITE
`#define' `__NEXTOS_DOS_CATALOG'  __NEXTOS_DOS_CATALOG
`#define' `__NEXTOS_DOS_FREE_SPACE'  __NEXTOS_DOS_FREE_SPACE
`#define' `__NEXTOS_DOS_DELETE'  __NEXTOS_DOS_DELETE
`#define' `__NEXTOS_DOS_RENAME'  __NEXTOS_DOS_RENAME
`#define' `__NEXTOS_DOS_BOOT'  __NEXTOS_DOS_BOOT
`#define' `__NEXTOS_DOS_SET_DRIVE'  __NEXTOS_DOS_SET_DRIVE
`#define' `__NEXTOS_DOS_SET_USER'  __NEXTOS_DOS_SET_USER
`#define' `__NEXTOS_DOS_GET_POSITION'  __NEXTOS_DOS_GET_POSITION
`#define' `__NEXTOS_DOS_SET_POSITION'  __NEXTOS_DOS_SET_POSITION
`#define' `__NEXTOS_DOS_GET_EOF'  __NEXTOS_DOS_GET_EOF
`#define' `__NEXTOS_DOS_GET_1346'  __NEXTOS_DOS_GET_1346
`#define' `__NEXTOS_DOS_SET_1346'  __NEXTOS_DOS_SET_1346
`#define' `__NEXTOS_DOS_FLUSH'  __NEXTOS_DOS_FLUSH
`#define' `__NEXTOS_DOS_SET_ACCESS'  __NEXTOS_DOS_SET_ACCESS
`#define' `__NEXTOS_DOS_SET_ATTRIBUTES'  __NEXTOS_DOS_SET_ATTRIBUTES
`#define' `__NEXTOS_DOS_SET_MESSAGE'  __NEXTOS_DOS_SET_MESSAGE

`#define' `__NEXTOS_IDE_VERSION'  __NEXTOS_IDE_VERSION
`#define' `__NEXTOS_IDE_SWAP_OPEN'  __NEXTOS_IDE_SWAP_OPEN
`#define' `__NEXTOS_IDE_SWAP_CLOSE'  __NEXTOS_IDE_SWAP_CLOSE
`#define' `__NEXTOS_IDE_SWAP_OUT'  __NEXTOS_IDE_SWAP_OUT
`#define' `__NEXTOS_IDE_SWAP_IN'  __NEXTOS_IDE_SWAP_IN
`#define' `__NEXTOS_IDE_SWAP_EX'  __NEXTOS_IDE_SWAP_EX
`#define' `__NEXTOS_IDE_SWAP_POS'  __NEXTOS_IDE_SWAP_POS
`#define' `__NEXTOS_IDE_SWAP_MOVE'  __NEXTOS_IDE_SWAP_MOVE
`#define' `__NEXTOS_IDE_SWAP_RESIZE'  __NEXTOS_IDE_SWAP_RESIZE
`#define' `__NEXTOS_IDE_PARTITION_FIND'  __NEXTOS_IDE_PARTITION_FIND
`#define' `__NEXTOS_IDE_DOS_MAP'  __NEXTOS_IDE_DOS_MAP
`#define' `__NEXTOS_IDE_DOS_UNMAP'  __NEXTOS_IDE_DOS_UNMAP
`#define' `__NEXTOS_IDE_DOS_MAPPING'  __NEXTOS_IDE_DOS_MAPPING
`#define' `__NEXTOS_IDE_SNAPLOAD'  __NEXTOS_IDE_SNAPLOAD

`#define' `__NEXTOS_IDE_PATH'  __NEXTOS_IDE_PATH
`#define' `__nextos_rc_path_change'  __nextos_rc_path_change
`#define' `__nextos_rc_path_get'  __nextos_rc_path_get
`#define' `__nextos_rc_path_make'  __nextos_rc_path_make
`#define' `__nextos_rc_path_delete'  __nextos_rc_path_delete

`#define' `__NEXTOS_IDE_CAPACITY'  __NEXTOS_IDE_CAPACITY
`#define' `__NEXTOS_IDE_GET_LFN'  __NEXTOS_IDE_GET_LFN

`#define' `__NEXTOS_IDE_BROWSER'  __NEXTOS_IDE_BROWSER
`#define' `__nextos_browsercaps_none'  __nextos_browsercaps_none
`#define' `__nextos_browsercaps_copy'  __nextos_browsercaps_copy
`#define' `__nextos_browsercaps_rename'  __nextos_browsercaps_rename
`#define' `__nextos_browsercaps_mkdir'  __nextos_browsercaps_mkdir
`#define' `__nextos_browsercaps_erase'  __nextos_browsercaps_erase
`#define' `__nextos_browsercaps_remount'  __nextos_browsercaps_remount
`#define' `__nextos_browsercaps_syscfg'  __nextos_browsercaps_syscfg
`#define' `__nextos_browsercaps_all'  __nextos_browsercaps_all

`#define' `__NEXTOS_IDE_STREAM_OPEN'  __NEXTOS_IDE_STREAM_OPEN
`#define' `__NEXTOS_IDE_STREAM_CLOSE'  __NEXTOS_IDE_STREAM_CLOSE
`#define' `__NEXTOS_IDE_STREAM_IN'  __NEXTOS_IDE_STREAM_IN
`#define' `__NEXTOS_IDE_STREAM_OUT'  __NEXTOS_IDE_STREAM_OUT
`#define' `__NEXTOS_IDE_STREAM_PTR'  __NEXTOS_IDE_STREAM_PTR

`#define' `__NEXTOS_IDE_BANK'  __NEXTOS_IDE_BANK
`#define' `__nextos_rc_banktype_zx'  __nextos_rc_banktype_zx
`#define' `__nextos_rc_banktype_mmc'  __nextos_rc_banktype_mmc
`#define' `__nextos_rc_bank_total'  __nextos_rc_bank_total
`#define' `__nextos_rc_bank_alloc'  __nextos_rc_bank_alloc
`#define' `__nextos_rc_bank_reserve'  __nextos_rc_bank_reserve
`#define' `__nextos_rc_bank_free'  __nextos_rc_bank_free

`#define' `__NEXTOS_IDE_BASIC'  __NEXTOS_IDE_BASIC
`#define' `__NEXTOS_IDE_WINDOW_LINEIN'  __NEXTOS_IDE_WINDOW_LINEIN
`#define' `__NEXTOS_IDE_WINDOW_STRING'  __NEXTOS_IDE_WINDOW_STRING
`#define' `__NEXTOS_IDE_INTEGER_VAR'  __NEXTOS_IDE_INTEGER_VAR
`#define' `__NEXTOS_IDE_RTC'  __NEXTOS_IDE_RTC
`#define' `__NEXTOS_IDE_DRIVER'  __NEXTOS_IDE_DRIVER

`#define' `__NEXTOS_DOS_REF_XDPB'  __NEXTOS_DOS_REF_XDPB
`#define' `__NEXTOS_DOS_MAP_B'  __NEXTOS_DOS_MAP_B
`#define' `__NEXTOS_DD_INTERFACE'  __NEXTOS_DD_INTERFACE
`#define' `__NEXTOS_DD_INIT'  __NEXTOS_DD_INIT
`#define' `__NEXTOS_DD_SETUP'  __NEXTOS_DD_SETUP
`#define' `__NEXTOS_DD_SET_RETRY'  __NEXTOS_DD_SET_RETRY
`#define' `__NEXTOS_DD_READ_SECTOR'  __NEXTOS_DD_READ_SECTOR
`#define' `__NEXTOS_DD_WRITE_SECTOR'  __NEXTOS_DD_WRITE_SECTOR
`#define' `__NEXTOS_DD_CHECK_SECTOR'  __NEXTOS_DD_CHECK_SECTOR
`#define' `__NEXTOS_DD_FORMAT'  __NEXTOS_DD_FORMAT
`#define' `__NEXTOS_DD_READ_ID'  __NEXTOS_DD_READ_ID
`#define' `__NEXTOS_DD_TEST_UNSUITABLE'  __NEXTOS_DD_TEST_UNSUITABLE
`#define' `__NEXTOS_DD_LOGIN'  __NEXTOS_DD_LOGIN
`#define' `__NEXTOS_DD_SEL_FORMAT'  __NEXTOS_DD_SEL_FORMAT
`#define' `__NEXTOS_DD_ASK_1'  __NEXTOS_DD_ASK_1
`#define' `__NEXTOS_DD_DRIVE_STATUS'  __NEXTOS_DD_DRIVE_STATUS
`#define' `__NEXTOS_DD_EQUIPMENT'  __NEXTOS_DD_EQUIPMENT
`#define' `__NEXTOS_DD_ENCODE'  __NEXTOS_DD_ENCODE
`#define' `__NEXTOS_DD_L_XDPB'  __NEXTOS_DD_L_XDPB
`#define' `__NEXTOS_DD_L_DPB'  __NEXTOS_DD_L_DPB
`#define' `__NEXTOS_DD_L_SEEK'  __NEXTOS_DD_L_SEEK
`#define' `__NEXTOS_DD_L_READ'  __NEXTOS_DD_L_READ
`#define' `__NEXTOS_DD_L_WRITE'  __NEXTOS_DD_L_WRITE
`#define' `__NEXTOS_DD_L_ON_MOTOR'  __NEXTOS_DD_L_ON_MOTOR
`#define' `__NEXTOS_DD_T_OFF_MOTOR'  __NEXTOS_DD_T_OFF_MOTOR
`#define' `__NEXTOS_DD_L_OFF_MOTOR'  __NEXTOS_DD_L_OFF_MOTOR

`#define' `__NEXTOS_DOS_INITIALISE'  __NEXTOS_DOS_INITIALISE
`#define' `__NEXTOS_DOS_INITIALIZE'  __NEXTOS_DOS_INITIALIZE
`#define' `__NEXTOS_IDE_INTERFACE'  __NEXTOS_IDE_INTERFACE
`#define' `__NEXTOS_IDE_INIT'  __NEXTOS_IDE_INIT
`#define' `__NEXTOS_IDE_DRIVE'  __NEXTOS_IDE_DRIVE
`#define' `__NEXTOS_IDE_SECTOR_READ'  __NEXTOS_IDE_SECTOR_READ
`#define' `__NEXTOS_IDE_SECTOR_WRITE'  __NEXTOS_IDE_SECTOR_WRITE
`#define' `__NEXTOS_IDE_PARTITION_NEW'  __NEXTOS_IDE_PARTITION_NEW
`#define' `__NEXTOS_IDE_PARTITION_INIT'  __NEXTOS_IDE_PARTITION_INIT
`#define' `__NEXTOS_IDE_PARTITION_READ'  __NEXTOS_IDE_PARTITION_READ
`#define' `__NEXTOS_IDE_PARTITION_OPEN'  __NEXTOS_IDE_PARTITION_OPEN
`#define' `__NEXTOS_IDE_PARTITION_CLOSE'  __NEXTOS_IDE_PARTITION_CLOSE
`#define' `__NEXTOS_IDE_PARTITIONS'  __NEXTOS_IDE_PARTITIONS

`#define' `__NEXTOS_DOTN_SP_DIVMMC'  __NEXTOS_DOTN_SP_DIVMMC

`#define' `__ESX_DISK_FILEMAP'  __ESX_DISK_FILEMAP
`#define' `__ESX_DISK_STRMSTART'  __ESX_DISK_STRMSTART
`#define' `__ESX_DISK_STRMEND'  __ESX_DISK_STRMEND

`#define' `__ESX_M_DOSVERSION'  __ESX_M_DOSVERSION
`#define' `__ESX_M_GETSETDRV'  __ESX_M_GETSETDRV
`#define' `__ESX_M_TAPEIN'  __ESX_M_TAPEIN
`#define' `__ESX_M_TAPEOUT'  __ESX_M_TAPEOUT
`#define' `__ESX_M_GETHANDLE'  __ESX_M_GETHANDLE
`#define' `__ESX_M_GETDATE'  __ESX_M_GETDATE
`#define' `__ESX_M_EXECCMD'  __ESX_M_EXECCMD
`#define' `__ESX_M_DRVAPI'  __ESX_M_DRVAPI
`#define' `__ESX_M_GETERR'  __ESX_M_GETERR
`#define' `__ESX_M_P3DOS'  __ESX_M_P3DOS
`#define' `__ESX_M_ERRH'  __ESX_M_ERRH

`#define' `__ESX_F_OPEN'  __ESX_F_OPEN
`#define' `__ESX_F_CLOSE'  __ESX_F_CLOSE
`#define' `__ESX_F_SYNC'  __ESX_F_SYNC
`#define' `__ESX_F_READ'  __ESX_F_READ
`#define' `__ESX_F_WRITE'  __ESX_F_WRITE
`#define' `__ESX_F_SEEK'  __ESX_F_SEEK
`#define' `__ESX_F_FGETPOS'  __ESX_F_FGETPOS
`#define' `__ESX_F_FSTAT'  __ESX_F_FSTAT
`#define' `__ESX_F_FTRUNCATE'  __ESX_F_FTRUNCATE
`#define' `__ESX_F_OPENDIR'  __ESX_F_OPENDIR
`#define' `__ESX_F_READDIR'  __ESX_F_READDIR
`#define' `__ESX_F_TELLDIR'  __ESX_F_TELLDIR
`#define' `__ESX_F_SEEKDIR'  __ESX_F_SEEKDIR
`#define' `__ESX_F_REWINDDIR'  __ESX_F_REWINDDIR
`#define' `__ESX_F_GETCWD'  __ESX_F_GETCWD
`#define' `__ESX_F_CHDIR'  __ESX_F_CHDIR
`#define' `__ESX_F_MKDIR'  __ESX_F_MKDIR
`#define' `__ESX_F_RMDIR'  __ESX_F_RMDIR
`#define' `__ESX_F_STAT'  __ESX_F_STAT
`#define' `__ESX_F_UNLINK'  __ESX_F_UNLINK
`#define' `__ESX_F_TRUNCATE'  __ESX_F_TRUNCATE
`#define' `__ESX_F_CHMOD'  __ESX_F_CHMOD
`#define' `__ESX_F_RENAME'  __ESX_F_RENAME
`#define' `__ESX_F_GETFREE'  __ESX_F_GETFREE

`#define' `__NEXTOS_RC_READY'  __NEXTOS_RC_READY
`#define' `__NEXTOS_RC_WP'  __NEXTOS_RC_WP
`#define' `__NEXTOS_RC_SEEK'  __NEXTOS_RC_SEEK
`#define' `__NEXTOS_RC_CRC'  __NEXTOS_RC_CRC
`#define' `__NEXTOS_RC_NODATA'  __NEXTOS_RC_NODATA
`#define' `__NEXTOS_RC_MARK'  __NEXTOS_RC_MARK
`#define' `__NEXTOS_RC_UNRECOG'  __NEXTOS_RC_UNRECOG
`#define' `__NEXTOS_RC_UNKNOWN'  __NEXTOS_RC_UNKNOWN
`#define' `__NEXTOS_RC_DISKCHG'  __NEXTOS_RC_DISKCHG
`#define' `__NEXTOS_RC_UNSUIT'  __NEXTOS_RC_UNSUIT

`#define' `__NEXTOS_RC_BADNAME'  __NEXTOS_RC_BADNAME
`#define' `__NEXTOS_RC_BADPARAM'  __NEXTOS_RC_BADPARAM
`#define' `__NEXTOS_RC_NODRIVE'  __NEXTOS_RC_NODRIVE
`#define' `__NEXTOS_RC_NOFILE'  __NEXTOS_RC_NOFILE
`#define' `__NEXTOS_RC_EXISTS'  __NEXTOS_RC_EXISTS
`#define' `__NEXTOS_RC_EOF'  __NEXTOS_RC_EOF
`#define' `__NEXTOS_RC_DISKFULL'  __NEXTOS_RC_DISKFULL
`#define' `__NEXTOS_RC_DIRFULL'  __NEXTOS_RC_DIRFULL
`#define' `__NEXTOS_RC_RO'  __NEXTOS_RC_RO
`#define' `__NEXTOS_RC_NUMBER'  __NEXTOS_RC_NUMBER
`#define' `__NEXTOS_RC_DENIED'  __NEXTOS_RC_DENIED
`#define' `__NEXTOS_RC_NORENAME'  __NEXTOS_RC_NORENAME
`#define' `__NEXTOS_RC_EXTENT'  __NEXTOS_RC_EXTENT
`#define' `__NEXTOS_RC_UNCACHED'  __NEXTOS_RC_UNCACHED
`#define' `__NEXTOS_RC_TOOBIG'  __NEXTOS_RC_TOOBIG
`#define' `__NEXTOS_RC_NOTBOOT'  __NEXTOS_RC_NOTBOOT
`#define' `__NEXTOS_RC_INUSE'  __NEXTOS_RC_INUSE

`#define' `__NEXTOS_RC_INVPARTITION'  __NEXTOS_RC_INVPARTITION
`#define' `__NEXTOS_RC_PARTEXIST'  __NEXTOS_RC_PARTEXIST
`#define' `__NEXTOS_RC_NOTIMP'  __NEXTOS_RC_NOTIMP
`#define' `__NEXTOS_RC_PARTOPEN'  __NEXTOS_RC_PARTOPEN
`#define' `__NEXTOS_RC_NOHANDLE'  __NEXTOS_RC_NOHANDLE
`#define' `__NEXTOS_RC_NOTSWAP'  __NEXTOS_RC_NOTSWAP
`#define' `__NEXTOS_RC_MAPPED'  __NEXTOS_RC_MAPPED
`#define' `__NEXTOS_RC_NOXDPB'  __NEXTOS_RC_NOXDPB
`#define' `__NEXTOS_RC_NOSWAP'  __NEXTOS_RC_NOSWAP
`#define' `__NEXTOS_RC_INVDEVICE'  __NEXTOS_RC_INVDEVICE
`#define' `__NEXTOS_RC_CMDPHASE'  __NEXTOS_RC_CMDPHASE
`#define' `__NEXTOS_RC_DATAPHASE'  __NEXTOS_RC_DATAPHASE
`#define' `__NEXTOS_RC_NOTDIR'  __NEXTOS_RC_NOTDIR
')
