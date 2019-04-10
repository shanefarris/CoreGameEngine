#ifndef __QUERYSTRINGS_H__
#define __QUERYSTRINGS_H__

#define TRAININGMANAGER_BUILDINGS "SELECT BuildingTypes.TypeValue, Buildings.Team " \
									"FROM Buildings Inner Join BuildingTypes On Buildings.BuildingTypeId = BuildingTypes.BuildingTypeId " \
									"ORDER by Buildings.Team"
#define PLAYER_ALL(ID)			"SELECT * FROM Player WHERE PlayerID='" + ID + "'"
#define PLAYERS_ALL				"SELECT * FROM Players"
#define ASTAR_ALL				"SELECT * FROM AStarNodes Orderby NodeId"
#define AI_PATHS_ALL			"SELECT * FROM AiPaths"
#define PLAYER_ITEMS			"SELECT * FROM PlayerInventory"
#define PLAYER_PATHS_ALL		"SELECT * FROM PlayerPaths"
#define LEVEL_INVENTORY_ALL		"SELECT * FROM LevelInventory"
#define GAMEOBJECTS_ALL			"SELECT * FROM GameObjects"
#define SPAWN_POINTS_ALL		"SELECT * FROM SpawnPoints"
#define BUILDINGS_ALL			"SELECT * FROM Buildings"
#define STATIC_DATA_ALL			"SELECT * FROM StaticData"
#define CREATE_EMPTY_DB "CREATE TABLE AStarNodes (NodeId INTEGER NOT NULL, Position VARCHAR(50) NOT NULL, Cost INTEGER NOT NULL, Neighbors VARCHAR(50)); " \
						"CREATE TABLE AiPaths (PathId INTEGER PRIMARY KEY AUTOINCREMENT, Name VARCHAR(50) NOT NULL, Vectors TEXT NOT NULL); " \
						"CREATE TABLE Buildings (BuildingID INTEGER PRIMARY KEY AUTOINCREMENT, BuildingCategory INTEGER NOT NULL, Team INTEGER NOT NULL, Health REAL NOT NULL, BuildingState INTEGER NOT NULL, Position TEXT NOT NULL, Name VARCHAR(50) NOT NULL, BuildingType VARCHAR(50) NOT NULL, DataValue VARCHAR(50)); " \
						"CREATE TABLE GameObjects (GameObjectsID INTEGER PRIMARY KEY AUTOINCREMENT, Name VARCHAR(50) NOT NULL, Type VARCHAR(50) NOT NULL, Orientation TEXT NOT NULL, Position TEXT NOT NULL); " \
						"CREATE TABLE JobTypes (JobTypeID INTEGER PRIMARY KEY AUTOINCREMENT, Name VARCHAR(50) NOT NULL, Description TEXT NOT NULL); " \
						"CREATE TABLE LevelInventory (LevelInventoryID INTEGER PRIMARY KEY AUTOINCREMENT, ItemName VARCHAR(50) NOT NULL, ProfileName VARCHAR(50) NOT NULL, Orientation TEXT NOT NULL, Position TEXT NOT NULL); " \
						"CREATE TABLE PhysicsStrategies (PhysicsID INTEGER PRIMARY KEY, Name VARCHAR(50) NOT NULL, Type INTEGER NOT NULL); " \
						"CREATE TABLE PlayerInventory (PlayerID INTEGER NOT NULL, PlayerInventoryID INTEGER PRIMARY KEY AUTOINCREMENT, IsCurrentItem BOOL DEFAULT 0, ProfileName TEXT NOT NULL, FOREIGN KEY(PlayerId) REFERENCES Players(PlayerId)); " \
						"CREATE TABLE PlayerJobs (JobTypeID INTEGER, PlayerId INTEGER, FOREIGN KEY(JobTypeID) REFERENCES JobTypes(JobTypeID), FOREIGN KEY(PlayerId) REFERENCES Players(PlayerId)); " \
						"CREATE TABLE PlayerPaths (PathId INTEGER NOT NULL, PlayerId INTEGER NOT NULL, FOREIGN KEY(PathId) REFERENCES AiPaths(PathId), FOREIGN KEY(PlayerId) REFERENCES Players(PlayerId)); " \
						"CREATE TABLE Players (PlayerID INTEGER PRIMARY KEY AUTOINCREMENT, Name VARCHAR(50) NOT NULL, Position TEXT NOT NULL, CrawlSpeed REAL NOT NULL, SprintSpeed REAL NOT NULL, IsHumanPlayer BOOL NOT NULL DEFAULT 0, ViewRange REAL NOT NULL, DieingTime REAL NOT NULL, MovableText TEXT, CharacterState VARCHAR(50) NOT NULL, Direction TEXT NOT NULL, PlayerType TEXT NOT NULL, Health REAL NOT NULL, Team INTEGER NOT NULL, RunSpeed REAL NOT NULL DEFAULT 0, ReloadSpeed REAL NOT NULL DEFAULT 0, RifleMarksman REAL NOT NULL DEFAULT 0, PhysicalStrength REAL NOT NULL DEFAULT 0); " \
						"CREATE TABLE SpawnPoints (Id INTEGER, Position TEXT NOT NULL, Team INTEGER, CoolDown REAL); " \
						"CREATE TABLE StaticData (XmlData TEXT); "
#define CLEAR_DB "DELETE FROM AStarNodes;" \
				 "DELETE FROM AiPaths;" \
				 "DELETE FROM Buildings;" \
				 "DELETE FROM GameObjects;" \
				 "DELETE FROM JobTypes;" \
				 "DELETE FROM LevelInventory;" \
				 "DELETE FROM PhysicsStrategies;" \
				 "DELETE FROM PlayerInventory;" \
				 "DELETE FROM PlayerJobs;" \
				 "DELETE FROM PlayerPaths;" \
				 "DELETE FROM Players;" \
				 "DELETE FROM SpawnPoints;" \
				 "DELETE FROM StaticData;"
#define AIPATHS_PLAYERS_JOINED "SELECT AiPaths.Name FROM PlayerPaths " \
								"INNER JOIN AiPaths on AiPaths.PathId = PlayerPaths.PathId " \
								"INNER JOIN Players on Players.PlayerId = PlayerPaths.PlayerId " \
								"WHERE Players.PlayerId = [PLAYERID];";

#endif // __QUERYSTRINGS_H__
