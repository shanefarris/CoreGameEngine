#ifndef __CGAME_H__
#define __CGAME_H__

#include "Defines.h"

// Base class which manages the standard startup of an application.
namespace Core
{
	class CGameManager;
	class CInputManager;
	class CGameState;
	class CPluginManager;
	class CGameObjectManager;
	class CCameraManager;
	class CItemsManager;
	class CBillboardManager;
	
	namespace AI
	{
		class CCharacterStateManager;
	}

	namespace OgreSpecific
	{
		class CTextOutput;
	}

	namespace GUI
	{
		class CGuiManager;
	}

	namespace Nature
	{
		class CNatureManager;
	}

	namespace Effects
	{
		class CEffectsManager;
	}

	namespace Physics
	{
		class CPhysicsManager;
	}

	namespace Mission
	{
		class CMissionManager;
	}

	class CORE_EXPORT CGame
	{
	public:
		CGame();
		~CGame();

		void Run();

		void AddGameState(CGameState* GameState);
		void AdvanceState();
	  
	private:
		CGameManager*				m_GameManager;
		CInputManager*				m_InputManager;
		CPluginManager*				m_PluginManager;
		GUI::CGuiManager*			m_GuiManager;
		AI::CCharacterStateManager* m_CharacterStateManager;
		CGameObjectManager*			m_GameObjectManager;
		CCameraManager*				m_CameraManager;
		CItemsManager*				m_ItemsManager;
		CBillboardManager*			m_BillboardManager;
		Nature::CNatureManager*		m_NatureManager;
		Effects::CEffectsManager*	m_EffectsManager;
		Physics::CPhysicsManager*	m_PhysicsManager;
		Mission::CMissionManager*	m_MissionManager;

		OgreSpecific::CTextOutput*	m_TextOutput;
		CGameState*					m_ActiveState;
		Timer*						m_Timer;
		ul32						m_LastTime;
		f32							m_DeltaTime;
		Vector<CGameState*>			m_States;
	};
}

#endif // __CGAME_H__
