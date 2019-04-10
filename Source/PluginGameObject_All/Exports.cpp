#define DLL_EXPORT

#include "Exports.h"
#include "CGameObjectAk47_1.h"
#include "CGameObjectAmmobox1.h"
#include "CGameObjectAppleGreen.h"
#include "CGameObjectAppleRed.h"
#include "CGameObjectArmycolt.h"
#include "CGameObjectAssaultrifleSig.h"
#include "CGameObjectAStarNode.h"
#include "CGameObjectBarrel01.h"
#include "CGameObjectBarrel2.h"
#include "CGameObjectBench.h"
#include "CGameObjectBigContainer1.h"
#include "CGameObjectBigContainer2.h"
#include "CGameObjectBowlSoup.h"
#include "CGameObjectBox1.h"


namespace Core
{
namespace Plugin
{
	CGameObjectAk47_1Factory*	GameObjectAk47_1Factory = nullptr;
	CGameObjectAmmobox1Factory*	GameObjectAmmobox1Factory = nullptr;
	CGameObjectAppleGreenFactory*	GameObjectAppleGreenFactory = nullptr;
	CGameObjectAppleRedFactory*	GameObjectAppleRedFactory = nullptr;
	CGameObjectArmycoltFactory*	GameObjectArmycoltFactory = nullptr;
	CGameObjectAssaultrifleSigFactory*	GameObjectAssaultrifleSigFactory = nullptr;
	CGameObjectAStarNodeFactory*	GameObjectAStarNodeFactory = nullptr;
	CGameObjectBarrel01Factory*	GameObjectBarrel01Factory = nullptr;
	CGameObjectBarrel2Factory*	GameObjectBarrel2Factory = nullptr;
	CGameObjectBenchFactory*	GameObjectBenchFactory = nullptr;
	CGameObjectBigContainer1Factory*	GameObjectBigContainer1Factory = nullptr;
	CGameObjectBigContainer2Factory*	GameObjectBigContainer2Factory = nullptr;
	CGameObjectBowlSoupFactory*	GameObjectBowlSoupFactory = nullptr;
	CGameObjectBox1Factory*	GameObjectBox1Factory = nullptr;
	

	extern "C"
	{
		DECLDIR void GetFactories(Vector<IGameObjectFactory*>& list)
		{
			GameObjectAk47_1Factory = new CGameObjectAk47_1Factory();
			GameObjectAmmobox1Factory = new CGameObjectAmmobox1Factory();
			GameObjectAppleGreenFactory = new CGameObjectAppleGreenFactory();
			GameObjectAppleRedFactory = new CGameObjectAppleRedFactory();
			GameObjectArmycoltFactory = new CGameObjectArmycoltFactory();
			GameObjectAssaultrifleSigFactory = new CGameObjectAssaultrifleSigFactory();
			GameObjectAStarNodeFactory = new CGameObjectAStarNodeFactory();
			GameObjectBarrel01Factory = new CGameObjectBarrel01Factory();
			GameObjectBarrel2Factory = new CGameObjectBarrel2Factory();
			GameObjectBenchFactory = new CGameObjectBenchFactory();
			GameObjectBigContainer1Factory = new CGameObjectBigContainer1Factory();
			GameObjectBigContainer2Factory = new CGameObjectBigContainer2Factory();
			GameObjectBowlSoupFactory = new CGameObjectBowlSoupFactory();
			GameObjectBox1Factory = new CGameObjectBox1Factory();
			

			if (GameObjectAk47_1Factory)
				list.push_back(GameObjectAk47_1Factory);

			if (GameObjectAmmobox1Factory)
				list.push_back(GameObjectAmmobox1Factory);

			if (GameObjectAppleGreenFactory)
				list.push_back(GameObjectAppleGreenFactory);

			if (GameObjectAppleRedFactory)
				list.push_back(GameObjectAppleRedFactory);

			if (GameObjectArmycoltFactory)
				list.push_back(GameObjectArmycoltFactory);

			if (GameObjectAssaultrifleSigFactory)
				list.push_back(GameObjectAssaultrifleSigFactory);

			if (GameObjectAStarNodeFactory)
				list.push_back(GameObjectAStarNodeFactory);

			if (GameObjectBarrel01Factory)
				list.push_back(GameObjectBarrel01Factory);

			if (GameObjectBarrel2Factory)
				list.push_back(GameObjectBarrel2Factory);

			if (GameObjectBenchFactory)
				list.push_back(GameObjectBenchFactory);

			if (GameObjectBigContainer1Factory)
				list.push_back(GameObjectBigContainer1Factory);

			if (GameObjectBigContainer2Factory)
				list.push_back(GameObjectBigContainer2Factory);

			if (GameObjectBowlSoupFactory)
				list.push_back(GameObjectBowlSoupFactory);

			if (GameObjectBox1Factory)
				list.push_back(GameObjectBox1Factory);

			

		}
		DECLDIR E_PLUGIN GetPluginType(void)
		{
			return Core::Plugin::EP_OBJECT_FACTORY;
		}
	}
}
}
