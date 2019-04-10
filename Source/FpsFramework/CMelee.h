// An weapon with no projectiles, no magazines.
#ifndef __CMELEE_H__
#define __CMELEE_H__

#include "Defines.h"
#include "CItemProfile.h"
#include "CInventoryItem.h"

namespace Ogre
{
	class RaySceneQuery;
}

namespace Core
{
	class CPlayer;
	class CToolProfile;

	class CORE_EXPORT CMelee : public CInventoryItem
	{
	public:
		CMelee(const CItemProfile& Profile, Physics::IPhysicsStrategy* Physics = nullptr);
		~CMelee();

		void Update(const f32& elapsedTime);
		bool Use(const Vector3& Target);
		
	private:
		RaySceneQuery*	m_RaySceneQuery;
	};
}

#endif // __CMELEE_H__