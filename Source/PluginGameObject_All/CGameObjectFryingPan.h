#ifndef __CGAMEOBJECTFRYINGPAN_H__
#define __CGAMEOBJECTFRYINGPAN_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectFryingPan : public CGameObject
	{
	public:
		CGameObjectFryingPan(const char* Name, Vector3& Pos);
		~CGameObjectFryingPan();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectFryingPanFactory : public IGameObjectFactory
	{
	public:
		CGameObjectFryingPanFactory();
		~CGameObjectFryingPanFactory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTFRYINGPAN_H__
