#define DLL_EXPORT

#include "Exports.h"
#include "CGameObjectCrate.h"
#include "CGameObjectFAB1.h"
#include "CGameObjectSphere.h"

namespace Core
{
namespace Plugin
{
	CGameObjectCrateFactory*	GameObjectCrateFactory = nullptr;
	CGameObjectFAB1Factory*		GameObjectFAB1Factory = nullptr;
	CGameObjectSphereFactory*   GameObjectSphereFactory = nullptr;
	CGameObjectSpawnPointFactory*   GameObjectSpawnPointFactory = nullptr;

	extern "C"
	{
		DECLDIR void GetFactories(Vector<IGameObjectFactory*>& list)
		{
			GameObjectCrateFactory = new CGameObjectCrateFactory();
			GameObjectFAB1Factory = new CGameObjectFAB1Factory();
			GameObjectSphereFactory = new CGameObjectSphereFactory();
			GameObjectSpawnPointFactory = new CGameObjectSpawnPointFactory();

			if(GameObjectCrateFactory)
				list.push_back(GameObjectCrateFactory);

			if(GameObjectFAB1Factory)
				list.push_back(GameObjectFAB1Factory);

			if(GameObjectSphereFactory)
				list.push_back(GameObjectSphereFactory);

			if(GameObjectSpawnPointFactory)
				list.push_back(GameObjectSpawnPointFactory);
		}

		DECLDIR E_PLUGIN GetPluginType(void)
		{
			return Core::Plugin::EP_OBJECT_FACTORY;
		}
	}

}
}