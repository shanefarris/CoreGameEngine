// Archived files
// Updated 5-8-07

#ifndef __CPAKREADER_H__
#define __CPAKREADER_H__

#include "IReadFile.h"

namespace IO
{
	struct SPAKFileHeader
	{
		char tag[4];
		u32 offset;
		u32 Length;
	};

	struct SPakFileEntry
	{
		String PakFileName;
		String SimpleFileName;
		String Path;
		u32	Position;
		u32	Length;

		bool operator <(const SPakFileEntry& Other) const { return SimpleFileName < Other.SimpleFileName; }
		bool operator ==(const SPakFileEntry& Other) const { return SimpleFileName == Other.SimpleFileName; }
	};


	class CORE_EXPORT CPakReader
	{
	private:
		IReadFile*			 m_File;
		SPAKFileHeader		 m_Header;
		std::vector<SPakFileEntry> FileList;

		bool IgnoreCase;
		bool IgnorePaths;

		bool ScanLocalHeader();										// Scans for a local m_Header, returns false if there is no more local File m_Header.
		void ExtractFilename(SPakFileEntry* Entry);					// Splits Filename from zip File into useful filenames and paths
		void DeletePathFromFilename(String& Filename);				// Deletes the Path from a Filename

	public:
		CPakReader(IReadFile* File, bool ignoreCase, bool ignorePaths);
		virtual ~CPakReader();

		virtual IReadFile* OpenFile(const char* Filename);			// Opens a File by File name
		IReadFile* OpenFile(s32 Index);								// Opens a File by Index
		size_t GetFileCount() { return FileList.size(); }			// Returns count of files in archive
		const SPakFileEntry* GetFileInfo(s32 Index) const;			// Returns data of File
		s32 FindFile(const char* Filename);							// Returns fileindex
	
	};

} // End namespace IO

#endif

