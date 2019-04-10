#include "CPlayer.h"
#include "CPlayerPimpl.h"
#include "CNatureManager.h"
#include "CoreStructures.h"
#include "PlayerEnums.h"

#include "OgreSceneNode.h"
#include "OgreEntity.h"
#include "OgreVector3.h"

using namespace Core;

CPlayer::CPlayer(const char* LabelName, Physics::IPhysicsStrategy* PhysicsStrategy) 
{ 
	m_PlayerPimpl = new CPlayerPimpl(LabelName, PhysicsStrategy);

	// Setup of terrain height method
	if(Nature::CNatureManager::Instance()->GetTerrainGroup())
		SetYAxisFromTerrain_Ptr = &CPlayer::SetYAxisFromTerrain_Paged;
	else
		SetYAxisFromTerrain_Ptr = &CPlayer::SetYAxisFromTerrain_Height;
}

//void CPlayer::PostInit()
//{
//	m_PlayerPimpl->PostInit(this);
//}

CPlayer::~CPlayer()
{
	CORE_DELETE(m_PlayerPimpl);
}

//void CPlayer::TextLabelSetup()
//{
//	m_PlayerPimpl->TextLabelSetup();
//}

//void CPlayer::UpdateTextLabel(const f32& elapsedTime)
//{
//	m_PlayerPimpl->
//}

//void CPlayer::CheckForObjects()
//{
//	// TODO: not finished
//	// Pick middle of the screen
//	static u32 CheckForObjects_time = 0;
//	if(CheckForObjects_time < 100)
//	{
//		CheckForObjects_time++;
//		return;
//	}
//
//	// set our query
//	Ray pickRay = m_CameraManager->GetCamera()->getCameraToViewportRay(0.5, 0.5);
//	m_ObjectQuery->setRay (pickRay);
//	m_ObjectQuery->setSortByDistance (true, 3);	//only 3 hits
//	const RaySceneQueryResult& result = m_ObjectQuery->execute();
//
//	if (!result.empty())
//	{
//		auto it = result.begin();
//		while((it != result.end()))
//		{
//			if(it->movable)
//			{
//				if(it->movable->getQueryFlags() == SQF_PLAYER)
//				{
//				}
//			}
//			++it;
//		}
//	}
//	CheckForObjects_time = 0;
//}

void CPlayer::SetDirection(const Vector3& Direction)
{	
	m_PlayerPimpl->SetDirection(Direction);
}

void CPlayer::SetLoSType(E_LOS_TYPE Type)
{
	m_PlayerPimpl->SetLoSType(Type);
}

bool CPlayer::CanSee(CPlayer* Player)
{
	return m_PlayerPimpl->CanSee(Player);
}

bool CPlayer::CanSee(const Vector3& Position)
{
	return m_PlayerPimpl->CanSee(Position);
}

CPlayer* CPlayer::Duplicate(const char* PlayerType)
{
	return m_PlayerPimpl->Duplicate(PlayerType);
}

#pragma region Items

void CPlayer::AddItem(CInventoryItem* Item)
{
	m_PlayerPimpl->AddItem(Item);
}

void CPlayer::RemoveItem(CInventoryItem* Item)
{
	m_PlayerPimpl->RemoveItem(Item);
}

void CPlayer::DropAllItems()
{
	m_PlayerPimpl->DropAllItems();
}

void CPlayer::RemoveAllItems()
{
	m_PlayerPimpl->RemoveAllItems();
}

void CPlayer::UseItem(CPlayer* Player, CInventoryItem* Item)
{
	m_PlayerPimpl->UseItem(Player, Item);
}

void CPlayer::UseItem(CGameObject* GameObject, CInventoryItem* Item)
{
	m_PlayerPimpl->UseItem(GameObject, Item);
}

#pragma endregion

#pragma region Events

void CPlayer::OnPickupItem()
{
	m_PlayerPimpl->OnPickupItem();
}

void CPlayer::OnKill(CPlayer* PlayerKilled, CProjectile* Projectile)
{
	m_PlayerPimpl->OnKill(PlayerKilled, Projectile);
}

void CPlayer::OnKill(CPlayer* PlayerKilled, CInventoryItem* InventoryItem)
{
	m_PlayerPimpl->OnKill(PlayerKilled, InventoryItem);
}

void CPlayer::OnShotFired()
{
	m_PlayerPimpl->OnShotFired();	
}

void CPlayer::OnHit(CProjectile* Projectile, const Vector3& Direction)
{
	m_PlayerPimpl->OnHit(Projectile, Direction);
}

void CPlayer::OnHit(CInventoryItem* InventoryItem, CPlayer* Owner, const Vector3& Direction)
{
	m_PlayerPimpl->OnHit(InventoryItem, Owner, Direction);
}

#pragma endregion

#pragma region Debugging

void CPlayer::DebugLoS(bool Show)
{
	m_PlayerPimpl->DebugLoS(Show);
}

#pragma endregion

#pragma region GET/SET

const char*	CPlayer::GetPlayerType()
{ 
	return m_PlayerPimpl->m_PlayerType; 
}

Physics::IPhysicsStrategy* CPlayer::GetPhysicsStrategy()
{ 
	return m_PlayerPimpl->m_PhysicsStrategy; 
}

Physics::ICharacterController* CPlayer::GetCharacterController()
{ 
	return m_PlayerPimpl->m_CharacterController; 
}

f32	CPlayer::GetRunSpeed()
{ 
	return m_PlayerPimpl->m_RunSpeed; 
}

f32	CPlayer::GetWalkSpeed()
{ 
	return m_PlayerPimpl->m_WalkSpeed; 
}

f32	CPlayer::GetSprintSpeed()
{ 
	return m_PlayerPimpl->m_SprintSpeed; 
}

f32	CPlayer::GetCrawlSpeed()
{ 
	return m_PlayerPimpl->m_CrawlSpeed; 
}

f32	CPlayer::GetDieTime()
{ 
	return m_PlayerPimpl->m_DieingTime; 
}

void CPlayer::SetRunSpeed(const f32& Speed) 
{ 
	m_PlayerPimpl->m_RunSpeed = Speed; 
}

void CPlayer::SetWalkSpeed(const f32& Speed) 
{ 
	m_PlayerPimpl->m_WalkSpeed = Speed; 
}

void CPlayer::SetSprintSpeed(const f32& Speed) 
{ 
	m_PlayerPimpl->m_SprintSpeed = Speed; 
}

void CPlayer::SetCrawlSpeed(const f32& Speed) 
{ 
	m_PlayerPimpl->m_CrawlSpeed = Speed; 
}

void CPlayer::SetDieTime(const f32& Time) 
{ 
	m_PlayerPimpl->m_DieingTime = Time; 
}

Vector3 CPlayer::GetHeadPosition()
{
	return m_PlayerPimpl->GetHeadPosition();
}

Quaternion CPlayer::GetHeadRotation()
{
	return m_PlayerPimpl->GetHeadRotation();
}

Vector3 CPlayer::GetBodyPosition()
{
	return m_PlayerPimpl->GetBodyPosition();
}

Quaternion CPlayer::GetBodyRotation()
{
	return m_PlayerPimpl->GetBodyRotation();
}

AI::CFpsVehicle* CPlayer::GetAiTarget()
{
	return m_PlayerPimpl->m_Target;
}

void CPlayer::GetAiPathPoints(Vector<Vector3>& Paths) 
{ 
	Paths = m_PlayerPimpl->m_PathPoints; 
}

CInventoryItem* CPlayer::GetCurrentInventoryItem()
{
	return m_PlayerPimpl->m_CurrItem;
}

Vector3 CPlayer::GetEyePosition()
{
	return m_PlayerPimpl->GetEyePosition();
}

Vector3 CPlayer::GetCharacterControllerSize() 
{ 
	return m_PlayerPimpl->m_CCSize; 
}

E_LOS_TYPE CPlayer::GetLoSType() 
{ 
	return m_PlayerPimpl->m_LosType; 
}

bool CPlayer::GetIsFps()
{
	return m_PlayerPimpl->isFpsView;
}

void CPlayer::SetYAxisFromTerrain(f32 elapsedTime)
{
	(*this.*SetYAxisFromTerrain_Ptr)(elapsedTime);
}

void CPlayer::SetYAxisFromTerrain_Paged(f32 elapsedTime)
{
	m_PlayerPimpl->SetYAxisFromTerrain_Paged(elapsedTime);
}

void CPlayer::SetYAxisFromTerrain_Height(f32 elapsedTime)
{
	m_PlayerPimpl->SetYAxisFromTerrain_Height(elapsedTime);
}

void CPlayer::SetCharacterState(E_PLAYER_STATE PlayerState)
{
	m_PlayerPimpl->SetCharacterState(PlayerState);
}

void CPlayer::SetExactCharacterState(const char* State)
{
	m_PlayerPimpl->SetExactCharacterState(State);
}

E_PLAYER_TEAM CPlayer::GetPlayerTeam()
{
	return m_PlayerPimpl->m_PlayerTeam;
}

void CPlayer::SetPlayerTeam(E_PLAYER_TEAM Team)
{
	m_PlayerPimpl->SetPlayerTeam(Team);
}

void CPlayer::SetHumanPlayer(bool isPlayer)
{
	m_PlayerPimpl->SetHumanPlayer(isPlayer);
}

void CPlayer::SetPlayerPosition(const Vector3& Position)
{
	m_PlayerPimpl->SetPlayerPosition(Position);
}

void CPlayer::SetPlayerPosition(const f32& x, const f32& y, const f32& z)
{
	m_PlayerPimpl->SetPlayerPosition(x, y, z);
}

AI::CFpsVehicle* CPlayer::GetAiVehicle()
{
	return m_PlayerPimpl->m_AbstractVehicle;
}

void CPlayer::SetAiVehicle(AI::CFpsVehicle* Vehicle)
{
	m_PlayerPimpl->m_AbstractVehicle = Vehicle;
}

AI::CCharacterState* CPlayer::GetCharacterState()
{
	return m_PlayerPimpl->m_CharacterState;
}

SceneNode* CPlayer::GetPlayerNode() 
{
	return m_PlayerPimpl->m_PlayerNode;
}

Entity* CPlayer::GetPlayerEntity()
{
	return m_PlayerPimpl->m_PlayerEntity;
}

void CPlayer::SetVisible(bool Visible)
{
	m_PlayerPimpl->SetVisible(Visible);
}

void CPlayer::SetHealth(f32 Health)
{
	m_PlayerPimpl->m_Health = Health;
}

void CPlayer::SetPlayerState(E_PLAYER_STATE State)
{
	m_PlayerPimpl->SetPlayerState(State);
}

f32 CPlayer::GetHealth()
{
	return m_PlayerPimpl->m_Health;
}

E_PLAYER_STATE CPlayer::GetPlayerState()
{
	return m_PlayerPimpl->m_PlayerState;
}

Vector3 CPlayer::GetPosition()
{
	return m_PlayerPimpl->GetPosition();
}

const char*	CPlayer::GetName() 
{ 
	return m_PlayerPimpl->Name.c_str(); 
}

const char*	CPlayer::GetMeshName() 
{ 
	return m_PlayerPimpl->m_MeshName.c_str(); 
}

bool CPlayer::GetIsVisible() 
{ 
	return m_PlayerPimpl->isVisible; 
}

bool CPlayer::GetIsHumanPlayer() 
{ 
	return m_PlayerPimpl->isHumanPlayer; 
}

Vector3	CPlayer::GetDirection() 
{ 
	return m_PlayerPimpl->m_Direction; 
}

Vector<CInventoryItem*> CPlayer::GetItems() 
{ 
	return m_PlayerPimpl->m_Items; 
}

f32 CPlayer::GetViewRange()
{
	return m_PlayerPimpl->m_ViewRange;
}

const char* CPlayer::GetMovableText()
{
	return m_PlayerPimpl->GetMovableText();
}

void CPlayer::SetViewRange(const f32& Range)
{
	m_PlayerPimpl->m_ViewRange = Range;
}

void CPlayer::SetTextLabelCaption(const char* Text)
{
	m_PlayerPimpl->SetTextLabelCaption(Text);
}

void CPlayer::SetTextLabelEnabled(bool Enabled)
{
	m_PlayerPimpl->SetTextLabelEnabled(Enabled);
}

void CPlayer::SetAiTarget(AI::CFpsVehicle* Target) 
{ 
	m_PlayerPimpl->m_Target = Target; 
}

void CPlayer::SetAiPathPoints(const Vector<Vector3>& PathPoints) 
{ 
	m_PlayerPimpl->m_PathPoints = PathPoints; 
}

void CPlayer::SetName(const char* LabelName) 
{ 
	m_PlayerPimpl->Name = LabelName; 
	m_PlayerPimpl->TextLabelSetup();
}

#pragma endregion

#pragma region Updates

void CPlayer::UpdateDefault(const f32& elapsedTime)
{	
	m_PlayerPimpl->UpdateDefault(elapsedTime);
}

void CPlayer::UpdateMovement(const f32& elapsedTime)
{
	m_PlayerPimpl->UpdateMovement(elapsedTime);
}

void CPlayer::UpdatePhysics(const f32& elapsedTime)
{
	m_PlayerPimpl->UpdatePhysics(elapsedTime);
}

void CPlayer::UpdateAnimationState(const f32& elapsedTime)
{
	m_PlayerPimpl->UpdateAnimationState(elapsedTime);
}

void CPlayer::UpdateAnimation(const f32& elapsedTime)
{
	m_PlayerPimpl->UpdateAnimation(elapsedTime);
}

#pragma endregion