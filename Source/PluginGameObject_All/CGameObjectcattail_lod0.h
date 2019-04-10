#ifndef __CGAMEOBJECTCATTAIL_LOD0_H__
#define __CGAMEOBJECTCATTAIL_LOD0_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectCattail_lod0 : public CGameObject
	{
	public:
		CGameObjectCattail_lod0(const char* Name, Vector3& Pos);
		~CGameObjectCattail_lod0();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectCattail_lod0Factory : public IGameObjectFactory
	{
	public:
		CGameObjectCattail_lod0Factory();
		~CGameObjectCattail_lod0Factory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTCATTAIL_LOD0_H__
