#ifndef __CPHYSICSSTRATEGYODE_H__
#define __CPHYSICSSTRATEGYODE_H__

#include "IPhysicsStrategy.h"
#include "PhysicsStructures.h"

namespace Ogre
{
	class TerrainGroup;
}

namespace Ode
{
	class World;
	class Body;
	class Space;
	class StepHandler;
	class Geometry;
	class Vehicle;
	class RagdollFactory;
	class Ragdoll;
	class DotLoader;
}

namespace Core
{
namespace Physics
{
	class CWorldProfile;
	class CPhysicsRagdoll_Ode;
	class CGenericCollisionListener_Ode;
	class CClosestRayCollisionListener_Ode;
	class CCharacterController_Ode;

	class CPhysicsStrategy_Ode : public IPhysicsStrategy
	{
	public:
		CPhysicsStrategy_Ode();
		~CPhysicsStrategy_Ode();

		bool InitWorld(CWorldProfile* WorldProfile = nullptr);

		bool AddShape(const CGameObject* GameObject);
		bool AddInfinitePlane(Plane* plane);
		void SetEnabled(const CGameObject* GameObject, bool IsEnabled);

		void SetPosition(const CGameObject* GameObject, const Vector3 Position);
		void AddForceAt(const CGameObject* GameObject, const Vector3& Force,const Vector3& Position);

		Vector3 RaycastClosestShape(const Vector3& From, const Vector3& To, SPhysicsRayCastReport& RayCastReport);
		Vector3 RaycastClosestType(const Vector3& From, const Vector3& To, E_BODY_TYPE Type, SPhysicsRayCastReport& RayCastReport);

		CVolumeObject* CreateVolume(E_VOLUME_TYPE Type, VolumePackage* Package) { return nullptr; }
		void		   RemoveVolume(CVolumeObject* Volume) { }

		void* AddTerrain(const Vector3 &scale, s32 nodes_per_sideX, s32 nodes_per_sideY, f32 worldSizeX, f32 worldSizeZ, bool centered, f32 thickness = 10.0f);
		void* AddTerrain(TerrainGroup* terrainGroup);

		void  SetCollisionListener(void* Listener);

		void* LoadPrefabVehicle(const char* FileName, const char* VehicleName);

		IPhysicsRagdoll* CreateRagdoll(CPlayer* Player, const CRagdollBoneInformation& RagdollBoneInformation);
		void			 RemoveRagdoll(IPhysicsRagdoll* Ragdoll);

		ICharacterController* CreateCharacterController(CPlayer* Player);
		void				  RemoveCharacterController(ICharacterController* CharacterController);

		void  ShowDebug(bool isDebug);
		void  Update(const f32& elapsedTime);
		const char*	GetStrategyType() { return "ODE"; }

		void DestroyPhysicsBody(const CGameObject* GameObject);
		bool UpdatePhysicsBody(const CGameObject* GameObject);
		bool UpdateWorld(const CWorldProfile* WorldProfile);

	private:
		
		Vector3 GetBoundingBox(const SceneNode* Node, Entity* entity) const;
		f32     GetBoundingRadius(const Entity* entity) const;
		bool    ValidateProfile(const CGameObject* Profile) const;
		void    Initialize();
		void    AddToContainer(const CGameObject* GameObject, Ode::Body* Body, Ode::Geometry* Geom);

		bool AddCube(const CGameObject* GameObject);
		bool AddSphere(const CGameObject* GameObject);
		bool AddCylinder(const CGameObject* GameObject);
		bool AddCapsule(const CGameObject* GameObject);
		bool AddCone(const CGameObject* GameObject);
		bool AddStaticTrimesh(const CGameObject* GameObject);
		bool AddTrimesh(const CGameObject* GameObject);

		struct GemoContainer
		{
			Ode::Body*		Body;
			Ode::Geometry*	Geometry;
		};

		Ode::World*							m_World;
		Ode::Space*							m_SpaceMain;			// Parent space for everything
		Ode::Space*							m_SpaceRay;				// Space for all rays
		Ode::Space*							m_SpaceChar;			// Space for character controllers
		Ode::StepHandler*					m_Stepper;
		Ode::DotLoader*						m_DotLoader;
		Ode::RagdollFactory*				m_RagdollFactory;
		Vector<Ode::Vehicle*>				m_Vehicles;
		Vector<CPhysicsRagdoll_Ode*>		m_Ragdolls;
		Vector<CCharacterController_Ode*>	m_CharacterControllers;
		CGenericCollisionListener_Ode*		m_DefaultListener;
		CClosestRayCollisionListener_Ode*	m_ClosestRayCollisionListener;
		Map<const CGameObject*, GemoContainer>	m_Containers;
	};
}
}

#endif // __CPHYSICSSTRATEGYODE_H__
