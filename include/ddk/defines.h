#ifndef _DDK_DEFINES_H
#define _DDK_DEFINES_H

/* GENERAL DEFINITIONS ****************************************************/

#ifndef __ASM__

#define _WIN32_WINNT 0x0400

#include <ddk/kedef.h> 
#include <ddk/iodef.h>

#define EXPORTED __declspec(dllexport)
#define IMPORTED __declspec(dllimport)

/*
 * PURPOSE: Number of a thread priority levels
 */
#define NR_PRIORITY_LEVELS (32)

/*
 * PURPOSE: Type of queue to insert a work item in
 */
enum
{
  CriticalWorkQueue,
  DelayedWorkQueue,
  HyperCriticalWorkQueue,
};

/*
 * Types of memory to allocate
 */
enum
{
   NonPagedPool,
   NonPagedPoolMustSucceed,
   NonPagedPoolCacheAligned,
   NonPagedPoolCacheAlignedMustS,
   PagedPool,
   PagedPoolCacheAligned,
};
   
/*
 * This is a list of bug check types (not MS's)
 */
enum
{
   APC_INDEX_MISMATCH = 1,
   DEVICE_QUEUE_NOT_BUSY,
   INVALID_AFFINITY_SET,
   INVALID_DATA_ACCESS_TRAP,
   INVALID_PROCESS_ATTACH_ATTEMPT,
   INVALID_PROCESS_DEATTACH_ATTEMPT,
   INVALID_SOFTWARE_INTERRUPT,
   IRQL_NOT_DISPATCH_LEVEL,
   IRQL_NOT_GREATER_OR_EQUAL,
   NO_EXCEPTION_HANDLING_SUPPORT,
   MAXIMUM_WAIT_OBJECTS_EXCEEDED,
   MUTEX_LEVEL_NUMBER_VIOLATION,
   NO_USER_MODE_CONTEXT,
   SPIN_LOCK_ALREADY_OWNED,
   SPIN_LOCK_NOT_OWNED,
   THREAD_NOT_MUTEX_OWNER,
   TRAP_CAUSE_UNKNOWN,
   EMPTY_THREAD_REAPER_LIST,
   CREATE_DELETE_LOCK_NOT_LOCKED,
   LAST_CHANCE_CALLED_FROM_KMODE,
   CID_HANDLE_CREATION,
   CID_HANDLE_DELETION,
   REFERENCE_BY_POINTER,
   BAD_POOL_HEADER,
   MEMORY_MANAGMENT,
   PFN_SHARE_COUNT,
   PFN_REFERENCE_COUNT,
   NO_SPIN_LOCK_AVAILABLE,
   KMODE_EXCEPTION_NOT_HANDLED,
   SHARED_RESOURCE_CONV_ERROR,
   KERNEL_APC_PENDING_DURING_EXIT,
   QUOTA_UNDERFLOW,
   FILE_SYSTEM,
   FAT_FILE_SYSTEM,
   NTFS_FILE_SYSTEM,
   NPFS_FILE_SYSTEM,
   CDFS_FILE_SYSTEM,
   RDR_FILE_SYSTEM,
   CORRUPT_ACCESS_TOKEN,
   SECURITY_SYSTEM,
   INCONSISTENT_IRP,
   PANIC_STACK_SWITCH,
   PORT_DRIVER_INTERNAL,
   SCSI_DISK_DRIVER_INTERNAL,
   INSTRUCTION_BUS_ERROR,
   SET_OF_INVALID_CONTEXT,
   PHASE0_INITIALIZATION_FAILED,
   PHASE1_INITIALIZATION_FAILED,
   UNEXPECTED_INITIALIZATION_CALL,
   CACHE_MANAGER,
   NO_MORE_IRP_STACK_LOCATIONS,
   DEVICE_REFERENCE_COUNT_NOT_ZERO,
   FLOPPY_INTERNAL_ERROR,
   SERIAL_DRIVER_INTERNAL,
   SYSTEM_EXIT_OWNED_MUTEX,
   SYSTEM_UNWIND_PREVIOUS_USER,
   SYSTEN_SERVICE_EXCEPTION,
   INTERRUPT_UNWIND_ATTEMPTED,
   INTERRUPT_EXCEPTION_NOT_HANDLED,
   MULTIPROCESSOR_CONFIGURATION_NOT_SUPPORTED,
   NO_MORE_SYSTEM_PTES,
   TARGET_MDL_TOO_SMALL,
   MUST_SUCCEED_POOL_EMPTY,
   ATDISK_DRIVER_INTERNAL,
   NO_SUCH_PARTITION,
   MULTIPLE_IRP_COMPLETE_REQUESTS,
   INSUFFICENT_SYSTEM_MAP_PAGES,
   DEREF_UNKNOWN_LOGON_SERVICE,
   REF_UNKNOWN_LOGON_SERVICE,
   CANCEL_STATE_IN_COMPLETED_IRP,
   PAGE_FAULT_WITH_INTERRUPTS_OFF,
   IRQL_GT_ZERO_AT_SYSTEM_SERVICE,
   STREAMS_INTERNAL_ERROR,
   FATAL_UNHANDLED_HARD_ERROR,
   NO_PAGES_AVAILABLE,
   PFN_LIST_CORRUPT,
   NDIS_INTERNAL_ERROR,
   PAGE_FAULT_IN_NONPAGED_AREA,
   REGISTRY_ERROR,
   MAILSLOT_FILE_SYSTEM,
   NO_BOOT_DEVICE,
   LM_SERVER_INTERNAL_ERROR,
   DATA_COHERENCY_EXCEPTION,
   INSTRUCTION_COHERENCY_EXCEPTION,
   XNS_INTERNAL_ERROR,
   FTDISK_INTERNAL_ERROR,
   PINBALL_FILE_SYSTEM,
   CRITICAL_SERVICE_FAILED,
   SET_ENV_VAR_FAILED,
   HAL_INITIALIZED_FAILED,
   UNSUPPORTED_PROCESSOR,
   OBJECT_INITIALIZATION_FAILED,
   SECURITY_INITIALIZATION_FAILED,
   PROCESS_INITIALIZATION_FAILED,
   HAL1_INITIALIZATION_FAILED,   
};
enum
{
   KBUG_NONE,
   KBUG_ORPHANED_IRP,
   KBUG_IO_STACK_OVERFLOW,
   KBUG_OUT_OF_MEMORY,
   KBUG_POOL_FREE_LIST_CORRUPT,
     
   /*
    * These are well known but the actual value is unknown
    */
//   NO_PAGES_AVAILABLE,
     
   /*
    * These are well known (MS) bug types
    * (Reference: NT Insider 1997 - http://www.osr.com)
    */
   IRQL_NOT_LESS_OR_EQUAL = 0xa,
//   KMODE_EXCEPTION_NOT_HANDLED = 0x1e,
   UNEXPECTED_KERNEL_MODE_TRAP = 0x7f,
   PAGE_FAULT_IN_NON_PAGED_AREA = 0x50,
};

/*
 * PURPOSE: Object attributes
 */
enum
{
   OBJ_INHERIT = 0x2,
   OBJ_PERMANENT = 0x10,
   OBJ_EXCLUSIVE = 0x20,
   OBJ_CASE_INSENSITIVE = 0x40,
   OBJ_OPENIF = 0x80,
   OBJ_OPENLINK = 0x100,
   OBJ_VALID_ATTRIBUTES = 0x1F2,
};

/*
 * PURPOSE: Timer types
 */
enum
  {
      NotificationTimer,
      SynchronizationTimer,
  };
   
/*
 * PURPOSE: Some drivers use these
 */
#ifndef IN
#define IN
#define OUT
#define OPTIONAL
#endif

/*
 * PURPOSE: Power IRP minor function numbers
 */
enum
{
   IRP_MN_QUERY_POWER,
   IRP_MN_SET_POWER,
   IRP_MN_WAIT_WAKE,
   IRP_MN_QUERY_CAPABILITIES,
   IRP_MN_POWER_SEQUENCE,
};

/*
 * PURPOSE: Arguments to MmProbeAndLockPages
 */
enum
{
   IoReadAccess,
   IoWriteAccess,
   IoModifyAccess,
};

#define MAXIMUM_VOLUME_LABEL_LENGTH (32)

#include <ddk/i386/irql.h>

/*
 * IRQ levels
 */
#define PASSIVE_LEVEL                (1)
#define APC_LEVEL                    (2)
#define DISPATCH_LEVEL               (3)
#define FIRST_DEVICE_SPECIFIC_LEVEL  (4)
#define HIGH_LEVEL (FIRST_DEVICE_SPECIFIC_LEVEL + NR_DEVICE_SPECIFIC_LEVELS)

/* NT's IRQL */
#if 0
#define PASSIVE_LEVEL	0		// Passive release level
#define LOW_LEVEL	0		// Lowest interrupt level
#define APC_LEVEL	1		// APC interrupt level
#define DISPATCH_LEVEL	2		// Dispatcher level

#define PROFILE_LEVEL	27		// timer used for profiling. 
#define CLOCK1_LEVEL	28		// Interval clock 1 level - Not used on x86
#define CLOCK2_LEVEL	28		// Interval clock 2 level
#define IPI_LEVEL	29		// Interprocessor interrupt level 
#define POWER_LEVEL	30		// Power failure level
#define HIGH_LEVEL	31		// Highest interrupt level
#define SYNCH_LEVEL	(IPI_LEVEL-1)	// synchronization level
#endif

#endif /* __ASM__ */

/* Values returned by KeGetPreviousMode() */
#define KernelMode (0)
#define UserMode   (1)

#endif /* ndef _DDK_DEFINES_H */
