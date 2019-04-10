#include "CWeaponProfile.h"

using namespace Core;

CProjectileProfile::CProjectileProfile() : CItemProfile(EIT_PROJECTILE), Damage(0.0f), Speed(64.0f)
{
}

CProjectileProfile::~CProjectileProfile()
{
}

CMagazineProfile::CMagazineProfile() : CItemProfile(EIT_MAGAZINE), Capacity(0)
{
}

CMagazineProfile::~CMagazineProfile()
{
}

CWeaponProfile::CWeaponProfile() : CItemProfile(EIT_WEAPON), Accuracy(0)
{
}

CWeaponProfile::~CWeaponProfile()
{
}