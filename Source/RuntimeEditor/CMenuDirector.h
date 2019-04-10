#ifndef __CMENU_DIRCTOR_H__
#define __CMENU_DIRCTOR_H__

#include "Defines.h"
#include "EditorObjects.h"

#include "MyGui/MyGUI.h"

namespace Core
{
	class CBuilding;
	class CGameObject;

	namespace GUI
	{
		class CGuiStrategy_MyGui;
	}

namespace Editor
{
	class CObjectsMenu;
	class CSoundProperties;
	class CMeshMenu;
	class CPlayerProperties;
	class CVolumeMenu;
	class CPhysicsProfileMenu;
	class CPhysicsSandboxOde;
	class CAStarMenu;
	class CSpawnPoints;
	class CBuildingMenu;
	class CMeshHierarchy;
	class CLightMenu;

	struct GEN_PROPERTY;
	struct SOUND_OBJ;

	class CMenuDirector
	{
		friend CObjectsMenu;

	public:
		static CMenuDirector* Instance();
		~CMenuDirector();

		void SetVisible(bool Visible);
		void SetObjectsMenuView(bool Visible);
		void SetSoundPropMenuView(bool Visible, SOUND_OBJ* SoundObject = nullptr);
		void SetPhysicsProfileMenuView(bool Visible);
		void SetMeshMenuView(bool Visible);
		void SetMeshMenuView(bool Visible, const SELECTED& Selected, CGameObject* GameObject = nullptr);
		void SetPlayerPropMenuView(bool Visible, CPlayer* Player = nullptr);
		void SetVolumeMenuView(bool Visible);
		void SetPhysicsSandboxOdeView(bool Visible);
		void SetPhysicsSandboxOdeView(bool Visible, const SELECTED& Selected, CGameObject* GameObject);
		void SetAStarMenuView(bool Visible);
		void SetAStarMenuView(bool Visible, const SELECTED& Selected);
		void SetSpawnPointsMenuVisible(bool Visible);
		void SetSpawnPointsMenuVisible(bool Visible, const SELECTED& Selected, CGameObject* GameObject);
		void SetBuildingMenuVisible(bool Visible);
		void SetBuildingMenuVisible(bool Visible, const SELECTED& Selected, CBuilding* Building);
		void SetMeshHierarchyMenuVisible(bool Visible);
		void SetMeshHierarchyMenuVisible(bool Visible, const SELECTED& Selected, CGameObject* GameObject);
		void SetLightMenuVisible(bool Visible);
		void SetLightMenuVisible(bool Visible, const SELECTED& Selected, CGameObject* GameObject);

		GUI::CGuiStrategy_MyGui*  GetGuiStrategy() { return m_GuiStrategy; }
		GEN_PROPERTY*			  GetGenProp();

		void Start();
		void Shutdown();
		void Update(f32 elapsedTime);

		void Play();
		void Pause();
		
		void Save(const String& FileName);

		static bool		isRunning;					// Have we shutdown (because this is a singelton)
		bool			isPaused;
		bool			isVisible;
		bool			isRayTest;					// Is the ray test started
		SELECTED		Selected;					// Currently selected item, obj, thing (if any)
		Vector3			m_CameraDirection;			// For setting and resetting the camers when the level is played or pasued

	private:
		// Play/Pause
		void btnPlay_Click(MyGUI::Widget* _sender);
		void btnPause_Click(MyGUI::Widget* _sender);

		static CMenuDirector*	MenuDirector;
		Vector3					m_CameraPosition;	// Setting for the camera if we remove it
		bool					isSceneLoading;		// Are we in the middle of loading a scene, so we don't over lap in with the frame listener

		CMenuDirector();
		void Init();

		GEN_PROPERTY*			 GeneralProperty;	// Values for the property menu
		GUI::CGuiStrategy_MyGui* m_GuiStrategy;
		CObjectsMenu*			 m_ObjectsMenu;
		CSoundProperties*		 m_SoundProperties;
		CMeshMenu*				 m_MeshMenu;
		CPlayerProperties*		 m_PlayerProperties;
		CVolumeMenu*			 m_VolumeMenu;
		CPhysicsProfileMenu*	 m_PhysicsProfileMenu;
		CAStarMenu*				 m_AStarMenu;
		CSpawnPoints*			 m_SpawnPoints;
		CBuildingMenu*			 m_BuildingMenu;
		CMeshHierarchy*			 m_MeshHierarchy;
		CLightMenu*				 m_LightMenu;
		#ifdef COMPILE_ODE
		CPhysicsSandboxOde*		 m_PhysicsSandboxOde;
		#endif
		
		MyGUI::StaticImage* btnPlay;
		MyGUI::StaticImage* btnPause;
		MyGUI::ScrollBar*	sldMasterSpeed;
	};

}
}

#endif // __CMENU_DIRCTOR_H__