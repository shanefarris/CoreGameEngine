#ifndef __CGAMEOBJECTFENCE1CURVE2_H__
#define __CGAMEOBJECTFENCE1CURVE2_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectFence1Curve2 : public CGameObject
	{
	public:
		CGameObjectFence1Curve2(const char* Name, Vector3& Pos);
		~CGameObjectFence1Curve2();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectFence1Curve2Factory : public IGameObjectFactory
	{
	public:
		CGameObjectFence1Curve2Factory();
		~CGameObjectFence1Curve2Factory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTFENCE1CURVE2_H__
