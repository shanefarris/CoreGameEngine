// Update 5-8-07

#include "CXMLWriter.h"
#include "IWriteFile.h"
#include <wchar.h>
#include <cstring>

using namespace IO;

const CXMLWriter::XMLSpecialCharacters XMLWSChar[] = 
{
	{ '&', "&amp;" },
	{ '<', "&lt;" },
	{ '>', "&gt;" },
	{ '"', "&quot;" },
	{ '\0', 0}
};

CXMLWriter::CXMLWriter(IWriteFile* File) : m_File(File), Tabs(0)
{
}

CXMLWriter::~CXMLWriter()
{
	CORE_DELETE(m_File);
}

void CXMLWriter::WriteXMLHeader()
{
	if(!m_File)
		return;

	//s16 h = 0xFEFF;
	//m_File->Write(&h, 2);
	m_File->Write("<?xml version=\"1.0\"?>", (u32)strlen("<?xml version=\"1.0\"?>"));

	WriteLineBreak();
}

void CXMLWriter::WriteElement(const char* Name, bool Empty, const char* Attribute1Name, const char* Attribute1Value,
	const char* Attribute2Name, const char* Attribute2Value, const char* Attribute3Name, const char* Attribute3Value,
	const char* Attribute4Name, const char* Attribute4Value, const char* Attribute5Name, const char* Attribute5Value)
{
	if(!m_File || !Name)
		return;

	if(Tabs > 0)
	{
		for(int i=0; i<Tabs; ++i)
			m_File->Write("\t", 1);
	}
	
	// Write Name
	m_File->Write("<", 1);
	m_File->Write((const void*)Name, (u32)strlen(Name));

	// Write Attributeibutes
	WriteAttribute(Attribute1Name, Attribute1Value);
	WriteAttribute(Attribute2Name, Attribute2Value);
	WriteAttribute(Attribute3Name, Attribute3Value);
	WriteAttribute(Attribute4Name, Attribute4Value);
	WriteAttribute(Attribute5Name, Attribute5Value);

	// Write closing tag
	if(Empty)
		m_File->Write(" />", 3);
	else
	{
		m_File->Write(">", 1);
		++Tabs;
	}
}

void CXMLWriter::WriteElement(const char* Name, bool Empty, std::vector<String> &Names, std::vector<String> &Values)
{
	if(!m_File || !Name)
		return;

	if(Tabs > 0)
	{
		for(int i=0; i<Tabs; ++i)
			m_File->Write("\t", 1);
	}
	
	// write Name

	m_File->Write("<", 1);
	m_File->Write(Name, (u32)strlen(Name));

	// write Attributeibutes
	u32 i=0;
	for(; i < Names.size() && i < Values.size(); ++i)
	{
		WriteAttribute(Names[i].c_str(), Values[i].c_str());
	}

	// write closing tag
	if(Empty)
		m_File->Write(" />", 3);
	else
	{
		m_File->Write(">", 1);
		++Tabs;
	}
}

void CXMLWriter::WriteAttribute(const char* Name, const char* Value)
{
	if(!Name || !Value)
		return;

	m_File->Write(" ", 1);
	m_File->Write(Name, (u32)strlen(Name));
	m_File->Write("=\"", 2);
	WriteText(Value);
	m_File->Write("\"", 1);
}

void CXMLWriter::WriteComment(const char* Comment)
{
	if(!m_File || !Comment)
		return;

	m_File->Write("<!--", 4);
	WriteText(Comment);
	m_File->Write("-->", 3);
}

void CXMLWriter::WriteClosingTag(const char* Name)
{
	if(!m_File || !Name)
		return;

	--Tabs;
	if(Tabs > 0)
	{
		for(int i=0; i<Tabs; ++i)
			m_File->Write("\t", 1);
	}

	m_File->Write("</", 2);
	m_File->Write(Name, (u32)strlen(Name));
	m_File->Write(">", 1);
}

void CXMLWriter::WriteText(const char* Text)
{
	if(!m_File || !Text)
		return;

	String s(Text);

	// check if it is matching
	bool found = false;
	for(s32 i = 0; XMLWSChar[i].Character != '\0'; ++i)
	{
		auto pos = s.find(XMLWSChar[i].Character);
		if(pos != String::npos)
		{
			s.append(XMLWSChar[i].Symbol);
			s.replace(XMLWSChar[i].Character, 1, XMLWSChar[i].Symbol);
		}
	}

	m_File->Write(s.c_str(), (u32)s.size());	// write new string
}

void CXMLWriter::WriteLineBreak()
{
	if(!m_File)
		return;

	m_File->Write("\n", 1);
}
