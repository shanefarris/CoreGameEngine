#ifndef __CGAMEOBJECTSTONERAMP_H__
#define __CGAMEOBJECTSTONERAMP_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectStoneRamp : public CGameObject
	{
	public:
		CGameObjectStoneRamp(const char* Name, Vector3& Pos);
		~CGameObjectStoneRamp();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectStoneRampFactory : public IGameObjectFactory
	{
	public:
		CGameObjectStoneRampFactory();
		~CGameObjectStoneRampFactory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTSTONERAMP_H__
