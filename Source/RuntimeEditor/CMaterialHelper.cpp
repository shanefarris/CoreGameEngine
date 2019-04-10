#include "CMaterialHelper.h"
#include "CUtility.h"

#include <iostream>
#include <windows.h>
#include <sqltypes.h>
#include <sql.h>
#include <sqlext.h>
#include <string>

#include "IO/CFileSystem.h"
#include "IO/CWriteFile.h"

#include "OgreRoot.h"
#include "OgreLogManager.h"
#include "OgreMaterialManager.h"
#include "OgreResourceManager.h"
#include "OgreHighLevelGpuProgramManager.h"

using namespace Core::Editor;

void CMaterialHelper::UnloadResource(Ogre::ResourceManager* resMgr, const String& resourceName)
{
	Ogre::ResourcePtr rPtr = resMgr->getByName(resourceName);
	if (rPtr.isNull())
	{
		StringUtil::StrStreamType msg;
		msg << "Resource no longer exists: " << resourceName;
		Ogre::LogManager::getSingleton().logMessage(msg.str());
		return;
	}

	rPtr->unload();
	if (rPtr->isLoaded())
	{
		StringUtil::StrStreamType msg;
		msg << "Resource was not unloaded: " << resourceName;
		Ogre::LogManager::getSingleton().logMessage(msg.str());
	}
	else
	{
		StringUtil::StrStreamType msg;
		msg << "Resource was unloaded: " << resourceName;
		Ogre::LogManager::getSingleton().logMessage(msg.str());
	}

	resMgr->remove(resourceName);
	rPtr = resMgr->getByName(resourceName);
	if (rPtr.isNull())
	{
		StringUtil::StrStreamType msg;
		msg << "Resource was removed: " << resourceName;
		Ogre::LogManager::getSingleton().logMessage(msg.str());
	}
	else
	{
		StringUtil::StrStreamType msg;
		msg << "Resource was not removed: " << resourceName;
		Ogre::LogManager::getSingleton().logMessage(msg.str());
	}

	if (resMgr->resourceExists(resourceName))
	{
		StringUtil::StrStreamType msg;
		msg << "Resource still exists: " << resourceName;
		Ogre::LogManager::getSingleton().logMessage(msg.str());
	}
	else
	{
		StringUtil::StrStreamType msg;
		msg << "Resource no longer exists: " << resourceName;
		Ogre::LogManager::getSingleton().logMessage(msg.str());
	}
}

void CMaterialHelper::LoadResource(Ogre::ResourceManager* resMgr, const String& resourceName, const String& resourceGroup)
{
	Ogre::ResourcePtr rPtr = resMgr->load(resourceName, resourceGroup);
	if (rPtr.isNull())
	{
		StringUtil::StrStreamType msg;
		msg << "Resource no longer exists: " << resourceName;
		Ogre::LogManager::getSingleton().logMessage(msg.str());
		return;
	}

	rPtr->reload();
	if (rPtr->isLoaded())
	{
		StringUtil::StrStreamType msg;
		msg << "Resource was reloaded: " << resourceName;
		Ogre::LogManager::getSingleton().logMessage(msg.str());
	}
	else
	{
		StringUtil::StrStreamType msg;
		msg << "Resource was not reloaded: " << resourceName;
		Ogre::LogManager::getSingleton().logMessage(msg.str());
	}

	if (resMgr->resourceExists(resourceName))
	{
		StringUtil::StrStreamType msg;
		msg << "Resource still exists: " << resourceName;
		Ogre::LogManager::getSingleton().logMessage(msg.str());
	}
	else
	{
		StringUtil::StrStreamType msg;
		msg << "Resource no longer exists: " << resourceName;
		Ogre::LogManager::getSingleton().logMessage(msg.str());
	}
}

void CMaterialHelper::UnloadMaterials(const String& filename)
{
	if (filename.empty())
	{
		Ogre::LogManager::getSingleton().logMessage("Filename is empty.");
		return;
	}

	IO::CFileSystem fileSystem;
	if(!fileSystem.ExistFile(filename.c_str()))
		return;

	Ogre::DataStreamPtr stream = Ogre::ResourceGroupManager::getSingleton().openResource(filename);
	if(!stream.isNull())
	{
		try
		{
			while(!stream->eof())
			{
				std::string line = stream->getLine();
				StringUtil::trim(line);

				///
				/// UNLOAD MATERIALS
				///
				if (StringUtil::startsWith(line, "material"))
				{
					auto vec = StringUtil::split(line," \t:");
					bool skipFirst = true;
					for (auto it = vec.begin(); it < vec.end(); ++it)
					{
						if (skipFirst)
						{
							skipFirst = false;
							continue;
						}
						std::string match = (*it);
						StringUtil::trim(match);
						if (!match.empty())
						{
							UnloadResource(Ogre::MaterialManager::getSingletonPtr(), match);
							break;
						}
					}
				}
			}
		}
		catch (Ogre::Exception &e)
		{
			StringUtil::StrStreamType msg;
			msg << "Exception: FILE: " << __FILE__ << " LINE: " << __LINE__ << " DESC: " << e.getFullDescription() << std::endl;
			Ogre::LogManager::getSingleton().logMessage(msg.str());
		}
	}
	stream->close();
}

void CMaterialHelper::UnloadVertexPrograms(const String& filename)
{
	if (filename.empty())
	{
		Ogre::LogManager::getSingleton().logMessage("Material filename is empty.");
		return;
	}

	Ogre::DataStreamPtr stream = Ogre::ResourceGroupManager::getSingleton().openResource(filename);
	if(!stream.isNull())
	{
		try
		{
			while(!stream->eof())
			{
				std::string line = stream->getLine();
				StringUtil::trim(line);

				///
				/// UNLOAD VERTEX PROGRAMS
				///
				if (StringUtil::startsWith(line, "vertex_program") && !StringUtil::startsWith(line, "vertex_program_ref"))
				{
					Ogre::vector<Ogre::String>::type vec = StringUtil::split(line," \t");
					bool skipFirst = true;
					for (Ogre::vector<Ogre::String>::type::iterator it = vec.begin(); it < vec.end(); ++it)
					{
						if (skipFirst)
						{
							skipFirst = false;
							continue;
						}
						std::string match = (*it);
						StringUtil::trim(match);
						if (!match.empty())
						{
							UnloadResource(Ogre::HighLevelGpuProgramManager::getSingletonPtr(), match);
							break;
						}
					}
				}
			}
		}
		catch (Ogre::Exception &e)
		{
			StringUtil::StrStreamType msg;
			msg << "Exception: FILE: " << __FILE__ << " LINE: " << __LINE__ << " DESC: " << e.getFullDescription() << std::endl;
			Ogre::LogManager::getSingleton().logMessage(msg.str());
		}
	}
	stream->close();
}

void CMaterialHelper::UnloadFragmentPrograms(const String& filename)
{
	if (filename.empty())
	{
		Ogre::LogManager::getSingleton().logMessage("Material filename is empty.");
		return;
	}

	Ogre::DataStreamPtr stream = Ogre::ResourceGroupManager::getSingleton().openResource(filename);
	if(!stream.isNull())
	{
		try
		{
			while(!stream->eof())
			{
				std::string line = stream->getLine();
				StringUtil::trim(line);

				///
				/// UNLOAD FRAGMENT PROGRAMS
				///
				if (StringUtil::startsWith(line, "fragment_program") && !StringUtil::startsWith(line, "fragment_program_ref"))
				{
					Ogre::vector<Ogre::String>::type vec = StringUtil::split(line," \t");
					bool skipFirst = true;
					for (Ogre::vector<Ogre::String>::type::iterator it = vec.begin(); it < vec.end(); ++it)
					{
						if (skipFirst)
						{
							skipFirst = false;
							continue;
						}
						std::string match = (*it);
						StringUtil::trim(match);
						if (!match.empty())
						{
							UnloadResource(Ogre::HighLevelGpuProgramManager::getSingletonPtr(), match);
							break;
						}
					}
				}
			}
		}
		catch (Ogre::Exception &e)
		{
			StringUtil::StrStreamType msg;
			msg << "Exception: FILE: " << __FILE__ << " LINE: " << __LINE__ << " DESC: " << e.getFullDescription() << std::endl;
			Ogre::LogManager::getSingleton().logMessage(msg.str());
		}
	}
	stream->close();
}

void CMaterialHelper::ReloadMaterial(const String& materialName, const String& groupName, const String& filename, bool parseMaterialScript)
{
	if (materialName.empty())
	{
		Ogre::LogManager::getSingleton().logMessage("Material name is empty.");
		return;
	}

	if (groupName.empty())
	{
		Ogre::LogManager::getSingleton().logMessage("Group name is empty.");
		return;
	}

	if (filename.empty())
	{
		Ogre::LogManager::getSingleton().logMessage("Filename is empty.");
		return;
	}

	UnloadMaterials(filename);
	UnloadVertexPrograms(filename);
	UnloadFragmentPrograms(filename);

	if (parseMaterialScript)
	{
		Ogre::DataStreamPtr stream = Ogre::ResourceGroupManager::getSingleton().openResource(filename);
		if(!stream.isNull())
		{
			try
			{
				Ogre::MaterialManager::getSingleton().parseScript(stream, groupName);
				Ogre::MaterialPtr materialPtr = Ogre::MaterialManager::getSingleton().getByName(materialName);
				if (!materialPtr.isNull())
				{
					materialPtr->compile();
					materialPtr->load();
				}
			}
			catch (Ogre::Exception &e)
			{
				StringUtil::StrStreamType msg;
				msg << "Exception: FILE: " << __FILE__ << " LINE: " << __LINE__ << " DESC: " << e.getFullDescription() << std::endl;
				Ogre::LogManager::getSingleton().logMessage(msg.str());
			}
		}
		stream->close();

		///
		/// RELOAD MATERIAL SCRIPT CONTENTS
		///
		stream = Ogre::ResourceGroupManager::getSingleton().openResource(filename);
		if(!stream.isNull())
		{
			try
			{
				///
				/// RELOAD ALL MATERIAL CONTENTS IN FILE
				///
				while(!stream->eof())
				{
					std::string line = stream->getLine();
					StringUtil::trim(line);
					///
					/// RELOAD MATERIALS
					///
					if (StringUtil::startsWith(line, "material"))
					{
						Ogre::vector<Ogre::String>::type vec = StringUtil::split(line," \t:");
						bool skipFirst = true;
						for (Ogre::vector<Ogre::String>::type::iterator it = vec.begin(); it < vec.end(); ++it)
						{
							if (skipFirst)
							{
								skipFirst = false;
								continue;
							}
							std::string match = (*it);
							StringUtil::trim(match);
							if (!match.empty())
							{
								LoadResource(Ogre::MaterialManager::getSingletonPtr(), match, groupName);
								break;
							}
						}
					}
					///
					/// RELOAD VERTEX PROGRAMS
					///
					if (StringUtil::startsWith(line, "vertex_program") && !StringUtil::startsWith(line, "vertex_program_ref"))
					{
						Ogre::vector<Ogre::String>::type vec = StringUtil::split(line," \t");
						bool skipFirst = true;
						for (Ogre::vector<Ogre::String>::type::iterator it = vec.begin(); it < vec.end(); ++it)
						{
							if (skipFirst)
							{
								skipFirst = false;
								continue;
							}
							std::string match = (*it);
							StringUtil::trim(match);
							if (!match.empty())
							{
								LoadResource(Ogre::HighLevelGpuProgramManager::getSingletonPtr(), match, groupName);
								break;
							}
						}
					}
					///
					/// RELOAD FRAGMENT PROGRAMS
					///
					if (StringUtil::startsWith(line, "fragment_program") && !StringUtil::startsWith(line, "fragment_program_ref"))
					{
						Ogre::vector<Ogre::String>::type vec = StringUtil::split(line," \t");
						bool skipFirst = true;
						for (Ogre::vector<Ogre::String>::type::iterator it = vec.begin(); it < vec.end(); ++it)
						{
							if (skipFirst)
							{
								skipFirst = false;
								continue;
							}
							std::string match = (*it);
							StringUtil::trim(match);
							if (!match.empty())
							{
								LoadResource(Ogre::HighLevelGpuProgramManager::getSingletonPtr(), match, groupName);
								break;
							}
						}
					}
				}
			}
			catch (Ogre::Exception &e)
			{
				StringUtil::StrStreamType msg;
				msg << "Exception: FILE: " << __FILE__ << " LINE: " << __LINE__ << " DESC: " << e.getFullDescription() << std::endl;
				Ogre::LogManager::getSingleton().logMessage(msg.str());
			}
		}
		stream->close();

		try
		{
			// Do a render test if it fails, leave materials unloaded
			Ogre::Root::getSingleton().renderOneFrame();
			return;
		}
		catch (Ogre::Exception &e)
		{
			UnloadVertexPrograms(filename);

			StringUtil::StrStreamType msg;
			msg << "Render test failed. Unloading vertex programs." << std::endl;
			msg << "Exception: FILE: " << __FILE__ << " LINE: " << __LINE__ << " DESC: " << e.getFullDescription() << std::endl;
			Ogre::LogManager::getSingleton().logMessage(msg.str());
		}

		try
		{
			// Do a render test if it fails, leave materials unloaded
			Ogre::Root::getSingleton().renderOneFrame();
		}
		catch (Ogre::Exception &e)
		{
			// Don't load the script this time
			ReloadMaterial(materialName, groupName, filename, false);

			StringUtil::StrStreamType msg;
			msg << "Render test failed. Unloading materials." << std::endl;
			msg << "Exception: FILE: " << __FILE__ << " LINE: " << __LINE__ << " DESC: " << e.getFullDescription() << std::endl;
			Ogre::LogManager::getSingleton().logMessage(msg.str());
		}
	}
}

bool CMaterialHelper::DownloadMaterialFile(const String& materialName)
{
	String fileName;
	String material;
	SQLHANDLE sqlenvhandle;    
	SQLHANDLE sqlconnectionhandle;
	SQLHANDLE sqlstatementhandle;
	SQLRETURN retcode;

	do
	{
		unsigned char sqlstate[1024];
		unsigned char message[1024];

		if(SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &sqlenvhandle))
			break;

		if(SQL_SUCCESS != SQLSetEnvAttr(sqlenvhandle,SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0)) 
			break;

		if(SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_DBC, sqlenvhandle, &sqlconnectionhandle))
			break;

		SQLCHAR retconstring[1024];
		auto connString = (unsigned char*)"DRIVER={SQL Server};SERVER=localhost,1433;DATABASE=AssetManager;UID=sa;PWD=t00lb0x;";
		auto ret = SQLDriverConnect(sqlconnectionhandle, nullptr, connString, SQL_NTS, retconstring, 1024, nullptr, SQL_DRIVER_NOPROMPT);

		switch(ret)
		{
		case SQL_SUCCESS_WITH_INFO:
			if(SQL_SUCCESS == SQLGetDiagRec(SQL_HANDLE_DBC, sqlconnectionhandle, 1, sqlstate, nullptr, message, 1024, nullptr))
				std::cout << "Message: " << message<< "\nSQLSTATE: " << sqlstate << std::endl;
			break;
		case SQL_INVALID_HANDLE:
		case SQL_ERROR:
			if(SQL_SUCCESS == SQLGetDiagRec(SQL_HANDLE_DBC, sqlconnectionhandle, 1, sqlstate, nullptr, message, 1024, nullptr))
				std::cout << "Message: " << message<< "\nSQLSTATE: " << sqlstate << std::endl;
			retcode = -1;
			break;
		default:
			break;
		}

		if(retcode == -1)
			break;

		if(SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_STMT, sqlconnectionhandle, &sqlstatementhandle))
			break;

		String sql = "select data, filename from asset where name = '%NAME%' and assettypeid = 1";
		CUtility::StringReplace(sql, "%NAME%", materialName);

		if(SQL_SUCCESS != SQLExecDirect(sqlstatementhandle, (SQLCHAR*)sql.c_str(), SQL_NTS))
		{
			if(SQL_SUCCESS == SQLGetDiagRec(SQL_HANDLE_DBC, sqlconnectionhandle, 1, sqlstate, nullptr, message, 1024, nullptr))
				std::cout << "Message: " << message<< "\nSQLSTATE: " << sqlstate << std::endl;
		}
		else
		{
			while (SQLFetch(sqlstatementhandle) != SQL_NO_DATA) 
			{
				const int SIZE = 512;
				char name[SIZE] = {0};
				SQLLEN BinaryLenOrInd;
				while(SQLGetData(sqlstatementhandle, 1, SQL_BINARY, name, SIZE, &BinaryLenOrInd) != SQL_NO_DATA)
				{
					String temp(name);
					material += temp.substr(0, SIZE < BinaryLenOrInd ? SIZE : BinaryLenOrInd);
				}

				char file[255];
				SQLGetData(sqlstatementhandle, 2, SQL_CHAR, file, 255, nullptr);
				fileName = file;
			}
		}
	}
	while(FALSE);

	SQLFreeHandle(SQL_HANDLE_STMT, sqlstatementhandle );
	SQLDisconnect(sqlconnectionhandle);
	SQLFreeHandle(SQL_HANDLE_DBC, sqlconnectionhandle);
	SQLFreeHandle(SQL_HANDLE_ENV, sqlenvhandle);

	fileName = "../../Media/" + fileName;
	IO::CFileSystem FileSystem;
	auto write = FileSystem.CreateAndWriteFile(fileName.c_str(), false, false);
	write->Write(material.c_str(), (u32)material.length());
	CORE_DELETE(write);

	return true;
}