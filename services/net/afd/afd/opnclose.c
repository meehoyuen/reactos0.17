/*
 * COPYRIGHT:   See COPYING in the top level directory
 * PROJECT:     ReactOS Ancillary Function Driver
 * FILE:        afd/opnclose.c
 * PURPOSE:     File object creation and destruction
 * PROGRAMMERS: Casper S. Hornstrup (chorns@users.sourceforge.net)
 * REVISIONS:
 *   CSH 01/09-2000 Created
 */
#include <afd.h>

PAFDFCB AfdInitializeFCB(
    PDEVICE_EXTENSION   DeviceExt,
    PFILE_OBJECT        FileObject  OPTIONAL)
/*
 * FUNCTION: Allocates and initializes a File Control Block structure
 */
{
    PAFDFCB NewFCB;

    NewFCB = ExAllocatePool(NonPagedPool, sizeof(AFDFCB));
    if (!NewFCB)
        return NULL;

    RtlZeroMemory(NewFCB, sizeof(AFDFCB));

	ExInitializeResourceLite(&NewFCB->NTRequiredFCB.MainResource);
	ExInitializeResourceLite(&NewFCB->NTRequiredFCB.PagingIoResource);

	NewFCB->DeviceExt       = DeviceExt;
	NewFCB->ReferenceCount  = 1;
	NewFCB->OpenHandleCount = 1;

    NewFCB->TdiAddressObjectHandle    = INVALID_HANDLE_VALUE;
    NewFCB->TdiConnectionObjectHandle = INVALID_HANDLE_VALUE;

    InitializeListHead(&NewFCB->CCBListHead);

    InsertTailList(&DeviceExt->FCBListHead, &NewFCB->ListEntry);

	if (FileObject)
		FileObject->FsContext = (PVOID)&NewFCB->NTRequiredFCB;

    return NewFCB;
}


PAFDCCB AfdInitializeCCB(
    PAFDFCB         FCB,
    PFILE_OBJECT    FileObject)
/*
 * FUNCTION: Allocates and initializes a Context Control Block structure
 */
{
    PAFDCCB NewCCB;

    NewCCB = ExAllocatePool(NonPagedPool, sizeof(AFDCCB));
    if (!NewCCB)
        return NULL;

    RtlZeroMemory(NewCCB, sizeof(AFDCCB));

    NewCCB->FileObject = FileObject;

    FileObject->FsContext2 = (PVOID)NewCCB;

    InsertTailList(&FCB->CCBListHead, &NewCCB->ListEntry);

    return NewCCB;
}


NTSTATUS AfdCreate(
    PDEVICE_OBJECT DeviceObject,
    PIRP Irp)
{
    PAFD_SOCKET_INFORMATION SocketInfo;
    PFILE_FULL_EA_INFORMATION EaInfo;
    PDEVICE_EXTENSION DeviceExt;
    PTA_ADDRESS Address;
    NTSTATUS Status;
    ULONG EaLength;
    PAFDFCB FCB;
    PAFDCCB CCB;
    PIO_STACK_LOCATION IrpSp = IoGetCurrentIrpStackLocation(Irp);
    PFILE_OBJECT FileObject  = IrpSp->FileObject;

    AFD_DbgPrint(MIN_TRACE, ("Called.\n"));

    DeviceExt = DeviceObject->DeviceExtension;

    EaInfo = Irp->AssociatedIrp.SystemBuffer;

    /* Parameter check */
    if (!EaInfo) {
        AFD_DbgPrint(MIN_TRACE, ("No EA information in IRP.\n"));
        return STATUS_INVALID_PARAMETER;
    }

    SocketInfo = (PAFD_SOCKET_INFORMATION)(EaInfo->EaName + EaInfo->EaNameLength);

    EaLength = sizeof(FILE_FULL_EA_INFORMATION) +
               EaInfo->EaNameLength +
               EaInfo->EaValueLength;

    if (EaLength < sizeof(FILE_FULL_EA_INFORMATION) +
        AFD_SOCKET_LENGTH + sizeof(AFD_SOCKET_INFORMATION)) {
        AFD_DbgPrint(MIN_TRACE, ("EA information has invalid length.\n"));
        return STATUS_INVALID_PARAMETER;
    }

    AFD_DbgPrint(MAX_TRACE, ("EaInfo at (0x%X)  length is (%d).\n", EaInfo, EaLength));

    /* FIXME: File/socket could already be open, do a search for it */

    FCB = AfdInitializeFCB(DeviceExt, FileObject);
    CCB = AfdInitializeCCB(FCB, FileObject);
    if (CCB && FCB) {
        FCB->AddressFamily      = SocketInfo->AddressFamily;
        FCB->SocketType         = SocketInfo->SocketType;
        FCB->Protocol           = SocketInfo->Protocol;
        FCB->HelperContext      = SocketInfo->HelperContext;
        FCB->NotificationEvents = SocketInfo->NotificationEvents;
        RtlCopyUnicodeString(&FCB->TdiDeviceName, &SocketInfo->TdiDeviceName);
    } else {
        Status = STATUS_INSUFFICIENT_RESOURCES;
    }

    if (!NT_SUCCESS(Status)) {
        /* FIXME: Cleanup */
    }

    Irp->IoStatus.Status = Status;
    Irp->IoStatus.Information = 0;

    IoCompleteRequest(Irp, IO_NO_INCREMENT);

    AFD_DbgPrint(MIN_TRACE, ("Leaving. Status (0x%X).\n", Status));

    return Status;
}


NTSTATUS AfdClose(
    PDEVICE_OBJECT DeviceObject,
    PIRP Irp)
{
    PIO_STACK_LOCATION IrpSp = IoGetCurrentIrpStackLocation(Irp);
    PFILE_OBJECT FileObject  = IrpSp->FileObject;
    NTSTATUS Status;
    PAFDFCB FCB;
    PAFDCCB CCB;

    FCB = FileObject->FsContext;
    CCB = FileObject->FsContext2;

    AFD_DbgPrint(MIN_TRACE, ("Called.\n"));

    switch (IrpSp->MajorFunction) {
    /* Close a file object */
    case IRP_MJ_CLOSE:
        FCB->ReferenceCount--;
        if (FCB->ReferenceCount < 1) {
            /* Close TDI connection file object */
            if (FCB->TdiConnectionObjectHandle != INVALID_HANDLE_VALUE) {
                TdiCloseDevice(FCB->TdiConnectionObjectHandle, FCB->TdiConnectionObject);
                FCB->TdiConnectionObjectHandle = INVALID_HANDLE_VALUE;
            }

            /* Close TDI address file object */
            if (FCB->TdiAddressObjectHandle != INVALID_HANDLE_VALUE) {
                AfdDeregisterEventHandlers(FCB);
                TdiCloseDevice(FCB->TdiAddressObjectHandle, FCB->TdiAddressObject);
                FCB->TdiAddressObjectHandle = INVALID_HANDLE_VALUE;
            }

            ExFreePool(FCB);
        }

        Status = STATUS_SUCCESS;
        break;

    /* Release resources bound to a file object */
    case IRP_MJ_CLEANUP:
        FCB->OpenHandleCount--;
        Status = STATUS_SUCCESS;
        break;

	default:
        Status = STATUS_INVALID_DEVICE_REQUEST;
    }

    ExFreePool(CCB);

    Irp->IoStatus.Status = Status;
    Irp->IoStatus.Information = 0;

    IoCompleteRequest(Irp, IO_NO_INCREMENT);
    return Status;
}

/* EOF */
