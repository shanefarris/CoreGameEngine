#include "CConfig.h"
#include "CFileSystem.h"

#include <fstream>

using namespace IO;

CConfig::CConfig(CFileSystem* FileSystem) 
{
	m_FileSystem = FileSystem;
}

bool CConfig::ReadConfig(String &FileName) 
{
	if(!m_FileSystem->ExistFile(FileName.c_str()))
		return false;

	std::ifstream file(FileName.c_str());

	String line;
	String name;
	String value;

	size_t posEqual;
	while (std::getline(file,line)) 
	{
		if (! line.length()) 
			continue;

		if (line[0] == '#') 
			continue;
		if (line[0] == ';') 
			continue;

		posEqual = line.find('=');
		name  = trim(line.substr(0, posEqual));
		value = trim(line.substr(posEqual + 1));
		content_[name] = value;
	}
	file.close();
	return true;
}

String CConfig::trim(String Source, char const* delims) 
{
	String result(Source);
	String::size_type index = result.find_last_not_of(delims);
	if(index != String::npos)
		result.erase(++index);

	index = result.find_first_not_of(delims);
	if(index != String::npos)
		result.erase(0, index);
	else
		result.erase();
	return result;
}

String CConfig::GetValue(String Entry) const 
{
	Map<String, String>::const_iterator ci = content_.find(Entry);
	if (ci == content_.end()) 
		return "";

	return ci->second;
}
