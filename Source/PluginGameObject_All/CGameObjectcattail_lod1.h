#ifndef __CGAMEOBJECTCATTAIL_LOD1_H__
#define __CGAMEOBJECTCATTAIL_LOD1_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectCattail_lod1 : public CGameObject
	{
	public:
		CGameObjectCattail_lod1(const char* Name, Vector3& Pos);
		~CGameObjectCattail_lod1();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectCattail_lod1Factory : public IGameObjectFactory
	{
	public:
		CGameObjectCattail_lod1Factory();
		~CGameObjectCattail_lod1Factory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTCATTAIL_LOD1_H__
