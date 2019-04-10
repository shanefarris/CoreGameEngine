#include "World.h"
#include "Body.h"
#include "Joint.h"
#include "Geometry.h"
#include "Space.h"
#include "DebugObject.h"

#include "OgreSceneNode.h"

using namespace Ode;
using namespace Ogre;

CollisionListener* World::_collision_listener = 0;

void World::setCollisionListener(CollisionListener* collision_listener)
{
	_collision_listener = collision_listener;
}

CollisionListener* World::getCollisionListener()
{
	return _collision_listener;
}

World::World(SceneManager* manager) : _show_debug_geoms (false),  _show_debug_contact (false), _manager (manager)
{
	dInitODE2(0);
	dAllocateODEDataForThread(dAllocateMaskAll);

	_world = dWorldCreate();
	_contacts = dJointGroupCreate(0);

	_default_space = new HashTableSpace(this);
	_default_space->setAutoCleanup(false);
	_default_space->setInternalCollisions(true);

	setDamping(0.0, 0.0);
	setHistorySize (1);
}

void World::setHistorySize(size_t historySize)
{
	_history_size = historySize;
	for(auto it = _body_list.begin(); it != _body_list.end(); it++)
	{
		Body * const b = (*it).second;
		b->_historyResize(historySize);
	}
}

size_t World::getHistorySize() const 
{
	return _history_size;
}

void World::setGravity(const Vector3& gravity)
{
	dWorldSetGravity(_world,(dReal)gravity.x,(dReal)gravity.y,(dReal)gravity.z);
}

const Vector3& World::getGravity()
{
	dVector3 g;
	dWorldGetGravity(_world,g);
	_gravity.x = (Real)g[0];
	_gravity.y = (Real)g[1];
	_gravity.z = (Real)g[2];
	return _gravity;
}

void World::setERP(const f32& erp)
{
	dWorldSetERP(_world,(dReal)erp);
}

Real World::getERP()
{
	return (Real)dWorldGetERP(_world);
}

void World::setCFM(const f32& cfm)
{
	dWorldSetCFM(_world,(dReal)cfm);
}

Real World::getCFM()
{
	return (Real)dWorldGetCFM(_world);
}

void World::setAutoSleep(bool auto_sleep)
{
	dWorldSetAutoDisableFlag(_world, (auto_sleep) ? 1 : 0);
}

bool World::getAutoSleep()
{
	return (dWorldGetAutoDisableFlag(_world)) ? true : false;
}

void World::setAutoSleepLinearThreshold(const f32& linear_threshold)
{
	dWorldSetAutoDisableLinearThreshold(_world,(dReal)linear_threshold);
}

Real World::getAutoSleepLinearThreshold()
{
	return (Real)dWorldGetAutoDisableLinearThreshold(_world);
}

void World::setAutoSleepAngularThreshold(const f32& angular_threshold)
{
	dWorldSetAutoDisableAngularThreshold(_world,(dReal)angular_threshold);
}

Real World::getAutoSleepAngularThreshold()
{
	return (Real)dWorldGetAutoDisableAngularThreshold(_world);
}

void World::setAutoSleepSteps(int steps)
{
	dWorldSetAutoDisableSteps(_world,steps);
}

int World::getAutoSleepSteps()
{
	return dWorldGetAutoDisableSteps(_world);
}

void World::setAutoSleepTime(const f32& time)
{
	dWorldSetAutoDisableTime(_world,(dReal)time);
}

f32 World::getAutoSleepTime()
{
	return (f32)dWorldGetAutoDisableTime(_world);
}

void World::setAutoSleepAverageSamplesCount(unsigned int time)
{
    dWorldSetAutoDisableAverageSamplesCount(_world, time);
}

int World::getAutoSleepAverageSamplesCount()
{
    return dWorldGetAutoDisableAverageSamplesCount(_world);
}

void World::setContactCorrectionVelocity(const f32& velocity)
{
	dWorldSetContactMaxCorrectingVel(_world,(dReal)velocity);
}

f32 World::getContactCorrectionVelocity()
{
	return (f32)dWorldGetContactMaxCorrectingVel(_world);
}

void World::setContactSurfaceLayer(const f32& layer)
{
	dWorldSetContactSurfaceLayer(_world,(dReal)layer);
}

f32 World::getContactSurfaceLayer()
{
	return (f32)dWorldGetContactSurfaceLayer(_world);
}

void World::collisionCallback(void *data, dGeomID geom_a, dGeomID geom_b)
{
	const bool a_space = (dGeomIsSpace(geom_a))?true:false;
	const bool b_space = (dGeomIsSpace(geom_b))?true:false;
	
	void* const ptr_a = dGeomGetData(geom_a);
	void* const ptr_b = dGeomGetData(geom_b);

	if(a_space  || b_space )
	{
		// Collide a space with a space
		if(a_space && b_space) 
			static_cast<Space*>(ptr_a)->collide(static_cast<Space*>(ptr_b),data);
		else if(a_space) 
			static_cast<Space*>(ptr_a)->collide(static_cast<Geometry*>(ptr_b),data);
		else 
			static_cast<Space*>(ptr_b)->collide(static_cast<Geometry*>(ptr_a),data);

		// Collide geometries internal to the spaces
		if(a_space) 
            static_cast<Space*>(ptr_a)->collide(data);

		if(b_space) 
            static_cast<Space*>(ptr_b)->collide(data);
	}
    else
	{
		// Collide a geom with a geom, i.e. generate contacts
		static_cast<Geometry*>(ptr_a)->collide(static_cast<Geometry*>(ptr_b),_collision_listener);
	}
}

Body* World::findBody(SceneNode* node)
{
	Body* body = 0;
	for(int i = 0;i < node->numAttachedObjects();i++)
	{
		MovableObject* obj = node->getAttachedObject(i);
		if(obj)
		{
			if(obj->getMovableType() == Ogre::String("Ode::Body"))
			{
				body = static_cast<Body*>(obj);
				break;
			}
		}
	}
	return body;
}

Body* World::findBody(const String& name)
{
	for(auto it = _body_list.cbegin(); it != _body_list.cend(); it++)
	{
		if((*it).second->getName() == name) 
			return (*it).second;
	}
	return nullptr;
}

void World::setDefaultSpace(Space* space)
{
	delete _default_space;
	_default_space = space;
}

void World::setQuickStepIterations(int iterations)
{
	dWorldSetQuickStepNumIterations(_world,iterations);
}

int World::getQuickStepIterations()
{
	return dWorldGetQuickStepNumIterations(_world);
}

void World::setShowDebugGeometries(bool show)
{
	for(auto it = _body_list.begin(); it != _body_list.end(); it++)
		(*it).second->setDebug(show);

	for(auto it = _geometry_list.begin(); it != _geometry_list.end(); it++)
		(*it).second->setDebug(show);

	_show_debug_geoms = show;
}

void World::setShowDebugContact(bool show)
{
	for(auto it = _geometry_list.begin(); it != _geometry_list.end(); it++)
		(*it).second->setDebugContact(show);

    _show_debug_contact = show;
}

void World::setDamping(const f32& linear_damping, const f32& angular_damping)
{
	_linear_damping = -linear_damping;
	_angular_damping = -angular_damping;
	dWorldSetDamping(_world, (dReal)_linear_damping, (dReal)_angular_damping);
}

f32 World::getLinearDamping()
{
	return -_linear_damping;
}

f32 World::getAngularDamping()
{
	return -_angular_damping;
}

f32 getLinearDampingThreshold();
f32 setAngularDampingThreshold();
void setLinearDampingThreshold(const f32& Threshold);
void setAngularDampingThreshold(const f32& Threshold);

f32  World::GetMaxAngularSpeed()
{
	return (f32)dWorldGetMaxAngularSpeed(_world);
}

void World::SetMaxAngularSpeed(const f32& max_speed)
{
	dWorldSetMaxAngularSpeed(_world, max_speed);
}

World::~World()
{
	delete _default_space;
	dJointGroupDestroy(_contacts);
    dWorldDestroy(_world);
    dCloseODE();
}

dWorldID World::getWorldID()
{
    return _world;
}

dJointGroupID World::getContactGroupID()
{
    return _contacts;
}

void World::notifyGeometry(Body* body)
{
	for(auto it = _geometry_list.begin(); it != _geometry_list.end(); it++)
		(*it).second->notify(body);
}

void World::synchronise()
{
	for(auto it = _body_list.begin(); it != _body_list.end(); it++)
		(*it).second->synchronise();
}

void World::updateDrawState()
{
	for(auto it = _body_list.begin(); it != _body_list.end(); it++)
		(*it).second->updateDrawState();

    if (_show_debug_contact)
	{
		for(auto it = _geometry_list.begin(); it != _geometry_list.end(); it++)
			(*it).second->updateDebugContact();
	}
}

void World::interpolateDrawState(const f32& alpha)
{
	for(auto it = _body_list.begin(); it != _body_list.end(); it++)
		(*it).second->interpolateDrawState(alpha);

    if (_show_debug_contact)
	{
		for(auto it = _geometry_list.begin(); it != _geometry_list.end(); it++)
			(*it).second->updateDebugContact();
	}
}

void World::updatePreviousState()
{
	for(auto it = _body_list.begin(); it != _body_list.end(); it++)
		(*it).second->updatePreviousState();
}

void World::updateCurrentState()
{
	for(auto it = _body_list.begin(); it != _body_list.end(); it++)
		(*it).second->updateCurrentState();
}

void World::clearContacts()
{
    dJointGroupEmpty(_contacts);
}

void World::step(const f32& stepsize)
{
    dWorldStep(_world,(dReal)stepsize); 
}

void World::quickStep(const f32& stepsize)
{
    dWorldQuickStep(_world,(dReal)stepsize);
}

void World::AddBody(Body* body) 
{
	assert(body->getBodyID());
	_body_list[body->getBodyID()] = body;
}

void World::RemoveBody(dBodyID BodyId) 
{
	if(_body_list.find(BodyId) != _body_list.end())
		_body_list.erase(BodyId);
}

void World::AddJoint(Joint* join)
{
	assert(join->getJointID());
	_joint_list[join->getJointID()] = join;
}

void World::RemoveJoint(dJointID JoinId)
{
	if(_joint_list.find(JoinId) != _joint_list.end())
		_joint_list.erase(JoinId);
}

Joint* World::GetJoint(dJointID JoinId)
{
	if(_joint_list.find(JoinId) != _joint_list.end())
		_joint_list.find(JoinId)->second;
	return nullptr;
}

void World::AddJoinGroup(JointGroup* joinGroup)
{
	assert(joinGroup->getJointGroupID());
	_joint_group_list[joinGroup->getJointGroupID()] = joinGroup;
}

void World::RemoveJoinGroup(dJointGroupID JoinGroupId)
{
	if(_joint_group_list.find(JoinGroupId) != _joint_group_list.end())
		_joint_group_list.erase(JoinGroupId);
}

void World::AddGeometry(Geometry* geometry)
{
	assert(geometry->getGeometryID());
	_geometry_list[geometry->getGeometryID()] = geometry;
}

void World::RemoveGeometry(dGeomID GeometryId)
{
	if(_geometry_list.find(GeometryId) != _geometry_list.end())
		_geometry_list.erase(GeometryId);
}

Geometry* World::GetGeometry(dGeomID GeometryId)
{
	if(_geometry_list.find(GeometryId) != _geometry_list.end())
		_geometry_list.find(GeometryId)->second;
	return nullptr;
}

void World::AddSpace(Space* space)
{
	assert(space->getSpaceID());
	_space_list[space->getSpaceID()] = space;
}

void World::RemoveSpace(dSpaceID SpaceId)
{
	if(_space_list.find(SpaceId) != _space_list.end())
		_space_list.erase(SpaceId);
}

Space* World::GetSpace(dSpaceID SpaceId)
{
	if(_space_list.find(SpaceId) != _space_list.end())
		_space_list.find(SpaceId)->second;
	return nullptr;
}
