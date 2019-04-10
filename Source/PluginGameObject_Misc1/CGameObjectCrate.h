#ifndef __CGAMEOBJECTCRATE_H__
#define __CGAMEOBJECTCRATE_H__

#include "Defines.h"
#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectCrate : public CGameObject
	{
	public:
		CGameObjectCrate(const char* Name, Vector3& Pos);
		~CGameObjectCrate();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectCrateFactory : public IGameObjectFactory
	{
	public:
		CGameObjectCrateFactory();
		~CGameObjectCrateFactory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);

	};
}
}

#endif //__CGAMEOBJECTCRATE_H__