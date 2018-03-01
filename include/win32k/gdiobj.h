/*
 *  GDI object common header definition
 * 
 * (RJJ) taken from WINE
 */

#ifndef __WIN32K_GDIOBJ_H
#define __WIN32K_GDIOBJ_H

#include <ddk/ntddk.h>

  /* GDI objects magic numbers */
#define GO_PEN_MAGIC             0x4f47
#define GO_BRUSH_MAGIC           0x4f48
#define GO_FONT_MAGIC            0x4f49
#define GO_PALETTE_MAGIC         0x4f4a
#define GO_BITMAP_MAGIC          0x4f4b
#define GO_REGION_MAGIC          0x4f4c
#define GO_DC_MAGIC              0x4f4d
#define GO_DISABLED_DC_MAGIC     0x4f4e
#define GO_META_DC_MAGIC         0x4f4f
#define GO_METAFILE_MAGIC        0x4f50
#define GO_METAFILE_DC_MAGIC     0x4f51
#define GO_ENHMETAFILE_MAGIC     0x4f52
#define GO_ENHMETAFILE_DC_MAGIC  0x4f53
#define GO_MAGIC_DONTCARE        0xffff

/* (RJJ) swiped stock handles from wine  */
  /* First handle possible for stock objects (must be >= GDI_HEAP_SIZE) */
#define FIRST_STOCK_HANDLE          0xffffff00

  /* Stock objects handles */
#define NB_STOCK_OBJECTS        (DEFAULT_GUI_FONT + 1)
#define STOCK_WHITE_BRUSH       ((HBRUSH)(FIRST_STOCK_HANDLE+WHITE_BRUSH))
#define STOCK_LTGRAY_BRUSH      ((HBRUSH)(FIRST_STOCK_HANDLE+LTGRAY_BRUSH))
#define STOCK_GRAY_BRUSH        ((HBRUSH)(FIRST_STOCK_HANDLE+GRAY_BRUSH))
#define STOCK_DKGRAY_BRUSH      ((HBRUSH)(FIRST_STOCK_HANDLE+DKGRAY_BRUSH))
#define STOCK_BLACK_BRUSH       ((HBRUSH)(FIRST_STOCK_HANDLE+BLACK_BRUSH))
#define STOCK_NULL_BRUSH        ((HBRUSH)(FIRST_STOCK_HANDLE+NULL_BRUSH))
#define STOCK_HOLLOW_BRUSH      ((HBRUSH)(FIRST_STOCK_HANDLE+HOLLOW_BRUSH))
#define STOCK_WHITE_PEN         ((HPEN)(FIRST_STOCK_HANDLE+WHITE_PEN))
#define STOCK_BLACK_PEN         ((HPEN)(FIRST_STOCK_HANDLE+BLACK_PEN))
#define STOCK_NULL_PEN          ((HPEN)(FIRST_STOCK_HANDLE+NULL_PEN))
#define STOCK_OEM_FIXED_FONT    ((HFONT)(FIRST_STOCK_HANDLE+OEM_FIXED_FONT))
#define STOCK_ANSI_FIXED_FONT   ((HFONT)(FIRST_STOCK_HANDLE+ANSI_FIXED_FONT))
#define STOCK_ANSI_VAR_FONT     ((HFONT)(FIRST_STOCK_HANDLE+ANSI_VAR_FONT))
#define STOCK_SYSTEM_FONT       ((HFONT)(FIRST_STOCK_HANDLE+SYSTEM_FONT))
#define STOCK_DEVICE_DEFAULT_FONT ((HFONT)(FIRST_STOCK_HANDLE+DEVICE_DEFAULT_FONT))
#define STOCK_DEFAULT_PALETTE   ((HPALETTE)(FIRST_STOCK_HANDLE+DEFAULT_PALETTE))
#define STOCK_SYSTEM_FIXED_FONT ((HFONT)(FIRST_STOCK_HANDLE+SYSTEM_FIXED_FONT))
#define STOCK_DEFAULT_GUI_FONT  ((HFONT)(FIRST_STOCK_HANDLE+DEFAULT_GUI_FONT))
#define FIRST_STOCK_FONT        STOCK_OEM_FIXED_FONT
#define LAST_STOCK_FONT         STOCK_DEFAULT_GUI_FONT
#define LAST_STOCK_HANDLE       ((DWORD)STOCK_DEFAULT_GUI_FONT)

typedef struct _GDIOBJHDR
{
  HANDLE  hNext;
  WORD  wMagic;
  DWORD  dwCount;
  KSPIN_LOCK  Lock;
} GDIOBJHDR, *PGDIOBJHDR;

typedef PVOID PGDIOBJ;

PGDIOBJ  GDIOBJ_AllocObject(WORD Size, WORD Magic);
BOOL  GDIOBJ_FreeObject (PGDIOBJ Obj, WORD Magic);
HGDIOBJ  GDIOBJ_PtrToHandle (PGDIOBJ Obj, WORD Magic);
PGDIOBJ  GDIOBJ_HandleToPtr (HGDIOBJ Obj, WORD Magic);
BOOL  GDIOBJ_LockObject (HGDIOBJ Obj);
BOOL  GDIOBJ_UnlockObject (HGDIOBJ Obj);
HGDIOBJ  GDIOBJ_GetNextObject (HGDIOBJ Obj, WORD Magic);
HGDIOBJ  GDIOBJ_SetNextObject (HGDIOBJ Obj, WORD Magic, HGDIOBJ NextObj);

#endif
