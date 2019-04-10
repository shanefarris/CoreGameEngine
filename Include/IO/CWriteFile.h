// Class for writing a real file to disk, implements IWriteFile
// Updated 5-8-07

#ifndef __CWRITEFILE_H__
#define __CWRITEFILE_H__

#include "IWriteFile.h"

namespace IO
{
	class CORE_EXPORT CWriteFile : public IWriteFile
	{
	private:
		String Filename;
		FILE*   m_File;
		s32	FileSize;

		void OpenFile(bool append, bool isBinary = true);		

	public:
		CWriteFile(const char* Filename, bool append, bool isBinary = true);
		virtual ~CWriteFile();

		virtual u32 Write(const void* Buffer, u32 WriteSize);
		virtual bool Seek(s32 FinalPos, bool RelativeMovement = false);
		virtual s32 GetPos()				{ return ftell(m_File); }
		virtual const char* GetFileName()	{ return Filename.c_str(); }
		inline bool IsOpen()				{ return m_File != nullptr; }

	};

} // End namespace IO

#endif

