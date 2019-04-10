#ifndef __CGAMEOBJECTLEAFPLANT4_LOD0_H__
#define __CGAMEOBJECTLEAFPLANT4_LOD0_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectLeafplant4_lod0 : public CGameObject
	{
	public:
		CGameObjectLeafplant4_lod0(const char* Name, Vector3& Pos);
		~CGameObjectLeafplant4_lod0();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectLeafplant4_lod0Factory : public IGameObjectFactory
	{
	public:
		CGameObjectLeafplant4_lod0Factory();
		~CGameObjectLeafplant4_lod0Factory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTLEAFPLANT4_LOD0_H__
