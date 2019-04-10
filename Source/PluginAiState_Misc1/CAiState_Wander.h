#ifndef __CAISTATE_WANDER_H__
#define __CAISTATE_WANDER_H__

#include "Defines.h"
#include "Plugins/IAiStateFactory.h"
#include "CCharacterState.h"

#include "OgreVector3.h"

namespace Core
{
	class CPlayer;

	namespace AI
	{
		class Obstacle;
	}

	namespace Plugin
	{
		class CAiState_Wander : public AI::CCharacterState
		{
		private:
			Vector3	m_TargetCenter;

		public:
			CAiState_Wander(CPlayer* Player);
			AI::E_CHARACTER_STATE_OUTCOME Update(f32 elapsedTime);

		};

		class CAiState_WanderFactory : public IAiStateFactory
		{
		public:
			CAiState_WanderFactory();
			~CAiState_WanderFactory();
			Core::AI::CCharacterState* GetCharacterState(CPlayer* Player);
		};

	}
}

#endif // __CAISTATE_WANDER_H__