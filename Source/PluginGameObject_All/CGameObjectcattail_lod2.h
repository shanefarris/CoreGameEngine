#ifndef __CGAMEOBJECTCATTAIL_LOD2_H__
#define __CGAMEOBJECTCATTAIL_LOD2_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectCattail_lod2 : public CGameObject
	{
	public:
		CGameObjectCattail_lod2(const char* Name, Vector3& Pos);
		~CGameObjectCattail_lod2();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectCattail_lod2Factory : public IGameObjectFactory
	{
	public:
		CGameObjectCattail_lod2Factory();
		~CGameObjectCattail_lod2Factory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTCATTAIL_LOD2_H__
