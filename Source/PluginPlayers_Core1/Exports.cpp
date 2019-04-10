#define DLL_EXPORT

#include "Exports.h"
#include "Plugins/PluginTypes.h"

#include "CPlayerSas.h"
#include "CPlayerGenmarine.h"
#include "CPlayerSoldier.h"
#include "CPlayerZombie_small.h"
#include "CPlayerFpsArms.h"

namespace Core
{
namespace Plugin
{
	CPlayerSasFactory*	PlayerSasFactory = nullptr;
	CPlayerGenmarineFactory*	PlayerGenmarineFactory = nullptr;
	CPlayerSoldierFactory*	PlayerSoldierFactory = nullptr;
	CPlayerZombie_smallFactory*	PlayerZombie_smallFactory = nullptr;
	CPlayerFpsArmsFactory* PlayerFpsArmsFactory = nullptr;

	extern "C"
	{
		DECLDIR void GetFactories(Vector<IPlayerFactory*>& list)
		{
			PlayerSasFactory = new CPlayerSasFactory();
			PlayerGenmarineFactory = new CPlayerGenmarineFactory();
			PlayerSoldierFactory = new CPlayerSoldierFactory();
			PlayerZombie_smallFactory = new CPlayerZombie_smallFactory();
			PlayerFpsArmsFactory = new CPlayerFpsArmsFactory();

			if (PlayerSasFactory)
				list.push_back(PlayerSasFactory);

			if (PlayerGenmarineFactory)
				list.push_back(PlayerGenmarineFactory);

			if (PlayerSoldierFactory)
				list.push_back(PlayerSoldierFactory);

			if (PlayerZombie_smallFactory)
				list.push_back(PlayerZombie_smallFactory);

			if (PlayerFpsArmsFactory)
				list.push_back(PlayerFpsArmsFactory);

		}
		DECLDIR E_PLUGIN GetPluginType(void)
		{
			return Core::Plugin::EP_PLAYER;
		}
	}
}
}
