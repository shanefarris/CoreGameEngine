// FileSystem which uses normal files and one zipfile.
// Original 5-1-07, Updated 5-30-7 (GetFileExtension)

#ifndef __CFILESYSTEM_H__
#define __CFILESYSTEM_H__

#include "IFileSystem.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>

#ifdef _WINDOWS
#include <direct.h> // for _chdir
#endif

namespace IO
{
	class IReadFile;
	class IWriteFile;
	class CZipReader;
	class CPakReader;
	class CUnZipReader;
	const s32 FILE_SYSTEM_MAX_PATH = 1024;

	class CORE_EXPORT CFileSystem : public IFileSystem
	{
	private:
		std::vector<CZipReader*>	ZipFileSystems;
		std::vector<CPakReader*>	PakFileSystems;
		std::vector<CUnZipReader*>	UnZipFileSystems;
		char WorkingDirectory[FILE_SYSTEM_MAX_PATH];

	public:
		CFileSystem();
		~CFileSystem();

		IReadFile*		CreateAndOpenFile(const char* FileName);
		IWriteFile*		CreateAndWriteFile(const char* FileName, bool append = false, bool isBinary = true);
		bool			AddZipFileArchive(const char* FileName, bool IgnoreCase = true, bool IgnorePaths = true);
		bool			AddFolderFileArchive(const char* FileName, bool IgnoreCase = true, bool IgnorePaths = true);
		bool			AddUnZipFileArchive(const char* FileName, bool IgnoreCase = true, bool IgnorePaths = true);
		bool			AddPakFileArchive(const char* FileName, bool IgnoreCase = true, bool IgnorePaths = true);
		const char*		GetWorkingDirectory();
		bool			ChangeWorkingDirectoryTo(const char* newDirectory);
		std::string		GetAbsolutePath(std::string& FileName);
		std::string		GetFileDir(std::string &FileName);
		IFileList*		CreateFileList();
		IXMLReader*		CreateXMLReader(const char* FileName);
		IXMLReader*		CreateXMLReader(IReadFile* File);
		IXMLWriter*		CreateXMLWriter(const char* FileName);
		IXMLWriter*		CreateXMLWriter(IWriteFile* File);
		bool			ExistFile(const char* FileName);				// File exist in loaded files
		static bool		IsFileExist(const char* FileName);				// Does the file exist on the computer
		static String   GetFileExtension(const std::string& FileName);
	};
}

#endif

