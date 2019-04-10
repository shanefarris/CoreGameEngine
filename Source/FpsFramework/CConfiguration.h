#ifndef __CCONFIGURATION_H__
#define __CCONFIGURATION_H__

#include "Defines.h"
#include "IO/IXMLReader.h"

namespace Core
{ 	
	enum KeyCode;
	enum E_DRIVER_TYPE;

	//bad naming
	struct RESOURCE_ITEM
	{
		String Name; 
		String Group;
	};

	class CConfiguration
	{
	private:
		CConfiguration();

		void PopulateKey();
		void PopulateVideo(IO::IXMLReader* xml);
		void PopulateFolderFileArchive(IO::IXMLReader* xml);
		void PopulateZipFileArchive(IO::IXMLReader* xml);
		void PopulateKey(IO::IXMLReader* xml);
		void PopulatePluginPaths(IO::IXMLReader* xml);
		void PopulateRendering(IO::IXMLReader* xml);

		static CConfiguration* Configuration;

		// Key bindings (2 elements because we can give the player two keys to do the same thing)
		KeyCode key_moveleft[2];
		KeyCode key_moveright[2];
		KeyCode key_moveforward[2]; 
		KeyCode key_movebackward[2]; 
		KeyCode key_jump[2]; 
		KeyCode key_crouch[2]; 
		KeyCode key_fire1[2]; 
		KeyCode key_fire2[2];

	public:
		static CConfiguration* Instance();
		~CConfiguration() { }

		void LoadConfig(bool restore = false);
		void SaveConfig();

		// Settings
		String	NickName;
		String	ModelType;
		String	ServerName;
		String	ServerIP;
		String	ScriptPath;
		String	ScriptLanguage;
		String	BaseResourceName;
		String	BaseAudioResourceName;
		String	DatabaseLocation;
		String	DefaultDatabaseName;
		String	DefaultPhysicsStrategy;
		s32		ServerPort;
		s32		ClientPort;
		f32		SoundVolume;
		f32		MusicVolume;
		bool	EnableAudio;

		// Video
		String VideoDriver;
		String EnableFullscreen;
		String VideoDepth;
		String VideoModeX;
		String VideoModeY;
		E_DRIVER_TYPE DriverType;

		Vector<RESOURCE_ITEM>	FolderList;
		Vector<RESOURCE_ITEM>	ZipList;
		Vector<String>			PluginPaths;
		Map<int, String>		RenderPlugins;

	};
}

#endif //__CCONFIGURATION_H__


