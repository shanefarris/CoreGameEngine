#include "CParserStrategies.h"
#include "CPlayer.h"
#include "CBuilding.h"
#include "CGameObjectManager.h"
#include "CUtility.h"
#include "CGameManager.h"
#include "Structures.h"

#include "IO/CMemoryReadFile.h"
#include "IO/CoreLogging.h"
#include "IO/CFileSystem.h"
#include "QueryStrings.h"
#include "FileDatabase/CoreDal.h"

// Ogre
#include "OgreStringConverter.h"

using namespace Core;
using namespace Core::DAL;

CDbParserStrategy::CDbParserStrategy() : m_Database(0)
{
}

CDbParserStrategy::~CDbParserStrategy()
{
	CORE_DELETE(m_Database);
}

bool CDbParserStrategy::ParseScene(const String& Importfile, DATA_CONTAINER& DataContainer)
{
	try
	{
		// Iterate through each row in the objects database and load the entities and nodes
		StderrLog log;
		m_Database = new Database(Importfile, &log); // sqlite3 specific

		if(!m_Database)
		{
			CORE_ERR("Could not find database in CSceneReaderStrategy_DB::ParseScene");
			return false;
		}

		if(!LoadItems(DataContainer))
			return false;
		if(!LoadAiPaths(DataContainer))
			return false;
		if(!LoadPlayers(DataContainer))
			return false;
		if(!LoadGameObjects(DataContainer))
			return false;
		if(!LoadAStarGrid(DataContainer))
			return false;
		if(!LoadStaticData(DataContainer))
			return false;
		if(!LoadSpawnPoints(DataContainer))
			return false;
		if(!LoadBuildings(DataContainer))
			return false;

		CORE_DELETE(m_Database);
	}
	catch(...)
	{
		CORE_DELETE(m_Database);
		return false;
	}
	
	return true;
}

bool CDbParserStrategy::LoadItems(DATA_CONTAINER& DataContainer)
{
	// Loads the level inventory, does not assign inventory to the players.
	// We place the items on the level assuming the item profile is already loaded.
	Query itemsQuery(*m_Database);

	// Inventory table
	itemsQuery.get_result(LEVEL_INVENTORY_ALL);
	while (itemsQuery.fetch_row())
	{
		LevelInventory tbl(m_Database, &itemsQuery); 
		PLACED_ITEM item;
		item.ProfileName = tbl.GetProfilename();
		item.Position = tbl.GetPosition() == nullptr ? Vector3::ZERO : StringConverter::parseVector3(tbl.GetPosition());

		// TODO: add the other fields that are being saved once the inventory manager can use them.

		DataContainer.PlacedItems.push_back(item);
	}
	return true;
}

bool CDbParserStrategy::LoadAiPaths(DATA_CONTAINER& DataContainer)
{
	// Read and display all records
	Query q(*m_Database);

	// AiPaths table
	q.get_result(AI_PATHS_ALL);
	while (q.fetch_row())
	{
		// spawns an object from Query object
		AiPaths tbl(m_Database, &q); 

		AI_PATH aiPath;

		// Get the path name and Id
		aiPath.Name = tbl.GetName();
		aiPath.PathId = tbl.GetPathid();
		
		// Parse the 3D points from ";"
		Vector<String> tokens;
		String allPoints = tbl.GetVectors();
		CUtility::StringSplit(allPoints, ';', tokens);

		// Parse the "," from the tokens
		for(u32 i = 0; i < tokens.size(); i++)
		{
			Vector3 pos;
			if(ParseVector3D(tokens[i], pos))
			{
				aiPath.Points.push_back(pos);
			}
			else
			{
				String msg = "Error parsing 3D vector for paths.";
				CORE_ERR(msg.c_str());
			}
		}
		
		// Add the path to path container
		if(aiPath.Points.size() > 0)
			DataContainer.AiPaths.push_back(aiPath);

	}
	q.free_result();
	return true;
}

bool CDbParserStrategy::LoadGameObjects(DATA_CONTAINER& DataContainer)
{
	// Read and display all records
	Query q(*m_Database);

	// AiPaths table
	q.get_result(GAMEOBJECTS_ALL);
	while (q.fetch_row())
	{
		// spawns an object from Query object
		GameObjects tbl(m_Database, &q); 
		
		GAMEOBJECT go;
		go.Name = tbl.GetName();
		go.ObstacleType = "";
		go.Orientation = tbl.GetOrientation() == nullptr ? Quaternion::IDENTITY : StringConverter::parseQuaternion(tbl.GetOrientation());		
		go.Position = tbl.GetPosition() == nullptr ? Vector3::ZERO : StringConverter::parseVector3(tbl.GetPosition());
		go.MeshFile = "";					// XML option only
		go.Parent = "";						// XML option only
		go.Scale = Vector3::UNIT_SCALE;		// XML option only
		go.Shadows = false;					// XML option only
		go.PhysicsProfileName = "";			// XML option only TODO: is this needed anymore?
		DataContainer.GameObjects.push_back(go);
	}
	q.free_result();
	return true;
}

bool CDbParserStrategy::LoadPlayers(DATA_CONTAINER& DataContainer)
{
	// Read and display all records
	Query q(*m_Database);

	// Players table
	q.get_result(PLAYERS_ALL);
	while (q.fetch_row())
	{
		// spawns an object from Query object
		Players tbl(m_Database, &q); 
					
		// Standard settings
		PLAYER player;
		player.Name = tbl.GetName();
		player.CrawlSpeed = tbl.GetCrawlspeed();
		player.DieingTime = tbl.GetDieingtime();
		player.Direction = tbl.GetDirection() == nullptr ? Vector3::UNIT_Z : StringConverter::parseVector3(tbl.GetDirection());
		player.Health = tbl.GetHealth();
		player.IsHumanplayer = tbl.GetIshumanplayer();
		player.MovableText = tbl.GetMovabletext();
		player.PhysicalStrength = tbl.GetPhysicalstrength();
		player.PlayerType = tbl.GetPlayertype();
		player.Position = tbl.GetPosition() == nullptr ? Vector3::ZERO : StringConverter::parseVector3(tbl.GetPosition());
		player.ReloadSpeed = tbl.GetReloadspeed();
		player.RifleMarksman = tbl.GetRiflemarksman();
		player.RunSpeed = tbl.GetRunspeed();
		player.SprintSpeed = tbl.GetSprintspeed();
		player.ViewRange = tbl.GetViewrange();
		player.PlayerType = tbl.GetPlayertype();
		player.Team = static_cast<E_PLAYER_TEAM>(tbl.GetTeam());
		player.CharacterState = tbl.GetCharacterstate();

		// Ai paths
		String cmdQuery = PLAYER_PATHS_ALL;
		cmdQuery += String(" WHERE PlayerId='");
		cmdQuery += StringConverter::toString(tbl.GetPlayerid());
		cmdQuery += "'";
		Query aiPathsQuery(*m_Database);
		aiPathsQuery.get_result(cmdQuery);
		while (aiPathsQuery.fetch_row())
		{
			AiPaths tblPaths(m_Database, &aiPathsQuery); 
			u32 pathId = tblPaths.GetPathid();
			for(auto it = DataContainer.AiPaths.cbegin(); it != DataContainer.AiPaths.cend(); it++)
			{
				if((*it).PathId == pathId)
				{
					player.PlayerPaths.push_back((*it));
				}
			}
		}

		// Player inventory
		cmdQuery = PLAYER_ITEMS;
		cmdQuery += String(" WHERE PlayerId='");
		cmdQuery += StringConverter::toString(tbl.GetPlayerid());
		cmdQuery += "'";
		Query itemsQuery(*m_Database);
		itemsQuery.get_result(cmdQuery);
		while (itemsQuery.fetch_row())
		{
			PlayerInventory tblInventory(m_Database, &itemsQuery); 
			PLAYER_INVENTORY pi;
			pi.ProfileName = tblInventory.GetProfilename();
			pi.IsActive = tblInventory.GetIscurrentitem();
			player.PlayerInventory.push_back(pi);
		}

		DataContainer.Players.push_back(player);

	}
	q.free_result();
	return true;
}

bool CDbParserStrategy::LoadAStarGrid(DATA_CONTAINER& DataContainer)
{
	// Read and display all records
	Query q(*m_Database);

	// AiPaths table
	q.get_result(ASTAR_ALL);
	Vector<String> elements;
	while (q.fetch_row())
	{
		// spawns an object from Query object
		AStarNodes tbl(m_Database, &q); 
		elements.clear();

		ASTAR_NODE node;
		node.Cost = tbl.GetCost();
		node.NodeId = tbl.GetNodeid();

		// Get position
		node.Position = StringConverter::parseVector3(tbl.GetPosition(), INVALID_POS);
		if(node.Position == INVALID_POS)
		{
			CORE_ERR("Invalid position for A* node.");
			return false;
		}

		// Get neighbors
		String str = tbl.GetNeighbors();
		
		CUtility::StringSplit(str, ',', elements);
		for(u32 i = 0; i < elements.size(); i++)
		{
			str = elements[i];
			int value = StringConverter::parseInt(str, -1);
			if(value > -1)
			{
				node.Neighbors.push_back(value);
			}
		}

		DataContainer.AStarGrid.Nodes.push_back(node);
	}
	q.free_result();
	return true;
}

bool CDbParserStrategy::LoadSpawnPoints(DATA_CONTAINER& DataContainer)
{
	// Read and display all records
	Query q(*m_Database);

	// SpawnPoints table
	q.get_result(SPAWN_POINTS_ALL);
	while (q.fetch_row())
	{
		SpawnPoints tbl(m_Database, &q); 

		SPAWN_POINT spawnPoint;
		spawnPoint.Id = tbl.GetId();
		spawnPoint.CoolDown = tbl.GetCooldown();
		
		if(tbl.GetTeam() > 0)
		{
			spawnPoint.Team = (E_PLAYER_TEAM)tbl.GetTeam();
		}

		// Get position
		spawnPoint.Position = StringConverter::parseVector3(tbl.GetPosition(), INVALID_POS);
		if(spawnPoint.Position == INVALID_POS)
		{
			CORE_ERR("Invalid position for spawn point.");
			return false;
		}

		DataContainer.SpawnPoints.push_back(spawnPoint);
	}
	q.free_result();
	return true;
}

bool CDbParserStrategy::LoadBuildings(DATA_CONTAINER& DataContainer)
{
	// Read and display all records
	Query q(*m_Database);

	// Buildings table
	q.get_result(BUILDINGS_ALL);
	while (q.fetch_row())
	{
		Buildings tbl(m_Database, &q); 

		BUILDING building;
		building.Category = (E_BUILDING_CATEGORY)tbl.GetBuildingcategory();
		building.Health = (f32)tbl.GetHealth();
		building.Name = tbl.GetName();
		building.Position = StringConverter::parseVector3(tbl.GetPosition(), INVALID_POS);
		building.State = (E_BUILDING_STATE)tbl.GetBuildingstate();
		building.Team = (E_PLAYER_TEAM)tbl.GetTeam();
		building.BuildingType = tbl.GetBuildingtype();

		// Get position
		if(building.Position == INVALID_POS)
		{
			CORE_ERR("Invalid position for building.");
			return false;
		}

		DataContainer.Buildings.push_back(building);
	}
	q.free_result();
	return true;
}

bool CDbParserStrategy::LoadStaticData(DATA_CONTAINER& DataContainer)
{
	bool ret = false;

	// Read and display all records
	Query q(*m_Database);

	// Static data table
	q.get_result(STATIC_DATA_ALL);
	if(q.num_rows() == 1 && q.fetch_row())
	{
		// spawns an object from Query object
		StaticData tbl(m_Database, &q); 
		DataContainer.StaticData = tbl.GetXmldata();
		assert(_CrtCheckMemory());

		try
		{
			auto memoryReader = new IO::CMemoryReadFile((void*)DataContainer.StaticData.data(), (s32)DataContainer.StaticData.size(), "", false);
			if(memoryReader->GetSize() == 0)
				return false;

			CFileSystem FileSystem;
			auto xml = FileSystem.CreateXMLReader(memoryReader);

			CXmlParserStrategy xmlParser;
			ret = xmlParser.ParseScene(*xml, DataContainer);

			CORE_DELETE(xml);
			assert(_CrtCheckMemory());
		}
		catch(...)
		{
			CORE_ERR("IO::CMemoryReadFile alloc in CDbParserStrategy::LoadStaticData.");
		}
	}
	q.free_result();
	assert(_CrtCheckMemory());
	return ret;
}

bool CDbParserStrategy::ParseVector3D(const String& DataValue, Vector3& Out)
{
	Vector<String> subTokens;
	CUtility::StringSplit(DataValue, ',', subTokens);

	if(subTokens.size() == 3)
	{
		Out.x = StringConverter::parseReal(subTokens[0]);
		Out.y = StringConverter::parseReal(subTokens[1]);
		Out.z = StringConverter::parseReal(subTokens[2]);
		return true;
	}
	return false;
}
