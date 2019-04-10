#ifndef __CGAMEOBJECTORANGEHALF_H__
#define __CGAMEOBJECTORANGEHALF_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectOrangeHalf : public CGameObject
	{
	public:
		CGameObjectOrangeHalf(const char* Name, Vector3& Pos);
		~CGameObjectOrangeHalf();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectOrangeHalfFactory : public IGameObjectFactory
	{
	public:
		CGameObjectOrangeHalfFactory();
		~CGameObjectOrangeHalfFactory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTORANGEHALF_H__
