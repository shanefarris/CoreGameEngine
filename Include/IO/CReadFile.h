// Class for reading a real file from disk, implements IReadFile
// Updated 5-8-07

#ifndef __CREADFILE_H__
#define __CREADFILE_H__

#include "IReadFile.h"

namespace IO
{
	class CORE_EXPORT CReadFile : public IReadFile
	{
	private:
		String  FileName;
		FILE*   m_File;
		u32   FileSize;

		void OpenFile();

	public:
		CReadFile(const char* Filename);
		virtual ~CReadFile();

		virtual s32 Read(void* Buffer);
		virtual s32 Read(void* Buffer, s32 ReadSize);
		virtual bool Seek(s32 FinalPos, bool RelativeMovement = false);
		virtual u32 GetSize()			  { return FileSize; }
		virtual s32 GetPos()			  { return ftell(m_File); }
		virtual const char* GetFileName() { return FileName.c_str(); }
		inline bool IsOpen()			  { return m_File != nullptr; }

	};

} // End namespace IO

#endif

