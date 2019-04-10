#ifndef __CGAMEOBJECTVEG2_LOD2_H__
#define __CGAMEOBJECTVEG2_LOD2_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectVeg2_lod2 : public CGameObject
	{
	public:
		CGameObjectVeg2_lod2(const char* Name, Vector3& Pos);
		~CGameObjectVeg2_lod2();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectVeg2_lod2Factory : public IGameObjectFactory
	{
	public:
		CGameObjectVeg2_lod2Factory();
		~CGameObjectVeg2_lod2Factory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTVEG2_LOD2_H__
