#ifndef __CGAMEOBJECTSTONE6_LOD1_H__
#define __CGAMEOBJECTSTONE6_LOD1_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectStone6_lod1 : public CGameObject
	{
	public:
		CGameObjectStone6_lod1(const char* Name, Vector3& Pos);
		~CGameObjectStone6_lod1();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectStone6_lod1Factory : public IGameObjectFactory
	{
	public:
		CGameObjectStone6_lod1Factory();
		~CGameObjectStone6_lod1Factory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTSTONE6_LOD1_H__
