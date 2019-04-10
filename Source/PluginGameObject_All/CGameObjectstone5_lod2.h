#ifndef __CGAMEOBJECTSTONE5_LOD2_H__
#define __CGAMEOBJECTSTONE5_LOD2_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectStone5_lod2 : public CGameObject
	{
	public:
		CGameObjectStone5_lod2(const char* Name, Vector3& Pos);
		~CGameObjectStone5_lod2();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectStone5_lod2Factory : public IGameObjectFactory
	{
	public:
		CGameObjectStone5_lod2Factory();
		~CGameObjectStone5_lod2Factory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTSTONE5_LOD2_H__
