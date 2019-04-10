// Updated 5-8-07

#include "CReadFile.h"
#include <stdio.h>

using namespace IO;

namespace IO
{
	IReadFile* CreateReadFile(const char* Filename)
	{
		CReadFile* file = new CReadFile(Filename);
		if(file->IsOpen())
			return file;

		return nullptr;
	}
}

CReadFile::CReadFile(const char* Filename) : FileSize(0)
{
	FileName = Filename;
	OpenFile();
}

CReadFile::~CReadFile()
{
	if(m_File)
		fclose(m_File);
}

s32 CReadFile::Read(void* Buffer)
{
	if(!IsOpen())
		return 0;

	return (s32)fread(Buffer, 1, FileSize, m_File);
}

s32 CReadFile::Read(void* Buffer, s32 ReadSize)
{
	if(!IsOpen())
		return 0;

	return (s32)fread(Buffer, 1, ReadSize, m_File);
}

bool CReadFile::Seek(s32 FinalPos, bool RelativeMovement)
{
	if(!IsOpen())
		return false;

	return fseek(m_File, FinalPos, RelativeMovement ? SEEK_CUR : SEEK_SET) == 0;
}

void CReadFile::OpenFile()
{
	if(FileName.size() == 0)
	{
		m_File = nullptr;
		return; 
	}

	m_File = fopen(FileName.c_str(), "rb");
	if(m_File)
	{
		// Get FileSize
		fseek(m_File, 0, SEEK_END);
		FileSize = ftell(m_File);
		fseek(m_File, 0, SEEK_SET);
	}
}
