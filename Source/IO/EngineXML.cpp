// Implementation of the File Read callback for ordinary files
// Updated 5-8-07

#include "IXMLReader.h"
#include <string>
#include <vector>
#include "fast_atof.h"
#include "CXMLReaderImpl.h"

using namespace IO;

class CFileReadCallBack : public IFileReadCallBack
{
private:
	FILE* m_File;
	int   Size;
	bool  Close;

	void GetFileSize()		// Retrieves the File Size of the open File
	{
		fseek(m_File, 0, SEEK_END);
		Size = ftell(m_File);
		fseek(m_File, 0, SEEK_SET);
	}

public:
	CFileReadCallBack(const char* Filename) : m_File(0), Size(0), Close(true)
	{
		m_File = fopen(Filename, "rb");		// open File
		if(m_File)
			GetFileSize();
	}

	// Construct from FILE pointer
	CFileReadCallBack(FILE* File) : m_File(File), Size(0), Close(false)
	{
		if(m_File)
			GetFileSize();
	}

	// Destructor
	virtual ~CFileReadCallBack()
	{
		if(Close && m_File)
			fclose(m_File);
	}

	// Reads an amount of bytes from the File.
	virtual int Read(void* Buffer, int ReadSize)
	{
		if(!m_File)
			return 0;

		return(int)fread(Buffer, 1, ReadSize, m_File);
	}

	// Returns Size of File in bytes
	virtual int GetSize() { return Size; }

};

// ================FACTORY FUNCTIONS===============================

// Creates an instance of an UFT-8 or ASCII character xml parser. 
IXMLReader* CreateXMLReader(const char* Filename)
{
	return new CXMLReaderImpl(new CFileReadCallBack(Filename)); 
}

// Creates an instance of an UFT-8 or ASCII character xml parser. 
IXMLReader* CreateXMLReader(FILE* File)
{
	return new CXMLReaderImpl(new CFileReadCallBack(File)); 
}

// Creates an instance of an UFT-8 or ASCII character xml parser. 
IXMLReader* CreateXMLReader(IFileReadCallBack* callback)
{
	return new CXMLReaderImpl(callback, false); 
}
