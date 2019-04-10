/* The FileSystem manages files and archives and provides access to them. It manages where files are, so that modules which use the the IO 
 * do not need to know where every File is located. A File could be in a .zip-Archive or as File on disk, using the IFileSystem 
 * makes no difference to this.
 * Original 5-1-07, Updated 5-30-07 (GetFileExtension) 6-14-07 (AddFolderFileArchive)
*/

#ifndef __IFILESYSTEM_H__
#define __IFILESYSTEM_H__

#include "IXMLReader.h"

namespace IO
{
	class IReadFile;
	class IWriteFile;
	class IFileList;
	class IXMLWriter;
	class IAttributes;

	class CORE_EXPORT IFileSystem
	{
	public:
		virtual ~IFileSystem() {};

		// Opens a File for Read access.
		virtual IReadFile* CreateAndOpenFile(const char* FileName) = 0;

		// Opens a File for write access.
		virtual IWriteFile* CreateAndWriteFile(const char* FileName, bool append = false, bool isBinary = true) = 0;

		// Adds an unzipped archive (or base dir/w subdirectories) to the file system, useful for handling data which will be in a zip file
		virtual bool AddFolderFileArchive(const char* FileName, bool IgnoreCase = true, bool IgnorePaths = true) = 0;

		/* Adds an zip archive to the File system. After calling this, the Irrlicht Engine will search and open files directly from 
		 * this archive too. This is useful for hiding data from the End user, speeding up File access and making it possible to
		 * access for example Quake3 .pk3 files, which are nothing different than .zip files. */
		virtual bool AddZipFileArchive(const char* FileName, bool IgnoreCase = true, bool IgnorePaths = true) = 0;

		// Adds unzipped archive(or basedirectory with subdirectories..) to File system. Useful for handling data which will be in a zip File
		virtual bool AddUnZipFileArchive(const char* FileName, bool IgnoreCase = true, bool IgnorePaths = true) = 0;
		
		// Adds an pak archive to the File system.
		virtual bool AddPakFileArchive(const char* FileName, bool IgnoreCase = true, bool IgnorePaths = true) = 0;

		// Returns the string of the current working directory.
		virtual const char* GetWorkingDirectory() = 0;

		// Changes the current Working Directory to the overgiven string.
		virtual bool ChangeWorkingDirectoryTo(const char* NewDirectory) = 0;

		// Converts a relative path to an absolute(unique) path, resolving symbolic links if required
		virtual String GetAbsolutePath(String& FileName) = 0;

		// Returns the directory a file is located in.
		virtual String GetFileDir(String &FileName) = 0;

		// Creates a list of files and directories in the current working directory and returns it.
		virtual IFileList* CreateFileList() = 0;

		// Determinates if a File exists and would be able to be opened.
		virtual bool ExistFile(const char* FileName) = 0;

		// Creates a XML Reader from a File which returns all parsed strings as wide characters(char*).
		virtual IXMLReader* CreateXMLReader(const char* FileName) = 0;

		// Creates a XML Reader from a File which returns all parsed strings as wide characters(char*).
		virtual IXMLReader* CreateXMLReader(IReadFile* File) = 0;

		// Creates a XML Writer from a File.
		virtual IXMLWriter* CreateXMLWriter(const char* FileName) = 0;

		// Creates a XML Writer from a File.
		virtual IXMLWriter* CreateXMLWriter(IWriteFile* File) = 0;
	};

} // End namespace IO


#endif

