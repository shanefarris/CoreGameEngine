#include "CProjectile.h"
#include "IPhysicsStrategy.h"
#include "PhysicsStructures.h"
#include "CPlayer.h"
#include "CWeapon.h"
#include "CBillboardManager.h"
#include "CPhysicsProfile.h"

#include "CGameManager.h"
#include "CUtility.h"
#include "OgreStringConverter.h"
#include "OgreResourceManager.h"
#include "OgreMaterialManager.h"
#include "OgreSceneManager.h"
#include "OgreManualObject.h"
#include "OgreSceneQuery.h"

using namespace Core;

#undef DEBUG_PROJECTILE
#if DEBUG_PROJECTILE
u32 counter = 0;
#endif

CProjectile::CProjectile(const CProjectileProfile& Profile, CWeapon* Weapon, bool IsVisible, bool UsePhysics) 
	: m_Profile(Profile), 
	m_Weapon(Weapon),
	isVisible(IsVisible),
	BillboardId(-1),
	m_UsePhysics(UsePhysics)
{
}

CProjectile::~CProjectile()
{
}

bool CProjectile::Shoot(CPlayer* Player, const Vector3& _Direction)
{
	if(Player)
		Owner = Player;
	else
		return false;
	
	if(Player->GetPhysicsStrategy())
		m_Physics = Player->GetPhysicsStrategy();
	else
		return false;
		
	Direction = _Direction.normalisedCopy();
	isAlive = true;
	Start = Player->GetEyePosition();
	Position = Start;

	// TODO: make this data driven
	isVisible = !Player->GetIsHumanPlayer();
	
	if(m_Profile.BillboardBullet.size() > 0 && isVisible)
		BillboardId = CBillboardManager::Instance()->ShowBillboard(m_Profile.BillboardBullet.c_str(), Start, 10.0f);
		
	return true;
}

void CProjectile::Update(const f32& elapsedTime)
{	
	if(!isAlive)
		return;

	//check if it will hit somthing
	Physics::SPhysicsRayCastReport Report;
	Vector3 toAdd = Direction * m_Profile.Speed * elapsedTime;
	Vector3 hitPos(INVALID_POS);

	if(m_UsePhysics)
		hitPos = m_Physics->RaycastClosestShape(Position, Position + toAdd, Report);
	else
	{
		// Pick middle of the screen
		Ray pickRay(Position, Position + toAdd);
		auto query = CGameManager::Instance()->GetSceneManager()->createRayQuery(Ray());
		query->setRay(pickRay);
 
		auto result = query->execute();
		if (!result.empty())
		{
			auto it = result.begin();
			while((it != result.end()))
			{
				if(it->movable != nullptr && it->movable->getQueryFlags() == SQF_PLAYER )
				{
					// This will not work unless all game objects and players have a CEO attached.
				}
				++it;
			}
		}
	}
	
#if DEBUG_PROJECTILE
	auto gm = CGameManager::Instance();
	auto sm = gm->GetSceneManager();
	auto myManualObject =  sm->createManualObject("obj_" + StringConverter::toString(counter)); 
	auto myManualObjectNode = sm->getRootSceneNode()->createChildSceneNode("node_" + StringConverter::toString(counter)); 
	auto Color = ColourValue::White;
	auto matName = "mat" + StringConverter::toString(counter);

	MaterialPtr mat = MaterialManager::getSingleton().create(matName, ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME); 
	mat->setReceiveShadows(false); 
	mat->getTechnique(0)->setLightingEnabled(true); 
	mat->getTechnique(0)->getPass(0)->setDiffuse(Color); 
	mat->getTechnique(0)->getPass(0)->setAmbient(Color); 
	mat->getTechnique(0)->getPass(0)->setSelfIllumination(Color); 
	//mat->dispose();  // dispose pointer, not the material
			 
	myManualObject->begin(mat->getName(), RenderOperation::OT_LINE_LIST); 
	myManualObject->position(Position); 
	myManualObject->position(Position + toAdd); 
	// etc 
	myManualObject->end(); 
			 
	myManualObjectNode->attachObject(myManualObject);
	counter++;
#endif

	// Fix: hitting the owners collision shape
	if (hitPos == INVALID_POS || Report.Data == Owner)
	{
		// Update position
		Position += toAdd;

		// Are we using a billboard to show the projectile
		if(BillboardId >=0)
		{
			// Show source
			if (isVisible)
			{
				CBillboardManager::Instance()->ShowBillboard(m_Profile.BillboardFlash.c_str(), Start, 1.0f);
			}
			CBillboardManager::Instance()->UpdateBillboard(m_Profile.BillboardBullet.c_str(), BillboardId, Position);
			
			if (Position.distance(Start) > m_Weapon->GetRange())
			{
				isAlive = false;
				CBillboardManager::Instance()->HideBillboard(m_Profile.BillboardBullet.c_str(), BillboardId);
				m_Weapon->UseResult = EIUR_MISS;
			}
		}
	}
	else if(Report.Data)
	{
		// Hide bullet
		if(BillboardId >= 0)
		{
			CBillboardManager::Instance()->HideBillboard(m_Profile.BillboardBullet.c_str(), BillboardId);
		}

		if(Report.BodyType == Physics::PLAYER)
		{
			m_Weapon->UseResult = EIUR_HIT_PLAYER;
			static_cast<CPlayer*>(Report.Data)->OnHit(this, Direction);
		}
		else if(Report.BodyType == Physics::GAME_OBJECT)
		{
			m_Weapon->UseResult = EIUR_HIT_GAMEOBJECT;
		}
			
		isAlive = false;
	}
	else if(Report.BodyType == Physics::TERRAIN)
	{
		isAlive = false;

		// Hide bullet
		if(BillboardId >= 0)
		{
			CBillboardManager::Instance()->HideBillboard(m_Profile.BillboardBullet.c_str(), BillboardId);
		}
		m_Weapon->UseResult = EIUR_MISS;
	}
	
}

f32 CProjectile::GetDamage()
{
	return m_Profile.Damage;
}