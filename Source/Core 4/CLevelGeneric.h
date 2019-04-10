#ifndef __CLEVELGENERIC_H__
#define __CLEVELGENERIC_H__

#include "CGameState.h"
#include "CFpsFrameListener.h"
#include "CPlayer.h"

class CPlayerZombie;

namespace Core
{
	namespace Physics
	{
		class CPhysicsManager;
	}

	namespace Editor
	{
		class CRuntimeEditorManager;
	}

	class CLevelGeneric: public CGameState
	{
	private:
		CFpsFrameListener*				m_FrameListenerFramework;
		Physics::CPhysicsManager*		m_PhysicsManager;
		Editor::CRuntimeEditorManager*	m_RuntimeEditorManager;

	public:
		CLevelGeneric(){}
		~CLevelGeneric();

		void Update(const f32& deltaTime);
		bool Load();
		void End(){}
	};
}

#endif // __CLEVELGENERIC_H__
