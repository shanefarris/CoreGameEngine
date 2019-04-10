#ifndef __CGAMEOBJECTGASPIPECURVE_H__
#define __CGAMEOBJECTGASPIPECURVE_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectGasPipeCurve : public CGameObject
	{
	public:
		CGameObjectGasPipeCurve(const char* Name, Vector3& Pos);
		~CGameObjectGasPipeCurve();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectGasPipeCurveFactory : public IGameObjectFactory
	{
	public:
		CGameObjectGasPipeCurveFactory();
		~CGameObjectGasPipeCurveFactory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTGASPIPECURVE_H__
