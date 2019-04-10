// Updated 5-8-07

#include "CZipReader.h"
#include "IReadFile.h"
#include "IFileSystem.h"
#include "CFileList.h"
#include "zlib.h"

#include <string.h>
#include <vector>
#include <algorithm>

using namespace IO;

CZipReader::CZipReader(IReadFile* File, bool IgnoreCase, bool IgnorePaths): m_File(File), isIgnoreCase(IgnoreCase), isIgnorePaths(IgnorePaths)
{
	if(m_File)
	{
		while(scanLocalHeader());	// scan local headers
		//FileList.Sort();			// prepare File Index for binary search
	}
}

CZipReader::~CZipReader()
{
	CORE_DELETE(m_File);
}

void CZipReader::ExtractFilename(SZipFileEntry* entry)
{
	s32 lorfn = entry->header.FilenameLength; // length of real File name

	if(!lorfn)
		return;

	if(isIgnoreCase)
		std::transform(entry->zipFileName.begin(), entry->zipFileName.end(), entry->zipFileName.begin(), tolower);

	const char* p = entry->zipFileName.c_str() + lorfn;
	while(*p!='/' && p!=entry->zipFileName.c_str())
	{
		--p;
		--lorfn;
	}

	bool thereIsAPath = p != entry->zipFileName.c_str();
	if(thereIsAPath)
	{
		// there is a path
		++p;
		++lorfn;
	}

	entry->simpleFileName = p;
	entry->path = "";

	if(thereIsAPath)
	{
		lorfn =(s32)(p - entry->zipFileName.c_str());
		entry->path = entry->zipFileName.substr(0, lorfn);
	}

	if(!isIgnorePaths)
		entry->simpleFileName = entry->zipFileName; // thanks to Pr3t3nd3r for this fix
}

bool CZipReader::scanLocalHeader()
{
	char tmp[1024];

	SZipFileEntry entry;
	entry.fileDataPosition = 0;
	memset(&entry.header, 0, sizeof(SZIPFileHeader));

	m_File->Read(&entry.header, sizeof(SZIPFileHeader));

	if(entry.header.Sig != 0x04034b50)
		return false; // local File headers End here.

	// Read Filename
	entry.zipFileName.reserve(entry.header.FilenameLength+2);
	m_File->Read(tmp, entry.header.FilenameLength);
	tmp[entry.header.FilenameLength] = 0x0;
	entry.zipFileName = tmp;

	ExtractFilename(&entry);

	// move forward length of extra field.
	if(entry.header.ExtraFieldLength)
		m_File->Seek(entry.header.ExtraFieldLength, true);

	// if bit 3 was set, Read DataDescriptor, following after the compressed data
	if(entry.header.GeneralBitFlag & ZIP_INFO_IN_DATA_DESCRITOR)
	{
		// Read data descriptor
		m_File->Read(&entry.header.DataDescriptor, sizeof(entry.header.DataDescriptor));
	}

	entry.fileDataPosition = m_File->GetPos();	// store position in File
	m_File->Seek(entry.header.DataDescriptor.CompressedSize, true);	// move forward length of data
	FileList.push_back(entry);

	return true;
}

IReadFile* CZipReader::OpenFile(const char* Filename)
{
	s32 Index = FindFile(Filename);
	if(Index != -1)
		return OpenFile(Index);

	return nullptr;
}

IReadFile* CZipReader::OpenFile(s32 Index)
{
	//0 - The File is stored(no compression)
	//1 - The File is Shrunk
	//2 - The File is Reduced with compression factor 1
	//3 - The File is Reduced with compression factor 2
	//4 - The File is Reduced with compression factor 3
	//5 - The File is Reduced with compression factor 4
	//6 - The File is Imploded
	//7 - Reserved for Tokenizing compression algorithm
	//8 - The File is Deflated
	//9 - Reserved for enhanced Deflating
	//10 - PKWARE Date Compression Library Imploding

	switch(FileList[Index].header.CompressionMethod)
	{
	case 0: // no compression
		{
			m_File->Seek(FileList[Index].fileDataPosition);
			return CreateLimitReadFile(FileList[Index].simpleFileName.c_str(), m_File, FileList[Index].header.DataDescriptor.UncompressedSize);
		}
	case 8:
		{
  			#ifdef _COMPILE_WITH_ZLIB_
			
			u32 uncompressedSize = FileList[Index].header.DataDescriptor.UncompressedSize;			
			u32 compressedSize = FileList[Index].header.DataDescriptor.CompressedSize;

			void* pBuf = new char[uncompressedSize];
			if(!pBuf)
			{
				Printer::Log("Not enough memory for decompressing", FileList[Index].simpleFileName.c_str(), LOG_ERROR);
				return nullptr;
			}

			char *pcData = new char[ compressedSize ];
			if(!pcData)
			{
				Printer::Log("Not enough memory for decompressing", FileList[Index].simpleFileName.c_str(), LOG_ERROR);
				return nullptr;
			}

			//memset(pcData, 0, compressedSize);
			m_File->Seek(FileList[Index].fileDataPosition);
			m_File->Read(pcData, compressedSize);
			
			// Setup the inflate stream.
			z_stream stream;
			s32 err;

			stream.next_in =(Bytef*)pcData;
			stream.avail_in =(uInt)compressedSize;
			stream.next_out =(Bytef*)pBuf;
			stream.avail_out = uncompressedSize;
			stream.zalloc =(alloc_func)0;
			stream.zfree =(free_func)0;

			// Perform inflation. wbits < 0 indicates no zlib header inside the data.
			err = inflateInit2(&stream, -MAX_WBITS);
			if(err == Z_OK)
			{
				err = inflate(&stream, Z_FINISH);
				inflateEnd(&stream);
				if(err == Z_STREAM_END)
					err = Z_OK;

				err = Z_OK;
				inflateEnd(&stream);
			}

			delete[] pcData;
			if(err != Z_OK)
			{
				Printer::Log("Error decompressing", FileList[Index].simpleFileName.c_str(), LOG_ERROR);
				delete [](char*)pBuf;
				return nullptr;
			}
			else
				return IO::CreateMemoryReadFile(pBuf, uncompressedSize, FileList[Index].simpleFileName.c_str(), true);
			
			#else
			return nullptr; // zlib not compiled, we cannot decompress the data.
			#endif
		}
	default:
		return nullptr;
	};
}

u32 CZipReader::GetFileCount()
{
	return (u32)FileList.size();
}

const SZipFileEntry* CZipReader::GetFileInfo(s32 Index) const
{
	return &FileList[Index];
}

void CZipReader::DeletePathFromFilename(String& Filename)
{
	// Delete path from Filename
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

s32 CZipReader::FindFile(const char* simpleFilename)
{
	SZipFileEntry Entry;
	Entry.simpleFileName = simpleFilename;

	if(isIgnoreCase)
		std::transform(Entry.simpleFileName.begin(), Entry.simpleFileName.end(), Entry.simpleFileName.begin(), tolower);

	if(isIgnorePaths)
		DeletePathFromFilename(Entry.simpleFileName);

	s32 ret = 0;
	for(std::vector<SZipFileEntry>::iterator i = FileList.begin(); i != FileList.end(); i++)
	{
		if(FileList[ret] == Entry)
			return ret;
	}

	return -1;
}

CUnZipReader::CUnZipReader(IFileSystem * Parent, const char* BaseName, bool IgnoreCase, bool IgnorePaths) :CZipReader(0, IgnoreCase, IgnorePaths), m_Parent(Parent)
{
	Base = BaseName;
	if(	Base [ Base.size() - 1 ] != '\\' || Base [ Base.size() - 1 ] != '/')
		Base += "/";
}

void CUnZipReader::BuildDirectory()
{
}

IReadFile* CUnZipReader::OpenFile(const char* Filename)
{
	IReadFile* File;
	String fname;
	fname = Base;
	fname += Filename;

	File = CreateReadFile(fname.c_str());
	return File;
}

s32 CUnZipReader::FindFile(const char* Filename)
{
	IReadFile *File = OpenFile(Filename);
	if(0 == File)
		return -1;

	return 1;
}
