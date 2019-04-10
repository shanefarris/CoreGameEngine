// Interface providing write acess to a file.
// Updated 5-1-07

#ifndef __IWRITEFILE_H__
#define __IWRITEFILE_H__

#include "Defines.h"

namespace IO
{
	class CORE_EXPORT IWriteFile
	{
	public:
		virtual ~IWriteFile() {};

		// Reads an amount of bytes from the file.
		virtual u32 Write(const void* Buffer, u32 SizeToWrite) = 0;

		// Changes position in file, returns true if successful.
		virtual bool Seek(s32 finalPos, bool relativeMovement = false) = 0;

		// Returns the current position in the file.
		virtual s32 GetPos() = 0;

		// Returns name of file.
		virtual const char* GetFileName() = 0;
	};

	// Internal function, please do not use.
	IWriteFile* CreateWriteFile(const char* FileName, bool append, bool isBinary = true);

} // End namespace IO

#endif

