#include "CPhysicsStrategy_Ode.h"
#include "CGameManager.h"
#include "CPhysicsProfile.h"
#include "CBuilding.h"
#include "CGameObject.h"
#include "CPlayer.h"
#include "CCharacterController_Ode.h"
#include "CCustomListener_Ode.h"
#include "CRagdollBoneInformation.h"
#include "CPhysicsRagdoll_Ode.h"
#include "PhysicsStructures.h"
#include "CWorldProfile.h"

#include "IO/CoreLogging.h"

#include "Wrapper/World.h"
#include "Wrapper/Space.h"
#include "Wrapper/Body.h"
#include "Wrapper/Geometry.h"
#include "Wrapper/Mass.h"
#include "Wrapper/Stepper.h"
#include "Wrapper/Utility.h"
#include "Wrapper/EntityInformer.h"
#include "Wrapper/Prefab/DotLoader.h"
#include "Wrapper/Prefab/Ragdoll.h"
#include "Wrapper/Prefab/Vehicle.h"

#include "OgreRoot.h"
#include "OgreMatrix4.h"
#include "Terrain/OgreTerrainGroup.h"

using namespace Core;
using namespace Core::Physics;
using namespace Ode;

CPhysicsStrategy_Ode::CPhysicsStrategy_Ode()
{
	Initialize();
}

CPhysicsStrategy_Ode::~CPhysicsStrategy_Ode()
{
	while(m_Vehicles.size() > 0)
	{
		CORE_DELETE(m_Vehicles[0]);
		m_Vehicles.erase(m_Vehicles.begin());
	}

	while(m_Ragdolls.size() > 0)
	{
		CORE_DELETE(m_Ragdolls[0]);
		m_Ragdolls.erase(m_Ragdolls.begin());
	}

	while(m_CharacterControllers.size() > 0)
	{
		CORE_DELETE(m_CharacterControllers[0]);
		m_CharacterControllers.erase(m_CharacterControllers.begin());
	}

	m_Containers.erase(m_Containers.begin(), m_Containers.end());

	CORE_DELETE(m_DefaultListener);
	CORE_DELETE(m_ClosestRayCollisionListener);
	CORE_DELETE(m_DotLoader);

	// Do not remove m_RagdollFactory, the scene manager will do that
	//CORE_DELETE(m_RagdollFactory);

	CORE_DELETE(m_WorldProfile);
	CORE_DELETE(m_World);
}

void CPhysicsStrategy_Ode::Initialize()
{
	// Setup ragdoll factory for movable objects fatory (ogre specific)
	m_RagdollFactory = new RagdollFactory();
	bool isFactoryLoaded = false;
	auto it = CGameManager::Instance()->GetEngineDevice()->getMovableObjectFactoryIterator();
	while(it.hasMoreElements())
	{
		if(it.current()->second->getType() == m_RagdollFactory->getType())
		{
			isFactoryLoaded = true;
			break;
		}
		it.getNext();
	}
	
	if(!isFactoryLoaded)
	{
		CGameManager::Instance()->GetEngineDevice()->addMovableObjectFactory(m_RagdollFactory);
	}

	// Set our loader to nullptr, can't initialize until we have a world
	m_DotLoader = nullptr;

	m_WorldProfile = nullptr;
}

bool CPhysicsStrategy_Ode::InitWorld(CWorldProfile* WorldProfile)
{
	// Create the ODE world
	m_World = new World(CGameManager::Instance()->GetSceneManager());

	if(WorldProfile)
		m_WorldProfile = new CWorldProfile(*WorldProfile);
	else
		m_WorldProfile = new CWorldProfile();
	
	m_World->setGravity(m_WorldProfile->Gravity);
	m_World->setCFM(10e-5f);
	m_World->setERP(0.8f);
	m_World->setAutoSleep(true);
    m_World->setAutoSleepAverageSamplesCount(10);
	m_World->setContactCorrectionVelocity(1.0);
	m_World->setAutoSleepAngularThreshold(Utility::Infinity);

	// Parent space
	m_SpaceMain = m_World->getDefaultSpace();

	// Ray space
	m_SpaceRay = new SimpleSpace(m_World, m_SpaceMain);
	m_SpaceRay->setAutoCleanup(false);
	m_SpaceRay->setInternalCollisions(true);

	// Characater space
	m_SpaceChar = new SimpleSpace(m_World, m_SpaceMain);
	m_SpaceChar->setAutoCleanup(false);
	m_SpaceChar->setInternalCollisions(true);

	//m_Stepper = new StepHandler(m_World, StepHandler::QuickStep, time_step, max_frame_time, time_scale);
	// default step handler
	const f32 time_step = 0.01f;
	const f32 time_scale = 1.0f; 
	const f32 max_frame_time = f32(1.0f / 4.0f);
	const f32 frame_rate = f32(1.0f / 60.0f);

	m_Stepper = new ForwardFixedStepHandler(m_World, 
            StepHandler::QuickStep, 
            time_step,
            max_frame_time,
            time_scale);

	//m_Stepper->setAutomatic(StepHandler::AutoMode_PostFrame, 
	//						CGameManager::Instance()->GetEngineDevice());

	// Setup default listeners
	m_DefaultListener = new CGenericCollisionListener_Ode();
	m_ClosestRayCollisionListener = new CClosestRayCollisionListener_Ode();
	m_World->setCollisionListener(m_DefaultListener);

	return true;
}

bool CPhysicsStrategy_Ode::AddShape(const CGameObject* GameObject)
{
	if(!ValidateProfile(GameObject))
		return false;

	bool ret = false;
	switch(GameObject->PhysicsProfile->GetShape())
	{
		case SHAPE_CUBE:
			ret = AddCube(GameObject);
			break;
		case SHAPE_SPHERE:
			ret = AddSphere(GameObject);
			break;
		case SHAPE_CAPSULE:
			ret = AddCapsule(GameObject);
			break;
		case SHAPE_CYLINDER:
			ret = AddCylinder(GameObject);
			break;
		case SHAPE_CONE:
			ret = AddCone(GameObject);
			break;
		case SHAPE_STATIC_TRIMESH:
			ret = AddStaticTrimesh(GameObject);
			break;
		case SHAPE_TRIMESH:
			ret = AddTrimesh(GameObject);
			break;
	}
	return ret;
}

bool CPhysicsStrategy_Ode::AddCube(const CGameObject* GameObject)
{
	// Set mass
	Vector3 size = GetBoundingBox(GameObject->Node, GameObject->Entity);
	BoxMass mass(GameObject->PhysicsProfile->GetMass(), size);
	if(GameObject->PhysicsProfile->GetDensity() <= 0)
		mass.setDensity(0.1f, size);
	else
		mass.setDensity(GameObject->PhysicsProfile->GetDensity(), size);

	// Create a body associated with the node we created
	Body* body = nullptr;
	if(GameObject->PhysicsProfile->GetIsStatic() == false)
	{
		body = new Body(m_World);
		GameObject->Node->attachObject(body);
		body->setMass(mass);
	}

	// Setup the geometry
	Geometry* geom = nullptr;
	if(GameObject->PhysicsProfile->GetPositionOffset() == INVALID_POS)
	{
		// Tie the collision geometry to the physical body
		geom = new BoxGeometry(size, m_World, m_SpaceMain); 
		if(GameObject->PhysicsProfile->GetIsStatic() == false)
		{
			geom->setBody(body);
		}
		geom->setPosition(GameObject->Node->getPosition());
	}
	else
	{
		geom = new BoxGeometry(size, m_World, nullptr); 
		geom->setPosition(GameObject->PhysicsProfile->GetPositionOffset());

		auto tranGeom = new Ode::TransformGeometry(m_World, m_SpaceMain); 
		if(GameObject->PhysicsProfile->GetIsStatic() == false)
		{
			tranGeom->setBody(body); 
		}
		
		tranGeom->SetBodyType(GameObject->PhysicsProfile->GetBodyType());
		tranGeom->setEncapsulatedGeometry(geom);
		tranGeom->SetCustomData((void*)GameObject);
	}

	geom->SetCustomData((void*)GameObject);
	geom->SetBodyType(GameObject->PhysicsProfile->GetBodyType());

	AddToContainer(GameObject, body, geom);
	return (body && geom);
}

bool CPhysicsStrategy_Ode::AddSphere(const CGameObject* GameObject)
{
	// Set mass
	f32 radius = GetBoundingRadius(GameObject->Entity);
	SphereMass mass(GameObject->PhysicsProfile->GetMass(), radius);

	if(GameObject->PhysicsProfile->GetDensity() <= 0)
		mass.setDensity(0.1f, radius);
	else
		mass.setDensity(GameObject->PhysicsProfile->GetDensity(), radius);

	// Create a body associated with the node we created
	Body* body = nullptr;
	if(GameObject->PhysicsProfile->GetIsStatic() == false)
	{
		body = new Body(m_World);
		GameObject->Node->attachObject(body);
		body->setMass(mass);
	}

	// Setup the geometry
	Geometry* geom = nullptr;
	if(GameObject->PhysicsProfile->GetPositionOffset() == INVALID_POS)
	{
		// Tie the collision geometry to the physical body
		geom = new SphereGeometry(radius, m_World, m_SpaceMain);
		if(GameObject->PhysicsProfile->GetIsStatic() == false)
		{
			geom->setBody(body);
		}
	}
	else
	{
		geom = new SphereGeometry(radius, m_World, nullptr); 
		geom->setPosition(GameObject->PhysicsProfile->GetPositionOffset());

		auto tranGeom = new Ode::TransformGeometry(m_World, m_SpaceMain); 
		if(GameObject->PhysicsProfile->GetIsStatic() == false)
		{
			tranGeom->setBody(body); 
		}
		tranGeom->SetBodyType(GameObject->PhysicsProfile->GetBodyType());
		tranGeom->setEncapsulatedGeometry(geom);
		tranGeom->SetCustomData((void*)GameObject);
	}
	geom->SetCustomData((void*)GameObject);
	geom->SetBodyType(GameObject->PhysicsProfile->GetBodyType());

	AddToContainer(GameObject, body, geom);
	return (body && geom);
}

bool CPhysicsStrategy_Ode::AddCylinder(const CGameObject* GameObject)
{
	f32 density = GameObject->PhysicsProfile->GetDensity();
	f32 size = GameObject->PhysicsProfile->GetSize().y;
	f32 radius = GetBoundingRadius(GameObject->Entity);
	Vector3 dir = Vector3::UNIT_Y;

	CylinderMass mass(GameObject->PhysicsProfile->GetMass(), dir, radius, size);
	mass.setDensity(GameObject->PhysicsProfile->GetDensity(), dir, radius, size);

	// Create a body associated with the node we created
	Body* body = nullptr;
	if(GameObject->PhysicsProfile->GetIsStatic() == false)
	{
		body = new Body(m_World);
		GameObject->Node->attachObject(body);
		body->setMass(mass);
	}

	// Setup the geometry
	Geometry* geom = nullptr;
	if(GameObject->PhysicsProfile->GetPositionOffset() == INVALID_POS)
	{
		// Tie the collision geometry to the physical body
		geom = new CylinderGeometry(radius, size, m_World, m_SpaceMain);
		if(GameObject->PhysicsProfile->GetIsStatic() == false)
		{
			geom->setBody(body);
		}
	}
	else
	{
		geom = new CylinderGeometry(radius, size, m_World, nullptr); 
		geom->setPosition(GameObject->PhysicsProfile->GetPositionOffset());

		auto tranGeom = new Ode::TransformGeometry(m_World, m_SpaceMain);
		if(GameObject->PhysicsProfile->GetIsStatic() == false)
		{
			tranGeom->setBody(body); 
		}
		tranGeom->SetBodyType(GameObject->PhysicsProfile->GetBodyType());
		tranGeom->setEncapsulatedGeometry(geom);
		tranGeom->SetCustomData((void*)GameObject);
	}
	geom->SetCustomData((void*)GameObject);
	geom->SetBodyType(GameObject->PhysicsProfile->GetBodyType());

	AddToContainer(GameObject, body, geom);
	return (body && geom);
}

bool CPhysicsStrategy_Ode::AddCapsule(const CGameObject* GameObject)
{
	f32 density = GameObject->PhysicsProfile->GetDensity();
	f32 size = GameObject->PhysicsProfile->GetSize().y;
	f32 radius = GetBoundingRadius(GameObject->Entity);
	Vector3 dir = GameObject->PhysicsProfile->GetDirection();

	CapsuleMass mass(GameObject->PhysicsProfile->GetMass(), radius, dir, size);
	mass.setDensity(GameObject->PhysicsProfile->GetDensity(), radius, dir, size);		
	
	// Create a body associated with the node we created
	Body* body = nullptr;
	if(GameObject->PhysicsProfile->GetIsStatic() == false)
	{
		body = new Body(m_World);
		GameObject->Node->attachObject(body);
		body->setMass(mass);
	}

	// Setup the geometry
	Geometry* geom = nullptr;
	if(GameObject->PhysicsProfile->GetPositionOffset() == INVALID_POS)
	{
		// Tie the collision geometry to the physical body
		geom = new CapsuleGeometry(radius, size, m_World, m_SpaceMain);
		if(GameObject->PhysicsProfile->GetIsStatic() == false)
		{
			geom->setBody(body);
		}
	}
	else
	{
		geom = new CapsuleGeometry(radius, size, m_World, nullptr); 
		geom->setPosition(GameObject->PhysicsProfile->GetPositionOffset());

		auto tranGeom = new Ode::TransformGeometry(m_World, m_SpaceMain); 
		if(GameObject->PhysicsProfile->GetIsStatic() == false)
		{
			tranGeom->setBody(body); 
		}
		tranGeom->SetBodyType(GameObject->PhysicsProfile->GetBodyType());
		tranGeom->setEncapsulatedGeometry(geom);
		tranGeom->SetCustomData((void*)GameObject);
	}
	geom->SetCustomData((void*)GameObject);
	geom->SetBodyType(GameObject->PhysicsProfile->GetBodyType());

	AddToContainer(GameObject, body, geom);
	return (body && geom);
}

bool CPhysicsStrategy_Ode::AddCone(const CGameObject* GameObject)
{
	CORE_THROW("CPhysicsStrategy_Ode::AddCone not supported", "");
	return false;
}

bool CPhysicsStrategy_Ode::AddStaticTrimesh(const CGameObject* GameObject)
{
	CORE_THROW("CPhysicsStrategy_Ode::AddCone not supported", "");
	return false;

	//if(!ValidateProfile(GameObject))
	//	return -1;

	//EntityInformer ei(Profile->GameObject->Entity, Profile->GameObject->Node->_getFullTransform());
	//Geometry* geom = ei.createStaticTriangleMesh(m_World, m_SpaceMain);
 //   BoxMass mass(1.0, ei.getSize());
 //   //mass.setDensity(5.0, ei.getSize());
 //   Profile->GameObject->Entity->setUserAny(Any(geom));
	//m_Geometries.push_back(geom);
	//return m_Geometries.size() - 1;
}

bool CPhysicsStrategy_Ode::AddTrimesh(const CGameObject* GameObject)
{
	// Create a body associated with the node we created
    Body* body = new Body(m_World);
	GameObject->Node->attachObject(body);

	EntityInformer ei(GameObject->Entity, GameObject->Node->_getFullTransform());
	Geometry* geom = ei.createStaticTriangleMesh(m_World, m_SpaceMain);

    BoxMass mass(1.0, ei.getSize());
    mass.setDensity(1.0, ei.getSize());
    body->setMass(mass);

	// Tie the collision geometry to the physical body
    geom->setBody(body);
    geom->SetCustomData((void*)GameObject);
	geom->SetBodyType(GameObject->PhysicsProfile->GetBodyType());

	AddToContainer(GameObject, body, geom);
	return (body && geom);
}

bool CPhysicsStrategy_Ode::AddInfinitePlane(Plane* plane)
{
	if(!plane)
		plane = new Plane(Vector3(0, 1, 0), 0);

	auto geom = new InfinitePlaneGeometry(*plane, m_World, m_World->getDefaultSpace());
	if(geom)
		geom->SetBodyType(TERRAIN);

	return geom != nullptr;
}

void CPhysicsStrategy_Ode::SetEnabled(const CGameObject* GameObject, bool IsEnabled)
{
	auto gemoContainer = m_Containers.find(GameObject);
	if(gemoContainer != m_Containers.end())
	{
		if(IsEnabled)
			gemoContainer->second.Body->isAwake();
		else
			gemoContainer->second.Body->sleep();
	}
}

void CPhysicsStrategy_Ode::SetPosition(const CGameObject* GameObject, const Vector3 Position)
{
	auto it = m_Containers.find(GameObject);
	if(it != m_Containers.end())
	{
		auto body = (*it).second.Body;
		body->sleep();
		body->setPosition(Position);
		body->wake();
	}
}

void CPhysicsStrategy_Ode::AddForceAt(const CGameObject* GameObject, const Vector3& Force,const Vector3& Position)
{
	auto it = m_Containers.find(GameObject);
	if(it != m_Containers.end())
	{
		auto body = (*it).second.Body;
		body->addForceAt(Force, Position);
	}
}

Vector3 CPhysicsStrategy_Ode::RaycastClosestShape(const Vector3& From, const Vector3& To, SPhysicsRayCastReport& RayCastReport)
{
	RayCastReport.Position = INVALID_POS;

	// Ray's are caught when collision tests are made in the stepper
	auto rayGeom = new RayGeometry(From.distance(To), m_World, m_SpaceRay);
	m_ClosestRayCollisionListener->OriginPoint = From;
	
	if(rayGeom)
	{
		Vector3 delta = From - To;
		rayGeom->setDefinition(From, delta.normalisedCopy());
		rayGeom->setCustomListener(m_ClosestRayCollisionListener);
		m_SpaceRay->collide(m_SpaceMain);

		auto report = rayGeom->GetRayCastReport();
		if(report)
		{
			RayCastReport.BodyType = report->BodyType;
			RayCastReport.Data = report->Data;
			RayCastReport.Position = report->Position;

			// Reset the listener
			m_ClosestRayCollisionListener->ClosestPoint = INVALID_POS;
		}
		delete rayGeom;
	}
	
	return RayCastReport.Position;
}

Vector3 CPhysicsStrategy_Ode::RaycastClosestType(const Vector3& From, const Vector3& To, E_BODY_TYPE Type, SPhysicsRayCastReport& RayCastReport)
{
	// Not finishing it for now.  I think the best way to do this is to assign a space per different E_BODY_TYPE, so a ray cast can be done
	// on that specific space.
	return INVALID_POS;
}

void* CPhysicsStrategy_Ode::AddTerrain(const Vector3 &scale, s32 nodes_per_sideX, s32 nodes_per_sideY, f32 worldSizeX, f32 worldSizeZ, bool centered, f32 thickness)
{
	TerrainGeometry* terrain = new TerrainGeometry(m_World,
        m_World->getDefaultSpace(), 
        scale,
        nodes_per_sideX,
        nodes_per_sideY,
        worldSizeX, 
        worldSizeZ,
        centered,
		thickness);
	return terrain;
}

void* CPhysicsStrategy_Ode::AddTerrain(TerrainGroup* terrainGroup)
{
	auto it = terrainGroup->getTerrainIterator();
	while(it.hasMoreElements())
	{
		Terrain* terrainPage = it.getNext()->instance;
		if(terrainPage)
		{
			PagedTerrainGeometry* terrain = new PagedTerrainGeometry(m_World, m_World->getDefaultSpace(), terrainPage, terrainGroup);
			if(terrain)
				terrain->SetBodyType(TERRAIN);
		}
	}
	return terrainGroup;
}

void CPhysicsStrategy_Ode::SetCollisionListener(void* Listener)
{
	m_World->clearContacts();
	m_World->setCollisionListener((CollisionListener*)Listener);
}

void* CPhysicsStrategy_Ode::LoadPrefabVehicle(const char* FileName, const char* VehicleName)
{
	if(!m_DotLoader)
		m_DotLoader = new DotLoader(m_World);

	auto obj = m_DotLoader->loadObject(FileName, VehicleName);

	Vehicle* vehicle = nullptr;
	if(obj)
	{
		auto vehicle = static_cast<Vehicle*>(obj);
		m_Vehicles.push_back(vehicle);
	}

	return vehicle;
}

IPhysicsRagdoll* CPhysicsStrategy_Ode::CreateRagdoll(CPlayer* Player, const CRagdollBoneInformation& RagdollBoneInformation) 
{ 
	if(!m_DotLoader)
		m_DotLoader = new DotLoader(m_World);

	auto ragdoll = new CPhysicsRagdoll_Ode(Player, m_World, m_DotLoader, RagdollBoneInformation);
    if(ragdoll)
	{
		m_Ragdolls.push_back(ragdoll);
		return ragdoll;
	}

	return nullptr; 
}

ICharacterController* CPhysicsStrategy_Ode::CreateCharacterController(CPlayer* Player)
{
	auto cc = new CCharacterController_Ode(Player, m_SpaceMain);
	if(cc)
	{
		cc->InitCharacterControllers();
		m_CharacterControllers.push_back(cc);
		return cc;
	}
	return nullptr;
}

void CPhysicsStrategy_Ode::RemoveCharacterController(ICharacterController* CharacterController)
{
	auto it = find(m_CharacterControllers.cbegin(), m_CharacterControllers.cend(), CharacterController);
	if(it != m_CharacterControllers.cend())
	{
		m_CharacterControllers.erase(it);
		delete CharacterController;
	}
}

void CPhysicsStrategy_Ode::RemoveRagdoll(IPhysicsRagdoll* Ragdoll)
{
	auto it = find(m_Ragdolls.cbegin(), m_Ragdolls.cend(), Ragdoll);
	if(it != m_Ragdolls.cend())
	{
		m_Ragdolls.erase(it);
		delete Ragdoll;
	}
}

void CPhysicsStrategy_Ode::ShowDebug(bool Debug)
{
#ifdef _DEBUG
	if(m_World)
		m_World->setShowDebugGeometries(Debug);
	isDebug = Debug;
#endif
}

void CPhysicsStrategy_Ode::Update(const f32& elapsedTime)
{
	// Update the world
	if (m_Stepper->step(elapsedTime))
	{
       m_World->synchronise();
	}

	// Update ragdolls
	for (auto it = m_Ragdolls.cbegin(); it != m_Ragdolls.cend(); ++it)
    {
		(*it)->Update(elapsedTime);
    }
}

void CPhysicsStrategy_Ode::DestroyPhysicsBody(const CGameObject* GameObject)
{
	if(GameObject)
	{
		auto body = m_Containers.find(GameObject);
		if(body != m_Containers.end())
		{
			m_Containers.erase(body);
		}
	}
}

bool CPhysicsStrategy_Ode::UpdatePhysicsBody(const CGameObject* GameObject)
{
	if(GameObject)
	{
		// Check to make sure the profile was added first
		auto gemoContainer = m_Containers.find(GameObject);
		if(gemoContainer != m_Containers.end())
		{
			// Get the profile to update
			auto profile = GameObject->PhysicsProfile;
			if(profile)
			{
				// Update basic settings
				if(profile->IsBasicDirty())
				{
					// Easier to just destory the shape and create a new one
					DestroyPhysicsBody(GameObject);
					if(AddShape(GameObject))
					{
						gemoContainer = m_Containers.find(GameObject);
						if(gemoContainer != m_Containers.end())
							return false;
					}
				}

				// Update disabling settings
				if(profile->IsDisabledDirty())
				{
					gemoContainer->second.Body->setAutoSleepLinearThreshold(profile->GetAutoDisableLinearThreshold());
					gemoContainer->second.Body->setAutoSleepAngularThreshold(profile->GetAutoDisableAngularThreshold());
					gemoContainer->second.Body->setAutoSleepTime(profile->GetAutoDisableTime());
					gemoContainer->second.Body->setAutoSleepSteps(profile->GetAutoDisableSteps());
				}

				// Update damping settings
				if(profile->IsDampingDirty())
				{
					gemoContainer->second.Body->setDamping(profile->GetLinearDamping(), profile->GetAngularDamping());
					gemoContainer->second.Body->setLinearDampingThreshold(profile->GetLinearDampingThreshold());
					gemoContainer->second.Body->setAngularDampingThreshold(profile->GetAngularDampingThreshold());
					gemoContainer->second.Body->setMaxAngularSpeed(profile->GetMaxAngularSpeed());
				}

				// Update dynamic settings
				if(profile->IsDampingDirty())
				{
					Vector3 vec;

					profile->GetForce(vec);
					gemoContainer->second.Body->addForce(vec);

					profile->GetTorque(vec);
					gemoContainer->second.Body->addTorque(vec);

					profile->GetRelativeForce(vec);
					gemoContainer->second.Body->addRelativeForce(vec);

					profile->GetRelativeTorque(vec);
					gemoContainer->second.Body->addRelativeTorque(vec);

					gemoContainer->second.Body->setLinearDampingThreshold(profile->GetLinearDampingThreshold());
					gemoContainer->second.Body->setAngularDampingThreshold(profile->GetAngularDampingThreshold());
					gemoContainer->second.Body->setMaxAngularSpeed(profile->GetMaxAngularSpeed());
				}

				// Reset the profile change settings
				profile->ResetDirty();
			}
		}
	}
	return nullptr;
}

bool CPhysicsStrategy_Ode::UpdateWorld(const CWorldProfile* WorldProfile)
{
	if(!m_World || !WorldProfile)
		return false;

	//WorldProfile->Bounds

	m_World->setDamping(WorldProfile->LinearDamping, WorldProfile->AngularDamping);
	m_World->setGravity(WorldProfile->Gravity);
	m_World->setContactSurfaceLayer(WorldProfile->ContactSurfaceLayer);
	m_World->setContactCorrectionVelocity(WorldProfile->ContactCorrectionVelocity);
	m_World->SetMaxAngularSpeed(WorldProfile->MaxAngularSpeed);

	return true;
}

Vector3 CPhysicsStrategy_Ode::GetBoundingBox(const SceneNode* Node, Entity* entity) const
{
	EntityInformer ei(entity, Node->_getFullTransform());
	return ei.getSize();
}

f32 CPhysicsStrategy_Ode::GetBoundingRadius(const Entity* entity) const
{
	AxisAlignedBox aab = entity->getBoundingBox(); 
	Vector3 min = aab.getMinimum();
	Vector3 max = aab.getMaximum();
	Vector3 size(fabs(max.x - min.x), fabs(max.y - min.y), fabs(max.z - min.z));
	f32 radius = (size.x > size.z) ? size.z / 2.0f : size.x / 2.0f;
	return radius;
}

void CPhysicsStrategy_Ode::AddToContainer(const CGameObject* GameObject, Body* Body, Geometry* Geom)
{
	if(m_Containers.find(GameObject) == m_Containers.end())
	{
		GemoContainer container;
		container.Body = Body;
		container.Geometry = Geom;
		m_Containers[GameObject] = container;
	}
}

// Check to ensure the physics profile is full and correct
bool CPhysicsStrategy_Ode::ValidateProfile(const CGameObject* GameObject) const
{		
	#ifdef _DEBUG
	if(!GameObject->PhysicsProfile)
	{
		CORE_THROW("Invalid physics profile.", "CPhysicsStrategy_Ode::ValidateProfile");
		return false;
	}
	else
	{
		if(GameObject->PhysicsProfile->GetDensity() <= 0.0)
		{
			CORE_THROW("ODE requires a density to be specified.", "CPhysicsStrategy_Ode::ValidateProfile");
			return false;
		}
		else if(GameObject->PhysicsProfile->GetMass() <= 0.0)
		{
			CORE_THROW("ODE requires a mess to be specified.", "CPhysicsStrategy_Ode::ValidateProfile");
			return false;
		}
	}
	#else
	if(!GameObject->PhysicsProfile)
	{
		return false;
	}
	#endif

	// Check Size and Radius
	if(GameObject->PhysicsProfile->GetRadius() == DEFAULT_PROFILE_RADIUS)
	{
		EntityInformer ei(GameObject->Entity, GameObject->Node->_getFullTransform());
		GameObject->PhysicsProfile->SetRadius(ei.getRadius());
	}
	
	if(GameObject->PhysicsProfile->GetSize() == DEFAULT_PROFILE_SIZE)
	{
		EntityInformer ei(GameObject->Entity, GameObject->Node->_getFullTransform());
		GameObject->PhysicsProfile->SetSize(ei.getSize());
	}

	return true;
}
