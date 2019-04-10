#ifndef __CGAMEOBJECTPATHPOINT_H__
#define __CGAMEOBJECTPATHPOINT_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectPathPoint : public CGameObject
	{
	public:
		CGameObjectPathPoint(const char* Name, Vector3& Pos);
		~CGameObjectPathPoint();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectPathPointFactory : public IGameObjectFactory
	{
	public:
		CGameObjectPathPointFactory();
		~CGameObjectPathPointFactory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTPATHPOINT_H__
