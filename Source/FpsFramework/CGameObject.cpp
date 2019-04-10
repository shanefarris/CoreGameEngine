#include "CGameObject.h"
#include "IBehavior.h"
#include "CGameManager.h"
#include "CGameObjectManager.h"
#include "CPhysicsProfile.h"
#include "CPhysicsManager.h"
#include "IPhysicsStrategy.h"
#include "AnimationMapping.h"
#include "CoreStructures.h"

#include "OgreEntity.h"
#include "OgreSceneNode.h"
#include "OgreSceneManager.h"

using namespace Core;

CGameObject::CGameObject(const char* Name, CGameObject* Parent) 
	: PhysicsProfile(nullptr), 
	Entity(nullptr), 
	Node(nullptr), 
	AttachedData(nullptr),
	m_AnimationState(nullptr),
	isEnabled(true),
	m_Parent(Parent),
	m_LoadType(ELT_INSTANCE)
{
	this->Name = Name;
	EnvironmentType = EAT_NONE;

	// Set default animation state
	m_CurrAnimState = EAS_NONE;
	m_AnimState = EAS_NONE;
	isAnimationDirty = false;
}

CGameObject::~CGameObject()
{
	try
	{
		if(Node)
			CGameManager::Instance()->GetSceneManager()->destroySceneNode(Node->getName());
		if(Entity)
			CGameManager::Instance()->GetSceneManager()->destroyEntity(Entity->getName());
	}
	catch(std::exception& e)
	{
		throw(e);
	}
	catch(...)
	{
		throw("Error in ~CGameObject()");
	}
}

void CGameObject::SetIsUpdatable(bool Value)
{
	CGameObjectManager::Instance()->SetGameObjectUpdatable(this, Value);
}

void CGameObject::SetPosition(const Vector3& Position)
{
	if(PhysicsProfile)
	{
		auto physics = Physics::CPhysicsManager::Instance()->GetStrategy();
		if(physics)
		{
			physics->SetPosition(this, Position);
		}
	}
	if(Node)
	{
		Node->setPosition(Position);
	}
}

void CGameObject::SetAnimationState(E_ANIM_STATE State) 
{ 
	m_AnimState = State; 
	isAnimationDirty = true;
}

void CGameObject::SetAnimationMappings(const Map<E_ANIM_STATE, SoundToAnimation*>& AnimationMaps, bool Loop)
{
	m_AnimationMaps = AnimationMaps;
	isLoop = Loop;
}

void CGameObject::AttachChild(CGameObject* Child, const Quaternion& Rotation, const Vector3& OffsetPosition)
{
	m_Children.push_back(Child);
	//Entity->attachObjectToBone;
}

void CGameObject::DetachChild(CGameObject* Child)
{
	m_Children.erase(
		std::remove(m_Children.begin(), m_Children.end(), Child), 
		m_Children.end());
}

void CGameObject::SetEnabled(bool IsEnabled)
{
	isEnabled = IsEnabled;
	if(Entity)
	{
		Entity->setVisible(isEnabled);
	}

	// Physics update
	auto physics = Physics::CPhysicsManager::Instance()->GetStrategy();
	if(physics)
	{
		physics->SetEnabled(this, isEnabled);
	}

	// Children update
	for(auto child : m_Children)
			child->SetEnabled(isEnabled);
}

void CGameObject::Reset()
{
}

void CGameObject::Update(const f32& elapsedTime)
{
	if(isEnabled)
	{
		if(isAnimationDirty)
		{
			UpdateAnimation(elapsedTime);
		}
	}
}

void CGameObject::UpdateAnimation(const f32& elapsedTime)
{
	// Has the animation state changed
	if(m_CurrAnimState != m_AnimState)
	{
		// Stop the current state
		if(m_AnimationState)
			m_AnimationState->setEnabled(false);

		auto it = m_AnimationMaps.find(m_AnimState);
		if(it != m_AnimationMaps.end())
		{
			if(it->second)
			{
				m_AnimationState = Entity->getAnimationState(it->second->Animation);
				m_AnimationState->setLoop(isLoop);
			}
		}

		m_CurrAnimState = m_AnimState;
	}
	else
	{
		// Update animation
		if(m_AnimationState)
		{
			Entity->getAnimationState(m_AnimationState->getAnimationName())->addTime(elapsedTime);
		}
	}

	isAnimationDirty = false;
}

CDummyGameObject::CDummyGameObject() : CGameObject("")
{ 
	GameObjectType = "DUMMY";
	m_LoadType = ELT_NONE;
}

CDummyGameObject::CDummyGameObject(const char* Name, SceneNode* n, Ogre::Entity* e) : CGameObject(Name)
{ 
	this->Entity = e; 
	this->Node = n;
	GameObjectType = "DUMMY";
	m_LoadType = ELT_NONE;
}
