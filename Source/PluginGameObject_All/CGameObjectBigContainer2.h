#ifndef __CGAMEOBJECTBIGCONTAINER2_H__
#define __CGAMEOBJECTBIGCONTAINER2_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectBigContainer2 : public CGameObject
	{
	public:
		CGameObjectBigContainer2(const char* Name, Vector3& Pos);
		~CGameObjectBigContainer2();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectBigContainer2Factory : public IGameObjectFactory
	{
	public:
		CGameObjectBigContainer2Factory();
		~CGameObjectBigContainer2Factory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTBIGCONTAINER2_H__
