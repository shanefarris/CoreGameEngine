#include "Vehicle.h"
#include "Core/CoreStructures.h"
#include "../World.h"
#include "../Body.h"
#include "../Joint.h"
#include "../Geometry.h"
#include "../Space.h"
#include "../EntityInformer.h"
#include "../Mass.h"
#include "../Collision.h"
#include "../Utility.h"

#include "OgreEntity.h"
#include "OgreSceneManager.h"

using namespace Ogre;
using namespace Ode;

const f32 Vehicle::Wheel::FudgeFactor = 0.1f;

Vehicle::Wheel::Wheel(Vehicle* vehicle,const String& name,const String& mesh,const Vector3& position, const f32& mass, World *world, Space* space):
	Object(ObjectType_Wheel, world) 
{
	_owner = vehicle;
	_name = name;

	_entity = world->getSceneManager()->createEntity(name + "_Entity",mesh);
	_entity->setQueryFlags(Core::SQF_VEHICLE);
	_entity->setCastShadows(true);	

	EntityInformer ei(_entity);
	_radius = ei.getRadius();

	_node = _world->getSceneManager()->getRootSceneNode()->createChildSceneNode(name + "_Node");
	_node->setPosition(position);
	_body = new Body(_world, name + "_Body");

	_node->attachObject(_entity);
	_node->attachObject(_body);

	_body->setMass(SphereMass(mass,_radius));

	_geometry = new SphereGeometry(_radius, _world, space);
	_geometry->setBody(_body);
	_geometry->setUserAny(Any(this));

	_joint = new SuspensionJoint(_world);
	_joint->attach(vehicle->getBody(),_body);
	_joint->setAnchor(_body->getPosition());
	_joint->setAxis(Vector3::UNIT_Y);
	_joint->setAdditionalAxis(Vector3::NEGATIVE_UNIT_X);
	_joint->setParameter(Parameter_FudgeFactor,Vehicle::Wheel::FudgeFactor);
	
	_bouncyness = _friction = _fds = 0.0f;
	setSteerFactor(0.0f);
	setSteerLimit(0.0f);
	setSteerForce(0.0f);
	setSteerSpeed(0.0f);
	setPowerFactor(0.0f);
	setBrakeFactor(0.0f);
	setSteer(0.0f);
}

void Vehicle::Wheel::setFactors(const f32& steer, const f32& power, const f32& brake)
{
	setSteerFactor(steer);
	setPowerFactor(power);
	setBrakeFactor(brake);
}

f32 Vehicle::Wheel::getRPM()
{
	return ((_joint) && (_power_factor > 0.0f)) ? _joint->getParameter(Parameter_MotorVelocity, 2) : 0.0f;
}

f32 Vehicle::Wheel::getSteer()
{
	return ((_joint) && (_steer_factor != 0.0f)) ? _joint->getAngle() : 0.0f;
}

void Vehicle::Wheel::setSteerFactor(const f32& factor)
{
	_steer_factor = factor;
	adjustJointParameters();
}

void Vehicle::Wheel::setSteerLimit(const f32& limit)
{
	_steer_limit = limit;
	adjustJointParameters();
}

void Vehicle::Wheel::adjustJointParameters()
{
	if (_joint)
	{
		_joint->setParameter(Parameter_HighStop,_steer_limit * fabs(_steer_factor));
		_joint->setParameter(Parameter_LowStop,-(_steer_limit * fabs(_steer_factor)));
	}
}

/* 
According to the ODE docs;

By adjusting the values of ERP and CFM, you can achieve various effects. 
For example you can simulate springy constraints, where the two bodies oscillate 
as though connected by springs. Or you can simulate more spongy constraints, without 
the oscillation. In fact, ERP and CFM can be selected to have the same effect as any 
desired spring and damper constants. If you have a spring constant kp and damping constant kd, 
then the corresponding ODE constants are:

ERP = h kp / (h kp + kd)
CFM = 1 / (h kp + kd)

where h is the stepsize. These values will give the same effect as a spring-and-damper 
system simulated with implicit first order integration.
*/
void Vehicle::Wheel::setSuspension(const f32& spring_constant, const f32& damping_constant, const f32& step_size)
{
	_spring = spring_constant;
	_damping = damping_constant;
	_step = step_size;

	if (_joint)
	{
		_joint->setParameter(Parameter_SuspensionERP,_step * _spring / (_step * _spring + _damping));
		_joint->setParameter(Parameter_SuspensionCFM, 1.0f / (_step * _spring + _damping));
	}
}

const Vector3& Vehicle::Wheel::getPosition()
{
	return _body->getPosition();
}

const Quaternion& Vehicle::Wheel::getOrientation()
{
	return _body->getOrientation();
}
void Vehicle::Wheel::setPosition(const Vector3& position)
{
	_body->setPosition(position);
}

void Vehicle::Wheel::update(const f32& power_force, const f32& desired_rpm, const f32& brake_force)
{
	if (!_joint) 
		return;

	auto force = (power_force * _power_factor) - (brake_force * _brake_factor);

	if (force > 0.0)
	{
		_joint->setParameter(Parameter_MotorVelocity, desired_rpm, 2);
		_joint->setParameter(Parameter_MaximumForce, force, 2);
	}
	else
	{
		_joint->setParameter(Parameter_MotorVelocity, 0.01f, 2);
		_joint->setParameter(Parameter_MaximumForce, -force, 2);
	}
}

void Vehicle::Wheel::setSteer(const f32& position)
{
	// Steer
	if (_steer_limit * _steer_factor != 0.0)
	{
		auto steer_angle = position * _steer_limit;
		auto vel = (steer_angle * _steer_factor) - _joint->getAngle();

		vel *= (_steer_speed * fabs(_steer_factor));

		_joint->setParameter(Parameter_MotorVelocity, vel);
		_joint->setParameter(Parameter_MaximumForce, _steer_force);
	}
}

void Vehicle::Wheel::snapOff()
{
	delete _joint;
	_joint = 0;
}

Vehicle::Wheel::~Wheel()
{
	delete _joint;
	delete _body;
	delete _geometry;

	_world->getSceneManager()->getRootSceneNode()->removeAndDestroyChild(_node->getName());
	_world->getSceneManager()->destroyEntity(_entity->getName());
}

Vehicle::Vehicle(const String& name,const String& mesh, const f32& mass, World *world, Space* space, const Vector3& offset, Geometry* geometry)
	: Object(ObjectType_Sphere_Wheeled_Vehicle, world),
    _name ( name),
    _antisway (false),
    _swayRate (0.0f),
    _swayLastUpdate (0.0f),
    _swayForce (0.0f),
    _swayForceLimit (0)

{
	
	_entity = _world->getSceneManager()->createEntity(name + "_Entity",mesh);
	_entity->setQueryFlags(Core::SQF_VEHICLE);
	_entity->setCastShadows(true);
	_node = _world->getSceneManager()->getRootSceneNode()->createChildSceneNode(name + "_Node");
    _body = new Body(_world, name + "_Body");

	_trans_node = _node->createChildSceneNode("Trans_" + _node->getName());
	_trans_node->attachObject(_entity);
	_node->attachObject(_body);

	EntityInformer ei(_entity);
	const Vector3 box = ei.getSize();
	
	BoxMass box_mass(mass,Vector3(box.x,box.y,box.z));
	_body->setMass(box_mass);

    _space = new SimpleSpace(_world, space ? space : _world->getDefaultSpace());
	_space->setInternalCollisions(false);
	_space->setAutoCleanup(false);

	_offset = -offset;

	if (!geometry) 
		_geometry = new BoxGeometry(box, _world, space ? space : _world->getDefaultSpace());
	else 
		_geometry = geometry;
	_geometry->setUserAny(Any(this));

	_transform = new TransformGeometry(_world, _space);
	_transform->setEncapsulatedGeometry(_geometry);
	_transform->setBody(_body);
	_geometry->setPosition(_offset);

	_trans_node->setPosition(_offset);

	_engine = new Vehicle::Engine();
}

Vehicle::Vehicle(const String& name, World *world, Space* space, Geometry* geometry) 
	: Object(ObjectType_Sphere_Wheeled_Vehicle, world),
    _name (name),
    _antisway(false),
    _swayRate (0.0f),
    _swayLastUpdate (0.0f),
    _swayForce (0.0f),
    _swayForceLimit (0),
    _entity (nullptr),
    _geometry (geometry),
    _transform (nullptr)
{
	_space = new SimpleSpace(_world, space?space:_world->getDefaultSpace());
	_space->setInternalCollisions(false);
	_space->setAutoCleanup(false);

	_engine = new Vehicle::Engine();

	_node = _world->getSceneManager()->getRootSceneNode()->createChildSceneNode(_name  + StringConverter::toString (instanceNumber) + "_Node");
	_body = new Body(_world, _name  + StringConverter::toString (instanceNumber) + "_Body");

	_trans_node = _node->createChildSceneNode("Trans_" + _node->getName());
	_node->attachObject(_body);

	if (_geometry) 
		_geometry->setUserAny(Any(this));
	
}

Vehicle::Wheel* Vehicle::addWheel(const String& mesh,const Vector3& position, const f32& mass)
{
	const String wheelName ( _name +  
		StringConverter::toString (instanceNumber) +  
		"_Wheel" + 
		StringConverter::toString((unsigned int)_wheels.size() + 1));

	Vehicle::Wheel* wheel = new Vehicle::Wheel(this, 
												wheelName, 
												mesh, 
												position + _body->getPosition() + _offset,
												mass,
                                                _world,
												_space);
	_wheels.push_back(wheel);
	return wheel;
}

const Vector3& Vehicle::getPosition()
{
    _lastPosition = _body->getPosition() + _offset;
	return _lastPosition;
}

const Quaternion& Vehicle::getOrientation()
{
	return _body->getOrientation();
}

Space* Vehicle::getSpace()
{
	return _space;
}

void Vehicle::setPosition(const Vector3& position)
{
	for (std::vector<Vehicle::Wheel*>::iterator i = _wheels.begin();i != _wheels.end();i++)
	{
		Vector3 diff = (*i)->getPosition() - _body->getPosition();
		(*i)->setPosition(position + diff);
	}
	_body->setPosition(position);
}

void Vehicle::setSuspension(const f32& spring_constant, const f32& damping_constant, const f32& step_size)
{
	for (std::vector<Vehicle::Wheel*>::iterator i = _wheels.begin();i != _wheels.end();i++)
	{
		(*i)->setSuspension(spring_constant,damping_constant,step_size);
	}
}

void Vehicle::setInputs(bool left,bool right,bool throttle,bool brake)
{
    if (left || right || throttle)
    {
        for (std::vector<Vehicle::Wheel*>::iterator i = _wheels.begin();i != _wheels.end();i++)
        {
            (*i)->getBody()->wake();
        }
        _body->wake();
    }
	_engine->setInputs(throttle,brake);
	setSteering(0.0f + ((right) ? 1.0f : 0.0f) - ((left) ? 1.0f : 0.0f));
}

void Vehicle::setInputs(const f32& steering_position, const f32& throttle_brake)
{
	_engine->setInputs(throttle_brake);
	setSteering(steering_position);
}

void Vehicle::setOffset(const Vector3 &of)
{
	_offset = of;
	if (_geometry) 
		_geometry->setPosition(of);
	_trans_node->setPosition(of);
}

void Vehicle::setInputs(const f32& steering_position, const f32& throttle_position, const f32& brake_position)
{
	_engine->setInputs(throttle_position,brake_position);
	setSteering(steering_position);
}

void Vehicle::setSteering(const f32& steering_position)
{
	for (std::vector<Vehicle::Wheel*>::iterator i = _wheels.begin();i != _wheels.end();++i)
	{
		(*i)->setSteer(steering_position);
	}
}

f32 Vehicle::getVelocity()
{
	return _body->getLinearVelocity().length();
}

void Vehicle::applyAntiSwayBarForces()
{
	f32 amt;
	Body* wheelBody = nullptr;
	for(s32 i = 0; i < 4; i++)
	{
		SuspensionJoint* const wheelJoint = static_cast<SuspensionJoint*>(_wheels.at(i)->getBody()->getJoint(0));
		const Vector3 anchor2 (wheelJoint->getAdditionalAnchor());
		const Vector3 anchor1 (wheelJoint->getAnchor());
		const Vector3 axis (wheelJoint->getAxis());
		const f32 displacement = ( anchor1 - anchor2 ).dotProduct( axis );
		if( displacement > 0 )
		{
			amt = displacement * _swayForce;
			if( amt > _swayForceLimit ) 
				amt = (f32)_swayForceLimit;

			// force down
			wheelBody = _wheels.at(i)->getBody();
			wheelBody->addForce(-axis * amt);

			// force up
			wheelBody = _wheels.at(i ^ 1)->getBody();
			wheelBody->addForce(axis * amt);
		}
	}
}

void Vehicle::update(const f32& time)
{
	f32 rpm = FLT_MIN;
	for (auto i = _wheels.begin(); i != _wheels.end(); ++i)
	{
		rpm = std::max(rpm, (*i)->getRPM());
	}

	_engine->update(time);
	const f32 power = _engine->getPowerAtRPM(rpm);
	const f32 desired_rpm = _engine->getDesiredRPM();
	const f32 brake = _engine->getBrakeForce();

	for (auto i = _wheels.begin();i != _wheels.end();++i)
	{
		(*i)->update(power, desired_rpm, brake);
	}
	
	if (_antisway)
	{
		_swayLastUpdate += time;
		if  (_swayLastUpdate > _swayRate)
		{
			applyAntiSwayBarForces ();
			_swayLastUpdate = 0.0f;
		}
	}
}

Vehicle::Wheel* Vehicle::findWheel(Geometry* geometry)
{
	for (auto i = _wheels.begin();i != _wheels.end();i++)
	{
		if ((*i)->getGeometry() == geometry)
			return (*i);
	}
	return nullptr;
}

Vehicle::~Vehicle()
{
	// _world->unregisterVehicle(_name);

	for(auto i = _wheels.begin(); i != _wheels.end(); i++) 
		delete (*i);

	CORE_DELETE(_body);
	CORE_DELETE(_geometry);
	CORE_DELETE(_transform);
	CORE_DELETE(_space);
	CORE_DELETE(_engine);

	_node->removeAndDestroyChild(_trans_node->getName());
	_world->getSceneManager()->getRootSceneNode()->removeAndDestroyChild(_node->getName());
	_world->getSceneManager()->destroyEntity(_entity->getName());
}

Vehicle::Engine::Engine()  
	: _torque_curve(0), _curve_length (0)
{
	setInputs(false,false);
	setRevLimit(40.0f);
	setTorque(0.5f, 5.0f);
	setBrakeForce(500.0f);
}

f32 Vehicle::Engine::getPowerAtRPM(const f32& rpm)
{
	_wheel_rpm = rpm;

	const f32 pos = getRevFactor() * (_curve_length - 1);
	const u32 i = (u32)pos;
	const f32 dx = pos - ((f32)i);

	assert (i < _curve_length);
	return _torque_curve[i] + (dx * (_torque_curve[i+1] - _torque_curve[i]));
}

f32 Vehicle::Engine::getBrakeForce()
{
	return _brake_force * _brake_position;
}

void Vehicle::Engine::setInputs(const f32& throttle_position, const f32& brake_position)
{
	_throttle_position = throttle_position;
	_brake_position = _brake_position;
}

void Vehicle::Engine::setInputs(const f32& throttle_brake)
{
	_throttle_position = std::max(0.0f, throttle_brake);
	_brake_position = std::max(0.0f, -throttle_brake);
}

void Vehicle::Engine::setInputs(bool throttle, bool brake)
{
	_throttle_position = (throttle) ? 1.0f : 0.0f;
	_brake_position = (brake) ? 1.0f : 0.0f;
}

// Manual gearbox
void Vehicle::Engine::changeUp()
{
}

void Vehicle::Engine::changeDown()
{
}

void Vehicle::Engine::setGear(char code)
{
}

void Vehicle::Engine::setGear(unsigned int i)
{
}

// Information functions
f32 Vehicle::Engine::getDesiredRPM()
{
	return _rev_limit * _throttle_position;
}

f32 Vehicle::Engine::getRevFactor()
{
	return _wheel_rpm * _inv_rev_limit;
}

char Vehicle::Engine::getGearCode()
{
	return '\0';
}

// Engine parameters
void Vehicle::Engine::setRevLimit(const f32& rpm)
{
	_rev_limit = rpm;
	_inv_rev_limit = 1.0f / _rev_limit;
}

// Set a custom torque curve
void Vehicle::Engine::setTorque(f32* torque, u32 samples)
{
	assert((samples > 1)&&("Need more than one sample for setTorque"));

	delete[] _torque_curve;
	_curve_length = samples;
	_torque_curve = new f32[_curve_length + 1];

	for (u32 i = 0; i < samples; i++) 
		_torque_curve[i] = torque[i];
	_torque_curve[_curve_length] = torque[samples - 1];
}

// Set a linear torque curve, minimum should be greater than zero, or the vehicle won't go anywhere!
void Vehicle::Engine::setTorque(const f32& minimum, const f32& maximum)
{
	f32 curve[] = {minimum, maximum};
	setTorque(curve, 2);
}

// Set a constant torque "curve"
void Vehicle::Engine::setTorque(const f32& constant)
{
	setTorque(constant, constant);
}

// Braking parameters
void Vehicle::Engine::setBrakeForce(const f32& force)
{
	_brake_force = force;
}

void Vehicle::Engine::update(const f32& time)
{
}

// Drivetrain parameters
void Vehicle::Engine::addGear(const f32& ratio,char code)
{
}

void Vehicle::Engine::setFinalDrive(const f32& ratio)
{
}

void Vehicle::Engine::setAutoShiftRevs(const f32& up, const f32& down)
{
}

void Vehicle::Engine::setAutoBox(bool automatic)
{
}

Vehicle::Engine::~Engine()
{
	delete[] _torque_curve;
}

void Vehicle::Wheel::setupTyreContact(Contact* contact)
{
	Quaternion vehicle_orient = _owner->getBody()->getOrientation();

	Vector3 wheel_up = vehicle_orient * Vector3::UNIT_Y;
	Quaternion wheel_rot(Radian(getSteer()), (Vector3) wheel_up);
	Vector3 wheel_forward = wheel_rot * (vehicle_orient * Vector3::UNIT_Z);
	Vector3 wheel_velocity = _body->getLinearVelocity();

	contact->setFrictionMode(Contact::Flag_BothFrictionPyramids);
	contact->setBouncyness(_bouncyness);
	contact->setCoulombFriction(_friction);
	contact->setFirstFrictionDirection(wheel_forward);
	contact->setAdditionalFDS(wheel_velocity.length() * _fds);
}

bool Vehicle::handleTyreCollision(Contact* contact)
{
	Geometry *geom = contact->getFirstGeometry();

	Object* pObject = any_cast<Object*>(geom->getUserAny());
	if (pObject && 
		(pObject->getObjectType() == ObjectType_Wheel))
	{
		((Vehicle::Wheel*)(pObject))->setupTyreContact(contact);
		return true;
	}
	else
	{
		geom = contact->getSecondGeometry();
		pObject = any_cast<Object*>(geom->getUserAny());
		if (pObject && (pObject->getObjectType() == ObjectType_Wheel))
		{
			((Vehicle::Wheel*)pObject)->setupTyreContact(contact);
			return true;
		}
	}
	return false;
}