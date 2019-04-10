#ifndef __CGAMEOBJECTFLOWER1_H__
#define __CGAMEOBJECTFLOWER1_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectFlower1 : public CGameObject
	{
	public:
		CGameObjectFlower1(const char* Name, Vector3& Pos);
		~CGameObjectFlower1();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectFlower1Factory : public IGameObjectFactory
	{
	public:
		CGameObjectFlower1Factory();
		~CGameObjectFlower1Factory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTFLOWER1_H__
