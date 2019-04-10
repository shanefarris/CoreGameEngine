#ifndef __CGAMEOBJECTBENCH_H__
#define __CGAMEOBJECTBENCH_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectBench : public CGameObject
	{
	public:
		CGameObjectBench(const char* Name, Vector3& Pos);
		~CGameObjectBench();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectBenchFactory : public IGameObjectFactory
	{
	public:
		CGameObjectBenchFactory();
		~CGameObjectBenchFactory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTBENCH_H__
