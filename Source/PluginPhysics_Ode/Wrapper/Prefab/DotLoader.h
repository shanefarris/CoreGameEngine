#ifndef _DotLoader_H_
#define _DotLoader_H_

#include "Core/Defines.h"
#include "../Prefab/Ragdoll.h"

class TiXmlNode;
class TiXmlDocument;

namespace Ode
{
	class Object;
	class Ragdoll;
	class Vehicle;
}

namespace Ode 
{
	class DotLoader 
	{
	public:
        DotLoader(World* world = nullptr, Space* space = nullptr);
		~DotLoader() { }

        void setWorld(World * world) { _world = world; }
        void setSpace(Space * space) { _space = space; }

        Object* loadObject(const String &filename, const String &object_name, const String &instance_name = StringUtil::BLANK);

    private:

        Object*  parseObject(const TiXmlNode *child, const String &object_name, const String &instance_name = StringUtil::BLANK);
        Object*  parseCompositeObject(const TiXmlNode *child, const String &object_name, const String &instance_name = StringUtil::BLANK);
        Object*  parseSingleObject(const TiXmlNode *child, const String &object_name, const String &instance_name = StringUtil::BLANK);
        Vehicle* parseVehicle(const TiXmlNode *child, const String &vehicle_name, const String &instance_name = StringUtil::BLANK);
        Ragdoll* parseRagdoll(const TiXmlNode *child, const String &ragdoll_name, const String &instance_name = StringUtil::BLANK);

		void parseRagdollSettings(Ragdoll::BoneSettings *bone_settings, const void *tag) const;

    protected:
        // load and check file
        TiXmlDocument * loadFile(const String &filename);

        World * _world;
        Space * _space;
	};
}

#endif //DotLoader
