#include "CItemsManager.h"
#include "CInventoryItem.h"
#include "CWeaponProfile.h"
#include "CWeapon.h"
#include "CMelee.h"
#include "CItemProfile.h"
#include "IPhysicsStrategy.h"
#include "CGameObject.h"

#include "IO/CoreLogging.h"

#include "OgreSceneNode.h"

using namespace Core;

CItemsManager* CItemsManager::ItemsManager = nullptr;

CItemsManager* CItemsManager::Instance()
{
	if(ItemsManager == nullptr)
		ItemsManager = new CItemsManager();
	return ItemsManager;
}

CItemsManager::CItemsManager()
{
}

CItemsManager::~CItemsManager()
{
	Shutdown();
}

void CItemsManager::Update(const f32& elapsedTime)
{
	// Placed items
	for(auto it = m_ItemsPlaced.cbegin(); it != m_ItemsPlaced.cend(); it++)
	{
		(*it)->Update(elapsedTime);
	}
	
	// Picked up items
	for(auto it = m_ItemsPickedUp.cbegin(); it != m_ItemsPickedUp.cend(); it++)
	{
		(*it)->Update(elapsedTime);
	}
}

void CItemsManager::AddProfile(const CItemProfile& Profile)
{
	// Names must be unique
	if(m_Profiles.find(Profile.Name) == m_Profiles.end())
	{
		auto profile = new CItemProfile(Profile);
		m_Profiles[Profile.Name] = profile;
	}
}

void CItemsManager::AddProfile(const CWeaponProfile& Profile)
{
	// Names must be unique
	if(m_Profiles.find(Profile.Name) == m_Profiles.end())
	{
		auto profile = new CWeaponProfile(Profile);
		m_Profiles[Profile.Name] = profile;
	}
}

bool CItemsManager::PlaceItem(const char* ProfileName, const Vector3& Position, Physics::IPhysicsStrategy* Physics)
{
	if(m_Profiles.find(ProfileName) == m_Profiles.end())
	{
		return false;
	}
	else
	{
		// duplicate the weapon, place it and add it to our list
		if(!m_Profiles[ProfileName])
			return false;

		// Take the profile and create an item from it
		CItemProfile* profile = m_Profiles[ProfileName];
		CInventoryItem* item = CreateItem(profile, Physics);

		if(item)
		{
			if(item->GetGameObject())
			{
				item->GetGameObject()->Node->setPosition(Position);
			}
			m_ItemsPlaced.push_back(item);
			return true;
		}
	}
	return false;
}

void CItemsManager::RemoveItem(CInventoryItem* InventoryItem)
{
	// Search for active items first
	for(auto it = m_ItemsPickedUp.begin(); it != m_ItemsPickedUp.end(); it++)
	{
		if((*it) == InventoryItem)
		{
			auto item = (*it);
			CORE_DELETE(item);
			m_ItemsPickedUp.erase(it);
			return;
		}
	}

	// Search for placed items
	for(auto it = m_ItemsPlaced.begin(); it != m_ItemsPlaced.end(); it++)
	{
		if((*it) == InventoryItem)
		{
			auto item = (*it);
			CORE_DELETE(item);
			m_ItemsPlaced.erase(it);
			return;
		}
	}
}

CInventoryItem* CItemsManager::Pickup(const char* ItemName)
{
	CInventoryItem* item = nullptr;
	for(auto it = m_ItemsPlaced.cbegin(); it != m_ItemsPlaced.cend(); it++)
	{
		if((*it)->Name == ItemName)
		{
			item = (*it);
			
			if(item)
			{
				// Set item visible to false
				if(item->GetGameObject())
				{
					item->GetGameObject()->Node->setVisible(false);
				}
			}
			
			// Remove from the placed items list and disable the physics
			m_ItemsPlaced.erase(it);
			
			// Add to the picked up list
			m_ItemsPickedUp.push_back(item);
			
			break;
		}
	}

	return item;
}

CInventoryItem* CItemsManager::PickupUnplaced(const char* ProfileName)
{
	if(m_Profiles.find(ProfileName) == m_Profiles.end())
	{
		return nullptr;
	}
	else
	{
		// duplicate the weapon, place it and add it to our list
		if(!m_Profiles[ProfileName])
			return nullptr;

		// Take the profile and create an item from it
		CItemProfile* profile = m_Profiles[ProfileName];
		CInventoryItem* item = CreateItem(profile);

		if(item)
		{
			if(item->GetGameObject())
			{
				item->GetGameObject()->Node->setVisible(false);
			}
			m_ItemsPickedUp.push_back(item);
			return item;
		}
	}
			
	return nullptr;
}

void CItemsManager::GetItemProfiles(Vector<CItemProfile*>& List)
{
	for(auto it = m_Profiles.cbegin(); it != m_Profiles.cend(); it++)
	{
		List.push_back((*it).second);
	}
}

CInventoryItem* CItemsManager::CreateItem(CItemProfile* ItemProfile, Physics::IPhysicsStrategy* Physics)
{
	CInventoryItem* inventoryItem = nullptr;
	if(ItemProfile)
	{
		if(ItemProfile->InventoryType == EIT_WEAPON)
		{
			CWeaponProfile* weaponProfile = static_cast<CWeaponProfile*>(ItemProfile);
			inventoryItem = new CWeapon(*weaponProfile, Physics);
		}
		else if(ItemProfile->InventoryType == EIT_MELEE)
		{
			inventoryItem = new CMelee(*ItemProfile, Physics);
		}
		else if(ItemProfile->InventoryType == EIT_TOOL)
		{
			// TODO: add tool support
		}
	}
	return inventoryItem;
}

CItemProfile* CItemsManager::GetItemProfile(const char* ProfileName)
{
	auto it = m_Profiles.find(ProfileName);
	if(it != m_Profiles.end())
	{
		return (*it).second;
	}

	return nullptr;
}

void CItemsManager::GetPlacedItems(std::vector<CInventoryItem*>& List)
{
	// Return the items that are placed on the level, and not in use yet.
	List = m_ItemsPlaced;
}

void CItemsManager::Shutdown()
{
	try
	{
		// Remove profiles
		auto it = m_Profiles.begin();
		while(it != m_Profiles.end())
		{
			auto profile = (*it).second;
			CORE_DELETE(profile);
			it++;
		}

		// Remove picked up items
		for(auto it = m_ItemsPickedUp.begin(); it != m_ItemsPickedUp.end(); it++)
			CORE_DELETE((*it));

		// Remove placed items
		for(auto it = m_ItemsPlaced.begin(); it != m_ItemsPlaced.end(); it++)
			CORE_DELETE((*it));

		m_Profiles.clear();
		m_ItemsPickedUp.clear();
		m_ItemsPlaced.clear();
	}
	catch(std::exception& e)
	{
		CORE_ASSERT(false);
		throw(e);
	}
	catch(...)
	{
		throw("Error in CItemManger::Shutdown()");
	}
}
