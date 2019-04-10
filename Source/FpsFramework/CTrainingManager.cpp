#include "CTrainingManager.h"
#include "FileDatabase/CoreDal.h"
#include "PlayerEnums.h"
#include "CPlayerAttributesComponent.h"

using namespace Core;
using namespace Core::Training;

CTrainingManager* CTrainingManager::TrainingManager = nullptr;

CTrainingManager* CTrainingManager::Instance()
{
	if(!TrainingManager)
		TrainingManager = new CTrainingManager();
	return TrainingManager;
}

CTrainingManager::CTrainingManager()
{
}

CTrainingManager::~CTrainingManager()
{
}

bool CTrainingManager::AddFacility(E_PLAYER_TEAM Team, u32 BuildingType)
{
	// Check to see if we are not asking for a team number greater then what we have
	if((u32)Team <= (NUM_TEAMS -1))
	{
		TeamBuildings[(u32)Team].push_back(BuildingType);
	}

	return false;
}

bool CTrainingManager::RemoveFacility(E_PLAYER_TEAM Team, u32 BuildingType)
{
	// Check to see if we are not asking for a team number greater then what we have
	if((u32)Team <= (NUM_TEAMS -1))
	{
		Vector<u32>::iterator it;
		for(it = TeamBuildings[(u32)Team].begin(); it != TeamBuildings[(u32)Team].end(); it++)
		{
			if(BuildingType == (*it))
				break;
		}
		TeamBuildings[(u32)Team].erase(it);
		return true;
	}

	return false;
}

bool CTrainingManager::IsCapable(E_PLAYER_TEAM Team, ET_CAPABILITIES Cap)
{
	for(auto it = TeamBuildings[Team].cbegin(); it != TeamBuildings[Team].cend(); it ++)
	{
		// Does the capability that we are looking for match whats in the list
		if(*it == (u32)Cap)
			return true;
	}

	return false;
}

bool CTrainingManager::StartPlayerTraining(CPlayer* Player, CPlayerAttributesComponent* GoalAttributes)
{
	return false;
}

bool CTrainingManager::StopPlayerTraining(CPlayer* Player)
{
	return false;
}

bool CTrainingManager::IsPlayerTraining(CPlayer* Player)
{
	return false;
}

void CTrainingManager::GetPlayerTrainingList(E_PLAYER_TEAM Team, Vector<u32>& List)
{
}

void CTrainingManager::OnPlayerAttributeUpdate()
{
}

void CTrainingManager::Update(const f32& elapsedTime)
{
	static int steps = 0;

}