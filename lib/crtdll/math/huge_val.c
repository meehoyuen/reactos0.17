/* Copyright (C) 1994 DJ Delorie, see COPYING.DJ for details */

#include <crtdll/internal/ieee.h>

#undef _HUGE
double_t _HUGE = { 0x00000, 0x00000, 0x7ff, 0x0 };
double *_HUGE_dll = (double *)&_HUGE; 
