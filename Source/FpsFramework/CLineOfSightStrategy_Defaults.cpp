#include "CLineOfSightStrategy_Defaults.h"
#include "Defines.h"
#include "CPlayer.h"
#include "CGameObject.h"
#include "PlayerEnums.h"
#include "IPhysicsStrategy.h"
#include "PhysicsStructures.h"
#include "CUtility.h"

// Ogre
#include "OgreSceneNode.h"

using namespace Core;
using namespace Core::Physics;

// ILineOfSightStrategy
ILineOfSightStrategy::ILineOfSightStrategy(CPlayer* Player) : m_Player(Player), m_PlayerNode(nullptr)
{
	if(m_Player)
		m_PlayerNode = m_Player->GetPlayerNode();
}

// CLineOfSightStrategy_Basic
CLineOfSightStrategy_Basic::CLineOfSightStrategy_Basic(CPlayer* Player) : ILineOfSightStrategy(Player)
{
	m_LosType = ELT_BASIC;
	m_PlayerNode = m_Player->GetPlayerNode();
}

CLineOfSightStrategy_Basic::~CLineOfSightStrategy_Basic()
{
}

bool CLineOfSightStrategy_Basic::CanSee(CPlayer* Player)
{
	//Check range
	if (m_PlayerNode->getPosition().distance(Player->GetPosition()) <= (m_Player->GetViewRange()))
	{
		return true;
	}
	return false;
}

bool CLineOfSightStrategy_Basic::CanSee(const Ogre::Vector3& Position)
{
	//Check range
	if (m_PlayerNode->getPosition().distance(Position) <= (m_Player->GetViewRange()))
	{
		return true;
	}
	return false;
}

// CLineOfSightStrategy_Triangle
CLineOfSightStrategy_Triangle::CLineOfSightStrategy_Triangle(CPlayer* Player) : ILineOfSightStrategy(Player)
{
	m_PhysicsStrategy = m_Player->GetPhysicsStrategy();
	m_LosType = ELT_TRIANGLE;
}

CLineOfSightStrategy_Triangle::~CLineOfSightStrategy_Triangle()
{
}

bool CLineOfSightStrategy_Triangle::CanSee(CPlayer* Player)
{
	Vector3 canSeePos = Player->GetPlayerNode()->getPosition();
	
	// Get distance
	f32 dist = m_Player->GetPlayerNode()->getPosition().squaredDistance(canSeePos);
	
	// Directly see if closer than minrange (5) and moving at a certain speed
	if (dist < 5)
	{
		return true;
	}
	else if (dist < (m_Player->GetViewRange() * m_Player->GetViewRange()))
	{
		// Prepare line of sight triangle
		// 60 degrees left & right, total 120 degrees of sight
		Quaternion q;
		q.FromAngleAxis(Radian(Math::PI/3), Vector3::UNIT_Y);
		Vector3 direction = m_Player->GetDirection().normalisedCopy();
		Vector3 A = m_PlayerNode->getPosition();
		Vector3 B = m_PlayerNode->getPosition() + q * (direction * m_Player->GetViewRange());
		Vector3 C = m_PlayerNode->getPosition() + q.Inverse() * (direction * m_Player->GetViewRange());
		
		// Check delta y
		float dy = Math::Abs(A.y - canSeePos.y);
		
		// Check ray cast
		if(m_PhysicsStrategy)
		{
			Vector3 add1 = direction * m_Player->GetEyePosition();
			Vector3 add2(-add1.x, add1.y, -add1.z);
			Physics::SPhysicsRayCastReport Report;
			Vector3 result = m_PhysicsStrategy->RaycastClosestShape(m_PlayerNode->getPosition() + add1, canSeePos + add2, Report);
			if(Report.BodyType == Physics::PLAYER)
				return dy < 100.0 && CUtility::PointInTriangle2D(canSeePos, A, B, C);
		}
		
		return false;
	}

	return false;
}

bool CLineOfSightStrategy_Triangle::CanSee(const Ogre::Vector3& Position)
{
#if 1
	//Check range
	if (m_PlayerNode->getPosition().squaredDistance(Position) <= (m_Player->GetViewRange() * m_Player->GetViewRange()))
	{
		//prepare line of sight triangle
		//60 degrees left & right, total 120 degrees of sight
		Quaternion q;
		q.FromAngleAxis(Radian(Math::PI / 3), Vector3::UNIT_Y);
		Vector3 direction = m_Player->GetDirection().normalisedCopy();
		Vector3 A = m_PlayerNode->getPosition();
		Vector3 B = m_PlayerNode->getPosition() + q * (direction * m_Player->GetViewRange());
		Vector3 C = m_PlayerNode->getPosition() + q.Inverse() * (direction * m_Player->GetViewRange());
		Vector3 P = Position;

		//check delta y
		const f32 dy = Math::Abs(A.y - P.y);

#ifdef _DEBUG

		bool test = dy < 100.0 && CUtility::PointInTriangle2D(P, A, B, C);
		return test;
#else
		return dy < 100.0 && CUtility::PointInTriangle2D(P, A, B, C);
#endif
	}

	return false;
#endif

#if 0
	// This does not work unless the player is looking in the +x direction
	if (m_PlayerNode->getPosition().squaredDistance(Position) <= (m_Player->GetViewRange() * m_Player->GetViewRange()))
	{
		Vector3 A = m_PlayerNode->getPosition();

		auto radians = A.angleBetween(Position);
		if(A.crossProduct(Position).y > 0.0f)
		{
			f32 newAngle = radians.valueDegrees();
			newAngle = 360.0f - newAngle;
			radians = Degree(newAngle);
		}

		auto degrees = Degree(radians);
		return degrees < Degree(60) && degrees > Degree(-60);
	}
	return false;
#endif
}

// CLineOfSightStrategy_RangeBasic
CLineOfSightStrategy_RangeBasic::CLineOfSightStrategy_RangeBasic(CPlayer* Player) : ILineOfSightStrategy(Player)
{
	m_PhysicsStrategy = m_Player->GetPhysicsStrategy();
	m_LosType = ELT_RANGE_BASIC;
}

CLineOfSightStrategy_RangeBasic::~CLineOfSightStrategy_RangeBasic()
{
}

bool CLineOfSightStrategy_RangeBasic::CanSee(CPlayer* Player)
{
	// Implement this, same as "basic" but with random rays trying to find the bounding box
	return false;
}

bool CLineOfSightStrategy_RangeBasic::CanSee(const Ogre::Vector3& Position)
{
	// Implement this, same as "basic" but with random rays trying to find the bounding box
	return false;
}
