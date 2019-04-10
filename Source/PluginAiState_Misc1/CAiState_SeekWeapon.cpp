#include "CAiState_SeekWeapon.h"
#include "CPlayer.h"
#include "CItemsManager.h"
#include "CInventoryItem.h"
#include "CGameObject.h"
#include "Ai/CFpsVehicle.h"
#include "Ai/Obstacle.h"
#include "CTextOutput.h"
#include "CCharacterStateManager.h"
#include "CGameObject.h"
#include "IO/CoreLogging.h"

#include "OgreSceneNode.h"

using namespace Core;
using namespace Core::Plugin;

CAiState_SeekWeapon::CAiState_SeekWeapon(CPlayer* Player) : CCharacterState(Player)
{
	m_State = WORKING;
	m_StateType = EPS_SEEK_ITEM;
	m_StateLabel = "FindWeapon";
	m_Level = 1;
	m_CheckCount = 0;
	m_Target = Vector3::ZERO;
}

Core::AI::E_CHARACTER_STATE_OUTCOME CAiState_SeekWeapon::Update(f32 elapsedTime)
{
	if(m_Target == Vector3::ZERO)
	{
		CCharacterStateManager::Instance()->Wander(m_Player, elapsedTime);
		CORE_TEXT("CAiState_SeekWeapon", "looking for a weapon");

		if(m_CheckCount >= 10)
		{
			Vector<CInventoryItem*> items;
			CItemsManager::Instance()->GetPlacedItems(items);
			for(u32 i = 0; i < items.size(); i++)
			{
				if(m_Player->CanSee(items[i]->GetGameObject()->Node->getPosition()))
				{
					m_Target = items[i]->GetGameObject()->Node->getPosition();
					break;
				}
			}
			m_CheckCount = 0;
		}
		m_CheckCount++;
	}
	else
	{
		CCharacterStateManager::Instance()->SeekPosition(m_Player, m_Target, elapsedTime);
		CORE_TEXT("CAiState_SeekWeapon", "walking to a weapon");
	}

	return m_State;
}

CAiState_SeekWeaponFactory::CAiState_SeekWeaponFactory()
{
	LabelName = "FindWeapon";
	Type = EPS_SEEK_ITEM;
	Level = 0;
}

CAiState_SeekWeaponFactory::~CAiState_SeekWeaponFactory()
{
}

Core::AI::CCharacterState* CAiState_SeekWeaponFactory::GetCharacterState(CPlayer* Player)
{
	return new CAiState_SeekWeapon(Player);
}