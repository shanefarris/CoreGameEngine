// Used to collect CProjectiles and keep track of how many are left in our container
#ifndef __CMAGAZINE_H__
#define __CMAGAZINE_H__

#include "Defines.h"
#include "CWeaponProfile.h"

namespace Core
{
	class CPlayer;
	class CWeapon;
	class CProjectile;
	
	class CMagazine
	{		
	public:
		CMagazine(const CMagazineProfile& Profile, CWeapon* Weapon);
		~CMagazine();
		
		bool Fire(CPlayer* Player, const Vector3& Direction);
		void RemoveProjectile(CProjectile* Projectile);	// Kills the projectile and erases it from the list
		Vector<CProjectile*>& GetProjectiles();			// Get active projectiles (not ones not used yet)
		
	protected:
		Vector<CProjectile*>	m_Projectiles;			// List of active projectiles
		SceneNode*				m_Node;
		Entity*					m_Entity;
		CMagazineProfile		m_Profile;
		u32						m_Count;				// Current projectiles still in the mag
		CWeapon*				m_Weapon;
	};
}

#endif // __CMAGAZINE_H__