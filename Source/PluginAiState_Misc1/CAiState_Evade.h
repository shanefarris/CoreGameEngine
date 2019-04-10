#ifndef __CAISTATE_EVADE_H__
#define __CAISTATE_EVADE_H__

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
		class CAiState_Evade : public AI::CCharacterState
		{
		private:
			Vector3	m_TargetCenter;

		public:
			CAiState_Evade(CPlayer* Player);
			AI::E_CHARACTER_STATE_OUTCOME Update(f32 elapsedTime);

		};

		class CAiState_EvadeFactory : public IAiStateFactory
		{
		public:
			CAiState_EvadeFactory();
			~CAiState_EvadeFactory();
			Core::AI::CCharacterState* GetCharacterState(CPlayer* Player);
		};

	}
}

#endif // __CAISTATE_EVADE_H__