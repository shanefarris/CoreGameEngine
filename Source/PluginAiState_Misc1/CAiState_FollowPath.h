// Walks a path given as a vector, and will end once the vehicle reaches the end point

#ifndef __CAISTATE_FOLLOWPATH_H__
#define __CAISTATE_FOLLOWPATH_H__

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
		class CAiState_FollowPath : public AI::CCharacterState
		{
		private:
			Vector<Vector3> m_PathPoints;

		public:
			CAiState_FollowPath(CPlayer* Player);
			AI::E_CHARACTER_STATE_OUTCOME Update(f32 elapsedTime);

		};

		class CAiState_FollowPathFactory : public IAiStateFactory
		{
		public:
			CAiState_FollowPathFactory();
			~CAiState_FollowPathFactory();
			Core::AI::CCharacterState* GetCharacterState(CPlayer* Player);
		};

	}
}

#endif // __CAISTATE_FOLLOWPATH_H__