#ifndef __CMISSIONMANAGER_H__
#define __CMISSIONMANAGER_H__

#include "Defines.h"

namespace Core
{
	class CPlayer;
	class CProjectile;
	class CPluginManager;
	class CInventoryItem;

namespace Mission
{
	class IMission;
	class CMissionEvent;
	enum MISSION_TYPE;

	class CORE_EXPORT CMissionManager
	{
	public:
		static CMissionManager* Instance();
		~CMissionManager();

		bool StartMission(const char* MissionLabel, CPlayer* Player);
		void ListAllAvailableMissions(Vector<String>& List);			// Returns all misisons loaded into the manager
		bool FindActivePlayerMissions(CPlayer* Player,  Vector<IMission*>& Missions); // Returns player's active missions
		void Update();													// Check the state of all running missions

		// Used to update the status of a mission
		void RegisterEvent(CPlayer* Owner, 
							MISSION_TYPE MissionType, 
							CPlayer* PlayerKilled = nullptr, 
							CInventoryItem* InventoryItem = nullptr, 
							CProjectile* Projectile = nullptr, 
							void* UserData = nullptr);

	private:
		CMissionManager();

		typedef IMission* (*CreateMission_Ptr)(void);
		typedef Map<String, CreateMission_Ptr>	 CreateMissionMap;
		typedef Map<CPlayer*, Vector<IMission*>> ActiveMissions;

		static CMissionManager*	MissionManager;
		Core::CPluginManager*	m_PluginManager;
		ActiveMissions			m_Missions;								// Our currently running missions
		CreateMissionMap		m_AvailableMissions;					// Missions that the game can run
		Vector<CMissionEvent*>  m_EventQueue;							// Events that are registered and still need to be processed by Update()
	};

}
}

#endif // __CMISSIONMANAGER_H__