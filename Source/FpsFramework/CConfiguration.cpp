#include "CConfiguration.h"
#include "IO/CFileSystem.h"
#include "CGameManager.h"
#include "CoreStructures.h"
#include "IO/CoreLogging.h"

#include "OgreStringConverter.h"
#include "OgreException.h"

using namespace Core;
using namespace IO;

CConfiguration* CConfiguration::Configuration = nullptr;

CConfiguration* CConfiguration::Instance()
{
	if(Configuration == nullptr)
		Configuration = new CConfiguration();
	return Configuration;
}

CConfiguration::CConfiguration()
{
}

void CConfiguration::SaveConfig()
{
}

void CConfiguration::LoadConfig(bool restore)
{
	assert(_CrtCheckMemory());

	CFileSystem FileSystem;
	IXMLReader* xml;

	if ( restore)
		xml = FileSystem.CreateXMLReader("config_orig.xml");
	else
		xml = FileSystem.CreateXMLReader("config.xml");

	if(!xml)
	{
		CORE_ERR("Unable to find config.xml file.");
		return;
	}

	while(xml->Read())
    {
        switch(xml->GetNodeType())
        {
	        case IO::XML_NODE_ELEMENT:
            {
				if (String("audio") == xml->GetNodeName())
				{
					SoundVolume = StringConverter::parseReal(xml->GetAttributeValueSafe("soundvolume"));
					MusicVolume = StringConverter::parseReal(xml->GetAttributeValueSafe("musicvolume"));
					if ( String("on") == xml->GetAttributeValueSafe("switch"))
						EnableAudio = true;
					else
						EnableAudio = false;
				}
				else if (String("video") == xml->GetNodeName())
				{
					PopulateVideo(xml);
				}
				else if (String("network") == xml->GetNodeName())
				{
					ServerName, xml->GetAttributeValueSafe("servername");
					ServerIP, xml->GetAttributeValueSafe("serverip");
					ServerPort = StringConverter::parseInt(xml->GetAttributeValueSafe("serverport"));
					ClientPort = StringConverter::parseInt(xml->GetAttributeValueSafe("clientport"));
				}
				else if (String("player") == xml->GetNodeName())
				{
					NickName = xml->GetAttributeValueSafe("nickname");
					ModelType = xml->GetAttributeValueSafe("modeltype");
				}				
				else if (String("script") == xml->GetNodeName())
				{
					ScriptLanguage = xml->GetAttributeValueSafe("language");
					ScriptPath = xml->GetAttributeValueSafe("path");
				}
				else if (String("resources") == xml->GetNodeName())
				{
					BaseResourceName = xml->GetAttributeValueSafe("baseresourcename");
					BaseAudioResourceName = xml->GetAttributeValueSafe("baseaudioresourcename");
				}
				else if (String("database") == xml->GetNodeName())
				{
					DefaultDatabaseName = xml->GetAttributeValueSafe("location");
				}
				else if (String("physics") == xml->GetNodeName())
				{
					DefaultPhysicsStrategy = xml->GetAttributeValueSafe("defaultstrategy");
				}
				else if (String("rendering") == xml->GetNodeName())
				{
					PopulateRendering(xml);
				}
				else if (String("key") == xml->GetNodeName())
				{
					PopulateKey(xml);
				}
				else if (String("archive") == xml->GetNodeName())
				{
					PopulateFolderFileArchive(xml);
				}
				else if (String("zip") == xml->GetNodeName())
				{
					PopulateZipFileArchive(xml);
				}
				else if (String("plugins") == xml->GetNodeName())
				{
					PopulatePluginPaths(xml);
				}
			}
            break;
        }
    }

	// Remove the xml reader
	CORE_DELETE(xml);

	assert(_CrtCheckMemory());
}

void CConfiguration::PopulateVideo(IXMLReader* xml)
{
	VideoModeX = xml->GetAttributeValueSafe("width");
	VideoModeY = xml->GetAttributeValueSafe("height");
	VideoDepth = xml->GetAttributeValueSafe("depth");
	EnableFullscreen = xml->GetAttributeValueSafe("fullscreen");
	if(EnableFullscreen == "true")
		EnableFullscreen = "Yes";
	else if(EnableFullscreen == "false")
		EnableFullscreen = "No";

	VideoDriver = xml->GetAttributeValueSafe("driver");
	if(VideoDriver == "ogl")
	{
		VideoDriver = "RenderSystem_GL";
		DriverType = EDT_OPENGL;
	}
	else if(VideoDriver == "dx9")
	{
		VideoDriver = "RenderSystem_Direct3D9";
		DriverType = EDT_DIRECT3D9;
	}
	else if(VideoDriver == "dx10")
	{
		CORE_THROW("DirectX 10 no longer supported.", "CConfiguration::PopulateVideo");
	}
	else if(VideoDriver == "dx11")
	{
		VideoDriver = "RenderSystem_Direct3D11";
		DriverType = EDT_DIRECT3D11;
	}
	else
	{
		CORE_THROW("Invalid video driver.", "CConfiguration::PopulateVideo");
	}

#ifdef _DEBUG
	VideoDriver += "_d";
#endif
}

void CConfiguration::PopulateKey(IXMLReader* xml)
{
	String action = xml->GetAttributeValueSafe("action");
	String key1 = xml->GetAttributeValueSafe("key1");
	String key2 = xml->GetAttributeValueSafe("key2");

	// TODO: finish this, right now user input is not mapped.
}

void CConfiguration::PopulateFolderFileArchive(IXMLReader* xml)
{
	bool isEnd = false;
	while(xml && xml->Read())
	{
		switch(xml->GetNodeType())
		{
		case IO::XML_NODE_ELEMENT:
			{
				isEnd = false;
				if (String("FolderFileArchive") == xml->GetNodeName())
				{
					RESOURCE_ITEM temp;
					temp.Name = String(xml->GetAttributeValue("dir"));
			 		temp.Group = String(xml->GetAttributeValue("group"));
					FolderList.push_back(temp);
				}
			}
		case IO::XML_NODE_ELEMENT_END:
			{
				if(isEnd)
					return;
				else
					isEnd = true;
			}
		}
	}
}

void CConfiguration::PopulateZipFileArchive(IXMLReader* xml)
{
	bool isEnd = false;
	while(xml && xml->Read())
	{
		switch(xml->GetNodeType())
		{
		case IO::XML_NODE_ELEMENT:
			{
				isEnd = false;
				if (String("ZipFileArchive") == xml->GetNodeName())
				{
					RESOURCE_ITEM temp;
					temp.Name = String(xml->GetAttributeValue("zip"));
			 		temp.Group = String(xml->GetAttributeValue("group"));
					ZipList.push_back(temp);
				}
			}
		case IO::XML_NODE_ELEMENT_END:
			{
				if(isEnd)
					return;
				else
					isEnd = true;
			}
		}
	}
}

void CConfiguration::PopulatePluginPaths(IXMLReader* xml)
{
	while(xml && xml->Read())
	{
		switch(xml->GetNodeType())
		{
		case IO::XML_NODE_ELEMENT:
			{
				if (String("path") == xml->GetNodeName())
				{
					String str = String(xml->GetAttributeValueSafe("dir"));
					PluginPaths.push_back(str);
				}
			}
		case IO::XML_NODE_ELEMENT_END:
			{
				if (String("plugins") == xml->GetNodeName())
				{
					return;
				}
			}
		}
	}
}

void CConfiguration::PopulateRendering(IXMLReader* xml)
{
	while(xml && xml->Read())
	{
		auto test1 = xml->GetNodeName();
		switch(xml->GetNodeType())
		{
		case IO::XML_NODE_ELEMENT:
			{
				if (String("plugin") == xml->GetNodeName())
				{
					String name = String(xml->GetAttributeValueSafe("name"));
					#ifdef _DEBUG
						name += "_d";
					#endif
					int order = StringConverter::parseInt(String(xml->GetAttributeValueSafe("order")));
					if(order < 1)
						CORE_THROW("Invalid plugin order number.", "CConfiguration::PopulateRendering");
					RenderPlugins[order] = name;
				}
			}
		case IO::XML_NODE_ELEMENT_END:
			{
				if (String("rendering") == xml->GetNodeName())
				{
					// Validate the order and ensure we are not missing any numbers
					auto pluginCount = RenderPlugins.size();
					for(u32 i = 1; i <= pluginCount; ++i)
					{
						if(RenderPlugins.find(i) == RenderPlugins.end())
							CORE_THROW("Plugin order is missing.", "CConfiguration::PopulateRendering");
					}
					return;
				}
			}
		}
	}

	
}