// Updated 5-8-07

#ifndef __CZIPREADER_H__
#define __CZIPREADER_H__

#include "Defines.h"

#pragma pack(push, packing)
#pragma pack(1)
#define PACK_STRUCT

namespace IO
{
	class IReadFile;
	class IFileSystem;

	const short ZIP_FILE_ENCRYPTED		   = 0x0001;	// Set if the File is encrypted
	const short ZIP_INFO_IN_DATA_DESCRITOR = 0x0008;	// The fields crc-32, compressed Size and uncompressed Size are set to zero in the local header

	struct SZIPFileDataDescriptor
	{
		s32 CRC32;
		s32 CompressedSize;
		s32 UncompressedSize;
	} PACK_STRUCT;

	struct SZIPFileHeader
	{
		s32 Sig;
		short VersionToExtract;
		short GeneralBitFlag;
		short CompressionMethod;
		short LastModFileTime;
		short LastModFileDate;
		SZIPFileDataDescriptor DataDescriptor;
		short FilenameLength;
		short ExtraFieldLength;
	} PACK_STRUCT;

	#pragma pack(pop, packing)							// Default alignment
	#undef PACK_STRUCT

	struct SZipFileEntry
	{
		String zipFileName;
		String simpleFileName;
		String path;
		s32	fileDataPosition;						// position of compressed data in File
		SZIPFileHeader header;

		bool operator <(const SZipFileEntry& Other) const { return simpleFileName < Other.simpleFileName; }
		bool operator ==(const SZipFileEntry& Other) const { return simpleFileName == Other.simpleFileName; }
	};

	class CORE_EXPORT CZipReader
	{
	private:
		IReadFile* m_File;
		bool scanLocalHeader();							// Scans for a local header, returns false if there is no more local File header.

	protected:
		bool isIgnoreCase;
		bool isIgnorePaths;
		std::vector<SZipFileEntry> FileList;

		void ExtractFilename(SZipFileEntry* entry);		// Splits Filename from zip File into useful filenames and paths
		void DeletePathFromFilename(String& Filename);	// Deletes the path from a Filename

	public:
		CZipReader(IReadFile* File, bool IgnoreCase, bool IgnorePaths);
		virtual ~CZipReader();

		virtual IReadFile* OpenFile(const char* Filename);
		IReadFile* OpenFile(s32 Index);
		u32 GetFileCount();
		const SZipFileEntry* GetFileInfo(s32 Index) const;
		s32 FindFile(const char* Filename);
	};

	class CORE_EXPORT CUnZipReader : public CZipReader
	{
	private:
		IFileSystem* m_Parent;
		String		 Base;

		void BuildDirectory();

	public:
		CUnZipReader(IFileSystem* Parent, const char* BaseName, bool IgnoreCase, bool IgnorePaths);

		virtual IReadFile* OpenFile(const char* Filename);
		s32 FindFile(const char* Filename);
	
	};
}

#endif

