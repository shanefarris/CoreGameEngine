#ifndef __CGAMEOBJECTVEG9_LOD2_H__
#define __CGAMEOBJECTVEG9_LOD2_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectVeg9_lod2 : public CGameObject
	{
	public:
		CGameObjectVeg9_lod2(const char* Name, Vector3& Pos);
		~CGameObjectVeg9_lod2();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectVeg9_lod2Factory : public IGameObjectFactory
	{
	public:
		CGameObjectVeg9_lod2Factory();
		~CGameObjectVeg9_lod2Factory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTVEG9_LOD2_H__
