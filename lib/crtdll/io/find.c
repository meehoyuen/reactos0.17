#include <windows.h>
#include <crtdll/io.h>
#include <crtdll/string.h>
#include <crtdll/internal/file.h>



int _findfirst(const char *_name, struct _finddata_t *result)
{

        WIN32_FIND_DATA FindFileData;
        char dir[MAX_PATH];
        long hFindFile;
        int len = 0;
        
        if ( _name == NULL || _name[0] == 0 ) {
                len = GetCurrentDirectory(MAX_PATH-4,dir);
                if (dir[len-1] != '\\') {
                        dir[len] = '\\';
                        dir[len+1] = 0;
                }
                strcat(dir,"*.*");
        }
        else 
                strcpy(dir,_name);
        hFindFile = (long)FindFirstFileA( dir, &FindFileData ); 
        if ( hFindFile == -1 ) {
        	memset(result,0,sizeof(struct _finddata_t));
        	return -1;
        }
        result->attrib = FindFileData.dwFileAttributes; 


        result->time_create = FileTimeToUnixTime( &FindFileData.ftCreationTime,NULL);
        result->time_access = FileTimeToUnixTime( &FindFileData.ftLastAccessTime,NULL);
        result->time_write = FileTimeToUnixTime( &FindFileData.ftLastWriteTime,NULL);
        result->size = FindFileData.nFileSizeLow;
        strncpy(result->name,FindFileData.cFileName,260);
        
        // if no wildcard the find file handle can be closed right away
        // a return value of 0 can flag this.
        
        if(!strchr(dir,'*') && !strchr(dir,'?')) {
        	_findclose(hFindFile);
        	return 0;
        }
        
        
        return hFindFile;

}

int  _findnext(int handle, struct _finddata_t  *result)
{
        WIN32_FIND_DATA FindFileData;
        
        // check no wildcards or invalid handle
        if ( handle == 0 || handle == -1)
		return 0;
                
          

        if ( !FindNextFile((void *)handle, &FindFileData ) )
                return -1;
        
        result->attrib = FindFileData.dwFileAttributes; 
        result->time_create = FileTimeToUnixTime( &FindFileData.ftCreationTime,NULL);
        result->time_access = FileTimeToUnixTime( &FindFileData.ftLastAccessTime,NULL);
        result->time_write = FileTimeToUnixTime( &FindFileData.ftLastWriteTime,NULL);
        result->size = FindFileData.nFileSizeLow;
        strncpy(result->name,FindFileData.cFileName,260);
        return 0;
}

int  _findclose(int handle)
{
	// check no wildcards or invalid handle
	if ( handle == 0 || handle == -1)
		return 0;
        return FindClose((void *)handle);
}
