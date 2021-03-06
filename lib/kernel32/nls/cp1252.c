/*
 * nls/cp1252.c
 * Copyright (C) 1996, Onno Hovers
 * 
 * This file has been generated by gencp.exe
 */

#include <windows.h>
#include <kernel32/nls.h>


WCHAR __CP1252_80[32]=
{
   0x0080, 0x0081, 0x201A, 0x0192, 0x201E, 0x2026, 0x2020, 0x2021, 
   0x02C6, 0x2030, 0x0160, 0x2039, 0x0152, 0x008D, 0x008E, 0x008F, 
   0x0090, 0x2018, 0x2019, 0x201C, 0x201D, 0x2022, 0x2013, 0x2014, 
   0x02DC, 0x2122, 0x0161, 0x203A, 0x0153, 0x009D, 0x009E, 0x0178, 
};

WCHAR __CP1252_A0[32]=
{
   0x00A0, 0x00A1, 0x00A2, 0x00A3, 0x00A4, 0x00A5, 0x00A6, 0x00A7, 
   0x00A8, 0x00A9, 0x00AA, 0x00AB, 0x00AC, 0x00AD, 0x00AE, 0x00AF, 
   0x00B0, 0x00B1, 0x00B2, 0x00B3, 0x00B4, 0x00B5, 0x00B6, 0x00B7, 
   0x00B8, 0x00B9, 0x00BA, 0x00BB, 0x00BC, 0x00BD, 0x00BE, 0x00BF, 
};

WCHAR __CP1252_C0[32]=
{
   0x00C0, 0x00C1, 0x00C2, 0x00C3, 0x00C4, 0x00C5, 0x00C6, 0x00C7, 
   0x00C8, 0x00C9, 0x00CA, 0x00CB, 0x00CC, 0x00CD, 0x00CE, 0x00CF, 
   0x00D0, 0x00D1, 0x00D2, 0x00D3, 0x00D4, 0x00D5, 0x00D6, 0x00D7, 
   0x00D8, 0x00D9, 0x00DA, 0x00DB, 0x00DC, 0x00DD, 0x00DE, 0x00DF, 
};

WCHAR __CP1252_E0[32]=
{
   0x00E0, 0x00E1, 0x00E2, 0x00E3, 0x00E4, 0x00E5, 0x00E6, 0x00E7, 
   0x00E8, 0x00E9, 0x00EA, 0x00EB, 0x00EC, 0x00ED, 0x00EE, 0x00EF, 
   0x00F0, 0x00F1, 0x00F2, 0x00F3, 0x00F4, 0x00F5, 0x00F6, 0x00F7, 
   0x00F8, 0x00F9, 0x00FA, 0x00FB, 0x00FC, 0x00FD, 0x00FE, 0x00FF, 
};


WCHAR *__CP1252_ToUnicode[8]=
{
   __ASCII_00, __ASCII_20, __ASCII_40, __ASCII_60,
   __CP1252_80, __CP1252_A0, __CP1252_C0, __CP1252_E0
};


CHAR __CP1252_0080[32]=
{
   0x80, 0x81, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x8D, 0x8E, 0x8F, 
   0x90, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x9D, 0x9E, 0x00, 
};

CHAR __CP1252_00A0[32]=
{
   0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 
   0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 
   0xB0, 0xB1, 0xB2, 0xB3, 0xB4, 0xB5, 0xB6, 0xB7, 
   0xB8, 0xB9, 0xBA, 0xBB, 0xBC, 0xBD, 0xBE, 0xBF, 
};

CHAR __CP1252_00C0[32]=
{
   0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 
   0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 
   0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0xD5, 0xD6, 0xD7, 
   0xD8, 0xD9, 0xDA, 0xDB, 0xDC, 0xDD, 0xDE, 0xDF, 
};

CHAR __CP1252_00E0[32]=
{
   0xE0, 0xE1, 0xE2, 0xE3, 0xE4, 0xE5, 0xE6, 0xE7, 
   0xE8, 0xE9, 0xEA, 0xEB, 0xEC, 0xED, 0xEE, 0xEF, 
   0xF0, 0xF1, 0xF2, 0xF3, 0xF4, 0xF5, 0xF6, 0xF7, 
   0xF8, 0xF9, 0xFA, 0xFB, 0xFC, 0xFD, 0xFE, 0xFF, 
};

CHAR __CP1252_0100[32]=
{
   0x41, 0x61, 0x41, 0x61, 0x41, 0x61, 0x43, 0x63, 
   0x43, 0x63, 0x43, 0x63, 0x43, 0x63, 0x44, 0x64, 
   0xD0, 0x64, 0x45, 0x65, 0x45, 0x65, 0x45, 0x65, 
   0x45, 0x65, 0x45, 0x65, 0x47, 0x67, 0x47, 0x67, 
};

CHAR __CP1252_0120[32]=
{
   0x47, 0x67, 0x47, 0x67, 0x48, 0x68, 0x48, 0x68, 
   0x49, 0x69, 0x49, 0x69, 0x49, 0x69, 0x49, 0x69, 
   0x49, 0x69, 0x00, 0x00, 0x4A, 0x6A, 0x4B, 0x6B, 
   0x00, 0x4C, 0x6C, 0x4C, 0x6C, 0x4C, 0x6C, 0x00, 
};

CHAR __CP1252_0140[32]=
{
   0x00, 0x4C, 0x6C, 0x4E, 0x6E, 0x4E, 0x6E, 0x4E, 
   0x6E, 0x00, 0x00, 0x00, 0x4F, 0x6F, 0x4F, 0x6F, 
   0x4F, 0x6F, 0x8C, 0x9C, 0x52, 0x72, 0x52, 0x72, 
   0x52, 0x72, 0x53, 0x73, 0x53, 0x73, 0x53, 0x73, 
};

CHAR __CP1252_0160[32]=
{
   0x8A, 0x9A, 0x54, 0x74, 0x54, 0x74, 0x54, 0x74, 
   0x55, 0x75, 0x55, 0x75, 0x55, 0x75, 0x55, 0x75, 
   0x55, 0x75, 0x55, 0x75, 0x57, 0x77, 0x59, 0x79, 
   0x9F, 0x5A, 0x7A, 0x5A, 0x7A, 0x5A, 0x7A, 0x00, 
};

CHAR __CP1252_0180[32]=
{
   0x62, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0xD0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x83, 0x83, 0x00, 0x00, 0x00, 0x00, 0x49, 
   0x00, 0x00, 0x6C, 0x00, 0x00, 0x00, 0x00, 0x4F, 
};

CHAR __CP1252_01A0[32]=
{
   0x4F, 0x6F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x74, 0x00, 0x00, 0x54, 0x55, 
   0x75, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7A, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

CHAR __CP1252_01C0[32]=
{
   0x7C, 0x00, 0x00, 0x21, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x41, 0x61, 0x49, 
   0x69, 0x4F, 0x6F, 0x55, 0x75, 0x55, 0x75, 0x55, 
   0x75, 0x55, 0x75, 0x55, 0x75, 0x00, 0x41, 0x61, 
};

CHAR __CP1252_01E0[32]=
{
   0x00, 0x00, 0x00, 0x00, 0x47, 0x67, 0x47, 0x67, 
   0x4B, 0x6B, 0x4F, 0x6F, 0x4F, 0x6F, 0x00, 0x00, 
   0x6A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

CHAR __CP1252_0260[32]=
{
   0x00, 0x67, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

CHAR __CP1252_02A0[32]=
{
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x27, 0x22, 0x00, 0x27, 0x00, 0x00, 0x00, 
};

CHAR __CP1252_02C0[32]=
{
   0x00, 0x00, 0x00, 0x00, 0x5E, 0x00, 0x88, 0x00, 
   0x27, 0xAF, 0xB4, 0x60, 0x00, 0x5F, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0xB0, 0x00, 0x98, 0x00, 0x00, 0x00, 
};

CHAR __CP1252_0300[32]=
{
   0x60, 0xB4, 0x5E, 0x7E, 0xAF, 0xAF, 0x00, 0x00, 
   0xA8, 0x00, 0xB0, 0x00, 0x00, 0x00, 0x22, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

CHAR __CP1252_0320[32]=
{
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xB8, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x5F, 0x5F, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

CHAR __CP1252_0360[32]=
{
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3B, 0x00, 
};

CHAR __CP1252_0380[32]=
{
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x47, 0x00, 0x00, 0x00, 0x00, 
   0x54, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

CHAR __CP1252_03A0[32]=
{
   0x00, 0x00, 0x00, 0x53, 0x00, 0x00, 0x46, 0x00, 
   0x00, 0x4F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x61, 0xDF, 0x00, 0x64, 0x65, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0xB5, 0x00, 0x00, 0x00, 
};

CHAR __CP1252_03C0[32]=
{
   0x70, 0x00, 0x00, 0x73, 0x74, 0x00, 0x66, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};


CHAR *__CP1252_00XX[32]=
{
   __ASCII_0000, __ASCII_0020, __ASCII_0040, __ASCII_0060,
   __CP1252_0080,   __CP1252_00A0,   __CP1252_00C0,   __CP1252_00E0,
   __CP1252_0100,   __CP1252_0120,   __CP1252_0140,   __CP1252_0160,
   __CP1252_0180,   __CP1252_01A0,   __CP1252_01C0,   __CP1252_01E0,
   __NULL_0000,   __NULL_0000,   __NULL_0000,   __CP1252_0260,
   __NULL_0000,   __CP1252_02A0,   __CP1252_02C0,   __NULL_0000,
   __CP1252_0300,   __CP1252_0320,   __NULL_0000,   __CP1252_0360,
   __CP1252_0380,   __CP1252_03A0,   __CP1252_03C0,   __NULL_0000,
};

CHAR __CP1252_04A0[32]=
{
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x68, 0x00, 0x00, 0x00, 0x00, 
};

CHAR __CP1252_0580[32]=
{
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x3A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

CHAR __CP1252_0660[32]=
{
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x25, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};


CHAR *__CP1252_04XX[32]=
{
   __NULL_0000, __NULL_0000, __NULL_0000, __NULL_0000,
   __NULL_0000, __CP1252_04A0, __NULL_0000, __NULL_0000,
   __NULL_0000, __NULL_0000, __NULL_0000, __NULL_0000,
   __CP1252_0580, __NULL_0000, __NULL_0000, __NULL_0000,
   __NULL_0000, __NULL_0000, __NULL_0000, __CP1252_0660,
   __NULL_0000, __NULL_0000, __NULL_0000, __NULL_0000,
   __NULL_0000, __NULL_0000, __NULL_0000, __NULL_0000,
   __NULL_0000, __NULL_0000, __NULL_0000, __NULL_0000,
};

CHAR __CP1252_2000[32]=
{
   0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x2D, 0x2D, 0x00, 0x96, 0x97, 0x00, 0x00, 0x3D, 
   0x91, 0x92, 0x82, 0x00, 0x93, 0x94, 0x84, 0x00, 
};

CHAR __CP1252_2020[32]=
{
   0x86, 0x87, 0x95, 0x00, 0xB7, 0x00, 0x85, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x89, 0x00, 0x27, 0x00, 0x00, 0x60, 0x00, 0x00, 
   0x00, 0x8B, 0x9B, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

CHAR __CP1252_2040[32]=
{
   0x00, 0x00, 0x00, 0x00, 0x2F, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

CHAR __CP1252_2060[32]=
{
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0xB0, 0x00, 0x00, 0x00, 0x34, 0x35, 0x36, 0x37, 
   0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6E, 
};

CHAR __CP1252_2080[32]=
{
   0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 
   0x38, 0x39, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

CHAR __CP1252_20A0[32]=
{
   0x00, 0xA2, 0x00, 0x00, 0xA3, 0x00, 0x00, 0x50, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

CHAR __CP1252_2100[32]=
{
   0x00, 0x00, 0x43, 0x00, 0x00, 0x00, 0x00, 0x45, 
   0x00, 0x00, 0x67, 0x48, 0x48, 0x48, 0x68, 0x00, 
   0x49, 0x49, 0x4C, 0x6C, 0x00, 0x4E, 0x00, 0x00, 
   0x50, 0x50, 0x51, 0x52, 0x52, 0x52, 0x00, 0x00, 
};

CHAR __CP1252_2120[32]=
{
   0x00, 0x00, 0x99, 0x00, 0x5A, 0x00, 0x00, 0x00, 
   0x5A, 0x00, 0x4B, 0xC5, 0x42, 0x43, 0x65, 0x65, 
   0x45, 0x46, 0x00, 0x4D, 0x6F, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

CHAR __CP1252_2200[32]=
{
   0x00, 0x00, 0x00, 0x00, 0x00, 0xD8, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x2D, 0xB1, 0x00, 0x2F, 0x5C, 0x2A, 
   0xB0, 0xB7, 0x76, 0x00, 0x00, 0x00, 0x38, 0x00, 
};

CHAR __CP1252_2220[32]=
{
   0x00, 0x00, 0x00, 0x7C, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x6E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3A, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x7E, 0x00, 0x00, 0x00, 
};

CHAR __CP1252_2240[32]=
{
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x98, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

CHAR __CP1252_2260[32]=
{
   0x00, 0x3D, 0x00, 0x00, 0x3D, 0x3D, 0x00, 0x00, 
   0x00, 0x00, 0xAB, 0xBB, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

CHAR __CP1252_22C0[32]=
{
   0x00, 0x00, 0x00, 0x00, 0x00, 0xB7, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

CHAR __CP1252_2300[32]=
{
   0x00, 0x00, 0xA6, 0x5E, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0xAC, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

CHAR __CP1252_2320[32]=
{
   0x28, 0x29, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x3C, 0x3E, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};


CHAR *__CP1252_20XX[32]=
{
   __CP1252_2000, __CP1252_2020, __CP1252_2040, __CP1252_2060,
   __CP1252_2080, __CP1252_20A0, __NULL_0000, __NULL_0000,
   __CP1252_2100, __CP1252_2120, __NULL_0000, __NULL_0000,
   __NULL_0000, __NULL_0000, __NULL_0000, __NULL_0000,
   __CP1252_2200, __CP1252_2220, __CP1252_2240, __CP1252_2260,
   __NULL_0000, __NULL_0000, __CP1252_22C0, __NULL_0000,
   __CP1252_2300, __CP1252_2320, __NULL_0000, __NULL_0000,
   __NULL_0000, __NULL_0000, __NULL_0000, __NULL_0000,
};

CHAR __CP1252_2500[32]=
{
   0x2D, 0x00, 0xA6, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x2B, 0x00, 0x00, 0x00, 
   0x2B, 0x00, 0x00, 0x00, 0x2B, 0x00, 0x00, 0x00, 
   0x2B, 0x00, 0x00, 0x00, 0x2B, 0x00, 0x00, 0x00, 
};

CHAR __CP1252_2520[32]=
{
   0x00, 0x00, 0x00, 0x00, 0xA6, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x2D, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x2D, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x2B, 0x00, 0x00, 0x00, 
};

CHAR __CP1252_2540[32]=
{
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x2D, 0xA6, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 
   0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0xA6, 0xA6, 
};

CHAR __CP1252_2560[32]=
{
   0xA6, 0xA6, 0xA6, 0xA6, 0x2D, 0x2D, 0x2D, 0x2D, 
   0x2D, 0x2D, 0x2B, 0x2B, 0x2B, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

CHAR __CP1252_2580[32]=
{
   0xAF, 0x00, 0x00, 0x00, 0x5F, 0x00, 0x00, 0x00, 
   0xA6, 0x00, 0x00, 0x00, 0xA6, 0x00, 0x00, 0x00, 
   0xA6, 0xA6, 0xA6, 0xA6, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

CHAR __CP1252_25A0[32]=
{
   0xA6, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

CHAR __CP1252_2620[32]=
{
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0xA4, 0x00, 0x00, 0x00, 
};

CHAR __CP1252_2740[32]=
{
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x7C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};


CHAR *__CP1252_24XX[32]=
{
   __NULL_0000, __NULL_0000, __NULL_0000, __NULL_0000,
   __NULL_0000, __NULL_0000, __NULL_0000, __NULL_0000,
   __CP1252_2500, __CP1252_2520, __CP1252_2540, __CP1252_2560,
   __CP1252_2580, __CP1252_25A0, __NULL_0000, __NULL_0000,
   __NULL_0000, __CP1252_2620, __NULL_0000, __NULL_0000,
   __NULL_0000, __NULL_0000, __NULL_0000, __NULL_0000,
   __NULL_0000, __NULL_0000, __CP1252_2740, __NULL_0000,
   __NULL_0000, __NULL_0000, __NULL_0000, __NULL_0000,
};

CHAR __CP1252_3000[32]=
{
   0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x3C, 0x3E, 0xAB, 0xBB, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x5B, 0x5D, 0x00, 0x00, 0x00, 0x00, 
};

CHAR __CP1252_30E0[32]=
{
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0xB7, 0x00, 0x00, 0x00, 0x00, 
};


CHAR *__CP1252_30XX[32]=
{
   __CP1252_3000, __NULL_0000, __NULL_0000, __NULL_0000,
   __NULL_0000, __NULL_0000, __NULL_0000, __CP1252_30E0,
   __NULL_0000, __NULL_0000, __NULL_0000, __NULL_0000,
   __NULL_0000, __NULL_0000, __NULL_0000, __NULL_0000,
   __NULL_0000, __NULL_0000, __NULL_0000, __NULL_0000,
   __NULL_0000, __NULL_0000, __NULL_0000, __NULL_0000,
   __NULL_0000, __NULL_0000, __NULL_0000, __NULL_0000,
   __NULL_0000, __NULL_0000, __NULL_0000, __NULL_0000,
};

CHAR __CP1252_FF00[32]=
{
   0x00, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 
   0x28, 0x29, 0x2A, 0x2B, 0x2C, 0x2D, 0x2E, 0x2F, 
   0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 
   0x38, 0x39, 0x3A, 0x3B, 0x3C, 0x3D, 0x3E, 0x00, 
};

CHAR __CP1252_FF20[32]=
{
   0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 
   0x48, 0x49, 0x4A, 0x4B, 0x4C, 0x4D, 0x4E, 0x4F, 
   0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 
   0x58, 0x59, 0x5A, 0x5B, 0x5C, 0x5D, 0x5E, 0x5F, 
};

CHAR __CP1252_FF40[32]=
{
   0x60, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 
   0x68, 0x69, 0x6A, 0x6B, 0x6C, 0x6D, 0x6E, 0x6F, 
   0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 
   0x78, 0x79, 0x7A, 0x7B, 0x7C, 0x7D, 0x7E, 0x00, 
};


CHAR *__CP1252_FCXX[32]=
{
   __NULL_0000, __NULL_0000, __NULL_0000, __NULL_0000,
   __NULL_0000, __NULL_0000, __NULL_0000, __NULL_0000,
   __NULL_0000, __NULL_0000, __NULL_0000, __NULL_0000,
   __NULL_0000, __NULL_0000, __NULL_0000, __NULL_0000,
   __NULL_0000, __NULL_0000, __NULL_0000, __NULL_0000,
   __NULL_0000, __NULL_0000, __NULL_0000, __NULL_0000,
   __CP1252_FF00, __CP1252_FF20, __CP1252_FF40, __NULL_0000,
   __NULL_0000, __NULL_0000, __NULL_0000, __NULL_0000,
};


CHAR **__CP1252_FromUnicode[64]=
{
   __CP1252_00XX, __CP1252_04XX, __NULL_00XX, __NULL_00XX,
   __NULL_00XX, __NULL_00XX, __NULL_00XX, __NULL_00XX,
   __CP1252_20XX, __CP1252_24XX, __NULL_00XX, __NULL_00XX,
   __CP1252_30XX, __NULL_00XX, __NULL_00XX, __NULL_00XX,
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
   __NULL_00XX, __NULL_00XX, __NULL_00XX, __CP1252_FCXX,
};
