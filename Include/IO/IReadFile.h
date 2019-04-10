// Interface providing Read acess to a file.
// Updated 5-1-07

#ifndef __IREADFILE_H__
#define __IREADFILE_H__

#include "Defines.h"

namespace IO
{
	class CORE_EXPORT IReadFile
	{
	public:
		virtual ~IReadFile() {};

		// Reads the entire file into the buffer
		virtual s32 Read(void* Buffer) = 0;

		// Reads an amount of bytes from the file.
		virtual s32 Read(void* Buffer, s32 SizeToRead) = 0;

		// Changes position in file, returns true if successful.
		virtual bool Seek(s32 FinalPos, bool RelativeMovement = false) = 0;

		// Returns Size of file.
		virtual u32 GetSize() = 0;

		// Returns the current position in the file.
		virtual s32 GetPos() = 0;

		// Returns name of file.
		virtual const char* GetFileName() = 0;
	};

	// Internal methods.
	IReadFile* CreateReadFile(const char* FileName);
	IReadFile* CreateLimitReadFile(const char* FileName, IReadFile* AlreadyOpenedFile, s32 AreaSize);
	IReadFile* CreateMemoryReadFile(void* Memory, s32 Size, const char* FileName, bool DeleteMemoryWhenDropped);

} // End namespace IO

#endif

