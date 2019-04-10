#ifndef _OGREODEPREFABOBJECT_H_
#define _OGREODEPREFABOBJECT_H_

namespace Ode
{
	class World;
}

namespace Ode 
{
	enum ObjectType
    {
        ObjectType_Sphere_Wheeled_Vehicle,
        ObjectType_Ray_Wheeled_Vehicle,
        ObjectType_Wheel,
        ObjectType_Ragdoll,
        ObjectType_CompositeObject,
        ObjectType_Single_Object
    };

	class Object 
    {
	public:
        Object(ObjectType type, Ode::World *world);

		virtual ~Object();

		Ode::ObjectType getObjectType() const;
		static unsigned int getInstanceNumber();
        static unsigned int getInstanceNumberAndIncrement();

	protected:
		ObjectType		_type;
        Ode::World* _world;

        static unsigned int instanceNumber;
	};
}

#endif

