#ifndef __CWEAPON_PROFILE_H__
#define __CWEAPON_PROFILE_H__

#include "Defines.h"
#include "CItemProfile.h"

namespace Core
{
	class CORE_EXPORT CProjectileProfile : public CItemProfile
	{
	public:
		CProjectileProfile();
		~CProjectileProfile();
		
		f32		Damage;				// Amount of damage
		f32		Speed;
		String	BillboardBullet;	// If we use a billboard, this is the bullet
		String	BillboardFlash;		// If we use a billboard, this is the flash from the muzzle
		bool	isPenetrate;		// Not used yet
	};

	class CORE_EXPORT CMagazineProfile : public CItemProfile
	{
	public:
		CMagazineProfile();
		~CMagazineProfile();
		
		u32	Capacity;				// Max Amount of projectiles
		
		// Stored profile of the protiles it holds
		CProjectileProfile ProjectileProfile;	
		
	};
	
	class CORE_EXPORT CWeaponProfile : public CItemProfile
	{
	public:
		CWeaponProfile();
		~CWeaponProfile();
		
		bool		isSemi;			// Semi-auto
		bool		isBurst;		// Burst rounds
		bool		isAuto;			// Automatic
		f32			Accuracy;
		
		// Stored profile of the protiles it holds
		CMagazineProfile MagazineProfile;	
		
	};
}

#endif // __CWEAPON_PROFILE_H__