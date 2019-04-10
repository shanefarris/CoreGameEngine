/*
 * This class is reponsible for taking the standard Core formats (xml, db) and parses the data into structures.
 * The structres are a common form for the scene loader to use to load the data into a renderable scene.  There
 * will be as least two formats so far, xml, and db.  The db is not finished yet. (12/23/09)
 */

#ifndef __CPARSER_H__
#define __CPARSER_H__

#include "Defines.h"
#include "IO/IReadFile.h"
#include "IO/IXMLReader.h"

using namespace IO;

class Database;

namespace Core
{
	#define MAX_NAME 255

	struct DATA_CONTAINER;
	enum E_ANIM_STATE;

	// Class for parsing levels in sqlite
	class CORE_DEBUG_EXPORT CDbParserStrategy
	{
	public:
		CDbParserStrategy();
		~CDbParserStrategy();

		// The function to Import Data
		bool ParseScene(const String& Importfile, DATA_CONTAINER& DataContainer);

	private:
		bool LoadItems(DATA_CONTAINER& DataContainer);
		bool LoadAiPaths(DATA_CONTAINER& DataContainer);
		bool LoadPlayers(DATA_CONTAINER& DataContainer);
		bool LoadGameObjects(DATA_CONTAINER& DataContainer);
		bool LoadAStarGrid(DATA_CONTAINER& DataContainer);
		bool LoadSpawnPoints(DATA_CONTAINER& DataContainer);
		bool LoadBuildings(DATA_CONTAINER& DataContainer);
		bool LoadStaticData(DATA_CONTAINER& DataContainer);

		// Helper method
		bool ParseVector3D(const String& DataValue, Vector3& Out);

		Database* m_Database;
	};

	// Class for parsing levels xml format
	class CORE_DEBUG_EXPORT CXmlParserStrategy
	{
	public:
		CXmlParserStrategy();
		~CXmlParserStrategy();

		// The function to Import Data
		bool ParseScene(IXMLReader& xml, DATA_CONTAINER& DataContainer);
		bool ParseScene(const String& FileName, DATA_CONTAINER& DataContainer);

	private:
		void LoadSceneManager(IXMLReader& xml, DATA_CONTAINER& DataContainer);
		void LoadViewport(IXMLReader& xml, DATA_CONTAINER& DataContainer);
		void LoadLight(IXMLReader& xml, DATA_CONTAINER& DataContainer);
		void LoadCamera(IXMLReader& xml, DATA_CONTAINER& DataContainer);
		void LoadGameObject(IXMLReader& xml, DATA_CONTAINER& DataContainer);
		void LoadPhysicsProfile(IXMLReader& xml, DATA_CONTAINER& DataContainer);
		void LoadCaelum(IXMLReader& xml, DATA_CONTAINER& DataContainer);
		void LoadHydrax(IXMLReader& xml, DATA_CONTAINER& DataContainer);
		void LoadBgSound(IXMLReader& xml, DATA_CONTAINER& DataContainer);
		void LoadSound(IXMLReader& xml, DATA_CONTAINER& DataContainer);
		void LoadWater(IXMLReader& xml, DATA_CONTAINER& DataContainer);
		void LoadWeapon(IXMLReader& xml, DATA_CONTAINER& DataContainer);
		void LoadMagazine(IXMLReader& xml, DATA_CONTAINER& DataContainer);
		void LoadProjectile(IXMLReader& xml, DATA_CONTAINER& DataContainer);
		void LoadMelee(IXMLReader& xml, DATA_CONTAINER& DataContainer);
		void LoadPagedTerrain(IXMLReader& xml, DATA_CONTAINER& DataContainer);
		void LoadHeightTerrain(IXMLReader& xml, DATA_CONTAINER& DataContainer);
		void LoadPlaneTerrain(IXMLReader& xml, DATA_CONTAINER& DataContainer);
		void LoadSinglePlayer(IXMLReader& xml, DATA_CONTAINER& DataContainer);
		void LoadArchive(IXMLReader& xml, DATA_CONTAINER& DataContainer);
		void LoadBillboard(IXMLReader& xml, DATA_CONTAINER& DataContainer);
		void LoadPagedGeometry(IXMLReader& xml, DATA_CONTAINER& DataContainer);
		void LoadAnimationMapping(IXMLReader& xml, DATA_CONTAINER& DataContainer);

		void PopulateAnimationMappingList();
		void Tokenize(const String& str, Vector<String>& tokens, const String& delimiters = ",");

		struct AnimationMapping
		{
			AnimationMapping(String xmlAttribute, E_ANIM_STATE state) : XmlAttribute(xmlAttribute), State(state) { }

			String XmlAttribute;
			E_ANIM_STATE State;
		};
		Vector<AnimationMapping*> AnimationMappingList;
	};
}

#endif // __CPARSER_H__