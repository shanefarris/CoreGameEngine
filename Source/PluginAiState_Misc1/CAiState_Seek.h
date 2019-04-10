#ifndef __CAISTATE_SEEK_H__
#define __CAISTATE_SEEK_H__

#include "Defines.h"
#include "Plugins/IAiStateFactory.h"
#include "CCharacterState.h"

namespace Core
{
	class CPlayer;

	namespace AI
	{
		class Obstacle;
		class CFpsVehicle;
	}

	namespace Plugin
	{
		class CAiState_Seek : public AI::CCharacterState
		{
		private:
			AI::CFpsVehicle* m_VehicleTarget;
			
		public:
			CAiState_Seek(CPlayer* Player);
			AI::E_CHARACTER_STATE_OUTCOME Update(f32 elapsedTime);

		};

		class CAiState_SeekFactory : public IAiStateFactory
		{
		public:
			CAiState_SeekFactory();
			~CAiState_SeekFactory();
			Core::AI::CCharacterState* GetCharacterState(CPlayer* Player);

		};

	}
}

#endif // __CAISTATE_SEEK_H__