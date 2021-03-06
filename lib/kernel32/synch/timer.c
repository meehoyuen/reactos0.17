/* $Id: timer.c,v 1.7 2001/01/27 19:35:04 ekohl Exp $
 *
 * COPYRIGHT:            See COPYING in the top level directory
 * PROJECT:              ReactOS kernel
 * FILE:                 lib/kernel32/mem/timer.c
 * PURPOSE:              Implementing timer
 * PROGRAMMER:           
 */

/* INCLUDES ******************************************************************/

#include <ddk/ntddk.h>
#include <kernel32/error.h>
#include <windows.h>

/* FUNCTIONS *****************************************************************/

HANDLE
STDCALL
CreateWaitableTimerW (
	LPSECURITY_ATTRIBUTES	lpTimerAttributes,
	WINBOOL			bManualReset,
	LPWSTR			lpTimerName
	)
{
   NTSTATUS errCode;
   HANDLE TimerHandle;
   OBJECT_ATTRIBUTES ObjectAttributes;
   UNICODE_STRING UnicodeName;

   ULONG TimerType;
   
   if (bManualReset)
     TimerType = 1;
   else
     TimerType = 2;

   RtlInitUnicodeString(&UnicodeName, lpTimerName);
   InitializeObjectAttributes(&ObjectAttributes,
			      &UnicodeName,
			      0,
			      NULL,
			      NULL);
   //TIMER_ALL_ACCESS
   errCode = NtCreateTimer(&TimerHandle,
			   0,
			   &ObjectAttributes,
			   TimerType);

   return TimerHandle;
}


HANDLE
STDCALL
CreateWaitableTimerA (
	LPSECURITY_ATTRIBUTES	lpTimerAttributes,
	WINBOOL			bManualReset,
	LPCSTR			lpTimerName
	)
{
	UNICODE_STRING TimerNameU;
	ANSI_STRING TimerName;
	HANDLE TimerHandle;

	RtlInitAnsiString (&TimerName,
	                   (LPSTR)lpTimerName);
	RtlAnsiStringToUnicodeString (&TimerNameU,
	                              &TimerName,
	                              TRUE);

	TimerHandle = CreateWaitableTimerW (lpTimerAttributes,
	                                    bManualReset,
	                                    TimerNameU.Buffer);

	RtlFreeUnicodeString (&TimerNameU);

	return TimerHandle;
}


HANDLE
STDCALL
OpenWaitableTimerW (
	DWORD	dwDesiredAccess,
	WINBOOL	bInheritHandle,
	LPCWSTR	lpTimerName
	)
{
	NTSTATUS errCode;

	HANDLE TimerHandle;
	OBJECT_ATTRIBUTES ObjectAttributes;
	UNICODE_STRING UnicodeName;
	ULONG Attributes = 0;

	if ( bInheritHandle )
		Attributes = OBJ_INHERIT;

	RtlInitUnicodeString(&UnicodeName, lpTimerName);
	InitializeObjectAttributes(&ObjectAttributes,
			      &UnicodeName,
			      Attributes,
			      NULL,
			      NULL);

	errCode = NtOpenTimer(
		&TimerHandle,
		dwDesiredAccess,
		&ObjectAttributes
	);

	return TimerHandle;
}


HANDLE
STDCALL
OpenWaitableTimerA (
	DWORD dwDesiredAccess,
	WINBOOL bInheritHandle,
	LPCSTR lpTimerName
	)
{
	UNICODE_STRING TimerNameU;
	ANSI_STRING TimerName;
	HANDLE TimerHandle;

	RtlInitAnsiString (&TimerName,
	                   (LPSTR)lpTimerName);
	RtlAnsiStringToUnicodeString (&TimerNameU,
	                              &TimerName,
	                              TRUE);

	TimerHandle = OpenWaitableTimerW (dwDesiredAccess,
	                                  bInheritHandle,
	                                  TimerNameU.Buffer);

	RtlFreeUnicodeString (&TimerNameU);

	return TimerHandle;
}


WINBOOL STDCALL SetWaitableTimer(
  HANDLE hTimer,
  const LARGE_INTEGER *pDueTime,
  LONG lPeriod,
  PTIMERAPCROUTINE pfnCompletionRoutine,
  LPVOID lpArgToCompletionRoutine,
  WINBOOL fResume
)
{
	NTSTATUS errCode;
	BOOLEAN pState;

	errCode = NtSetTimer(hTimer, (LARGE_INTEGER *)pDueTime,
		 pfnCompletionRoutine,
		lpArgToCompletionRoutine, fResume, lPeriod, &pState);

	if ( !NT_SUCCESS(errCode) ) {
		SetLastErrorByStatus (errCode);
		return FALSE;
	}
	return TRUE;
}

WINBOOL STDCALL CancelWaitableTimer(HANDLE hTimer)
{
	NTSTATUS errCode;
	BOOLEAN CurrentState;

	errCode = NtCancelTimer(
		hTimer,
		&CurrentState
	);
	if ( !NT_SUCCESS(errCode) ) {
		SetLastErrorByStatus (errCode);
		return FALSE;
	}
	return TRUE;
}

/* EOF */
