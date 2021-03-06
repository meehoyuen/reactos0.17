/*
 * COPYRIGHT:            See COPYING in the top level directory
 * PROJECT:              ReactOS project
 * FILE:                 ntoskrnl/ke/wait.c
 * PURPOSE:              Manages non-busy waiting
 * PROGRAMMER:           David Welch (welch@mcmail.com)
 * REVISION HISTORY:
 *           21/07/98: Created
 *	     12/1/99:  Phillip Susi: Fixed wake code in KeDispatcherObjectWake
 *		   so that things like KeWaitForXXX() return the correct value
 */

/* NOTES ********************************************************************
 * 
 */

/* INCLUDES ******************************************************************/

#include <ddk/ntddk.h>
#include <internal/ke.h>
#include <internal/ps.h>
#include <internal/ob.h>
#include <internal/id.h>
#include <ntos/ntdef.h>

#define NDEBUG
#include <internal/debug.h>

/* GLOBALS ******************************************************************/

static KSPIN_LOCK DispatcherDatabaseLock;
static BOOLEAN WaitSet = FALSE;
static KIRQL oldlvl = PASSIVE_LEVEL;
static PKTHREAD Owner = NULL; 

/* FUNCTIONS *****************************************************************/

VOID KeInitializeDispatcherHeader(DISPATCHER_HEADER* Header,
				  ULONG Type,
				  ULONG Size,
				  ULONG SignalState)
{
   Header->Type = Type;
   Header->Absolute = 0;
   Header->Inserted = 0;
   Header->Size = Size;
   Header->SignalState = SignalState;
   InitializeListHead(&(Header->WaitListHead));
}

VOID KeAcquireDispatcherDatabaseLock(BOOLEAN Wait)
/*
 * PURPOSE: Acquires the dispatcher database lock for the caller
 */
{
   DPRINT("KeAcquireDispatcherDatabaseLock(Wait %x)\n",Wait);
   if (WaitSet && Owner == KeGetCurrentThread())
     {
	return;
     }
   KeAcquireSpinLock(&DispatcherDatabaseLock, &oldlvl);
   WaitSet = Wait;
   Owner = KeGetCurrentThread();
}

VOID KeReleaseDispatcherDatabaseLockAtDpcLevel(BOOLEAN Wait)
{
  DPRINT("KeReleaseDispatcherDatabaseLockAtDpcLevel(Wait %x)\n", Wait);
  assert(Wait == WaitSet);
  if (!Wait)
    {
      Owner = NULL;
      KeReleaseSpinLockFromDpcLevel(&DispatcherDatabaseLock);
    }
}

VOID KeReleaseDispatcherDatabaseLock(BOOLEAN Wait)
{
   DPRINT("KeReleaseDispatcherDatabaseLock(Wait %x)\n",Wait);  
   assert(Wait==WaitSet);
   if (!Wait)
     {
	Owner = NULL;
	KeReleaseSpinLock(&DispatcherDatabaseLock, oldlvl);
     }
}

VOID KiSideEffectsBeforeWake(DISPATCHER_HEADER* hdr,
			     PKTHREAD Thread)
/*
 * FUNCTION: Perform side effects on object before a wait for a thread is
 *           satisfied
 */
{
   switch (hdr->Type)
     {
      case InternalSynchronizationEvent:
	hdr->SignalState = 0;
	break;
	
      case InternalSemaphoreType:
	hdr->SignalState--;
	break;
	
      case InternalProcessType:
	break;
	
      case InternalThreadType:
	break;
	
      case InternalNotificationEvent:
	break;
	
      case InternalSynchronizationTimer:
	hdr->SignalState = FALSE;
	break;
	
      case InternalNotificationTimer:
	break;
	
      case InternalMutexType:
	  {
	     PKMUTEX Mutex;
	     
	     Mutex = CONTAINING_RECORD(hdr, KMUTEX, Header);
	     hdr->SignalState--;
	     assert(hdr->SignalState <= 1);
	     Mutex->OwnerThread = Thread;
	  }
	break;
	
      default:
	DbgPrint("(%s:%d) Dispatcher object %x has unknown type\n",
		 __FILE__,__LINE__,hdr);
	KeBugCheck(0);
     }

}

static BOOLEAN KiIsObjectSignalled(DISPATCHER_HEADER* hdr,
				   PKTHREAD Thread)
{
   if (hdr->Type == InternalMutexType)
     {
        PKMUTEX Mutex;
	
	Mutex = CONTAINING_RECORD(hdr, KMUTEX, Header);
	
	assert(hdr->SignalState <= 1);
	if ((hdr->SignalState < 1 && Mutex->OwnerThread == Thread) ||
	    hdr->SignalState == 1)
	  {
	     KiSideEffectsBeforeWake(hdr,
				     Thread);
	     return(TRUE);
	  }
	else
	  {
	     return(FALSE);
	  }
     }
   if (hdr->SignalState <= 0)
     {
	return(FALSE);
     }
   else
     {
	KiSideEffectsBeforeWake(hdr, Thread);
	return(TRUE);
     }
}

VOID KeRemoveAllWaitsThread(PETHREAD Thread, NTSTATUS WaitStatus)
{  
   PKWAIT_BLOCK WaitBlock;
   BOOLEAN WasWaiting = FALSE;
   
   KeAcquireDispatcherDatabaseLock(FALSE);
   
   WaitBlock = (PKWAIT_BLOCK)Thread->Tcb.WaitBlockList;
   if (WaitBlock != NULL)
     {
	WasWaiting = TRUE;
     }   
   while (WaitBlock != NULL)
     {
	RemoveEntryList(&WaitBlock->WaitListEntry);
	WaitBlock = WaitBlock->NextWaitBlock;
     }
   Thread->Tcb.WaitBlockList = NULL;
   
   if (WasWaiting)
     {
	PsUnblockThread(Thread, &WaitStatus);
     }
   
   KeReleaseDispatcherDatabaseLock(FALSE);
}

static BOOLEAN KeDispatcherObjectWakeAll(DISPATCHER_HEADER* hdr)
{
   PKWAIT_BLOCK current;
   PLIST_ENTRY current_entry;
   PKWAIT_BLOCK PrevBlock;
   NTSTATUS Status;

   DPRINT("KeDispatcherObjectWakeAll(hdr %x)\n",hdr);
   
   if (IsListEmpty(&hdr->WaitListHead))
     {
	return(FALSE);
     }
   
   while (!IsListEmpty(&(hdr->WaitListHead)))
     {
	current_entry = RemoveHeadList(&hdr->WaitListHead);
	current = CONTAINING_RECORD(current_entry,
				    KWAIT_BLOCK,
				    WaitListEntry);
        DPRINT("Waking %x\n",current->Thread);
        if (current->WaitType == WaitAny)
          {
             DPRINT("WaitAny: Remove all wait blocks.\n");
	     for( PrevBlock = current->Thread->WaitBlockList; PrevBlock; PrevBlock = PrevBlock->NextWaitBlock )
	       if( PrevBlock != current )
		 RemoveEntryList( &(PrevBlock->WaitListEntry) );
	     current->Thread->WaitBlockList = 0;
          }
        else
          {
	     DPRINT("WaitAll: Remove the current wait block only.\n");
	     
	     PrevBlock = current->Thread->WaitBlockList;
	     if (PrevBlock == current)
	       {
		  DPRINT( "WaitAll: Current block is list head.\n" );
		  current->Thread->WaitBlockList = current->NextWaitBlock;
	       }
	     else
	       {
		  DPRINT( "WaitAll: Current block is not list head.\n" );
		  while ( PrevBlock && PrevBlock->NextWaitBlock != current)
		    {
		       PrevBlock = PrevBlock->NextWaitBlock;
		    }
		  if (PrevBlock)
		    {
		       PrevBlock->NextWaitBlock = current->NextWaitBlock;
		    }
	       }
	  }     
	KiSideEffectsBeforeWake(hdr, current->Thread);
	Status = current->WaitKey;
	if (current->Thread->WaitBlockList == NULL)
	  {
	     PsUnblockThread(CONTAINING_RECORD(current->Thread,ETHREAD,Tcb), 
			     &Status);
	  }
     }
   return(TRUE);
}

static BOOLEAN KeDispatcherObjectWakeOne(DISPATCHER_HEADER* hdr)
{
   PKWAIT_BLOCK current;
   PLIST_ENTRY current_entry;
   PKWAIT_BLOCK PrevBlock;
   NTSTATUS Status;

   DPRINT("KeDispatcherObjectWakeOn(hdr %x)\n",hdr);
   DPRINT("hdr->WaitListHead.Flink %x hdr->WaitListHead.Blink %x\n",
	  hdr->WaitListHead.Flink,hdr->WaitListHead.Blink);
   if (IsListEmpty(&(hdr->WaitListHead)))
     {
	return(FALSE);
     }
   current_entry = RemoveHeadList(&(hdr->WaitListHead));
   current = CONTAINING_RECORD(current_entry,KWAIT_BLOCK,
			       WaitListEntry);
   DPRINT("current_entry %x current %x\n",current_entry,current);

   if (current->WaitType == WaitAny)
     {
        DPRINT("WaitAny: Remove all wait blocks.\n");
	for( PrevBlock = current->Thread->WaitBlockList; PrevBlock; PrevBlock = PrevBlock->NextWaitBlock )
	  if( PrevBlock != current )
	    RemoveEntryList( &(PrevBlock->WaitListEntry) );
	current->Thread->WaitBlockList = 0;
     }
   else
     {
        DPRINT("WaitAll: Remove the current wait block only.\n");

        PrevBlock = current->Thread->WaitBlockList;
        if (PrevBlock == current)
           {
              DPRINT( "WaitAll: Current block is list head.\n" );
              current->Thread->WaitBlockList = current->NextWaitBlock;
           }
        else
           {
              DPRINT( "WaitAll: Current block is not list head.\n" );
              while ( PrevBlock && PrevBlock->NextWaitBlock != current)
                {
                   PrevBlock = PrevBlock->NextWaitBlock;
                }
              if (PrevBlock)
                {
                   PrevBlock->NextWaitBlock = current->NextWaitBlock;
                }
	   }
     }

   DPRINT("Waking %x\n",current->Thread);
   KiSideEffectsBeforeWake(hdr, current->Thread);
   Status = current->WaitKey;
   PsUnblockThread(CONTAINING_RECORD(current->Thread, ETHREAD, Tcb), 
		   &Status);
   return(TRUE);
}

BOOLEAN KeDispatcherObjectWake(DISPATCHER_HEADER* hdr)
/*
 * FUNCTION: Wake threads waiting on a dispatcher object
 * NOTE: The exact semantics of waking are dependant on the type of object
 */
{
   BOOL Ret;

   DPRINT("Entering KeDispatcherObjectWake(hdr %x)\n",hdr);
//   DPRINT("hdr->WaitListHead %x hdr->WaitListHead.Flink %x\n",
//	  &hdr->WaitListHead,hdr->WaitListHead.Flink);
   DPRINT("hdr->Type %x\n",hdr->Type);
   switch (hdr->Type)
     {
      case InternalNotificationEvent:
	return(KeDispatcherObjectWakeAll(hdr));
	
      case InternalNotificationTimer:
	return(KeDispatcherObjectWakeAll(hdr));
	
      case InternalSynchronizationEvent:
	return(KeDispatcherObjectWakeOne(hdr));


      case InternalSynchronizationTimer:
	return(KeDispatcherObjectWakeOne(hdr));
	
      case InternalSemaphoreType:
	DPRINT("hdr->SignalState %d\n", hdr->SignalState);
	if(hdr->SignalState>0)
	{
	   do
	     {
		DPRINT("Waking one semaphore waiter\n");
		Ret = KeDispatcherObjectWakeOne(hdr);
	     } while(hdr->SignalState > 0 &&  Ret) ;
	   return(Ret);
	}
	else return FALSE;
	
      case InternalProcessType:
	return(KeDispatcherObjectWakeAll(hdr));

      case InternalThreadType:
	return(KeDispatcherObjectWakeAll(hdr));
	
      case InternalMutexType:
	return(KeDispatcherObjectWakeOne(hdr));
     }
   DbgPrint("Dispatcher object %x has unknown type %d\n", hdr, hdr->Type);
   KeBugCheck(0);
   return(FALSE);
}


NTSTATUS STDCALL KeWaitForSingleObject (PVOID		Object,
					KWAIT_REASON	WaitReason,
					KPROCESSOR_MODE	WaitMode,
					BOOLEAN		Alertable,
					PLARGE_INTEGER	Timeout)
/*
 * FUNCTION: Puts the current thread into a wait state until the
 * given dispatcher object is set to signalled 
 * ARGUMENTS:
 *         Object = Object to wait on
 *         WaitReason = Reason for the wait (debugging aid)
 *         WaitMode = Can be KernelMode or UserMode, if UserMode then
 *                    user-mode APCs can be delivered and the thread's
 *                    stack can be paged out
 *         Altertable = Specifies if the wait is a alertable
 *         Timeout = Optional timeout value
 * RETURNS: Status
 */
{
   DISPATCHER_HEADER* hdr = (DISPATCHER_HEADER *)Object;
   PKTHREAD CurrentThread;
   NTSTATUS Status;
   KIRQL WaitIrql;

   DPRINT("Entering KeWaitForSingleObject(Object %x) "
	  "PsGetCurrentThread() %x\n",Object,PsGetCurrentThread());

   CurrentThread = KeGetCurrentThread();
   WaitIrql = KeGetCurrentIrql();

   if (Timeout != NULL)
     {
	KeAddThreadTimeout(CurrentThread, Timeout);
     }
   
   do
     {
       KeAcquireDispatcherDatabaseLock(FALSE);
	
       DPRINT("hdr->SignalState %d\n", hdr->SignalState);     
       
       if (Alertable && KiTestAlert())
	 {
	   KeReleaseDispatcherDatabaseLock(FALSE);
	   return(STATUS_USER_APC);
	 }      

       if (KiIsObjectSignalled(hdr, CurrentThread))
	 {	     
	   KeReleaseDispatcherDatabaseLock(FALSE);
	   if (Timeout != NULL)
	     {
	       KeCancelTimer(&KeGetCurrentThread()->Timer);
	     }
	   return(STATUS_WAIT_0);
	  }
       
       CurrentThread->WaitStatus = STATUS_UNSUCCESSFUL;
       /* Append wait block to the KTHREAD wait block list */
       CurrentThread->WaitBlockList = &CurrentThread->WaitBlock[0];	
       CurrentThread->WaitBlock[0].Object = Object;
       CurrentThread->WaitBlock[0].Thread = CurrentThread;
       CurrentThread->WaitBlock[0].WaitKey = 0;
       CurrentThread->WaitBlock[0].WaitType = WaitAny;
       CurrentThread->WaitBlock[0].NextWaitBlock = NULL;
       InsertTailList(&hdr->WaitListHead, 
		      &CurrentThread->WaitBlock[0].WaitListEntry);
       PsBlockThread(&Status, (UCHAR)Alertable, WaitMode, TRUE, WaitIrql);
     } while (Status == STATUS_KERNEL_APC);
   
   if (Timeout != NULL)
     {
       KeCancelTimer(&KeGetCurrentThread()->Timer);
     }
   
   DPRINT("Returning from KeWaitForSingleObject()\n");
   return(Status);
}


NTSTATUS STDCALL
KeWaitForMultipleObjects (ULONG		Count,
			  PVOID		Object[],
			  WAIT_TYPE	WaitType,
			  KWAIT_REASON	WaitReason,
			  KPROCESSOR_MODE	WaitMode,
			  BOOLEAN		Alertable,
			  PLARGE_INTEGER	Timeout,
			  PKWAIT_BLOCK	WaitBlockArray)
{
  DISPATCHER_HEADER* hdr;
  PKWAIT_BLOCK blk;
  PKTHREAD CurrentThread;
  ULONG CountSignaled;
  ULONG i;
  NTSTATUS Status;
  KIRQL WaitIrql;

  DPRINT("Entering KeWaitForMultipleObjects(Count %lu Object[] %p) "
	 "PsGetCurrentThread() %x\n",Count,Object,PsGetCurrentThread());

  CountSignaled = 0;
  CurrentThread = KeGetCurrentThread();
  WaitIrql = KeGetCurrentIrql();

  if (WaitBlockArray == NULL)
    {
      if (Count > 4)
        {
	  DbgPrint("(%s:%d) Too many objects!\n",
		   __FILE__,__LINE__);
	  return STATUS_UNSUCCESSFUL;
        }
      blk = &CurrentThread->WaitBlock[0];
    }
  else
    {
      if (Count > 64)
        {
	  DbgPrint("(%s:%d) Too many objects!\n",
		   __FILE__,__LINE__);
	  return STATUS_UNSUCCESSFUL;
        }
      blk = WaitBlockArray;
    }
  if (Timeout != NULL)
    {
      KeAddThreadTimeout(CurrentThread,Timeout);
    }
  
  do {
    KeAcquireDispatcherDatabaseLock(FALSE);
    
    for (i = 0; i < Count; i++)
      {
	hdr = (DISPATCHER_HEADER *)Object[i];
	
	DPRINT("hdr->SignalState %d\n", hdr->SignalState);
	
	if (KiIsObjectSignalled(hdr, CurrentThread))
	  {
	    CountSignaled++;
	    
	    if (WaitType == WaitAny)
	      {
		  KeReleaseDispatcherDatabaseLock(FALSE);
		  DPRINT("One object is already signaled!\n");
		  return(STATUS_WAIT_0 + i);
	      }
	  }
      }
    
    if ((WaitType == WaitAll) && (CountSignaled == Count))
      {
	KeReleaseDispatcherDatabaseLock(FALSE);
	DPRINT("All objects are already signaled!\n");
	return(STATUS_WAIT_0);
      }
    
    /* Append wait block to the KTHREAD wait block list */
    CurrentThread->WaitBlockList = blk;
    
    for (i = 0; i < Count; i++)
      {
	hdr = (DISPATCHER_HEADER *)Object[i];
	
	DPRINT("hdr->SignalState %d\n", hdr->SignalState);
	
	blk->Object = Object[i];
	blk->Thread = CurrentThread;
	blk->WaitKey = i;
	blk->WaitType = WaitType;
	if (i == Count - 1)
	  blk->NextWaitBlock = NULL;
	else
	  blk->NextWaitBlock = blk + 1;
	
	InsertTailList(&(hdr->WaitListHead),&(blk->WaitListEntry));
	
	blk = blk->NextWaitBlock;
      }
    
    PsBlockThread(&Status, Alertable, WaitMode, TRUE, WaitIrql);
  } while( Status == STATUS_KERNEL_APC );
  if (Timeout != NULL)
    KeCancelTimer(&KeGetCurrentThread()->Timer);
  DPRINT("Returning from KeWaitForMultipleObjects()\n");
  return(Status);
}

VOID KeInitializeDispatcher(VOID)
{
   KeInitializeSpinLock(&DispatcherDatabaseLock);
}

NTSTATUS STDCALL NtWaitForMultipleObjects(IN ULONG Count,
					  IN HANDLE Object [],
					  IN CINT WaitType,
					  IN BOOLEAN Alertable,
					  IN PLARGE_INTEGER Time)
{
   KWAIT_BLOCK WaitBlockArray[EX_MAXIMUM_WAIT_OBJECTS]; 
   PVOID ObjectPtrArray[EX_MAXIMUM_WAIT_OBJECTS];       
   NTSTATUS Status;
   ULONG i, j;

   DPRINT("NtWaitForMultipleObjects(Count %lu Object[] %x, Alertable %d, "
	  "Time %x)\n", Count,Object,Alertable,Time);

   if (Count > EX_MAXIMUM_WAIT_OBJECTS)  
     return STATUS_UNSUCCESSFUL;

   /* reference all objects */
   for (i = 0; i < Count; i++)
     {
        Status = ObReferenceObjectByHandle(Object[i],
                                           SYNCHRONIZE,
                                           NULL,
                                           UserMode,
                                           &ObjectPtrArray[i],
                                           NULL);
        if (Status != STATUS_SUCCESS)
          {
             /* dereference all referenced objects */
             for (j = 0; j < i; i++)
               {
                  ObDereferenceObject(ObjectPtrArray[j]);
               }

             return(Status);
          }
     }

   Status = KeWaitForMultipleObjects(Count,
                                     ObjectPtrArray,
                                     WaitType,
                                     UserRequest,
                                     UserMode,
                                     Alertable,
                                     Time,
                                     WaitBlockArray);

   /* dereference all objects */
   for (i = 0; i < Count; i++)
     {
        ObDereferenceObject(ObjectPtrArray[i]);
     }

   return(Status);
}


NTSTATUS STDCALL NtWaitForSingleObject (IN	HANDLE		Object,
					IN	BOOLEAN		Alertable,
					IN	PLARGE_INTEGER	Time)
{
   PVOID ObjectPtr;
   NTSTATUS Status;
   
   DPRINT("NtWaitForSingleObject(Object %x, Alertable %d, Time %x)\n",
	  Object,Alertable,Time);
   
   Status = ObReferenceObjectByHandle(Object,
				      SYNCHRONIZE,
				      NULL,
				      UserMode,
				      &ObjectPtr,
				      NULL);
   if (!NT_SUCCESS(Status))
     {
	return(Status);
     }
   
   Status = KeWaitForSingleObject(ObjectPtr,
				  UserMode,
				  UserMode,
				  Alertable,
				  Time);
   
   ObDereferenceObject(ObjectPtr);
   
   return(Status);
}


NTSTATUS STDCALL
NtSignalAndWaitForSingleObject(IN HANDLE SignalObject,
			       IN HANDLE WaitObject,
			       IN BOOLEAN Alertable,
			       IN PLARGE_INTEGER Time)
{
   KPROCESSOR_MODE ProcessorMode;
   DISPATCHER_HEADER* hdr;
   PVOID SignalObj;
   PVOID WaitObj;
   NTSTATUS Status;

   ProcessorMode = ExGetPreviousMode();
   Status = ObReferenceObjectByHandle(SignalObject,
				      0,
				      NULL,
				      ProcessorMode,
				      &SignalObj,
				      NULL);
   if (!NT_SUCCESS(Status))
     {
	return Status;
     }

   Status = ObReferenceObjectByHandle(WaitObject,
				      SYNCHRONIZE,
				      NULL,
				      ProcessorMode,
				      &WaitObj,
				      NULL);
   if (!NT_SUCCESS(Status))
     {
	ObDereferenceObject(SignalObj);
	return Status;
     }

   hdr = (DISPATCHER_HEADER *)SignalObj;
   switch (hdr->Type)
     {
      case InternalNotificationEvent:
      case InternalSynchronizationEvent:
	KeSetEvent(SignalObj,
		   EVENT_INCREMENT,
		   TRUE);
	break;

      case InternalMutexType:
	KeReleaseMutex(SignalObj,
		       TRUE);
	break;

      case InternalSemaphoreType:
	KeReleaseSemaphore(SignalObj,
			   SEMAPHORE_INCREMENT,
			   1,
			   TRUE);
	break;

      default:
	ObDereferenceObject(SignalObj);
	ObDereferenceObject(WaitObj);
	return STATUS_OBJECT_TYPE_MISMATCH;
     }

   Status = KeWaitForSingleObject(WaitObj,
				  UserRequest,
				  ProcessorMode,
				  Alertable,
				  Time);

   ObDereferenceObject(SignalObj);
   ObDereferenceObject(WaitObj);

   return Status;
}
