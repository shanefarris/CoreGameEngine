#include "CCustomListener_Ode.h"
#include "PhysicsStructures.h"

#include "Wrapper/Collision.h"
#include "Wrapper/Joint.h"
#include "Wrapper/Utility.h"
#include "Wrapper/Geometry.h"

using namespace Core;
using namespace Core::Physics;

CGenericCollisionListener_Ode::CGenericCollisionListener_Ode()
{
}

CGenericCollisionListener_Ode::~CGenericCollisionListener_Ode()
{
}

bool CGenericCollisionListener_Ode::collision(Ode::Contact* contact)
{
	// Check for collisions between things that are connected and ignore them
	Ode::Geometry * const g1 = contact->getFirstGeometry();
	Ode::Geometry * const g2 = contact->getSecondGeometry();

	if (g1 && g2)
	{
		const Ode::Body * const b1 = g1->getBody();
		const Ode::Body * const  b2 = g2->getBody();
		if (b1 && b2 && Ode::Joint::areConnected(b1, b2)) 
			return false; 
	}

	// Set the friction at the contact
	contact->setCoulombFriction(Ode::Utility::Infinity);

	contact->setBouncyness(0.1f);

	// Yes, this collision is valid
	return true;
}

CClosestRayCollisionListener_Ode::CClosestRayCollisionListener_Ode() : ClosestPoint(INVALID_POS), OriginPoint(INVALID_POS)
{
}

CClosestRayCollisionListener_Ode::~CClosestRayCollisionListener_Ode()
{
}

bool CClosestRayCollisionListener_Ode::collision(Ode::Contact* contact)
{
	// Check for collisions between things that are connected and ignore them
	auto g1 = contact->getFirstGeometry();
	auto g2 = contact->getSecondGeometry();

	// g1 should always be the ray geometry
	Ode::RayGeometry* ray = nullptr;
	if(g1->getClass() == Ode::Class_Ray)
		ray = static_cast<Ode::RayGeometry*>(g1);

	if(ray)
	{
		auto report = new SPhysicsRayCastReport();
		report->Data = g2->GetCustomData();
		report->BodyType = g2->GetBodyType();
		report->Position = contact->getPosition();
				
		// Update closest point and save if closest
		if(ClosestPoint.distance(OriginPoint) > report->Position.distance(OriginPoint) || ClosestPoint == INVALID_POS)
		{
			ClosestPoint = report->Position;
			ray->SetRayCastReport(report);
		}
	}

	return true;
}
	
CGenericPagedTerrainGeometryHeightListener_Ode::CGenericPagedTerrainGeometryHeightListener_Ode(Ode::PagedTerrainGeometry* Terrain)
{
	m_Terrain = Terrain;
}

CGenericPagedTerrainGeometryHeightListener_Ode::~CGenericPagedTerrainGeometryHeightListener_Ode()
{
}

bool CGenericPagedTerrainGeometryHeightListener_Ode::collision(Ode::Contact* contact)
{
	// Check for collisions between things that are connected and ignore them
	Ode::Geometry * const g1 = contact->getFirstGeometry();
	Ode::Geometry * const g2 = contact->getSecondGeometry();

	if (g1 && g2)
	{
		const Ode::Body * const b1 = g1->getBody();
		const Ode::Body * const  b2 = g2->getBody();
		if (b1 && b2 && Ode::Joint::areConnected(b1, b2)) 
			return false; 
	}

	// Set the friction at the contact
	contact->setCoulombFriction(Ode::Utility::Infinity);

	contact->setBouncyness(0.1f);

	// Yes, this collision is valid
	return true;
}

f32 CGenericPagedTerrainGeometryHeightListener_Ode::heightAt(const Vector3& position)
{
	return m_Terrain->getHeightAt(position); //this is the get height function 
}
	
CGenericTerrainGeometryHeightListener_Ode::CGenericTerrainGeometryHeightListener_Ode(Ode::TerrainGeometry* Terrain)
{
	m_Terrain = Terrain;
}

CGenericTerrainGeometryHeightListener_Ode::~CGenericTerrainGeometryHeightListener_Ode()
{
}

bool CGenericTerrainGeometryHeightListener_Ode::collision(Ode::Contact* contact)
{
	// Check for collisions between things that are connected and ignore them
	Ode::Geometry * const g1 = contact->getFirstGeometry();
	Ode::Geometry * const g2 = contact->getSecondGeometry();

	if (g1 && g2)
	{
		const Ode::Body * const b1 = g1->getBody();
		const Ode::Body * const  b2 = g2->getBody();
		if (b1 && b2 && Ode::Joint::areConnected(b1, b2)) 
			return false; 
	}

	// Set the friction at the contact
	contact->setCoulombFriction(Ode::Utility::Infinity);

	contact->setBouncyness(0.1f);

	// Yes, this collision is valid
	return true;
}

f32 CGenericTerrainGeometryHeightListener_Ode::heightAt(const Vector3& position)
{
	return m_Terrain->getHeightAt(position); //this is the get height function 
}