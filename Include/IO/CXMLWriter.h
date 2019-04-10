// Interface providing methods for making it easier to write XML files.
// Updated 5-8-07

#ifndef __CXMLWRITER_H__
#define __CXMLWRITER_H__

#include "IXMLWriter.h"
#include "Defines.h"

namespace IO
{
	class IWriteFile;

	class CORE_EXPORT CXMLWriter : public IXMLWriter
	{
	private:
		IWriteFile* m_File;
		s32		Tabs;

		void WriteAttribute(const char* Attribute, const char* Name);

	public:
		CXMLWriter(IWriteFile* File);
		virtual ~CXMLWriter();

		virtual void WriteXMLHeader();
		virtual void WriteElement(const char* Name, bool Empty = false,
			const char* Attribute1Name = 0, const char* Attribute1Value = 0,
			const char* Attribute2Name = 0, const char* Attribute2Value = 0,
			const char* Attribute3Name = 0, const char* Attribute3Value = 0,
			const char* Attribute4Name = 0, const char* Attribute4Value = 0,
			const char* Attribute5Name = 0, const char* Attribute5Value = 0);

		virtual void WriteElement(const char* Name, bool Empty, std::vector<String> &Names, std::vector<String> &Values);
		virtual void WriteComment(const char* Comment);
		virtual void WriteClosingTag(const char* Name);
		virtual void WriteText(const char* Text);
		virtual void WriteLineBreak();

		struct XMLSpecialCharacters
		{
			char Character;
			char* Symbol;
		};
	};

} // End namespace IO

#endif

