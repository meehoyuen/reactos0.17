/* $Id: mdl.c,v 1.5 2000/03/26 19:38:25 ea Exp $
 *
 * COPYRIGHT:       See COPYING in the top level directory
 * PROJECT:         ReactOS kernel
 * FILE:            ntoskrnl/io/mdl.c
 * PURPOSE:         Io manager mdl functions
 * PROGRAMMER:      David Welch (welch@mcmail.com)
 * UPDATE HISTORY:
 *                  Created 22/05/98
 */

/* INCLUDES *****************************************************************/

#include <ddk/ntddk.h>
#include <internal/mmhal.h>

#include <internal/debug.h>

/* FUNCTIONS *****************************************************************/

PMDL
STDCALL
IoAllocateMdl(PVOID VirtualAddress,
		   ULONG Length,
		   BOOLEAN SecondaryBuffer,
		   BOOLEAN ChargeQuota,
		   PIRP Irp)
{
   PMDL Mdl;
   
   if (ChargeQuota)
     {
//	Mdl = ExAllocatePoolWithQuota(NonPagedPool,
//				      MmSizeOfMdl(VirtualAddress,Length));
	Mdl = ExAllocatePool(NonPagedPool,MmSizeOfMdl(VirtualAddress,Length));
     }
   else
     {
	Mdl = ExAllocatePool(NonPagedPool,MmSizeOfMdl(VirtualAddress,Length));
     }
   MmInitializeMdl(Mdl,VirtualAddress,Length);
   if (Irp!=NULL && !SecondaryBuffer)
     {
	Irp->MdlAddress = Mdl;
     }
   return(Mdl);
}

VOID
STDCALL
IoBuildPartialMdl(PMDL SourceMdl,
		       PMDL TargetMdl,
		       PVOID VirtualAddress,
		       ULONG Length)
{
   PULONG TargetPages = (PULONG)(TargetMdl + 1);
   PULONG SourcePages = (PULONG)(SourceMdl + 1);
   ULONG Va;
   ULONG Delta = (PAGE_ROUND_DOWN(VirtualAddress) - (ULONG)SourceMdl->StartVa)/
                 PAGESIZE;

   for (Va = 0; Va < (PAGE_ROUND_UP(Length)/PAGESIZE); Va++)
     {
	TargetPages[Va] = SourcePages[Va+Delta];
     }
}

VOID
STDCALL
IoFreeMdl(PMDL Mdl)
{   
   MmUnmapLockedPages(MmGetSystemAddressForMdl(Mdl),Mdl);
   MmUnlockPages(Mdl);
   ExFreePool(Mdl);
}


/* EOF */
