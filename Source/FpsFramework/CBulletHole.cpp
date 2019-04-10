#include "CBulletHole.h"
#include "CGameManager.h"
#include "CoreStructures.h"

#include "OgrePlane.h"
#include "OgreStringConverter.h"
#include "OgreMeshManager.h"
#include "OgreResourceManager.h"
#include "OgreSceneManager.h"
#include "OgreEntity.h"

using namespace Core;

CBulletHoles* CBulletHoles::BulletHoles;

CBulletHoles::CBulletHoles(): m_BulletHoleCount(0)
{
}

CBulletHoles* CBulletHoles::Instance()
{
	if(!BulletHoles)
		BulletHoles = new CBulletHoles();
	return BulletHoles;
}

void CBulletHoles::AddBulletHole(const Vector3& Normal, const Vector3& Position)
{
	f32 mBulletHoleSize = 10.0;

	//Creates the plane.
	Ogre::Plane plane(Normal, 0.001f);

	//The name of the plane.
	String name = "bulletHole_" + Ogre::StringConverter::toString(m_BulletHoleCount);

	//An up vector has to be defined. Using a vector that is perpendicular to the normal.
	Vector3 upVector = Normal.perpendicular();

	//Creates a mesh from the earlier created plane.
	MeshManager::getSingleton().createPlane(name, 
		ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, plane, mBulletHoleSize, mBulletHoleSize, 20, 20, true, 1, 1, 1, upVector);

	//Creates an entity from the mesh and attaches it to a scene node.
	Entity* entity = CGameManager::Instance()->GetSceneManager()->createEntity(name + "entity", name);
	entity->setQueryFlags(SQF_EFFECT);
	CGameManager::Instance()->GetSceneManager()->getRootSceneNode()->createChildSceneNode(Position)->attachObject(entity);
	entity->setMaterialName("BulletHole");
	entity->setCastShadows(false);

	m_BulletHoleCount++;
	
}
