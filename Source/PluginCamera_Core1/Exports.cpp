#define DLL_EXPORT

#include "Exports.h"
#include "Plugins/ICameraFactory.h"
#include "Factories.h"

namespace Core
{
namespace Plugin
{
	CCameraFactory_Fixed*			FixedCamera = nullptr;
	CCameraFactory_RTS*				RtsCamera = nullptr;
	CCameraFactory_Free*			FreeCamera = nullptr;
	CCameraFactory_ChaseSpaceShip*	ChaseSpaceShipCamera = nullptr;

	extern "C"
	{
		DECLDIR void GetFactories(Vector<ICameraFactory*>& list)
		{
			FixedCamera = new CCameraFactory_Fixed();
			if(FixedCamera)
				list.push_back(FixedCamera);

			RtsCamera = new CCameraFactory_RTS();
			if(RtsCamera)
				list.push_back(RtsCamera);

			FreeCamera = new CCameraFactory_Free();
			if(FreeCamera)
				list.push_back(FreeCamera);

			ChaseSpaceShipCamera = new CCameraFactory_ChaseSpaceShip();
			if(ChaseSpaceShipCamera)
				list.push_back(ChaseSpaceShipCamera);
		}

		DECLDIR E_PLUGIN GetPluginType(void)
		{
			return Core::Plugin::EP_CAMERA;
		}
	}

}
}