#ifndef __CGAMEOBJECTVEG1_LOD2_H__
#define __CGAMEOBJECTVEG1_LOD2_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectVeg1_lod2 : public CGameObject
	{
	public:
		CGameObjectVeg1_lod2(const char* Name, Vector3& Pos);
		~CGameObjectVeg1_lod2();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectVeg1_lod2Factory : public IGameObjectFactory
	{
	public:
		CGameObjectVeg1_lod2Factory();
		~CGameObjectVeg1_lod2Factory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTVEG1_LOD2_H__
