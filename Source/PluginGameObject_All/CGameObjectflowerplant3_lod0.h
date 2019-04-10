#ifndef __CGAMEOBJECTFLOWERPLANT3_LOD0_H__
#define __CGAMEOBJECTFLOWERPLANT3_LOD0_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectFlowerplant3_lod0 : public CGameObject
	{
	public:
		CGameObjectFlowerplant3_lod0(const char* Name, Vector3& Pos);
		~CGameObjectFlowerplant3_lod0();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectFlowerplant3_lod0Factory : public IGameObjectFactory
	{
	public:
		CGameObjectFlowerplant3_lod0Factory();
		~CGameObjectFlowerplant3_lod0Factory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTFLOWERPLANT3_LOD0_H__
