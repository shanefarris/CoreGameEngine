#ifndef __CCUSTOMLISTENER_ODE_H__
#define __CCUSTOMLISTENER_ODE_H__

#include "Wrapper/Collision.h"

namespace Ode
{
	class Contact;
	class TerrainGeometry;
	class PagedTerrainGeometry;
}

namespace Core
{
namespace Physics
{
	class CGenericCollisionListener_Ode : public Ode::CollisionListener
	{
	public:
		CGenericCollisionListener_Ode();
		~CGenericCollisionListener_Ode();
		bool collision(Ode::Contact* contact);
	};

	class CClosestRayCollisionListener_Ode : public Ode::CollisionListener
	{
	public:
		CClosestRayCollisionListener_Ode();
		~CClosestRayCollisionListener_Ode();
		bool collision(Ode::Contact* contact);

		Vector3 ClosestPoint;		// As it iterates it will record the clostest point found.
		Vector3 OriginPoint;		// Where the ray starts
		
	};
	
	class CGenericPagedTerrainGeometryHeightListener_Ode  : public Ode::CollisionListener, Ode::PagedTerrainGeometryHeightListener
	{
	protected:
		Ode::PagedTerrainGeometry* m_Terrain;

	public:
		CGenericPagedTerrainGeometryHeightListener_Ode(Ode::PagedTerrainGeometry* Terrain);
		~CGenericPagedTerrainGeometryHeightListener_Ode();
		bool collision(Ode::Contact* contact);
		f32 heightAt(const Vector3& position);
	};
	
	class CGenericTerrainGeometryHeightListener_Ode  : public Ode::CollisionListener, Ode::TerrainGeometryHeightListener
	{
	protected:
		Ode::TerrainGeometry* m_Terrain;

	public:
		CGenericTerrainGeometryHeightListener_Ode(Ode::TerrainGeometry* Terrain);
		~CGenericTerrainGeometryHeightListener_Ode();
		bool collision(Ode::Contact* contact);
		f32 heightAt(const Vector3& position);
	};
}
}

#endif // __CCUSTOMLISTENER_ODE_H__