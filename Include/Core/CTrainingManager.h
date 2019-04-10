#ifndef __CTRAININGMANAGER_H__
#define __CTRAININGMANAGER_H__

#include "Defines.h"

namespace Core
{
	class CPlayer;
	class CPlayerAttributesComponent;
	enum E_PLAYER_TEAM;

namespace Training
{
	enum ET_CAPABILITIES
	{
		ETC_BASIC_INFANTRY		= 0,
		ETC_BASIC_ENGINEER		= 1,
		ETC_BASIC_HTH_COMBAT	= 2,		// Hand to hand
	};

	class CORE_EXPORT CTrainingManager
	{
	public:
		static CTrainingManager* Instance();

		~CTrainingManager();

		// General methods
		bool AddFacility(E_PLAYER_TEAM Team, u32 BuildingType);
		bool RemoveFacility(E_PLAYER_TEAM Team, u32 BuildingType);
		bool IsCapable(E_PLAYER_TEAM Team, ET_CAPABILITIES Cap);

		// Player methods
		bool StartPlayerTraining(CPlayer* Player, CPlayerAttributesComponent* GoalAttributes);
		bool StopPlayerTraining(CPlayer* Player);
		bool IsPlayerTraining(CPlayer* Player);
		void GetPlayerTrainingList(E_PLAYER_TEAM Team, Vector<u32>& List);

		// Events
		void OnPlayerAttributeUpdate();
		void Update(const f32& elapsedTime);

	private:
		static CTrainingManager* TrainingManager;
		CTrainingManager();

		// List of building type values grouped by teams
		Vector<u32>	TeamBuildings[NUM_TEAMS -1];

		// List of players in training grouped by teams
		Vector<CPlayer*> m_PlayersTraining[NUM_TEAMS - 1];

	};
}
}

#endif // __CTRAININGMANAGER_H__