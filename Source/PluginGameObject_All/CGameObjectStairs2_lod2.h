#ifndef __CGAMEOBJECTSTAIRS2_LOD2_H__
#define __CGAMEOBJECTSTAIRS2_LOD2_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectStairs2_lod2 : public CGameObject
	{
	public:
		CGameObjectStairs2_lod2(const char* Name, Vector3& Pos);
		~CGameObjectStairs2_lod2();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectStairs2_lod2Factory : public IGameObjectFactory
	{
	public:
		CGameObjectStairs2_lod2Factory();
		~CGameObjectStairs2_lod2Factory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTSTAIRS2_LOD2_H__
