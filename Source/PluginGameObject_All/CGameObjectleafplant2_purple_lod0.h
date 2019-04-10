#ifndef __CGAMEOBJECTLEAFPLANT2_PURPLE_LOD0_H__
#define __CGAMEOBJECTLEAFPLANT2_PURPLE_LOD0_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectLeafplant2_purple_lod0 : public CGameObject
	{
	public:
		CGameObjectLeafplant2_purple_lod0(const char* Name, Vector3& Pos);
		~CGameObjectLeafplant2_purple_lod0();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectLeafplant2_purple_lod0Factory : public IGameObjectFactory
	{
	public:
		CGameObjectLeafplant2_purple_lod0Factory();
		~CGameObjectLeafplant2_purple_lod0Factory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTLEAFPLANT2_PURPLE_LOD0_H__
