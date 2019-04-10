#ifndef __CGAMEOBJECTLEAFLARGE2_LOD0_H__
#define __CGAMEOBJECTLEAFLARGE2_LOD0_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectLeaflarge2_lod0 : public CGameObject
	{
	public:
		CGameObjectLeaflarge2_lod0(const char* Name, Vector3& Pos);
		~CGameObjectLeaflarge2_lod0();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectLeaflarge2_lod0Factory : public IGameObjectFactory
	{
	public:
		CGameObjectLeaflarge2_lod0Factory();
		~CGameObjectLeaflarge2_lod0Factory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTLEAFLARGE2_LOD0_H__
