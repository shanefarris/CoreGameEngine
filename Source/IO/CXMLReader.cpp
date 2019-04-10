// Implementation of the File Read callback for the xml parser
// Updated 5-8-07

#include "CXMLReaderImpl.h"
#include "CXMLReader.h"
#include "IReadFile.h"

namespace IO
{
	class CEngineXMLFileReadCallBack : public IFileReadCallBack
	{
	private:
		IReadFile* ReadFile;

	public:
		CEngineXMLFileReadCallBack(IReadFile* File): ReadFile(File) { }
		virtual ~CEngineXMLFileReadCallBack() { CORE_DELETE(ReadFile); }

		virtual int Read(void* Buffer, int ReadSize) { return ReadFile->Read(Buffer, ReadSize); }
		virtual int GetSize() { return ReadFile->GetSize(); }

	
	}; 

	// Creates an implementation for IXMLReader using EngineXML.
	IXMLReader* CreateIXMLReader(IReadFile* File)
	{
		if(!File)
			return nullptr;

		return new CXMLReaderImpl(new CEngineXMLFileReadCallBack(File)); 
	}
}
