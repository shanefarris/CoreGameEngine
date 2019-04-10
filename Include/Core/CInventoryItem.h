#ifndef __CINVENTORYITEM_H__
#define __CINVENTORYITEM_H__

#include "Defines.h"
#include "CoreStructures.h"
#include "CItemProfile.h"

namespace Ogre
{
	class Overlay;
}

namespace Core
{
	class CPlayer;
	class CGameObject;
	struct SoundToAnimation;
	enum E_ANIM_STATE;

	namespace Physics
	{
		class IPhysicsStrategy;
	}

	// Reports the last result of the use of the item, the item could have multiple results, this just stores the latest result.
	enum E_ITEM_USE_RESULT
	{
		EIUR_HIT_PLAYER,
		EIUR_HIT_GAMEOBJECT,
		EIUR_MISS,
		EIUR_NONE
	};
	
	class CORE_EXPORT CInventoryItem
	{
	public:
		CInventoryItem(const CItemProfile& Profile, Physics::IPhysicsStrategy* Physics = nullptr);
		virtual ~CInventoryItem();
		
		virtual void Update(const f32& elapsedTime) = 0;	// Called every frame by the items manager
		virtual bool Use(const Vector3& Target) = 0;		// Use the item, true if all is successful

		void			PickedUp(CPlayer* Player);			// When a player picks the item up
		void			ShowSight(bool Show);				// Show the sight for the item if there is a sight
		f32				GetRange();
		CGameObject*	GetGameObject();
		INVENTORY_TYPE	GetType();

		String			  Name;								// Internal name
		String			  Desc;								// Descriptional name
		f32				  Power;							// Power (Damage) of the tool
		E_ITEM_USE_RESULT UseResult;						// What happened after we used the item

	protected:
		CPlayer*			m_Player;						// If this is a copy of a profile, then it might have a player that owns it
		f32					m_CoolDown;						// Used to dff from last time used
		CItemProfile		m_Profile;						// Profile this item relates to
		bool				isUsed;							// Is this tool in the hands for someone
		CGameObject*		m_GameObject;					// Used to encompass the node and entity and id during scene queries

	private:
		CoreEntityObject*	m_Ceo;							// Object we attach to the entity
		Overlay*			m_Sight;						// Used for the sight (if any)
		static u32			InventoryNum;					// Index of item number
		Physics::IPhysicsStrategy*	m_Physics;
	};
}

#endif // __CINVENTORYITEM_H__