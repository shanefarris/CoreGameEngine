#ifndef __IGAMEOBJECTFACTORY_H__
#define __IGAMEOBJECTFACTORY_H__

#include "Defines.h"

#if defined DLL_EXPORT
#define DECLDIR __declspec(dllexport)
#else
#define DECLDIR __declspec(dllimport)
#endif

namespace Core
{
	class CGameObject;

	namespace Physics
	{
		class CPhysicsProfile;
	}

namespace Plugin
{
	class IGameObjectFactory
	{
	public:
		virtual Core::CGameObject* CreateObject(const char* Name, Vector3& Pos) = 0;

		String GameObjectType;
	};
}
}

#endif //__IGAMEOBJECTFACTORY_H__