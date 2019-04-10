// Will load all weapons data that needs to be loaded, collect, and manage.  Same applies to mags, and projectiles

#ifndef __CITEMSMANAGER_H__
#define __CITEMSMANAGER_H__

#include "Defines.h"

namespace Core
{
	class CItemProfile;
	class CWeaponProfile;
	class CInventoryItem;
	
	namespace Physics
	{
		class IPhysicsStrategy;
	}

	class CORE_EXPORT CItemsManager
	{
	public:
		static CItemsManager* Instance();
		
		~CItemsManager();

		void Update(const f32& elapsedTime);
		void GetItemProfiles(Vector<CItemProfile*>& List);			// Returns all the loaded profiles
		CItemProfile* GetItemProfile(const char* ProfileName);		// Gets a single profile by the profile name
		void GetPlacedItems(Vector<CInventoryItem*>& List);

		CInventoryItem* Pickup(const char* ItemName);				// When we pick an item up, item name is unique
		CInventoryItem* PickupUnplaced(const char* ProfileName);	// Picking up an item that hasn't been placed on the level (usually for level loading)
		
		// Put a copy of the profile on the level, ready for pickup
		bool PlaceItem(const char* ProfileName, const Vector3& Position, Physics::IPhysicsStrategy* Physics = nullptr); 

		// Removes the item from the world, either pickedup, or placed
		void RemoveItem(CInventoryItem* InventoryItem);

		// Adds a profile to the profiles list (unique)
		void AddProfile(const CItemProfile& Profile);
		void AddProfile(const CWeaponProfile& Profile);

		void Shutdown();											// Remove all inventory

	private:
		CItemsManager();

		CInventoryItem* CreateItem(CItemProfile* ItemProfile, Physics::IPhysicsStrategy* Physics = nullptr);

		static CItemsManager*	ItemsManager;

		Map<String, CItemProfile*>		m_Profiles;					// More like a profile of what weapons are loaded
		Vector<CInventoryItem*>			m_ItemsPlaced;				// List of items placed and active on the level
		Vector<CInventoryItem*>			m_ItemsPickedUp;			// List of items that are picked up and in a players inventory
	};
}
#endif // __CITEMSMANAGER_H__
