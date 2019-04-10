#include "CAiState_Evade.h"
#include "CPlayer.h"
#include "Ai/CFpsVehicle.h"
#include "Ai/Obstacle.h"

using namespace Core;
using namespace Core::AI;
using namespace Core::Plugin;

CAiState_Evade::CAiState_Evade(CPlayer* Player) : CCharacterState(Player)
{
	m_State = WORKING;
	m_StateType = EPS_EVADING;
	m_StateLabel = "Evade";
	m_Level = 1;
}

E_CHARACTER_STATE_OUTCOME CAiState_Evade::Update(f32 elapsedTime) 
{
	//Vector3 evade (0, 0, 0);
//      const float goalDistance = Vec3Utilities::distance (gHomeBaseCenter, position());

//      // sum up weighted evasion
//      for (int i = 0; i < ctfEnemyCount; i++)
//      {
//          const CtfEnemy& e = *ctfEnemies[i];
//          const Vector3 eOffset = e.position() - position();
//          const float eDistance = eOffset.length();

//          const float eForwardDistance = forward().dotProduct (eOffset);
//          const float behindThreshold = radius() * 2;
//          const bool behind = eForwardDistance < behindThreshold;
//          if ((!behind) || (eDistance < 5))
//          {
//              if (eDistance < (goalDistance * 1.2)) //xxx
//              {
//                  // const float timeEstimate = 0.5f * eDistance / e.speed;//xxx
//                  const float timeEstimate = 0.15f * eDistance / e.speed();//xxx
//                  const Vector3 future =
//                      e.predictFuturePosition (timeEstimate);

//                  annotationXZCircle (e.radius(), future, evadeColor, 20); // xxx

//                  const Vector3 offset = future - position();
//                  const Vector3 lateral = offset.perpendicularComponent (forward());
//                  const float d = lateral.length();
//                  const float weight = -1000 / (d * d);
//                  evade += (lateral / d) * weight;
//              }
//          }
//      }
//      return evade;

	return m_State;
}

CAiState_EvadeFactory::CAiState_EvadeFactory()
{
	LabelName = "Evade";
	Type = EPS_EVADING;
	Level = 1;
}

CAiState_EvadeFactory::~CAiState_EvadeFactory() 
{ 
}

Core::AI::CCharacterState* CAiState_EvadeFactory::GetCharacterState(CPlayer* Player)
{
	return new CAiState_Evade(Player);
}