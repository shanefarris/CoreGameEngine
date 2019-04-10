/* Interface providing methods for making it easier to write XML files. This XML Writer only writes UTF-16 xml files, because these are parsed 
 * faster than all Other formats by IXMLReader.
 * Updated 5-1-07
 */

#ifndef __IXMLWRITER_H__
#define __IXMLWRITER_H__

#include "Defines.h"

namespace IO
{
	class CORE_EXPORT IXMLWriter
	{
	public:
		virtual ~IXMLWriter() {};

		// Writes a xml 1.0 header
		virtual void WriteXMLHeader() = 0;

		// Writes an xml Element with maximal 5 Attributeibutes like "<foo />" 
		virtual void WriteElement(const char* Name, bool Empty=false,
			const char* Attribute1Name = 0, const char* Attribute1Value = 0,
			const char* Attribute2Name = 0, const char* Attribute2Value = 0,
			const char* Attribute3Name = 0, const char* Attribute3Value = 0,
			const char* Attribute4Name = 0, const char* Attribute4Value = 0,
			const char* Attribute5Name = 0, const char* Attribute5Value = 0) = 0;

		// Writes an xml Element with any number of Attributeibutes
		virtual void WriteElement(const char* Name, bool Empty, std::vector<String> &Names, std::vector<String> &Values) = 0;

		// Writes a comment into the xml file
		virtual void WriteComment(const char* Comment) = 0;

		// Writes the closing tag for an Element. Like "</foo>"
		virtual void WriteClosingTag(const char* Name) = 0;

		// Writes a text into the file. All occurrences of special characters
		virtual void WriteText(const char* Text) = 0;

		// Writes a line break
		virtual void WriteLineBreak() = 0;
	};

} // End namespace IO

#endif

