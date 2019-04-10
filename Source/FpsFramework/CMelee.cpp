#include "CMelee.h"
#include "IPhysicsStrategy.h"
#include "CGameManager.h"
#include "CPlayer.h"

#include "OgreSceneManager.h"
#include "OgreSceneQuery.h"

using namespace Core;
using namespace Core::Physics;

CMelee::CMelee(const CItemProfile& Profile, Physics::IPhysicsStrategy* Physics) 
	: CInventoryItem(Profile, Physics),
	m_RaySceneQuery(nullptr)
{	
	m_RaySceneQuery = CGameManager::Instance()->GetSceneManager()->createRayQuery(Ogre::Ray());
	m_RaySceneQuery->setSortByDistance(true);
	m_RaySceneQuery->setQueryMask(SQF_PLAYER);
	m_RaySceneQuery->setQueryTypeMask(SceneManager::ENTITY_TYPE_MASK);
}

CMelee::~CMelee()
{
	CGameManager::Instance()->GetSceneManager()->destroyQuery(m_RaySceneQuery);
}

bool CMelee::Use(const Vector3& Target)
{
	if(m_Player)
	{
		if(m_CoolDown <= 0.0f)
		{
			Ray ray(m_Player->GetPosition() + Vector3(0, 3.0f, 0), Target);
			m_RaySceneQuery->setRay(ray);
			RaySceneQueryResult &result = m_RaySceneQuery->execute();
			for(auto it = result.begin(); it != result.end(); it++)
			{
				if (it->movable->getQueryFlags() == SQF_PLAYER && it->distance <= m_Profile.Range)
				{
					auto coreEntityObject = any_cast<CoreEntityObject*>(it->movable->getUserAny());
					if(coreEntityObject)
					{
						if(coreEntityObject->Player)
						{
							if(coreEntityObject->Player->GetPlayerTeam() != m_Player->GetPlayerTeam())
							{
								coreEntityObject->Player->OnHit(this, m_Player, Target);
							}
						}
					}
				}
				else if(it->distance > m_Profile.Range)
				{
					break;
				}
			}

			m_CoolDown = m_Profile.UseTime;
			return true;
		}
	}
	return false;
}

void CMelee::Update(const f32& elapsedTime)
{
	// Update our shot time
	if(m_CoolDown > 0.0f)
		m_CoolDown -= elapsedTime;
}
