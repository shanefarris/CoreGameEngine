// Updated 5-7-07

#include "CFileList.h"

#include <stdlib.h>
#include <stdio.h>

#ifdef _WINDOWS
#include <io.h>
#include <direct.h>

#endif

#ifdef LINUX

#include "limits.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <string>

#define MAX_PATH PATH_MAX
#define _MAX_PATH PATH_MAX
#define _getcwd getcwd
#define _chdir chdir


#endif


using namespace IO;

CFileList::CFileList()
{
	char tmp[_MAX_PATH] = { '\0' };

	// Gets the current working directory.
	if(_getcwd(tmp, _MAX_PATH))
	{
		Path = tmp;
		FileEntry entry;
	}

#ifdef WINDOWS
	//Adds every file in the current directory to our file list?
	struct _finddata_t c_file;
	long hFile;

	if((hFile = _findfirst("*", &c_file)) != -1L)
	{
		do
		{
			entry.Name = c_file.name;
			entry.Size = c_file.size;
			entry.IsDirectory =(_A_SUBDIR & c_file.attrib) != 0;
			Files.push_back(entry);
		}
		while(_findnext(hFile, &c_file) == 0);

		_findclose(hFile);
	}
#endif

#ifdef LINUX

	DIR *dp;
	struct dirent *ep;
	
	dp = opendir ("./");
	if (dp != nullptr)
	  {
	    while (ep = readdir (dp))
	      {
		String t_string = ep->d_name;
		if(t_string!="." && t_string!="..")
		{
		  struct stat t_stat;
		  stat(t_string.c_str(), &t_stat); //get the size of the file
		  entry.Name = t_string;
		  entry.Size = t_stat.st_size;
		  entry.IsDirectory = (S_ISDIR(t_stat.st_mode));
		  Files.push_back(entry);
		}
	    }
	(void) closedir (dp);
       }

#endif

	//TODO add drives
	//entry.Name = "E:\\";
	//entry.IsDirectory = true;
	//Files.push_back(entry);

	// sort the list on all platforms
	//Files.Sort();
}

u32 CFileList::GetFileCount()
{
	return (u32)Files.size();
}

const char* CFileList::GetFileName(s32 Index)
{
	if(Index < 0 || Index >(s32)Files.size())
		return nullptr;

	return Files[Index].Name.c_str();
}

const char* CFileList::GetFullFileName(s32 Index)
{
	if(Index < 0 || Index >(s32)Files.size())
		return nullptr;

	if(Files[Index].FullName.size() < Files[Index].Name.size())
	{
		// create full name
		Files[Index].FullName = Path;

		if(Path.size() > 3)
			Files[Index].FullName.append("/");

		Files[Index].FullName.append(Files[Index].Name);
	}

	return Files[Index].FullName.c_str();
}

bool CFileList::IsDirectory(s32 Index)
{
	if(Index < 0 || Index >(s32)Files.size())
		return false;

	return Files[Index].IsDirectory;
}
