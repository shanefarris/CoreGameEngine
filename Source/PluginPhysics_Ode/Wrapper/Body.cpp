#include "World.h"
#include "Body.h"
#include "Mass.h"
#include "DebugObject.h"
#include "Geometry.h"

#include "OgreSceneNode.h"
#include "OgreSceneManager.h"
#include "OgreAxisAlignedBox.h"
#include "OgreMovableObject.h"
#include "OgreStringConverter.h"

using namespace Ode;
using namespace Ogre;

BodyState::BodyState(const Vector3	&position, const Quaternion &orientation)
{
    _position = position;
    _orientation = orientation;	
}

void BodyState::operator=(const BodyState &other)
{
    _position = other._position;
    _orientation = other._orientation;
}

bool BodyState::operator==(const BodyState &other) const
{
    return _position == other._position && 
        _orientation == other._orientation;			
}

bool BodyState::operator!=(const BodyState &other) const
{
    return _position != other._position || 
        _orientation != other._orientation;
} 

bool BodyState::isDifferent(const BodyState &other, const f32 threshold) const
{
    return (other._position-_position).squaredLength() > threshold || 
        (other._orientation-_orientation).normalise() > threshold;
}

void BodyState::interpolate(const BodyState * const _previous_state, const BodyState * const _current_state, const f32 alpha)
{
    const f32 timeDiffuseless = f32(0.0001);
    if (alpha - timeDiffuseless < 0) // alpha <= 0
    {	
        _position = _current_state->_position;
        _orientation = _current_state->_orientation;			
    }
    else if (alpha - 1 - timeDiffuseless > 0) // alpha >= 1
    {	
        _position = _previous_state->_position;
        _orientation = _previous_state->_orientation;	
    }
    else
#if _DEBUG 
    if (_previous_state->isDifferent(*_current_state, f32(0.01)))
    {        
        _position = _current_state->_position*alpha + _previous_state->_position * (1.0f - alpha);
        _orientation = Quaternion::Slerp(alpha, _previous_state->_orientation, _current_state->_orientation, true); //shortest path ?				
    }
    else
    {
        _position = _previous_state->_position;
        _orientation = _previous_state->_orientation;
    }
#else
    {
        _position = _current_state->_position*alpha + _previous_state->_position * (1.0f - alpha);
        _orientation = Quaternion::Slerp(alpha, _previous_state->_orientation, _current_state->_orientation, true); //shortest path ?				
    }
#endif
}

//-----------------------------------------------------------------------
int Body::_body_count = 0;
const String Body::MovableType = "Ode::Body";

Body::Body(World *world, const String& name): MovableObject(), _name(name), _world(world), _modify_parent_orientation(true)
{ 
	_body_count++;
	_body = dBodyCreate(_world->getWorldID()); 
	
	_debug_node = 0;
	_mass = new Mass(); 

	dBodySetData(_body,(void*)this);
	_world->AddBody(this);

	if (_name.empty())
		_name = MovableType + StringConverter::toString(_body_count);

	setDamping (_world->_linear_damping, 
				_world->_angular_damping);
	_user_data = 0;
	
	_isEnabled = true;
    _historyResize(_world->getHistorySize());
    // Tie the physical body to the movable used when getting physical out of Movables. 
    this->setUserAny (Any(this));

}

void Body::_historyResize(const size_t size)
{
	_state_history.resize (size);
	for (size_t i = 0; i < size; i++)
	{
		_state_history.add(new BodyState (_draw_state));
	}
}

void Body::_notifyAttached(Node* parent, bool isTagPoint)
{
    MovableObject::_notifyAttached(parent,isTagPoint);
    if (parent)
    {
        Body* other_body = _world->findBody(static_cast<SceneNode*>(parent));
        if ((other_body) && (other_body != this))
        {
            static_cast<SceneNode*>(parent)->detachObject(other_body);

        }

        setPosition(parent->getPosition());
        setOrientation(parent->getOrientation());
    } 
}

void Body::destroyDebugNode()
{
	if (_debug_node)
	{
		_world->notifyGeometry(this);

        SceneNode* sn = static_cast<SceneNode*>(_debug_node);
        sn->removeAndDestroyAllChildren ();
        sn = static_cast<SceneNode*>(_debug_node->getParent());
        sn->removeAndDestroyChild(_debug_node->getName());
		_debug_node = 0;
	}
}

void Body::addDebugNode(Node* node)
{
	if (!_debug_node)
	{
		_debug_node = _world->_manager->getRootSceneNode()->createChild(_name + String("_DebugBody"));
	}
   
    _debug_node->addChild(node);
   
}

void Body::setModifyParentOrientation(bool bModify)
{
	_modify_parent_orientation = bModify;
} 

void Body::setPosition(const Vector3& position)
{
	dBodySetPosition(_body,(dReal)position.x,(dReal)position.y,(dReal)position.z); 

	_draw_state._position = position;
	for (size_t i = 0; i < _state_history.size (); i++)
	{
		_state_history[i]->_position = position;
	}

	if (mParentNode) 
        mParentNode->setPosition(position);
}

void Body::setOrientation(const Quaternion& orientation)
{
	dQuaternion q; 
	q[0] = (dReal)orientation.w;
	q[1] = (dReal)orientation.x;
	q[2] = (dReal)orientation.y;
	q[3] = (dReal)orientation.z;
	dBodySetQuaternion(_body,q); 

	_draw_state._orientation = orientation;
	for (size_t i = 0; i < _state_history.size (); i++)
	{
		_state_history[i]->_orientation = orientation;
	}

	if (mParentNode && _modify_parent_orientation) 
        mParentNode->setOrientation(orientation);
}

void Body::setLinearVelocity(const Vector3& linear_velocity)
{
	dBodySetLinearVel(_body,(dReal)linear_velocity.x,(dReal)linear_velocity.y,(dReal)linear_velocity.z); 
}

void Body::setAngularVelocity(const Vector3& angular_velocity)
{
	dBodySetAngularVel(_body,(dReal)angular_velocity.x,(dReal)angular_velocity.y,(dReal)angular_velocity.z); 
}

void Body::setMaxAngularSpeed(const f32& speed)
{
	dBodySetMaxAngularSpeed(_body, speed);
}

f32 Body::getMaxAngularSpeed()
{
	return (f32)dBodyGetMaxAngularSpeed(_body);
}

const Vector3& Body::getLinearVelocity()
{
	const dReal* linear_velocity = dBodyGetLinearVel(_body); 
	_linear_vel.x = (f32)linear_velocity[0];
	_linear_vel.y = (f32)linear_velocity[1];
	_linear_vel.z = (f32)linear_velocity[2];

	return _linear_vel;
}

const Vector3& Body::getAngularVelocity()
{
	const dReal* angular_velocity = dBodyGetAngularVel(_body); 
	_angular_vel.x = (f32)angular_velocity[0];
	_angular_vel.y = (f32)angular_velocity[1];
	_angular_vel.z = (f32)angular_velocity[2];

	return _angular_vel;
}

const String& Body::getMovableType() const
{
	return MovableType;
}

void Body::_notifyCurrentCamera(Camera* camera)
{
}

const AxisAlignedBox& Body::getBoundingBox(void) const
{
	return _bounding_box;
}

f32 Body::getBoundingRadius(void) const
{
	return 0.0f;
}

void Body::_updateRenderQueue(RenderQueue* queue)
{
}

void Body::setMass(const Mass& mass)
{
	dBodySetMass(_body,mass.getMassPtr());
}

const Mass& Body::getMass()
{
	dMass mass;
	dBodyGetMass(_body,&mass); 
	*_mass = &mass;
	return *_mass;
}

void Body::addForce(const Vector3& force)
{
	dBodyAddForce(_body,(dReal)force.x,(dReal)force.y,(dReal)force.z);
}

void Body::addTorque(const Vector3& torque)
{
	dBodyAddTorque(_body,(dReal)torque.x,(dReal)torque.y,(dReal)torque.z);
}

void Body::addRelativeForce(const Vector3& force)
{
	dBodyAddRelForce(_body,(dReal)force.x,(dReal)force.y,(dReal)force.z);
}

void Body::addRelativeTorque(const Vector3& torque)
{
	dBodyAddRelTorque(_body,(dReal)torque.x,(dReal)torque.y,(dReal)torque.z);
}

void Body::addForceAt(const Vector3& force,const Vector3& position)
{
	dBodyAddForceAtPos(_body,(dReal)force.x,(dReal)force.y,(dReal)force.z,(dReal)position.x,(dReal)position.y,(dReal)position.z); 
}

void Body::addForceAtRelative(const Vector3& force,const Vector3& position)
{
	dBodyAddForceAtRelPos(_body,(dReal)force.x,(dReal)force.y,(dReal)force.z,(dReal)position.x,(dReal)position.y,(dReal)position.z);
}

void Body::addRelativeForceAt(const Vector3& force,const Vector3& position)
{
    dBodyAddRelForceAtPos(_body,(dReal)force.x,(dReal)force.y,(dReal)force.z,(dReal)position.x,(dReal)position.y,(dReal)position.z); 
}

void Body::addRelativeForceAtRelative(const Vector3& force,const Vector3& position)
{
	dBodyAddRelForceAtRelPos(_body,(dReal)force.x,(dReal)force.y,(dReal)force.z,(dReal)position.x,(dReal)position.y,(dReal)position.z); 
}

const Vector3& Body::getForce()
{
	const dReal* force = dBodyGetForce(_body); 
	_force.x = (f32)force[0];
	_force.y = (f32)force[1];
	_force.z = (f32)force[2];

	return _force;
}

const Vector3& Body::getTorque()
{
	const dReal* torque = dBodyGetTorque(_body); 
	_torque.x = (f32)torque[0];
	_torque.y = (f32)torque[1];
	_torque.z = (f32)torque[2];

	return _torque;
}

void Body::setForce(const Vector3& force)
{
    dBodySetForce(_body, (dReal) force.x, (dReal)force.y, (dReal)force.z);
}

void Body::setTorque(const Vector3& torque)
{
    dBodySetTorque(_body, (dReal) torque.x, (dReal)torque.y, (dReal)torque.z);
}

Vector3 Body::getPointWorldPosition(const Vector3& position)
{
	dVector3 result;
	dBodyGetRelPointPos(_body,(dReal)position.x,(dReal)position.y,(dReal)position.z,result);

	return Vector3((f32)result[0], (f32)result[1], (f32)result[2]);
}

Vector3 Body::getPointWorldVelocity(const Vector3& position)
{
	dVector3 result;
	dBodyGetRelPointVel(_body,(dReal)position.x,(dReal)position.y,(dReal)position.z,result);

	return Vector3((f32)result[0], (f32)result[1], (f32)result[2]);
}

Vector3 Body::getPointVelocity(const Vector3& position)
{
	dVector3 result;
	dBodyGetPointVel(_body,(dReal)position.x,(dReal)position.y,(dReal)position.z,result); 

	return Vector3((f32)result[0], (f32)result[1], (f32)result[2]);
}

Vector3 Body::getPointBodyPosition(const Vector3& position)
{
	dVector3 result;
	dBodyGetPosRelPoint(_body,(dReal)position.x,(dReal)position.y,(dReal)position.z,result); 

	return Vector3((f32)result[0], (f32)result[1], (f32)result[2]);
}

Vector3 Body::getVectorToWorld(const Vector3& vector)
{
	dVector3 result;
	dBodyVectorToWorld(_body,(dReal)vector.x,(dReal)vector.y,(dReal)vector.z,result);

	return Vector3((f32)result[0], (f32)result[1], (f32)result[2]);
}

Vector3 Body::getVectorFromWorld(const Vector3& vector)
{
	dVector3 result;
	dBodyVectorFromWorld(_body,(dReal)vector.x,(dReal)vector.y,(dReal)vector.z,result); 

	return Vector3((f32)result[0], (f32)result[1], (f32)result[2]);
}

void Body::wake()
{
	dBodyEnable(_body); 
	_isEnabled = true;
}

void Body::sleep()
{
	dBodyDisable(_body); 
	_isEnabled = false;
}

void Body::setAutoSleep(bool auto_disable)
{
	dBodySetAutoDisableFlag(_body,((auto_disable)?1:0)); 
}

bool Body::getAutoSleep()
{
	return ((dBodyGetAutoDisableFlag(_body))?true:false); 
}

void Body::setAutoSleepLinearThreshold(const f32& linear_threshold)
{
	dBodySetAutoDisableLinearThreshold(_body,(dReal)linear_threshold); 
}

Real Body::getAutoSleepLinearThreshold()
{
	return (Real)dBodyGetAutoDisableLinearThreshold(_body); 
}

void Body::setAutoSleepAngularThreshold(const f32& angular_threshold)
{
	dBodySetAutoDisableAngularThreshold(_body,(dReal)angular_threshold); 
}

Real Body::getAutoSleepAngularThreshold()
{
	return (Real)dBodyGetAutoDisableAngularThreshold(_body); 
}

void Body::setAutoSleepSteps(int steps)
{
	dBodySetAutoDisableSteps(_body,steps); 
}

int Body::getAutoSleepSteps()
{
	return dBodyGetAutoDisableSteps(_body); 
}

void Body::setAutoSleepTime(const f32& time)
{
	dBodySetAutoDisableTime(_body,(dReal)time); 
}

Real Body::getAutoSleepTime()
{
	return (Real)dBodyGetAutoDisableTime(_body); 
}

void Body::setAutoSleepDefaults()
{
	dBodySetAutoDisableDefaults(_body);
}

void Body::setFiniteRotationMode(bool on)
{
	dBodySetFiniteRotationMode(_body,((on)?1:0)); 
}

bool Body::getFiniteRotationMode()
{
	return ((dBodyGetFiniteRotationMode(_body))?true:false); 
}

void Body::setFiniteRotationAxis(const Vector3& axis)
{
	dBodySetFiniteRotationAxis(_body,(dReal)axis.x,(dReal)axis.y,(dReal)axis.z); 
}

const Vector3& Body::getFiniteRotationAxis()
{
	dVector3 result;
	dBodyGetFiniteRotationAxis(_body,result); 
	_finite_axis.x = (f32)result[0];
	_finite_axis.y = (f32)result[1];
	_finite_axis.z = (f32)result[2];

	return _finite_axis;
}

int Body::getJointCount()
{
	return dBodyGetNumJoints(_body); 
}

Joint* Body::getJoint(int index)
{
	return (Joint*)_world->GetJoint(dBodyGetJoint(_body,index)); 
}

size_t Body::getGeometryCount()
{
    return _geometries.size();
}

Geometry* Body::getGeometry(s32 index)
{
	if(_geometries.size() < (size_t)index)
		return nullptr;
    return _geometries[index];
}

GeometryArray* Body::getGeometries()
{
    return &_geometries;
}

void Body::addGeometry(Geometry *g) 
{
    _geometries.push_back(g);
}

void Body::removeGeometry(Geometry *g) 
{
    for (GeometryArray::iterator it = _geometries.begin ();
        it != _geometries.end ();
        ++it)
    {
        if (*it == g)
        {
            _geometries.erase (it);
            return;
        }
    }
}

void Body::setAffectedByGravity(bool on)
{
	dBodySetGravityMode(_body,((on)?1:0)); 
}

bool Body::getAffectedByGravity()
{
	return ((dBodyGetGravityMode(_body))?true:false); 
}

dBodyID Body::getBodyID() const
{
	return _body;
}

const String& Body::getName(void) const
{
	return _name;
}

void Body::deriveLocation()
{
	if (mParentNode)
	{
		setPosition(mParentNode->getPosition());
		setOrientation(mParentNode->getOrientation());
	}
}

void Body::recursiveSetMode(SceneNode* node)
{
	for(unsigned short i = 0;i < node->numChildren();i++)
	{
		recursiveSetMode(static_cast<SceneNode*>(node->getChild(i)));		
	}

	if (_debug_node)
	{
		for(unsigned short j = 0;j < node->numAttachedObjects();j++)
		{
			static_cast<DebugObject*>(node->getAttachedObject(j))->setMode(
				(dBodyIsEnabled(_body))?
				DebugObject::Mode_Enabled
				:
				DebugObject::Mode_Disabled);
		}
	}
}

void Body::setDamping(const f32& linear_damping, const f32& angular_damping)
{
	_linear_damping = -(dReal)linear_damping;
	_is_linear_damped = (_linear_damping < 0.0);
	_angular_damping = -(dReal)angular_damping;
	_is_angular_damped = (_angular_damping < 0.0);

	_is_damped = _linear_damping || _is_angular_damped;
}

void Body::setLinearDamping(const f32& linear_damping)
{
	_linear_damping = -(dReal)linear_damping;
	_is_linear_damped = (_linear_damping < 0.0);

	_is_damped = _linear_damping || _is_angular_damped;
}

void Body::setAngularDamping(const f32& angular_damping)
{
	_angular_damping = -(dReal)angular_damping;
	_is_angular_damped = (_angular_damping < 0.0);

	_is_damped = _linear_damping || _is_angular_damped;
}

void Body::setLinearDampingThreshold(const f32& threshold)
{
	dBodySetAutoDisableLinearThreshold(_body, threshold);
}

void Body::setAngularDampingThreshold(const f32& threshold)
{
	dBodySetAutoDisableAngularThreshold(_body, threshold);
}

f32 Body::getLinearDamping()
{
	return (f32)-_linear_damping;
}

f32 Body::getAngularDamping()
{
	return (f32)-_angular_damping;
}

void Body::applyDamping()
{
	assert (_isEnabled && _is_damped);
	
	if (_linear_damping)
	{
		const dReal * const v = dBodyGetLinearVel(_body);
		dBodyAddForce(_body, v[0] * _linear_damping, v[1] * _linear_damping, v[2] * _linear_damping);
	}

	if (_is_angular_damped)
	{
		const dReal * const v = dBodyGetAngularVel(_body);
		dBodyAddTorque(_body, v[0] * _angular_damping, v[1] * _angular_damping, v[2] * _angular_damping);
	}	
}

f32 Body::getLinearDampingThreshold()
{
	return (f32)dBodyGetAutoDisableLinearThreshold(_body);
}

f32 Body::getAngularDampingThreshold()
{
	return (f32)dBodyGetAutoDisableAngularThreshold(_body);
}

void Body::setDebug(const bool debug)
{
	destroyDebugNode();
}

void Body::setUserData(size_t user_data)
{
	_user_data = user_data;
}

size_t Body::getUserData()
{
	return _user_data;
}

Body::~Body()
{
	destroyDebugNode();
	delete _mass;

	_world->RemoveBody(_body);
	dBodyDestroy(_body);
}

bool Body::collide(void* data, Geometry *otherGeometry)
{
    bool collided = false;
    dContactGeom contactGeom;
    Geometry *o1;
    GeometryArray::const_iterator proxy1, proxy1end;
    proxy1end = _geometries.end();

    //dContact contact;
    //Real bounce, velThresh, softness;

    //CollisionInfo collInfo;

    // @@TODO : HAS TO HANDLE TransFormedGeometry and GoemtryOffset
    for (proxy1 = _geometries.begin(); proxy1 != proxy1end; ++proxy1)
    {
        o1 = *proxy1;
        const int numc = dCollide(o1->getGeometryID(), otherGeometry->getGeometryID(), 0, &contactGeom, sizeof(dContactGeom));
        if (numc)
        {
            // Create contact joints if either object is dynamics simulated
            // If one is not, then sim will not affect it anyway, it will be fixed
            // However if one is enabled, we need the contact joint
            if (this->isAwake())
            {
                  _world->collisionCallback(data, o1->getGeometryID(), otherGeometry->getGeometryID());
            }

            // set return 
            collided = true;
            
        }
    }
    return collided;
}

bool Body::collide(void* data, Body *otherBody)
{
    bool collided = false;
    dContactGeom contactGeom;
    Geometry *o1, *o2;
    GeometryArray::const_iterator proxy1, proxy2, proxy1end, proxy2end;
    proxy1end = _geometries.end();
    proxy2end = otherBody->getGeometries()->end();

    //dContact contact;
    //Real bounce, velThresh, softness;

    //CollisionInfo collInfo;

    // @@TODO : HAS TO HANDLE TransFormedGeometry and GoemtryOffset
    for (proxy1 = _geometries.begin(); proxy1 != proxy1end; ++proxy1)
    {
        for (proxy2 = otherBody->getGeometries()->begin(); proxy2 != proxy2end; ++proxy2)
        {
            o1 = *proxy1;
            o2 = *proxy2;
            const int numc = dCollide(o1->getGeometryID(), o2->getGeometryID(), 0, &contactGeom, sizeof(dContactGeom));
            if (numc)
            {
                // Create contact joints if either object is dynamics simulated
                // If one is not, then sim will not affect it anyway, it will be fixed
                // However if one is enabled, we need the contact joint
                if (this->isAwake() || otherBody->isAwake())
                {

                    _world->collisionCallback(data, o1->getGeometryID(), o2->getGeometryID());

                }
                // set return 
                collided = true;
            }
        }
    }
    return collided;
}

bool Body::collidePlaneBounds(void* data, SceneQuery::WorldFragment *wf)
{
    bool collided = false;
    dContactGeom contactGeom;
    Geometry *geom;
    GeometryArray::const_iterator proxy, proxyend;
    proxyend = _geometries.end();

	list<Plane>::type::const_iterator pi, piend;
    piend = wf->planes->end();

    //CollisionInfo collInfo;

    // @@TODO : HAS TO HANDLE TransFormedGeometry and GoemtryOffset
    for (proxy = _geometries.begin(); proxy != proxyend; ++proxy)
    {
        // Hack, simply collide against planes which is facing towards center
        // We can't do this properly without mesh collision
        geom = *proxy;
        f32 maxdist = -1.0f;
        const Plane* bestPlane = 0;
        for (pi = wf->planes->begin(); pi != piend; ++pi)
        {
            const Plane * const boundPlane = &(*pi);
            const f32 dist = boundPlane->getDistance (this->getPosition());
            if (dist >= 0.0f)
            {

                //@@@@ TODO reuse a static InfinitePlaneGeometry ?
                InfinitePlaneGeometry *sliding_plane = new InfinitePlaneGeometry(*boundPlane, 0);


                int numc = dCollide(geom->getGeometryID(), 
                                    sliding_plane->getGeometryID(), 
                                    0, 
                                    &contactGeom, 
                                    sizeof(dContactGeom));
                if (numc)
                {
                    // Create contact joints if object is dynamics simulated
                    if (this->isAwake())
                    {
                        _world->collisionCallback(data, geom->getGeometryID(), sliding_plane->getGeometryID());

                    }
                    // set return 
                    collided = true;
                }
            }
        } 

    }
    return collided;
}

void Body::updateParentNode()
{
    if (mParentNode)
    { 
        mParentNode->setPosition(_draw_state._position);
        mParentNode->setOrientation(_draw_state._orientation);
    }

    if (_debug_node)
    {
        _debug_node->setPosition(_draw_state._position);
        _debug_node->setOrientation(_draw_state._orientation);

        recursiveSetMode(static_cast<SceneNode*>(_debug_node));
    }
} 

void Body::updatePreviousState()
{
    _isEnabled = dBodyIsEnabled(_body) || _debug_node;
    if (_isEnabled)
    {
        BodyState *previous = _state_history.almostNewest ();
        updatePosition (previous);
        updateOrientation (previous);
    }
}

void Body::updateCurrentState()
{
    _isEnabled = dBodyIsEnabled(_body) || _debug_node;
    if (_isEnabled)
    {
        BodyState *current = _state_history.newest ();
        updatePosition(current);
        updateOrientation(current);
    }
}

void Body::updateDrawState ()
{
    _isEnabled = dBodyIsEnabled(_body) || _debug_node;
    if (_isEnabled)
    {
        updatePosition(&_draw_state);
        updateOrientation(&_draw_state);
    }
}

void Body::interpolateDrawState(const f32 alpha)
{
    if (_isEnabled)
    {
        BodyState *current = _state_history.newest ();
        BodyState *previous = _state_history.almostNewest ();
        assert (current != previous);
        _draw_state.interpolate (previous, current, alpha);
    }
}

void Body::synchronise()
{
    if (_isEnabled)
    {
        if (_is_damped)
            applyDamping();
        updateParentNode();
    }
}

const Vector3& Body::getPosition() const
{
    return _draw_state._position;
}

const Quaternion& Body::getOrientation() const
{
    return _draw_state._orientation;
}

void Body::updatePosition(BodyState * const bodystate)
{
    const dReal * const position = dBodyGetPosition(_body);

    bodystate->_position.x = (f32)position[0];
    bodystate->_position.y = (f32)position[1];
    bodystate->_position.z = (f32)position[2];
}

void Body::updateOrientation(BodyState * const bodystate)
{
    const dReal * const orientation = dBodyGetQuaternion(_body); 
    bodystate->_orientation.w = (f32)orientation[0];
    bodystate->_orientation.x = (f32)orientation[1];
    bodystate->_orientation.y = (f32)orientation[2];
    bodystate->_orientation.z = (f32)orientation[3];
}
