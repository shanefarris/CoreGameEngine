#ifndef __CGAMEOBJECTVEG9_H__
#define __CGAMEOBJECTVEG9_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectVeg9 : public CGameObject
	{
	public:
		CGameObjectVeg9(const char* Name, Vector3& Pos);
		~CGameObjectVeg9();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectVeg9Factory : public IGameObjectFactory
	{
	public:
		CGameObjectVeg9Factory();
		~CGameObjectVeg9Factory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTVEG9_H__
