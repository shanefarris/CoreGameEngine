#ifndef __CGAMEOBJECTVEG8_H__
#define __CGAMEOBJECTVEG8_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectVeg8 : public CGameObject
	{
	public:
		CGameObjectVeg8(const char* Name, Vector3& Pos);
		~CGameObjectVeg8();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectVeg8Factory : public IGameObjectFactory
	{
	public:
		CGameObjectVeg8Factory();
		~CGameObjectVeg8Factory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTVEG8_H__
