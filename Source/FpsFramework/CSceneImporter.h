// Takes the structures that have been populated by the parser and loads a level based on the data in the structures.

#ifndef __CSCENEIMPORTER_H__
#define __CSCENEIMPORTER_H__

#include "Defines.h"
#include "Structures.h"
#include "SceneImporterPackage.h"

namespace Sound
{
	class CSoundManager;
}

namespace Core
{
	class CGameManager;
	class CItemsManager;
	class CGameObjectManager;
	class CCameraManager;
	class CProjectileProfile;
	class CMagazineProfile;
	struct DATA_CONTAINER;

	namespace Physics
	{
		class CPhysicsProfile;
		class IPhysicsStrategy;
	}

	namespace Nature
	{
		class CNatureManager;
	}

	class CSceneImporter
	{
	public:
		CSceneImporter();
		~CSceneImporter();

		bool ImportScene(const String& file, const String& ResourceGroupName);
		bool SerializeStructures(const String& file, const String& outFile);

	private:
		CGameManager*				m_GameManager;
		EngineDevice*				m_EngineDevice; 
		SceneManager*				m_SceneManager; 
		RenderWindow*				m_RenderWindow;
		Physics::IPhysicsStrategy*	m_PhysicsStrategy;
		Sound::CSoundManager*		m_SoundManager;
		CItemsManager*				m_ItemsManager;
		CGameObjectManager*			m_GameObjectManager;
		CCameraManager*				m_CameraManager;
		Nature::CNatureManager*		m_NatureManager;

		static const String XML_EXT;				// File extension types
		static const String DB_EXT;

		bool			m_IsPhysicStrategy;			// Was an physics strategy initialized
		String			m_ResourceGroupName;		// If we need to specific a resource group name
		DATA_CONTAINER	m_Parser;					// Parsed data container

		Vector<CMagazineProfile>	 m_Magazines;	// For weapon items
		Vector<CProjectileProfile>  m_Projectiles;

		
		

		// Loading static data
		bool LoadSceneManager();
		bool LoadCameras();
		bool LoadGameObjects();
		bool LoadPhysicProfiles();
		bool LoadNatureWorld();
		bool LoadBgSounds();
		bool LoadSounds();
		bool LoadWater();
		bool LoadLight();
		bool LoadWeaponProfiles();
		bool LoadMagazineProfiles();
		bool LoadProjectileProfiles();
		bool LoadMeleeProfiles();
		bool LoadSpawnPoints();
		bool LoadArchives();
		bool LoadBillboards();

		// Loading dynamic data
		bool LoadPlacedItems();
		bool LoadAiPaths();
		bool LoadPlayers();
		bool LoadAnimationMapping();
		bool LoadBuildings();

		// Utility methods
		SceneNode* FindNode(String Name);

		bool ParseScene(const String& Importfile);
	};
}

#endif // __CSCENEIMPORTER_H__