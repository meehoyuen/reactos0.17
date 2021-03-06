/*
 * nls/cp852.c
 * Copyright (C) 1996, Onno Hovers
 * 
 * This file has been generated by gencp.exe
 */

#include <windows.h>
#include <kernel32/nls.h>


WCHAR __CP852_00[32]=
{
   0x0000, 0x263A, 0x263B, 0x2665, 0x2666, 0x2663, 0x2660, 0x2022, 
   0x25D8, 0x25CB, 0x25D9, 0x2642, 0x2640, 0x266A, 0x266B, 0x263C, 
   0x25BA, 0x25C4, 0x2195, 0x203C, 0x00B6, 0x00A7, 0x25AC, 0x21A8, 
   0x2191, 0x2193, 0x2192, 0x2190, 0x221F, 0x2194, 0x25B2, 0x25BC, 
};

WCHAR __CP852_60[32]=
{
   0x0060, 0x0061, 0x0062, 0x0063, 0x0064, 0x0065, 0x0066, 0x0067, 
   0x0068, 0x0069, 0x006A, 0x006B, 0x006C, 0x006D, 0x006E, 0x006F, 
   0x0070, 0x0071, 0x0072, 0x0073, 0x0074, 0x0075, 0x0076, 0x0077, 
   0x0078, 0x0079, 0x007A, 0x007B, 0x007C, 0x007D, 0x007E, 0x2302, 
};

WCHAR __CP852_80[32]=
{
   0x00C7, 0x00FC, 0x00E9, 0x00E2, 0x00E4, 0x016F, 0x0107, 0x00E7, 
   0x0142, 0x00EB, 0x0150, 0x0151, 0x00EE, 0x0179, 0x00C4, 0x0106, 
   0x00C9, 0x0139, 0x013A, 0x00F4, 0x00F6, 0x013D, 0x013E, 0x015A, 
   0x015B, 0x00D6, 0x00DC, 0x0164, 0x0165, 0x0141, 0x00D7, 0x010D, 
};

WCHAR __CP852_A0[32]=
{
   0x00E1, 0x00ED, 0x00F3, 0x00FA, 0x0104, 0x0105, 0x017D, 0x017E, 
   0x0118, 0x0119, 0x00AC, 0x017A, 0x010C, 0x015F, 0x00AB, 0x00BB, 
   0x2591, 0x2592, 0x2593, 0x2502, 0x2524, 0x00C1, 0x00C2, 0x011A, 
   0x015E, 0x2563, 0x2551, 0x2557, 0x255D, 0x017B, 0x017C, 0x2510, 
};

WCHAR __CP852_C0[32]=
{
   0x2514, 0x2534, 0x252C, 0x251C, 0x2500, 0x253C, 0x0102, 0x0103, 
   0x255A, 0x2554, 0x2569, 0x2566, 0x2560, 0x2550, 0x256C, 0x00A4, 
   0x0111, 0x0110, 0x010E, 0x00CB, 0x010F, 0x0147, 0x00CD, 0x00CE, 
   0x011B, 0x2518, 0x250C, 0x2588, 0x2584, 0x0162, 0x016E, 0x2580, 
};

WCHAR __CP852_E0[32]=
{
   0x00D3, 0x00DF, 0x00D4, 0x0143, 0x0144, 0x0148, 0x0160, 0x0161, 
   0x0154, 0x00DA, 0x0155, 0x0170, 0x00FD, 0x00DD, 0x0163, 0x00B4, 
   0x00AD, 0x02DD, 0x02DB, 0x02C7, 0x02D8, 0x00A7, 0x00F7, 0x00B8, 
   0x00B0, 0x00A8, 0x02D9, 0x0171, 0x0158, 0x0159, 0x25A0, 0x00A0, 
};


WCHAR *__CP852_ToUnicode[8]=
{
   __ASCII_00, __ASCII_20, __ASCII_40, __ASCII_60,
   __CP852_80, __CP852_A0, __CP852_C0, __CP852_E0
};


WCHAR *__CP852_ToUnicodeGlyph[8]=
{
   __CP852_00, __ASCII_20, __ASCII_40, __CP852_60,
   __CP852_80, __CP852_A0, __CP852_C0, __CP852_E0
};


CHAR __CP852_00A0[32]=
{
   0xFF, 0x21, 0x63, 0x4C, 0xCF, 0x59, 0x7C, 0xF5, 
   0xF9, 0x63, 0x61, 0xAE, 0xAA, 0xF0, 0x52, 0xC4, 
   0xF8, 0x2B, 0x32, 0x33, 0xEF, 0x75, 0x14, 0x07, 
   0xF7, 0x31, 0x6F, 0xAF, 0x31, 0x31, 0x33, 0x00, 
};

CHAR __CP852_00C0[32]=
{
   0x41, 0xB5, 0xB6, 0x41, 0x8E, 0x41, 0x41, 0x80, 
   0x45, 0x90, 0x45, 0xD3, 0x49, 0xD6, 0xD7, 0x49, 
   0x00, 0x4E, 0x4F, 0xE0, 0xE2, 0x4F, 0x99, 0x9E, 
   0x4F, 0x55, 0xE9, 0x55, 0x9A, 0xED, 0x00, 0xE1, 
};

CHAR __CP852_00E0[32]=
{
   0x61, 0xA0, 0x83, 0x61, 0x84, 0x61, 0x61, 0x87, 
   0x63, 0x82, 0x65, 0x89, 0x69, 0xA1, 0x8C, 0x69, 
   0x00, 0x6E, 0x6F, 0xA2, 0x93, 0x6F, 0x94, 0xF6, 
   0x6F, 0x75, 0xA3, 0x75, 0x81, 0xEC, 0x00, 0x79, 
};

CHAR __CP852_0100[32]=
{
   0x41, 0x61, 0xC6, 0xC7, 0xA4, 0xA5, 0x8F, 0x86, 
   0x43, 0x63, 0x43, 0x63, 0xAC, 0x9F, 0xD2, 0xD4, 
   0xD1, 0xD0, 0x45, 0x65, 0x45, 0x65, 0x45, 0x65, 
   0xA8, 0xA9, 0xB7, 0xD8, 0x47, 0x67, 0x47, 0x67, 
};

CHAR __CP852_0120[32]=
{
   0x47, 0x67, 0x47, 0x67, 0x48, 0x68, 0x48, 0x68, 
   0x49, 0x69, 0x49, 0x69, 0x49, 0x69, 0x49, 0x69, 
   0x49, 0x69, 0x00, 0x00, 0x4A, 0x6A, 0x4B, 0x6B, 
   0x00, 0x91, 0x92, 0x4C, 0x6C, 0x95, 0x96, 0x00, 
};

CHAR __CP852_0140[32]=
{
   0x00, 0x9D, 0x88, 0xE3, 0xE4, 0x4E, 0x6E, 0xD5, 
   0xE5, 0x00, 0x00, 0x00, 0x4F, 0x6F, 0x4F, 0x6F, 
   0x8A, 0x8B, 0x4F, 0x6F, 0xE8, 0xEA, 0x52, 0x72, 
   0xFC, 0xFD, 0x97, 0x98, 0x53, 0x73, 0xB8, 0xAD, 
};

CHAR __CP852_0160[32]=
{
   0xE6, 0xE7, 0xDD, 0xEE, 0x9B, 0x9C, 0x54, 0x74, 
   0x55, 0x75, 0x55, 0x75, 0x55, 0x75, 0xDE, 0x85, 
   0xEB, 0xFB, 0x55, 0x75, 0x57, 0x77, 0x59, 0x79, 
   0x59, 0x8D, 0xAB, 0xBD, 0xBE, 0xA6, 0xA7, 0x00, 
};

CHAR __CP852_0180[32]=
{
   0x62, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0xD1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x46, 0x66, 0x00, 0x00, 0x00, 0x00, 0x49, 
   0x00, 0x00, 0x6C, 0x00, 0x00, 0x00, 0x00, 0x4F, 
};

CHAR __CP852_01A0[32]=
{
   0x4F, 0x6F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x74, 0x00, 0x00, 0x54, 0x55, 
   0x75, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7A, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

CHAR __CP852_01C0[32]=
{
   0x7C, 0x00, 0x00, 0x21, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x41, 0x61, 0x49, 
   0x69, 0x4F, 0x6F, 0x55, 0x75, 0x55, 0x75, 0x55, 
   0x75, 0x55, 0x75, 0x55, 0x75, 0x00, 0x41, 0x61, 
};

CHAR __CP852_01E0[32]=
{
   0x00, 0x00, 0x00, 0x00, 0x47, 0x67, 0x47, 0x67, 
   0x4B, 0x6B, 0x4F, 0x6F, 0x4F, 0x6F, 0x00, 0x00, 
   0x6A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

CHAR __CP852_0260[32]=
{
   0x00, 0x67, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

CHAR __CP852_02A0[32]=
{
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x27, 0x22, 0x27, 0x27, 0x00, 0x00, 0x00, 
};

CHAR __CP852_02C0[32]=
{
   0x00, 0x00, 0x00, 0x00, 0x5E, 0x00, 0x5E, 0xF3, 
   0x27, 0xC4, 0xEF, 0x60, 0x00, 0x5F, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0xF4, 0xFA, 0xF8, 0xF2, 0x7E, 0xF1, 0x00, 0x00, 
};

CHAR __CP852_0300[32]=
{
   0x60, 0xEF, 0x5E, 0x7E, 0xC4, 0xC4, 0xF4, 0xFA, 
   0xF9, 0x00, 0xF8, 0x00, 0xF3, 0x00, 0x22, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

CHAR __CP852_0320[32]=
{
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF7, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x5F, 0x5F, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

CHAR __CP852_0360[32]=
{
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3B, 0x00, 
};

CHAR __CP852_03A0[32]=
{
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0xE1, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x75, 0x00, 0x00, 0x00, 
};


CHAR *__CP852_00XX[32]=
{
   __ASCII_0000, __ASCII_0020, __ASCII_0040, __ASCII_0060,
   __NULL_0000,   __CP852_00A0,   __CP852_00C0,   __CP852_00E0,
   __CP852_0100,   __CP852_0120,   __CP852_0140,   __CP852_0160,
   __CP852_0180,   __CP852_01A0,   __CP852_01C0,   __CP852_01E0,
   __NULL_0000,   __NULL_0000,   __NULL_0000,   __CP852_0260,
   __NULL_0000,   __CP852_02A0,   __CP852_02C0,   __NULL_0000,
   __CP852_0300,   __CP852_0320,   __NULL_0000,   __CP852_0360,
   __NULL_0000,   __CP852_03A0,   __NULL_0000,   __NULL_0000,
};

CHAR __CP852_04A0[32]=
{
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x68, 0x00, 0x00, 0x00, 0x00, 
};

CHAR __CP852_0580[32]=
{
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x3A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

CHAR __CP852_0660[32]=
{
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x25, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};


CHAR *__CP852_04XX[32]=
{
   __NULL_0000, __NULL_0000, __NULL_0000, __NULL_0000,
   __NULL_0000, __CP852_04A0, __NULL_0000, __NULL_0000,
   __NULL_0000, __NULL_0000, __NULL_0000, __NULL_0000,
   __CP852_0580, __NULL_0000, __NULL_0000, __NULL_0000,
   __NULL_0000, __NULL_0000, __NULL_0000, __CP852_0660,
   __NULL_0000, __NULL_0000, __NULL_0000, __NULL_0000,
   __NULL_0000, __NULL_0000, __NULL_0000, __NULL_0000,
   __NULL_0000, __NULL_0000, __NULL_0000, __NULL_0000,
};

CHAR __CP852_2000[32]=
{
   0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x2D, 0x2D, 0x00, 0x2D, 0x2D, 0x00, 0x00, 0x00, 
   0x27, 0x27, 0x27, 0x00, 0x22, 0x22, 0x22, 0x00, 
};

CHAR __CP852_2020[32]=
{
   0xC5, 0xC5, 0x07, 0x00, 0x07, 0x00, 0x07, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x25, 0x00, 0x27, 0x22, 0x00, 0x22, 0x00, 0x00, 
   0x00, 0x3C, 0x3E, 0x00, 0x13, 0x00, 0x00, 0x00, 
};

CHAR __CP852_2040[32]=
{
   0x00, 0x00, 0x00, 0x00, 0x2F, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

CHAR __CP852_2060[32]=
{
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x30, 0x00, 0x00, 0x00, 0x34, 0x35, 0x36, 0x37, 
   0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

CHAR __CP852_2080[32]=
{
   0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 
   0x38, 0x39, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

CHAR __CP852_20A0[32]=
{
   0x00, 0x00, 0x00, 0x00, 0x4C, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

CHAR __CP852_2100[32]=
{
   0x00, 0x00, 0x43, 0x00, 0x00, 0x00, 0x00, 0x45, 
   0x00, 0x00, 0x67, 0x48, 0x48, 0x48, 0x68, 0x00, 
   0x49, 0x49, 0x4C, 0x6C, 0x00, 0x4E, 0x00, 0x00, 
   0x50, 0x50, 0x51, 0x52, 0x52, 0x52, 0x00, 0x00, 
};

CHAR __CP852_2120[32]=
{
   0x00, 0x00, 0x74, 0x00, 0x5A, 0x00, 0x00, 0x00, 
   0x5A, 0x00, 0x4B, 0x41, 0x42, 0x43, 0x65, 0x65, 
   0x45, 0x46, 0x00, 0x4D, 0x6F, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

CHAR __CP852_2180[32]=
{
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x1B, 0x18, 0x1A, 0x19, 0x1D, 0x12, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

CHAR __CP852_21A0[32]=
{
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x17, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

CHAR __CP852_2200[32]=
{
   0x00, 0x00, 0x00, 0x00, 0x00, 0x4F, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x2D, 0x2D, 0x00, 0x2F, 0x5C, 0x2A, 
   0xF8, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1C, 
};

CHAR __CP852_2220[32]=
{
   0x00, 0x00, 0x00, 0x7C, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3A, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x7E, 0x00, 0x00, 0x00, 
};

CHAR __CP852_2260[32]=
{
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0xAE, 0xAF, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

CHAR __CP852_22C0[32]=
{
   0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

CHAR __CP852_2300[32]=
{
   0x00, 0x00, 0x7F, 0x5E, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

CHAR __CP852_2320[32]=
{
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x3C, 0x3E, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};


CHAR *__CP852_20XX[32]=
{
   __CP852_2000, __CP852_2020, __CP852_2040, __CP852_2060,
   __CP852_2080, __CP852_20A0, __NULL_0000, __NULL_0000,
   __CP852_2100, __CP852_2120, __NULL_0000, __NULL_0000,
   __CP852_2180, __CP852_21A0, __NULL_0000, __NULL_0000,
   __CP852_2200, __CP852_2220, __NULL_0000, __CP852_2260,
   __NULL_0000, __NULL_0000, __CP852_22C0, __NULL_0000,
   __CP852_2300, __CP852_2320, __NULL_0000, __NULL_0000,
   __NULL_0000, __NULL_0000, __NULL_0000, __NULL_0000,
};

CHAR __CP852_2500[32]=
{
   0xC4, 0x00, 0xB3, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0xDA, 0x00, 0x00, 0x00, 
   0xBF, 0x00, 0x00, 0x00, 0xC0, 0x00, 0x00, 0x00, 
   0xD9, 0x00, 0x00, 0x00, 0xC3, 0x00, 0x00, 0x00, 
};

CHAR __CP852_2520[32]=
{
   0x00, 0x00, 0x00, 0x00, 0xB4, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0xC2, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0xC1, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0xC5, 0x00, 0x00, 0x00, 
};

CHAR __CP852_2540[32]=
{
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0xCD, 0xBA, 0x00, 0x00, 0xC9, 0x00, 0x00, 0xBB, 
   0x00, 0x00, 0xC8, 0x00, 0x00, 0xBC, 0x00, 0x00, 
};

CHAR __CP852_2560[32]=
{
   0xCC, 0x00, 0x00, 0xB9, 0x00, 0x00, 0xCB, 0x00, 
   0x00, 0xCA, 0x00, 0x00, 0xCE, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

CHAR __CP852_2580[32]=
{
   0xDF, 0x00, 0x00, 0x00, 0xDC, 0x00, 0x00, 0x00, 
   0xDB, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0xB0, 0xB1, 0xB2, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

CHAR __CP852_25A0[32]=
{
   0xFE, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x16, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x1E, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x10, 0x00, 0x1F, 0x00, 0x00, 0x00, 
};

CHAR __CP852_25C0[32]=
{
   0x00, 0x00, 0x00, 0x00, 0x11, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x09, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x08, 0x0A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

CHAR __CP852_2620[32]=
{
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x01, 0x02, 0x0F, 0x00, 0x00, 0x00, 
};

CHAR __CP852_2640[32]=
{
   0x0C, 0x00, 0x0B, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

CHAR __CP852_2660[32]=
{
   0x06, 0x00, 0x00, 0x05, 0x00, 0x03, 0x04, 0x00, 
   0x00, 0x00, 0x0D, 0x0E, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

CHAR __CP852_2740[32]=
{
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x7C, 0x00, 0x00, 0x27, 0x27, 0x22, 0x22, 0x00, 
};


CHAR *__CP852_24XX[32]=
{
   __NULL_0000, __NULL_0000, __NULL_0000, __NULL_0000,
   __NULL_0000, __NULL_0000, __NULL_0000, __NULL_0000,
   __CP852_2500, __CP852_2520, __CP852_2540, __CP852_2560,
   __CP852_2580, __CP852_25A0, __CP852_25C0, __NULL_0000,
   __NULL_0000, __CP852_2620, __CP852_2640, __CP852_2660,
   __NULL_0000, __NULL_0000, __NULL_0000, __NULL_0000,
   __NULL_0000, __NULL_0000, __CP852_2740, __NULL_0000,
   __NULL_0000, __NULL_0000, __NULL_0000, __NULL_0000,
};

CHAR __CP852_3000[32]=
{
   0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x3C, 0x3E, 0xAE, 0xAF, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x5B, 0x5D, 0x00, 0x22, 0x22, 0x22, 
};

CHAR __CP852_30E0[32]=
{
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x07, 0x5F, 0x00, 0x00, 0x00, 
};


CHAR *__CP852_30XX[32]=
{
   __CP852_3000, __NULL_0000, __NULL_0000, __NULL_0000,
   __NULL_0000, __NULL_0000, __NULL_0000, __CP852_30E0,
   __NULL_0000, __NULL_0000, __NULL_0000, __NULL_0000,
   __NULL_0000, __NULL_0000, __NULL_0000, __NULL_0000,
   __NULL_0000, __NULL_0000, __NULL_0000, __NULL_0000,
   __NULL_0000, __NULL_0000, __NULL_0000, __NULL_0000,
   __NULL_0000, __NULL_0000, __NULL_0000, __NULL_0000,
   __NULL_0000, __NULL_0000, __NULL_0000, __NULL_0000,
};

CHAR __CP852_FF00[32]=
{
   0x00, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 
   0x28, 0x29, 0x2A, 0x2B, 0x2C, 0x2D, 0x2E, 0x2F, 
   0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 
   0x38, 0x39, 0x3A, 0x3B, 0x3C, 0x3D, 0x3E, 0x00, 
};

CHAR __CP852_FF20[32]=
{
   0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 
   0x48, 0x49, 0x4A, 0x4B, 0x4C, 0x4D, 0x4E, 0x4F, 
   0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 
   0x58, 0x59, 0x5A, 0x5B, 0x5C, 0x5D, 0x5E, 0x5F, 
};

CHAR __CP852_FF40[32]=
{
   0x60, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 
   0x68, 0x69, 0x6A, 0x6B, 0x6C, 0x6D, 0x6E, 0x6F, 
   0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 
   0x78, 0x79, 0x7A, 0x7B, 0x7C, 0x7D, 0x7E, 0x00, 
};


CHAR *__CP852_FCXX[32]=
{
   __NULL_0000, __NULL_0000, __NULL_0000, __NULL_0000,
   __NULL_0000, __NULL_0000, __NULL_0000, __NULL_0000,
   __NULL_0000, __NULL_0000, __NULL_0000, __NULL_0000,
   __NULL_0000, __NULL_0000, __NULL_0000, __NULL_0000,
   __NULL_0000, __NULL_0000, __NULL_0000, __NULL_0000,
   __NULL_0000, __NULL_0000, __NULL_0000, __NULL_0000,
   __CP852_FF00, __CP852_FF20, __CP852_FF40, __NULL_0000,
   __NULL_0000, __NULL_0000, __NULL_0000, __NULL_0000,
};


CHAR **__CP852_FromUnicode[64]=
{
   __CP852_00XX, __CP852_04XX, __NULL_00XX, __NULL_00XX,
   __NULL_00XX, __NULL_00XX, __NULL_00XX, __NULL_00XX,
   __CP852_20XX, __CP852_24XX, __NULL_00XX, __NULL_00XX,
   __CP852_30XX, __NULL_00XX, __NULL_00XX, __NULL_00XX,
   __NULL_00XX, __NULL_00XX, __NULL_00XX, __NULL_00XX,
   __NULL_00XX, __NULL_00XX, __NULL_00XX, __NULL_00XX,
   __NULL_00XX, __NULL_00XX, __NULL_00XX, __NULL_00XX,
   __NULL_00XX, __NULL_00XX, __NULL_00XX, __NULL_00XX,
   __NULL_00XX, __NULL_00XX, __NULL_00XX, __NULL_00XX,
   __NULL_00XX, __NULL_00XX, __NULL_00XX, __NULL_00XX,
   __NULL_00XX, __NULL_00XX, __NULL_00XX, __NULL_00XX,
   __NULL_00XX, __NULL_00XX, __NULL_00XX, __NULL_00XX,
   __NULL_00XX, __NULL_00XX, __NULL_00XX, __NULL_00XX,
   __NULL_00XX, __NULL_00XX, __NULL_00XX, __NULL_00XX,
   __NULL_00XX, __NULL_00XX, __NULL_00XX, __NULL_00XX,
   __NULL_00XX, __NULL_00XX, __NULL_00XX, __CP852_FCXX,
};
