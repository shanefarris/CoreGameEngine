#ifndef __CGAMEOBJECTSTONE2_LOD2_H__
#define __CGAMEOBJECTSTONE2_LOD2_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectStone2_lod2 : public CGameObject
	{
	public:
		CGameObjectStone2_lod2(const char* Name, Vector3& Pos);
		~CGameObjectStone2_lod2();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectStone2_lod2Factory : public IGameObjectFactory
	{
	public:
		CGameObjectStone2_lod2Factory();
		~CGameObjectStone2_lod2Factory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTSTONE2_LOD2_H__
