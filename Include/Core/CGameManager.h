// Container for application level data.

#ifndef __CGAMEMANAGER_H__
#define __CGAMEMANAGER_H__

#include "Defines.h"
#include "CoreStructures.h"

namespace Ogre
{
	class OverlaySystem;
}

namespace Core
{
	class CGame;
	class CConfiguration;
	class CGameObjectManager;
	class CCameraManager;
	class CItemsManager;
	class CBillboardManager;
	class CSceneImporter;

	namespace Effects
	{
		class CEffectsManager;
	}

	namespace Nature
	{
		class CNatureManager;
	}

	namespace Physics
	{
		class CPhysicsManager;
	}

	class CORE_EXPORT CGameManager
	{
	private:
		static CGameManager*	GameManager;
		
		CGame*					m_Game;
		CConfiguration*			Configuration;
	 	EngineDevice*			m_EngineDevice;
		SceneManager*			m_SceneManager;
		RenderWindow*			m_RenderWindow;
		OverlaySystem*			m_OverlaySystem;
		CSceneImporter*			m_SceneImporter;
		Timer*					m_Timer;
		bool					isShouldQuit;
		bool					isConsoleOpened;
		String					m_StaticData;
		String					m_BaseResourceName;
		String					m_BaseAudioResourceName;
		String					m_DefaultDatabaseName;

		// Managers to update
		CGameObjectManager*			m_GameObjectManager;
		CCameraManager*				m_CameraManager;
		CItemsManager*				m_ItemsManager;
		Nature::CNatureManager*		m_NatureManager;
		Effects::CEffectsManager*	m_EffectsManager;
		CBillboardManager*			m_BillboardManager;
		Physics::CPhysicsManager*	m_PhysicsManager;

		void InitializeEngine();
		void Initialize();

	protected:
		CGameManager();

	public:
		bool isSupportShaders;

		static CGameManager* Instance();
		
		~CGameManager();

		inline EngineDevice* GetEngineDevice();
		inline SceneManager* GetSceneManager();
		inline RenderWindow* GetRenderWindow();
		inline Timer*		 GetTimer();
		inline E_DRIVER_TYPE GetVideoDeviceType();

		inline void SetEngineDevice(EngineDevice* e);
		inline void SetSceneManager(SceneManager* s);
		inline void SetRenderWindow(RenderWindow* r);
		inline void SetGame(CGame* Game);
		inline void SetQuit(bool quit);

		// Loop
		inline bool GetQuit();
		inline void AdvanceGameState();
		inline void UpdateGame(const f32& elapsedTime);
		void		Shutdown();

		// Console status
		inline bool GetConsoleVisible() { return isConsoleOpened; }
		inline void SetConsoleVisible(bool Visible) { isConsoleOpened = Visible; }

		// Resources
		void AddResourceArchive(const char* FileName, const char* GroupName);
		void RemoveResourceArchive(const char* FileName, const char* GroupName);

		// Serialization
		bool	SaveGame(const char* FileName);
		bool	LoadGame(const char* FileName, const String& ResourceGroupName);
		void	SetStaticData(const String& StaticData) { m_StaticData = StaticData; }	// TODO: This is a temp solution for saving static data for a level.
		String& GetStaticData() { return m_StaticData; }

		// Data driven Settings
		inline void			SetBaseResourceName(const String& ResourceName);
		inline void			SetBaseAudioResourceName(const String& ResourceName);
		inline const char*	GetBaseResourceName();
		inline const char*	GetBaseAudioResourceName();
		inline const char*	GetScriptPath();
		inline const char*	GetDefaultPhysicsStrategy();
		inline const char*	GetDefaultDatabaseName();

		// Create a new scene manager
		SceneManager* CreateScene(const char* SceneType, const char* SceneName);	

	};
}

#endif // __CGAMEMANAGER_H__
