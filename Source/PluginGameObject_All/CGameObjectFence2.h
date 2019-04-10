#ifndef __CGAMEOBJECTFENCE2_H__
#define __CGAMEOBJECTFENCE2_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectFence2 : public CGameObject
	{
	public:
		CGameObjectFence2(const char* Name, Vector3& Pos);
		~CGameObjectFence2();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectFence2Factory : public IGameObjectFactory
	{
	public:
		CGameObjectFence2Factory();
		~CGameObjectFence2Factory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTFENCE2_H__
