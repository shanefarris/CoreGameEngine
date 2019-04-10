// Container for application level data.

#ifndef __CGAMEOBJECTMANAGER_H__
#define __CGAMEOBJECTMANAGER_H__

#include <iostream>

#include "Defines.h"
#include "PlayerEnums.h"

namespace Core
{
	class CPlayer;
	class CBuilding;
	class CGameObject;
	class CPluginManager;

	namespace Physics
	{
		class IPhysicsStrategy;
	}

	namespace SceneLoader
	{
		class CSerializer;
	}

	namespace AI
	{
		class CFpsVehicle;
		class Obstacle;
		class SphereObstacle;
		class BoxObstacle;
		class Wall;
	}

	namespace Plugin
	{
		class IGameObjectFactory;
	}

	class CORE_EXPORT CGameObjectManager
	{
		friend SceneLoader::CSerializer;

	public:
		typedef Map<CGameObject*, AI::Obstacle*> ObstacleList;

		static CGameObjectManager* Instance();
		
		~CGameObjectManager();

		// Game Objects
		CGameObject* CreateObject(const char* GameObjectType);		// Objects from plugins
		CGameObject* CreateObject(const char* GameObjectType, const char* Name, Vector3& Pos);
		CGameObject* CreateCustomObject(const char* MeshName);		// Objects without plugins
		CGameObject* CreateCustomObject(const char* MeshName, const char* Name, Vector3& Pos);
		CGameObject* GetGameObject(Entity* entity);					// Search by entity pointer
		CGameObject* GetGameObject(const char* Name);				// Search by game object name
		CGameObject* GetGameObjectByEntityName(const char* Name);	// Search by entity name, used when doing a scene query, and all you get back is a movable object
		void		 SetGameObjectUpdatable(CGameObject* GameObject, bool Value);
		void		 GetGameObjects(Vector<CGameObject*>& GameObjects);
		void		 GetAllObjectTypes(Vector<const char*>& ObjectTypes);
		void		 RemoveGameObject(CGameObject* GameObject);

		// Player methods
		CPlayer* CreatePlayer(const char* Type, E_PLAYER_TEAM Team, const char* LabelName = "", Physics::IPhysicsStrategy* PhysicsStrategy = nullptr, bool isPlayer = false);
		bool	 CreateCustomPlayer(CPlayer* Player, E_PLAYER_TEAM Team, const char* LabelName = "", Physics::IPhysicsStrategy* PhysicsStrategy = nullptr, bool isPlayer = false);
		bool	 AddCustomPlayer(CPlayer* Player, E_PLAYER_TEAM Team, bool isPlayer = false);
		void	 RemovePlayer(CPlayer* Player);
		void	 RemoveAllPlayers();
		void	 GetTeam(E_PLAYER_TEAM Team, std::vector<CPlayer*>& List);
		void	 GetAllPlayers(Vector<CPlayer*>& Players);
		void	 GetPlayerTypes(Vector<const char*>& PlayerType);
		CPlayer* GetHumanPlayer() { return m_HumanPlayer; }
		CPlayer* GetPlayerByName(const char* Name);
		CPlayer* GetPlayerByEntityName(const char* EntityName);
		CPlayer* GetClosestVisibleEnemy(CPlayer* Player);
		CPlayer* GetClosestEnemy(CPlayer* Player);
		void	 SetHumanPlayer(CPlayer* Player);
		void	 ChangePlayerTeam(CPlayer* Player, E_PLAYER_TEAM Team);

		// Building methods
		CBuilding*  CreateBuilding(const char* Type, E_PLAYER_TEAM Team, const char* LabelName, Physics::IPhysicsStrategy* PhysicsStrategy);
		CBuilding*	GetBuildingByEntityName(const char* EntityName);
		void		RemoveBuilding(CBuilding* Building);
		void		RemoveAddBuildings();
		void		GetAllBuildingTypes(Vector<const char*>& ObjectTypes);
		Vector<CBuilding*>&	GetAllBuildings();

		// Events
		void Update(const f32& elapsedTime);
		void Shutdown();												// Destroy all objects, players and obstacles
		void Restart();													// Ensure the manager is ready to do its job again.

		// Obstacles
		void AddSphereObstacle(CGameObject* GameObject);
		void AddBoxObstacle(CGameObject* GameObject);
		void GetObstacles(Vector<AI::Obstacle*>& list);
		void GetSphereObstacles(Vector<AI::Obstacle*>& list);			// Only sphere obstacles, temp fix for opensteer not working on all types of obstacles
		void RemoveObstacle(CGameObject* GameObject);

		// Walls
		void AddWall(const Vector3& From, const Vector3& To, bool LeftNormal = false);
		void GetWalls(Vector<AI::Wall*>& Walls);
		void RemoveWalls();

	private:
		CGameObjectManager();

		// Creates an internal unquie name for ogre
		String CreateName(const char* Name);

		// Player Methods
		void RemoveFromPlayerList(CPlayer* Player);					// Removes the player from the players list

		// Obstacle Methods
		AI::SphereObstacle* FindClosestSphereObstacle(CPlayer* Player, f32& Max);
		AI::BoxObstacle* FindClosestBoxObstacle(CPlayer* Player, f32& Max);
		
		// Game Objects
		Vector<CGameObject*>		m_GameObjects;					// All game objects including objects that are NOT updated every frame
		Vector<CGameObject*>		m_UpdatableGameObjects;			// All game objects that need to be updated every frame

		// Players
		CPlayer*					m_HumanPlayer;					// Current human player
		Vector<CPlayer*>			m_Players;						// Used to run updates on all players including the human player
		Vector<CPlayer*>			m_Teams[NUM_TEAMS];				// Used to do queries based on the teams for each player

		// Buildings
		Vector<CBuilding*>			m_Buildings;					// All buildings
		Vector<CBuilding*>			m_UpdatableBuildings;			// All updatable buildings

		ObstacleList				m_ObsObj;						// Map objects to obstacles
		Vector<AI::Wall*>			m_Walls;
		static CGameObjectManager*	GameObjectManager;
		Core::CPluginManager*		m_PluginManager;
		u32							m_GameObjectCounter;			// Number of game objects that have been created
		u32							m_PlayerCounter;				// Number of players that have been created
		u32							m_BuildingCounter;				// Number of buildings that have been created

	};
}

#endif // __CGAMEOBJECTMANAGER_H__
