#ifndef __CAI_STATE_SEEK_ENEMEY_H__
#define __CAI_STATE_SEEK_ENEMEY_H__

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
		class CAiState_FindEnemy : public Core::AI::CCharacterState
		{
		public:
			CAiState_FindEnemy(CPlayer* Player);

			Core::AI::E_CHARACTER_STATE_OUTCOME Update(f32 elapsedTime);

		private:
			u32					m_CheckCount;
			Vector3			m_TargetPos;
			CGameObjectManager* m_GameObjectManager;
			
		};	

		class CAiState_FindEnemyFactory : public IAiStateFactory
		{
		public:
			CAiState_FindEnemyFactory();
			~CAiState_FindEnemyFactory();

			Core::AI::CCharacterState* GetCharacterState(CPlayer* Player);
		};
	}
}

#endif // __CAI_STATE_SEEK_ENEMEY_H__