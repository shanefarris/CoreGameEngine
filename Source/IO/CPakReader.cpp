// Updated 5-8-07

#include <string.h>
#include <algorithm>
#include "CPakReader.h"

using namespace IO;

CPakReader::CPakReader(IReadFile* File, bool ignoreCase, bool ignorePaths): m_File(File), IgnoreCase(ignoreCase), IgnorePaths(ignorePaths)
{
	if(m_File)
	{
		ScanLocalHeader();		// Scan local headers
	}
}

CPakReader::~CPakReader()
{
	CORE_DELETE(m_File);
}

void CPakReader::ExtractFilename(SPakFileEntry* Entry)
{
	s32 lorfn = 56;	// Length of real File name

	if(!lorfn)
		return;

	if(IgnoreCase)
		std::transform(Entry->PakFileName.begin(), Entry->PakFileName.end(), Entry->PakFileName.begin(), tolower);

	const char* p = Entry->PakFileName.c_str() + lorfn;
	while(*p!='/' && p!=Entry->PakFileName.c_str())
	{
		--p;
		--lorfn;
	}

	bool thereIsAPath = p != Entry->PakFileName.c_str();

	if(thereIsAPath)		// there is a Path
	{
		++p;
		++lorfn;
	}

	Entry->SimpleFileName = p;
	Entry->Path = "";

	if(thereIsAPath)
	{
		lorfn =(s32)(p - Entry->PakFileName.c_str());
		Entry->Path += Entry->PakFileName;
		Entry->Path += lorfn;
	}

	if(!IgnorePaths)
		Entry->SimpleFileName = Entry->PakFileName;
}

bool CPakReader::ScanLocalHeader()
{
	char tmp[1024];

	SPakFileEntry Entry;
	Entry.Position = 0;

	memset(&m_Header, 0, sizeof(SPAKFileHeader));
	m_File->Read(&m_Header, sizeof(SPAKFileHeader));


	if(m_Header.tag[0] != 'P' && m_Header.tag[1] != 'A')
		return false;		// local File headers End here.

	m_File->Seek(m_Header.offset);

	int count = m_Header.Length /((sizeof(u32) * 2) + 56);

	for(int i = 0; i < count; i++)
	{
		// Read Filename
		Entry.PakFileName.reserve(56+2);
		m_File->Read(tmp, 56);
		tmp[56] = 0x0;
		Entry.PakFileName = tmp;

		ExtractFilename(&Entry);

		m_File->Read(&Entry.Position, sizeof(u32));
		m_File->Read(&Entry.Length, sizeof(u32));
		FileList.push_back(Entry);
	}

	return true;
}

IReadFile* CPakReader::OpenFile(const char* Filename)
{
	s32 Index = FindFile(Filename);

	if(Index != -1)
		return OpenFile(Index);

	return nullptr;
}

IReadFile* CPakReader::OpenFile(s32 Index)
{
	m_File->Seek(FileList[Index].Position);
	return CreateLimitReadFile(FileList[Index].SimpleFileName.c_str(), m_File, FileList[Index].Length);
}

const SPakFileEntry* CPakReader::GetFileInfo(s32 Index) const
{
	return &FileList[Index];
}

void CPakReader::DeletePathFromFilename(String& Filename)
{
	// Delete Path from Filename
	const char* p = Filename.c_str() + Filename.size();
	while(*p!='/' && *p!='\\' && p!=Filename.c_str())
		--p;

	String newName;

	if(p != Filename.c_str())
	{
		++p;
		Filename = p;
	}
}

s32 CPakReader::FindFile(const char* simpleFilename)
{
	SPakFileEntry Entry;
	Entry.SimpleFileName = simpleFilename;

	if(IgnoreCase)
		std::transform(Entry.SimpleFileName.begin(), Entry.SimpleFileName.end(), Entry.SimpleFileName.begin(), tolower);

	if(IgnorePaths)
		DeletePathFromFilename(Entry.SimpleFileName);

	s32 ret = 0;
	for(std::vector<SPakFileEntry>::iterator i = FileList.begin(); i != FileList.end(); i++)
	{
		if(FileList[ret] == Entry)
			return ret;
	}

	return -1;
}
