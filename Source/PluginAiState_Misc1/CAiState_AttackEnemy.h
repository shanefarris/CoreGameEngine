#ifndef __CAI_STATE_ATTACK_ENEMEY_H__
#define __CAI_STATE_ATTACK_ENEMEY_H__

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
		class CAiState_AttackEnemy : public Core::AI::CCharacterState
		{
		public:
			CAiState_AttackEnemy(CPlayer* Player);

			Core::AI::E_CHARACTER_STATE_OUTCOME Update(f32 elapsedTime);

		private:
			void Pursue(const f32& elapsedTime, const f32& Radius);
			Core::AI::E_CHARACTER_STATE_OUTCOME FailState();

			u32					m_CheckCount;
			Vector3				m_TargetPos;
			CGameObjectManager* m_GameObjectManager;
			
		};	

		class CAiState_AttackEnemyFactory : public IAiStateFactory
		{
		public:
			CAiState_AttackEnemyFactory();
			~CAiState_AttackEnemyFactory();

			Core::AI::CCharacterState* GetCharacterState(CPlayer* Player);
		};
	}
}

#endif // __CAI_STATE_ATTACK_ENEMEY_H__