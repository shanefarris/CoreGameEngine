// Class for reading a real file from disk, implements IReadFile
// Updated 5-8-07

#ifndef __CASYNREADFILE_H__
#define __CASYNREADFILE_H__

#include "IReadFile.h"
#include "Windows.h"
#include <stdio.h>
#include <string>

#define NUMBER_OF_BLOCKS 8

namespace IO
{
	class CORE_EXPORT CAsynReadFile : public IReadFile
	{
	private:
		static const int NumBlocks = NUMBER_OF_BLOCKS;

		FILE*	   m_File;
		char*	   m_Blocks[NumBlocks];
		OVERLAPPED m_Overlapped[NumBlocks];
		
		std::string FileName;
		u32			FileSize;
		s32			WriterPos;
		s32			ReaderPos;
		u32			IOPos;
		u32			Pos;
		s32			NumBlocksMask;
		s32			BlockSize;
		

	public:
		CAsynReadFile(const char* Filename);
		~CAsynReadFile();

		s32 Read(void* Buffer);
		s32 Read(void* Buffer, s32 ReadSize);
		bool  Seek(s32 FinalPos, bool RelativeMovement = false);
		inline u32  GetSize() { return FileSize; }
		inline s32 GetPos() { return ReaderPos; }
		inline s32 GetNumBlocks() { return NumBlocks; }
		inline s32 GetNumBlocksMask() { return NumBlocksMask; }
		inline s32 GetBlockSize() { return BlockSize; }
		inline const char* GetFileName() { return FileName.c_str(); }
		inline bool IsOpen() { return m_File != 0; }

	};
} // End namespace IO

#endif
