// This will handle the spawn points, timing, and any other specific logic used in spawning players.
#ifndef __CSPAWNMANAGER__
#define __CSPAWNMANAGER__

#include "Defines.h"

namespace Core
{
	class CPlayer;
	enum E_PLAYER_TEAM;
	struct SPAWN_POINT;

	class CORE_EXPORT CSpawnManager
	{
	protected:
		CSpawnManager();

	public:
		static CSpawnManager* Instance();
		~CSpawnManager();

		u32  AddSpawnPoint(const Vector3& Position, E_PLAYER_TEAM Team, const f32& CoolDown = 0.0f);
		u32  AddSpawnPoint(u32 Id, const Vector3& Position, E_PLAYER_TEAM Team, const f32& CoolDown = 0.0f);

		bool RemoveSpawnPoint(u32 Id);

		Map<u32, SPAWN_POINT*>& GetAllSpawnPoints();
		SPAWN_POINT*			GetSpawnPoint(u32 Id);
		SPAWN_POINT*			GetSpawnPoint(const Vector3& Position, const f32& Threshold = 0.0f);

		bool SpawnPlayer(u32 Id, CPlayer* Player);
		bool SpawnPlayer(const Vector3& Position, const f32& Threshold, CPlayer* Player);
		
	private:
		static CSpawnManager*	SpawnManager;
		Map<u32, SPAWN_POINT*>	m_SpawnPoints;
		u32						m_SpawnPointIndex;
	};

}

#endif // __CSPAWNMANAGER__