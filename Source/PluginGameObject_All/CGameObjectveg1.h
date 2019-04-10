#ifndef __CGAMEOBJECTVEG1_H__
#define __CGAMEOBJECTVEG1_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectVeg1 : public CGameObject
	{
	public:
		CGameObjectVeg1(const char* Name, Vector3& Pos);
		~CGameObjectVeg1();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectVeg1Factory : public IGameObjectFactory
	{
	public:
		CGameObjectVeg1Factory();
		~CGameObjectVeg1Factory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTVEG1_H__
