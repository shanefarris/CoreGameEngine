#ifndef __CGAMEOBJECTGASPIPELONG_H__
#define __CGAMEOBJECTGASPIPELONG_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectGasPipeLong : public CGameObject
	{
	public:
		CGameObjectGasPipeLong(const char* Name, Vector3& Pos);
		~CGameObjectGasPipeLong();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectGasPipeLongFactory : public IGameObjectFactory
	{
	public:
		CGameObjectGasPipeLongFactory();
		~CGameObjectGasPipeLongFactory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTGASPIPELONG_H__
