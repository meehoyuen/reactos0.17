/*
 * COPYRIGHT:   See COPYING in the top level directory
 * PROJECT:     ReactOS system libraries
 * FILE:        lib/crtdll/ctype/isalnum.c
 * PURPOSE:     Test for a alpha numeric character
 * PROGRAMER:   Boudewijn Dekker
 * UPDATE HISTORY:
 *              28/12/98: Created
 */
#include <crtdll/ctype.h>


#undef isalnum
int isalnum(int c)
{
   return _isctype(c,_ALPHA | _DIGIT);
}

#undef iswalnum
int iswalnum(wint_t c)
{
   return iswctype(c,_ALPHA | _DIGIT);
}
