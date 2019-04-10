// Original 5-1-07, Updated 5-30-7 (GetFileExtention)

#include "CFileSystem.h"
#include "IReadFile.h"
#include "IWriteFile.h"
#include "CZipReader.h"
#include "CPakReader.h"
#include "CFileList.h"
#include "CXMLReader.h"
#include "CXMLWriter.h"

#if WIN32
#include "Windows.h"
#endif
#ifdef LINUX
#include "limits.h"
#include "unistd.h"

#define MAX_PATH PATH_MAX
#define _MAX_PATH PATH_MAX
#define _getcwd getcwd
#define _chdir chdir
#endif

using namespace IO;

//namespace IO
//{
//	IFileSystem* CreateFileSystem()
//	{
//		return new CFileSystem();
//	}
//}

CFileSystem::CFileSystem()
{
}

CFileSystem::~CFileSystem()
{
	u32 i;

	for(i = 0; i < ZipFileSystems.size(); ++i)
		CORE_DELETE(ZipFileSystems[i]);

	for(i = 0; i < PakFileSystems.size(); ++i)
		CORE_DELETE(PakFileSystems[i]);

	for(i = 0; i < UnZipFileSystems.size(); ++i)
		CORE_DELETE(UnZipFileSystems[i]);
}

IReadFile* CFileSystem::CreateAndOpenFile(const char* FileName)
{
	IReadFile* File = nullptr;
	u32 i;

	for(i = 0; i < ZipFileSystems.size(); ++i)
	{
		File = ZipFileSystems[i]->OpenFile(FileName);
		if(File)
			return File;
	}

	for(i = 0; i < PakFileSystems.size(); ++i)
	{
		File = PakFileSystems[i]->OpenFile(FileName);
		if(File)
			return File;
	}

	for(i = 0; i < UnZipFileSystems.size(); ++i)
	{
		File = UnZipFileSystems[i]->OpenFile(FileName);
		if(File)
			return File;
	}

	File = CreateReadFile(FileName);
	return File;
}

IWriteFile* CFileSystem::CreateAndWriteFile(const char* FileName, bool append, bool isBinary)
{
	return CreateWriteFile(FileName, append, isBinary);
}

bool CFileSystem::AddUnZipFileArchive(const char* FileName, bool IgnoreCase, bool IgnorePaths)
{
	bool ret = false;

	CUnZipReader* zr = new CUnZipReader(this, FileName, IgnoreCase, IgnorePaths);
	if(zr)
	{
		UnZipFileSystems.push_back(zr);
		ret = true;
	}

	return ret;
}

bool CFileSystem::AddZipFileArchive(const char* FileName, bool IgnoreCase, bool IgnorePaths)
{
	IReadFile* File = CreateReadFile(FileName);
	if(File)
	{
		CZipReader* zr = new CZipReader(File, IgnoreCase, IgnorePaths);
		if(zr)
			ZipFileSystems.push_back(zr);

		bool ret =(zr != 0);
		return ret;
	}

	return false;
}

bool CFileSystem::AddFolderFileArchive(const char* FileName, bool IgnoreCase, bool IgnorePaths)
{
	bool ret = false;
	CUnZipReader* zr = new CUnZipReader(this, FileName, IgnoreCase, IgnorePaths);
	if(zr)
	{
		UnZipFileSystems.push_back(zr);
		ret = true;
	}

	return ret;
}

bool CFileSystem::AddPakFileArchive(const char* FileName, bool IgnoreCase, bool IgnorePaths)
{
	IReadFile* File = CreateReadFile(FileName);
	if(File)
	{
		CPakReader* zr = new CPakReader(File, IgnoreCase, IgnorePaths);
		if(zr)
			PakFileSystems.push_back(zr);

		bool ret =(zr != 0);
		return ret;
	}

	return false;
}

const char* CFileSystem::GetWorkingDirectory()
{
  if (_getcwd(WorkingDirectory, FILE_SYSTEM_MAX_PATH) != nullptr )
    return WorkingDirectory;
  else
	return nullptr;
}

bool CFileSystem::ChangeWorkingDirectoryTo(const char* newDirectory)
{
	bool success = false;
	success = (_chdir(newDirectory) == 0);
	return success;
}

String CFileSystem::GetAbsolutePath(String& FileName)
{
  char *p = nullptr;
  String ret;
  char fpath[ _MAX_PATH ];
  
#ifdef _WIN32
  p = _fullpath(fpath, FileName.c_str(), _MAX_PATH);
  ret = p;
#endif
  
#ifdef LINUX
  p = getcwd(fpath, sizeof(fpath) );
  ret = p;
  ret = ret + FileName;
#endif	
  
  return ret;
}

String CFileSystem::GetFileDir(String &FileName)
{
	String ret;
 
	// Bind last forward or backslash
	auto lastSlash = FileName.find_last_of('/');
	auto lastBackSlash = FileName.find_last_of('\\');

	lastSlash = lastSlash > lastBackSlash ? lastSlash : lastBackSlash;

	if (lastSlash >= 0 && lastSlash < (s32)FileName.size())
		ret = FileName.substr(0, lastSlash);
	else
		ret = ".";

	return ret;
}

String CFileSystem::GetFileExtension(const String& FileName)
{
	auto pos = FileName.find_last_of('.');
	if(pos < 0 || pos == FileName.size())
		return "";
	else
		return FileName.substr(pos + 1, FileName.size() - (pos + 1));
}

IFileList* CFileSystem::CreateFileList()
{
	return new CFileList();
}

bool CFileSystem::ExistFile(const char* FileName)
{
	u32 i;

	for(i = 0; i < ZipFileSystems.size(); ++i)
		if(ZipFileSystems[i]->FindFile(FileName)!=-1)
			return true;

	for(i = 0; i < PakFileSystems.size(); ++i)
		if(PakFileSystems[i]->FindFile(FileName)!=-1)
			return true;

	for(i = 0; i < UnZipFileSystems.size(); ++i)
		if(UnZipFileSystems[i]->FindFile(FileName)!=-1)
			return true;

	FILE* f = fopen(FileName, "rb");
	if(f) 
	{
		fclose(f);
		return true;
	}

	return false;
}

bool CFileSystem::IsFileExist(const char* FileName)
{
#if WIN32
	DWORD fileAttr = GetFileAttributes(FileName);
	return (fileAttr != 0xFFFFFFFF);
#endif
	return false;
}

IXMLReader* CFileSystem::CreateXMLReader(const char* FileName)
{
	IReadFile* File = CreateAndOpenFile(FileName);
	if(!File)
		return nullptr;

	IXMLReader* reader = CreateXMLReader(File);
	return reader;
}

IXMLReader* CFileSystem::CreateXMLReader(IReadFile* File)
{
	if(!File)
		return nullptr;

	return CreateIXMLReader(File);
}

IXMLWriter* CFileSystem::CreateXMLWriter(const char* FileName)
{
	IWriteFile* File = CreateAndWriteFile(FileName, false, false);
	IXMLWriter* Writer = CreateXMLWriter(File);
	return Writer;
}

IXMLWriter* CFileSystem::CreateXMLWriter(IWriteFile* File)
{
	return new CXMLWriter(File);
}
