#include "CMagazine.h"
#include "CProjectile.h"

using namespace Core;

CMagazine::CMagazine(const CMagazineProfile& Profile, CWeapon* Weapon) 
	: m_Node(nullptr), 
	m_Entity(nullptr), 
	m_Weapon(Weapon),
	m_Profile(Profile)
{
	m_Count = Profile.Capacity;	// TODO: make dynamic (could pick up on the field and half of the rounds were spent)
}

CMagazine::~CMagazine()
{
	for(auto it = m_Projectiles.begin(); it != m_Projectiles.end(); it++)
		CORE_DELETE((*it));
	m_Projectiles.erase(m_Projectiles.begin(), m_Projectiles.end());
}

bool CMagazine::Fire(CPlayer* Player, const Vector3& Direction)
{
	if(m_Count > 0)
	{
		//m_Count--;
		CProjectile* projectile = new CProjectile(m_Profile.ProjectileProfile, m_Weapon);
		projectile->Shoot(Player, Direction);
		m_Projectiles.push_back(projectile);
		return true;
	}
	return false;
}

void CMagazine::RemoveProjectile(CProjectile* Projectile)
{
	auto it = find(m_Projectiles.cbegin(), m_Projectiles.cend(), Projectile);
	if(it != m_Projectiles.cend())
	{
		m_Projectiles.erase(it);
		CORE_DELETE(Projectile);
	}
}

Vector<CProjectile*>& CMagazine::GetProjectiles()
{
	return m_Projectiles;
}
