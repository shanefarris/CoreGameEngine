#include "CGameObjectManager.h"
#include "IPhysicsStrategy.h"
#include "CGameManager.h"
#include "CPluginManager.h"
#include "CInputManager.h"
#include "CUtility.h"
#include "AI/Obstacle.h"
#include "AI/Wall.h"
#include "IO/CoreLogging.h"
#include "CScriptManager.h"

#include "CPlayer.h"
#include "CBuilding.h"
#include "CGameObject.h"
#include "Plugins\IPlayerFactory.h"
#include "Plugins\IBuildingFactory.h"
#include "Plugins\IGameObjectFactory.h"

// Ogre
#include "OgreEntity.h"
#include "OgreSceneNode.h"
#include "OgreSceneManager.h"
#include "OgreStringConverter.h"
#include "OgreAxisAlignedBox.h"

//#include <omp.h>

using namespace Core;
using namespace Core::AI;
using namespace Core::Physics;

CGameObjectManager* CGameObjectManager::GameObjectManager = nullptr;

CGameObjectManager* CGameObjectManager::Instance()
{
	if(GameObjectManager == nullptr)
		GameObjectManager = new CGameObjectManager();
	return GameObjectManager;
}

CGameObjectManager::CGameObjectManager() 
	: m_HumanPlayer(nullptr), 
	m_GameObjectCounter(0), 
	m_PlayerCounter(0), 
	m_BuildingCounter(0)
{
	Restart();
}

CGameObjectManager::~CGameObjectManager()
{
	Shutdown();
}

// Player methods
CPlayer* CGameObjectManager::CreatePlayer(const char* Type, E_PLAYER_TEAM Team, const char* LabelName, IPhysicsStrategy* Physics, bool isPlayer)
{
	CPlayer* player = nullptr;
	
	String name;
	if(LabelName)
		name = LabelName;
	else
		name = "";

	if(name.length() == 0)
		name = "player_" + StringConverter::toString(m_Players.size()) + "_" + StringConverter::toString(m_PlayerCounter);

	auto playerFactories = m_PluginManager->GetPlayerFactories();
	size_t size = playerFactories.size();

	// Find the custom object (plugin) and use it
	for(size_t i = 0; i < size; i++)
	{
		if(strncmp(playerFactories[i]->PlayerType, Type, strlen(Type)) == 0)
		{
			player = playerFactories[i]->CreatePlayer(name.c_str(), Physics);
			
			// Add it to the objects list
			if(player)
			{
				m_Players.push_back(player);
			}
			else
			{
				String msg("Unable to load player type: ");
				msg += Type;
				CORE_ERR(msg.c_str());
				return nullptr;
			}

			break;
		}
	}

	if(!player)
	{
		String msg = "Could not find player of type: " + String(Type);
		CORE_ERR(msg.c_str());
	}
	else
	{
		// Set team
		player->SetPlayerTeam(Team);

		// Is this the human player
		if(isPlayer)
		{
			// Was there already a human player selected
			if(m_HumanPlayer)
			{
				m_HumanPlayer->SetHumanPlayer(false);
			}
			m_HumanPlayer = player;
			player->SetHumanPlayer(true);
		}
	}

	// Trigger script
	if(player)
	{
		CALL_VOIDFUNCCONSTCHAR("OnPlayerCreated", player->GetName());
	}

	m_PlayerCounter++;
	return player;
}

bool CGameObjectManager::CreateCustomPlayer(CPlayer* Player, E_PLAYER_TEAM Team, const char* LabelName, Physics::IPhysicsStrategy* PhysicsStrategy, bool isPlayer)
{	
	String name;
	if(LabelName)
		name = LabelName;
	else
		name = "";

	if(name.length() == 0)
		name = "player_" + StringConverter::toString(m_Players.size()) + "_" + StringConverter::toString(m_PlayerCounter);

	// Add it to the objects list
	if(Player)
		m_Players.push_back(Player);
	else
		return false;

	// Set team
	Player->SetPlayerTeam(Team);

	// Is this the human player
	if(isPlayer)
	{
		// Was there already a human player selected
		if(m_HumanPlayer)
		{
			m_HumanPlayer->SetHumanPlayer(false);
		}
		m_HumanPlayer = Player;
		Player->SetHumanPlayer(true);
	}

	// Trigger script
	if(Player)
	{
		CALL_VOIDFUNCCONSTCHAR("OnPlayerCreated", Player->GetName());
	}

	m_PlayerCounter++;
	return true;
}

CPlayer* CGameObjectManager::GetPlayerByName(const char* Name)
{
	for(auto it = m_Players.cbegin(); it != m_Players.cend(); it++)
	{
		if(strncmp((*it)->GetName(), Name, strlen(Name)) == 0)
		{
			return (*it);
		}
	}
	return nullptr;
}

CPlayer* CGameObjectManager::GetPlayerByEntityName(const char* Name)
{
	for(auto it = m_Players.cbegin(); it != m_Players.cend(); it++)
	{
		if(strncmp((*it)->GetPlayerEntity()->getName().c_str(), Name, (*it)->GetPlayerEntity()->getName().size()) == 0)
		{
			return (*it);
		}
	}
	return nullptr;
}

void CGameObjectManager::GetTeam(E_PLAYER_TEAM Team, std::vector<CPlayer*>& List)
{
	List = m_Teams[Team - 1];
}

void CGameObjectManager::GetAllPlayers(Vector<CPlayer*>& Players)
{
	Players = m_Players;
}

void CGameObjectManager::GetPlayerTypes(Vector<const char*>& PlayerType)
{
	auto factories = m_PluginManager->GetPlayerFactories();
	for(auto it = factories.cbegin(); it != factories.cend(); it++)
		PlayerType.push_back((*it)->PlayerType);
}

bool CGameObjectManager::AddCustomPlayer(CPlayer* Player, E_PLAYER_TEAM Team, bool isPlayer)
{
	// TODO: do a unique lable name check
	// If we are successful then save it in the list
	if(Player)
	{
		Player->SetPlayerTeam(Team);

		m_Players.push_back(Player);

		// Is this the human player
		if(isPlayer)
		{
			m_HumanPlayer = Player;
		}
	}
	return true;
}

void CGameObjectManager::SetHumanPlayer(CPlayer* Player)
{
	m_HumanPlayer = Player;
}

void CGameObjectManager::ChangePlayerTeam(CPlayer* Player, E_PLAYER_TEAM Team)
{
	if(Player)
	{
		auto oldTeam = (u32)Player->GetPlayerTeam();
		auto newTeam = (u32)Team;

		// Remove from the old team
		auto it = find(m_Teams[oldTeam].begin(), m_Teams[oldTeam].end(), Player);
		if(it != m_Teams[oldTeam].end())
			m_Teams[oldTeam].erase(it);

		// Add player to the new team
		m_Teams[newTeam].push_back(Player);
	}
	
	
}

void CGameObjectManager::RemovePlayer(CPlayer* Player)
{
	if(Player)
	{
		RemoveFromPlayerList(Player);
		if(Player->GetIsHumanPlayer())
			m_HumanPlayer = nullptr;
		CORE_DELETE(Player);
	}
}

void CGameObjectManager::RemoveAllPlayers()
{
	if(m_Players.size() > 0)
	{
		RemovePlayer(m_Players[0]);
		RemoveAllPlayers();
	}

	m_HumanPlayer = nullptr;
}

void CGameObjectManager::RemoveFromPlayerList(CPlayer* Player)
{
	// Remove the player from the team
	auto team = Player->GetPlayerTeam();
	if((u32)team <= NUM_TEAMS)
	{
		auto teamRoster = m_Teams[(u32)team];
		for(u32 i = 0; i < teamRoster.size(); i++)
		{
			if(teamRoster[i] == Player)
			{
				m_Teams[(u32)team].erase(m_Teams[(u32)team].begin() + i);
				break;
			}
		}
	}

	// Can compare against the pointer address
	for(u32 i = 0; i < m_Players.size(); i++)
	{
		if(m_Players[i] == Player)
		{
			m_Players.erase(m_Players.begin() + i);
			break;
		}
	}
}

CPlayer* CGameObjectManager::GetClosestVisibleEnemy(CPlayer* Player)
{
	// Finds the closest player on a different team that is visible
	CPlayer* ret = nullptr;
	f32 max = 9999999;

	for(u32 i = 0; i < NUM_TEAMS; i++)
	{
		if((u32)Player->GetPlayerTeam() != i)
		{
			for(auto it = m_Teams[i].cbegin(); it != m_Teams[i].cend(); it++)
			{
				if(Player->CanSee((*it)) && (*it)->GetHealth() > 0 && Player != (*it))
				{
					float d = Player->GetPosition().squaredDistance((*it)->GetPosition());
					if (d < max)
					{
						max = d;
						ret = (*it);
					}
				}
			}

		}
	}
	return ret;
}

CPlayer* CGameObjectManager::GetClosestEnemy(CPlayer* Player)
{
	// Finds the closest player on a different team
	CPlayer* ret = nullptr;
	f32 max = 9999999;

	for(u32 i = 0; i < NUM_TEAMS; i++)
	{
		if((u32)Player->GetPlayerTeam() != i)
		{
			for(auto it = m_Teams[i].cbegin(); it != m_Teams[i].cend(); it++)
			{
				f32 d = Player->GetPosition().squaredDistance((*it)->GetPosition());
				if (d < max)
				{
					max = d;
					ret = (*it);
				}
			}

		}
	}
	return ret;
}

// Obstacle methods
void CGameObjectManager::AddSphereObstacle(CGameObject* GameObject)
{
	f32 radius = GameObject->Entity->getBoundingRadius();
	Vector3 center = GameObject->Node->getPosition();

	// If its been scaled
	Vector3 scale = GameObject->Node->getScale();
	if(scale.x > scale.y && scale.x > scale.z)
		radius *= scale.x;
	if(scale.y > scale.x && scale.y > scale.z)
		radius *= scale.y;
	else
		radius *= scale.z;

	SphereObstacle* obs = new SphereObstacle(radius, center);

	m_ObsObj[GameObject] = obs;
}

void CGameObjectManager::GetObstacles(Vector<AI::Obstacle*>& list)
{
	list.clear();
	for(auto it = m_ObsObj.cbegin(); it != m_ObsObj.cend(); it++)
	{
		list.push_back(it->second);
	}
}

void CGameObjectManager::GetSphereObstacles(Vector<AI::Obstacle*>& list)
{
	for(auto it = m_ObsObj.cbegin(); it != m_ObsObj.cend(); it++)
	{
		if(it->second->getObstacleType() == AbstractObstacle::OT_SPHERE)
			list.push_back(it->second);
	}
}

void CGameObjectManager::AddBoxObstacle(CGameObject* GameObject)
{
	AxisAlignedBox box = GameObject->Entity->getBoundingBox();

	// If its been scaled
	Vector3 size = box.getSize() * GameObject->Node->getScale();

	BoxObstacle* obs = new BoxObstacle(size.x, size.y, size.z);
	obs->SetPosition(GameObject->Node->getPosition());

	m_ObsObj[GameObject] = obs;
}

void CGameObjectManager::RemoveObstacle(CGameObject* GameObject)
{
	auto it = m_ObsObj.find(GameObject);
	if(it != m_ObsObj.end())
	{
		if(it->second)
			delete it->second;		// Use regular delete because this is a const.
		m_ObsObj.erase(it);
		return;
	}
}

// Game object methods
String CGameObjectManager::CreateName(const char* Name)
{
	String ret;
	if(Name == nullptr || String(Name) == "")
		ret = "obj_" + StringConverter::toString(m_GameObjectCounter);
	else
		ret = String(Name) + String("_" + StringConverter::toString(m_GameObjectCounter));

	return ret;
}

Core::CGameObject* CGameObjectManager::CreateObject(const char* GameObjectType)
{
	// Creates an object that is loaded as a plugin
	if(GameObjectType)
		return CreateObject(GameObjectType, nullptr, Vector3(0, 0, 0));

	return nullptr;
}

Core::CGameObject* CGameObjectManager::CreateObject(const char* GameObjectType, const char* Name, Vector3& Pos)
{
	// Creates an object that is loaded as a plugin
	CGameObject* obj = nullptr;
	String str = GameObjectType;
	
	// Check name
	String name = Name == nullptr ? "" : Name;
	if(name.length() == 0)
		name = CreateName(nullptr);

	auto factories = m_PluginManager->GetGameObjectFactories();

	// Find the custom object (plugin) and use it
	for(auto it = factories.cbegin(); it != factories.cend(); it++)
	{
		if((*it)->GameObjectType == str)
		{
			obj = (*it)->CreateObject(name.c_str(), Pos);
			
			// Add it to the objects list
			if(obj)
			{
				m_GameObjects.push_back(obj);
				m_GameObjectCounter++;
			}

			break;
		}
	}

	// Error logging
	if(!obj)
	{
		String msg = "Unable to load game object: ";
		msg += GameObjectType;
		CORE_ERR(msg.c_str());
	}

	return obj;
}

void CGameObjectManager::GetGameObjects(Vector<CGameObject*>& GameObjects) 
{ 
	GameObjects.clear();
	GameObjects = m_GameObjects; 
}

void CGameObjectManager::GetAllObjectTypes(Vector<const char*>& ObjectTypes)
{
	auto factories = m_PluginManager->GetGameObjectFactories();
	for(auto it = factories.cbegin(); it != factories.cend(); it++)
	{
		ObjectTypes.push_back((*it)->GameObjectType.c_str());
	}
}

Core::CGameObject* CGameObjectManager::CreateCustomObject(const char* MeshName)
{
	// Creates an object by the mesh name
	String Name = CreateName(nullptr);
	return CreateCustomObject(MeshName, Name.c_str(), Vector3(0, 0, 0));
}

Core::CGameObject* CGameObjectManager::CreateCustomObject(const char* MeshName, const char* Name, Vector3& Pos)
{
	// Creates an object by the mesh name
	CGameObject* obj = nullptr;

	// Check name
	String name;
	if(!Name)
		name = CreateName(Name);

	SceneManager* sm = CGameManager::Instance()->GetSceneManager();
	SceneNode* Node = sm->getRootSceneNode()->createChildSceneNode(Name + String("_node"), Pos);
	if(Node)
	{
		Node->setScale(1, 1, 1);
		Entity* entity = sm->createEntity(Name + String("_entity"), MeshName);
		if(entity)
		{
			entity->setQueryFlags(0);
			Node->attachObject(entity);
			obj = new CDummyGameObject(name.c_str(), Node, entity);
			if(obj)
			{
				obj->GameObjectType = "CUSTOM";
				m_GameObjects.push_back(obj);
			}
		}
	}

	return obj;
}

void CGameObjectManager::SetGameObjectUpdatable(CGameObject* GameObject, bool Value)
{
	// See if the object is in the update list
	auto it = std::find(m_UpdatableGameObjects.cbegin(), m_UpdatableGameObjects.cend(), GameObject);
	if(Value)
	{
		
		if(it == m_UpdatableGameObjects.cend())
		{
			m_UpdatableGameObjects.push_back(GameObject);
		}
	}
	else
	{
		if(it != m_UpdatableGameObjects.cend())
		{
			m_UpdatableGameObjects.erase(it);
		}
	}

}

CGameObject* CGameObjectManager::GetGameObject(Entity* entity)
{
	for(auto it = m_GameObjects.cbegin(); it != m_GameObjects.cend(); it++)
	{
		if((*it)->Entity == entity)
			return (*it);
	}

	return nullptr;
}

CGameObject* CGameObjectManager::GetGameObject(const char* Name)
{
	for(auto it = m_GameObjects.cbegin(); it != m_GameObjects.cend(); it++)
	{
		if(strncmp((*it)->Name.c_str(), Name, (*it)->Name.size()) == 0)
			return (*it);
	}

	return nullptr;
}

CGameObject* CGameObjectManager::GetGameObjectByEntityName(const char* Name)
{
	for(auto it = m_GameObjects.cbegin(); it != m_GameObjects.cend(); it++)
	{
		if(strncmp((*it)->Entity->getName().c_str(), Name, (*it)->Entity->getName().size()) == 0)
			return (*it);
	}

	return nullptr;
}

void CGameObjectManager::RemoveGameObject(CGameObject* GameObject)
{
	// Remove from object list
	for(u32 i = 0; i < m_GameObjects.size(); i++)
	{
		if(GameObject == m_GameObjects[i])
		{
			m_GameObjects.erase(m_GameObjects.begin() + i);
			break;
		}
	}

	// Remove from update list (if its in there)
	for(u32 i = 0; i < m_UpdatableGameObjects.size(); i++)
	{
		if(GameObject == m_UpdatableGameObjects[i])
		{
			m_UpdatableGameObjects.erase(m_UpdatableGameObjects.begin() + i);
			break;
		}
	}

	// Remove the game object as an obstacle
	RemoveObstacle(GameObject);

	CORE_DELETE(GameObject);
}

// Event methods
void CGameObjectManager::Update(const f32& elapsedTime)
{
	_ASSERTE(_CrtCheckMemory());
	// Update all AI players
	//#pragma omp parallel for
	for(auto it = m_Players.begin(); it != m_Players.end();)
	{	
		// If they are dead, don't update, and remove from the list
		if((*it)->GetPlayerState() == EPS_DEAD)
		{
			// Remove the player from the team
			auto team = (*it)->GetPlayerTeam();
			if((u32)team <= NUM_TEAMS)
			{
				auto teamRoster = m_Teams[(u32)team];
				for(u32 i = 0; i < teamRoster.size(); i++)
				{
					if(teamRoster[i] == (*it))
					{
						m_Teams[(u32)team].erase(m_Teams[(u32)team].begin() + i);
						break;
					}
				}
			}

			if((*it)->GetIsHumanPlayer())
				m_HumanPlayer = nullptr;
			CORE_DELETE((*it));
			it = m_Players.erase(it);
		}
		else
		{
			(*it)->Update(elapsedTime);
			it++;
		}
	}

	// Update all AI players
	//#pragma omp parallel for
	for(u32 i = 0; i < m_UpdatableGameObjects.size(); i++)
	{
		m_UpdatableGameObjects[i]->Update(elapsedTime);
	}
	_ASSERTE(_CrtCheckMemory());
}

void CGameObjectManager::Shutdown()
{
	try
	{
		// Remove all the objects and obstacles
		while(m_GameObjects.size() > 0)
			RemoveGameObject(m_GameObjects[0]);
		m_GameObjects.clear();

		// Remove all walls
		for(auto it = m_Walls.begin(); it != m_Walls.end(); it++)
			CORE_DELETE((*it));

		// Remove all players
		while(m_Players.size() > 0)
		{
			CORE_DELETE(m_Players[0]);
			m_Players.erase(m_Players.begin());
		}

		// Remove all buidings
		while(m_Buildings.size() > 0)
		{
			CORE_DELETE(m_Buildings[0]);
			m_Buildings.erase(m_Buildings.begin());
		}

		m_GameObjectCounter = 0;
		m_PlayerCounter = 0;
		m_BuildingCounter = 0;
	}
	catch(std::exception& e)
	{
		CORE_ASSERT(false);
		throw(e);
	}
	catch(...)
	{
		throw("Error in CGameObjectManager::Shutdown()");
	}

}

void CGameObjectManager::Restart()
{
	// Get our plugin manager
	m_PluginManager = CPluginManager::Instance();
}

// Wall methods
void CGameObjectManager::AddWall(const Vector3& From, const Vector3& To, bool LeftNormal)
{
	AI::Wall* wall = new AI::Wall(From, To, LeftNormal);
	if(wall)
		m_Walls.push_back(wall);
}

void CGameObjectManager::GetWalls(Vector<AI::Wall*>& Walls)
{
	Walls = m_Walls;
}

void CGameObjectManager::RemoveWalls()
{
	for(u32 i = 0; i < m_Walls.size(); i++)
	{
		CORE_DELETE(m_Walls[i]);
	}
	m_Walls.clear();
}

// Building methods
CBuilding* CGameObjectManager::CreateBuilding(const char* Type, E_PLAYER_TEAM Team, const char* LabelName, Physics::IPhysicsStrategy* PhysicsStrategy)
{
	CBuilding* building = nullptr;
	
	String name;
	if(LabelName)
		name = LabelName;
	else
		name = "";

	if(name.length() == 0)
		name = "building_" + StringConverter::toString(m_Buildings.size()) + "_" + StringConverter::toString(m_BuildingCounter);

	auto buildingFactories = m_PluginManager->GetBuildingFactories();
	size_t size = buildingFactories.size();

	// Find the custom object (plugin) and use it
	for(size_t i = 0; i < size; i++)
	{
		if(strncmp(buildingFactories[i]->BuildingType, Type, strlen(Type)) == 0)
		{
			building = buildingFactories[i]->CreateBuilding(name.c_str(), PhysicsStrategy);
			
			// Add it to the objects list
			if(building)
			{
				m_Buildings.push_back(building);
			}
			else
			{
				String msg("Unable to load building type: ");
				msg += Type;
				CORE_ERR(msg.c_str());
				return nullptr;
			}

			break;
		}
	}

	if(!building)
	{
		String msg = "Could not find building of type: " + String(Type);
		CORE_ERR(msg.c_str());
	}
	else
	{
		// Set team
		building->SetTeam(Team);
	}

	//// Trigger script
	//if(building)
	//{
	//	CALL_VOIDFUNCCONSTCHAR("OnBuildingCreated", player->GetName());
	//}

	m_BuildingCounter++;
	return building;
}

CBuilding* CGameObjectManager::GetBuildingByEntityName(const char* EntityName)
{
	for(auto it = m_Buildings.cbegin(); it != m_Buildings.cend(); it++)
	{
		if(strncmp((*it)->GetEntity()->getName().c_str(), EntityName, (*it)->GetEntity()->getName().size()) == 0)
			return (*it);
	}

	return nullptr;
}

void CGameObjectManager::RemoveBuilding(CBuilding* Building)
{
}

void CGameObjectManager::RemoveAddBuildings()
{
}

void CGameObjectManager::GetAllBuildingTypes(Vector<const char*>& ObjectTypes)
{
	auto factories = m_PluginManager->GetBuildingFactories();
	for(auto it = factories.cbegin(); it != factories.cend(); it++)
	{
		ObjectTypes.push_back((*it)->BuildingType);
	}
}

Vector<CBuilding*>& CGameObjectManager::GetAllBuildings()
{
	return m_Buildings;
}