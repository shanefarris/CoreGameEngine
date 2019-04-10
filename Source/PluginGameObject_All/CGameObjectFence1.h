#ifndef __CGAMEOBJECTFENCE1_H__
#define __CGAMEOBJECTFENCE1_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectFence1 : public CGameObject
	{
	public:
		CGameObjectFence1(const char* Name, Vector3& Pos);
		~CGameObjectFence1();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectFence1Factory : public IGameObjectFactory
	{
	public:
		CGameObjectFence1Factory();
		~CGameObjectFence1Factory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTFENCE1_H__
