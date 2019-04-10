#ifndef __CGAMEOBJECTSTAIRS3_LOD3_H__
#define __CGAMEOBJECTSTAIRS3_LOD3_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectStairs3_lod3 : public CGameObject
	{
	public:
		CGameObjectStairs3_lod3(const char* Name, Vector3& Pos);
		~CGameObjectStairs3_lod3();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectStairs3_lod3Factory : public IGameObjectFactory
	{
	public:
		CGameObjectStairs3_lod3Factory();
		~CGameObjectStairs3_lod3Factory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTSTAIRS3_LOD3_H__
