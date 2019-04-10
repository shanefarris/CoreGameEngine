#ifndef __CGAMEOBJECTVEG2_H__
#define __CGAMEOBJECTVEG2_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectVeg2 : public CGameObject
	{
	public:
		CGameObjectVeg2(const char* Name, Vector3& Pos);
		~CGameObjectVeg2();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectVeg2Factory : public IGameObjectFactory
	{
	public:
		CGameObjectVeg2Factory();
		~CGameObjectVeg2Factory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTVEG2_H__
