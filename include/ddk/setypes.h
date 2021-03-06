/* $Id: setypes.h,v 1.5 2000/06/29 23:35:12 dwelch Exp $
 *
 * COPYRIGHT:         See COPYING in the top level directory for details
 * PROJECT:           ReactOS kernel
 * FILE:              include/ddk/setypes.h
 * PURPOSE:           Security manager types
 * REVISION HISTORY:
 *                 ??/??/??:    Created with empty stubs by David Welch
 *                 29/08/98:    ACCESS_TOKEN definition from Boudewijn Dekker
 */

#ifndef __INCLUDE_DDK_SETYPES_H
#define __INCLUDE_DDK_SETYPES_H

#include <ntos/security.h>

/* SID */
#define SECURITY_NULL_RID	(0L)
#define SECURITY_WORLD_RID	(0L)
#define SECURITY_LOCAL_RID	(0L)
#define SECURITY_CREATOR_OWNER_RID	(0L)
#define SECURITY_CREATOR_GROUP_RID	(0x1L)
#define SECURITY_DIALUP_RID	(0x1L)
#define SECURITY_NETWORK_RID	(0x2L)
#define SECURITY_BATCH_RID	(0x3L)
#define SECURITY_INTERACTIVE_RID	(0x4L)
#define SECURITY_LOGON_IDS_RID	(0x5L)
#define SECURITY_LOGON_IDS_RID_COUNT	(0x3L)
#define SECURITY_SERVICE_RID	(0x6L)
#define SECURITY_LOCAL_SYSTEM_RID	(0x12L)
#define SECURITY_BUILTIN_DOMAIN_RID	(0x20L)
#define DOMAIN_USER_RID_ADMIN	(0x1f4L)
#define DOMAIN_USER_RID_GUEST	(0x1f5L)
#define DOMAIN_GROUP_RID_ADMINS	(0x200L)
#define DOMAIN_GROUP_RID_USERS	(0x201L)
#define DOMAIN_ALIAS_RID_ADMINS	(0x220L)
#define DOMAIN_ALIAS_RID_USERS	(0x221L)
#define DOMAIN_ALIAS_RID_GUESTS	(0x222L)
#define DOMAIN_ALIAS_RID_POWER_USERS	(0x223L)
#define DOMAIN_ALIAS_RID_ACCOUNT_OPS	(0x224L)
#define DOMAIN_ALIAS_RID_SYSTEM_OPS	(0x225L)
#define DOMAIN_ALIAS_RID_PRINT_OPS	(0x226L)
#define DOMAIN_ALIAS_RID_BACKUP_OPS	(0x227L)
#define DOMAIN_ALIAS_RID_REPLICATOR	(0x228L)

/* TOKEN_GROUPS structure */
#define SE_GROUP_MANDATORY	(0x1L)
#define SE_GROUP_ENABLED_BY_DEFAULT	(0x2L)
#define SE_GROUP_ENABLED	(0x4L)
#define SE_GROUP_OWNER	(0x8L)
#define SE_GROUP_LOGON_ID	(0xc0000000L)

/* ACL Defines */
#define ACL_REVISION  (2)

/* ACE_HEADER structure */
#define ACCESS_ALLOWED_ACE_TYPE      (0x0)
#define ACCESS_DENIED_ACE_TYPE       (0x1)
#define SYSTEM_AUDIT_ACE_TYPE        (0x2)
#define SYSTEM_ALARM_ACE_TYPE        (0x3)

/* ACE flags in the ACE_HEADER structure */
#define OBJECT_INHERIT_ACE           (0x1)
#define CONTAINER_INHERIT_ACE        (0x2)
#define NO_PROPAGATE_INHERIT_ACE     (0x4)
#define INHERIT_ONLY_ACE             (0x8)
#define SUCCESSFUL_ACCESS_ACE_FLAG   (0x40)
#define FAILED_ACCESS_ACE_FLAG       (0x80)

/* SECURITY_DESCRIPTOR_CONTROL */
#define SECURITY_DESCRIPTOR_REVISION	(1)
#define SECURITY_DESCRIPTOR_MIN_LENGTH	(20)
#define SE_OWNER_DEFAULTED	(1)
#define SE_GROUP_DEFAULTED	(2)
#define SE_DACL_PRESENT	(4)
#define SE_DACL_DEFAULTED	(8)
#define SE_SACL_PRESENT	(16)
#define SE_SACL_DEFAULTED	(32)
#define SE_SELF_RELATIVE	(32768)

/* PRIVILEGE_SET */
#define SE_PRIVILEGE_ENABLED_BY_DEFAULT	(0x1L)
#define SE_PRIVILEGE_ENABLED	(0x2L)
#define SE_PRIVILEGE_USED_FOR_ACCESS	(0x80000000L)
#define PRIVILEGE_SET_ALL_NECESSARY	(0x1)

typedef struct _ACCESS_TOKEN 
{
   TOKEN_SOURCE			TokenSource;               // 0x00
   LUID                         TokenId;                   // 0x10
   LUID				AuthenticationId;          // 0x18
   LARGE_INTEGER		ExpirationTime;            // 0x20
   LUID				ModifiedId;                // 0x28
   ULONG			UserAndGroupCount;         // 0x30
   ULONG			PrivilegeCount;            // 0x34
   ULONG			VariableLength;            // 0x38
   ULONG			DynamicCharged;            // 0x3C
   ULONG			DynamicAvailable;          // 0x40
   ULONG                        DefaultOwnerIndex;         // 0x44
   PSID_AND_ATTRIBUTES          UserAndGroups;             // 0x48
   PSID                         PrimaryGroup;              // 0x4C
   PLUID_AND_ATTRIBUTES         Privileges;                // 0x50
   ULONG                        Unknown1;                  // 0x54
   PACL				DefaultDacl;               // 0x58
   TOKEN_TYPE			TokenType;                         // 0x5C
   SECURITY_IMPERSONATION_LEVEL 	ImpersonationLevel;        // 0x60
   UCHAR				TokenFlags;                // 0x64
   UCHAR				TokenInUse;                // 0x65
   UCHAR				Unused[2];                 // 0x66
   PVOID				ProxyData;                 // 0x68
   PVOID				AuditData;                 // 0x6c
   UCHAR				VariablePart[0];           // 0x70
} ACCESS_TOKEN, *PACCESS_TOKEN;


typedef struct _SECURITY_SUBJECT_CONTEXT
{
   PACCESS_TOKEN ClientToken;                              // 0x0
   SECURITY_IMPERSONATION_LEVEL ImpersonationLevel;        // 0x4
   PACCESS_TOKEN PrimaryToken;                             // 0x8
   PVOID ProcessAuditId;                                   // 0xC
} SECURITY_SUBJECT_CONTEXT, *PSECURITY_SUBJECT_CONTEXT;

BOOLEAN STDCALL RtlValidSid (PSID Sid);
/*
 * from ntoskrnl/se/token.c:
 */
extern struct _OBJECT_TYPE* SeTokenType;

typedef struct
{
   ULONG Unknown1;                                 // 0x0
   SECURITY_IMPERSONATION_LEVEL Level;             // 0x4
   UCHAR ContextTrackingMode;                      // 0x8
   UCHAR EffectiveOnly;                            // 0x9
   UCHAR Unknown5;                                 // 0xa
   UCHAR Unknown6;                                 // 0xb
   PACCESS_TOKEN Token;                            // 0xc
   UCHAR Unknown8;                                 // 0x10
   UCHAR Unknown9;                                 // 0x11
   UCHAR Unknown10;                                // 0x12
   UCHAR Pad[1];                                   // 0x13
   ULONG Unknown11;                                // 0x14
} SE_SOME_STRUCT2, *PSE_SOME_STRUCT2;



#endif
