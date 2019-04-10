#ifndef __CGAMEOBJECTARMYCOLT_H__
#define __CGAMEOBJECTARMYCOLT_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectArmycolt : public CGameObject
	{
	public:
		CGameObjectArmycolt(const char* Name, Vector3& Pos);
		~CGameObjectArmycolt();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectArmycoltFactory : public IGameObjectFactory
	{
	public:
		CGameObjectArmycoltFactory();
		~CGameObjectArmycoltFactory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTARMYCOLT_H__
