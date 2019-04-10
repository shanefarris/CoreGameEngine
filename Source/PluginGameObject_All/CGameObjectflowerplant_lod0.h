#ifndef __CGAMEOBJECTFLOWERPLANT_LOD0_H__
#define __CGAMEOBJECTFLOWERPLANT_LOD0_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectFlowerplant_lod0 : public CGameObject
	{
	public:
		CGameObjectFlowerplant_lod0(const char* Name, Vector3& Pos);
		~CGameObjectFlowerplant_lod0();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectFlowerplant_lod0Factory : public IGameObjectFactory
	{
	public:
		CGameObjectFlowerplant_lod0Factory();
		~CGameObjectFlowerplant_lod0Factory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTFLOWERPLANT_LOD0_H__
