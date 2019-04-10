#ifndef __SCENE_IMPORT_PACKAGE_H__
#define __SCENE_IMPORT_PACKAGE_H__

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

	namespace Physics
	{
		class IPhysicsStrategy;
	}

	namespace Nature
	{
		class CNatureManager;
	}

	// Used to package of the current state of the application and send it over to another library
	struct SceneImporterPackage
	{
		SceneImporterPackage() 
			: GameManager(nullptr), 
			PhysicsStrategy(nullptr), 
			SoundManager(nullptr), 
			ItemsManager(nullptr), 
			GameObjectManager(nullptr), 
			NatureManager(nullptr), 
			CameraManager(nullptr) 
		{ 
		}

		Core::CGameManager*				GameManager;
		Physics::IPhysicsStrategy*		PhysicsStrategy; 
		Sound::CSoundManager*			SoundManager;
		Core::CItemsManager*			ItemsManager;
		Core::CGameObjectManager*		GameObjectManager;
		Core::Nature::CNatureManager*	NatureManager;
		Core::CCameraManager*			CameraManager;
		String							ResourceGroupName;
	};

}

#endif // __SCENE_IMPORT_PACKAGE_H__