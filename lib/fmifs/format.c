/* $Id: format.c,v 1.1 1999/05/11 21:19:41 ea Exp $
 *
 * COPYING:	See the top level directory
 * PROJECT:	ReactOS 
 * FILE:	reactos/lib/fmifs/format.c
 * DESCRIPTION:	File management IFS utility functions
 * PROGRAMMER:	Emanuele Aliberti
 * UPDATED
 * 	1999-02-16 (Emanuele Aliberti)
 * 		Entry points added.
 */
#define UNICODE
#define _UNICODE
#include <windows.h>
#include <fmifs.h>

/* FMIFS.6 */
VOID
__stdcall
Format(VOID)
{
}


/* FMIFS.7 */
VOID
__stdcall
FormatEx(
	PWCHAR		DriveRoot,
	DWORD		MediaFlag,
	PWCHAR		Format,
	PWCHAR		Label,
	BOOL		QuickFormat,
	DWORD		ClusterSize,
	PFMIFSCALLBACK	Callback
	)
{
	BOOL	Argument = FALSE;

	/* FAIL immediately */
	Callback(
		DONE,		/* Command */
		0,		/* DWORD Modifier */
		& Argument	/* Argument */
		);
}


/* EOF */
