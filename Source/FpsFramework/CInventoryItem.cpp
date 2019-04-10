#include "CInventoryItem.h"
#include "CGameManager.h"
#include "IPhysicsStrategy.h"
#include "CPhysicsProfile.h"
#include "PhysicsStructures.h"
#include "CGameObject.h"
#include "CGameObjectManager.h"
#include "IO/CoreLogging.h"

#include "OgreStringConverter.h"
#include "OgreOverlay.h"
#include "OgreOverlayManager.h"
#include "OgreSceneManager.h"
#include "OgreEntity.h"

using namespace Core;

u32 CInventoryItem::InventoryNum = 0;

CInventoryItem::CInventoryItem(const CItemProfile& Profile, Physics::IPhysicsStrategy* Physics) 
	: m_Profile(Profile), 
	m_Ceo(nullptr),
	m_GameObject(nullptr), 
	m_Sight(nullptr),
	m_Player(nullptr),
	m_Physics(Physics), 
	Power(0.0f),
	m_CoolDown(0.0f),
	isUsed(false)
{ 
	// Get scene manager
	SceneManager* sm = CGameManager::Instance()->GetSceneManager();

	Name = m_Profile.Name;
	Desc = m_Profile.Desc;
	Power = m_Profile.Power;

	// Setup Mesh (Optional)
	if(m_Profile.MeshName.length() > 0)
	{
		auto entity = sm->createEntity(StringConverter::toString(InventoryNum), m_Profile.MeshName);
		entity->setCastShadows(false);
		entity->setQueryFlags(SQF_INVENTORY_ITEM);

		// Setup node
		auto node = sm->getRootSceneNode()->createChildSceneNode(Name + StringConverter::toString(InventoryNum), Vector3::ZERO);
		node->attachObject(entity);
		node->scale(m_Profile.Scale);

		m_GameObject = new CDummyGameObject(Name.c_str(), node, entity);

		// Add collision if we have physics
		if(m_Physics && m_GameObject)
		{
			m_GameObject->PhysicsProfile = new Physics::CPhysicsProfile();
			m_GameObject->PhysicsProfile->SetMass(1.0f);
			m_GameObject->PhysicsProfile->SetDensity(0.1f);
			m_GameObject->PhysicsProfile->SetShape(Physics::SHAPE_CUBE);
			m_Physics->AddShape(m_GameObject);
		}

		//// Setup our core entity data and attach
		//m_Ceo = new CoreEntityObject();
		//m_Ceo->Item = this;
		//m_Ceo->QueryType = SQF_INVENTORY_ITEM;
		//entity->setUserAny(Any(m_Ceo));
	}

	// Do we have a sight
	if(m_Profile.OverlayName.length() > 0)
	{
		m_Sight = (Overlay*)OverlayManager::getSingleton().getByName(m_Profile.OverlayName); 
		if(m_Sight)
		{
			m_Sight->hide();
		}
		else
		{
			String msg = "Error loading profile overlay: " + String(m_Profile.OverlayName);
			CORE_ERR(msg.c_str());
		}
	}

	InventoryNum++;
}

CInventoryItem::~CInventoryItem()
{
	CORE_DELETE(m_Ceo);
	CORE_DELETE(m_GameObject);
	CORE_DELETE(m_Sight);
}

void CInventoryItem::PickedUp(CPlayer* Player)
{
	m_Player = Player;
	
	// Remove physics if we have it
	if(m_Physics && m_GameObject)
	{
		m_Physics->DestroyPhysicsBody(m_GameObject);
	}
}

void CInventoryItem::ShowSight(bool Show)
{
	if(m_Sight)
	{
		if(Show)
			m_Sight->show();
		else
			m_Sight->hide();
	}
}

f32 CInventoryItem::GetRange()
{
	return m_Profile.Range;
}

CGameObject* CInventoryItem::GetGameObject() 
{ 
	return m_GameObject;
}

INVENTORY_TYPE CInventoryItem::GetType() 
{ 
	return m_Profile.InventoryType;
}
