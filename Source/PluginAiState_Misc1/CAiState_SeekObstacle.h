#ifndef __CAISTATE_SEEKOBSTACLE_H__
#define __CAISTATE_SEEKOBSTACLE_H__

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
		// For testing for now, finds the closes obstacle, walks to it, rinse and repeat
		class CAiState_SeekObstacle : public AI::CCharacterState
		{
		private:
			Vector3		m_TargetPosition;
			AI::Obstacle*	m_TargetObstacle;

			bool FindClosestObstacle();

		public:
			CAiState_SeekObstacle(CPlayer* Player);
			AI::E_CHARACTER_STATE_OUTCOME Update(f32 elapsedTime);

		};

		class CAiState_SeekObstacleFactory : public IAiStateFactory
		{
		public:
			CAiState_SeekObstacleFactory();
			~CAiState_SeekObstacleFactory();
			Core::AI::CCharacterState* GetCharacterState(CPlayer* Player);
		};

	}
}

#endif // __CAISTATE_SEEKOBSTACLE_H__