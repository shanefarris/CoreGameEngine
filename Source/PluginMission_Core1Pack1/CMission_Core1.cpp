#include "CMission_Core1.h"
#include "MissionEvents.h"

using namespace Core;
using namespace Core::Plugin;
using namespace Core::Mission;

CMission_Core1::CMission_Core1()
{
	// Just kill enemy
	CompletionDefinition = MT_ELIMINATE;
	m_MissionStatus = MS_STOPPED;
	KillCount = 0;
	KillGoal = 3;

	LableName = "Core1_Mission1";
}

CMission_Core1::~CMission_Core1()
{
}

void CMission_Core1::OnStart()
{
	m_MissionStatus = MS_WORKING;
}

void CMission_Core1::OnFail()
{
	m_MissionStatus = MS_FAILED;
}

void CMission_Core1::OnComplete()
{
	m_MissionStatus = MS_SUCCESS;
}

Core::Mission::MISSION_STATUS CMission_Core1::Update()
{
	if(KillCount >= KillGoal && m_MissionStatus == MS_WORKING)
	{
		OnComplete();
		m_MissionStatus = MS_SUCCESS;
	}
	return m_MissionStatus;
}

void CMission_Core1::RegisterEvent(CMissionEvent* Event)
{
	if(Event->Killed && Event->Projectile && Event->InventoryItem)
		KillCount++;
}

CMissionFactory_Core1::CMissionFactory_Core1()
{
	LabelName = "Core1_Mission1";
}

CMissionFactory_Core1::~CMissionFactory_Core1()
{
}

Core::Mission::IMission* CMissionFactory_Core1::GetMission()
{
	return new CMission_Core1();
}