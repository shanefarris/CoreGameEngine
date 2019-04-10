#if COMPILE_BULLET

#include "CPhysicsStrategy_Bullet.h"
#include "CGameManager.h"
#include "OgreBulletCollisionsShape.h"
#include "Utils/OgreBulletCollisionsMeshToShapeConverter.h"
#include "Shapes/OgreBulletCollisionsBoxShape.h"
#include "Shapes/OgreBulletCollisionsSphereShape.h"
#include "Shapes/OgreBulletCollisionsCylinderShape.h"
#include "Shapes/OgreBulletCollisionsConeShape.h"

using namespace Core;
using namespace Core::Physics;

CPhysicsStrategy_Bullet::CPhysicsStrategy_Bullet() :  m_World(0), m_SceneManager(0)
{
	Initialize();
}

CPhysicsStrategy_Bullet::~CPhysicsStrategy_Bullet()
{

}

void CPhysicsStrategy_Bullet::Initialize()
{
	CGameManager* GameManager = CGameManager::Instance();
	m_SceneManager = GameManager->GetSceneManager();
}

void CPhysicsStrategy_Bullet::InitWorld(const reVector3Df &Gravity, const AxisAlignedBox& Bounds)
{
	// Start Bullet
    m_World = new DynamicsWorld(m_SceneManager, Bounds, Gravity);

    // add Debug info display tool
    //DebugDrawer *debugDrawer = new DebugDrawer();
    //m_World->setDebugDrawer(debugDrawer);
    //SceneNode *node = m_SceneManager->getRootSceneNode()->createChildSceneNode("debugDrawer", Vector3::ZERO);
    //node->attachObject (static_cast <SimpleRenderable *> (debugDrawer));
	NumOfShapes = 0;
}

void CPhysicsStrategy_Bullet::AddCube(SceneNode* Node, Entity* entity, const f32 bodyRestitution, const f32 bodyFriction, const f32 bodyMass)
{
    BoxCollisionShape* sceneCubeShape = new BoxCollisionShape(GetBoundingBox(entity));
	RigidBody* defaultBody = new RigidBody("defaultCubeRigid" + StringConverter::toString(NumOfShapes), m_World);

	reVector3Df p = entity->getParentNode()->getPosition(); 
	Quaternion q = entity->getParentNode()->getOrientation(); 
    defaultBody->setShape(Node, sceneCubeShape, bodyRestitution, bodyFriction, bodyMass, p, q);

	m_Shapes.push_back(sceneCubeShape);
    m_Bodies.push_back(defaultBody);
	NumOfShapes++;
}

void CPhysicsStrategy_Bullet::AddSphere(SceneNode* Node, Entity* entity, const f32 bodyRestitution, const Real bodyFriction, const f32 bodyMass)
{
	SphereCollisionShape* sceneCubeShape = new SphereCollisionShape(GetBoundingRadius(entity));
    RigidBody *defaultBody = new RigidBody("defaultSphereRigid" + StringConverter::toString(NumOfShapes), m_World);

	reVector3Df p = entity->getParentNode()->getPosition(); 
	Quaternion q = entity->getParentNode()->getOrientation(); 
    defaultBody->setShape(Node, sceneCubeShape, bodyRestitution, bodyFriction, bodyMass, p, q);

    m_Shapes.push_back(sceneCubeShape);
    m_Bodies.push_back(defaultBody);
}

void CPhysicsStrategy_Bullet::AddCylinder(SceneNode* Node, Entity* entity, const f32 bodyRestitution, const f32 bodyFriction, 
										const f32 bodyMass)
{
	reVector3Df size = GetBoundingBox(entity);
    CylinderCollisionShape *sceneCubeShape = new CylinderCollisionShape(size, reVector3Df::UNIT_X);
    RigidBody *defaultBody = new RigidBody("defaultCylinderRigid" + StringConverter::toString(NumOfShapes), m_World);

	reVector3Df p = Node->getPosition(); 
	Quaternion q = Node->getOrientation(); 
    defaultBody->setShape(Node, sceneCubeShape, bodyRestitution, bodyFriction, bodyMass, p, q);

    m_Shapes.push_back(sceneCubeShape);
    m_Bodies.push_back(defaultBody);
}

void CPhysicsStrategy_Bullet::AddCone(SceneNode* Node, Entity* entity, const f32 bodyRestitution, const f32 bodyFriction, 
									const f32 bodyMass)
{
	reVector3Df size = GetBoundingBox(entity);
    ConeCollisionShape *sceneCubeShape = new ConeCollisionShape(size.x, size.y, reVector3Df::UNIT_Y);
    RigidBody *defaultBody = new RigidBody("defaultConeRigid" + StringConverter::toString(NumOfShapes), m_World);

	reVector3Df p = Node->getPosition(); 
	Quaternion q = Node->getOrientation(); 
    defaultBody->setShape(Node, sceneCubeShape, bodyRestitution, bodyFriction, bodyMass, p, q);

    m_Shapes.push_back(sceneCubeShape);
    m_Bodies.push_back(defaultBody);
}

void CPhysicsStrategy_Bullet::AddStaticTrimesh(SceneNode* Node, Entity* entity, const f32 bodyRestitution, 
												const f32 bodyFriction)
{
    StaticMeshToShapeConverter *trimeshConverter = new StaticMeshToShapeConverter(entity);
    TriangleMeshCollisionShape *sceneTriMeshShape = trimeshConverter->createTrimesh();
    delete trimeshConverter;

	reVector3Df p = entity->getParentNode()->getPosition(); 
    RigidBody* sceneRigid = new RigidBody("Rigid" + StringConverter::toString(NumOfShapes), m_World);
    sceneRigid->setStaticShape(Node, (CollisionShape*)sceneTriMeshShape, bodyRestitution, bodyFriction, p);

    m_Shapes.push_back(sceneTriMeshShape);
    m_Bodies.push_back(sceneRigid);
}

void CPhysicsStrategy_Bullet::Update(f32 elapsedTime)
{
	m_World->stepSimulation(elapsedTime);
}

reVector3Df CPhysicsStrategy_Bullet::GetBoundingBox(Entity* entity)
{
	AxisAlignedBox ebb = entity->getBoundingBox();
    ebb.scale(reVector3Df(0.49, 0.49, 0.49));

    return ebb.getMaximum() - ebb.getMinimum();
}

f32 CPhysicsStrategy_Bullet::GetBoundingRadius(Entity* entity)
{
	return entity->getBoundingRadius();
}

#endif