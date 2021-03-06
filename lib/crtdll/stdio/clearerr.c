/* Copyright (C) 1994 DJ Delorie, see COPYING.DJ for details */
#include <crtdll/stdio.h>
#include <crtdll/errno.h>
#include <crtdll/internal/file.h>

#ifdef clearerr
#undef clearerr
void clearerr(FILE *stream);
#endif

void
clearerr(FILE *f)
{
  if (!__validfp (f)) {
    __set_errno (EINVAL);
    return;
  }
  f->_flag &= ~(_IOERR|_IOEOF);
}
