#include "CWeapon.h"
#include "CMagazine.h"
#include "CPlayer.h"
#include "CWeaponProfile.h"
#include "CItemProfile.h"
#include "CProjectile.h"
#include "CGameObject.h"
#include "AnimationMapping.h"

using namespace Core;
using namespace Core::Physics;

CWeapon::CWeapon(const CWeaponProfile& Profile, Physics::IPhysicsStrategy* Physics) 
	: CInventoryItem((const CItemProfile&)Profile, Physics),
	m_Mag(nullptr)
{	
	Power = Profile.Power;
	m_Mag = new CMagazine(Profile.MagazineProfile, this);
}

CWeapon::~CWeapon()
{
	CORE_DELETE(m_Mag);
}

bool CWeapon::Use(const Vector3& Target)
{
	if(m_Player && m_Mag)
	{
		if(m_CoolDown <= 0.0f)
		{
			if(m_Mag->Fire(m_Player, Target))
			{
				// Update animation state
				m_GameObject->SetAnimationState(EAS_SHOOT);

				// Cooldown time
				m_CoolDown = m_Profile.UseTime;
				return true;
			}
		}
	}
	return false;
}

void CWeapon::Update(const f32& elapsedTime)
{
	if(m_Mag)
	{
		auto projectiles = m_Mag->GetProjectiles();
		for(auto it = projectiles.cbegin(); it != projectiles.cend(); it++)
		{
			if((*it)->isAlive)
				(*it)->Update(elapsedTime);
			else
				m_Mag->RemoveProjectile((*it));
		}
	}
	
	// Update our shot time
	m_CoolDown -= elapsedTime;
}

void CWeapon::ShowSight(bool Show)
{
	// TODO
}