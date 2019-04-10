#ifndef __CGAMEOBJECTGASPIPELONG_LOD_H__
#define __CGAMEOBJECTGASPIPELONG_LOD_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectGasPipeLong_lod : public CGameObject
	{
	public:
		CGameObjectGasPipeLong_lod(const char* Name, Vector3& Pos);
		~CGameObjectGasPipeLong_lod();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectGasPipeLong_lodFactory : public IGameObjectFactory
	{
	public:
		CGameObjectGasPipeLong_lodFactory();
		~CGameObjectGasPipeLong_lodFactory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTGASPIPELONG_LOD_H__
