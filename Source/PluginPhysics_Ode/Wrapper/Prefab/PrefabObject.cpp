#include "PrefabObject.h"
#include "../World.h"

using namespace Ogre;
using namespace Ode;
using namespace Ode;

namespace Ode
{
    unsigned int Object::instanceNumber = 0;
}

Object::Object(ObjectType type, Ode::World *world) : _type(type), _world(world)
{
	instanceNumber++;
}

Object::~Object()
{
    instanceNumber--;
}

Ode::ObjectType Object::getObjectType() const
{
    return _type;
}

unsigned int Object::getInstanceNumber()
{
	return instanceNumber;
}

unsigned int Object::getInstanceNumberAndIncrement()
{
    return instanceNumber++;
}