// Front end methods for XML reader
// Updated 5-8-07

#ifndef __CXMLREADER_H__
#define __CXMLREADER_H__

#include "IXMLReader.h"

namespace IO
{
	class IReadFile;
	IXMLReader* CreateIXMLReader(IReadFile* File);

}  

#endif

