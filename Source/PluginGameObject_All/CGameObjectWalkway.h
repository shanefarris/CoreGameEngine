#ifndef __CGAMEOBJECTWALKWAY_H__
#define __CGAMEOBJECTWALKWAY_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectWalkway : public CGameObject
	{
	public:
		CGameObjectWalkway(const char* Name, Vector3& Pos);
		~CGameObjectWalkway();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectWalkwayFactory : public IGameObjectFactory
	{
	public:
		CGameObjectWalkwayFactory();
		~CGameObjectWalkwayFactory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTWALKWAY_H__
