#ifndef __CGAMEOBJECTSTAIRS1_LOD2_H__
#define __CGAMEOBJECTSTAIRS1_LOD2_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectStairs1_lod2 : public CGameObject
	{
	public:
		CGameObjectStairs1_lod2(const char* Name, Vector3& Pos);
		~CGameObjectStairs1_lod2();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectStairs1_lod2Factory : public IGameObjectFactory
	{
	public:
		CGameObjectStairs1_lod2Factory();
		~CGameObjectStairs1_lod2Factory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTSTAIRS1_LOD2_H__
