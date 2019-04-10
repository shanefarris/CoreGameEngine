// forward-only, Read-only access to a stream of non validated XML data
// Updated 5-1-07

#ifndef __XML_H__
#define __XML_H__

#include "Defines.h"

namespace IO
{
	enum XML_TEXT_FORMAT_TYPE	// Enumeration of all supported source text file formats
	{
		XML_TEXT_ASCII,			// ASCII, file without byte order mark, or not a text file
		XML_TEXT_UTF8,			// UTF-8 format
		XML_TEXT_UTF16_BE,		// UTF-16 format, big endian
		XML_TEXT_UTF16_LE,		// UTF-16 format, little endian
		XML_TEXT_UTF32_BE,		// UTF-32 format, big endian
		XML_TEXT_UTF32_LE		// UTF-32 format, little endian
	};

	enum XML_NODE_TYPE			// Enumeration for all xml nodes which are parsed by XMLReader
	{
		XML_NODE_NONE,			// No xml node. This is usually the node if you did not Read anything yet.
		XML_NODE_ELEMENT,		// An xml Element such as <foo>
		XML_NODE_ELEMENT_END,	// End of an xml Element such as </foo>
		XML_NODE_TEXT,			// Text within an xml Element
		XML_NODE_COMMENT,		// An xml comment
		XML_NODE_CDATA,			// An xml cdata section
		XML_NODE_UNKNOWN
	};

	/* Callback class for file Read abstraction. With this, it is possible to make the xml parser Read in Other things  than just files. 
	 * The engine is using this for example to Read xml from compressed .zip files. To make the parser Read in any Other data, derive a 
	 * class from this interface, implement the two methods to Read your data and give a pointer to an instance of your implementation 
	 * when calling CreateXMLReader(), CreateXMLReader16() or CreateXMLReader32() */
	class CORE_EXPORT IFileReadCallBack
	{
	public:
		virtual ~IFileReadCallBack() {};
		virtual int Read(void* buffer, int sizeToRead) = 0;		// Reads an amount of bytes from the file.
		virtual int GetSize() = 0;								// Returns Size of file in bytes
	};

	// Interface providing easy Read access to a XML file.
	class IXMLReader
	{
	public:
		virtual ~IXMLReader() {};

		// Reads forward to the next xml node. 
		virtual bool Read() = 0;

		// Returns the type of the current XML node.
		virtual XML_NODE_TYPE GetNodeType() const = 0;

        // Returns attribute count of the current XML node.  This is usually non null if the current node is XML_NODE_ELEMENT, and the Element has attributes.
		virtual unsigned int GetAttributeCount() const = 0;

		// Returns Name of an attribute. 
		virtual const char* GetAttributeName(unsigned int Index) const = 0;

		// Returns the value of an attribute. 
		virtual const char* GetAttributeValue(unsigned int Index) const = 0;

		// Returns the value of an attribute. 
		virtual const char* GetAttributeValue(const char* Name) const = 0;

		// Returns the value of an attribute in a safe way.
		virtual const char* GetAttributeValueSafe(const char* Name) const = 0;

		// Returns the value of an attribute as integer. 
		virtual int GetAttributeValueAsInt(const char* Name) const = 0;

		// Returns the value of an attribute as integer. 
		virtual int GetAttributeValueAsInt(unsigned int Index) const = 0;

		// Returns the value of an attribute as float. 
		virtual float GetAttributeValueAsFloat(const char* Name) const = 0;

		// Returns the value of an attribute as float. 
		virtual float GetAttributeValueAsFloat(unsigned int Index) const = 0;

		// Returns the Name of the current node. 
		virtual const char* GetNodeName() const = 0;

		// Returns data of the current node. 
		virtual const char* GetNodeData() const = 0;

		// Returns if an Element is an empty Element, like <foo />
		virtual bool IsEmptyElement() const = 0;

		// Returns format of the source xml file. 
		virtual XML_TEXT_FORMAT_TYPE GetSourceFormat() const = 0;

		// Returns format of the strings returned by the parser. 
		virtual XML_TEXT_FORMAT_TYPE GetParserFormat() const = 0;
	};

	/* Creates an instance of an UFT-8 or ASCII character xml parser. This means that all character data will be returned in 8 bit ASCII or UTF-8.  The file to 
	 * Read can be in any format, it will be converted to UTF8 if it is not in this format. Better not to use this but IFileSystem::CreateXMLReaderUTF8() instead. */
	IXMLReader* CreateXMLReader(const char* FileName);

	// Creates an instance of an UFT-8 or ASCII character xml parser.
	IXMLReader* CreateXMLReader(FILE* file);

	// Creates an instance of an UFT-8 or ASCII character xml parser. 
	IXMLReader* CreateXMLReader(IFileReadCallBack* Callback);

} // End namespace Engine

#endif

