#include <crtdll/process.h>
#include <crtdll/stdlib.h>
#include <crtdll/stdarg.h>


// fixme rewrite to pass the array variants to va_list variant

int _execle(const char *path, const char *szArgv0, ... /*, const char **envp */)
{
  char *szArg[100];
  const char *a;
  char *ptr;
  int i = 0;
  va_list l = 0;
  va_start(l,szArgv0);
  do {
  	a = (const char *)va_arg(l,const char *);
	szArg[i++] = (char *)a;
  } while ( a != NULL && i < 100 );


// szArg0 is passed and not environment if there is only one parameter;

  if ( i >=2 ) {
  	ptr = szArg[i-2];
  	szArg[i-2] = NULL;
  }
  else
	ptr = NULL;


  return _spawnve(P_OVERLAY, path, (char * const *)szArg, (char * const *)ptr);
}
