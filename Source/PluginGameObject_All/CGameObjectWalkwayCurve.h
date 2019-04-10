#ifndef __CGAMEOBJECTWALKWAYCURVE_H__
#define __CGAMEOBJECTWALKWAYCURVE_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectWalkwayCurve : public CGameObject
	{
	public:
		CGameObjectWalkwayCurve(const char* Name, Vector3& Pos);
		~CGameObjectWalkwayCurve();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectWalkwayCurveFactory : public IGameObjectFactory
	{
	public:
		CGameObjectWalkwayCurveFactory();
		~CGameObjectWalkwayCurveFactory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTWALKWAYCURVE_H__
