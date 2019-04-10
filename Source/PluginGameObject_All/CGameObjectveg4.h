#ifndef __CGAMEOBJECTVEG4_H__
#define __CGAMEOBJECTVEG4_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectVeg4 : public CGameObject
	{
	public:
		CGameObjectVeg4(const char* Name, Vector3& Pos);
		~CGameObjectVeg4();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectVeg4Factory : public IGameObjectFactory
	{
	public:
		CGameObjectVeg4Factory();
		~CGameObjectVeg4Factory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTVEG4_H__
