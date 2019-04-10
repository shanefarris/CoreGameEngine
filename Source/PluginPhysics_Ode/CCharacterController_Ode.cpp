#include "CCharacterController_Ode.h"
#include "CPhysicsStrategy_Ode.h"
#include "CPhysicsManager.h"
#include "CGameObject.h"
#include "CPlayer.h"
#include "CPhysicsProfile.h"
#include "Wrapper/Space.h"
#include "Wrapper/Body.h"
#include "Wrapper/Mass.h"
#include "Wrapper/Geometry.h"

#include "OgreEntity.h"
#include "OgreSceneNode.h"
#include "OgreAxisAlignedBox.h"

using namespace Core;
using namespace Core::Physics;

CCharacterController_Ode::CCharacterController_Ode(CPlayer* Player, Ode::Space* Space)
	: m_Player(Player),
	m_Space(Space),
	m_Body(0),
	m_FeetBody(0),
	m_TorsoBody(0),
	m_TorsoGeom(0),
	m_TorsoTrans(0)
{
	m_Physics = static_cast<CPhysicsStrategy_Ode*>(CPhysicsManager::Instance()->GetStrategy());
}

CCharacterController_Ode::~CCharacterController_Ode()
{
	CORE_DELETE(m_TorsoGeom);
	CORE_DELETE(m_TorsoTrans);
	CORE_DELETE(m_TorsoBody);
}

bool CCharacterController_Ode::InitCharacterControllers()
{
	// Getting AABB
	Vector3 size;
	if(m_Player->GetCharacterControllerSize() == DEFAULT_PROFILE_SIZE)
	{
		AxisAlignedBox aab = m_Player->GetPlayerEntity()->getBoundingBox(); 
		Vector3 min = aab.getMinimum() * m_Player->GetPlayerNode()->getScale();
		Vector3 max = aab.getMaximum() * m_Player->GetPlayerNode()->getScale();
		Vector3 center = aab.getCenter() * m_Player->GetPlayerNode()->getScale();
		size = Vector3(fabs(max.x - min.x), fabs(max.y - min.y), fabs(max.z - min.z));
	}
	else
	{
		size = m_Player->GetCharacterControllerSize();
	}

	return InitCharacterControllers(size);
}

bool CCharacterController_Ode::InitCharacterControllers(const Vector3& Size)
{
	float radius = (Size.x > Size.z) ? Size.z : Size.x;
	radius += radius * 0.4f;

	// Create a new space
	//auto dollSpace = new Ode::SimpleSpace(m_Space->getWorld(), m_Space->getWorld()->getDefaultSpace());
	//dollSpace->setInternalCollisions(false);

	// Create the Capsule (torso)
	m_TorsoBody = new Ode::Body(m_Space->getWorld(), String(m_Player->GetName()) + "torso"); 
	m_TorsoBody->setMass(Ode::CapsuleMass(70.0f * 2.5f, radius, Vector3::UNIT_Y, radius)); 
	m_TorsoBody->setAffectedByGravity(true);
	m_TorsoBody->setAngularVelocity(Vector3::ZERO);
	m_TorsoBody->setMaxAngularSpeed(0.0f);

	m_TorsoTrans = new Ode::TransformGeometry(m_Space->getWorld(), m_Space); 
	m_TorsoGeom = new Ode::CapsuleGeometry(radius, Size.y - (Size.y * 0.5f), m_Space->getWorld(), nullptr); 
	m_TorsoGeom->setPosition(Vector3(0, Size.y / 2, 0));
	m_TorsoGeom->setOrientation(Quaternion(Degree(90), Vector3::UNIT_X));
	m_TorsoGeom->SetBodyType(PLAYER);
	m_TorsoTrans->setBody(m_TorsoBody); 
	m_TorsoTrans->SetBodyType(PLAYER);
	m_TorsoTrans->setEncapsulatedGeometry(m_TorsoGeom);
	m_TorsoTrans->SetCustomData(m_Player);

	auto modelNode = m_Player->GetPlayerNode()->createChildSceneNode(String(m_Player->GetName()) + "_cc_node");
	modelNode->translate(Vector3(0, -radius / m_Player->GetPlayerNode()->getScale().y, 0));
	modelNode->attachObject(m_TorsoBody);

	return true;
}

void CCharacterController_Ode::UpdateControllers()
{
}

u32 CCharacterController_Ode::MoveCharacter(const Vector3& dispVector, f32 elapsedTime, u32 collisionGroups, f32 heightDelta)
{
	//if(m_TorsoBody)
	//{
	//	Vector3 d = dispVector * elapsedTime;
	//	if(heightDelta != 0.0f)
	//		d.y += heightDelta;

	//	m_TorsoBody->sleep();
	//	m_TorsoBody->setPosition(d);
	//	m_TorsoBody->wake();
	//}
	return 0;
}

Vector3 CCharacterController_Ode::GetCharacterPos()
{
	if(m_Player)
		return m_Player->GetPlayerNode()->getPosition();
	return INVALID_POS;
}

void CCharacterController_Ode::SetCharacterPos(const Vector3& pos)
{
	if(m_TorsoBody)
	{
		m_TorsoBody->sleep();
		m_TorsoBody->setPosition(pos);
		m_TorsoBody->wake();
	}
}

bool CCharacterController_Ode::ResetCharacterPos(const Vector3& pos)
{
	return true;
}

bool CCharacterController_Ode::UpdateCharacterExtents(bool& increase)
{
	return true;
}

void CCharacterController_Ode::SetEnabled(bool isEnabled)
{
	// TODO: sleep() and wake() don't seem to work, so just destorying it.
	if(isEnabled)
	{
		InitCharacterControllers();
	}
	else
	{
		CORE_DELETE(m_TorsoGeom);
		CORE_DELETE(m_TorsoTrans);
		CORE_DELETE(m_TorsoBody);
	}
}

	//// Create a body associated with the node we created
 //   m_Body = new Ode::Body(m_Space->getWorld());
	//m_Player->GetPlayerNode()->attachObject(m_Body);

	//Entity* entity = m_Player->GetPlayerEntity();
	//SceneNode* node = m_Player->GetPlayerNode();
	//SceneNode* modelNode = node->createChildSceneNode(String(m_Player->GetName()) + "_cc_node");

	//// Getting AABB
	//AxisAlignedBox aab = entity->getBoundingBox(); 
	//Vector3 min = aab.getMinimum() * node->getScale();
	//Vector3 max = aab.getMaximum() * node->getScale();
	//Vector3 center = aab.getCenter() * node->getScale();
	//Vector3 size(fabs(max.x - min.x), fabs(max.y - min.y), fabs(max.z - min.z));
	//float radius = (size.x > size.z) ? size.z / 2.0f : size.x / 2.0f;

	//// Create a new space
	//Ode::SimpleSpace* dollSpace = new Ode::SimpleSpace(m_Space->getWorld(), m_Space->getWorld()->getDefaultSpace());
	//dollSpace->setInternalCollisions(false);

	//// create sphere
	//m_FeetBody = new Ode::Body(m_Space->getWorld(), String(m_Player->GetName()) + "_feet");
	//m_FeetBody->setMass(Ode::SphereMass(70 * 2.5, radius)); 
	//m_FeetBody->setAffectedByGravity(false);
	//Ode::SphereGeometry* feetGeom = new Ode::SphereGeometry(radius, m_Space->getWorld(), nullptr);
	//Ode::TransformGeometry* feetTrans = new Ode::TransformGeometry(m_Space->getWorld(), dollSpace); 
	//modelNode->translate(Vector3(0, -radius / node->getScale().y, 0));
	//feetTrans->setBody(m_FeetBody); 
	//feetTrans->setEncapsulatedGeometry(feetGeom);
	//m_FeetBody->setPosition(m_Player->GetPosition() + Vector3(0, 5, 0));
	//node->attachObject(m_FeetBody);

	//// Create the Capsule (torso)
	//m_TorsoBody = new Ode::Body(m_Space->getWorld(), String(m_Player->GetName()) + "torso"); 
	//m_TorsoBody->setMass(Ode::CapsuleMass(70 * 2.5, radius, Vector3::UNIT_Y, radius)); 
	//m_TorsoBody->setAffectedByGravity(false);
	//m_TorsoBody->setAngularVelocity(Vector3::ZERO);
	//Ode::TransformGeometry* torsoTrans = new Ode::TransformGeometry(m_Space->getWorld(), nullptr /*dollSpace*/); 
	//Ode::CapsuleGeometry* torsoGeom = new Ode::CapsuleGeometry(radius, size.y - 4 * radius, m_Space->getWorld(), dollSpace); 
	//torsoGeom->setPosition(Vector3(0, size.y - ((size.y - 4 * radius) / 2 + 2 * radius), 0)); //can't find a good way to explain this
	//torsoGeom->setOrientation(Quaternion(Degree(90), Vector3::UNIT_X));
	//torsoTrans->setBody(m_TorsoBody); 
	//torsoTrans->setEncapsulatedGeometry(torsoGeom);
	//modelNode->attachObject(m_TorsoBody);

	//// Create the Joint
	//Ode::HingeJoint* joint = new Ode::HingeJoint(m_Space->getWorld());
	//joint->attach(m_TorsoBody, m_FeetBody);
	//joint->setAxis(Vector3::UNIT_X);	//set the rotation axis