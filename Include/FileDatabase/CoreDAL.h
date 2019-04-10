// Generated DAL code. 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sqlite3.h"
#include "IError.h"
#include "StderrLog.h"
#include "Database.h"
#include "Query.h"
#include <map>

#include <vector>
#include <string>

#ifndef _COREDAL_H
#define _COREDAL_H

#ifdef _WIN32
#define strncasecmp _strnicmp
#define strcasecmp stricmp
#pragma warning(push)
#pragma warning(disable:4251)

#ifdef CORE_DLL
	#define CORE_EXPORT __declspec(dllexport)
#else
	#define CORE_EXPORT __declspec(dllimport)
#endif
#endif // _WIN32

namespace Core
{
namespace DAL
{
//  Class 'AStarNodes'
class __declspec(dllexport) AStarNodes {
public:
	AStarNodes(Database *);
	AStarNodes(Database *,const std::string& );
	AStarNodes(Database *,Query *,int = 0 /* offset */);
	~AStarNodes();
	Database& GetDatabase() { return *database; }

	unsigned __int64 insert();
	void save();
	std::string xml();
	std::string xml(const std::string& ,const std::string& );
	size_t num_cols();

	long GetNodeid() { return this -> nodeid; }
	void SetNodeid(long x) { this -> nodeid = x; }
	const char *GetPosition() { return this -> position.c_str(); }
	void SetPosition(const std::string&  x) { this -> position = x; }
	float GetCost() { return this -> cost; }
	void SetCost(float x) { this -> cost = x; }
	const char *GetNeighbors() { return this -> neighbors.c_str(); }
	void SetNeighbors(const std::string&  x) { this -> neighbors = x; }

	// table columns
private:
	long         nodeid; // INTEGER
	std::string  position; // VARCHAR(50)
	float        cost; // REAL
	std::string  neighbors; // VARCHAR(50)
	//
	void clear();
	void spawn(const std::string& );
	void spawn(Query *,int = 0 /* offset */);
	void select(const std::string& );
	//
	Database *database;
	short new_object;
}; // End of class 'AStarNodes'

//  Class 'AiPaths'
class __declspec(dllexport) AiPaths {
public:
	AiPaths(Database *);
	AiPaths(Database *,const std::string& );
	AiPaths(Database *,Query *,int = 0 /* offset */);
	AiPaths(Database&,long pathid);
	~AiPaths();
	Database& GetDatabase() { return *database; }

	unsigned __int64 insert();
	void update();
	void save();
	void erase();
	std::string xml();
	std::string xml(const std::string& ,const std::string& );
	size_t num_cols();

	long GetPathid() { return this -> pathid; }
	void SetPathid(long x) { this -> pathid = x; }
	const char *GetName() { return this -> name.c_str(); }
	void SetName(const std::string&  x) { this -> name = x; }
	const char *GetVectors() { return this -> vectors.c_str(); }
	void SetVectors(const std::string&  x) { this -> vectors = x; }

	// table columns
private:
	long         pathid; // INTEGER
	std::string  name; // VARCHAR(50)
	std::string  vectors; // TEXT
	//
	void clear();
	void spawn(const std::string& );
	void spawn(Query *,int = 0 /* offset */);
	void select(const std::string& );
	void update(long pathid);
	//
	Database *database;
	short new_object;
}; // End of class 'AiPaths'

//  Class 'Buildings'
class __declspec(dllexport) Buildings {
public:
	Buildings(Database *);
	Buildings(Database *,const std::string& );
	Buildings(Database *,Query *,int = 0 /* offset */);
	Buildings(Database&,long buildingid);
	~Buildings();
	Database& GetDatabase() { return *database; }

	unsigned __int64 insert();
	void update();
	void save();
	void erase();
	std::string xml();
	std::string xml(const std::string& ,const std::string& );
	size_t num_cols();

	long GetBuildingid() { return this -> buildingid; }
	void SetBuildingid(long x) { this -> buildingid = x; }
	long GetBuildingcategory() { return this -> buildingcategory; }
	void SetBuildingcategory(long x) { this -> buildingcategory = x; }
	long GetTeam() { return this -> team; }
	void SetTeam(long x) { this -> team = x; }
	float GetHealth() { return this -> health; }
	void SetHealth(float x) { this -> health = x; }
	long GetBuildingstate() { return this -> buildingstate; }
	void SetBuildingstate(long x) { this -> buildingstate = x; }
	const char *GetPosition() { return this -> position.c_str(); }
	void SetPosition(const std::string&  x) { this -> position = x; }
	const char *GetName() { return this -> name.c_str(); }
	void SetName(const std::string&  x) { this -> name = x; }
	const char *GetBuildingtype() { return this -> buildingtype.c_str(); }
	void SetBuildingtype(const std::string&  x) { this -> buildingtype = x; }
	const char *GetDatavalue() { return this -> datavalue.c_str(); }
	void SetDatavalue(const std::string&  x) { this -> datavalue = x; }

	// table columns
private:
	long         buildingid; // INTEGER
	long         buildingcategory; // INTEGER
	long         team; // INTEGER
	float        health; // REAL
	long         buildingstate; // INTEGER
	std::string  position; // TEXT
	std::string  name; // VARCHAR(50)
	std::string  buildingtype; // VARCHAR(50)
	std::string  datavalue; // VARCHAR(50)
	//
	void clear();
	void spawn(const std::string& );
	void spawn(Query *,int = 0 /* offset */);
	void select(const std::string& );
	void update(long buildingid);
	//
	Database *database;
	short new_object;
}; // End of class 'Buildings'

//  Class 'GameObjects'
class __declspec(dllexport) GameObjects {
public:
	GameObjects(Database *);
	GameObjects(Database *,const std::string& );
	GameObjects(Database *,Query *,int = 0 /* offset */);
	GameObjects(Database&,long gameobjectsid);
	~GameObjects();
	Database& GetDatabase() { return *database; }

	unsigned __int64 insert();
	void update();
	void save();
	void erase();
	std::string xml();
	std::string xml(const std::string& ,const std::string& );
	size_t num_cols();

	long GetGameobjectsid() { return this -> gameobjectsid; }
	void SetGameobjectsid(long x) { this -> gameobjectsid = x; }
	const char *GetName() { return this -> name.c_str(); }
	void SetName(const std::string&  x) { this -> name = x; }
	const char *GetType() { return this -> type.c_str(); }
	void SetType(const std::string&  x) { this -> type = x; }
	const char *GetMeshfile() { return this -> meshfile.c_str(); }
	void SetMeshfile(const std::string&  x) { this -> meshfile = x; }
	const char *GetPhysicsprofile() { return this -> physicsprofile.c_str(); }
	void SetPhysicsprofile(const std::string&  x) { this -> physicsprofile = x; }
	const char *GetScale() { return this -> scale.c_str(); }
	void SetScale(const std::string&  x) { this -> scale = x; }
	bool GetShadows() { return this -> shadows; }
	void SetShadows(bool x) { this -> shadows = x; }
	const char *GetOrientation() { return this -> orientation.c_str(); }
	void SetOrientation(const std::string&  x) { this -> orientation = x; }
	const char *GetPosition() { return this -> position.c_str(); }
	void SetPosition(const std::string&  x) { this -> position = x; }

	// table columns
private:
	long         gameobjectsid; // INTEGER
	std::string  name; // VARCHAR(50)
	std::string  type; // VARCHAR(50)
	std::string  meshfile; // VARCHAR(50)
	std::string  physicsprofile; // VARCHAR(50)
	std::string  scale; // TEXT
	bool         shadows; // BOOL
	std::string  orientation; // TEXT
	std::string  position; // TEXT
	//
	void clear();
	void spawn(const std::string& );
	void spawn(Query *,int = 0 /* offset */);
	void select(const std::string& );
	void update(long gameobjectsid);
	//
	Database *database;
	short new_object;
}; // End of class 'GameObjects'

//  Class 'JobTypes'
class __declspec(dllexport) JobTypes {
public:
	JobTypes(Database *);
	JobTypes(Database *,const std::string& );
	JobTypes(Database *,Query *,int = 0 /* offset */);
	JobTypes(Database&,long jobtypeid);
	~JobTypes();
	Database& GetDatabase() { return *database; }

	unsigned __int64 insert();
	void update();
	void save();
	void erase();
	std::string xml();
	std::string xml(const std::string& ,const std::string& );
	size_t num_cols();

	long GetJobtypeid() { return this -> jobtypeid; }
	void SetJobtypeid(long x) { this -> jobtypeid = x; }
	const char *GetName() { return this -> name.c_str(); }
	void SetName(const std::string&  x) { this -> name = x; }
	const char *GetDescription() { return this -> description.c_str(); }
	void SetDescription(const std::string&  x) { this -> description = x; }

	// table columns
private:
	long         jobtypeid; // INTEGER
	std::string  name; // VARCHAR(50)
	std::string  description; // TEXT
	//
	void clear();
	void spawn(const std::string& );
	void spawn(Query *,int = 0 /* offset */);
	void select(const std::string& );
	void update(long jobtypeid);
	//
	Database *database;
	short new_object;
}; // End of class 'JobTypes'

//  Class 'LevelInventory'
class __declspec(dllexport) LevelInventory {
public:
	LevelInventory(Database *);
	LevelInventory(Database *,const std::string& );
	LevelInventory(Database *,Query *,int = 0 /* offset */);
	LevelInventory(Database&,long levelinventoryid);
	~LevelInventory();
	Database& GetDatabase() { return *database; }

	unsigned __int64 insert();
	void update();
	void save();
	void erase();
	std::string xml();
	std::string xml(const std::string& ,const std::string& );
	size_t num_cols();

	long GetLevelinventoryid() { return this -> levelinventoryid; }
	void SetLevelinventoryid(long x) { this -> levelinventoryid = x; }
	const char *GetItemname() { return this -> itemname.c_str(); }
	void SetItemname(const std::string&  x) { this -> itemname = x; }
	const char *GetProfilename() { return this -> profilename.c_str(); }
	void SetProfilename(const std::string&  x) { this -> profilename = x; }
	const char *GetOrientation() { return this -> orientation.c_str(); }
	void SetOrientation(const std::string&  x) { this -> orientation = x; }
	const char *GetPosition() { return this -> position.c_str(); }
	void SetPosition(const std::string&  x) { this -> position = x; }

	// table columns
private:
	long         levelinventoryid; // INTEGER
	std::string  itemname; // VARCHAR(50)
	std::string  profilename; // VARCHAR(50)
	std::string  orientation; // TEXT
	std::string  position; // TEXT
	//
	void clear();
	void spawn(const std::string& );
	void spawn(Query *,int = 0 /* offset */);
	void select(const std::string& );
	void update(long levelinventoryid);
	//
	Database *database;
	short new_object;
}; // End of class 'LevelInventory'

//  Class 'PhysicsStrategies'
class __declspec(dllexport) PhysicsStrategies {
public:
	PhysicsStrategies(Database *);
	PhysicsStrategies(Database *,const std::string& );
	PhysicsStrategies(Database *,Query *,int = 0 /* offset */);
	PhysicsStrategies(Database&,long physicsid);
	~PhysicsStrategies();
	Database& GetDatabase() { return *database; }

	unsigned __int64 insert();
	void update();
	void save();
	void erase();
	std::string xml();
	std::string xml(const std::string& ,const std::string& );
	size_t num_cols();

	long GetPhysicsid() { return this -> physicsid; }
	void SetPhysicsid(long x) { this -> physicsid = x; }
	const char *GetName() { return this -> name.c_str(); }
	void SetName(const std::string&  x) { this -> name = x; }
	long GetType() { return this -> type; }
	void SetType(long x) { this -> type = x; }

	// table columns
private:
	long         physicsid; // INTEGER
	std::string  name; // VARCHAR(50)
	long         type; // INTEGER
	//
	void clear();
	void spawn(const std::string& );
	void spawn(Query *,int = 0 /* offset */);
	void select(const std::string& );
	void update(long physicsid);
	//
	Database *database;
	short new_object;
}; // End of class 'PhysicsStrategies'

//  Class 'PlayerInventory'
class __declspec(dllexport) PlayerInventory {
public:
	PlayerInventory(Database *);
	PlayerInventory(Database *,const std::string& );
	PlayerInventory(Database *,Query *,int = 0 /* offset */);
	PlayerInventory(Database&,long playerinventoryid);
	~PlayerInventory();
	Database& GetDatabase() { return *database; }

	unsigned __int64 insert();
	void update();
	void save();
	void erase();
	std::string xml();
	std::string xml(const std::string& ,const std::string& );
	size_t num_cols();

	long GetPlayerinventoryid() { return this -> playerinventoryid; }
	void SetPlayerinventoryid(long x) { this -> playerinventoryid = x; }
	long GetPlayerid() { return this -> playerid; }
	void SetPlayerid(long x) { this -> playerid = x; }
	bool GetIscurrentitem() { return this -> iscurrentitem; }
	void SetIscurrentitem(bool x) { this -> iscurrentitem = x; }
	const char *GetProfilename() { return this -> profilename.c_str(); }
	void SetProfilename(const std::string&  x) { this -> profilename = x; }
	// 4 - foreign KEY(PlayerId)(PlayerId)
	// table columns
private:
	long         playerinventoryid; // INTEGER
	long         playerid; // INTEGER
	bool         iscurrentitem; // BOOL
	std::string  profilename; // TEXT
	// 4 - foreign KEY(PlayerId)(PlayerId)
	//
	void clear();
	void spawn(const std::string& );
	void spawn(Query *,int = 0 /* offset */);
	void select(const std::string& );
	void update(long playerinventoryid);
	//
	Database *database;
	short new_object;
}; // End of class 'PlayerInventory'

//  Class 'PlayerJobs'
class __declspec(dllexport) PlayerJobs {
public:
	PlayerJobs(Database *);
	PlayerJobs(Database *,const std::string& );
	PlayerJobs(Database *,Query *,int = 0 /* offset */);
	PlayerJobs(Database&,long jobtypeid);
	~PlayerJobs();
	Database& GetDatabase() { return *database; }

	unsigned __int64 insert();
	void update();
	void save();
	void erase();
	std::string xml();
	std::string xml(const std::string& ,const std::string& );
	size_t num_cols();

	long GetJobtypeid() { return this -> jobtypeid; }
	void SetJobtypeid(long x) { this -> jobtypeid = x; }
	long GetPlayerid() { return this -> playerid; }
	void SetPlayerid(long x) { this -> playerid = x; }
	// 2 - foreign KEY(JobTypeID)(JobTypeID)	// 3 - foreign KEY(PlayerId)(PlayerId)
	// table columns
private:
	long         jobtypeid; // INTEGER
	long         playerid; // INTEGER
	// 2 - foreign KEY(JobTypeID)(JobTypeID)
	// 3 - foreign KEY(PlayerId)(PlayerId)
	//
	void clear();
	void spawn(const std::string& );
	void spawn(Query *,int = 0 /* offset */);
	void select(const std::string& );
	void update(long jobtypeid);
	//
	Database *database;
	short new_object;
}; // End of class 'PlayerJobs'

//  Class 'PlayerPaths'
class __declspec(dllexport) PlayerPaths {
public:
	PlayerPaths(Database *);
	PlayerPaths(Database *,const std::string& );
	PlayerPaths(Database *,Query *,int = 0 /* offset */);
	~PlayerPaths();
	Database& GetDatabase() { return *database; }

	unsigned __int64 insert();
	void save();
	std::string xml();
	std::string xml(const std::string& ,const std::string& );
	size_t num_cols();

	long GetPathid() { return this -> pathid; }
	void SetPathid(long x) { this -> pathid = x; }
	long GetPlayerid() { return this -> playerid; }
	void SetPlayerid(long x) { this -> playerid = x; }
	// 2 - foreign KEY(PathId)(PathId)	// 3 - foreign KEY(PlayerId)(PlayerId)
	// table columns
private:
	long         pathid; // INTEGER
	long         playerid; // INTEGER
	// 2 - foreign KEY(PathId)(PathId)
	// 3 - foreign KEY(PlayerId)(PlayerId)
	//
	void clear();
	void spawn(const std::string& );
	void spawn(Query *,int = 0 /* offset */);
	void select(const std::string& );
	//
	Database *database;
	short new_object;
}; // End of class 'PlayerPaths'

//  Class 'Players'
class __declspec(dllexport) Players {
public:
	Players(Database *);
	Players(Database *,const std::string& );
	Players(Database *,Query *,int = 0 /* offset */);
	Players(Database&,long playerid);
	~Players();
	Database& GetDatabase() { return *database; }

	unsigned __int64 insert();
	void update();
	void save();
	void erase();
	std::string xml();
	std::string xml(const std::string& ,const std::string& );
	size_t num_cols();

	long GetPlayerid() { return this -> playerid; }
	void SetPlayerid(long x) { this -> playerid = x; }
	const char *GetName() { return this -> name.c_str(); }
	void SetName(const std::string&  x) { this -> name = x; }
	const char *GetPosition() { return this -> position.c_str(); }
	void SetPosition(const std::string&  x) { this -> position = x; }
	float GetCrawlspeed() { return this -> crawlspeed; }
	void SetCrawlspeed(float x) { this -> crawlspeed = x; }
	float GetSprintspeed() { return this -> sprintspeed; }
	void SetSprintspeed(float x) { this -> sprintspeed = x; }
	bool GetIshumanplayer() { return this -> ishumanplayer; }
	void SetIshumanplayer(bool x) { this -> ishumanplayer = x; }
	float GetViewrange() { return this -> viewrange; }
	void SetViewrange(float x) { this -> viewrange = x; }
	float GetDieingtime() { return this -> dieingtime; }
	void SetDieingtime(float x) { this -> dieingtime = x; }
	const char *GetMovabletext() { return this -> movabletext.c_str(); }
	void SetMovabletext(const std::string&  x) { this -> movabletext = x; }
	const char *GetCharacterstate() { return this -> characterstate.c_str(); }
	void SetCharacterstate(const std::string&  x) { this -> characterstate = x; }
	const char *GetDirection() { return this -> direction.c_str(); }
	void SetDirection(const std::string&  x) { this -> direction = x; }
	const char *GetPlayertype() { return this -> playertype.c_str(); }
	void SetPlayertype(const std::string&  x) { this -> playertype = x; }
	float GetHealth() { return this -> health; }
	void SetHealth(float x) { this -> health = x; }
	long GetTeam() { return this -> team; }
	void SetTeam(long x) { this -> team = x; }
	float GetRunspeed() { return this -> runspeed; }
	void SetRunspeed(float x) { this -> runspeed = x; }
	float GetReloadspeed() { return this -> reloadspeed; }
	void SetReloadspeed(float x) { this -> reloadspeed = x; }
	float GetRiflemarksman() { return this -> riflemarksman; }
	void SetRiflemarksman(float x) { this -> riflemarksman = x; }
	float GetPhysicalstrength() { return this -> physicalstrength; }
	void SetPhysicalstrength(float x) { this -> physicalstrength = x; }

	// table columns
private:
	long         playerid; // INTEGER
	std::string  name; // VARCHAR(50)
	std::string  position; // TEXT
	float        crawlspeed; // REAL
	float        sprintspeed; // REAL
	bool         ishumanplayer; // BOOL
	float        viewrange; // REAL
	float        dieingtime; // REAL
	std::string  movabletext; // TEXT
	std::string  characterstate; // VARCHAR(50)
	std::string  direction; // TEXT
	std::string  playertype; // TEXT
	float        health; // REAL
	long         team; // INTEGER
	float        runspeed; // REAL
	float        reloadspeed; // REAL
	float        riflemarksman; // REAL
	float        physicalstrength; // REAL
	//
	void clear();
	void spawn(const std::string& );
	void spawn(Query *,int = 0 /* offset */);
	void select(const std::string& );
	void update(long playerid);
	//
	Database *database;
	short new_object;
}; // End of class 'Players'

//  Class 'SpawnPoints'
class __declspec(dllexport) SpawnPoints {
public:
	SpawnPoints(Database *);
	SpawnPoints(Database *,const std::string& );
	SpawnPoints(Database *,Query *,int = 0 /* offset */);
	~SpawnPoints();
	Database& GetDatabase() { return *database; }

	unsigned __int64 insert();
	void save();
	std::string xml();
	std::string xml(const std::string& ,const std::string& );
	size_t num_cols();

	long GetId() { return this -> id; }
	void SetId(long x) { this -> id = x; }
	const char *GetPosition() { return this -> position.c_str(); }
	void SetPosition(const std::string&  x) { this -> position = x; }
	long GetTeam() { return this -> team; }
	void SetTeam(long x) { this -> team = x; }
	float GetCooldown() { return this -> cooldown; }
	void SetCooldown(float x) { this -> cooldown = x; }

	// table columns
private:
	long         id; // INTEGER
	std::string  position; // TEXT
	long         team; // INTEGER
	float        cooldown; // REAL
	//
	void clear();
	void spawn(const std::string& );
	void spawn(Query *,int = 0 /* offset */);
	void select(const std::string& );
	//
	Database *database;
	short new_object;
}; // End of class 'SpawnPoints'

//  Class 'StaticData'
class __declspec(dllexport) StaticData {
public:
	StaticData(Database *);
	StaticData(Database *,const std::string& );
	StaticData(Database *,Query *,int = 0 /* offset */);
	~StaticData();
	Database& GetDatabase() { return *database; }

	unsigned __int64 insert();
	void save();
	std::string xml();
	std::string xml(const std::string& ,const std::string& );
	size_t num_cols();

	const char *GetXmldata() { return this -> xmldata.c_str(); }
	void SetXmldata(const std::string&  x) { this -> xmldata = x; }

	// table columns
private:
	std::string  xmldata; // TEXT
	//
	void clear();
	void spawn(const std::string& );
	void spawn(Query *,int = 0 /* offset */);
	void select(const std::string& );
	//
	Database *database;
	short new_object;
}; // End of class 'StaticData'

} // end of DAL namespace
} // end of Core namespace
#pragma warning(pop)
#endif // _COREDAL_H
