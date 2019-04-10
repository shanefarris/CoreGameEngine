#ifndef __CRUNTIMEMENUMANAGER_H__
#define __CRUNTIMEMENUMANAGER_H__

#include "Defines.h"

namespace Sound
{
	class CSoundManager;
}

namespace Core
{
	class CItemsManager;
	class CGameManager;
	class CCameraManager;
	class CGameObjectManager;
	struct SceneImporterPackage;

	namespace Physics
	{
		class IPhysicsStrategy;
	}

	namespace Nature
	{
		class CWorld;
		class CNatureManager;
	}

namespace Editor
{
	class CCustomFrameListener;
	class CObjectsMenu;
	class CPropertiesMenu;
	class CMenuDirector;
	struct SOUND_OBJ;
	struct PAGED_GEO;

	class CORE_EXPORT CRuntimeEditorManager
	{
	public:
		static CRuntimeEditorManager* Instance();
		~CRuntimeEditorManager();
		bool InitEditor(SceneImporterPackage& SIP);			// Called to start and initialize the editor
		bool StartEditor();									// Shows the menu system
		bool StopEditor();									// Pauses the editor
		bool Shutdown();									// Stop using the editor and deletes all components
		bool CreatePlane();									// Helper method to testing environments
		bool IsRunning();									// Is the editor initialized and running, (is it running even if its not visible)

		void		GetSoundObjects(Vector<SOUND_OBJ*>& SoundObjects);
		SOUND_OBJ*	GetSoundObject(const char* EntityName);
		void		AddSoundObject(const SOUND_OBJ& SoundObject);
		void		RemoveSoundObject(SOUND_OBJ* SoundObject);
		
		// Serialize data that is not supported in Core's serialzition process
		void WritePagedGeometry(const PAGED_GEO& PagedGeo);

	private:
		CRuntimeEditorManager();

		bool HaveRequiredResources();
		void InitializeTestInventory();

		static CRuntimeEditorManager*	RuntimeEditorManager;
		CMenuDirector*					m_MenuDirector;
		CCustomFrameListener*			m_CustomFrameListener;
		Core::CGameManager*				m_GameManager;
		Physics::IPhysicsStrategy*		m_PhysicsStrategy; 
		Sound::CSoundManager*			m_SoundManager;
		Core::CItemsManager*			m_ItemsManager;
		Core::CGameObjectManager*		m_GameObjectManager;
		Core::Nature::CNatureManager*	m_NatureManager;
		Core::CCameraManager*			m_CameraManager;

		bool							isRunning;
		Nature::CWorld*					m_CurrWorld;

		// Editor objects
		Vector<SOUND_OBJ*>				m_EditorSounds;
	};

}
}

#endif // __CRUNTIMEMENUMANAGER_H__