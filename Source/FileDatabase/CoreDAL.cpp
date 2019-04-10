// Generated DAL code.
#include "CoreDal.h"

namespace Core {
namespace DAL {
// Begin class 'AStarNodes'
AStarNodes::AStarNodes(Database *db)
{
	database = db;
	new_object = 1;
	clear();
}

AStarNodes::AStarNodes(Database *db,const std::string& sql)
{
	database = db;
	new_object = 1;
	spawn(sql);
}

AStarNodes::AStarNodes(Database *db,Query *qd,int offset)
{
	database = db;
	new_object = 0;
	spawn(qd, offset);
}

AStarNodes::~AStarNodes()
{
}

void AStarNodes::select(const std::string& sql)
{
	spawn(sql);
}

unsigned __int64 AStarNodes::insert()
{
	Query q(*database);
	std::string sql;

	sql = "insert into AStarNodes(NodeId,Position,Cost,Neighbors)";
	{
		char slask[200];
		sprintf_s(slask, 200, " values(%ld",this -> nodeid);
		sql += slask;
	}
	sql += ", '" + q.GetDatabase().safestr(this -> position) + "'";
	{
		char slask[200];
		sprintf_s(slask, 200, ", %f",this -> cost);
		sql += slask;
	}
	sql += ", '" + q.GetDatabase().safestr(this -> neighbors) + "'";
	sql += ")";

	if(!q.execute(sql))
		return 0;

	new_object = 0;
	unsigned __int64 inserted_id = q.insert_id();
	nodeid = (long)inserted_id;
	return inserted_id;
}

void AStarNodes::save()
{
	if (new_object)
		insert();
}

std::string AStarNodes::xml()
{
	Query q(*database);
	std::string dest;
	char slask[200];
	dest = "<ASTARNODES>";
	sprintf_s(slask, 200, "<NODEID>%ld</NODEID>",this -> nodeid);
	dest += slask;
	dest += "<POSITION>" + q.GetDatabase().xmlsafestr(this -> position) + "</POSITION>";
	sprintf_s(slask, 200,"<COST>%f</COST>",this -> cost);
	dest += slask;
	dest += "<NEIGHBORS>" + q.GetDatabase().xmlsafestr(this -> neighbors) + "</NEIGHBORS>";
	dest += "</ASTARNODES>";
	return dest;
}

std::string AStarNodes::xml(const std::string& tag,const std::string& xvalx)
{
	Query q(*database);
	std::string dest;
	char slask[200];
	dest = "<ASTARNODES " + tag + "=\"" + xvalx + "\">";
	sprintf_s(slask, 200, "<NODEID>%ld</NODEID>",this -> nodeid);
	dest += slask;
	dest += "<POSITION>" + q.GetDatabase().xmlsafestr(this -> position) + "</POSITION>";
	sprintf_s(slask, 200,"<COST>%f</COST>",this -> cost);
	dest += slask;
	dest += "<NEIGHBORS>" + q.GetDatabase().xmlsafestr(this -> neighbors) + "</NEIGHBORS>";
	dest += "</ASTARNODES>";
	return dest;
}

size_t AStarNodes::num_cols()
{
	return 4;
}

void AStarNodes::clear()
{
	this -> nodeid = 0;
	this -> position = "";
	this -> cost = 0;
	this -> neighbors = "";
}

void AStarNodes::spawn(const std::string& sql)
{
	Query q(*database);
	std::string temp;

	clear();

	if (!strncasecmp(sql.c_str(),"select * ",9))
	{
		temp = "select NodeId,Position,Cost,Neighbors " + sql.substr(9);
	} else
		temp = sql;
	q.get_result(temp);
	if (q.fetch_row())
	{
		this -> nodeid = q.getval(0);			// 0 - nodeid INTEGER
		this -> position = q.getstr(1);			// 1 - position VARCHAR(50)
		this -> cost = (float)q.getnum(2);			// 2 - cost REAL
		this -> neighbors = q.getstr(3);			// 3 - neighbors VARCHAR(50)
		new_object = 0;
	} else
		clear();
	q.free_result();
}

void AStarNodes::spawn(Query *qd,int offset)
{
	clear();

	this -> nodeid = qd->getval(0 + offset);			// 0 - nodeid INTEGER
	this -> position = qd -> getstr(1 + offset);			// 1 - position VARCHAR(50)
	this -> cost = (float)qd->getnum(2 + offset);			// 2 - cost REAL
	this -> neighbors = qd -> getstr(3 + offset);			// 3 - neighbors VARCHAR(50)
}

// Begin class 'AiPaths'
AiPaths::AiPaths(Database *db)
{
	database = db;
	new_object = 1;
	clear();
}

AiPaths::AiPaths(Database *db,const std::string& sql)
{
	database = db;
	new_object = 1;
	spawn(sql);
}

AiPaths::AiPaths(Database *db,Query *qd,int offset)
{
	database = db;
	new_object = 0;
	spawn(qd, offset);
}

AiPaths::AiPaths(Database& db,long i_pathid):database(&db),new_object(1)
{
	Query q(*database);
	std::string sql = "select * from AiPaths where ";
	{
		char slask[100];
		sprintf_s(slask, 100, "PathId='%ld'",i_pathid);
		sql += slask;
	}
	spawn(sql);
}

AiPaths::~AiPaths()
{
}

void AiPaths::select(const std::string& sql)
{
	spawn(sql);
}

unsigned __int64 AiPaths::insert()
{
	Query q(*database);
	std::string sql;

	sql = "insert into AiPaths(Name,Vectors)";
	sql += " values('" + q.GetDatabase().safestr(this -> name) + "'";
	sql += ", '" + q.GetDatabase().safestr(this -> vectors) + "'";
	sql += ")";

	if(!q.execute(sql))
		return 0;

	new_object = 0;
	unsigned __int64 inserted_id = q.insert_id();
	pathid = (long)inserted_id;
	return inserted_id;
}

void AiPaths::update()
{
	update(this -> pathid);
}

void AiPaths::update(long i_pathid)
{
	Query q(*database);
	std::string sql;
	sql += "update AiPaths set Name='" + q.GetDatabase().safestr(this -> name) + "'";
	sql += ", Vectors='" + q.GetDatabase().safestr(this -> vectors) + "'";
	{
		char slask[200];
		sprintf_s(slask, 200, " where PathId='%ld'",i_pathid);
		sql += slask;
	}
	q.execute(sql);
}

void AiPaths::save()
{
	if (new_object)
		insert();
	else
		update();
}

void AiPaths::erase()
{
	if (!new_object)
	{
		std::string sql = "delete from AiPaths where";
		Query q(*database);
		{
			char slask[200];
			sprintf_s(slask, 200, " PathId='%ld'",this -> pathid);
			sql += slask;
		}
		q.execute(sql);
	}
}

std::string AiPaths::xml()
{
	Query q(*database);
	std::string dest;
	char slask[200];
	dest = "<AIPATHS>";
	sprintf_s(slask, 200, "<PATHID>%ld</PATHID>",this -> pathid);
	dest += slask;
	dest += "<NAME>" + q.GetDatabase().xmlsafestr(this -> name) + "</NAME>";
	dest += "<VECTORS>" + q.GetDatabase().xmlsafestr(this -> vectors) + "</VECTORS>";
	dest += "</AIPATHS>";
	return dest;
}

std::string AiPaths::xml(const std::string& tag,const std::string& xvalx)
{
	Query q(*database);
	std::string dest;
	char slask[200];
	dest = "<AIPATHS " + tag + "=\"" + xvalx + "\">";
	sprintf_s(slask, 200, "<PATHID>%ld</PATHID>",this -> pathid);
	dest += slask;
	dest += "<NAME>" + q.GetDatabase().xmlsafestr(this -> name) + "</NAME>";
	dest += "<VECTORS>" + q.GetDatabase().xmlsafestr(this -> vectors) + "</VECTORS>";
	dest += "</AIPATHS>";
	return dest;
}

size_t AiPaths::num_cols()
{
	return 3;
}

void AiPaths::clear()
{
	this -> pathid = 0;
	this -> name = "";
	this -> vectors = "";
}

void AiPaths::spawn(const std::string& sql)
{
	Query q(*database);
	std::string temp;

	clear();

	if (!strncasecmp(sql.c_str(),"select * ",9))
	{
		temp = "select PathId,Name,Vectors " + sql.substr(9);
	} else
		temp = sql;
	q.get_result(temp);
	if (q.fetch_row())
	{
		this -> pathid = q.getval(0);			// 0 - pathid INTEGER
		this -> name = q.getstr(1);			// 1 - name VARCHAR(50)
		this -> vectors = q.getstr(2);			// 2 - vectors TEXT
		new_object = 0;
	} else
		clear();
	q.free_result();
}

void AiPaths::spawn(Query *qd,int offset)
{
	clear();

	this -> pathid = qd->getval(0 + offset);			// 0 - pathid INTEGER
	this -> name = qd -> getstr(1 + offset);			// 1 - name VARCHAR(50)
	this -> vectors = qd->getstr(2 + offset);			// 2 - vectors TEXT
}

// Begin class 'Buildings'
Buildings::Buildings(Database *db)
{
	database = db;
	new_object = 1;
	clear();
}

Buildings::Buildings(Database *db,const std::string& sql)
{
	database = db;
	new_object = 1;
	spawn(sql);
}

Buildings::Buildings(Database *db,Query *qd,int offset)
{
	database = db;
	new_object = 0;
	spawn(qd, offset);
}

Buildings::Buildings(Database& db,long i_buildingid):database(&db),new_object(1)
{
	Query q(*database);
	std::string sql = "select * from Buildings where ";
	{
		char slask[100];
		sprintf_s(slask, 100, "BuildingID='%ld'",i_buildingid);
		sql += slask;
	}
	spawn(sql);
}

Buildings::~Buildings()
{
}

void Buildings::select(const std::string& sql)
{
	spawn(sql);
}

unsigned __int64 Buildings::insert()
{
	Query q(*database);
	std::string sql;

	sql = "insert into Buildings(BuildingCategory,Team,Health,BuildingState,Position,Name,BuildingType,DataValue)";
	{
		char slask[200];
		sprintf_s(slask, 200, " values(%ld",this -> buildingcategory);
		sql += slask;
	}
	{
		char slask[200];
		sprintf_s(slask, 200, ", %ld",this -> team);
		sql += slask;
	}
	{
		char slask[200];
		sprintf_s(slask, 200, ", %f",this -> health);
		sql += slask;
	}
	{
		char slask[200];
		sprintf_s(slask, 200, ", %ld",this -> buildingstate);
		sql += slask;
	}
	sql += ", '" + q.GetDatabase().safestr(this -> position) + "'";
	sql += ", '" + q.GetDatabase().safestr(this -> name) + "'";
	sql += ", '" + q.GetDatabase().safestr(this -> buildingtype) + "'";
	sql += ", '" + q.GetDatabase().safestr(this -> datavalue) + "'";
	sql += ")";

	if(!q.execute(sql))
		return 0;

	new_object = 0;
	unsigned __int64 inserted_id = q.insert_id();
	buildingid = (long)inserted_id;
	return inserted_id;
}

void Buildings::update()
{
	update(this -> buildingid);
}

void Buildings::update(long i_buildingid)
{
	Query q(*database);
	std::string sql;
	{
		char slask[200];
		sprintf_s(slask, 200, "update Buildings set BuildingCategory=%ld",this -> buildingcategory);
		sql += slask;
	}
	{
		char slask[200];
		sprintf_s(slask, 200, ", Team=%ld",this -> team);
		sql += slask;
	}
	{
		char slask[200];
		sprintf_s(slask, 200, ", Health='%f'",this -> health);
		sql += slask;
	}
	{
		char slask[200];
		sprintf_s(slask, 200, ", BuildingState=%ld",this -> buildingstate);
		sql += slask;
	}
	sql += ", Position='" + q.GetDatabase().safestr(this -> position) + "'";
	sql += ", Name='" + q.GetDatabase().safestr(this -> name) + "'";
	sql += ", BuildingType='" + q.GetDatabase().safestr(this -> buildingtype) + "'";
	sql += ", DataValue='" + q.GetDatabase().safestr(this -> datavalue) + "'";
	{
		char slask[200];
		sprintf_s(slask, 200, " where BuildingID='%ld'",i_buildingid);
		sql += slask;
	}
	q.execute(sql);
}

void Buildings::save()
{
	if (new_object)
		insert();
	else
		update();
}

void Buildings::erase()
{
	if (!new_object)
	{
		std::string sql = "delete from Buildings where";
		Query q(*database);
		{
			char slask[200];
			sprintf_s(slask, 200, " BuildingID='%ld'",this -> buildingid);
			sql += slask;
		}
		q.execute(sql);
	}
}

std::string Buildings::xml()
{
	Query q(*database);
	std::string dest;
	char slask[200];
	dest = "<BUILDINGS>";
	sprintf_s(slask, 200, "<BUILDINGID>%ld</BUILDINGID>",this -> buildingid);
	dest += slask;
	sprintf_s(slask, 200, "<BUILDINGCATEGORY>%ld</BUILDINGCATEGORY>",this -> buildingcategory);
	dest += slask;
	sprintf_s(slask, 200, "<TEAM>%ld</TEAM>",this -> team);
	dest += slask;
	sprintf_s(slask, 200,"<HEALTH>%f</HEALTH>",this -> health);
	dest += slask;
	sprintf_s(slask, 200, "<BUILDINGSTATE>%ld</BUILDINGSTATE>",this -> buildingstate);
	dest += slask;
	dest += "<POSITION>" + q.GetDatabase().xmlsafestr(this -> position) + "</POSITION>";
	dest += "<NAME>" + q.GetDatabase().xmlsafestr(this -> name) + "</NAME>";
	dest += "<BUILDINGTYPE>" + q.GetDatabase().xmlsafestr(this -> buildingtype) + "</BUILDINGTYPE>";
	dest += "<DATAVALUE>" + q.GetDatabase().xmlsafestr(this -> datavalue) + "</DATAVALUE>";
	dest += "</BUILDINGS>";
	return dest;
}

std::string Buildings::xml(const std::string& tag,const std::string& xvalx)
{
	Query q(*database);
	std::string dest;
	char slask[200];
	dest = "<BUILDINGS " + tag + "=\"" + xvalx + "\">";
	sprintf_s(slask, 200, "<BUILDINGID>%ld</BUILDINGID>",this -> buildingid);
	dest += slask;
	sprintf_s(slask, 200, "<BUILDINGCATEGORY>%ld</BUILDINGCATEGORY>",this -> buildingcategory);
	dest += slask;
	sprintf_s(slask, 200, "<TEAM>%ld</TEAM>",this -> team);
	dest += slask;
	sprintf_s(slask, 200,"<HEALTH>%f</HEALTH>",this -> health);
	dest += slask;
	sprintf_s(slask, 200, "<BUILDINGSTATE>%ld</BUILDINGSTATE>",this -> buildingstate);
	dest += slask;
	dest += "<POSITION>" + q.GetDatabase().xmlsafestr(this -> position) + "</POSITION>";
	dest += "<NAME>" + q.GetDatabase().xmlsafestr(this -> name) + "</NAME>";
	dest += "<BUILDINGTYPE>" + q.GetDatabase().xmlsafestr(this -> buildingtype) + "</BUILDINGTYPE>";
	dest += "<DATAVALUE>" + q.GetDatabase().xmlsafestr(this -> datavalue) + "</DATAVALUE>";
	dest += "</BUILDINGS>";
	return dest;
}

size_t Buildings::num_cols()
{
	return 9;
}

void Buildings::clear()
{
	this -> buildingid = 0;
	this -> buildingcategory = 0;
	this -> team = 0;
	this -> health = 0;
	this -> buildingstate = 0;
	this -> position = "";
	this -> name = "";
	this -> buildingtype = "";
	this -> datavalue = "";
}

void Buildings::spawn(const std::string& sql)
{
	Query q(*database);
	std::string temp;

	clear();

	if (!strncasecmp(sql.c_str(),"select * ",9))
	{
		temp = "select BuildingID,BuildingCategory,Team,Health,BuildingState,Position,Name,BuildingType,DataValue " + sql.substr(9);
	} else
		temp = sql;
	q.get_result(temp);
	if (q.fetch_row())
	{
		this -> buildingid = q.getval(0);			// 0 - buildingid INTEGER
		this -> buildingcategory = q.getval(1);			// 1 - buildingcategory INTEGER
		this -> team = q.getval(2);			// 2 - team INTEGER
		this -> health = (float)q.getnum(3);			// 3 - health REAL
		this -> buildingstate = q.getval(4);			// 4 - buildingstate INTEGER
		this -> position = q.getstr(5);			// 5 - position TEXT
		this -> name = q.getstr(6);			// 6 - name VARCHAR(50)
		this -> buildingtype = q.getstr(7);			// 7 - buildingtype VARCHAR(50)
		this -> datavalue = q.getstr(8);			// 8 - datavalue VARCHAR(50)
		new_object = 0;
	} else
		clear();
	q.free_result();
}

void Buildings::spawn(Query *qd,int offset)
{
	clear();

	this -> buildingid = qd->getval(0 + offset);			// 0 - buildingid INTEGER
	this -> buildingcategory = qd->getval(1 + offset);			// 1 - buildingcategory INTEGER
	this -> team = qd->getval(2 + offset);			// 2 - team INTEGER
	this -> health = (float)qd->getnum(3 + offset);			// 3 - health REAL
	this -> buildingstate = qd->getval(4 + offset);			// 4 - buildingstate INTEGER
	this -> position = qd->getstr(5 + offset);			// 5 - position TEXT
	this -> name = qd -> getstr(6 + offset);			// 6 - name VARCHAR(50)
	this -> buildingtype = qd -> getstr(7 + offset);			// 7 - buildingtype VARCHAR(50)
	this -> datavalue = qd -> getstr(8 + offset);			// 8 - datavalue VARCHAR(50)
}

// Begin class 'GameObjects'
GameObjects::GameObjects(Database *db)
{
	database = db;
	new_object = 1;
	clear();
}

GameObjects::GameObjects(Database *db,const std::string& sql)
{
	database = db;
	new_object = 1;
	spawn(sql);
}

GameObjects::GameObjects(Database *db,Query *qd,int offset)
{
	database = db;
	new_object = 0;
	spawn(qd, offset);
}

GameObjects::GameObjects(Database& db,long i_gameobjectsid):database(&db),new_object(1)
{
	Query q(*database);
	std::string sql = "select * from GameObjects where ";
	{
		char slask[100];
		sprintf_s(slask, 100, "GameObjectsID='%ld'",i_gameobjectsid);
		sql += slask;
	}
	spawn(sql);
}

GameObjects::~GameObjects()
{
}

void GameObjects::select(const std::string& sql)
{
	spawn(sql);
}

unsigned __int64 GameObjects::insert()
{
	Query q(*database);
	std::string sql;

	sql = "insert into GameObjects(Name,Type,MeshFile,PhysicsProfile,Scale,Shadows,Orientation,Position)";
	sql += " values('" + q.GetDatabase().safestr(this -> name) + "'";
	sql += ", '" + q.GetDatabase().safestr(this -> type) + "'";
	sql += ", '" + q.GetDatabase().safestr(this -> meshfile) + "'";
	sql += ", '" + q.GetDatabase().safestr(this -> physicsprofile) + "'";
	sql += ", '" + q.GetDatabase().safestr(this -> scale) + "'";
	sql += ", '" + (this -> shadows ? q.GetDatabase().safestr(this -> shadows ? "true" : "false") : "") + "'";
	sql += ", '" + q.GetDatabase().safestr(this -> orientation) + "'";
	sql += ", '" + q.GetDatabase().safestr(this -> position) + "'";
	sql += ")";

	if(!q.execute(sql))
		return 0;

	new_object = 0;
	unsigned __int64 inserted_id = q.insert_id();
	gameobjectsid = (long)inserted_id;
	return inserted_id;
}

void GameObjects::update()
{
	update(this -> gameobjectsid);
}

void GameObjects::update(long i_gameobjectsid)
{
	Query q(*database);
	std::string sql;
	sql += "update GameObjects set Name='" + q.GetDatabase().safestr(this -> name) + "'";
	sql += ", Type='" + q.GetDatabase().safestr(this -> type) + "'";
	sql += ", MeshFile='" + q.GetDatabase().safestr(this -> meshfile) + "'";
	sql += ", PhysicsProfile='" + q.GetDatabase().safestr(this -> physicsprofile) + "'";
	sql += ", Scale='" + q.GetDatabase().safestr(this -> scale) + "'";
	sql += ", Shadows='" + q.GetDatabase().safestr(this -> shadows  ? "true" : "false") + "'";
	sql += ", Orientation='" + q.GetDatabase().safestr(this -> orientation) + "'";
	sql += ", Position='" + q.GetDatabase().safestr(this -> position) + "'";
	{
		char slask[200];
		sprintf_s(slask, 200, " where GameObjectsID='%ld'",i_gameobjectsid);
		sql += slask;
	}
	q.execute(sql);
}

void GameObjects::save()
{
	if (new_object)
		insert();
	else
		update();
}

void GameObjects::erase()
{
	if (!new_object)
	{
		std::string sql = "delete from GameObjects where";
		Query q(*database);
		{
			char slask[200];
			sprintf_s(slask, 200, " GameObjectsID='%ld'",this -> gameobjectsid);
			sql += slask;
		}
		q.execute(sql);
	}
}

std::string GameObjects::xml()
{
	Query q(*database);
	std::string dest;
	char slask[200];
	dest = "<GAMEOBJECTS>";
	sprintf_s(slask, 200, "<GAMEOBJECTSID>%ld</GAMEOBJECTSID>",this -> gameobjectsid);
	dest += slask;
	dest += "<NAME>" + q.GetDatabase().xmlsafestr(this -> name) + "</NAME>";
	dest += "<TYPE>" + q.GetDatabase().xmlsafestr(this -> type) + "</TYPE>";
	dest += "<MESHFILE>" + q.GetDatabase().xmlsafestr(this -> meshfile) + "</MESHFILE>";
	dest += "<PHYSICSPROFILE>" + q.GetDatabase().xmlsafestr(this -> physicsprofile) + "</PHYSICSPROFILE>";
	dest += "<SCALE>" + q.GetDatabase().xmlsafestr(this -> scale) + "</SCALE>";
	dest += "<SHADOWS>" + q.GetDatabase().xmlsafestr(this -> shadows ? "true" : "false") + "</SHADOWS>";
	dest += "<ORIENTATION>" + q.GetDatabase().xmlsafestr(this -> orientation) + "</ORIENTATION>";
	dest += "<POSITION>" + q.GetDatabase().xmlsafestr(this -> position) + "</POSITION>";
	dest += "</GAMEOBJECTS>";
	return dest;
}

std::string GameObjects::xml(const std::string& tag,const std::string& xvalx)
{
	Query q(*database);
	std::string dest;
	char slask[200];
	dest = "<GAMEOBJECTS " + tag + "=\"" + xvalx + "\">";
	sprintf_s(slask, 200, "<GAMEOBJECTSID>%ld</GAMEOBJECTSID>",this -> gameobjectsid);
	dest += slask;
	dest += "<NAME>" + q.GetDatabase().xmlsafestr(this -> name) + "</NAME>";
	dest += "<TYPE>" + q.GetDatabase().xmlsafestr(this -> type) + "</TYPE>";
	dest += "<MESHFILE>" + q.GetDatabase().xmlsafestr(this -> meshfile) + "</MESHFILE>";
	dest += "<PHYSICSPROFILE>" + q.GetDatabase().xmlsafestr(this -> physicsprofile) + "</PHYSICSPROFILE>";
	dest += "<SCALE>" + q.GetDatabase().xmlsafestr(this -> scale) + "</SCALE>";
	dest += "<SHADOWS>" + q.GetDatabase().xmlsafestr(this -> shadows ? "true" : "false") + "</SHADOWS>";
	dest += "<ORIENTATION>" + q.GetDatabase().xmlsafestr(this -> orientation) + "</ORIENTATION>";
	dest += "<POSITION>" + q.GetDatabase().xmlsafestr(this -> position) + "</POSITION>";
	dest += "</GAMEOBJECTS>";
	return dest;
}

size_t GameObjects::num_cols()
{
	return 9;
}

void GameObjects::clear()
{
	this -> gameobjectsid = 0;
	this -> name = "";
	this -> type = "";
	this -> meshfile = "";
	this -> physicsprofile = "";
	this -> scale = "";
	this -> shadows = "";
	this -> orientation = "";
	this -> position = "";
}

void GameObjects::spawn(const std::string& sql)
{
	Query q(*database);
	std::string temp;

	clear();

	if (!strncasecmp(sql.c_str(),"select * ",9))
	{
		temp = "select GameObjectsID,Name,Type,MeshFile,PhysicsProfile,Scale,Shadows,Orientation,Position " + sql.substr(9);
	} else
		temp = sql;
	q.get_result(temp);
	if (q.fetch_row())
	{
		this -> gameobjectsid = q.getval(0);			// 0 - gameobjectsid INTEGER
		this -> name = q.getstr(1);			// 1 - name VARCHAR(50)
		this -> type = q.getstr(2);			// 2 - type VARCHAR(50)
		this -> meshfile = q.getstr(3);			// 3 - meshfile VARCHAR(50)
		this -> physicsprofile = q.getstr(4);			// 4 - physicsprofile VARCHAR(50)
		this -> scale = q.getstr(5);			// 5 - scale TEXT
		this -> shadows = q.getnum(6) > 0;			// 6 - shadows BOOL
		this -> orientation = q.getstr(7);			// 7 - orientation TEXT
		this -> position = q.getstr(8);			// 8 - position TEXT
		new_object = 0;
	} else
		clear();
	q.free_result();
}

void GameObjects::spawn(Query *qd,int offset)
{
	clear();

	this -> gameobjectsid = qd->getval(0 + offset);			// 0 - gameobjectsid INTEGER
	this -> name = qd -> getstr(1 + offset);			// 1 - name VARCHAR(50)
	this -> type = qd -> getstr(2 + offset);			// 2 - type VARCHAR(50)
	this -> meshfile = qd -> getstr(3 + offset);			// 3 - meshfile VARCHAR(50)
	this -> physicsprofile = qd -> getstr(4 + offset);			// 4 - physicsprofile VARCHAR(50)
	this -> scale = qd->getstr(5 + offset);			// 5 - scale TEXT
	this -> shadows = qd->getnum(6 + offset) > 0;			// 6 - shadows BOOL
	this -> orientation = qd->getstr(7 + offset);			// 7 - orientation TEXT
	this -> position = qd->getstr(8 + offset);			// 8 - position TEXT
}

// Begin class 'JobTypes'
JobTypes::JobTypes(Database *db)
{
	database = db;
	new_object = 1;
	clear();
}

JobTypes::JobTypes(Database *db,const std::string& sql)
{
	database = db;
	new_object = 1;
	spawn(sql);
}

JobTypes::JobTypes(Database *db,Query *qd,int offset)
{
	database = db;
	new_object = 0;
	spawn(qd, offset);
}

JobTypes::JobTypes(Database& db,long i_jobtypeid):database(&db),new_object(1)
{
	Query q(*database);
	std::string sql = "select * from JobTypes where ";
	{
		char slask[100];
		sprintf_s(slask, 100, "JobTypeID='%ld'",i_jobtypeid);
		sql += slask;
	}
	spawn(sql);
}

JobTypes::~JobTypes()
{
}

void JobTypes::select(const std::string& sql)
{
	spawn(sql);
}

unsigned __int64 JobTypes::insert()
{
	Query q(*database);
	std::string sql;

	sql = "insert into JobTypes(Name,Description)";
	sql += " values('" + q.GetDatabase().safestr(this -> name) + "'";
	sql += ", '" + q.GetDatabase().safestr(this -> description) + "'";
	sql += ")";

	if(!q.execute(sql))
		return 0;

	new_object = 0;
	unsigned __int64 inserted_id = q.insert_id();
	jobtypeid = (long)inserted_id;
	return inserted_id;
}

void JobTypes::update()
{
	update(this -> jobtypeid);
}

void JobTypes::update(long i_jobtypeid)
{
	Query q(*database);
	std::string sql;
	sql += "update JobTypes set Name='" + q.GetDatabase().safestr(this -> name) + "'";
	sql += ", Description='" + q.GetDatabase().safestr(this -> description) + "'";
	{
		char slask[200];
		sprintf_s(slask, 200, " where JobTypeID='%ld'",i_jobtypeid);
		sql += slask;
	}
	q.execute(sql);
}

void JobTypes::save()
{
	if (new_object)
		insert();
	else
		update();
}

void JobTypes::erase()
{
	if (!new_object)
	{
		std::string sql = "delete from JobTypes where";
		Query q(*database);
		{
			char slask[200];
			sprintf_s(slask, 200, " JobTypeID='%ld'",this -> jobtypeid);
			sql += slask;
		}
		q.execute(sql);
	}
}

std::string JobTypes::xml()
{
	Query q(*database);
	std::string dest;
	char slask[200];
	dest = "<JOBTYPES>";
	sprintf_s(slask, 200, "<JOBTYPEID>%ld</JOBTYPEID>",this -> jobtypeid);
	dest += slask;
	dest += "<NAME>" + q.GetDatabase().xmlsafestr(this -> name) + "</NAME>";
	dest += "<DESCRIPTION>" + q.GetDatabase().xmlsafestr(this -> description) + "</DESCRIPTION>";
	dest += "</JOBTYPES>";
	return dest;
}

std::string JobTypes::xml(const std::string& tag,const std::string& xvalx)
{
	Query q(*database);
	std::string dest;
	char slask[200];
	dest = "<JOBTYPES " + tag + "=\"" + xvalx + "\">";
	sprintf_s(slask, 200, "<JOBTYPEID>%ld</JOBTYPEID>",this -> jobtypeid);
	dest += slask;
	dest += "<NAME>" + q.GetDatabase().xmlsafestr(this -> name) + "</NAME>";
	dest += "<DESCRIPTION>" + q.GetDatabase().xmlsafestr(this -> description) + "</DESCRIPTION>";
	dest += "</JOBTYPES>";
	return dest;
}

size_t JobTypes::num_cols()
{
	return 3;
}

void JobTypes::clear()
{
	this -> jobtypeid = 0;
	this -> name = "";
	this -> description = "";
}

void JobTypes::spawn(const std::string& sql)
{
	Query q(*database);
	std::string temp;

	clear();

	if (!strncasecmp(sql.c_str(),"select * ",9))
	{
		temp = "select JobTypeID,Name,Description " + sql.substr(9);
	} else
		temp = sql;
	q.get_result(temp);
	if (q.fetch_row())
	{
		this -> jobtypeid = q.getval(0);			// 0 - jobtypeid INTEGER
		this -> name = q.getstr(1);			// 1 - name VARCHAR(50)
		this -> description = q.getstr(2);			// 2 - description TEXT
		new_object = 0;
	} else
		clear();
	q.free_result();
}

void JobTypes::spawn(Query *qd,int offset)
{
	clear();

	this -> jobtypeid = qd->getval(0 + offset);			// 0 - jobtypeid INTEGER
	this -> name = qd -> getstr(1 + offset);			// 1 - name VARCHAR(50)
	this -> description = qd->getstr(2 + offset);			// 2 - description TEXT
}

// Begin class 'LevelInventory'
LevelInventory::LevelInventory(Database *db)
{
	database = db;
	new_object = 1;
	clear();
}

LevelInventory::LevelInventory(Database *db,const std::string& sql)
{
	database = db;
	new_object = 1;
	spawn(sql);
}

LevelInventory::LevelInventory(Database *db,Query *qd,int offset)
{
	database = db;
	new_object = 0;
	spawn(qd, offset);
}

LevelInventory::LevelInventory(Database& db,long i_levelinventoryid):database(&db),new_object(1)
{
	Query q(*database);
	std::string sql = "select * from LevelInventory where ";
	{
		char slask[100];
		sprintf_s(slask, 100, "LevelInventoryID='%ld'",i_levelinventoryid);
		sql += slask;
	}
	spawn(sql);
}

LevelInventory::~LevelInventory()
{
}

void LevelInventory::select(const std::string& sql)
{
	spawn(sql);
}

unsigned __int64 LevelInventory::insert()
{
	Query q(*database);
	std::string sql;

	sql = "insert into LevelInventory(ItemName,ProfileName,Orientation,Position)";
	sql += " values('" + q.GetDatabase().safestr(this -> itemname) + "'";
	sql += ", '" + q.GetDatabase().safestr(this -> profilename) + "'";
	sql += ", '" + q.GetDatabase().safestr(this -> orientation) + "'";
	sql += ", '" + q.GetDatabase().safestr(this -> position) + "'";
	sql += ")";

	if(!q.execute(sql))
		return 0;

	new_object = 0;
	unsigned __int64 inserted_id = q.insert_id();
	levelinventoryid = (long)inserted_id;
	return inserted_id;
}

void LevelInventory::update()
{
	update(this -> levelinventoryid);
}

void LevelInventory::update(long i_levelinventoryid)
{
	Query q(*database);
	std::string sql;
	sql += "update LevelInventory set ItemName='" + q.GetDatabase().safestr(this -> itemname) + "'";
	sql += ", ProfileName='" + q.GetDatabase().safestr(this -> profilename) + "'";
	sql += ", Orientation='" + q.GetDatabase().safestr(this -> orientation) + "'";
	sql += ", Position='" + q.GetDatabase().safestr(this -> position) + "'";
	{
		char slask[200];
		sprintf_s(slask, 200, " where LevelInventoryID='%ld'",i_levelinventoryid);
		sql += slask;
	}
	q.execute(sql);
}

void LevelInventory::save()
{
	if (new_object)
		insert();
	else
		update();
}

void LevelInventory::erase()
{
	if (!new_object)
	{
		std::string sql = "delete from LevelInventory where";
		Query q(*database);
		{
			char slask[200];
			sprintf_s(slask, 200, " LevelInventoryID='%ld'",this -> levelinventoryid);
			sql += slask;
		}
		q.execute(sql);
	}
}

std::string LevelInventory::xml()
{
	Query q(*database);
	std::string dest;
	char slask[200];
	dest = "<LEVELINVENTORY>";
	sprintf_s(slask, 200, "<LEVELINVENTORYID>%ld</LEVELINVENTORYID>",this -> levelinventoryid);
	dest += slask;
	dest += "<ITEMNAME>" + q.GetDatabase().xmlsafestr(this -> itemname) + "</ITEMNAME>";
	dest += "<PROFILENAME>" + q.GetDatabase().xmlsafestr(this -> profilename) + "</PROFILENAME>";
	dest += "<ORIENTATION>" + q.GetDatabase().xmlsafestr(this -> orientation) + "</ORIENTATION>";
	dest += "<POSITION>" + q.GetDatabase().xmlsafestr(this -> position) + "</POSITION>";
	dest += "</LEVELINVENTORY>";
	return dest;
}

std::string LevelInventory::xml(const std::string& tag,const std::string& xvalx)
{
	Query q(*database);
	std::string dest;
	char slask[200];
	dest = "<LEVELINVENTORY " + tag + "=\"" + xvalx + "\">";
	sprintf_s(slask, 200, "<LEVELINVENTORYID>%ld</LEVELINVENTORYID>",this -> levelinventoryid);
	dest += slask;
	dest += "<ITEMNAME>" + q.GetDatabase().xmlsafestr(this -> itemname) + "</ITEMNAME>";
	dest += "<PROFILENAME>" + q.GetDatabase().xmlsafestr(this -> profilename) + "</PROFILENAME>";
	dest += "<ORIENTATION>" + q.GetDatabase().xmlsafestr(this -> orientation) + "</ORIENTATION>";
	dest += "<POSITION>" + q.GetDatabase().xmlsafestr(this -> position) + "</POSITION>";
	dest += "</LEVELINVENTORY>";
	return dest;
}

size_t LevelInventory::num_cols()
{
	return 5;
}

void LevelInventory::clear()
{
	this -> levelinventoryid = 0;
	this -> itemname = "";
	this -> profilename = "";
	this -> orientation = "";
	this -> position = "";
}

void LevelInventory::spawn(const std::string& sql)
{
	Query q(*database);
	std::string temp;

	clear();

	if (!strncasecmp(sql.c_str(),"select * ",9))
	{
		temp = "select LevelInventoryID,ItemName,ProfileName,Orientation,Position " + sql.substr(9);
	} else
		temp = sql;
	q.get_result(temp);
	if (q.fetch_row())
	{
		this -> levelinventoryid = q.getval(0);			// 0 - levelinventoryid INTEGER
		this -> itemname = q.getstr(1);			// 1 - itemname VARCHAR(50)
		this -> profilename = q.getstr(2);			// 2 - profilename VARCHAR(50)
		this -> orientation = q.getstr(3);			// 3 - orientation TEXT
		this -> position = q.getstr(4);			// 4 - position TEXT
		new_object = 0;
	} else
		clear();
	q.free_result();
}

void LevelInventory::spawn(Query *qd,int offset)
{
	clear();

	this -> levelinventoryid = qd->getval(0 + offset);			// 0 - levelinventoryid INTEGER
	this -> itemname = qd -> getstr(1 + offset);			// 1 - itemname VARCHAR(50)
	this -> profilename = qd -> getstr(2 + offset);			// 2 - profilename VARCHAR(50)
	this -> orientation = qd->getstr(3 + offset);			// 3 - orientation TEXT
	this -> position = qd->getstr(4 + offset);			// 4 - position TEXT
}

// Begin class 'PhysicsStrategies'
PhysicsStrategies::PhysicsStrategies(Database *db)
{
	database = db;
	new_object = 1;
	clear();
}

PhysicsStrategies::PhysicsStrategies(Database *db,const std::string& sql)
{
	database = db;
	new_object = 1;
	spawn(sql);
}

PhysicsStrategies::PhysicsStrategies(Database *db,Query *qd,int offset)
{
	database = db;
	new_object = 0;
	spawn(qd, offset);
}

PhysicsStrategies::PhysicsStrategies(Database& db,long i_physicsid):database(&db),new_object(1)
{
	Query q(*database);
	std::string sql = "select * from PhysicsStrategies where ";
	{
		char slask[100];
		sprintf_s(slask, 100, "PhysicsID='%ld'",i_physicsid);
		sql += slask;
	}
	spawn(sql);
}

PhysicsStrategies::~PhysicsStrategies()
{
}

void PhysicsStrategies::select(const std::string& sql)
{
	spawn(sql);
}

unsigned __int64 PhysicsStrategies::insert()
{
	Query q(*database);
	std::string sql;

	sql = "insert into PhysicsStrategies(Name,Type)";
	sql += " values('" + q.GetDatabase().safestr(this -> name) + "'";
	{
		char slask[200];
		sprintf_s(slask, 200, ", %ld",this -> type);
		sql += slask;
	}
	sql += ")";

	if(!q.execute(sql))
		return 0;

	new_object = 0;
	unsigned __int64 inserted_id = q.insert_id();
	physicsid = (long)inserted_id;
	return inserted_id;
}

void PhysicsStrategies::update()
{
	update(this -> physicsid);
}

void PhysicsStrategies::update(long i_physicsid)
{
	Query q(*database);
	std::string sql;
	{
		char slask[200];
		sprintf_s(slask, 200, "update PhysicsStrategies set PhysicsID=%ld",this -> physicsid);
		sql += slask;
	}
	sql += ", Name='" + q.GetDatabase().safestr(this -> name) + "'";
	{
		char slask[200];
		sprintf_s(slask, 200, ", Type=%ld",this -> type);
		sql += slask;
	}
	{
		char slask[200];
		sprintf_s(slask, 200, " where PhysicsID='%ld'",i_physicsid);
		sql += slask;
	}
	q.execute(sql);
}

void PhysicsStrategies::save()
{
	if (new_object)
		insert();
	else
		update();
}

void PhysicsStrategies::erase()
{
	if (!new_object)
	{
		std::string sql = "delete from PhysicsStrategies where";
		Query q(*database);
		{
			char slask[200];
			sprintf_s(slask, 200, " PhysicsID='%ld'",this -> physicsid);
			sql += slask;
		}
		q.execute(sql);
	}
}

std::string PhysicsStrategies::xml()
{
	Query q(*database);
	std::string dest;
	char slask[200];
	dest = "<PHYSICSSTRATEGIES>";
	sprintf_s(slask, 200, "<PHYSICSID>%ld</PHYSICSID>",this -> physicsid);
	dest += slask;
	dest += "<NAME>" + q.GetDatabase().xmlsafestr(this -> name) + "</NAME>";
	sprintf_s(slask, 200, "<TYPE>%ld</TYPE>",this -> type);
	dest += slask;
	dest += "</PHYSICSSTRATEGIES>";
	return dest;
}

std::string PhysicsStrategies::xml(const std::string& tag,const std::string& xvalx)
{
	Query q(*database);
	std::string dest;
	char slask[200];
	dest = "<PHYSICSSTRATEGIES " + tag + "=\"" + xvalx + "\">";
	sprintf_s(slask, 200, "<PHYSICSID>%ld</PHYSICSID>",this -> physicsid);
	dest += slask;
	dest += "<NAME>" + q.GetDatabase().xmlsafestr(this -> name) + "</NAME>";
	sprintf_s(slask, 200, "<TYPE>%ld</TYPE>",this -> type);
	dest += slask;
	dest += "</PHYSICSSTRATEGIES>";
	return dest;
}

size_t PhysicsStrategies::num_cols()
{
	return 3;
}

void PhysicsStrategies::clear()
{
	this -> physicsid = 0;
	this -> name = "";
	this -> type = 0;
}

void PhysicsStrategies::spawn(const std::string& sql)
{
	Query q(*database);
	std::string temp;

	clear();

	if (!strncasecmp(sql.c_str(),"select * ",9))
	{
		temp = "select PhysicsID,Name,Type " + sql.substr(9);
	} else
		temp = sql;
	q.get_result(temp);
	if (q.fetch_row())
	{
		this -> physicsid = q.getval(0);			// 0 - physicsid INTEGER
		this -> name = q.getstr(1);			// 1 - name VARCHAR(50)
		this -> type = q.getval(2);			// 2 - type INTEGER
		new_object = 0;
	} else
		clear();
	q.free_result();
}

void PhysicsStrategies::spawn(Query *qd,int offset)
{
	clear();

	this -> physicsid = qd->getval(0 + offset);			// 0 - physicsid INTEGER
	this -> name = qd -> getstr(1 + offset);			// 1 - name VARCHAR(50)
	this -> type = qd->getval(2 + offset);			// 2 - type INTEGER
}

// Begin class 'PlayerInventory'
PlayerInventory::PlayerInventory(Database *db)
{
	database = db;
	new_object = 1;
	clear();
}

PlayerInventory::PlayerInventory(Database *db,const std::string& sql)
{
	database = db;
	new_object = 1;
	spawn(sql);
}

PlayerInventory::PlayerInventory(Database *db,Query *qd,int offset)
{
	database = db;
	new_object = 0;
	spawn(qd, offset);
}

PlayerInventory::PlayerInventory(Database& db,long i_playerinventoryid):database(&db),new_object(1)
{
	Query q(*database);
	std::string sql = "select * from PlayerInventory where ";
	{
		char slask[100];
		sprintf_s(slask, 100, "PlayerInventoryID='%ld'",i_playerinventoryid);
		sql += slask;
	}
	spawn(sql);
}

PlayerInventory::~PlayerInventory()
{
}

void PlayerInventory::select(const std::string& sql)
{
	spawn(sql);
}

unsigned __int64 PlayerInventory::insert()
{
	Query q(*database);
	std::string sql;

	sql = "insert into PlayerInventory(PlayerID,IsCurrentItem,ProfileName)";
	{
		char slask[200];
		sprintf_s(slask, 200, " values(%ld",this -> playerid);
		sql += slask;
	}
	sql += ", '" + (this -> iscurrentitem ? q.GetDatabase().safestr(this -> iscurrentitem ? "true" : "false") : "") + "'";
	sql += ", '" + q.GetDatabase().safestr(this -> profilename) + "'";
	sql += ")";

	if(!q.execute(sql))
		return 0;

	new_object = 0;
	unsigned __int64 inserted_id = q.insert_id();
	playerinventoryid = (long)inserted_id;
	return inserted_id;
}

void PlayerInventory::update()
{
	update(this -> playerinventoryid);
}

void PlayerInventory::update(long i_playerinventoryid)
{
	Query q(*database);
	std::string sql;
	{
		char slask[200];
		sprintf_s(slask, 200, "update PlayerInventory set PlayerID=%ld",this -> playerid);
		sql += slask;
	}
	sql += ", IsCurrentItem='" + q.GetDatabase().safestr(this -> iscurrentitem  ? "true" : "false") + "'";
	sql += ", ProfileName='" + q.GetDatabase().safestr(this -> profilename) + "'";
	{
		char slask[200];
		sprintf_s(slask, 200, " where PlayerInventoryID='%ld'",i_playerinventoryid);
		sql += slask;
	}
	q.execute(sql);
}

void PlayerInventory::save()
{
	if (new_object)
		insert();
	else
		update();
}

void PlayerInventory::erase()
{
	if (!new_object)
	{
		std::string sql = "delete from PlayerInventory where";
		Query q(*database);
		{
			char slask[200];
			sprintf_s(slask, 200, " PlayerInventoryID='%ld'",this -> playerinventoryid);
			sql += slask;
		}
		q.execute(sql);
	}
}

std::string PlayerInventory::xml()
{
	Query q(*database);
	std::string dest;
	char slask[200];
	dest = "<PLAYERINVENTORY>";
	sprintf_s(slask, 200, "<PLAYERINVENTORYID>%ld</PLAYERINVENTORYID>",this -> playerinventoryid);
	dest += slask;
	sprintf_s(slask, 200, "<PLAYERID>%ld</PLAYERID>",this -> playerid);
	dest += slask;
	dest += "<ISCURRENTITEM>" + q.GetDatabase().xmlsafestr(this -> iscurrentitem ? "true" : "false") + "</ISCURRENTITEM>";
	dest += "<PROFILENAME>" + q.GetDatabase().xmlsafestr(this -> profilename) + "</PROFILENAME>";
	dest += "</PLAYERINVENTORY>";
	return dest;
}

std::string PlayerInventory::xml(const std::string& tag,const std::string& xvalx)
{
	Query q(*database);
	std::string dest;
	char slask[200];
	dest = "<PLAYERINVENTORY " + tag + "=\"" + xvalx + "\">";
	sprintf_s(slask, 200, "<PLAYERINVENTORYID>%ld</PLAYERINVENTORYID>",this -> playerinventoryid);
	dest += slask;
	sprintf_s(slask, 200, "<PLAYERID>%ld</PLAYERID>",this -> playerid);
	dest += slask;
	dest += "<ISCURRENTITEM>" + q.GetDatabase().xmlsafestr(this -> iscurrentitem ? "true" : "false") + "</ISCURRENTITEM>";
	dest += "<PROFILENAME>" + q.GetDatabase().xmlsafestr(this -> profilename) + "</PROFILENAME>";
	dest += "</PLAYERINVENTORY>";
	return dest;
}

size_t PlayerInventory::num_cols()
{
	return 5;
}

void PlayerInventory::clear()
{
	this -> playerinventoryid = 0;
	this -> playerid = 0;
	this -> iscurrentitem = "";
	this -> profilename = "";
	// 4 - foreign KEY(PlayerId)(PlayerId)
}

void PlayerInventory::spawn(const std::string& sql)
{
	Query q(*database);
	std::string temp;

	clear();

	if (!strncasecmp(sql.c_str(),"select * ",9))
	{
		temp = "select PlayerInventoryID,PlayerID,IsCurrentItem,ProfileName,FOREIGN " + sql.substr(9);
	} else
		temp = sql;
	q.get_result(temp);
	if (q.fetch_row())
	{
		this -> playerinventoryid = q.getval(0);			// 0 - playerinventoryid INTEGER
		this -> playerid = q.getval(1);			// 1 - playerid INTEGER
		this -> iscurrentitem = q.getnum(2) > 0;			// 2 - iscurrentitem BOOL
		this -> profilename = q.getstr(3);			// 3 - profilename TEXT
		// 4 - foreign KEY(PlayerId)(PlayerId)
		new_object = 0;
	} else
		clear();
	q.free_result();
}

void PlayerInventory::spawn(Query *qd,int offset)
{
	clear();

	this -> playerinventoryid = qd->getval(0 + offset);			// 0 - playerinventoryid INTEGER
	this -> playerid = qd->getval(1 + offset);			// 1 - playerid INTEGER
	this -> iscurrentitem = qd->getnum(2 + offset) > 0;			// 2 - iscurrentitem BOOL
	this -> profilename = qd->getstr(3 + offset);			// 3 - profilename TEXT
	// 4 - foreign KEY(PlayerId)(PlayerId)
}

// Begin class 'PlayerJobs'
PlayerJobs::PlayerJobs(Database *db)
{
	database = db;
	new_object = 1;
	clear();
}

PlayerJobs::PlayerJobs(Database *db,const std::string& sql)
{
	database = db;
	new_object = 1;
	spawn(sql);
}

PlayerJobs::PlayerJobs(Database *db,Query *qd,int offset)
{
	database = db;
	new_object = 0;
	spawn(qd, offset);
}

PlayerJobs::PlayerJobs(Database& db,long i_jobtypeid):database(&db),new_object(1)
{
	Query q(*database);
	std::string sql = "select * from PlayerJobs where ";
	{
		char slask[100];
		sprintf_s(slask, 100, "JobTypeID='%ld'",i_jobtypeid);
		sql += slask;
	}
	spawn(sql);
}

PlayerJobs::~PlayerJobs()
{
}

void PlayerJobs::select(const std::string& sql)
{
	spawn(sql);
}

unsigned __int64 PlayerJobs::insert()
{
	Query q(*database);
	std::string sql;

	sql = "insert into PlayerJobs(PlayerId)";
	{
		char slask[200];
		sprintf_s(slask, 200, " values(%ld",this -> playerid);
		sql += slask;
	}
	sql += ")";

	if(!q.execute(sql))
		return 0;

	new_object = 0;
	unsigned __int64 inserted_id = q.insert_id();
	jobtypeid = (long)inserted_id;
	return inserted_id;
}

void PlayerJobs::update()
{
	update(this -> jobtypeid);
}

void PlayerJobs::update(long i_jobtypeid)
{
	Query q(*database);
	std::string sql;
	{
		char slask[200];
		sprintf_s(slask, 200, "update PlayerJobs set JobTypeID=%ld",this -> jobtypeid);
		sql += slask;
	}
	{
		char slask[200];
		sprintf_s(slask, 200, ", PlayerId=%ld",this -> playerid);
		sql += slask;
	}
	{
		char slask[200];
		sprintf_s(slask, 200, " where JobTypeID='%ld'",i_jobtypeid);
		sql += slask;
	}
	q.execute(sql);
}

void PlayerJobs::save()
{
	if (new_object)
		insert();
	else
		update();
}

void PlayerJobs::erase()
{
	if (!new_object)
	{
		std::string sql = "delete from PlayerJobs where";
		Query q(*database);
		{
			char slask[200];
			sprintf_s(slask, 200, " JobTypeID='%ld'",this -> jobtypeid);
			sql += slask;
		}
		q.execute(sql);
	}
}

std::string PlayerJobs::xml()
{
	Query q(*database);
	std::string dest;
	char slask[200];
	dest = "<PLAYERJOBS>";
	sprintf_s(slask, 200, "<JOBTYPEID>%ld</JOBTYPEID>",this -> jobtypeid);
	dest += slask;
	sprintf_s(slask, 200, "<PLAYERID>%ld</PLAYERID>",this -> playerid);
	dest += slask;
	dest += "</PLAYERJOBS>";
	return dest;
}

std::string PlayerJobs::xml(const std::string& tag,const std::string& xvalx)
{
	Query q(*database);
	std::string dest;
	char slask[200];
	dest = "<PLAYERJOBS " + tag + "=\"" + xvalx + "\">";
	sprintf_s(slask, 200, "<JOBTYPEID>%ld</JOBTYPEID>",this -> jobtypeid);
	dest += slask;
	sprintf_s(slask, 200, "<PLAYERID>%ld</PLAYERID>",this -> playerid);
	dest += slask;
	dest += "</PLAYERJOBS>";
	return dest;
}

size_t PlayerJobs::num_cols()
{
	return 4;
}

void PlayerJobs::clear()
{
	this -> jobtypeid = 0;
	this -> playerid = 0;
	// 2 - foreign KEY(JobTypeID)(JobTypeID)
	// 3 - foreign KEY(PlayerId)(PlayerId)
}

void PlayerJobs::spawn(const std::string& sql)
{
	Query q(*database);
	std::string temp;

	clear();

	if (!strncasecmp(sql.c_str(),"select * ",9))
	{
		temp = "select JobTypeID,PlayerId,FOREIGN,FOREIGN " + sql.substr(9);
	} else
		temp = sql;
	q.get_result(temp);
	if (q.fetch_row())
	{
		this -> jobtypeid = q.getval(0);			// 0 - jobtypeid INTEGER
		this -> playerid = q.getval(1);			// 1 - playerid INTEGER
		// 2 - foreign KEY(JobTypeID)(JobTypeID)
		// 3 - foreign KEY(PlayerId)(PlayerId)
		new_object = 0;
	} else
		clear();
	q.free_result();
}

void PlayerJobs::spawn(Query *qd,int offset)
{
	clear();

	this -> jobtypeid = qd->getval(0 + offset);			// 0 - jobtypeid INTEGER
	this -> playerid = qd->getval(1 + offset);			// 1 - playerid INTEGER
	// 2 - foreign KEY(JobTypeID)(JobTypeID)
	// 3 - foreign KEY(PlayerId)(PlayerId)
}

// Begin class 'PlayerPaths'
PlayerPaths::PlayerPaths(Database *db)
{
	database = db;
	new_object = 1;
	clear();
}

PlayerPaths::PlayerPaths(Database *db,const std::string& sql)
{
	database = db;
	new_object = 1;
	spawn(sql);
}

PlayerPaths::PlayerPaths(Database *db,Query *qd,int offset)
{
	database = db;
	new_object = 0;
	spawn(qd, offset);
}

PlayerPaths::~PlayerPaths()
{
}

void PlayerPaths::select(const std::string& sql)
{
	spawn(sql);
}

unsigned __int64 PlayerPaths::insert()
{
	Query q(*database);
	std::string sql;

	sql = "insert into PlayerPaths(PathId,PlayerId)";
	{
		char slask[200];
		sprintf_s(slask, 200, " values(%ld",this -> pathid);
		sql += slask;
	}
	{
		char slask[200];
		sprintf_s(slask, 200, ", %ld",this -> playerid);
		sql += slask;
	}
	sql += ")";

	if(!q.execute(sql))
		return 0;

	new_object = 0;
	unsigned __int64 inserted_id = q.insert_id();
	pathid = (long)inserted_id;
	return inserted_id;
}

void PlayerPaths::save()
{
	if (new_object)
		insert();
}

std::string PlayerPaths::xml()
{
	Query q(*database);
	std::string dest;
	char slask[200];
	dest = "<PLAYERPATHS>";
	sprintf_s(slask, 200, "<PATHID>%ld</PATHID>",this -> pathid);
	dest += slask;
	sprintf_s(slask, 200, "<PLAYERID>%ld</PLAYERID>",this -> playerid);
	dest += slask;
	dest += "</PLAYERPATHS>";
	return dest;
}

std::string PlayerPaths::xml(const std::string& tag,const std::string& xvalx)
{
	Query q(*database);
	std::string dest;
	char slask[200];
	dest = "<PLAYERPATHS " + tag + "=\"" + xvalx + "\">";
	sprintf_s(slask, 200, "<PATHID>%ld</PATHID>",this -> pathid);
	dest += slask;
	sprintf_s(slask, 200, "<PLAYERID>%ld</PLAYERID>",this -> playerid);
	dest += slask;
	dest += "</PLAYERPATHS>";
	return dest;
}

size_t PlayerPaths::num_cols()
{
	return 4;
}

void PlayerPaths::clear()
{
	this -> pathid = 0;
	this -> playerid = 0;
	// 2 - foreign KEY(PathId)(PathId)
	// 3 - foreign KEY(PlayerId)(PlayerId)
}

void PlayerPaths::spawn(const std::string& sql)
{
	Query q(*database);
	std::string temp;

	clear();

	if (!strncasecmp(sql.c_str(),"select * ",9))
	{
		temp = "select PathId,PlayerId,FOREIGN,FOREIGN " + sql.substr(9);
	} else
		temp = sql;
	q.get_result(temp);
	if (q.fetch_row())
	{
		this -> pathid = q.getval(0);			// 0 - pathid INTEGER
		this -> playerid = q.getval(1);			// 1 - playerid INTEGER
		// 2 - foreign KEY(PathId)(PathId)
		// 3 - foreign KEY(PlayerId)(PlayerId)
		new_object = 0;
	} else
		clear();
	q.free_result();
}

void PlayerPaths::spawn(Query *qd,int offset)
{
	clear();

	this -> pathid = qd->getval(0 + offset);			// 0 - pathid INTEGER
	this -> playerid = qd->getval(1 + offset);			// 1 - playerid INTEGER
	// 2 - foreign KEY(PathId)(PathId)
	// 3 - foreign KEY(PlayerId)(PlayerId)
}

// Begin class 'Players'
Players::Players(Database *db)
{
	database = db;
	new_object = 1;
	clear();
}

Players::Players(Database *db,const std::string& sql)
{
	database = db;
	new_object = 1;
	spawn(sql);
}

Players::Players(Database *db,Query *qd,int offset)
{
	database = db;
	new_object = 0;
	spawn(qd, offset);
}

Players::Players(Database& db,long i_playerid):database(&db),new_object(1)
{
	Query q(*database);
	std::string sql = "select * from Players where ";
	{
		char slask[100];
		sprintf_s(slask, 100, "PlayerID='%ld'",i_playerid);
		sql += slask;
	}
	spawn(sql);
}

Players::~Players()
{
}

void Players::select(const std::string& sql)
{
	spawn(sql);
}

unsigned __int64 Players::insert()
{
	Query q(*database);
	std::string sql;

	sql = "insert into Players(Name,Position,CrawlSpeed,SprintSpeed,IsHumanPlayer,ViewRange,DieingTime,MovableText,CharacterState,Direction,PlayerType,Health,Team,RunSpeed,ReloadSpeed,RifleMarksman,PhysicalStrength)";
	sql += " values('" + q.GetDatabase().safestr(this -> name) + "'";
	sql += ", '" + q.GetDatabase().safestr(this -> position) + "'";
	{
		char slask[200];
		sprintf_s(slask, 200, ", %f",this -> crawlspeed);
		sql += slask;
	}
	{
		char slask[200];
		sprintf_s(slask, 200, ", %f",this -> sprintspeed);
		sql += slask;
	}
	sql += ", '" + (this -> ishumanplayer ? q.GetDatabase().safestr(this -> ishumanplayer ? "true" : "false") : "") + "'";
	{
		char slask[200];
		sprintf_s(slask, 200, ", %f",this -> viewrange);
		sql += slask;
	}
	{
		char slask[200];
		sprintf_s(slask, 200, ", %f",this -> dieingtime);
		sql += slask;
	}
	sql += ", '" + q.GetDatabase().safestr(this -> movabletext) + "'";
	sql += ", '" + q.GetDatabase().safestr(this -> characterstate) + "'";
	sql += ", '" + q.GetDatabase().safestr(this -> direction) + "'";
	sql += ", '" + q.GetDatabase().safestr(this -> playertype) + "'";
	{
		char slask[200];
		sprintf_s(slask, 200, ", %f",this -> health);
		sql += slask;
	}
	{
		char slask[200];
		sprintf_s(slask, 200, ", %ld",this -> team);
		sql += slask;
	}
	{
		char slask[200];
		sprintf_s(slask, 200, ", %f",this -> runspeed);
		sql += slask;
	}
	{
		char slask[200];
		sprintf_s(slask, 200, ", %f",this -> reloadspeed);
		sql += slask;
	}
	{
		char slask[200];
		sprintf_s(slask, 200, ", %f",this -> riflemarksman);
		sql += slask;
	}
	{
		char slask[200];
		sprintf_s(slask, 200, ", %f",this -> physicalstrength);
		sql += slask;
	}
	sql += ")";

	if(!q.execute(sql))
		return 0;

	new_object = 0;
	unsigned __int64 inserted_id = q.insert_id();
	playerid = (long)inserted_id;
	return inserted_id;
}

void Players::update()
{
	update(this -> playerid);
}

void Players::update(long i_playerid)
{
	Query q(*database);
	std::string sql;
	sql += "update Players set Name='" + q.GetDatabase().safestr(this -> name) + "'";
	sql += ", Position='" + q.GetDatabase().safestr(this -> position) + "'";
	{
		char slask[200];
		sprintf_s(slask, 200, ", CrawlSpeed='%f'",this -> crawlspeed);
		sql += slask;
	}
	{
		char slask[200];
		sprintf_s(slask, 200, ", SprintSpeed='%f'",this -> sprintspeed);
		sql += slask;
	}
	sql += ", IsHumanPlayer='" + q.GetDatabase().safestr(this -> ishumanplayer  ? "true" : "false") + "'";
	{
		char slask[200];
		sprintf_s(slask, 200, ", ViewRange='%f'",this -> viewrange);
		sql += slask;
	}
	{
		char slask[200];
		sprintf_s(slask, 200, ", DieingTime='%f'",this -> dieingtime);
		sql += slask;
	}
	sql += ", MovableText='" + q.GetDatabase().safestr(this -> movabletext) + "'";
	sql += ", CharacterState='" + q.GetDatabase().safestr(this -> characterstate) + "'";
	sql += ", Direction='" + q.GetDatabase().safestr(this -> direction) + "'";
	sql += ", PlayerType='" + q.GetDatabase().safestr(this -> playertype) + "'";
	{
		char slask[200];
		sprintf_s(slask, 200, ", Health='%f'",this -> health);
		sql += slask;
	}
	{
		char slask[200];
		sprintf_s(slask, 200, ", Team=%ld",this -> team);
		sql += slask;
	}
	{
		char slask[200];
		sprintf_s(slask, 200, ", RunSpeed='%f'",this -> runspeed);
		sql += slask;
	}
	{
		char slask[200];
		sprintf_s(slask, 200, ", ReloadSpeed='%f'",this -> reloadspeed);
		sql += slask;
	}
	{
		char slask[200];
		sprintf_s(slask, 200, ", RifleMarksman='%f'",this -> riflemarksman);
		sql += slask;
	}
	{
		char slask[200];
		sprintf_s(slask, 200, ", PhysicalStrength='%f'",this -> physicalstrength);
		sql += slask;
	}
	{
		char slask[200];
		sprintf_s(slask, 200, " where PlayerID='%ld'",i_playerid);
		sql += slask;
	}
	q.execute(sql);
}

void Players::save()
{
	if (new_object)
		insert();
	else
		update();
}

void Players::erase()
{
	if (!new_object)
	{
		std::string sql = "delete from Players where";
		Query q(*database);
		{
			char slask[200];
			sprintf_s(slask, 200, " PlayerID='%ld'",this -> playerid);
			sql += slask;
		}
		q.execute(sql);
	}
}

std::string Players::xml()
{
	Query q(*database);
	std::string dest;
	char slask[200];
	dest = "<PLAYERS>";
	sprintf_s(slask, 200, "<PLAYERID>%ld</PLAYERID>",this -> playerid);
	dest += slask;
	dest += "<NAME>" + q.GetDatabase().xmlsafestr(this -> name) + "</NAME>";
	dest += "<POSITION>" + q.GetDatabase().xmlsafestr(this -> position) + "</POSITION>";
	sprintf_s(slask, 200,"<CRAWLSPEED>%f</CRAWLSPEED>",this -> crawlspeed);
	dest += slask;
	sprintf_s(slask, 200,"<SPRINTSPEED>%f</SPRINTSPEED>",this -> sprintspeed);
	dest += slask;
	dest += "<ISHUMANPLAYER>" + q.GetDatabase().xmlsafestr(this -> ishumanplayer ? "true" : "false") + "</ISHUMANPLAYER>";
	sprintf_s(slask, 200,"<VIEWRANGE>%f</VIEWRANGE>",this -> viewrange);
	dest += slask;
	sprintf_s(slask, 200,"<DIEINGTIME>%f</DIEINGTIME>",this -> dieingtime);
	dest += slask;
	dest += "<MOVABLETEXT>" + q.GetDatabase().xmlsafestr(this -> movabletext) + "</MOVABLETEXT>";
	dest += "<CHARACTERSTATE>" + q.GetDatabase().xmlsafestr(this -> characterstate) + "</CHARACTERSTATE>";
	dest += "<DIRECTION>" + q.GetDatabase().xmlsafestr(this -> direction) + "</DIRECTION>";
	dest += "<PLAYERTYPE>" + q.GetDatabase().xmlsafestr(this -> playertype) + "</PLAYERTYPE>";
	sprintf_s(slask, 200,"<HEALTH>%f</HEALTH>",this -> health);
	dest += slask;
	sprintf_s(slask, 200, "<TEAM>%ld</TEAM>",this -> team);
	dest += slask;
	sprintf_s(slask, 200,"<RUNSPEED>%f</RUNSPEED>",this -> runspeed);
	dest += slask;
	sprintf_s(slask, 200,"<RELOADSPEED>%f</RELOADSPEED>",this -> reloadspeed);
	dest += slask;
	sprintf_s(slask, 200,"<RIFLEMARKSMAN>%f</RIFLEMARKSMAN>",this -> riflemarksman);
	dest += slask;
	sprintf_s(slask, 200,"<PHYSICALSTRENGTH>%f</PHYSICALSTRENGTH>",this -> physicalstrength);
	dest += slask;
	dest += "</PLAYERS>";
	return dest;
}

std::string Players::xml(const std::string& tag,const std::string& xvalx)
{
	Query q(*database);
	std::string dest;
	char slask[200];
	dest = "<PLAYERS " + tag + "=\"" + xvalx + "\">";
	sprintf_s(slask, 200, "<PLAYERID>%ld</PLAYERID>",this -> playerid);
	dest += slask;
	dest += "<NAME>" + q.GetDatabase().xmlsafestr(this -> name) + "</NAME>";
	dest += "<POSITION>" + q.GetDatabase().xmlsafestr(this -> position) + "</POSITION>";
	sprintf_s(slask, 200,"<CRAWLSPEED>%f</CRAWLSPEED>",this -> crawlspeed);
	dest += slask;
	sprintf_s(slask, 200,"<SPRINTSPEED>%f</SPRINTSPEED>",this -> sprintspeed);
	dest += slask;
	dest += "<ISHUMANPLAYER>" + q.GetDatabase().xmlsafestr(this -> ishumanplayer ? "true" : "false") + "</ISHUMANPLAYER>";
	sprintf_s(slask, 200,"<VIEWRANGE>%f</VIEWRANGE>",this -> viewrange);
	dest += slask;
	sprintf_s(slask, 200,"<DIEINGTIME>%f</DIEINGTIME>",this -> dieingtime);
	dest += slask;
	dest += "<MOVABLETEXT>" + q.GetDatabase().xmlsafestr(this -> movabletext) + "</MOVABLETEXT>";
	dest += "<CHARACTERSTATE>" + q.GetDatabase().xmlsafestr(this -> characterstate) + "</CHARACTERSTATE>";
	dest += "<DIRECTION>" + q.GetDatabase().xmlsafestr(this -> direction) + "</DIRECTION>";
	dest += "<PLAYERTYPE>" + q.GetDatabase().xmlsafestr(this -> playertype) + "</PLAYERTYPE>";
	sprintf_s(slask, 200,"<HEALTH>%f</HEALTH>",this -> health);
	dest += slask;
	sprintf_s(slask, 200, "<TEAM>%ld</TEAM>",this -> team);
	dest += slask;
	sprintf_s(slask, 200,"<RUNSPEED>%f</RUNSPEED>",this -> runspeed);
	dest += slask;
	sprintf_s(slask, 200,"<RELOADSPEED>%f</RELOADSPEED>",this -> reloadspeed);
	dest += slask;
	sprintf_s(slask, 200,"<RIFLEMARKSMAN>%f</RIFLEMARKSMAN>",this -> riflemarksman);
	dest += slask;
	sprintf_s(slask, 200,"<PHYSICALSTRENGTH>%f</PHYSICALSTRENGTH>",this -> physicalstrength);
	dest += slask;
	dest += "</PLAYERS>";
	return dest;
}

size_t Players::num_cols()
{
	return 18;
}

void Players::clear()
{
	this -> playerid = 0;
	this -> name = "";
	this -> position = "";
	this -> crawlspeed = 0;
	this -> sprintspeed = 0;
	this -> ishumanplayer = "";
	this -> viewrange = 0;
	this -> dieingtime = 0;
	this -> movabletext = "";
	this -> characterstate = "";
	this -> direction = "";
	this -> playertype = "";
	this -> health = 0;
	this -> team = 0;
	this -> runspeed = 0;
	this -> reloadspeed = 0;
	this -> riflemarksman = 0;
	this -> physicalstrength = 0;
}

void Players::spawn(const std::string& sql)
{
	Query q(*database);
	std::string temp;

	clear();

	if (!strncasecmp(sql.c_str(),"select * ",9))
	{
		temp = "select PlayerID,Name,Position,CrawlSpeed,SprintSpeed,IsHumanPlayer,ViewRange,DieingTime,MovableText,CharacterState,Direction,PlayerType,Health,Team,RunSpeed,ReloadSpeed,RifleMarksman,PhysicalStrength " + sql.substr(9);
	} else
		temp = sql;
	q.get_result(temp);
	if (q.fetch_row())
	{
		this -> playerid = q.getval(0);			// 0 - playerid INTEGER
		this -> name = q.getstr(1);			// 1 - name VARCHAR(50)
		this -> position = q.getstr(2);			// 2 - position TEXT
		this -> crawlspeed = (float)q.getnum(3);			// 3 - crawlspeed REAL
		this -> sprintspeed = (float)q.getnum(4);			// 4 - sprintspeed REAL
		this -> ishumanplayer = q.getnum(5) > 0;			// 5 - ishumanplayer BOOL
		this -> viewrange = (float)q.getnum(6);			// 6 - viewrange REAL
		this -> dieingtime = (float)q.getnum(7);			// 7 - dieingtime REAL
		this -> movabletext = q.getstr(8);			// 8 - movabletext TEXT
		this -> characterstate = q.getstr(9);			// 9 - characterstate VARCHAR(50)
		this -> direction = q.getstr(10);			// 10 - direction TEXT
		this -> playertype = q.getstr(11);			// 11 - playertype TEXT
		this -> health = (float)q.getnum(12);			// 12 - health REAL
		this -> team = q.getval(13);			// 13 - team INTEGER
		this -> runspeed = (float)q.getnum(14);			// 14 - runspeed REAL
		this -> reloadspeed = (float)q.getnum(15);			// 15 - reloadspeed REAL
		this -> riflemarksman = (float)q.getnum(16);			// 16 - riflemarksman REAL
		this -> physicalstrength = (float)q.getnum(17);			// 17 - physicalstrength REAL
		new_object = 0;
	} else
		clear();
	q.free_result();
}

void Players::spawn(Query *qd,int offset)
{
	clear();

	this -> playerid = qd->getval(0 + offset);			// 0 - playerid INTEGER
	this -> name = qd -> getstr(1 + offset);			// 1 - name VARCHAR(50)
	this -> position = qd->getstr(2 + offset);			// 2 - position TEXT
	this -> crawlspeed = (float)qd->getnum(3 + offset);			// 3 - crawlspeed REAL
	this -> sprintspeed = (float)qd->getnum(4 + offset);			// 4 - sprintspeed REAL
	this -> ishumanplayer = qd->getnum(5 + offset) > 0;			// 5 - ishumanplayer BOOL
	this -> viewrange = (float)qd->getnum(6 + offset);			// 6 - viewrange REAL
	this -> dieingtime = (float)qd->getnum(7 + offset);			// 7 - dieingtime REAL
	this -> movabletext = qd->getstr(8 + offset);			// 8 - movabletext TEXT
	this -> characterstate = qd -> getstr(9 + offset);			// 9 - characterstate VARCHAR(50)
	this -> direction = qd->getstr(10 + offset);			// 10 - direction TEXT
	this -> playertype = qd->getstr(11 + offset);			// 11 - playertype TEXT
	this -> health = (float)qd->getnum(12 + offset);			// 12 - health REAL
	this -> team = qd->getval(13 + offset);			// 13 - team INTEGER
	this -> runspeed = (float)qd->getnum(14 + offset);			// 14 - runspeed REAL
	this -> reloadspeed = (float)qd->getnum(15 + offset);			// 15 - reloadspeed REAL
	this -> riflemarksman = (float)qd->getnum(16 + offset);			// 16 - riflemarksman REAL
	this -> physicalstrength = (float)qd->getnum(17 + offset);			// 17 - physicalstrength REAL
}

// Begin class 'SpawnPoints'
SpawnPoints::SpawnPoints(Database *db)
{
	database = db;
	new_object = 1;
	clear();
}

SpawnPoints::SpawnPoints(Database *db,const std::string& sql)
{
	database = db;
	new_object = 1;
	spawn(sql);
}

SpawnPoints::SpawnPoints(Database *db,Query *qd,int offset)
{
	database = db;
	new_object = 0;
	spawn(qd, offset);
}

SpawnPoints::~SpawnPoints()
{
}

void SpawnPoints::select(const std::string& sql)
{
	spawn(sql);
}

unsigned __int64 SpawnPoints::insert()
{
	Query q(*database);
	std::string sql;

	sql = "insert into SpawnPoints(Id,Position,Team,CoolDown)";
	{
		char slask[200];
		sprintf_s(slask, 200, " values(%ld",this -> id);
		sql += slask;
	}
	sql += ", '" + q.GetDatabase().safestr(this -> position) + "'";
	{
		char slask[200];
		sprintf_s(slask, 200, ", %ld",this -> team);
		sql += slask;
	}
	{
		char slask[200];
		sprintf_s(slask, 200, ", %f",this -> cooldown);
		sql += slask;
	}
	sql += ")";

	if(!q.execute(sql))
		return 0;

	new_object = 0;
	unsigned __int64 inserted_id = q.insert_id();
	id = (long)inserted_id;
	return inserted_id;
}

void SpawnPoints::save()
{
	if (new_object)
		insert();
}

std::string SpawnPoints::xml()
{
	Query q(*database);
	std::string dest;
	char slask[200];
	dest = "<SPAWNPOINTS>";
	sprintf_s(slask, 200, "<ID>%ld</ID>",this -> id);
	dest += slask;
	dest += "<POSITION>" + q.GetDatabase().xmlsafestr(this -> position) + "</POSITION>";
	sprintf_s(slask, 200, "<TEAM>%ld</TEAM>",this -> team);
	dest += slask;
	sprintf_s(slask, 200,"<COOLDOWN>%f</COOLDOWN>",this -> cooldown);
	dest += slask;
	dest += "</SPAWNPOINTS>";
	return dest;
}

std::string SpawnPoints::xml(const std::string& tag,const std::string& xvalx)
{
	Query q(*database);
	std::string dest;
	char slask[200];
	dest = "<SPAWNPOINTS " + tag + "=\"" + xvalx + "\">";
	sprintf_s(slask, 200, "<ID>%ld</ID>",this -> id);
	dest += slask;
	dest += "<POSITION>" + q.GetDatabase().xmlsafestr(this -> position) + "</POSITION>";
	sprintf_s(slask, 200, "<TEAM>%ld</TEAM>",this -> team);
	dest += slask;
	sprintf_s(slask, 200,"<COOLDOWN>%f</COOLDOWN>",this -> cooldown);
	dest += slask;
	dest += "</SPAWNPOINTS>";
	return dest;
}

size_t SpawnPoints::num_cols()
{
	return 4;
}

void SpawnPoints::clear()
{
	this -> id = 0;
	this -> position = "";
	this -> team = 0;
	this -> cooldown = 0;
}

void SpawnPoints::spawn(const std::string& sql)
{
	Query q(*database);
	std::string temp;

	clear();

	if (!strncasecmp(sql.c_str(),"select * ",9))
	{
		temp = "select Id,Position,Team,CoolDown " + sql.substr(9);
	} else
		temp = sql;
	q.get_result(temp);
	if (q.fetch_row())
	{
		this -> id = q.getval(0);			// 0 - id INTEGER
		this -> position = q.getstr(1);			// 1 - position TEXT
		this -> team = q.getval(2);			// 2 - team INTEGER
		this -> cooldown = (float)q.getnum(3);			// 3 - cooldown REAL
		new_object = 0;
	} else
		clear();
	q.free_result();
}

void SpawnPoints::spawn(Query *qd,int offset)
{
	clear();

	this -> id = qd->getval(0 + offset);			// 0 - id INTEGER
	this -> position = qd->getstr(1 + offset);			// 1 - position TEXT
	this -> team = qd->getval(2 + offset);			// 2 - team INTEGER
	this -> cooldown = (float)qd->getnum(3 + offset);			// 3 - cooldown REAL
}

// Begin class 'StaticData'
StaticData::StaticData(Database *db)
{
	database = db;
	new_object = 1;
	clear();
}

StaticData::StaticData(Database *db,const std::string& sql)
{
	database = db;
	new_object = 1;
	spawn(sql);
}

StaticData::StaticData(Database *db,Query *qd,int offset)
{
	database = db;
	new_object = 0;
	spawn(qd, offset);
}

StaticData::~StaticData()
{
}

void StaticData::select(const std::string& sql)
{
	spawn(sql);
}

unsigned __int64 StaticData::insert()
{
	Query q(*database);
	std::string sql;

	sql = "insert into StaticData(XmlData)";
	sql += " values('" + q.GetDatabase().safestr(this -> xmldata) + "'";
	sql += ")";

	if(!q.execute(sql))
		return 0;

	new_object = 0;
	unsigned __int64 inserted_id = q.insert_id();
	return inserted_id;
}

void StaticData::save()
{
	if (new_object)
		insert();
}

std::string StaticData::xml()
{
	Query q(*database);
	std::string dest;
	dest = "<STATICDATA>";
	dest += "<XMLDATA>" + q.GetDatabase().xmlsafestr(this -> xmldata) + "</XMLDATA>";
	dest += "</STATICDATA>";
	return dest;
}

std::string StaticData::xml(const std::string& tag,const std::string& xvalx)
{
	Query q(*database);
	std::string dest;
	dest = "<STATICDATA " + tag + "=\"" + xvalx + "\">";
	dest += "<XMLDATA>" + q.GetDatabase().xmlsafestr(this -> xmldata) + "</XMLDATA>";
	dest += "</STATICDATA>";
	return dest;
}

size_t StaticData::num_cols()
{
	return 1;
}

void StaticData::clear()
{
	this -> xmldata = "";
}

void StaticData::spawn(const std::string& sql)
{
	Query q(*database);
	std::string temp;

	clear();

	if (!strncasecmp(sql.c_str(),"select * ",9))
	{
		temp = "select XmlData " + sql.substr(9);
	} else
		temp = sql;
	q.get_result(temp);
	if (q.fetch_row())
	{
		this -> xmldata = q.getstr(0);			// 0 - xmldata TEXT
		new_object = 0;
	} else
		clear();
	q.free_result();
}

void StaticData::spawn(Query *qd,int offset)
{
	clear();

	this -> xmldata = qd->getstr(0 + offset);			// 0 - xmldata TEXT
}

} // End of Core namespace
} // End of DAL namespace
