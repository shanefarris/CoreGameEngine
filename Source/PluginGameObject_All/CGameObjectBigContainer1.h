#ifndef __CGAMEOBJECTBIGCONTAINER1_H__
#define __CGAMEOBJECTBIGCONTAINER1_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectBigContainer1 : public CGameObject
	{
	public:
		CGameObjectBigContainer1(const char* Name, Vector3& Pos);
		~CGameObjectBigContainer1();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectBigContainer1Factory : public IGameObjectFactory
	{
	public:
		CGameObjectBigContainer1Factory();
		~CGameObjectBigContainer1Factory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTBIGCONTAINER1_H__
