#ifndef __CGAMEOBJECTGATE_H__
#define __CGAMEOBJECTGATE_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectGate : public CGameObject
	{
	public:
		CGameObjectGate(const char* Name, Vector3& Pos);
		~CGameObjectGate();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectGateFactory : public IGameObjectFactory
	{
	public:
		CGameObjectGateFactory();
		~CGameObjectGateFactory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTGATE_H__
