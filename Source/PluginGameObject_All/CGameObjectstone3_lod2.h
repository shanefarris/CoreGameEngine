#ifndef __CGAMEOBJECTSTONE3_LOD2_H__
#define __CGAMEOBJECTSTONE3_LOD2_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectStone3_lod2 : public CGameObject
	{
	public:
		CGameObjectStone3_lod2(const char* Name, Vector3& Pos);
		~CGameObjectStone3_lod2();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectStone3_lod2Factory : public IGameObjectFactory
	{
	public:
		CGameObjectStone3_lod2Factory();
		~CGameObjectStone3_lod2Factory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTSTONE3_LOD2_H__
