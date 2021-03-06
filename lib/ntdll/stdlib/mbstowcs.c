/* $Id: mbstowcs.c,v 1.1 1999/12/30 14:38:54 ekohl Exp $
 *
 * COPYRIGHT:       See COPYING in the top level directory
 * PROJECT:         ReactOS kernel
 * FILE:            lib/ntdll/stdlib/mbstowcs.c
 * PURPOSE:         converts a multi byte string to a unicode string
 */

#include <ddk/ntddk.h>
#include <stdlib.h>
#include <string.h>

size_t mbstowcs (wchar_t *wcstr, const char *mbstr, size_t count)
{
	NTSTATUS Status;
	ULONG Size;
	ULONG Length;

	Length = strlen (mbstr);

	if (wcstr == NULL)
	{
		RtlMultiByteToUnicodeSize (&Size,
		                           (char *)mbstr,
		                           Length);

		return (size_t)Size;
	}

	Status = RtlMultiByteToUnicodeN (wcstr,
	                                 count,
	                                 &Size,
	                                 (char *)mbstr,
	                                 Length);
	if (!NT_SUCCESS(Status))
		return -1;

	return (size_t)Size;
}

/* EOF */