#ifndef __CGAMEOBJECTLEAFLARGE_LOD0_H__
#define __CGAMEOBJECTLEAFLARGE_LOD0_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectLeaflarge_lod0 : public CGameObject
	{
	public:
		CGameObjectLeaflarge_lod0(const char* Name, Vector3& Pos);
		~CGameObjectLeaflarge_lod0();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectLeaflarge_lod0Factory : public IGameObjectFactory
	{
	public:
		CGameObjectLeaflarge_lod0Factory();
		~CGameObjectLeaflarge_lod0Factory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTLEAFLARGE_LOD0_H__
