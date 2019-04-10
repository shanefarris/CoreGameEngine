// Updated 5-7-07

#include "CMemoryReadFile.h"
#include <string.h>

using namespace IO;

namespace IO
{
	IReadFile* CreateMemoryReadFile(void* Memory, s32 Size, const char* Filename, bool DeleteMemoryWhenDropped)
	{
		CMemoryReadFile* File = new CMemoryReadFile(Memory, Size, Filename, DeleteMemoryWhenDropped);
		return File;
	}
}
	
CMemoryReadFile::CMemoryReadFile(void* Memory, s32 Length, const char* Filename, bool DeleteMemoryWhenDropped)
{
	m_Buffer = Memory;
	Len		 = Length;
	Pos		 = 0;
	FileName = Filename;
	isDeleteMemoryWhenDropped = DeleteMemoryWhenDropped;
}

CMemoryReadFile::~CMemoryReadFile()
{
	if(isDeleteMemoryWhenDropped)
		delete [](char*)m_Buffer;
}

s32 CMemoryReadFile::Read(void* Buffer)
{
	s32 amount = sizeof(Buffer);
	if(Pos + amount > Len)
		amount -= Pos + amount - Len;

	if(amount < 0)
		amount = 0;

	char* p =(char*)m_Buffer;
	memcpy(Buffer, p + Pos, amount);
	
	Pos += static_cast<u32>(amount);

	return amount;
}

s32 CMemoryReadFile::Read(void* Buffer, s32 sizeToRead)
{
	s32 amount = sizeToRead;
	if(Pos + amount > Len)
		amount -= Pos + amount - Len;

	if(amount < 0)
		amount = 0;

	char* p =(char*)m_Buffer;
	memcpy(Buffer, p + Pos, amount);
	
	Pos += static_cast<u32>(amount);

	return amount;
}

bool CMemoryReadFile::Seek(s32 FinalPos, bool RelativeMovement)
{
	if(RelativeMovement)
	{
		if(Pos + FinalPos > Len)
			return false;

		Pos += FinalPos;
	}
	else
	{
		if((unsigned) FinalPos > Len)
			return false;
		
        Pos = FinalPos;
	}

	return true;
}
