#ifndef __CCONFIG_H__
#define __CCONFIG_H__

#include "Defines.h"

namespace IO
{
	class CFileSystem;

	class CORE_EXPORT CConfig 
	{
	public:
		CConfig(CFileSystem* FileSystem);
		bool ReadConfig(String &FileName);
		String GetValue(String Entry) const;

	private:
		CFileSystem* m_FileSystem;
		Map<String,String> content_;

		String trim(String Source, char const* delims = " \t\r\n");

	};
}

#endif // __CCONFIG_H__