#ifndef __IPHYSICSSTRATEGY_H__
#define __IPHYSICSSTRATEGY_H__

#include "Defines.h"

namespace Ogre
{
	class TerrainGroup;
}

namespace Core
{
	class CPlayer;
	class CGameObject;

namespace Physics
{
	class CWorldProfile;
	class CPhysicsHelper;
	class CVolumeObject;
	class ICharacterController;
	class CRagdollBoneInformation;
	class IPhysicsRagdoll;
	struct VolumePackage;
	struct SPhysicsRayCastReport;
	enum E_BODY_TYPE;
	enum E_VOLUME_TYPE;

	class IPhysicsStrategy
	{
		friend CPhysicsHelper;

	public:
		virtual ~IPhysicsStrategy() { }

		virtual bool InitWorld(CWorldProfile* WorldProfile = nullptr) = 0;

		// Returns the index of the shape created so it can be looked up if needed.
		virtual bool AddShape(const CGameObject* GameObject) = 0;
		virtual bool AddInfinitePlane(Plane* plane) = 0;
		virtual void SetEnabled(const CGameObject* GameObject, bool IsEnabled) = 0;


		// External modifications
		virtual void SetPosition(const CGameObject* GameObject, const Vector3 Position) = 0;
		virtual void AddForceAt(const CGameObject* GameObject, const Vector3& Force,const Vector3& Position) = 0;

		// Rays ***************************************************************************************************************
		// Finds the first shape if any
		virtual Vector3 RaycastClosestShape(const Vector3& From, const Vector3& To, SPhysicsRayCastReport& RayCastReport) = 0;
		// Finds the fisrt shape of a specified body shape type
		virtual Vector3 RaycastClosestType(const Vector3& From, const Vector3& To, E_BODY_TYPE Type, SPhysicsRayCastReport& RayCastReport) = 0;

		// Volume *************************************************************************************************************
		virtual CVolumeObject* CreateVolume(E_VOLUME_TYPE Type, VolumePackage* Package) = 0;
		virtual void		   RemoveVolume(CVolumeObject* Volume) = 0;
		
		// Terrain ************************************************************************************************************
		virtual void* AddTerrain(TerrainGroup* terrainGroup) = 0;

		// Listener ***********************************************************************************************************
		virtual void SetCollisionListener(void* Listener) = 0;
		
		// Ragdoll ************************************************************************************************************
		virtual IPhysicsRagdoll* CreateRagdoll(CPlayer* Player, const CRagdollBoneInformation& RagdollBoneInformation) = 0;
		virtual void			 RemoveRagdoll(IPhysicsRagdoll* Ragdoll) = 0;

		// Predefs ************************************************************************************************************
		virtual void* LoadPrefabVehicle(const char* FileName, const char* VehicleName) = 0;

		virtual void ShowDebug(bool Debug) = 0;
		virtual void Update(const f32& elapsedTime) = 0;
		virtual const char* GetStrategyType() = 0;

		// Character controller (NPC) *****************************************************************************************
		virtual ICharacterController* CreateCharacterController(CPlayer* Player) = 0;
		virtual void				  RemoveCharacterController(ICharacterController* CharacterController) = 0;

		// Used for serializing
		bool			IsDebug() { return isDebug; }
		CWorldProfile*	GetWorldProfile() { return m_WorldProfile; }
		
		// Physics body that is created when creating a shape
		virtual void DestroyPhysicsBody(const CGameObject* GameObject) = 0;
		virtual bool UpdatePhysicsBody(const CGameObject* GameObject) = 0;
		virtual bool UpdateWorld(const CWorldProfile* WorldProfile) = 0;

	protected:
		Vector<CVolumeObject*>	m_Volumes;
		CWorldProfile*			m_WorldProfile;
		bool					isDebug;
	};

}
}

#endif