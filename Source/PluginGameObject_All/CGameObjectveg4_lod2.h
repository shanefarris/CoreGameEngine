#ifndef __CGAMEOBJECTVEG4_LOD2_H__
#define __CGAMEOBJECTVEG4_LOD2_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectVeg4_lod2 : public CGameObject
	{
	public:
		CGameObjectVeg4_lod2(const char* Name, Vector3& Pos);
		~CGameObjectVeg4_lod2();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectVeg4_lod2Factory : public IGameObjectFactory
	{
	public:
		CGameObjectVeg4_lod2Factory();
		~CGameObjectVeg4_lod2Factory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTVEG4_LOD2_H__
