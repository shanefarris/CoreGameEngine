#ifndef __CGAMEOBJECTGASPIPECURVE_LOD_H__
#define __CGAMEOBJECTGASPIPECURVE_LOD_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectGasPipeCurve_lod : public CGameObject
	{
	public:
		CGameObjectGasPipeCurve_lod(const char* Name, Vector3& Pos);
		~CGameObjectGasPipeCurve_lod();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectGasPipeCurve_lodFactory : public IGameObjectFactory
	{
	public:
		CGameObjectGasPipeCurve_lodFactory();
		~CGameObjectGasPipeCurve_lodFactory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTGASPIPECURVE_LOD_H__
