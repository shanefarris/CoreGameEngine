#ifndef __CGAMEOBJECTSTONE4_LOD2_H__
#define __CGAMEOBJECTSTONE4_LOD2_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectStone4_lod2 : public CGameObject
	{
	public:
		CGameObjectStone4_lod2(const char* Name, Vector3& Pos);
		~CGameObjectStone4_lod2();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectStone4_lod2Factory : public IGameObjectFactory
	{
	public:
		CGameObjectStone4_lod2Factory();
		~CGameObjectStone4_lod2Factory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTSTONE4_LOD2_H__
