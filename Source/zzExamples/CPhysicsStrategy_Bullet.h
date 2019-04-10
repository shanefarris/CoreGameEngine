#if COMPILE_BULLET

#ifndef __CPHYSICSSTRATEGYBULLET_H__
#define __CPHYSICSSTRATEGYBULLET_H__

#include "Defines.h"
#include "IPhysicsStrategy.h"
#include "OgreBulletDynamicsPreRequisites.h"
#include "OgreBulletDynamicsRigidBody.h"

using namespace OgreBulletCollisions;
using namespace OgreBulletDynamics;

namespace Core
{
namespace Physics
{
	class CORE_EXPORT CPhysicsStrategy_Bullet : public IPhysicsStrategy
	{
	public:
		CPhysicsStrategy_Bullet();
		~CPhysicsStrategy_Bullet();

		// For now we will only have one world
		void InitWorld(const reVector3Df &gravityVector, const AxisAlignedBox &bounds);
		void AddCube(SceneNode* Node, Entity* entity, const f32 bodyRestitution, const f32 bodyFriction, const f32 bodyMass);
		void AddSphere(SceneNode* Node, Entity* entity, const f32 bodyRestitution, const Real bodyFriction, const f32 bodyMass);
		void AddCylinder(SceneNode* Node, Entity* entity, const f32 bodyRestitution, const f32 bodyFriction, const f32 bodyMass);
		void AddCone(SceneNode* Node, Entity* entity, const f32 bodyRestitution, const f32 bodyFriction, const f32 bodyMass);
		void AddStaticTrimesh(SceneNode* Node, Entity* entity, const f32 bodyRestitution, const f32 bodyFriction);
		void AddTrimesh(SceneNode* Node, Entity* entity, const f32 bodyRestitution, const f32 bodyFriction);
		void AddInfinitePlane(Plane* plane) { }
		void* AddTerrain(const reVector3Df &scale,
									s32 nodes_per_sideX,
									s32 nodes_per_sideY,
									f32 worldSizeX,
									f32 worldSizeZ,
									bool centered,
									f32 thickness = 10.0f) { return nullptr; };

		void SetCollisionListener(void* Listener) { };
		E_PHYSICS_STRATEGY GetStrategyType() { return EPS_BULLET; }

		void		Update(f32 elapsedTime);
		reVector3Df GetBoundingBox(Entity* entity);
		f32			GetBoundingRadius(Entity* entity);

	private:

		void Initialize();

		SceneManager*	m_SceneManager;
		DynamicsWorld*	m_World;

		std::deque<Entity *>		 m_Entities;
		std::deque<RigidBody *>		 m_Bodies;
		std::deque<CollisionShape *> m_Shapes;
		u32 NumOfShapes;
	};
}
}

#endif // __CPHYSICSSTRATEGYBULLET_H__

#endif