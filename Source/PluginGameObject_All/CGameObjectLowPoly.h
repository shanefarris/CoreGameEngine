#ifndef __CGAMEOBJECTLOWPOLY_H__
#define __CGAMEOBJECTLOWPOLY_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectLowPoly : public CGameObject
	{
	public:
		CGameObjectLowPoly(const char* Name, Vector3& Pos);
		~CGameObjectLowPoly();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectLowPolyFactory : public IGameObjectFactory
	{
	public:
		CGameObjectLowPolyFactory();
		~CGameObjectLowPolyFactory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTLOWPOLY_H__
