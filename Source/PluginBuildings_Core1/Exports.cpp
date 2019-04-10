#define DLL_EXPORT

#include "Exports.h"
#include "Plugins/PluginTypes.h"

#include "CBuildingBigOilTanker.h"
#include "CBuildingBigOilTanker_lod3.h"
#include "CBuildingBrokenHouse.h"
#include "CBuildingBrokenHouse_lod3.h"
#include "CBuildingElectricTower.h"
#include "CBuildingElectricTower_lod2.h"
#include "CBuildingHall1.h"
#include "CBuildingHall1_lod2.h"
#include "CBuildingHall3.h"
#include "CBuildingHall3_lod2.h"
#include "CBuildingHall4.h"
#include "CBuildingHall4_lod2.h"
#include "CBuildingHallWithInterior.h"
#include "CBuildingHallWithInterior_lod2.h"
#include "CBuildingHQMilitiaTentShape.h"
#include "CBuildingOilPump.h"
#include "CBuildingOilTank.h"
#include "CBuildingOilTank2.h"
#include "CBuildingOilTank2_lod2.h"
#include "CBuildingOilTank6.h"
#include "CBuildingOilTank6_lod2.h"
#include "CBuildingOldHouse1.h"
#include "CBuildingOldHouse1_lod2.h"
#include "CBuildingOldHouse10.h"
#include "CBuildingOldHouse10_lod.h"
#include "CBuildingOldHouse11.h"
#include "CBuildingOldHouse11_lod2.h"
#include "CBuildingOldHouse2.h"
#include "CBuildingOldHouse2_lod2.h"
#include "CBuildingOldHouse3.h"
#include "CBuildingOldHouse4.h"
#include "CBuildingOldHouse4_lod2.h"
#include "CBuildingOldHouse4Socket.h"
#include "CBuildingOldHouse5.h"
#include "CBuildingOldHouse5_lod2.h"
#include "CBuildingOldHouse6.h"
#include "CBuildingOldHouse6_lod2.h"
#include "CBuildingOldHouse7.h"
#include "CBuildingOldHouse7_lod2.h"
#include "CBuildingOldHouse8.h"
#include "CBuildingOldHouse8_lod.h"
#include "CBuildingOldHouse9.h"
#include "CBuildingOldHouse9_lod2.h"
#include "CBuildingOldShed.h"
#include "CBuildingOpenedHall.h"
#include "CBuildingOpenedHall_lod1.h"
#include "CBuildingRuinedHall.h"
#include "CBuildingSilo1.h"
#include "CBuildingSilo1_lod2.h"
#include "CBuildingTank1.h"
#include "CBuildingTank1_lod2.h"
#include "CBuildingTower.h"
#include "CBuildingTower_lod.h"
#include "CBuildingTowerRedWhite.h"
#include "CBuildingTowerRedWhite_lod1.h"
#include "CBuildingVillage_church.h"
#include "CBuildingVillage_house1.h"
#include "CBuildingVillage_house2.h"
#include "CBuildingVillage_house3.h"
#include "CBuildingVillage_house4.h"
#include "CBuildingVillage_house5.h"
#include "CBuildingVillage_house6.h"
#include "CBuildingVillage_house7.h"
#include "CBuildingVillageRoadTCross.h"

namespace Core
{
namespace Plugin
{
	CBuildingBigOilTankerFactory*	BuildingBigOilTankerFactory = nullptr;
	CBuildingBigOilTanker_lod3Factory*	BuildingBigOilTanker_lod3Factory = nullptr;
	CBuildingBrokenHouseFactory*	BuildingBrokenHouseFactory = nullptr;
	CBuildingBrokenHouse_lod3Factory*	BuildingBrokenHouse_lod3Factory = nullptr;
	CBuildingElectricTowerFactory*	BuildingElectricTowerFactory = nullptr;
	CBuildingElectricTower_lod2Factory*	BuildingElectricTower_lod2Factory = nullptr;
	CBuildingHall1Factory*	BuildingHall1Factory = nullptr;
	CBuildingHall1_lod2Factory*	BuildingHall1_lod2Factory = nullptr;
	CBuildingHall3Factory*	BuildingHall3Factory = nullptr;
	CBuildingHall3_lod2Factory*	BuildingHall3_lod2Factory = nullptr;
	CBuildingHall4Factory*	BuildingHall4Factory = nullptr;
	CBuildingHall4_lod2Factory*	BuildingHall4_lod2Factory = nullptr;
	CBuildingHallWithInteriorFactory*	BuildingHallWithInteriorFactory = nullptr;
	CBuildingHallWithInterior_lod2Factory*	BuildingHallWithInterior_lod2Factory = nullptr;
	CBuildingHQMilitiaTentShapeFactory*	BuildingHQMilitiaTentShapeFactory = nullptr;
	CBuildingOilPumpFactory*	BuildingOilPumpFactory = nullptr;
	CBuildingOilTankFactory*	BuildingOilTankFactory = nullptr;
	CBuildingOilTank2Factory*	BuildingOilTank2Factory = nullptr;
	CBuildingOilTank2_lod2Factory*	BuildingOilTank2_lod2Factory = nullptr;
	CBuildingOilTank6Factory*	BuildingOilTank6Factory = nullptr;
	CBuildingOilTank6_lod2Factory*	BuildingOilTank6_lod2Factory = nullptr;
	CBuildingOldHouse1Factory*	BuildingOldHouse1Factory = nullptr;
	CBuildingOldHouse1_lod2Factory*	BuildingOldHouse1_lod2Factory = nullptr;
	CBuildingOldHouse10Factory*	BuildingOldHouse10Factory = nullptr;
	CBuildingOldHouse10_lodFactory*	BuildingOldHouse10_lodFactory = nullptr;
	CBuildingOldHouse11Factory*	BuildingOldHouse11Factory = nullptr;
	CBuildingOldHouse11_lod2Factory*	BuildingOldHouse11_lod2Factory = nullptr;
	CBuildingOldHouse2Factory*	BuildingOldHouse2Factory = nullptr;
	CBuildingOldHouse2_lod2Factory*	BuildingOldHouse2_lod2Factory = nullptr;
	CBuildingOldHouse3Factory*	BuildingOldHouse3Factory = nullptr;
	CBuildingOldHouse4Factory*	BuildingOldHouse4Factory = nullptr;
	CBuildingOldHouse4_lod2Factory*	BuildingOldHouse4_lod2Factory = nullptr;
	CBuildingOldHouse4SocketFactory*	BuildingOldHouse4SocketFactory = nullptr;
	CBuildingOldHouse5Factory*	BuildingOldHouse5Factory = nullptr;
	CBuildingOldHouse5_lod2Factory*	BuildingOldHouse5_lod2Factory = nullptr;
	CBuildingOldHouse6Factory*	BuildingOldHouse6Factory = nullptr;
	CBuildingOldHouse6_lod2Factory*	BuildingOldHouse6_lod2Factory = nullptr;
	CBuildingOldHouse7Factory*	BuildingOldHouse7Factory = nullptr;
	CBuildingOldHouse7_lod2Factory*	BuildingOldHouse7_lod2Factory = nullptr;
	CBuildingOldHouse8Factory*	BuildingOldHouse8Factory = nullptr;
	CBuildingOldHouse8_lodFactory*	BuildingOldHouse8_lodFactory = nullptr;
	CBuildingOldHouse9Factory*	BuildingOldHouse9Factory = nullptr;
	CBuildingOldHouse9_lod2Factory*	BuildingOldHouse9_lod2Factory = nullptr;
	CBuildingOldShedFactory*	BuildingOldShedFactory = nullptr;
	CBuildingOpenedHallFactory*	BuildingOpenedHallFactory = nullptr;
	CBuildingOpenedHall_lod1Factory*	BuildingOpenedHall_lod1Factory = nullptr;
	CBuildingRuinedHallFactory*	BuildingRuinedHallFactory = nullptr;
	CBuildingSilo1Factory*	BuildingSilo1Factory = nullptr;
	CBuildingSilo1_lod2Factory*	BuildingSilo1_lod2Factory = nullptr;
	CBuildingTank1Factory*	BuildingTank1Factory = nullptr;
	CBuildingTank1_lod2Factory*	BuildingTank1_lod2Factory = nullptr;
	CBuildingTowerFactory*	BuildingTowerFactory = nullptr;
	CBuildingTower_lodFactory*	BuildingTower_lodFactory = nullptr;
	CBuildingTowerRedWhiteFactory*	BuildingTowerRedWhiteFactory = nullptr;
	CBuildingTowerRedWhite_lod1Factory*	BuildingTowerRedWhite_lod1Factory = nullptr;
	CBuildingVillage_churchFactory*	BuildingVillage_churchFactory = nullptr;
	CBuildingVillage_house1Factory*	BuildingVillage_house1Factory = nullptr;
	CBuildingVillage_house2Factory*	BuildingVillage_house2Factory = nullptr;
	CBuildingVillage_house3Factory*	BuildingVillage_house3Factory = nullptr;
	CBuildingVillage_house4Factory*	BuildingVillage_house4Factory = nullptr;
	CBuildingVillage_house5Factory*	BuildingVillage_house5Factory = nullptr;
	CBuildingVillage_house6Factory*	BuildingVillage_house6Factory = nullptr;
	CBuildingVillage_house7Factory*	BuildingVillage_house7Factory = nullptr;
	CBuildingVillageRoadTCrossFactory*	BuildingVillageRoadTCrossFactory = nullptr;

	extern "C"
	{
		DECLDIR void GetFactories(Vector<IBuildingFactory*>& list)
		{
			BuildingBigOilTankerFactory = new CBuildingBigOilTankerFactory();
			BuildingBigOilTanker_lod3Factory = new CBuildingBigOilTanker_lod3Factory();
			BuildingBrokenHouseFactory = new CBuildingBrokenHouseFactory();
			BuildingBrokenHouse_lod3Factory = new CBuildingBrokenHouse_lod3Factory();
			BuildingElectricTowerFactory = new CBuildingElectricTowerFactory();
			BuildingElectricTower_lod2Factory = new CBuildingElectricTower_lod2Factory();
			BuildingHall1Factory = new CBuildingHall1Factory();
			BuildingHall1_lod2Factory = new CBuildingHall1_lod2Factory();
			BuildingHall3Factory = new CBuildingHall3Factory();
			BuildingHall3_lod2Factory = new CBuildingHall3_lod2Factory();
			BuildingHall4Factory = new CBuildingHall4Factory();
			BuildingHall4_lod2Factory = new CBuildingHall4_lod2Factory();
			BuildingHallWithInteriorFactory = new CBuildingHallWithInteriorFactory();
			BuildingHallWithInterior_lod2Factory = new CBuildingHallWithInterior_lod2Factory();
			BuildingHQMilitiaTentShapeFactory = new CBuildingHQMilitiaTentShapeFactory();
			BuildingOilPumpFactory = new CBuildingOilPumpFactory();
			BuildingOilTankFactory = new CBuildingOilTankFactory();
			BuildingOilTank2Factory = new CBuildingOilTank2Factory();
			BuildingOilTank2_lod2Factory = new CBuildingOilTank2_lod2Factory();
			BuildingOilTank6Factory = new CBuildingOilTank6Factory();
			BuildingOilTank6_lod2Factory = new CBuildingOilTank6_lod2Factory();
			BuildingOldHouse1Factory = new CBuildingOldHouse1Factory();
			BuildingOldHouse1_lod2Factory = new CBuildingOldHouse1_lod2Factory();
			BuildingOldHouse10Factory = new CBuildingOldHouse10Factory();
			BuildingOldHouse10_lodFactory = new CBuildingOldHouse10_lodFactory();
			BuildingOldHouse11Factory = new CBuildingOldHouse11Factory();
			BuildingOldHouse11_lod2Factory = new CBuildingOldHouse11_lod2Factory();
			BuildingOldHouse2Factory = new CBuildingOldHouse2Factory();
			BuildingOldHouse2_lod2Factory = new CBuildingOldHouse2_lod2Factory();
			BuildingOldHouse3Factory = new CBuildingOldHouse3Factory();
			BuildingOldHouse4Factory = new CBuildingOldHouse4Factory();
			BuildingOldHouse4_lod2Factory = new CBuildingOldHouse4_lod2Factory();
			BuildingOldHouse4SocketFactory = new CBuildingOldHouse4SocketFactory();
			BuildingOldHouse5Factory = new CBuildingOldHouse5Factory();
			BuildingOldHouse5_lod2Factory = new CBuildingOldHouse5_lod2Factory();
			BuildingOldHouse6Factory = new CBuildingOldHouse6Factory();
			BuildingOldHouse6_lod2Factory = new CBuildingOldHouse6_lod2Factory();
			BuildingOldHouse7Factory = new CBuildingOldHouse7Factory();
			BuildingOldHouse7_lod2Factory = new CBuildingOldHouse7_lod2Factory();
			BuildingOldHouse8Factory = new CBuildingOldHouse8Factory();
			BuildingOldHouse8_lodFactory = new CBuildingOldHouse8_lodFactory();
			BuildingOldHouse9Factory = new CBuildingOldHouse9Factory();
			BuildingOldHouse9_lod2Factory = new CBuildingOldHouse9_lod2Factory();
			BuildingOldShedFactory = new CBuildingOldShedFactory();
			BuildingOpenedHallFactory = new CBuildingOpenedHallFactory();
			BuildingOpenedHall_lod1Factory = new CBuildingOpenedHall_lod1Factory();
			BuildingRuinedHallFactory = new CBuildingRuinedHallFactory();
			BuildingSilo1Factory = new CBuildingSilo1Factory();
			BuildingSilo1_lod2Factory = new CBuildingSilo1_lod2Factory();
			BuildingTank1Factory = new CBuildingTank1Factory();
			BuildingTank1_lod2Factory = new CBuildingTank1_lod2Factory();
			BuildingTowerFactory = new CBuildingTowerFactory();
			BuildingTower_lodFactory = new CBuildingTower_lodFactory();
			BuildingTowerRedWhiteFactory = new CBuildingTowerRedWhiteFactory();
			BuildingTowerRedWhite_lod1Factory = new CBuildingTowerRedWhite_lod1Factory();
			BuildingVillage_churchFactory = new CBuildingVillage_churchFactory();
			BuildingVillage_house1Factory = new CBuildingVillage_house1Factory();
			BuildingVillage_house2Factory = new CBuildingVillage_house2Factory();
			BuildingVillage_house3Factory = new CBuildingVillage_house3Factory();
			BuildingVillage_house4Factory = new CBuildingVillage_house4Factory();
			BuildingVillage_house5Factory = new CBuildingVillage_house5Factory();
			BuildingVillage_house6Factory = new CBuildingVillage_house6Factory();
			BuildingVillage_house7Factory = new CBuildingVillage_house7Factory();
			BuildingVillageRoadTCrossFactory = new CBuildingVillageRoadTCrossFactory();

			if (BuildingBigOilTankerFactory)
				list.push_back(BuildingBigOilTankerFactory);

			if (BuildingBigOilTanker_lod3Factory)
				list.push_back(BuildingBigOilTanker_lod3Factory);

			if (BuildingBrokenHouseFactory)
				list.push_back(BuildingBrokenHouseFactory);

			if (BuildingBrokenHouse_lod3Factory)
				list.push_back(BuildingBrokenHouse_lod3Factory);

			if (BuildingElectricTowerFactory)
				list.push_back(BuildingElectricTowerFactory);

			if (BuildingElectricTower_lod2Factory)
				list.push_back(BuildingElectricTower_lod2Factory);

			if (BuildingHall1Factory)
				list.push_back(BuildingHall1Factory);

			if (BuildingHall1_lod2Factory)
				list.push_back(BuildingHall1_lod2Factory);

			if (BuildingHall3Factory)
				list.push_back(BuildingHall3Factory);

			if (BuildingHall3_lod2Factory)
				list.push_back(BuildingHall3_lod2Factory);

			if (BuildingHall4Factory)
				list.push_back(BuildingHall4Factory);

			if (BuildingHall4_lod2Factory)
				list.push_back(BuildingHall4_lod2Factory);

			if (BuildingHallWithInteriorFactory)
				list.push_back(BuildingHallWithInteriorFactory);

			if (BuildingHallWithInterior_lod2Factory)
				list.push_back(BuildingHallWithInterior_lod2Factory);

			if (BuildingHQMilitiaTentShapeFactory)
				list.push_back(BuildingHQMilitiaTentShapeFactory);

			if (BuildingOilPumpFactory)
				list.push_back(BuildingOilPumpFactory);

			if (BuildingOilTankFactory)
				list.push_back(BuildingOilTankFactory);

			if (BuildingOilTank2Factory)
				list.push_back(BuildingOilTank2Factory);

			if (BuildingOilTank2_lod2Factory)
				list.push_back(BuildingOilTank2_lod2Factory);

			if (BuildingOilTank6Factory)
				list.push_back(BuildingOilTank6Factory);

			if (BuildingOilTank6_lod2Factory)
				list.push_back(BuildingOilTank6_lod2Factory);

			if (BuildingOldHouse1Factory)
				list.push_back(BuildingOldHouse1Factory);

			if (BuildingOldHouse1_lod2Factory)
				list.push_back(BuildingOldHouse1_lod2Factory);

			if (BuildingOldHouse10Factory)
				list.push_back(BuildingOldHouse10Factory);

			if (BuildingOldHouse10_lodFactory)
				list.push_back(BuildingOldHouse10_lodFactory);

			if (BuildingOldHouse11Factory)
				list.push_back(BuildingOldHouse11Factory);

			if (BuildingOldHouse11_lod2Factory)
				list.push_back(BuildingOldHouse11_lod2Factory);

			if (BuildingOldHouse2Factory)
				list.push_back(BuildingOldHouse2Factory);

			if (BuildingOldHouse2_lod2Factory)
				list.push_back(BuildingOldHouse2_lod2Factory);

			if (BuildingOldHouse3Factory)
				list.push_back(BuildingOldHouse3Factory);

			if (BuildingOldHouse4Factory)
				list.push_back(BuildingOldHouse4Factory);

			if (BuildingOldHouse4_lod2Factory)
				list.push_back(BuildingOldHouse4_lod2Factory);

			if (BuildingOldHouse4SocketFactory)
				list.push_back(BuildingOldHouse4SocketFactory);

			if (BuildingOldHouse5Factory)
				list.push_back(BuildingOldHouse5Factory);

			if (BuildingOldHouse5_lod2Factory)
				list.push_back(BuildingOldHouse5_lod2Factory);

			if (BuildingOldHouse6Factory)
				list.push_back(BuildingOldHouse6Factory);

			if (BuildingOldHouse6_lod2Factory)
				list.push_back(BuildingOldHouse6_lod2Factory);

			if (BuildingOldHouse7Factory)
				list.push_back(BuildingOldHouse7Factory);

			if (BuildingOldHouse7_lod2Factory)
				list.push_back(BuildingOldHouse7_lod2Factory);

			if (BuildingOldHouse8Factory)
				list.push_back(BuildingOldHouse8Factory);

			if (BuildingOldHouse8_lodFactory)
				list.push_back(BuildingOldHouse8_lodFactory);

			if (BuildingOldHouse9Factory)
				list.push_back(BuildingOldHouse9Factory);

			if (BuildingOldHouse9_lod2Factory)
				list.push_back(BuildingOldHouse9_lod2Factory);

			if (BuildingOldShedFactory)
				list.push_back(BuildingOldShedFactory);

			if (BuildingOpenedHallFactory)
				list.push_back(BuildingOpenedHallFactory);

			if (BuildingOpenedHall_lod1Factory)
				list.push_back(BuildingOpenedHall_lod1Factory);

			if (BuildingRuinedHallFactory)
				list.push_back(BuildingRuinedHallFactory);

			if (BuildingSilo1Factory)
				list.push_back(BuildingSilo1Factory);

			if (BuildingSilo1_lod2Factory)
				list.push_back(BuildingSilo1_lod2Factory);

			if (BuildingTank1Factory)
				list.push_back(BuildingTank1Factory);

			if (BuildingTank1_lod2Factory)
				list.push_back(BuildingTank1_lod2Factory);

			if (BuildingTowerFactory)
				list.push_back(BuildingTowerFactory);

			if (BuildingTower_lodFactory)
				list.push_back(BuildingTower_lodFactory);

			if (BuildingTowerRedWhiteFactory)
				list.push_back(BuildingTowerRedWhiteFactory);

			if (BuildingTowerRedWhite_lod1Factory)
				list.push_back(BuildingTowerRedWhite_lod1Factory);

			if (BuildingVillage_churchFactory)
				list.push_back(BuildingVillage_churchFactory);

			if (BuildingVillage_house1Factory)
				list.push_back(BuildingVillage_house1Factory);

			if (BuildingVillage_house2Factory)
				list.push_back(BuildingVillage_house2Factory);

			if (BuildingVillage_house3Factory)
				list.push_back(BuildingVillage_house3Factory);

			if (BuildingVillage_house4Factory)
				list.push_back(BuildingVillage_house4Factory);

			if (BuildingVillage_house5Factory)
				list.push_back(BuildingVillage_house5Factory);

			if (BuildingVillage_house6Factory)
				list.push_back(BuildingVillage_house6Factory);

			if (BuildingVillage_house7Factory)
				list.push_back(BuildingVillage_house7Factory);

			if (BuildingVillageRoadTCrossFactory)
				list.push_back(BuildingVillageRoadTCrossFactory);

		}
		DECLDIR E_PLUGIN GetPluginType(void)
		{
			return Core::Plugin::EP_BUILDING;
		}
	}
}
}
