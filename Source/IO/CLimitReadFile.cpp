// Updated 5-7-07

#include "CLimitReadFile.h"
#include <string>

using namespace IO;

namespace IO
{
	IReadFile* CreateLimitReadFile(const char* FileName, IReadFile* File, s32 AreaSize)
	{
		return new CLimitReadFile(File, AreaSize, FileName);
	}
} 

CLimitReadFile::CLimitReadFile(IReadFile* File, s32 areaSize, const char* name): AreaSize(areaSize), m_File(File), Filename(name)
{
	Init();
}

void CLimitReadFile::Init()
{
	if(!m_File)
		return;

	AreaStart = m_File->GetPos();
	AreaEnd = AreaStart + AreaSize;
}

CLimitReadFile::~CLimitReadFile()
{
	CORE_DELETE(m_File);
}

s32 CLimitReadFile::Read(void* buffer)
{
	s32 pos = m_File->GetPos();

	if(pos >= AreaEnd)
		return 0;

	return m_File->Read(buffer, (AreaEnd - pos));
}

s32 CLimitReadFile::Read(void* buffer, s32 sizeToRead)
{
	s32 pos = m_File->GetPos();

	if(pos >= AreaEnd)
		return 0;

	if(pos + sizeToRead >= AreaEnd)
		sizeToRead = AreaEnd - pos;

	return m_File->Read(buffer, sizeToRead);
}

bool CLimitReadFile::Seek(s32 finalPos, bool relativeMovement)
{
	s32 pos = m_File->GetPos();

	if(relativeMovement)
	{
		if(pos + finalPos > AreaEnd)
			finalPos = AreaEnd - pos;
	}
	else
	{
		finalPos += AreaStart;
		if((s32)finalPos > AreaEnd)
			return false;
	}

	return m_File->Seek(finalPos, relativeMovement);	
}

