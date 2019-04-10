#ifndef __ICXML_READER_IMPL_H_INCLUDED__
#define __ICXML_READER_IMPL_H_INCLUDED__

#include "IXMLReader.h"
#include "fast_atof.h"
#include "Defines.h"

namespace IO
{
// Implementation of the XMLReader8
class CORE_EXPORT CXMLReaderImpl : public IXMLReader
{
public:
	CXMLReaderImpl(IFileReadCallBack* callback, bool deleteCallBack = true)
		: TextData(0), P(0), TextSize(0), TextBegin(0), CurrentNodeType(XML_NODE_NONE),
		SourceFormat(XML_TEXT_ASCII), TargetFormat(XML_TEXT_ASCII)
	{
		if(!callback)
			return;

		storeTargetFormat();

		// Read whole xml file
		readFile(callback);
		
		// Clean up
		if(deleteCallBack)
			CORE_DELETE(callback);

		// create list with special characters
		createSpecialCharacterList();

		// set pointer to text Begin
		P = TextBegin;
	}
    	
	virtual ~CXMLReaderImpl()
	{
		delete [] TextData;
	}

	// Reads forward to the next xml node.  
	virtual bool Read()
	{
		// if not End reached, parse the node
		if(P &&(u32)(P - TextBegin) < TextSize - 1 && *P != 0)
		{
			parseCurrentNode();
			return true;
		}

		return false;
	}

	// Returns the type of the current XML node.
	virtual XML_NODE_TYPE GetNodeType() const
	{
		return CurrentNodeType;
	}

	// Returns attribute count of the current XML node.
	virtual unsigned int GetAttributeCount() const
	{
		return (unsigned int)Attributes.size();
	}

	// Returns name of an attribute.
	virtual const char* GetAttributeName(unsigned int idx) const
	{
		if(idx < 0 || idx >=(unsigned int)Attributes.size())
			return nullptr;

		return (char*)Attributes[idx].Name.c_str();
	}

	// Returns the value of an attribute. 
	virtual const char* GetAttributeValue(unsigned int idx) const
	{
		if(idx < 0 || idx >=(unsigned int)Attributes.size())
			return nullptr;

		return (char*)Attributes[idx].Value.c_str();
	}

	// Returns the value of an attribute. 
	virtual const char* GetAttributeValue(const char* name) const
	{
		const SAttribute* attr = getAttributeByName(name);
		if(!attr)
			return nullptr;

		return (char*)attr->Value.c_str();
	}

	// Returns the value of an attribute
	virtual const char* GetAttributeValueSafe(const char* name) const
	{
		const SAttribute* attr = getAttributeByName(name);
		if(!attr)
			return (char*)EmptyString.c_str();

		return (char*)attr->Value.c_str();
	}

	// Returns the value of an attribute as integer. 
	int GetAttributeValueAsInt(const char* name) const
	{
		return(int)GetAttributeValueAsFloat(name);
	}

	// Returns the value of an attribute as integer. 
	int GetAttributeValueAsInt(unsigned int idx) const
	{
		return(int)GetAttributeValueAsFloat(idx);
	}

	// Returns the value of an attribute as float. 
	float GetAttributeValueAsFloat(const char* name) const
	{
		const SAttribute* attr = getAttributeByName(name);
		if(!attr)
			return 0;

		String c = attr->Value.c_str();
		return fast_atof(c.c_str());
	}

	// Returns the value of an attribute as float. 
	float GetAttributeValueAsFloat(unsigned int idx) const
	{
		const char* attrvalue = GetAttributeValue(idx);
		if(!attrvalue)
			return 0;

		String c(attrvalue);
		return fast_atof(c.c_str());
	}


	// Returns the name of the current node.
	virtual const char* GetNodeName() const
	{
		return NodeName.c_str();
	}


	// Returns data of the current node.
	virtual const char* GetNodeData() const
	{
		return NodeName.c_str();
	}


	// Returns if an Element is an empty Element, like <foo />
	virtual bool IsEmptyElement() const
	{
		return isEmptyElement;
	}

	// Returns format of the source xml file.
	virtual XML_TEXT_FORMAT_TYPE GetSourceFormat() const
	{
		return SourceFormat;
	}

	// Returns format of the strings returned by the parser.
	virtual XML_TEXT_FORMAT_TYPE GetParserFormat() const
	{
		return TargetFormat;
	}

private:

	// Reads the current xml node
	void parseCurrentNode()
	{
		char* Start = P;

		// more forward until '<' found
		while(*P != L'<' && *P)
			++P;

		if(!*P)
			return;

		if(P - Start > 0)
		{
			// we found some text, store it
			if(SetText(Start, P))
				return;
		}

		++P;

		// based on current token, parse and report next Element
		switch(*P)
		{
		case L'/':
			parseClosingXMLElement(); 
			break;
		case L'?':
			ignoreDefinition();	
			break;
		case L'!':
			if(!parseCDATA())
				parseComment();	
			break;
		default:
			parseOpeningXMLElement();
			break;
		}
	}


	// sets the state that text was found. Returns true if set should be set
	bool SetText(char* Start, char* End)
	{
		// check if text is more than 2 characters, and if not, check if there is 
		// only white space, so that this text won't be reported
		if(End - Start < 3)
		{
			char* p = Start;
			for(; p != End; ++p)
				if(!isWhiteSpace(*p))
					break;

			if(p == End)
				return false;
		}

		// set current text to the parsed text, and replace xml special characters
		String s(Start,(int)(End - Start));
		NodeName = replaceSpecialCharacters(s);

		// current XML node type is text
		CurrentNodeType = XML_NODE_TEXT;

		return true;
	}



	// ignores an xml definition like <?xml something />
	void ignoreDefinition()
	{
		CurrentNodeType = XML_NODE_UNKNOWN;

		// move until End marked with '>' reached
		while(*P != L'>')
			++P;

		++P;
	}


	// parses a comment
	void parseComment()
	{
		CurrentNodeType = XML_NODE_COMMENT;
		P += 1;

		char *pCommentBegin = P;

		int count = 1;

		// move until End of comment reached
		while(count)
		{
			if(*P == L'>')
				--count;
			else
			if(*P == L'<')
				++count;

			++P;
		}

		P -= 3;
		NodeName = String(pCommentBegin+2,(int)(P - pCommentBegin-2));
		P += 3;
	}


	// parses an opening xml Element and reads attributes
	void parseOpeningXMLElement()
	{
		CurrentNodeType = XML_NODE_ELEMENT;
		isEmptyElement = false;
		Attributes.clear();

		// find name
		const char* startName = P;

		// find End of Element
		while(*P != L'>' && !isWhiteSpace(*P))
			++P;

		const char* endName = P;

		// find Attributes
		while(*P != L'>')
		{
			if(isWhiteSpace(*P))
				++P;
			else
			{
				if(*P != L'/')
				{
					// we've got an attribute

					// Read the attribute names
					const char* AttributeNameBegin = P;

					while(!isWhiteSpace(*P) && *P != L'=')
						++P;

					const char* AttributeNameEnd = P;
					++P;

					// Read the attribute value
					// check for quotes and single quotes, thx to murphy
					while((*P != L'\"') &&(*P != L'\'') && *P) 
						++P;

					if(!*P) // malformatted xml file
						return;

					const char attributeQuoteChar = *P;

					++P;
					const char* attributeValueBegin = P;
					
					while(*P != attributeQuoteChar && *P)
						++P;

					if(!*P) // malformatted xml file
						return;

					const char* attributeValueEnd = P;
					++P;

					SAttribute attr;
					attr.Name = String(AttributeNameBegin, 
						(int)(AttributeNameEnd - AttributeNameBegin));

					String s(attributeValueBegin, 
						(int)(attributeValueEnd - attributeValueBegin));

					attr.Value = replaceSpecialCharacters(s);
					Attributes.push_back(attr);
				}
				else
				{
					// tag is closed directly
					++P;
					isEmptyElement = true;
					break;
				}
			}
		}

		// check if this tag is closing directly
		if(endName > startName && *(endName-1) == L'/')
		{
			// directly closing tag
			isEmptyElement = true;
			endName--;
		}
		
		NodeName = String(startName,(int)(endName - startName));

		++P;
	}


	// parses an closing xml tag
	void parseClosingXMLElement()
	{
		CurrentNodeType = XML_NODE_ELEMENT_END;
		isEmptyElement = false;
		Attributes.clear();

		++P;
		const char* pBeginClose = P;

		while(*P != L'>')
			++P;

		NodeName = String(pBeginClose,(int)(P - pBeginClose));
		++P;
	}

	// parses a possible CDATA section, returns false if Begin was not a CDATA section
	bool parseCDATA()
	{
		if(*(P+1) != L'[')
			return false;

		CurrentNodeType = XML_NODE_CDATA;

		// skip '<![CDATA['
		int count=0;
		while(*P && count<8)
		{
			++P;
			++count;
		}

		if(!*P)
			return true;

		char *cDataBegin = P;
		char *cDataEnd = nullptr;

		// find End of CDATA
		while(*P && !cDataEnd)
		{
			if(*P == L'>' && 
			  (*(P-1) == L']') &&
			  (*(P-2) == L']'))
			{
				cDataEnd = P - 2;
			}

			++P;
		}

		if(cDataEnd)
			NodeName = String(cDataBegin,(int)(cDataEnd - cDataBegin));
		else
			NodeName = "";

		return true;
	}


	// structure for storing attribute-name pairs
	struct SAttribute
	{
		String Name;
		String Value;
	};

	// finds a current attribute by name, returns 0 if not found
	const SAttribute* getAttributeByName(const char* name) const
	{
		if(!name)
			return nullptr;

		String n = name;

		for(int i=0; i<(int)Attributes.size(); ++i)
			if(Attributes[i].Name == n)
				return &Attributes[i];

		return nullptr;
	}

	// replaces xml special characters in a string and creates a new one
	String replaceSpecialCharacters(String& origstr)
	{
		size_t pos = origstr.find_first_of(L'&');
		size_t oldPos = 0;

		if(pos == String::npos)
			return origstr;

		String newstr;

		while(pos != -1 && pos < origstr.size() - 2)
		{
			// check if it is one of the special characters

			int specialChar = -1;
			for(int i = 0; i < (int)SpecialCharacters.size(); ++i)
			{
				const char* p = &origstr.c_str()[pos]+1;

				if(EqualsN(&SpecialCharacters[i][1], p, (s32)SpecialCharacters[i].size() - 1))
				{
					specialChar = i;
					break;
				}
			}

			if(specialChar != -1)
			{
				newstr.append(origstr.substr(oldPos, pos - oldPos));
				newstr.append(SpecialCharacters[specialChar].c_str());
				pos += SpecialCharacters[specialChar].size();
			}
			else
			{
				newstr.append(origstr.substr(oldPos, pos - oldPos + 1));
				pos += 1;
			}

			// find next &
			oldPos = pos;
			pos = origstr.find(L'&', pos);		
		}

		if(oldPos < origstr.size() - 1)
			newstr.append(origstr.substr(oldPos, origstr.size()-oldPos));

		return newstr;
	}



	// reads the xml file and converts it into the wanted character format.
	bool readFile(IFileReadCallBack* callback)
	{
		int Size = callback->GetSize();		
		Size += 4; // We need two terminating 0's at the End.
		           // For ASCII we need 1 0's, for UTF-16 2, for UTF-32 4.

		char* data8 = new char[Size];

		if(!callback->Read(data8, Size-4))
		{
			delete [] data8;
			return false;
		}

		// add zeros at End

		data8[Size-1] = 0;
		data8[Size-2] = 0;
		data8[Size-3] = 0;
		data8[Size-4] = 0;

		s16* data16 = reinterpret_cast<s16*>(data8);
		u32* data32 = reinterpret_cast<u32*>(data8);	

		// now we need to convert the data to the desired target format
		// based on the byte order mark.
		const unsigned char UTF8[] = {0xEF, 0xBB, 0xBF}; // 0xEFBBBF;
		const int UTF16_BE = 0xFFFE;
		const int UTF16_LE = 0xFEFF;
		const int UTF32_BE = 0xFFFE0000;
		const int UTF32_LE = 0x0000FEFF;

		// check source for all utf versions and convert to target data format
		if(Size >= 4 && data32[0] ==(u32)UTF32_BE)
		{
			// UTF-32, big endian
			SourceFormat = XML_TEXT_UTF32_BE;
			convertTextData(data32+1, data8,(Size/4)); // data32+1 because we need to skip the header
		}
		else if(Size >= 4 && data32[0] ==(u32)UTF32_LE)
		{
			// UTF-32, little endian
			SourceFormat = XML_TEXT_UTF32_LE;
			convertTextData(data32+1, data8,(Size/4)); // data32+1 because we need to skip the header
		}
		else if(Size >= 2 && data16[0] == UTF16_BE)
		{
			// UTF-16, big endian
			SourceFormat = XML_TEXT_UTF16_BE;
			convertTextData(data16+1, data8,(Size/2)); // data16+1 because we need to skip the header
		}
		else if(Size >= 2 && data16[0] == UTF16_LE)
		{
			// UTF-16, little endian
			SourceFormat = XML_TEXT_UTF16_LE;
			convertTextData(data16+1, data8,(Size/2)); // data16+1 because we need to skip the header
		}
		else if(Size >= 3 && data8[0] == UTF8[0] && data8[1] == UTF8[1] && data8[2] == UTF8[2])
		{
			// UTF-8
			SourceFormat = XML_TEXT_UTF8;
			convertTextData(data8+3, data8, Size); // data8+3 because we need to skip the header
		}
		else
		{
			// ASCII
			SourceFormat = XML_TEXT_ASCII;
			convertTextData(data8, data8, Size);
		}

		return true;
	}

	// converts the text file into the desired format.
	template<class src_char_type> void convertTextData(src_char_type* source, char* pointerToStore, int sizeWithoutHeader)
	{
		// convert little to big endian if necessary
		if(sizeof(src_char_type) > 1 && 
			isLittleEndian(TargetFormat) != isLittleEndian(SourceFormat))
			convertToLittleEndian(source);

		// check if conversion is necessary:
		if(sizeof(src_char_type) == sizeof(char))
		{
			// no need to convert
			TextBegin =(char*)source;
			TextData =(char*)pointerToStore;
			TextSize = sizeWithoutHeader;
		}
		else
		{
			// convert source into target data format. 
			// TODO: implement a real conversion. This one just 
			// copies bytes. This is a problem when there are 
			// unicode symbols using more than one character.

			TextData = new char[sizeWithoutHeader];

			for(int i=0; i<sizeWithoutHeader; ++i)
				TextData[i] =(char)source[i];

			TextBegin = TextData;
			TextSize = sizeWithoutHeader;

			// delete original data because no longer needed
			delete [] pointerToStore;
		}
	}

	// converts whole text buffer to little endian
	template<class src_char_type> void convertToLittleEndian(src_char_type* t)
	{
		if(sizeof(src_char_type) == 4) 
		{
			// 32 bit

			while(*t)
			{
				*t =((*t & 0xff000000) >> 24) |
				    ((*t & 0x00ff0000) >> 8)  |
				    ((*t & 0x0000ff00) << 8)  |
				    ((*t & 0x000000ff) << 24);
				++t;
			}
		}
		else
		{
			// 16 bit 

			while(*t)
			{
				*t =(*t >> 8) |(*t << 8);
				++t;
			}
		}
	}

	// returns if a format is little endian
	inline bool isLittleEndian(XML_TEXT_FORMAT_TYPE f)
	{
		return f == XML_TEXT_ASCII ||
		       f == XML_TEXT_UTF8 ||
		       f == XML_TEXT_UTF16_LE ||
		       f == XML_TEXT_UTF32_LE;
	}


	// returns true if a character is whitespace
	inline bool isWhiteSpace(char c)
	{
		return(c==' ' || c=='\t' || c=='\n' || c=='\r');
	}


	// generates a list with xml special characters
	void createSpecialCharacterList()
	{
		// list of strings containing special symbols, 
		// the first character is the special character,
		// the following is the symbol string without trailing &.

		SpecialCharacters.push_back("&amp;");
		SpecialCharacters.push_back("<lt;");
		SpecialCharacters.push_back(">gt;");
		SpecialCharacters.push_back("\"quot;");
		SpecialCharacters.push_back("'apos;");
		
	}

	// compares the first n characters of the strings
	bool EqualsN(const char* str1, const char* str2, int len)
	{
		int i;
		for(i=0; str1[i] && str2[i] && i < len; ++i)
			if(str1[i] != str2[i])
				return false;

		// if one(or both) of the strings was smaller then they
		// are only equal if they have the same lenght
		return(i == len) ||(str1[i] == 0 && str2[i] == 0);
	}

	// stores the target text format
	void storeTargetFormat()
	{
		// get target format. We could have done this using template specialization,
		// but VisualStudio 6 don't like it and we want to support it.
		switch(sizeof(char))
		{
		case 1: 
			TargetFormat = XML_TEXT_UTF8;
			break;
		case 2: 
			TargetFormat = XML_TEXT_UTF16_LE;
			break;
		case 4: 
			TargetFormat = XML_TEXT_UTF32_LE;
			break;
		default:
			TargetFormat = XML_TEXT_ASCII; // should never happen.
		}
	}


	// instance variables:

	char* TextData;         // data block of the text file
	char* P;                // current point in text to parse
	char* TextBegin;        // Start of text to parse
	u32 TextSize;				// Size of text to parse in characters, not bytes

	XML_NODE_TYPE CurrentNodeType;   // type of the currently parsed node
	XML_TEXT_FORMAT_TYPE SourceFormat;   // source format of the xml file
	XML_TEXT_FORMAT_TYPE TargetFormat;   // output format of this parser

	String NodeName;    // name of the node currently in
	String EmptyString; // empty string to be returned by getSafe() methods

	bool isEmptyElement;       // is the currently parsed node empty?

	std::vector< String > SpecialCharacters; // see createSpecialCharacterList()

	std::vector<SAttribute> Attributes; // attributes of current Element
	
}; // End CXMLReaderImpl

} // End namespace

#endif
