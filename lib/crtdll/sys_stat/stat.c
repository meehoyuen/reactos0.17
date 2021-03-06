#include <windows.h>
#include <crtdll/sys/types.h>
#include <crtdll/sys/stat.h>
#include <crtdll/fcntl.h>
#include <crtdll/io.h>
#include <crtdll/errno.h>


int _stat( const char *path, struct stat *buffer )
{
 WIN32_FIND_DATA wfd;
 HANDLE fh;
  fh = FindFirstFile (path,&wfd);
  if ( fh == -1 )
  {
    __set_errno(ENOFILE);
    return -1;
  }
  if ( ! (wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
  {
	int fd = _open(path,_O_RDONLY);
	int ret;
	
	ret = fstat(fd,buffer);
	_close(fd);

	return ret;
  }
  buffer->st_ctime = FileTimeToUnixTime( &wfd.ftCreationTime,NULL);
  buffer->st_atime = FileTimeToUnixTime( &wfd.ftLastAccessTime,NULL);
  buffer->st_mtime = FileTimeToUnixTime( &wfd.ftLastWriteTime,NULL);

  if (buffer->st_atime ==0)
    buffer->st_atime = buffer->st_mtime;
  if (buffer->st_ctime ==0)
    buffer->st_ctime = buffer->st_mtime;

  buffer->st_mode = S_IREAD;
  if (wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
    buffer->st_mode |= S_IFDIR;
  else
    buffer->st_mode |= S_IFREG;
  if ( ! (wfd.dwFileAttributes & FILE_ATTRIBUTE_READONLY))
    buffer->st_mode |= S_IWRITE | S_IEXEC;

  buffer->st_size = wfd.nFileSizeLow; 
  buffer->st_nlink = 1;
  if (FindNextFile(fh,&wfd))
  {
    __set_errno(ENOFILE);
    FindClose(fh);
    return -1;
  }
  return 0;
}
