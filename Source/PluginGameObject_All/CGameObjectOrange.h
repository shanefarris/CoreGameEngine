#ifndef __CGAMEOBJECTORANGE_H__
#define __CGAMEOBJECTORANGE_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectOrange : public CGameObject
	{
	public:
		CGameObjectOrange(const char* Name, Vector3& Pos);
		~CGameObjectOrange();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectOrangeFactory : public IGameObjectFactory
	{
	public:
		CGameObjectOrangeFactory();
		~CGameObjectOrangeFactory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTORANGE_H__
