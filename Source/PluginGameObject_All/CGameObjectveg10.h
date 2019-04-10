#ifndef __CGAMEOBJECTVEG10_H__
#define __CGAMEOBJECTVEG10_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectVeg10 : public CGameObject
	{
	public:
		CGameObjectVeg10(const char* Name, Vector3& Pos);
		~CGameObjectVeg10();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectVeg10Factory : public IGameObjectFactory
	{
	public:
		CGameObjectVeg10Factory();
		~CGameObjectVeg10Factory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTVEG10_H__
