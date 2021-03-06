/*
 * nls/cp1257.c
 * Copyright (C) 1996, Onno Hovers
 * 
 * This file has been generated by gencp.exe
 */

#include <windows.h>
#include <kernel32/nls.h>


WCHAR __CP1257_80[32]=
{
   0x0080, 0x0081, 0x201A, 0x0083, 0x201E, 0x2026, 0x2020, 0x2021, 
   0x0088, 0x2030, 0x008A, 0x2039, 0x008C, 0x00A8, 0x02C7, 0x00B8, 
   0x0090, 0x2018, 0x2019, 0x201C, 0x201D, 0x2022, 0x2013, 0x2014, 
   0x0098, 0x2122, 0x009A, 0x203A, 0x009C, 0x00AF, 0x02DB, 0x009F, 
};

WCHAR __CP1257_A0[32]=
{
   0x00A0, 0xF8FC, 0x00A2, 0x00A3, 0x00A4, 0xF8FD, 0x00A6, 0x00A7, 
   0x00D8, 0x00A9, 0x0156, 0x00AB, 0x00AC, 0x00AD, 0x00AE, 0x00C6, 
   0x00B0, 0x00B1, 0x00B2, 0x00B3, 0x00B4, 0x00B5, 0x00B6, 0x00B7, 
   0x00F8, 0x00B9, 0x0157, 0x00BB, 0x00BC, 0x00BD, 0x00BE, 0x00E6, 
};

WCHAR __CP1257_C0[32]=
{
   0x0104, 0x012E, 0x0100, 0x0106, 0x00C4, 0x00C5, 0x0118, 0x0112, 
   0x010C, 0x00C9, 0x0179, 0x0116, 0x0122, 0x0136, 0x012A, 0x013B, 
   0x0160, 0x0143, 0x0145, 0x00D3, 0x014C, 0x00D5, 0x00D6, 0x00D7, 
   0x0172, 0x0141, 0x015A, 0x016A, 0x00DC, 0x017B, 0x017D, 0x00DF, 
};

WCHAR __CP1257_E0[32]=
{
   0x0105, 0x012F, 0x0101, 0x0107, 0x00E4, 0x00E5, 0x0119, 0x0113, 
   0x010D, 0x00E9, 0x017A, 0x0117, 0x0123, 0x0137, 0x012B, 0x013C, 
   0x0161, 0x0144, 0x0146, 0x00F3, 0x014D, 0x00F5, 0x00F6, 0x00F7, 
   0x0173, 0x0142, 0x015B, 0x016B, 0x00FC, 0x017C, 0x017E, 0x02D9, 
};


WCHAR *__CP1257_ToUnicode[8]=
{
   __ASCII_00, __ASCII_20, __ASCII_40, __ASCII_60,
   __CP1257_80, __CP1257_A0, __CP1257_C0, __CP1257_E0
};


CHAR __CP1257_0080[32]=
{
   0x80, 0x81, 0x00, 0x83, 0x00, 0x00, 0x00, 0x00, 
   0x88, 0x00, 0x8A, 0x00, 0x8C, 0x00, 0x00, 0x00, 
   0x90, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x98, 0x00, 0x9A, 0x00, 0x9C, 0x00, 0x00, 0x9F, 
};

CHAR __CP1257_00A0[32]=
{
   0xA0, 0x00, 0xA2, 0xA3, 0xA4, 0x00, 0xA6, 0xA7, 
   0x8D, 0xA9, 0x00, 0xAB, 0xAC, 0xAD, 0xAE, 0x9D, 
   0xB0, 0xB1, 0xB2, 0xB3, 0xB4, 0xB5, 0xB6, 0xB7, 
   0x8F, 0xB9, 0x00, 0xBB, 0xBC, 0xBD, 0xBE, 0x00, 
};

CHAR __CP1257_00C0[32]=
{
   0x00, 0x00, 0x00, 0x00, 0xC4, 0xC5, 0xAF, 0x00, 
   0x00, 0xC9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0xD3, 0x00, 0xD5, 0xD6, 0xD7, 
   0xA8, 0x00, 0x00, 0x00, 0xDC, 0x00, 0x00, 0xDF, 
};

CHAR __CP1257_00E0[32]=
{
   0x00, 0x00, 0x00, 0x00, 0xE4, 0xE5, 0xBF, 0x00, 
   0x00, 0xE9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0xF3, 0x00, 0xF5, 0xF6, 0xF7, 
   0xB8, 0x00, 0x00, 0x00, 0xFC, 0x00, 0x00, 0x00, 
};

CHAR __CP1257_0100[32]=
{
   0xC2, 0xE2, 0x00, 0x00, 0xC0, 0xE0, 0xC3, 0xE3, 
   0x00, 0x00, 0x00, 0x00, 0xC8, 0xE8, 0x00, 0x00, 
   0x00, 0x00, 0xC7, 0xE7, 0x00, 0x00, 0xCB, 0xEB, 
   0xC6, 0xE6, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

CHAR __CP1257_0120[32]=
{
   0x00, 0x00, 0xCC, 0xEC, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0xCE, 0xEE, 0x00, 0x00, 0xC1, 0xE1, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xCD, 0xED, 
   0x00, 0x00, 0x00, 0xCF, 0xEF, 0x00, 0x00, 0x00, 
};

CHAR __CP1257_0140[32]=
{
   0x00, 0xD9, 0xF9, 0xD1, 0xF1, 0xD2, 0xF2, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0xD4, 0xF4, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xAA, 0xBA, 
   0x00, 0x00, 0xDA, 0xFA, 0x00, 0x00, 0x00, 0x00, 
};

CHAR __CP1257_0160[32]=
{
   0xD0, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0xDB, 0xFB, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0xD8, 0xF8, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0xCA, 0xEA, 0xDD, 0xFD, 0xDE, 0xFE, 0x00, 
};

CHAR __CP1257_02C0[32]=
{
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x8E, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0xFF, 0x00, 0x9E, 0x00, 0x00, 0x00, 0x00, 
};


CHAR *__CP1257_00XX[32]=
{
   __ASCII_0000, __ASCII_0020, __ASCII_0040, __ASCII_0060,
   __CP1257_0080,   __CP1257_00A0,   __CP1257_00C0,   __CP1257_00E0,
   __CP1257_0100,   __CP1257_0120,   __CP1257_0140,   __CP1257_0160,
   __NULL_0000,   __NULL_0000,   __NULL_0000,   __NULL_0000,
   __NULL_0000,   __NULL_0000,   __NULL_0000,   __NULL_0000,
   __NULL_0000,   __NULL_0000,   __CP1257_02C0,   __NULL_0000,
   __NULL_0000,   __NULL_0000,   __NULL_0000,   __NULL_0000,
   __NULL_0000,   __NULL_0000,   __NULL_0000,   __NULL_0000,
};

CHAR __CP1257_2000[32]=
{
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x96, 0x97, 0x00, 0x00, 0x00, 
   0x91, 0x92, 0x82, 0x00, 0x93, 0x94, 0x84, 0x00, 
};

CHAR __CP1257_2020[32]=
{
   0x86, 0x87, 0x95, 0x00, 0x00, 0x00, 0x85, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x89, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x8B, 0x9B, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

CHAR __CP1257_2120[32]=
{
   0x00, 0x00, 0x99, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};


CHAR *__CP1257_20XX[32]=
{
   __CP1257_2000, __CP1257_2020, __NULL_0000, __NULL_0000,
   __NULL_0000, __NULL_0000, __NULL_0000, __NULL_0000,
   __NULL_0000, __CP1257_2120, __NULL_0000, __NULL_0000,
   __NULL_0000, __NULL_0000, __NULL_0000, __NULL_0000,
   __NULL_0000, __NULL_0000, __NULL_0000, __NULL_0000,
   __NULL_0000, __NULL_0000, __NULL_0000, __NULL_0000,
   __NULL_0000, __NULL_0000, __NULL_0000, __NULL_0000,
   __NULL_0000, __NULL_0000, __NULL_0000, __NULL_0000,
};

CHAR __CP1257_F8E0[32]=
{
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0xA1, 0xA5, 0x00, 0x00, 
};


CHAR *__CP1257_F8XX[32]=
{
   __NULL_0000, __NULL_0000, __NULL_0000, __NULL_0000,
   __NULL_0000, __NULL_0000, __NULL_0000, __CP1257_F8E0,
   __NULL_0000, __NULL_0000, __NULL_0000, __NULL_0000,
   __NULL_0000, __NULL_0000, __NULL_0000, __NULL_0000,
   __NULL_0000, __NULL_0000, __NULL_0000, __NULL_0000,
   __NULL_0000, __NULL_0000, __NULL_0000, __NULL_0000,
   __NULL_0000, __NULL_0000, __NULL_0000, __NULL_0000,
   __NULL_0000, __NULL_0000, __NULL_0000, __NULL_0000,
};

CHAR __CP1257_FF00[32]=
{
   0x00, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 
   0x28, 0x29, 0x2A, 0x2B, 0x2C, 0x2D, 0x2E, 0x2F, 
   0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 
   0x38, 0x39, 0x3A, 0x3B, 0x3C, 0x3D, 0x3E, 0x00, 
};

CHAR __CP1257_FF20[32]=
{
   0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 
   0x48, 0x49, 0x4A, 0x4B, 0x4C, 0x4D, 0x4E, 0x4F, 
   0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 
   0x58, 0x59, 0x5A, 0x5B, 0x5C, 0x5D, 0x5E, 0x5F, 
};

CHAR __CP1257_FF40[32]=
{
   0x60, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 
   0x68, 0x69, 0x6A, 0x6B, 0x6C, 0x6D, 0x6E, 0x6F, 
   0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 
   0x78, 0x79, 0x7A, 0x7B, 0x7C, 0x7D, 0x7E, 0x00, 
};


CHAR *__CP1257_FCXX[32]=
{
   __NULL_0000, __NULL_0000, __NULL_0000, __NULL_0000,
   __NULL_0000, __NULL_0000, __NULL_0000, __NULL_0000,
   __NULL_0000, __NULL_0000, __NULL_0000, __NULL_0000,
   __NULL_0000, __NULL_0000, __NULL_0000, __NULL_0000,
   __NULL_0000, __NULL_0000, __NULL_0000, __NULL_0000,
   __NULL_0000, __NULL_0000, __NULL_0000, __NULL_0000,
   __CP1257_FF00, __CP1257_FF20, __CP1257_FF40, __NULL_0000,
   __NULL_0000, __NULL_0000, __NULL_0000, __NULL_0000,
};


CHAR **__CP1257_FromUnicode[64]=
{
   __CP1257_00XX, __NULL_00XX, __NULL_00XX, __NULL_00XX,
   __NULL_00XX, __NULL_00XX, __NULL_00XX, __NULL_00XX,
   __CP1257_20XX, __NULL_00XX, __NULL_00XX, __NULL_00XX,
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
   __NULL_00XX, __NULL_00XX, __NULL_00XX, __NULL_00XX,
   __NULL_00XX, __NULL_00XX, __CP1257_F8XX, __CP1257_FCXX,
};
