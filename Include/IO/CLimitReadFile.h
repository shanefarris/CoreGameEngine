/* This is a Read file, which is limited to some boundaries, so that it may only Start from a certain file position and may only Read until a certain 
 * file position. This can be useful, for example for reading uncompressed files in an archive(zip).
 * Updated 5-3-07
 */

#ifndef __CLIMITREADFILE_H__
#define __CLIMITREADFILE_H__

#include "IReadFile.h"
#include "Defines.h"

namespace IO
{
	class CUnicodeConverter;

	class CORE_EXPORT CLimitReadFile : public IReadFile
	{
	private:
		String		Filename;
		u32		AreaSize;
		s32		AreaStart;
		s32		AreaEnd;
		IReadFile*	m_File;

		void Init();

	public:
		CLimitReadFile(IReadFile* File, s32 Size, const char* Name);

		virtual ~CLimitReadFile();
		virtual s32 Read(void* Buffer);
		virtual s32 Read(void* Buffer, s32 SizeToRead);
		virtual bool Seek(s32 FinalPos, bool RelativeMovement = false);

		virtual u32 GetSize()				{ return AreaSize; };
		virtual s32 GetPos()				{ return m_File->GetPos() - AreaStart; }
		virtual const char* GetFileName()	{ return Filename.c_str(); }
	
	};

} // End namespace IO

#endif

