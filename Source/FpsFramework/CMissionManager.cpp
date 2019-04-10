#include "CMissionManager.h"
#include "CPluginManager.h"
#include "IMission.h"
#include "CPlayer.h"
#include "MissionEvents.h"

#include "IO/CoreLogging.h"

// Plugin
#include "Plugins\IMissionFactory.h"

using namespace Core;
using namespace Core::Mission;

CMissionManager* CMissionManager::MissionManager = nullptr;

CMissionManager* CMissionManager::Instance()
{
	if(!MissionManager)
		MissionManager = new CMissionManager();
	return MissionManager;
}

CMissionManager::CMissionManager()
{
	m_PluginManager = CPluginManager::Instance();
}

CMissionManager::~CMissionManager()
{
	try
	{
		// Remove active missions
		for(auto collection = m_Missions.begin(); collection != m_Missions.end(); collection++)
		{
			for(auto mission = collection->second.begin(); mission != collection->second.end(); mission++)
			{
				CORE_DELETE((*mission));
			}
		}

		auto am = m_AvailableMissions.begin();
		while(am != m_AvailableMissions.end())
		{
			m_AvailableMissions.erase(am++);
		}

		while(m_EventQueue.size() > 0)
		{
			CORE_DELETE(m_EventQueue[0]);
			m_EventQueue.erase(m_EventQueue.begin());
		}

		m_EventQueue.clear();
		m_AvailableMissions.clear();
		m_Missions.clear();

		m_PluginManager = nullptr;
	}
	catch(std::exception& e)
	{
		CORE_ASSERT(false);
		throw(e);
	}
	catch(...)
	{
		throw("Error in ~CMissionManager()");
	}
}

bool CMissionManager::StartMission(const char* MissionLabel, CPlayer* Player)
{
	if(!Player)
		return false;

	// Look for plugins next
	String str = MissionLabel;
	u32 size = (u32)m_PluginManager->GetMissionFactories().size();

	// Find the custom object (plugin) and use it
	for(u32 i = 0; i < size; i++)
	{
		if(m_PluginManager->GetMissionFactories()[i]->LabelName == str)
		{
			IMission* mission = m_PluginManager->GetMissionFactories()[i]->GetMission();
			
			// Add it to the objects list
			if(mission)
			{
				// Is the player already in a map
				ActiveMissions::iterator it = m_Missions.find(Player);
				if(it != m_Missions.end())
				{
					it->second.push_back(mission);
				}
				else
				{
					Vector<IMission*> list;
					list.push_back(mission);
					m_Missions[Player] = list;
				}

				mission->OnStart();
				
				return true;
			}
		}
	}
	return false;
}

void CMissionManager::ListAllAvailableMissions(Vector<String>& List)
{
	// Collect plugins
	for(u32 i = 0; i < m_PluginManager->GetMissionFactories().size(); i++)
	{
		String str = m_PluginManager->GetMissionFactories()[i]->LabelName;
		List.push_back(str);
	}
}

bool CMissionManager::FindActivePlayerMissions(CPlayer* Player,  Vector<IMission*>& Missions)
{
	return false;
}

void CMissionManager::RegisterEvent(CPlayer* Owner, MISSION_TYPE MissionType, CPlayer* PlayerKilled, CInventoryItem* InventoryItem, CProjectile* Projectile, void* UserData)
{
	// Validate
	if(!Owner)
		return;

	auto missionEvent = new CMissionEvent();
	missionEvent->Killed = PlayerKilled;
	missionEvent->MissionType = MissionType;
	missionEvent->Owner = Owner;
	missionEvent->Projectile = Projectile;
	missionEvent->InventoryItem = InventoryItem;

	m_EventQueue.push_back(missionEvent);
}

void CMissionManager::Update()
{
	// Process the events first
	for(auto it = m_EventQueue.cbegin(); it != m_EventQueue.cend(); it++)
	{
		if(m_Missions.find((*it)->Owner) != m_Missions.end())
		{
			Vector<IMission*> missions = m_Missions[(*it)->Owner];
			for(auto i = missions.begin(); i != missions.end(); i++)
			{
				// Found the player and the mission type, but there could be more missions with the same type
				// so continue to iterate
				if((*i)->CompletionDefinition == (*it)->MissionType)
				{
					(*i)->RegisterEvent((*it));
				}
			}
		}
	}
	m_EventQueue.clear();

	// Update all missions running
	for(auto it = m_Missions.cbegin(); it != m_Missions.cend(); it++)
	{
		Vector<IMission*> missions = (*it).second;
		for(u32 i = 0; i < missions.size(); i++)
		{
			// Remove if its stopped, failed or succeeded
			if(missions[i]->Update() != MS_WORKING)
			{
				//(*it).second.erase(missions.begin() + i);
			}
		}

		//// Remove any missions that are done
		//if(remove.size() > 0)
		//{
		//	for(Vector<IMission*>::const_iterator i = remove.begin(); i != remove.end(); i++)
		//	{
		//		// Remove if its stopped, failed or succeeded
		//		if((*i)->Update() != MS_WORKING)
		//			remove.push_back((*i));
		//	}
		//}
	}
}