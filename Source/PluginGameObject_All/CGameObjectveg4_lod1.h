#ifndef __CGAMEOBJECTVEG4_LOD1_H__
#define __CGAMEOBJECTVEG4_LOD1_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectVeg4_lod1 : public CGameObject
	{
	public:
		CGameObjectVeg4_lod1(const char* Name, Vector3& Pos);
		~CGameObjectVeg4_lod1();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectVeg4_lod1Factory : public IGameObjectFactory
	{
	public:
		CGameObjectVeg4_lod1Factory();
		~CGameObjectVeg4_lod1Factory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTVEG4_LOD1_H__
