// Class for reading from Memory.
// Updated 5-7-07

#ifndef __CMEMORYREADFILE_H__
#define __CMEMORYREADFILE_H__

#include "IReadFile.h"

namespace IO
{
	class CORE_EXPORT CMemoryReadFile : public IReadFile
	{
	private:
		String	FileName;
		void*	m_Buffer;
		u32	Len;
		u32	Pos;
		bool	isDeleteMemoryWhenDropped;

	public:
		CMemoryReadFile(void* Memory, s32 Length, const char* Filename, bool DeleteMemoryWhenDropped);

		virtual ~CMemoryReadFile();
		virtual s32 Read(void* Buffer);
		virtual s32 Read(void* Buffer, s32 SizeToRead);
		virtual bool Seek(s32 FinalPos, bool RelativeMovement = false);

		virtual u32 GetSize()			  { return Len; }
		virtual s32 GetPos()			  { return Pos; }
		virtual const char* GetFileName() { return FileName.c_str(); }
	
	};

} // End namespace IO

#endif

