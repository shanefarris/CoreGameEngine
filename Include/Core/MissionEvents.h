#ifndef __MISSION_EVENTS_H__
#define __MISSION_EVENTS_H__

namespace Core
{
	class CPlayer;
	class CInventoryItem;
	class CProjectile;

namespace Mission
{
	enum MISSION_TYPE;

	// Standard mission/achievement event
	class CMissionEvent
	{
	public:
		CMissionEvent() : Owner(nullptr), Killed(nullptr), InventoryItem(nullptr), Projectile(nullptr), UserData(nullptr) { }
		CPlayer*		Owner;
		CPlayer*		Killed;
		CInventoryItem*	InventoryItem;
		CProjectile*	Projectile;
		void*			UserData;

		MISSION_TYPE	MissionType;
	};

}
}

#endif // __MISSION_EVENTS_H__