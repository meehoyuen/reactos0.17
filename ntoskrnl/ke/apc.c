/*
 * COPYRIGHT:       See COPYING in the top level directory
 * PROJECT:         ReactOS kernel
 * FILE:            ntoskrnl/ke/apc.c
 * PURPOSE:         Possible implementation of APCs
 * PROGRAMMER:      David Welch (welch@cwcom.net)
 * UPDATE HISTORY:
 *                  Created 22/05/98
 *                  12/11/99:  Phillip Susi: Reworked the APC code
 */

/* INCLUDES *****************************************************************/

#include <ddk/ntddk.h>
#include <internal/i386/segment.h>
#include <internal/ps.h>
#include <internal/ke.h>
#include <internal/ldr.h>

#define NDEBUG
#include <internal/debug.h>

/* NOTES *********************************************************************/



/* GLOBALS *******************************************************************/

KSPIN_LOCK PiApcLock;
extern KSPIN_LOCK PiThreadListLock;

VOID PsTerminateCurrentThread(NTSTATUS ExitStatus);

/* FUNCTIONS *****************************************************************/

VOID KiRundownThread(VOID)
/*
 * FUNCTION: 
 */
{
}

BOOLEAN KiTestAlert(VOID)
/*
 * FUNCTION: Tests whether there are any pending APCs for the current thread
 * and if so the APCs will be delivered on exit from kernel mode
 */
{
   KIRQL oldIrql; 
   
   KeAcquireSpinLock(&PiApcLock, &oldIrql);
   if (KeGetCurrentThread()->ApcState.UserApcPending == 0)
     {
	KeReleaseSpinLock(&PiApcLock, oldIrql);
	return(FALSE);
     }
   KeGetCurrentThread()->Alerted[0] = 1;
   KeReleaseSpinLock(&PiApcLock, oldIrql);
   return(TRUE);
}

VOID
KiDeliverNormalApc(VOID)
{
   PETHREAD Thread = PsGetCurrentThread();
   PLIST_ENTRY current;
   PKAPC Apc;
   KIRQL oldlvl;
   PKNORMAL_ROUTINE NormalRoutine;
   PVOID NormalContext;
   PVOID SystemArgument1;
   PVOID SystemArgument2;

   KeAcquireSpinLock(&PiApcLock, &oldlvl);
   while(!IsListEmpty(&(Thread->Tcb.ApcState.ApcListHead[0])))
   {
     current = Thread->Tcb.ApcState.ApcListHead[0].Blink;
     Apc = CONTAINING_RECORD(current, KAPC, ApcListEntry);
     if (Apc->NormalRoutine != NULL)
       {
	 (void)RemoveTailList(&Thread->Tcb.ApcState.ApcListHead[0]);
	 Thread->Tcb.ApcState.KernelApcInProgress++;
	 Thread->Tcb.ApcState.KernelApcPending--;

	 KeReleaseSpinLock(&PiApcLock, oldlvl);
	 
	 NormalRoutine = Apc->NormalRoutine;
	 NormalContext = Apc->NormalContext;
	 SystemArgument1 = Apc->SystemArgument1;
	 SystemArgument2 = Apc->SystemArgument2;
	 Apc->KernelRoutine(Apc,
			    &NormalRoutine,
			    &NormalContext,
			    &SystemArgument1,
			    &SystemArgument2);	 
	 NormalRoutine(NormalContext, SystemArgument1, SystemArgument2);

	 KeAcquireSpinLock(&PiApcLock, &oldlvl);
	 Thread->Tcb.ApcState.KernelApcInProgress--;
       }
   }
   KeReleaseSpinLock(&PiApcLock, oldlvl);
}

BOOLEAN 
KiDeliverUserApc(PKTRAP_FRAME TrapFrame)
/*
 * FUNCTION: Tests whether there are any pending APCs for the current thread
 * and if so the APCs will be delivered on exit from kernel mode.
 * ARGUMENTS:
 *        Thread = Thread to test for alerts
 *        UserContext = The user context saved on entry to kernel mode
 */
{
   PLIST_ENTRY current_entry;
   PKAPC Apc;
   PULONG Esp;
   PCONTEXT Context;
   KIRQL oldlvl;
   PKTHREAD Thread;

   DPRINT("KiDeliverUserApc(TrapFrame %x/%x)\n", TrapFrame,
	  KeGetCurrentThread()->TrapFrame);
   Thread = KeGetCurrentThread();

   /*
    * Check for thread termination
    */

   KeAcquireSpinLock(&PiApcLock, &oldlvl);

   current_entry = Thread->ApcState.ApcListHead[1].Flink;
   
   /*
    * Shouldn't happen but check anyway.
    */
   if (current_entry == &Thread->ApcState.ApcListHead[1])
     {
	KeReleaseSpinLock(&PiApcLock, oldlvl);
	DbgPrint("KiDeliverUserApc called but no APC was pending\n");
	return(FALSE);
     }
   
   current_entry = RemoveHeadList(&Thread->ApcState.ApcListHead[1]);
   Apc = CONTAINING_RECORD(current_entry, KAPC, ApcListEntry);
   
   /*
    * Save the thread's current context (in other words the registers
    * that will be restored when it returns to user mode) so the
    * APC dispatcher can restore them later
    */
   Context = (PCONTEXT)(((PUCHAR)TrapFrame->Esp) - sizeof(CONTEXT));
   memset(Context, 0, sizeof(CONTEXT));
   Context->ContextFlags = CONTEXT_CONTROL | CONTEXT_INTEGER | 
     CONTEXT_SEGMENTS | CONTEXT_i386;
   Context->SegGs = TrapFrame->Gs;
   Context->SegFs = TrapFrame->Fs;
   Context->SegEs = TrapFrame->Es;
   Context->SegDs = TrapFrame->Ds;
   Context->Edi = TrapFrame->Edi;
   Context->Esi = TrapFrame->Esi;
   Context->Ebx = TrapFrame->Ebx;
   Context->Edx = TrapFrame->Edx;
   Context->Ecx = TrapFrame->Ecx;
   Context->Eax = TrapFrame->Eax;
   Context->Ebp = TrapFrame->Ebp;
   Context->Eip = TrapFrame->Eip;
   Context->SegCs = TrapFrame->Cs;
   Context->EFlags = TrapFrame->Eflags;
   Context->Esp = TrapFrame->Esp;
   Context->SegSs = TrapFrame->Ss;
   
   /*
    * Setup the trap frame so the thread will start executing at the
    * APC Dispatcher when it returns to user-mode
    */
   Esp = (PULONG)(((PUCHAR)TrapFrame->Esp) - 
		  (sizeof(CONTEXT) + (6 * sizeof(ULONG))));
   
   Esp[0] = 0xdeadbeef;
   Esp[1] = (ULONG)Apc->NormalRoutine;
   Esp[2] = (ULONG)Apc->NormalContext;
   Esp[3] = (ULONG)Apc->SystemArgument1;
   Esp[4] = (ULONG)Apc->SystemArgument2;
   Esp[5] = (ULONG)Context;
   TrapFrame->Eip = (ULONG)LdrpGetSystemDllApcDispatcher();
   TrapFrame->Esp = (ULONG)Esp;     
   
   /*
    * We've dealt with one pending user-mode APC
    */
   Thread->ApcState.UserApcPending--;
   
   /*
    * FIXME: Give some justification for this
    */
   KeReleaseSpinLock(&PiApcLock, oldlvl);
       
   /*
    * Now call for the kernel routine for the APC, which will free
    * the APC data structure, we can't do this ourselves because
    * the APC may be embedded in some larger structure e.g. an IRP
    * We also give the kernel routine a last chance to modify the arguments to 
    * the user APC routine.
    */
   Apc->KernelRoutine(Apc,
		      (PKNORMAL_ROUTINE*)&Esp[1],
		      (PVOID*)&Esp[2],
		      (PVOID*)&Esp[3],
		      (PVOID*)&Esp[4]);
   
   Thread->Alerted[0] = 0;
   return(TRUE);
}

VOID STDCALL KiDeliverApc(ULONG Unknown1,
			  ULONG Unknown2,
			  ULONG Unknown3)
/*
 * FUNCTION: Deliver an APC to the current thread.
 * NOTES: This is called from the IRQL switching code if the current thread
 * is returning from an IRQL greater than or equal to APC_LEVEL to 
 * PASSIVE_LEVEL and there are kernel-mode APCs pending. This means any
 * pending APCs will be delivered after a thread gets a new quantum and
 * after it wakes from a wait. 
 */
{
   PETHREAD Thread = PsGetCurrentThread();
   PLIST_ENTRY current;
   PKAPC Apc;
   KIRQL oldlvl;

   DPRINT("KiDeliverApc()\n");
   KeAcquireSpinLock(&PiApcLock, &oldlvl);
   while(!IsListEmpty(&(Thread->Tcb.ApcState.ApcListHead[0])))
   {
     current = Thread->Tcb.ApcState.ApcListHead[0].Blink;
     Apc = CONTAINING_RECORD(current, KAPC, ApcListEntry);
     if (Apc->NormalRoutine == NULL)
       {
	 (void)RemoveTailList(&Thread->Tcb.ApcState.ApcListHead[0]);
	 Thread->Tcb.ApcState.KernelApcInProgress++;
	 Thread->Tcb.ApcState.KernelApcPending--;

	 KeReleaseSpinLock(&PiApcLock, oldlvl);
	 
	 Apc = CONTAINING_RECORD(current, KAPC, ApcListEntry);
	 Apc->KernelRoutine(Apc,
			    &Apc->NormalRoutine,
			    &Apc->NormalContext,
			    &Apc->SystemArgument1,
			    &Apc->SystemArgument2);	 

	 KeAcquireSpinLock(&PiApcLock, &oldlvl);
	 Thread->Tcb.ApcState.KernelApcInProgress--;
       }
   }
   KeReleaseSpinLock(&PiApcLock, oldlvl);
}

VOID STDCALL
KeInsertQueueApc (PKAPC	Apc,
		  PVOID	SystemArgument1,
		  PVOID	SystemArgument2,
		  UCHAR	Mode)
/*
 * FUNCTION: Queues an APC for execution
 * ARGUMENTS:
 *         Apc = APC to be queued
 *         SystemArgument[1-2] = TBD
 *         Mode = TBD
 */
{
   KIRQL oldlvl;
   PKTHREAD TargetThread;
   
   DPRINT("KeInsertQueueApc(Apc %x, SystemArgument1 %x, "
	  "SystemArgument2 %x, Mode %d)\n",Apc,SystemArgument1,
	  SystemArgument2,Mode);
   
   KeAcquireSpinLock(&PiApcLock, &oldlvl);
   
   Apc->SystemArgument1 = SystemArgument1;
   Apc->SystemArgument2 = SystemArgument2;
   
   if (Apc->Inserted)
     {
	DbgPrint("KeInsertQueueApc(): multiple APC insertations\n");
	KeBugCheck(0);
     }
   
   TargetThread = Apc->Thread;
   if (Apc->ApcMode == KernelMode)
     {
	InsertTailList(&TargetThread->ApcState.ApcListHead[0], 
		       &Apc->ApcListEntry);
	TargetThread->ApcState.KernelApcPending++;
     }
   else
     {
	InsertTailList(&TargetThread->ApcState.ApcListHead[1],
		       &Apc->ApcListEntry);
	TargetThread->ApcState.UserApcPending++;
     }
   Apc->Inserted = TRUE;
   
   if (Apc->ApcMode == KernelMode && TargetThread->KernelApcDisable >= 1 &&
       TargetThread->WaitIrql < APC_LEVEL && Apc->NormalRoutine == NULL)
     {
	KeRemoveAllWaitsThread(CONTAINING_RECORD(TargetThread, ETHREAD, Tcb),
			       STATUS_KERNEL_APC);
     }
   if (Apc->ApcMode == KernelMode && Apc->NormalRoutine != NULL)
     {
       TargetThread->Alerted[1] = 1;
       if (TargetThread->Alertable == TRUE &&
	   TargetThread->WaitMode == UserMode)
	 {
	   PETHREAD Thread;

	   Thread = CONTAINING_RECORD(TargetThread, ETHREAD, Tcb);
	   KeRemoveAllWaitsThread(Thread, STATUS_USER_APC);
	 }
     }

   /*
    * For user mode APCs if the thread is already waiting then we wait it
    * up and increment UserApcPending so it will deliver the APC on exit
    * from kernel mode. If the thread isn't waiting then before it
    * enters an alertable, user mode wait then it will check for
    * user mode APCs and if there are any pending then return immediately
    * and they will be delivered on exit from kernel mode
    */
   if (Apc->ApcMode == UserMode && TargetThread->Alertable == TRUE &&
       TargetThread->WaitMode == UserMode)
     {
	NTSTATUS Status;
	
	DPRINT("Resuming thread for user APC\n");
	
	Status = STATUS_USER_APC;
	TargetThread->Alerted[0] = 1;
	KeRemoveAllWaitsThread(CONTAINING_RECORD(TargetThread, ETHREAD, Tcb),
			       STATUS_USER_APC);
     }
   KeReleaseSpinLock(&PiApcLock, oldlvl);
}

BOOLEAN STDCALL
KeRemoveQueueApc (PKAPC Apc)
/*
 * FUNCTION: Removes APC object from the apc queue
 * ARGUMENTS:
 *          Apc = APC to remove
 * RETURNS: TRUE if the APC was in the queue
 *          FALSE otherwise
 * NOTE: This function is not exported.
 */
{
   KIRQL oldIrql;
   PKTHREAD TargetThread;
   
   KeAcquireSpinLockAtDpcLevel(&PiApcLock);
   KeRaiseIrql(HIGH_LEVEL, &oldIrql);
   if (Apc->Inserted == FALSE)
     {
	KeReleaseSpinLock(&PiApcLock, oldIrql);
	return(FALSE);
     }

   TargetThread = Apc->Thread;
   RemoveEntryList(&Apc->ApcListEntry);
   if (Apc->ApcMode == KernelMode)
     {
	TargetThread->ApcState.KernelApcPending--;
     }
   else
     {
	TargetThread->ApcState.UserApcPending--;
     }
   Apc->Inserted = FALSE;

   KeReleaseSpinLock(&PiApcLock, oldIrql);
   return(TRUE);
}


VOID STDCALL
KeInitializeApc (PKAPC			Apc,
		 PKTHREAD		Thread,
		 UCHAR			StateIndex,
		 PKKERNEL_ROUTINE	KernelRoutine,
		 PKRUNDOWN_ROUTINE	RundownRoutine,
		 PKNORMAL_ROUTINE	NormalRoutine,
		 UCHAR			Mode,
		 PVOID			Context)
/*
 * FUNCTION: Initialize an APC object
 * ARGUMENTS:
 *       Apc = Pointer to the APC object to initialized
 *       Thread = Thread the APC is to be delivered to
 *       StateIndex = TBD
 *       KernelRoutine = Routine to be called for a kernel-mode APC
 *       RundownRoutine = Routine to be called if the thread has exited with
 *                        the APC being executed
 *       NormalRoutine = Routine to be called for a user-mode APC
 *       Mode = APC mode
 *       Context = Parameter to be passed to the APC routine
 */
{   
   DPRINT("KeInitializeApc(Apc %x, Thread %x, StateIndex %d, "
	  "KernelRoutine %x, RundownRoutine %x, NormalRoutine %x, Mode %d, "
	  "Context %x)\n",Apc,Thread,StateIndex,KernelRoutine,RundownRoutine,
	  NormalRoutine,Mode,Context);
   memset(Apc, 0, sizeof(KAPC));
   Apc->Thread = Thread;
   Apc->ApcListEntry.Flink = NULL;
   Apc->ApcListEntry.Blink = NULL;
   Apc->KernelRoutine = KernelRoutine;
   Apc->RundownRoutine = RundownRoutine;
   Apc->NormalRoutine = NormalRoutine;
   Apc->NormalContext = Context;
   Apc->Inserted = FALSE;
   Apc->ApcStateIndex = StateIndex;
   if (Apc->NormalRoutine != NULL)
     {
	Apc->ApcMode = Mode;
     }
   else
     {
	Apc->ApcMode = KernelMode;
     }
}

VOID NtQueueApcRundownRoutine(PKAPC Apc)
{
   ExFreePool(Apc);
}

VOID NtQueueApcKernelRoutine(PKAPC Apc,
			     PKNORMAL_ROUTINE* NormalRoutine,
			     PVOID* NormalContext,
			     PVOID* SystemArgument1,
			     PVOID* SystemArgument2)
{
   ExFreePool(Apc);
}

NTSTATUS STDCALL NtQueueApcThread(HANDLE			ThreadHandle,
				  PKNORMAL_ROUTINE	ApcRoutine,
				  PVOID			NormalContext,
				  PVOID			SystemArgument1,
				  PVOID			SystemArgument2)
{
   PKAPC Apc;
   PETHREAD Thread;
   NTSTATUS Status;
   
   Status = ObReferenceObjectByHandle(ThreadHandle,
				      THREAD_ALL_ACCESS, /* FIXME */
				      PsThreadType,
				      UserMode,
				      (PVOID*)&Thread,
				      NULL);
   if (!NT_SUCCESS(Status))
     {
	return(Status);
     }
   
   Apc = ExAllocatePool(NonPagedPool, sizeof(KAPC));
   if (Apc == NULL)
     {
	ObDereferenceObject(Thread);
	return(STATUS_NO_MEMORY);
     }
   
   KeInitializeApc(Apc,
		   &Thread->Tcb,
		   0,
		   NtQueueApcKernelRoutine,
		   NtQueueApcRundownRoutine,
		   ApcRoutine,
		   UserMode,
		   NormalContext);
   KeInsertQueueApc(Apc,
		    SystemArgument1,
		    SystemArgument2,
		    UserMode);
   
   ObDereferenceObject(Thread);
   return(STATUS_SUCCESS);
}


NTSTATUS STDCALL NtTestAlert(VOID)
{
   KiTestAlert();
   return(STATUS_SUCCESS);
}

VOID PiInitApcManagement(VOID)
{
   KeInitializeSpinLock(&PiApcLock);
}

