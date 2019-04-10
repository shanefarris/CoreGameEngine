// The Filelist lists all files in a directory.
// 5-1-07

#ifndef __IFILELIST_H__
#define __IFILELIST_H__

#include "Defines.h"

namespace IO
{
	class CORE_EXPORT IFileList
	{
	public:
		virtual ~IFileList() {};

		// Returns the amount of files and directories in the file list.
		virtual u32 GetFileCount() = 0;

		// Gets the name of a file in the list, based on an index.
		// Returns the file name of the file. Returns 0, if an error occured.
		virtual const char* GetFileName(s32 Index) = 0;

		// Gets the full name of a file in the list, path included, based on an index.
		// Returns the file name of the file. Returns 0, if an error occured.
		virtual const char* GetFullFileName(s32 Index) = 0;

		// Returns of the file is a directory. If an error occurs, the result is undefined.
		virtual bool IsDirectory(s32 Index) = 0;
	};

} // End namespace IO


#endif

