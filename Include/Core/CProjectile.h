// Used as bullets, rocks, missles, anything that can go through the air
#ifndef __CPROJECTILE_H__
#define __CPROJECTILE_H__

#include "Defines.h"
#include "CWeaponProfile.h"

#include "OgreVector3.h"

namespace Core
{
	class CPlayer;
	class CWeapon;
	class CProjectileProfile;
	struct SItemUseReport;
	enum PROJECTILE_TYPE;
	
	namespace Physics
	{
		class CPhysicsProfile;
		class IPhysicsStrategy;
	}

	class CProjectile
	{
	public:
		CProjectile(const CProjectileProfile& Profile, CWeapon* Weapon, bool IsVisible = true, bool UsePhysics = true);
		~CProjectile();

		bool Shoot(CPlayer* Player, const Vector3& Direction);	// Returns true is all parameters are valid
		void Update(const f32& elapsedTime);
		
		f32			GetDamage();
		CPlayer*	GetOwner() { return Owner; }
		CWeapon*	GetWeapon() { return m_Weapon; }
		Vector3*	GetPosition() { return &Position; }
		Vector3*	GetDirection() { return &Direction; }

		bool		isAlive;		// Do we need to kill this projectile.
		
	private:
		CProjectileProfile			m_Profile;
		Physics::IPhysicsStrategy*	m_Physics;
		CWeapon*					m_Weapon;
		
		CPlayer*	Owner;
		Vector3		Start;
		Vector3		Position;
		Vector3		Direction;
		bool		isVisible;		// Is the projectile visible
		s32			BillboardId;	// Id if the bb is used
		bool		m_UsePhysics;

	};
}

#endif // __CPROJECTILES_H__