#define DLL_EXPORT

#include "Plugins/IAiStateFactory.h"
#include "CAiState_SeekObstacle.h"
#include "CAiState_Wander.h"
#include "CAiState_Seek.h"
#include "CAiState_Evade.h"
#include "CAiState_FollowPath.h"
#include "CAiState_SeekWeapon.h"
#include "CAiState_FindEnemy.h"
#include "CAiState_AttackEnemy.h"
#include "CAiState_Defend.h"

using namespace Core;
using namespace Core::Plugin;

namespace Core
{
namespace Plugin
{
	CAiState_SeekObstacleFactory*	AiFactory_SeekObs = nullptr;
	CAiState_WanderFactory*			AiFactory_Wander = nullptr;
	CAiState_SeekFactory*			AiFactory_Seek = nullptr;
	CAiState_EvadeFactory*			AiFactory_Evade = nullptr;
	CAiState_FollowPathFactory*		AiFactory_FollowPath = nullptr;
	CAiState_SeekWeaponFactory*		AiFactory_FindWeapon = nullptr;
	CAiState_FindEnemyFactory*		AiFactory_FindEnemy = nullptr;
	CAiState_AttackEnemyFactory*	AiState_AttackEnemy = nullptr;
	CAiState_DefendFactory*			AiState_Defend = nullptr;

	extern "C"
	{
		DECLDIR void GetFactories(Vector<Core::Plugin::IAiStateFactory*>& list)
		{
			AiFactory_SeekObs = new CAiState_SeekObstacleFactory();
			if(AiFactory_SeekObs)
				list.push_back(AiFactory_SeekObs);

			AiFactory_Wander = new CAiState_WanderFactory();
			if(AiFactory_Wander)
				list.push_back(AiFactory_Wander);

			AiFactory_Seek = new CAiState_SeekFactory();
			if(AiFactory_Seek)
				list.push_back(AiFactory_Seek);

			AiFactory_Evade = new CAiState_EvadeFactory();
			if(AiFactory_Evade)
				list.push_back(AiFactory_Evade);

			AiFactory_FollowPath = new CAiState_FollowPathFactory();
			if(AiFactory_FollowPath)
				list.push_back(AiFactory_FollowPath);

			AiFactory_FindWeapon = new CAiState_SeekWeaponFactory();
			if(AiFactory_FindWeapon)
				list.push_back(AiFactory_FindWeapon);
				
			AiFactory_FindEnemy = new CAiState_FindEnemyFactory();
			if(AiFactory_FindEnemy)
				list.push_back(AiFactory_FindEnemy);
				
			AiState_AttackEnemy = new CAiState_AttackEnemyFactory();
			if(AiState_AttackEnemy)
				list.push_back(AiState_AttackEnemy);

			AiState_Defend = new CAiState_DefendFactory();
			if(AiState_Defend)
				list.push_back(AiState_Defend);
		}

		DECLDIR Core::Plugin::E_PLUGIN GetPluginType(void)
		{
			return Core::Plugin::EP_AI_STATE;
		}
	}
}
}