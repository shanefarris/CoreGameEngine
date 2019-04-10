#ifndef __CGAMEOBJECTDIRTROADFALLING_H__
#define __CGAMEOBJECTDIRTROADFALLING_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectDirtRoadFalling : public CGameObject
	{
	public:
		CGameObjectDirtRoadFalling(const char* Name, Vector3& Pos);
		~CGameObjectDirtRoadFalling();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectDirtRoadFallingFactory : public IGameObjectFactory
	{
	public:
		CGameObjectDirtRoadFallingFactory();
		~CGameObjectDirtRoadFallingFactory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTDIRTROADFALLING_H__
