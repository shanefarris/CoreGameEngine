#ifndef _OGREODECOLLISION_H_
#define _OGREODECOLLISION_H_

#include "PreReqs.h"
#include "OgreVector3.h"

namespace Ode 
{
	class CollisionListener
	{
	public:
		CollisionListener();
		virtual ~CollisionListener();

		virtual bool collision(Contact* contact) = 0;
	};


	/** Using the default collisionCallbacks provided here will use the internal collisions setting of of the space. 
		The space collide function now takes a bool useInternalCollisionFlag if you want internal collisions.
	*/
	class CollisionCallback : public CollisionListener
	{
	public:
	
		friend class Space;
		friend class Geometry;
	
		CollisionCallback();
		virtual ~CollisionCallback();
		
		// handles the ode callback and passes on to pure virtual methods that inherited classes implement
		static void collisionCallback(void *data, dGeomID geom_a, dGeomID geom_b);

		// User impliemented
		virtual void collisionCallback(Ode::Space* spaceFirst, Ode::Space* spaceSecond);
		virtual void collisionCallback(Ode::Space* space, Ode::Geometry* geometry);
		virtual void collisionCallback(Ode::Space* space);
		
		// This is down to a AABB level of the geometry, call collide() in here to go down further.
		virtual void collisionCallback(Ode::Geometry* geometryFirst, Ode::Geometry* geometrySecond);
	};

	class Contact
	{
		friend class Geometry;
		friend class ContactMapCollisionListener;
	
	public:
		enum Flag
		{
			Flag_UseAdditionalFriction			= dContactMu2,
			Flag_UseFirstFrictionDirection		= dContactFDir1,
			Flag_SurfaceIsBouncy				= dContactBounce,
			Flag_UseERP							= dContactSoftERP,
			Flag_UseCFM							= dContactSoftCFM,
			Flag_IndependentMotion				= dContactMotion1, 
			Flag_AdditionalIndependentMotion	= dContactMotion2,
			Flag_UseFDS							= dContactSlip1,
			Flag_UseAdditionalFDS				= dContactSlip2,
			Flag_FrictionPyramid				= dContactApprox1_1,
			Flag_AdditionalFrictionPyramid		= dContactApprox1_2,
			Flag_BothFrictionPyramids			= dContactApprox1 
		};

	public:
		Contact();
		~Contact();

		const Vector3& getPosition();
		const Vector3& getNormal();
		f32 getPenetrationDepth();

        int getFirstSide();
        int getSecondSide();

		Geometry* getFirstGeometry();
		Geometry* getSecondGeometry();

		void setFirstFrictionDirection(const Vector3& vector);
		void setFrictionMode(Contact::Flag flag);

		void setCoulombFriction(const f32& mu, const f32& additional_mu = -1.0f);
		void setBouncyness(const f32& bouncyness, const f32& velocity_threshold = -1.0f);
		void setSoftness(const f32& ERP, const f32& CFM);
		void setIndependentMotion(const f32& velocity, const f32& additional_velocity = -1.0f);
		void setForceDependentSlip(const f32& FDS);
		void setAdditionalFDS(const f32& FDS);

		inline void setContact(dContact* contact)
		{
			_contact = contact;
			_contact->surface.mode = 0;
		}

	protected:
		inline Contact& operator=(dContact* contact)
		{
			_contact = contact;
			_contact->surface.mode = 0;
			return *this;
		}

	protected:
		dContact*	_contact;
		Vector3		_position,_normal;
	};

	class ContactMapCollisionListener : public CollisionListener
	{
	public:
		ContactMapCollisionListener();
		virtual ~ContactMapCollisionListener();

		virtual bool collision(Contact* contact);

		void createContact(MaterialID materialA,MaterialID materialB); 
		Contact *getContactPtr(MaterialID materialA,MaterialID materialB); 

	protected:
		Map<MaterialID, MaterialMap* > _map;
	};

	class PagedTerrainGeometryHeightListener
	{
	public:
		PagedTerrainGeometryHeightListener(){}
		virtual ~PagedTerrainGeometryHeightListener(){}

		virtual Ogre::Real heightAt(const Vector3& position) = 0;
	};

	class TerrainGeometryHeightListener
	{
	public:
		TerrainGeometryHeightListener() { }
		virtual ~TerrainGeometryHeightListener() { }

		virtual Ogre::Real heightAt(const Vector3& position) = 0;
	};
}

#endif
