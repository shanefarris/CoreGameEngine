#include "CBuildingVillage_church.h"
#include "CGameManager.h"
#include "CGameObject.h"
#include "IPhysicsStrategy.h"
#include "CPhysicsManager.h"
#include "CPhysicsProfile.h"
#include "CPlayerSoundComponent.h"
#include "AnimationMapping.h"

#include "OgreEntity.h"
#include "OgreSceneNode.h"
#include "OgreSceneManager.h"
#include "OgreAnimationState.h"

using namespace Core;
using namespace Core::Plugin;

CBuildingVillage_church::CBuildingVillage_church(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy) : CBuilding(Name, PhysicsStrategy)
{
	m_MeshName = "village_church.mesh";
	auto sceneManager = CGameManager::Instance()->GetSceneManager();

	m_BuildingNode = sceneManager->getRootSceneNode()->createChildSceneNode(Name);
	m_BuildingEntity = sceneManager->createEntity(Name, m_MeshName);
	m_BuildingEntity->setQueryFlags(SQF_BUILDING);
	m_BuildingNode->attachObject(m_BuildingEntity);
	m_BuildingNode->setPosition(0, 0, 0);

	// ====== Set the building type ========
	m_BuildingType = "VILLAGE_CHURCH";
	// ===================================

	// ====== Set the category ===========
	m_BuildingCategory = EBC_SUPPLY;
	// ===================================

	// ====== Setup default physics ======
	if(PhysicsStrategy && m_BuildingNode && m_BuildingEntity)
	{
		auto profile = Physics::CPhysicsManager::Instance()->GetPhysicsProfile("DEFAULT_LIGHT_CUBE");
		if(profile)
		{
			auto boundingBox = m_BuildingEntity->getBoundingBox();
			auto height = boundingBox.getMaximum().y / 2;
			profile->SetPositionOffset(Vector3(0, height, 0));
			String objName = String(Name) + "_obj";
			auto gameObject = new CDummyGameObject(objName.c_str(), m_BuildingNode, m_BuildingEntity);
			if(gameObject)
			{
				m_GameObjects.push_back(gameObject);
				gameObject->PhysicsProfile = profile;
				PhysicsStrategy->AddShape(gameObject);
			}
		}
	}
	// ===================================

	PostInit();
}

CBuildingVillage_church::~CBuildingVillage_church()
{
}

void CBuildingVillage_church::SetupMapping()
{
}

void CBuildingVillage_church::Update(const f32& elapsedTime)
{
}

// CBuildingVillage_churchFactory
CBuildingVillage_churchFactory::CBuildingVillage_churchFactory()
{
	BuildingType = "VILLAGE_CHURCH";
}

CBuildingVillage_churchFactory::~CBuildingVillage_churchFactory()
{
}

Core::CBuilding* CBuildingVillage_churchFactory::CreateBuilding(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy)
{
	return new CBuildingVillage_church(Name, PhysicsStrategy);
}