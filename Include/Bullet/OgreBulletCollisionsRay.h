#ifndef _OGREBULLETCOLLISIONS_CollisionRay_H
#define _OGREBULLETCOLLISIONS_CollisionRay_H

#include "OgreBulletCollisionsPreRequisites.h"

namespace OgreBulletCollisions
{
	// basic CollisionRay
	class CORE_EXPORT CollisionRayResultCallback 
	{
	public:
		CollisionRayResultCallback(const Ogre::Ray &ray, CollisionsWorld *world, Ogre::Real max_distance, bool init = true);
		virtual ~CollisionRayResultCallback();

		btCollisionWorld::RayResultCallback *getBulletRay() const {return mRayResultCallback;}

		bool doesCollide () const;

		void setRay(const Ogre::Ray &ray);
		void setWorld(CollisionsWorld *world);
		void setMaxDistance(Ogre::Real max_distance);

		inline const Ogre::Ray &getRay() const;
		Ogre::Vector3 getRayStartPoint() const;
		Ogre::Vector3 getRayEndPoint() const;

	protected:

		btCollisionWorld::RayResultCallback   *mRayResultCallback;
		CollisionsWorld                       *mWorld;
		Ogre::Ray                              mRay;
		Ogre::Real                             mMaxDistance;

	};

	// basic CollisionRay inline methods
	inline const Ogre::Ray &CollisionRayResultCallback::getRay() const 
	{
		return mRay;
	}

	//  CollisionClosestRay
	class CORE_EXPORT CollisionClosestRayResultCallback : public CollisionRayResultCallback
	{ 
	public:
		CollisionClosestRayResultCallback(const Ogre::Ray &ray, CollisionsWorld *world, Ogre::Real max_distance);
		virtual ~CollisionClosestRayResultCallback() {};

		Object *getCollidedObject() const;
		Ogre::Vector3 getCollisionPoint() const;
		Ogre::Vector3 getCollisionNormal() const;

		inline btCollisionWorld::ClosestRayResultCallback *getBulletClosestRayResultCallback() const 
		{
			return static_cast <btCollisionWorld::ClosestRayResultCallback * > (mRayResultCallback);
		}
	};
}
#endif //_OGREBULLETCOLLISIONS_CollisionRay_H

