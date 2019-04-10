#ifndef __CGAMEOBJECTSHOOTINGRANGEWALL1_H__
#define __CGAMEOBJECTSHOOTINGRANGEWALL1_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectShootingRangeWall1 : public CGameObject
	{
	public:
		CGameObjectShootingRangeWall1(const char* Name, Vector3& Pos);
		~CGameObjectShootingRangeWall1();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectShootingRangeWall1Factory : public IGameObjectFactory
	{
	public:
		CGameObjectShootingRangeWall1Factory();
		~CGameObjectShootingRangeWall1Factory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTSHOOTINGRANGEWALL1_H__
