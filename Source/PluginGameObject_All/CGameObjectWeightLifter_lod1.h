#ifndef __CGAMEOBJECTWEIGHTLIFTER_LOD1_H__
#define __CGAMEOBJECTWEIGHTLIFTER_LOD1_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectWeightLifter_lod1 : public CGameObject
	{
	public:
		CGameObjectWeightLifter_lod1(const char* Name, Vector3& Pos);
		~CGameObjectWeightLifter_lod1();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectWeightLifter_lod1Factory : public IGameObjectFactory
	{
	public:
		CGameObjectWeightLifter_lod1Factory();
		~CGameObjectWeightLifter_lod1Factory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTWEIGHTLIFTER_LOD1_H__
