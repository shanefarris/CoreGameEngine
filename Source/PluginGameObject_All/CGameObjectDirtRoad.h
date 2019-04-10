#ifndef __CGAMEOBJECTDIRTROAD_H__
#define __CGAMEOBJECTDIRTROAD_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectDirtRoad : public CGameObject
	{
	public:
		CGameObjectDirtRoad(const char* Name, Vector3& Pos);
		~CGameObjectDirtRoad();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectDirtRoadFactory : public IGameObjectFactory
	{
	public:
		CGameObjectDirtRoadFactory();
		~CGameObjectDirtRoadFactory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTDIRTROAD_H__
