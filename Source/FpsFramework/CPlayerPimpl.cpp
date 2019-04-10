#include "CPlayerPimpl.h"
#include "CPlayer.h"
#include "CWeapon.h"
#include "CMagazine.h"
#include "CProjectile.h"
#include "CUtility.h"
#include "CTextOutput.h"
#include "MovableTextOverlay.h"
#include "RectLayoutManager.h"
#include "CInventoryItem.h"
#include "MissionEvents.h"
#include "IMission.h"
#include "PlayerEnums.h"
#include "AnimationMapping.h"
#include "CInputEvent.h"
#include "CInputListener.h"

// Managers
#include "CGameManager.h"
#include "CScriptManager.h"
#include "CCameraManager.h"
#include "CItemsManager.h"
#include "CMissionManager.h"
#include "CGameObjectManager.h"
#include "CNatureManager.h"
#include "CInputManager.h"

// Physics
#include "IPhysicsStrategy.h"
#include "ICharacterController.h"
#include "IPhysicsRagdoll.h"
#include "PhysicsStructures.h"

// Components
#include "CPlayerSoundComponent.h"
#include "CPlayerAttributesComponent.h"
#include "CAiReactionComponent_Default.h"

// AI
#include "CCharacterState.h"
#include "Ai/CFpsVehicle.h"
#include "CEnvironmentObserver.h"
#include "CCharacterStateManager.h"
#include "CLineOfSightStrategy_Defaults.h"

// Ogre
#include "OgreEntity.h"
#include "OgreManualObject.h"
#include "OgreMaterialManager.h"
#include "OgreSceneNode.h"

#include "Terrain/OgreTerrainGroup.h"

using namespace Core;

CPlayerPimpl::CPlayerPimpl(const char* LabelName, Physics::IPhysicsStrategy* PhysicsStrategy)
	: Name(LabelName), 
	m_WalkSpeed(1.9f),
	m_RunSpeed(5.0f),	
	m_SprintSpeed(6.0f),	
	m_CrawlSpeed(0.3f),	
	m_ReloadSpeed(1.0f),
	m_Health(100),
	m_PickupRadius(0.0f),					// Means the node has to be exactly on the item
	m_DestinationRadius(0.1f),
	m_FallVelocity(5),
	m_DieingTime(5),						// Set 5 seconds for default
	m_ViewRange(500),						// Default range
	m_AnimationSpeed(1.0f),
	m_SightNode(nullptr),
	m_PlayerEntity(nullptr),
	m_PlayerNode(nullptr),
	isKilled(false),
	isVisible(true),						// Show the player by default
	isMovableText(false),					// Don't show text
	isHumanPlayer(false),					// Not human player
	isFpsView(false),
	isCharacterController(true),
	m_Movement(Vector3::ZERO),
	m_CCSize(DEFAULT_PROFILE_SIZE),
	m_CurrItem(nullptr),
	m_PlayerTeam(EPT_TEAM_3),				// Default team
	m_Lineofsight(nullptr),
	m_Target(nullptr),
	m_LosType(ELT_BASIC),
	m_AbstractVehicle(nullptr),
	m_CharacterState(nullptr),
	m_LineOfSightStrategy(nullptr),
	m_PhysicsStrategy(PhysicsStrategy),
	m_CharacterController(nullptr),
	m_PhysicsRagdoll(nullptr),
	m_AnimationState(nullptr),
	m_Ceo(nullptr),
	m_EnvironmentObserver(nullptr),		
	m_MovableTextOverlay(nullptr),
	m_Player(nullptr)
{
	m_GameManager = CGameManager::Instance();
	m_CameraManager = CCameraManager::Instance();
	m_ItemsManager = CItemsManager::Instance();
	m_GameObjectManager = CGameObjectManager::Instance();
	m_CharacterStateManager = AI::CCharacterStateManager::Instance();

	// create ray scene query for terrain
	m_TerrainRaySceneQuery = CGameManager::Instance()->GetSceneManager()->createRayQuery(Ray(Vector3::ZERO, Vector3::NEGATIVE_UNIT_Y));

	// For querying ojects for items
	m_ObjectQuery = m_GameManager->GetSceneManager()->createRayQuery(Ray());
	m_ObjectQuery->setQueryTypeMask(SceneManager::ENTITY_TYPE_MASK);
	m_ObjectQuery->setQueryMask(SQF_INVENTORY_ITEM);

	// For querying other players
	m_PlayerQuery = CGameManager::Instance()->GetSceneManager()->createRayQuery(Ray());
	m_PlayerQuery->setQueryTypeMask(SceneManager::ENTITY_TYPE_MASK);
	m_PlayerQuery->setQueryMask(SQF_PLAYER);

	// Set default animation state
	m_CurrAnimState = EAS_NONE;
	m_AnimState = EAS_NONE;

	// Set default characater state
	m_PlayerState = EPS_IDLE;

	// Set our sound helper class
	m_PlayerSoundComponent = new CPlayerSoundComponent();

	// Set our attributes helper class
	m_AttributesComponent = new CPlayerAttributesComponent();

	// Set default direction
	m_Direction = Vector3::UNIT_Z;
}

CPlayerPimpl::~CPlayerPimpl()
{
	// Scene queries
	if(m_ObjectQuery)
		m_GameManager->GetSceneManager()->destroyQuery(m_ObjectQuery);
	if(m_PlayerQuery)
		m_GameManager->GetSceneManager()->destroyQuery(m_PlayerQuery);

	if(m_PlayerNode)
	{
		m_PlayerNode->detachAllObjects();
		//delete mEntity;
		m_PlayerNode->removeAndDestroyAllChildren();
	}

	if(m_CharacterController)
	{
		if(m_PhysicsStrategy)
			m_PhysicsStrategy->RemoveCharacterController(m_CharacterController);
	}

	if(m_PhysicsRagdoll)
	{
		if(m_PhysicsStrategy)
		{
			m_PhysicsStrategy->RemoveRagdoll(m_PhysicsRagdoll);
		}
	}

	// Entity
	if(m_PlayerEntity)
		m_GameManager->GetSceneManager()->destroyEntity(m_PlayerEntity);

	// Components
	CORE_DELETE(m_LineOfSightStrategy);
	CORE_DELETE(m_PlayerSoundComponent);
	CORE_DELETE(m_AttributesComponent);
	CORE_DELETE(m_AiReactionComponent);

	// Others
	CORE_DELETE(m_AbstractVehicle);
	CORE_DELETE(m_CharacterState);
	CORE_DELETE(m_MovableTextOverlay);
	CORE_DELETE(m_Ceo);
	CORE_DELETE(m_EnvironmentObserver);
}

void CPlayerPimpl::PostInit(CPlayer* Player)
{
	m_Player = Player;

	// Setup our core entity data and attach
	m_Ceo = new CoreEntityObject();
	m_Ceo->Player = m_Player;
	m_Ceo->QueryType = SQF_PLAYER;
	m_PlayerEntity->setUserAny(Any(m_Ceo));

	if(m_PhysicsStrategy && isCharacterController && !m_CharacterController)
	{
		m_CharacterController = m_PhysicsStrategy->CreateCharacterController(m_Player);
	}

	// Set the default AI component
	m_AiReactionComponent = new CAiReactionComponent_Default(m_Player);

	// Set the query type
	m_PlayerEntity->setQueryFlags(SQF_PLAYER);

	// Setup movable text label
	if(isMovableText)
		TextLabelSetup();

	// Map animation names and sounds
	m_Player->SetupMapping();

	// Create the Environment Observer for our AI
	m_EnvironmentObserver = new CEnvironmentObserver(50.0f, m_Player);

	// Set the direction
	m_Direction = m_PlayerNode->getOrientation() * Vector3::UNIT_Z;
	m_PlayerNode->setDirection(m_Direction);

	// Setup AI
	m_AbstractVehicle = new AI::CFpsVehicle(m_Player);
	m_AbstractVehicle->SetUp(Vector3(0, 0, -1));
	m_AbstractVehicle->SetPosition(m_PlayerNode->getPosition());
	m_AbstractVehicle->SetSpeed(m_WalkSpeed);		// speed along Forward direction.
	m_AbstractVehicle->SetMaxForce(500.0f);		// steering force is clipped to this magnitude
	m_AbstractVehicle->SetMaxSpeed(m_WalkSpeed);	// velocity is clipped to this magnitude
	m_AbstractVehicle->SetRadius(2.0f);
	m_AbstractVehicle->SetForward(m_Direction * Vector3::NEGATIVE_UNIT_Z);

	// Create LoS strategy if it isn't already created
	if(!m_LineOfSightStrategy)
		SetLoSType(m_LosType);

}

void CPlayerPimpl::TextLabelSetup()
{
	CORE_DELETE(m_MovableTextOverlay);

	using namespace Core::OgreSpecific;

	Camera* cam = CCameraManager::Instance()->GetCamera();

	// Implementing the movable text overlay
	MovableTextOverlayAttributes *attrs = new MovableTextOverlayAttributes("Attrs1", cam, "BlueHigh", 16, ColourValue::White ,"RedTransparent");

	SceneNode* node = m_PlayerNode->createChildSceneNode(Name + "_MovableTextNode");
	node->setPosition(m_PlayerNode->getPosition() + Vector3(0, 10, 0));
	node->scale(Vector3(1, 1, 1));

	m_MovableTextOverlay = new MovableTextOverlay(String(Name + "TextLabel").c_str(), Name.c_str(), m_PlayerEntity, attrs);
	m_MovableTextOverlay->Enable(false);					// make it invisible for now
	m_MovableTextOverlay->SetUpdateFrequency(0.01f);			// set update frequency to 0.01 seconds
}

void CPlayerPimpl::UpdateTextLabel(const f32& elapsedTime)
{
	using namespace Core::OgreSpecific;

	if(!m_MovableTextOverlay->IsEnabled())
		return;

	Camera* cam = CCameraManager::Instance()->GetCamera();

	RectLayoutManager m(0, 0, (u32)cam->getViewport()->getActualWidth(), (u32)cam->getViewport()->getActualHeight());
	m.setDepth(0);

	m_MovableTextOverlay->Update(elapsedTime);
	if (m_MovableTextOverlay->IsOnScreen())
	{ 
		RectLayoutManager::Rect r((s16)m_MovableTextOverlay->GetPixelsLeft(), 
			(s16)m_MovableTextOverlay->GetPixelsTop(), 
			(s16)m_MovableTextOverlay->GetPixelsRight(), 
			(s16)m_MovableTextOverlay->GetPixelsBottom());

		RectLayoutManager::RectList::iterator it = m.addData(r);
		if (it != m.getListEnd())
		{
			m_MovableTextOverlay->SetPixelsTop((*it).getTop());
			m_MovableTextOverlay->Enable(true);
		}
		else
			m_MovableTextOverlay->Enable(false);
	}
	else
		m_MovableTextOverlay->Enable(false);
}

void CPlayerPimpl::CheckForObjects()
{
	// TODO: not finished
	// Pick middle of the screen
	static u32 CheckForObjects_time = 0;
	if(CheckForObjects_time < 100)
	{
		CheckForObjects_time++;
		return;
	}

	// set our query
	Ray pickRay = m_CameraManager->GetCamera()->getCameraToViewportRay(0.5, 0.5);
	m_ObjectQuery->setRay (pickRay);
	m_ObjectQuery->setSortByDistance (true, 3);	//only 3 hits
	const RaySceneQueryResult& result = m_ObjectQuery->execute();

	if (!result.empty())
	{
		auto it = result.begin();
		while((it != result.end()))
		{
			if(it->movable)
			{
				if(it->movable->getQueryFlags() == SQF_PLAYER)
				{
				}
			}
			++it;
		}
	}
	CheckForObjects_time = 0;
}

void CPlayerPimpl::SetDirection(const Vector3& Direction)
{	
	m_Direction = Direction;
	m_PlayerNode->setDirection(m_Direction, Node::TS_WORLD, Vector3::UNIT_Z);
	m_AbstractVehicle->SetForward(m_Direction * Vector3::NEGATIVE_UNIT_Z);
}

void CPlayerPimpl::SetLoSType(E_LOS_TYPE Type)
{
	if(m_LineOfSightStrategy)
		CORE_DELETE(m_LineOfSightStrategy);

	if(Type == ELT_TRIANGLE)
		m_LineOfSightStrategy = new CLineOfSightStrategy_Triangle(m_Player);
	else if(Type == ELT_RANGE_BASIC)
		m_LineOfSightStrategy = new CLineOfSightStrategy_RangeBasic(m_Player);
	else
		m_LineOfSightStrategy = new CLineOfSightStrategy_Basic(m_Player);
}

bool CPlayerPimpl::CanSee(CPlayer* Player)
{
	if(m_LineOfSightStrategy)
		return m_LineOfSightStrategy->CanSee(Player);

	String msg = "LoS Strategy not created for player: " + Name;
	CORE_THROW(msg.c_str(), "CPlayer::CanSee");
	return false;
}

bool CPlayerPimpl::CanSee(const Vector3& Position)
{
	if(m_LineOfSightStrategy)
		return m_LineOfSightStrategy->CanSee(Position);

	String msg = "LoS Strategy not created for player: " + Name;
	CORE_THROW(msg.c_str(), "CPlayer::CanSee");
	return false;
}

CPlayer* CPlayerPimpl::Duplicate(const char* PlayerType)
{
	auto player = CGameObjectManager::Instance()->CreatePlayer(PlayerType, m_PlayerTeam, nullptr, m_PhysicsStrategy, false);
	if(!player)
		return nullptr;

	player->m_PlayerPimpl->m_WalkSpeed = m_WalkSpeed;
	player->m_PlayerPimpl->m_RunSpeed = m_RunSpeed;	
	player->m_PlayerPimpl->m_SprintSpeed = m_SprintSpeed;	
	player->m_PlayerPimpl->m_CrawlSpeed = m_CrawlSpeed;
	player->m_PlayerPimpl->m_ReloadSpeed = m_ReloadSpeed;
	player->m_PlayerPimpl->m_Health = m_Health;
	player->m_PlayerPimpl->m_PickupRadius = m_PickupRadius;
	player->m_PlayerPimpl->m_DestinationRadius = m_DestinationRadius;
	player->m_PlayerPimpl->m_FallVelocity = m_FallVelocity;
	player->m_PlayerPimpl->m_DieingTime = m_DieingTime;
	player->m_PlayerPimpl->m_ViewRange = m_ViewRange;
	player->m_PlayerPimpl->m_AnimationSpeed = m_AnimationSpeed;
	player->m_PlayerPimpl->m_SightNode = m_SightNode;
	player->m_PlayerPimpl->m_PlayerEntity = m_PlayerEntity;
	player->m_PlayerPimpl->m_PlayerNode = m_PlayerNode;
	player->m_PlayerPimpl->isKilled = isKilled;
	player->m_PlayerPimpl->isVisible = isVisible;
	player->m_PlayerPimpl->isMovableText = isMovableText;
	player->m_PlayerPimpl->isHumanPlayer = isHumanPlayer;
	player->m_PlayerPimpl->isCharacterController = isCharacterController;
	player->m_PlayerPimpl->m_Movement = m_Movement;
	player->m_PlayerPimpl->m_CCSize = m_CCSize;
	player->m_PlayerPimpl->m_PlayerTeam = m_PlayerTeam;
	player->m_PlayerPimpl->m_Target = m_Target;
	player->m_PlayerPimpl->m_LosType = m_LosType;
	player->m_PlayerPimpl->m_CharacterState = m_CharacterState;

	return player;
}

#pragma region Items

void CPlayerPimpl::AddItem(CInventoryItem* Item)
{
	if(!Item)
		return;

	Item->PickedUp(m_Player);

	m_Items.push_back(Item);
	if(!m_CurrItem)
	{
		m_CurrItem = Item;
		if(isHumanPlayer)
			m_CurrItem->ShowSight(true);
	}
}

void CPlayerPimpl::RemoveItem(CInventoryItem* Item)
{
	if(!Item)
		return;

	// Clear this item from the current item variable
	if(m_CurrItem == Item)
		m_CurrItem = nullptr;

	CItemsManager::Instance()->PlaceItem(Item->Name.c_str(), m_PlayerNode->getPosition(), m_PhysicsStrategy);
	for(u32 i = 0; i < m_Items.size(); i++)
	{
		if(m_Items[i] == Item)
		{
			m_Items.erase(m_Items.begin() + i);
			return;
		}
	}

	// If there is no current item, and the player has items, set a default current item
	if(m_CurrItem == nullptr && m_Items.size() > 0 && m_Items[0] != nullptr)
		m_CurrItem = m_Items[0];
}

void CPlayerPimpl::DropAllItems()
{
	for(auto it = m_Items.begin(); it != m_Items.end(); it++)
	{
		CItemsManager::Instance()->PlaceItem((*it)->Name.c_str(), m_PlayerNode->getPosition(), m_PhysicsStrategy);
	}

	m_Items.clear();
	m_CurrItem = nullptr;
}

void CPlayerPimpl::RemoveAllItems()
{
	for(auto it = m_Items.begin(); it != m_Items.end(); it++)
	{
		CItemsManager::Instance()->RemoveItem((*it));
	}

	m_Items.clear();
	m_CurrItem = nullptr;
}

void CPlayerPimpl::UseItem(CPlayer* Player, CInventoryItem* Item)
{
	// Item could be a tool, med kit, anything, but if not specified, it will be a weapon.
	if(!Player)
		return;

	if(!Item)
	{
		if(m_CurrItem)
		{
			Vector3 target;
			if(m_CurrItem->GetType() == EIT_WEAPON)
			{
				// Set direction
				Vector3 dir = (Player->GetPosition() /* will need to set when not standing + 0.0f*/) - GetPosition();
				//dir.y = 0;

				Vector3 closest = dir;
				f32 coeff = m_PlayerNode->getPosition().distance(closest) / m_CurrItem->GetRange();
				target = closest;
				target.x += coeff * Math::RangeRandom(-0.1f , 0.1f);
				target.y += coeff * Math::RangeRandom(-0.01f, 0.02f);
				target.z += coeff * Math::RangeRandom(-0.1f , 0.1f);
			}
			else if(m_CurrItem->GetType() == EIT_MELEE)
			{
				// Set direction, assumes we are in range to use the melee attack
				target = Player->GetPosition() - GetPosition();
			}

			// Fire
			if(m_CurrItem->Use(target))
			{
				// Make a sound
				m_PlayerSoundComponent->PlayShot();
				if(m_PlayerState != EPS_ATTACKING)
				{
					SetPlayerState(EPS_ATTACKING);
				}
			}
		}
	}
	else if(Item)
	{
		// TODO: tools not implented yet.
		Item->Use(m_Direction);
	}
}

void CPlayerPimpl::UseItem(CGameObject* GameObject, CInventoryItem* Item)
{
	throw("Not Implemented");
}

#pragma endregion

#pragma region Events

void CPlayerPimpl::OnPickupItem()
{
	// set our query
	Ray pickRay = m_CameraManager->GetCamera()->getCameraToViewportRay(0.5, 0.5);
	m_ObjectQuery->setRay (pickRay);
	m_ObjectQuery->setSortByDistance (true, 3);
	const RaySceneQueryResult& result = m_ObjectQuery->execute();

	if (!result.empty())
	{
		auto it = result.begin();
		while((it != result.end()))
		{
			if(it->movable)
			{
				if (it->movable->getQueryFlags() == SQF_INVENTORY_ITEM)
				{
					// Are we close enough to pickup
					if(it->distance <= 50.0f)
					{
						CoreEntityObject* obj = any_cast<CoreEntityObject*>(it->movable->getUserAny());
						if(obj && obj->Item)
						{
							// Pickup the item
							CInventoryItem* item = m_ItemsManager->Pickup(obj->Item->Name.c_str());
							if(item)
							{
								m_Items.push_back(item);
								m_CurrItem = item;
								m_CurrItem->ShowSight(true);
							}
						}

					}					
				}
			}
			++it;
		}
	}
}

void CPlayerPimpl::OnKill(CPlayer* PlayerKilled, CProjectile* Projectile)
{
	using namespace Core::Mission;
	auto inventoryItem = static_cast<CInventoryItem*>(Projectile->GetWeapon());
	CMissionManager::Instance()->RegisterEvent(m_Player, Mission::MT_ELIMINATE, PlayerKilled, inventoryItem, Projectile);
}

void CPlayerPimpl::OnKill(CPlayer* PlayerKilled, CInventoryItem* InventoryItem)
{
	using namespace Core::Mission;
	CMissionManager::Instance()->RegisterEvent(m_Player, Mission::MT_ELIMINATE, PlayerKilled, InventoryItem);
}

void CPlayerPimpl::OnShotFired()
{
	if(m_CurrItem)
	{
		if(m_CurrItem->GetType() == EIT_WEAPON)
		{
			auto weapon = static_cast<CWeapon*>(m_CurrItem);
			Ray pickRay = m_CameraManager->GetCamera()->getCameraToViewportRay(0.5, 0.5);
			weapon->Use(pickRay.getDirection());
		}
	}	
}

void CPlayerPimpl::OnHit(CProjectile* Projectile, const Vector3& Direction)
{
	if(Projectile)
	{
		m_Health -= Projectile->GetDamage();
		// Find if player is dead
		if(m_Health <= 0.0f && isKilled == false)
		{
			DebugLoS(false);
			isKilled = true;
			if(Projectile->GetOwner())
				Projectile->GetOwner()->OnKill(m_Player, Projectile);
			m_Health = 0.0f;

			// Activate ragdoll
			if(m_PhysicsRagdoll)
			{
				m_PhysicsRagdoll->TakePhysicalControl();
				m_PhysicsRagdoll->Pick(Projectile);
			}
		}
	}
}

void CPlayerPimpl::OnHit(CInventoryItem* InventoryItem, CPlayer* Owner, const Vector3& Direction)
{
	if(InventoryItem && Owner)
	{
		m_Health -= InventoryItem->Power;
		// Find if player is dead
		if(m_Health <= 0.0f && isKilled == false)
		{
			isKilled = true;
			if(Owner)
				Owner->OnKill(m_Player, InventoryItem);
			m_Health = 0.0f;

			// Activate ragdoll
			if(m_PhysicsRagdoll)
			{
				m_PhysicsRagdoll->TakePhysicalControl();
			}
		}
	}
}

#pragma endregion

#pragma region Debugging

void CPlayerPimpl::DebugLoS(bool Show)
{
	if(Show)
	{
		// Show line of sight
		m_Lineofsight = m_GameManager->GetSceneManager()->createManualObject();
		m_Lineofsight->setCastShadows(false);
		MaterialPtr lineofsightMaterial = MaterialManager::getSingleton().create("lineofsightMaterial","General");
		lineofsightMaterial->setReceiveShadows(false);
		lineofsightMaterial->getTechnique(0)->setLightingEnabled(false);

		m_Lineofsight->clear();
		m_Lineofsight->begin("lineofsightMaterial", RenderOperation::OT_LINE_LIST);

		//60 degrees left & right, total 120 degrees of sight
		Quaternion q;
		q.FromAngleAxis(Radian(Math::PI/3), Vector3::UNIT_Y);
		Vector3 direction = m_Direction * Vector3::UNIT_Z;
		Vector3 A = Vector3::ZERO;
		Vector3 B = A + q * (direction * m_ViewRange);
		Vector3 C = A + q.Inverse() * (direction * m_ViewRange);

		m_Lineofsight->position(A);	
		m_Lineofsight->colour(1,0,0);
		m_Lineofsight->position(A + GetEyePosition());	
		m_Lineofsight->colour(1,0,0);

		m_Lineofsight->position(A);	
		m_Lineofsight->colour(0,1,0);
		m_Lineofsight->position(B);	
		m_Lineofsight->colour(0,1,0);

		m_Lineofsight->position(B);	
		m_Lineofsight->colour(0,1,0);
		m_Lineofsight->position(C);	
		m_Lineofsight->colour(0,1,0);

		m_Lineofsight->position(C);	
		m_Lineofsight->colour(0,1,0);
		m_Lineofsight->position(A);	
		m_Lineofsight->colour(0,1,0);

		m_Lineofsight->end();
		m_Lineofsight->setVisible(true);

		m_PlayerNode->attachObject(m_Lineofsight);
	}
	else
	{
		if(m_Lineofsight)
		{
			m_PlayerNode->detachObject(m_Lineofsight);
		}
	}
}

#pragma endregion

#pragma region GET/SET

Vector3 CPlayerPimpl::GetPosition()
{
	return m_PlayerNode->getPosition();
}

Vector3 CPlayerPimpl::GetHeadPosition()
{
	if(m_HeadBoneName != "")
	{
		Bone* bone = m_PlayerEntity->getSkeleton()->getBone(m_HeadBoneName.c_str());
		return m_PlayerEntity->_getParentNodeFullTransform() * bone->_getDerivedPosition();
	}
	return Vector3::ZERO;
}

Quaternion CPlayerPimpl::GetHeadRotation()
{
	if(m_HeadBoneName != "")
	{
		Bone* bone = m_PlayerEntity->getSkeleton()->getBone(m_HeadBoneName.c_str());
		Quaternion q = m_PlayerEntity->_getParentNodeFullTransform().extractQuaternion();
		return q * bone->_getDerivedOrientation();
	}
	return Quaternion::ZERO;
}

Vector3 CPlayerPimpl::GetBodyPosition()
{
	if(m_RootBoneName != "")
	{
		Bone* bone = m_PlayerEntity->getSkeleton()->getBone(m_RootBoneName.c_str());
		return m_PlayerEntity->_getParentNodeFullTransform() * bone->_getDerivedPosition();
	}
	return Vector3::ZERO;
}

Quaternion CPlayerPimpl::GetBodyRotation()
{
	if(m_RootBoneName != "")
	{
		Bone* bone = m_PlayerEntity->getSkeleton()->getBone(m_RootBoneName.c_str());
		Quaternion q = m_PlayerEntity->_getParentNodeFullTransform().extractQuaternion();
		return q * bone->_getDerivedOrientation();
	}
	return Quaternion::ZERO;
}

void CPlayerPimpl::SetYAxisFromTerrain_Paged(f32 elapsedTime)
{
	// clamp to terrain
	Vector3 pos = m_PlayerNode->getPosition();
	Ray ray;
	ray.setOrigin(Vector3(pos.x, 1000, pos.z));
	ray.setDirection(Vector3::NEGATIVE_UNIT_Y);

	TerrainGroup::RayResult rayResult = Nature::CNatureManager::Instance()->GetTerrainGroup()->rayIntersects(ray);
	f32 distanceAboveTerrain = 0;
	f32 fallSpeed = 300;
	f32 newy = pos.y;
	if (rayResult.hit)
	{
		if (pos.y > rayResult.position.y + distanceAboveTerrain)
		{
			m_FallVelocity += elapsedTime * 20;
			m_FallVelocity = std::min(m_FallVelocity, fallSpeed);
			newy = pos.y - m_FallVelocity * elapsedTime;

		}
		newy = std::max(rayResult.position.y + distanceAboveTerrain, newy);
		this->SetPlayerPosition(pos.x, newy, pos.z);
	}
}

void CPlayerPimpl::SetYAxisFromTerrain_Height(f32 elapsedTime)
{
	// Update +Y axis
	static Ray updateRay;
	static f32 axisY;
	updateRay.setOrigin(m_PlayerNode->_getDerivedPosition());
	updateRay.setDirection(Vector3::NEGATIVE_UNIT_Y);
	m_TerrainRaySceneQuery->setRay(updateRay);
	auto qryResult = m_TerrainRaySceneQuery->execute();
	auto it = qryResult.begin();

	// are we above the terrain
	if (it != qryResult.end() && it->worldFragment)
	{
		m_PlayerNode->setPosition(m_PlayerNode->_getDerivedPosition().x, 
			it->worldFragment->singleIntersection.y, 
			m_PlayerNode->_getDerivedPosition().z);
		//static_cast<AbstractVehicle*>(this)->setPosition(m_PlayerNode->getPosition());
		// axisY = it->worldFragment->singleIntersection.y;
	}
	// are be below the terrain
	else if(it != qryResult.end() && !it->worldFragment)
	{
		// Double check with -Y axis
		updateRay.setOrigin(m_PlayerNode->_getDerivedPosition());
		updateRay.setDirection(Vector3::UNIT_Y);
		m_TerrainRaySceneQuery->setRay(updateRay);
		auto qryResult2 = m_TerrainRaySceneQuery->execute();
		auto it2 = qryResult2.begin();
		if (it2 != qryResult2.end() && it2->worldFragment)
		{
			m_PlayerNode->setPosition(m_PlayerNode->_getDerivedPosition().x, 
				it2->worldFragment->singleIntersection.y, 
				m_PlayerNode->_getDerivedPosition().z);
		}
	}
}

void CPlayerPimpl::SetCharacterState(E_PLAYER_STATE PlayerState)
{
	// Set the state, but can tweak which exact state beause the Ai can decide if it
	// needs to change for a more specific state

	// If player is controlling then we don't need Ai
	if(isHumanPlayer)
	{
		// Clear the state
		CORE_DELETE(m_CharacterState);

		m_PlayerState = PlayerState;
		return;
	}

	// Do nothing if we're dead
	if(PlayerState == EPS_DIEING || PlayerState == EPS_DEAD)
	{
		// Clear the state
		CORE_DELETE(m_CharacterState);

		m_PlayerState = PlayerState;

		if(m_PhysicsRagdoll)
			m_PhysicsRagdoll->isActive = true;

		return;
	}

	AI::CCharacterState* characterState = m_CharacterStateManager->GetState(PlayerState, m_Player);
	if(characterState)
	{
		m_CharacterState = characterState;
		m_PlayerState = characterState->GetStateType();
	}
}

void CPlayerPimpl::SetExactCharacterState(const char* State)
{
	AI::CCharacterState* characterState = m_CharacterStateManager->GetState(State, m_Player);
	if(characterState)
	{
		m_CharacterState = characterState;
		m_PlayerState = characterState->GetStateType();
	}
}

void CPlayerPimpl::SetHumanPlayer(bool isPlayer)
{
	isHumanPlayer = isPlayer;
	if(m_GameObjectManager)
	{
		m_GameObjectManager->SetHumanPlayer(isHumanPlayer ? m_Player : nullptr);
	}

	if(isHumanPlayer)
	{
		SetTextLabelEnabled(false);
	}
}

void CPlayerPimpl::SetPlayerPosition(const Vector3& Position)
{
	if(isFpsView)
		return;

	m_PlayerNode->setPosition(Position);
	if(m_AbstractVehicle)
		m_AbstractVehicle->SetPosition(Position);
	if(m_CharacterController)
		m_CharacterController->SetCharacterPos(Position);
}

void CPlayerPimpl::SetPlayerPosition(const f32& x, const f32& y, const f32& z)
{
	if(isFpsView)
		return;

	if(m_PlayerNode)
		m_PlayerNode->setPosition(x, y, z);
	if(m_AbstractVehicle)
		m_AbstractVehicle->SetPosition(x, y, z);
	if(m_CharacterController)
		m_CharacterController->SetCharacterPos(Vector3(x, y, z));
}

void CPlayerPimpl::SetVisible(bool Visible)
{
	isVisible = Visible;
	m_PlayerNode->setVisible(isVisible);

	// Don't want to be visible if this is the human player
	if(Visible && m_MovableTextOverlay && !isHumanPlayer)
		m_MovableTextOverlay->Enable(Visible);
}

const char* CPlayerPimpl::GetMovableText()
{
	if(m_MovableTextOverlay)
	{
		return m_MovableTextOverlay->GetCaption().c_str();
	}
	return nullptr;
}

void CPlayerPimpl::SetPlayerState(E_PLAYER_STATE State)
{
	m_PlayerState = State;
}

void CPlayerPimpl::SetPlayerTeam(E_PLAYER_TEAM Team)
{
	// The GOM needs to update the player team list first
	m_GameObjectManager->ChangePlayerTeam(m_Player, Team);
	m_PlayerTeam = Team;
}

Vector3 CPlayerPimpl::GetEyePosition()
{
	// LoS
	f32 Radius = 1.0f;	 // TODO: make dynamic
	//auto test1 = m_PlayerNode->getPosition() + Vector3(0, 4.0f, 0);
	//auto test2 = m_Direction.normalise() * Vector3(0, 0, Radius);
	//auto test3 = test1 + test2;
	return (m_PlayerNode->getPosition() + Vector3(0, 4.0f, 0)) + (m_Direction.normalisedCopy() * Radius);
}

void CPlayerPimpl::SetTextLabelEnabled(bool Enabled)
{
	if(m_MovableTextOverlay)
	{
		m_MovableTextOverlay->Enable(Enabled);
	}
}

void CPlayerPimpl::SetTextLabelCaption(const char* Text)
{
	if(m_MovableTextOverlay)
	{
		m_MovableTextOverlay->SetCaption(Text);
	}
}

#pragma endregion

#pragma region Updates

void CPlayerPimpl::UpdateDefault(const f32& elapsedTime)
{	
	CALL_VOIDFUNCFLOAT("PlayerPreUpdate", elapsedTime);

	// Update Movement
	UpdateMovement(elapsedTime);

	// Update physics
	UpdatePhysics(elapsedTime);

	// Update the enum animiation state
	UpdateAnimationState(elapsedTime);

	// Update ogre animation state based on the enum animation state
	UpdateAnimation(elapsedTime);

	// Update our Y axis
	m_Player->SetYAxisFromTerrain(elapsedTime);

	// Update text label
	if(isMovableText)
		UpdateTextLabel(elapsedTime);

	CALL_VOIDFUNCFLOAT("PostUpdatePlayer", elapsedTime)
}

void CPlayerPimpl::UpdateMovement(const f32& elapsedTime)
{
	m_Movement = Vector3::ZERO;

	// Are we in good health
	if(m_Health <= 0.0f)
		return;

	// If console is not opened, and is this the human player
	if(isHumanPlayer && !m_GameManager->GetConsoleVisible() && m_CameraManager->GetIsPlayerFriendly())
	{
		// Update direction
		m_Direction = m_PlayerNode->getOrientation() * Vector3::UNIT_Z;
		m_Direction.normalise();

		// Get movement
		f32 scalar = 0;
		auto inputManager = CInputManager::Instance();
		if(inputManager->IsKeyDown(KC_LSHIFT))
			scalar = m_RunSpeed;
		else
			scalar = m_WalkSpeed;

		if(inputManager->IsKeyDown(KC_W)) 
		{
			m_Movement += m_Direction;
		}
		if(inputManager->IsKeyDown(KC_S)) 
		{
			m_Movement += -m_Direction;
		}
		if(inputManager->IsKeyDown(KC_A)) 
		{
			m_Movement.z += m_Direction.x * -1;
			m_Movement.x += m_Direction.z;
		}
		if(inputManager->IsKeyDown(KC_D))
		{
			m_Movement.x += m_Direction.z * -1;
			m_Movement.z += m_Direction.x;
		}

		// Move
		if(m_Movement != Vector3::ZERO)
		{
			m_Movement *= scalar * elapsedTime;
			m_PlayerNode->translate(m_Movement);
		}

		// Pickup object
		if(inputManager->IsKeyDown(KC_G))
		{
			OnPickupItem();
		}

		// mouse
		CInputMouseEvent evt;
		inputManager->GetMouseEvent(evt);
		Radian m_RotX = Degree(-evt.relX * 0.13f);

		// update camera
		m_PlayerNode->yaw(m_RotX, Node::TS_WORLD);	

		// Picking shots
		if (m_CurrItem && m_CurrItem->GetType() == EIT_WEAPON && inputManager->IsMouseDown(MB_Left))
		{
			OnShotFired();	
		}
	}
	// Non-human player
	else
	{
		// Update or check the status of the character state
		if(m_CharacterState)
		{
			if(m_CharacterState->GetOutcomeState() == AI::WORKING)
			{
				Vector3 pos = m_PlayerNode->getPosition();
				m_CharacterState->Update(elapsedTime);

				// Gets the delta movement because Ai is moving it when its not the human player
				m_Movement = pos - m_PlayerNode->getPosition();
			}
			else
			{
				m_AiReactionComponent->OnCharacterStateChange();
			}
		}
	}

	// Update AI Vehicle
	if(m_AbstractVehicle)
		m_AbstractVehicle->SetPosition(m_PlayerNode->getPosition());
}

void CPlayerPimpl::UpdatePhysics(const f32& elapsedTime)
{
	if(!m_CharacterController)
		return;

	if(m_Movement != Vector3::ZERO)
	{
		// Update the position if this is the human player, otherwise the AI will move the player
		if(isHumanPlayer)
		{
			m_CharacterController->SetCharacterPos(m_PlayerNode->getPosition());
		}
		else
		{
			m_CharacterController->MoveCharacter(m_Movement, elapsedTime, 0, 0);
		}

		// Update the Environment Observer
		m_EnvironmentObserver->Update();
	}
	m_CharacterController->UpdateControllers();
}

void CPlayerPimpl::UpdateAnimationState(const f32& elapsedTime)
{
	// Are we moving
	if(m_Movement != Vector3::ZERO)
	{
		// Are we running
		if(isHumanPlayer)
		{
			if(CInputManager::Instance()->IsKeyDown(KC_LSHIFT))
				m_AnimState = EAS_RUN;
			else
				m_AnimState = EAS_WALK;
		}
		else
		{
			if(m_AbstractVehicle->Speed() == m_WalkSpeed)
				m_AnimState = EAS_WALK;
			else if(m_AbstractVehicle->Speed() == m_RunSpeed)
				m_AnimState = EAS_RUN;
		}
	}
	// We are not moving
	else if(m_Movement == Vector3::ZERO)
	{
		// Are we dying
		if(m_Health <= 0.0f)
		{
			// Check if we are already dying
			if((m_PlayerState != EPS_DIEING) && !(m_PlayerState == EPS_DEAD))
			{
				// Change our state to dieing
				m_PlayerState = EPS_DIEING;

				// Set our count down to finally die 30 seconds minus any negetive health for bad injuries
				m_DieingTime += m_Health;

				// Disable the physics character controller
				if(m_CharacterController)
					m_CharacterController->SetEnabled(false);
			}
			// Are we still dieing
			else if(m_PlayerState == EPS_DIEING && m_DieingTime > 0)
			{
				m_DieingTime -= elapsedTime;
			}
			// We are dead now
			else
			{
				m_PlayerState = EPS_DEAD;
				m_DieingTime = 0;
			}

			// Set our animation state
			if(m_PhysicsRagdoll)
				m_AnimState = EAS_NONE;
			else
				m_AnimState = EAS_DIEING;
		}
		// Are we standing still and attacking
		else if(m_PlayerState == EPS_ATTACKING)
		{
			// Get the current weapon, and set animation based on the item in hand
			// Projectile weapon
			if(m_CurrItem->GetType() == EIT_WEAPON)
			{
				m_AnimState = EAS_AIM_STAND;
			}
			else if(m_CurrItem->GetType() == EIT_MELEE)
			{
				m_AnimState = EAS_MELEE;
			}
		}
		// We are alive, just not moving.  There is not Ai state that is using no movement for now so we will be idle
		else
		{
			m_AnimState = EAS_IDLE;
		}
	}
}

void CPlayerPimpl::UpdateAnimation(const f32& elapsedTime)
{
	// Has the animation state changed
	if(m_CurrAnimState != m_AnimState)
	{
		// Stop the current state
		if(m_AnimationState)
		{
			m_AnimationState->setLoop(false);
			m_AnimationState->setEnabled(false);
		}

		auto it = m_AnimationMaps.find(m_AnimState);
		if(it != m_AnimationMaps.end())
		{
			if(it->second)
			{
				m_AnimationState = m_PlayerEntity->getAnimationState(it->second->Animation);

				// Set if still looping
				if(m_PlayerState == EPS_DIEING || m_PlayerState == EPS_DEAD)
					m_AnimationState->setLoop(false);
				else
					m_AnimationState->setLoop(true);

				// Set if still enabled
				if(m_PlayerState == EPS_DEAD)
					m_AnimationState->setEnabled(false);
				else
					m_AnimationState->setEnabled(true);
			}
		}

		m_CurrAnimState = m_AnimState;
	}
	else
	{
		// Update animation
		if(m_AnimationState)
		{
			m_PlayerEntity->getAnimationState(m_AnimationState->getAnimationName())->addTime(elapsedTime);
		}
	}
}

#pragma endregion