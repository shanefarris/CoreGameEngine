#ifndef __CGAMEOBJECTHUMVEE_1_H__
#define __CGAMEOBJECTHUMVEE_1_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectHumvee_1 : public CGameObject
	{
	public:
		CGameObjectHumvee_1(const char* Name, Vector3& Pos);
		~CGameObjectHumvee_1();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectHumvee_1Factory : public IGameObjectFactory
	{
	public:
		CGameObjectHumvee_1Factory();
		~CGameObjectHumvee_1Factory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTHUMVEE_1_H__
