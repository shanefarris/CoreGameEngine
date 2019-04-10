#ifndef __CGAMEOBJECTSTONE1_LOD2_H__
#define __CGAMEOBJECTSTONE1_LOD2_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectStone1_lod2 : public CGameObject
	{
	public:
		CGameObjectStone1_lod2(const char* Name, Vector3& Pos);
		~CGameObjectStone1_lod2();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectStone1_lod2Factory : public IGameObjectFactory
	{
	public:
		CGameObjectStone1_lod2Factory();
		~CGameObjectStone1_lod2Factory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTSTONE1_LOD2_H__
