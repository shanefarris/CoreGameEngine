#ifndef __CGAMEOBJECTWALLLAMP_H__
#define __CGAMEOBJECTWALLLAMP_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectWallLamp : public CGameObject
	{
	public:
		CGameObjectWallLamp(const char* Name, Vector3& Pos);
		~CGameObjectWallLamp();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectWallLampFactory : public IGameObjectFactory
	{
	public:
		CGameObjectWallLampFactory();
		~CGameObjectWallLampFactory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTWALLLAMP_H__
