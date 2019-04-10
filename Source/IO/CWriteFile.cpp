// Updated 5-8-07

#include "CWriteFile.h"
#include <stdio.h>

using namespace IO;

namespace IO
{
	IWriteFile* CreateWriteFile(const char* FileName, bool append, bool isBinary)
	{
		CWriteFile* file = new CWriteFile(FileName, append, isBinary);
		if(file->IsOpen())
			return file;

		return nullptr;
	}
}

CWriteFile::CWriteFile(const char* FileName, bool append, bool isBinary) : FileSize(0)
{
	Filename = FileName;
	OpenFile(append, isBinary);
}

CWriteFile::~CWriteFile()
{
	if(m_File)
		fclose(m_File);
}

u32 CWriteFile::Write(const void* Buffer, u32 WriteSize)
{
	if(!IsOpen())
		return 0;

	return (u32)fwrite(Buffer, 1, WriteSize, m_File);
}

bool CWriteFile::Seek(s32 FinalPos, bool RelativeMovement)
{
	if(!IsOpen())
		return false;

	return fseek(m_File, FinalPos, RelativeMovement ? SEEK_CUR : SEEK_SET) == 0;
}

void CWriteFile::OpenFile(bool append, bool isBinary)
{
	if(Filename.size() == 0)
	{
		m_File = nullptr;
		return; 
	}

	if(isBinary)
		m_File = fopen(Filename.c_str(), append ? "ab" : "wb");
	else
		m_File = fopen(Filename.c_str(), append ? "ab" : "w");

	if(m_File)
	{
		// Get FileSize
		fseek(m_File, 0, SEEK_END);
		FileSize = ftell(m_File);
		fseek(m_File, 0, SEEK_SET);
	}
}
