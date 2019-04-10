// A projectile weapon that uses a magazine, and shoots a projectile
#ifndef __CWEAPON_H__
#define __CWEAPON_H__

#include "Defines.h"
#include "CInventoryItem.h"

namespace Core
{
	class CPlayer;
	class CItemProfile;
	class CMagazine;
	class CWeaponProfile;
	class CMagazineProfile;

	class CORE_EXPORT CWeapon : public CInventoryItem
	{
	public:
		CWeapon(const CWeaponProfile& Profile, Physics::IPhysicsStrategy* Physics = nullptr);
		~CWeapon();

		void		Update(const f32& elapsedTime);
		void		ShowSight(bool Show);
		void		SetUsed(bool Used) { isUsed = Used; }
		bool		Use(const Vector3& Target);		// Fire the weapon

		CMagazine*	GetMagazine() { return m_Mag; }
		void		SetMagazine(CMagazine* m) { m_Mag = m; }

	protected:
		CMagazine*	m_Mag;			// Only one type of mag for now
	};
}

#endif // __CWEAPON_H__