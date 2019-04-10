// The serializer will save/load dynamic data after the scene loader has loaded the static game data

#ifndef __CSERIALIZER_H__
#define __CSERIALIZER_H__

#include "Defines.h"

class Database;

namespace Core
{
	class CSerializer
	{
	public:
		CSerializer();
		~CSerializer();

		// Saves game state (dynamic) data
		bool SaveGame(const char* FileName);

		// Lists all saved games and/or scenes
		void GetSavedFiles(Vector<String>& list);

	private:
		struct TAG_ELEMENT
		{
			TAG_ELEMENT(const char* name, const char* value)
			{
				Name = name;
				Value = value;
			}

			TAG_ELEMENT(const char* name, const String& value)
			{
				Name = name;
				Value = value.c_str();
			}

			String Name;
			String Value;
		};

		struct MASTER_ELEMENT
		{
			MASTER_ELEMENT(String Name, Vector<TAG_ELEMENT> Tags)
			{
				TagName = Name;
				Elements = Tags;
			}

			String TagName;
			Vector<TAG_ELEMENT> Elements;
		};

		friend class CPlayer;

		// DB data
		bool SavePlayers(Database* Db);
		bool SaveItems(Database* Db);
		bool SavePhysics(Database* Db);
		bool SaveGameObjects(Database* Db);
		bool SaveAiPaths(Database* Db);
		bool SaveAStarGrid(Database* Db);
		bool SaveSpawnPoints(Database* Db);
		bool SaveBuildings(Database* Db);
		bool Execute(const String& FileName, const String& Command);
		
		// Xml data
		bool SaveInventoryProfiles();
		bool SavePhysicsProfiles();
		bool SaveStaticData(Database* Db);

		Vector<MASTER_ELEMENT>	m_Elements;
		
	};
}

#endif // __CSERIALIZER_H__