#ifndef __CGAMEOBJECTWEIGHTLIFTER_H__
#define __CGAMEOBJECTWEIGHTLIFTER_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectWeightLifter : public CGameObject
	{
	public:
		CGameObjectWeightLifter(const char* Name, Vector3& Pos);
		~CGameObjectWeightLifter();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectWeightLifterFactory : public IGameObjectFactory
	{
	public:
		CGameObjectWeightLifterFactory();
		~CGameObjectWeightLifterFactory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTWEIGHTLIFTER_H__
