#ifndef __CAI_STATE_DEFEND_H__
#define __CAI_STATE_DEFEND_H__

#include "Defines.h"
#include "Plugins/PluginTypes.h"
#include "Plugins/IAiStateFactory.h"
#include "CCharacterState.h"
#include "OgreVector3.h"

namespace Core
{
	class CPlayer;
	class CGameObjectManager;

	namespace Plugin
	{
		class CAiState_Defend : public Core::AI::CCharacterState
		{
		public:
			CAiState_Defend(CPlayer* Player);

			Core::AI::E_CHARACTER_STATE_OUTCOME Update(f32 elapsedTime);

		private:
			Core::AI::E_CHARACTER_STATE_OUTCOME FailState();
			void LookForTargets();

			u32					m_CheckCount;
			Vector3				m_TargetPos;
			CGameObjectManager* m_GameObjectManager;
			
		};	

		class CAiState_DefendFactory : public IAiStateFactory
		{
		public:
			CAiState_DefendFactory();
			~CAiState_DefendFactory();

			Core::AI::CCharacterState* GetCharacterState(CPlayer* Player);
		};
	}
}

#endif // __CAI_STATE_DEFEND_H__