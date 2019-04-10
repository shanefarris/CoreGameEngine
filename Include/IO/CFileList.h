//FileSystem, which manages where files are, so that modules which use the io do not need to know where every file is located.
// Updated 5-1-07

#ifndef __CFILELIST_H__
#define __CFILELIST_H__

#include "IFileList.h"

namespace IO
{
	class CORE_EXPORT CFileList : public IFileList
	{
	private:
		struct FileEntry
		{
			String Name;
			String FullName;
			s32   Size;
			bool    IsDirectory;
			bool operator<(const struct FileEntry& Other) const {return Name < Other.Name;}
		};

		String Path;
		std::vector<FileEntry> Files;

	public:
		CFileList();
		virtual ~CFileList() { }

		virtual u32 GetFileCount();
		virtual const char* GetFileName(s32 Index);
		virtual const char* GetFullFileName(s32 Index);
		virtual bool IsDirectory(s32 Index);
	};
} // End namespace IO


#endif

