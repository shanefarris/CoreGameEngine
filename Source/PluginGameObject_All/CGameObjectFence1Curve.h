#ifndef __CGAMEOBJECTFENCE1CURVE_H__
#define __CGAMEOBJECTFENCE1CURVE_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectFence1Curve : public CGameObject
	{
	public:
		CGameObjectFence1Curve(const char* Name, Vector3& Pos);
		~CGameObjectFence1Curve();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectFence1CurveFactory : public IGameObjectFactory
	{
	public:
		CGameObjectFence1CurveFactory();
		~CGameObjectFence1CurveFactory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTFENCE1CURVE_H__
