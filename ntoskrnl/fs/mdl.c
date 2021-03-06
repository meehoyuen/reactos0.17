/* $Id: mdl.c,v 1.1 2000/03/05 19:17:42 ea Exp $
 *
 * reactos/ntoskrnl/fs/mdl.c
 *
 */
#include <ntos.h>
#include <internal/cc.h>
#include <ddk/ntifs.h>

/**********************************************************************
 * NAME							EXPORTED
 *	FsRtlMdlRead@24
 *
 * DESCRIPTION
 *	
 * ARGUMENTS
 *
 * RETURN VALUE
 *
 */
BOOLEAN
STDCALL
FsRtlMdlRead (
	DWORD	Unknown0,
	DWORD	Unknown1,
	DWORD	Unknown2,
	DWORD	Unknown3,
	DWORD	Unknown4,
	DWORD	Unknown5
	)
{
	return FALSE; /* FIXME: call FsRtlMdlReadDev ? */
}


/**********************************************************************
 * NAME							EXPORTED
 *	FsRtlMdlReadComplete@8
 *
 * DESCRIPTION
 *	
 * ARGUMENTS
 *
 * RETURN VALUE
 *
 */
BOOLEAN
STDCALL
FsRtlMdlReadComplete (
	IN	PFILE_OBJECT	FileObject,
	IN OUT	PMDL		Mdl
	)
{
	PDEVICE_OBJECT	DeviceObject [2] = {NULL};
	PDRIVER_OBJECT	DriverObject = NULL;

	/*
	 * Try fast I/O first
	 */
	DeviceObject [0] = IoGetRelatedDeviceObject (FileObject);
	DriverObject = DeviceObject [0]->DriverObject;
	if (NULL != DriverObject->FastIoDispatch)
	{
#if 0
		if (IRP_MJ_READ <= DriverObject->FastIoDispatch->Count)
		{
			return FALSE;
		}
		if (NULL == DriverObject->FastIoDispatch->Dispatch [IRP_MJ_READ])
		{
			return FALSE;
		}
		return DriverObject->FastIoDispatch->Dispatch
			[IRP_MJ_READ] (
				Mdl,
				NULL /* FIXME: how to get the IRP? */
				);
#endif
	}
	/*
	 * Default I/O path
	 */
	DeviceObject [1] = IoGetBaseFileSystemDeviceObject (FileObject);
	/*
	 * Did IoGetBaseFileSystemDeviceObject ()
	 * returned the same device
	 * IoGetRelatedDeviceObject () returned?
	 */
	if (DeviceObject [1] != DeviceObject [0])
	{
#if 0
		DriverObject = DeviceObject [1]->DriverObject;
		if (NULL != DriverObject->FastIoDispatch)
		{
			/* 
			 * Check if the driver provides
			 * IRP_MJ_READ.
			 */
			if (IRP_MJ_READ <= DriverObject->FastIoDispatch->Count)
			{
				if (NULL == DriverObject->FastIoDispatch->Dispatch [IRP_MJ_READ])
				{
					return FALSE;
				}
			}
		}
#endif
		DeviceObject [0] = DeviceObject [1];
	}
	return FsRtlMdlReadCompleteDev (
			FileObject,
			Mdl,
			DeviceObject [0]
			);
}


/**********************************************************************
 * NAME							EXPORTED
 *	FsRtlMdlReadCompleteDev@12
 *
 * DESCRIPTION
 *	
 * ARGUMENTS
 *
 * RETURN VALUE
 *
 * NOTE
 * 	From Bo Branten's ntifs.h v13.
 * 	(CcMdlReadCompleteDev declared in internal/cc.h)
 */
BOOLEAN
STDCALL
FsRtlMdlReadCompleteDev (
	IN	PFILE_OBJECT	FileObject,
	IN	PMDL		MdlChain,
	IN	PDEVICE_OBJECT	DeviceObject
	)
{
	FileObject = FileObject; /* unused parameter */
	CcMdlReadCompleteDev (MdlChain, DeviceObject);
	return TRUE;
}


/**********************************************************************
 * NAME							EXPORTED
 *	FsRtlMdlReadDev@28
 *
 * DESCRIPTION
 *	
 * ARGUMENTS
 *
 * RETURN VALUE
 *
 */
BOOLEAN
STDCALL
FsRtlMdlReadDev (
	DWORD	Unknown0,
	DWORD	Unknown1,
	DWORD	Unknown2,
	DWORD	Unknown3,
	DWORD	Unknown4,
	DWORD	Unknown5,
	DWORD	Unknown6
	)
{
	return FALSE;
}


/**********************************************************************
 * NAME							EXPORTED
 *	FsRtlMdlWriteComplete@12
 *
 * DESCRIPTION
 *	
 * ARGUMENTS
 *
 * RETURN VALUE
 *
 */
BOOLEAN
STDCALL
FsRtlMdlWriteComplete (
	IN	PFILE_OBJECT	FileObject,
	IN	PLARGE_INTEGER	FileOffset,
	IN	PMDL		MdlChain
	)
{
	return FALSE; /* FIXME: call FsRtlMdlWriteCompleteDev ? */
}


/**********************************************************************
 * NAME							EXPORTED
 *	FsRtlMdlWriteCompleteDev@16
 *
 * DESCRIPTION
 *	
 * ARGUMENTS
 *
 * RETURN VALUE
 *
 */
BOOLEAN
STDCALL
FsRtlMdlWriteCompleteDev (
	IN	PFILE_OBJECT	FileObject,
	IN	PLARGE_INTEGER	FileOffset,
	IN	PMDL		MdlChain,
	IN	PDEVICE_OBJECT	DeviceObject
	)
{
	return FALSE;
}


/**********************************************************************
 * NAME							EXPORTED
 *	FsRtlPrepareMdlWrite@24
 *
 * DESCRIPTION
 *	
 * ARGUMENTS
 *
 * RETURN VALUE
 *
 */
BOOLEAN
STDCALL
FsRtlPrepareMdlWrite (
	DWORD	Unknown0,
	DWORD	Unknown1,
	DWORD	Unknown2,
	DWORD	Unknown3,
	DWORD	Unknown4,
	DWORD	Unknown5
	)
{
	return FALSE; /* call FsRtlPrepareMdlWriteDev ? */
}


/**********************************************************************
 * NAME							EXPORTED
 *	FsRtlPrepareMdlWriteDev@28
 *
 * DESCRIPTION
 *	
 * ARGUMENTS
 *
 * RETURN VALUE
 *
 */
BOOLEAN
STDCALL
FsRtlPrepareMdlWriteDev (
	DWORD	Unknown0,
	DWORD	Unknown1,
	DWORD	Unknown2,
	DWORD	Unknown3,
	DWORD	Unknown4,
	DWORD	Unknown5,
	DWORD	Unknown6
	)
{
	return FALSE;
}


/* EOF */
