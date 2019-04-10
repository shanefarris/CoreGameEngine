// This uses both Xml for static data, and the Db for dynamic data.

#include "CSerializer.h"
#include "IO/CFileSystem.h"
#include "FileDatabase/CoreDal.h"

#include "CGameObjectManager.h"
#include "CPlayer.h"
#include "CBuilding.h"
#include "CGameObject.h"
#include "CCharacterState.h"
#include "CPhysicsManager.h"
#include "IPhysicsStrategy.h"
#include "CUtility.h"
#include "QueryStrings.h"
#include "CItemsManager.h"
#include "CInventoryItem.h"
#include "CCharacterStateManager.h"
#include "CGameManager.h"
#include "CSpawnManager.h"
#include "Structures.h"
#include "AI/CAStarGrid.h"
#include "AI/CAStarNode.h"
#include "IO/CoreLogging.h"

// Inventory profiles
#include "CWeaponProfile.h"

// Physics profiles
#include "CPhysicsProfile.h"

// Ogre
#include "OgreSceneNode.h"
#include "OgreStringConverter.h"
#include "OgreResourceGroupManager.h"

using namespace IO;
using namespace Core;
using namespace Core::AI;
using namespace Core::DAL;

CSerializer::CSerializer()
{
}

CSerializer::~CSerializer()
{
	m_Elements.clear();
}

bool CSerializer::SaveGame(const char* FileName)
{
	try
	{
		// If the file name doesn't contain the extension, then add it
		String fileName = FileName;
		String extension = IO::CFileSystem::GetFileExtension(fileName);
		if(extension != ".scd")
			fileName += ".scd";

		// Empty the DB if it exist, else create an empty DB
		String initDb;
		if(CUtility::FileExists(FileName))
			initDb = CLEAR_DB;
		else
			initDb = CREATE_EMPTY_DB;

		if(!Execute(FileName, initDb))
			return false;

		StderrLog log;
		auto db = new Database(FileName, &log); // sqlite3 specific
		if(!db)
			return false;

		// Xml first and save to a memory file
		if(!SaveInventoryProfiles())
			return false;

		if(!SavePhysicsProfiles())
			return false;

		if(!SaveStaticData(db))
			return false;

		if(!SaveItems(db))
			return false;

		if(!SavePlayers(db))
			return false;

		if(!SavePhysics(db))
			return false;

		if(!SaveGameObjects(db))
			return false;

		if(!SaveAiPaths(db))
			return false;

		if(!SaveAStarGrid(db))
			return false;

		if(!SaveSpawnPoints(db))
			return false;

		if(!SaveBuildings(db))
			return false;

		db->freedb(db->grabdb());
	}
	catch(...)
	{
		return false;
	}

	return true;
}

void CSerializer::GetSavedFiles(Vector<String>& list)
{
	auto files = Ogre::ResourceGroupManager::getSingleton().listResourceFileInfo(ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	for(u32 i = 0; i < files->size(); i++)
	{
		auto fileInfo = files->at(i);
		if(IO::CFileSystem::GetFileExtension(fileInfo.basename) == "scd" ||
			IO::CFileSystem::GetFileExtension(fileInfo.basename) == "scx")
		{
			list.push_back(fileInfo.basename);
		}
	}
}

bool CSerializer::Execute(const String& FileName, const String& Command)
{
	Database* database = nullptr;
	Query* query = nullptr;

	try
	{
		StderrLog log;
		database = new Database(FileName, &log);
		if(!database)
			return false;

		query = new Query(*database);

		Vector<String> commands;
		CUtility::StringSplit(Command, ';', commands);
		for(auto it = commands.cbegin(); it != commands.cend(); it++)
		{
			String cmd = (*it);
			CUtility::Trim(cmd);
			if(cmd.length() > 0)
			{
				if(!query->execute(cmd))
				{
					String msg = "Error executing DB command: ";
					msg += cmd;
					CORE_ERR(msg.c_str());
					return false;
				}
			}
		}

		database->freedb(database->grabdb());
	}
	catch(...)
	{
		CORE_DELETE(database);
		CORE_DELETE(query);
	}
	return true;
}

bool CSerializer::SaveItems(Database* Db)
{
	// Saves the inventory in the level, not the players inventory.
	Vector<CInventoryItem*> list;
	CItemsManager::Instance()->GetPlacedItems(list);
	for(auto it = list.cbegin(); it != list.cend(); it++)
	{
		LevelInventory* item = new LevelInventory(Db);
		item->SetItemname((*it)->Name);
		item->SetOrientation(StringConverter::toString((*it)->GetGameObject()->Node->getOrientation()));
		item->SetPosition(StringConverter::toString((*it)->GetGameObject()->Node->getPosition()));
		
		if(item->insert() == 0)
			return false;
	}
	return true;
}

bool CSerializer::SavePlayers(Database* Db)
{
	Vector<CPlayer*> players;
	CGameObjectManager::Instance()->GetAllPlayers(players);
	for(auto it = players.cbegin(); it != players.cend(); it++)
	{
		Players* player = new Players(Db);

		player->SetPlayertype((*it)->GetPlayerType());
		player->SetName((*it)->GetName());
		player->SetTeam((u32)(*it)->GetPlayerTeam());
		player->SetIshumanplayer((*it)->GetIsHumanPlayer());
		player->SetPosition(StringConverter::toString((*it)->GetPosition()));
		player->SetCrawlspeed((*it)->GetCrawlSpeed());
		player->SetSprintspeed((*it)->GetSprintSpeed());
		player->SetViewrange((*it)->GetViewRange());
		player->SetDieingtime((*it)->GetDieTime());
		
		// Get Movable text
		const char* text = (*it)->GetMovableText();
		if(text)
			player->SetMovabletext(text);
		else
			player->SetMovabletext("");

		// Character state
		auto characterState = (*it)->GetCharacterState();
		if(characterState)
		{
			player->SetCharacterstate(characterState->GetStateName());
		}
		else
		{
			CORE_ERR("No character state found in CSceneWriterStrategy_DB::SavePlayers");
			// TODO: Need to build a default "idle" state in the engine.
			player->SetCharacterstate("IDLE");
		}

		player->SetDirection(StringConverter::toString((*it)->GetDirection()));
		player->SetHealth((*it)->GetHealth());
		player->SetRunspeed((*it)->GetRunSpeed());
		player->SetRiflemarksman(0);
		player->SetPhysicalstrength(0);

		long playerId = (long)player->insert();
		if(playerId == 0)
			return false;

		// Save player's items
		auto items = (*it)->GetItems();
		for(u32 i = 0; i < items.size(); i++)
		{
			PlayerInventory* item = new PlayerInventory(Db);
			item->SetProfilename(items[i]->Name);
			item->SetIscurrentitem(true);
			item->SetPlayerid(playerId);
			
			if(item->insert() == 0)
				return false;
		}
	}

	return true;
}

bool CSerializer::SavePhysics(Database* Db)
{
	Physics::IPhysicsStrategy* physics = Physics::CPhysicsManager::Instance()->GetStrategy();
	if(physics)
	{
		PhysicsStrategies* row = new PhysicsStrategies(Db);
		row->SetType((u32)physics->GetStrategyType());
		row->SetName("physics");

		if(row->insert() == 0)
			return false;
	}

	return true;
}

bool CSerializer::SaveGameObjects(Database* Db)
{
	Vector<CGameObject*> objects;
	CGameObjectManager::Instance()->GetGameObjects(objects);
	for(auto it = objects.cbegin(); it != objects.cend(); it++)
	{
		// Don't save game objects made only for an editor's use
		if((*it)->EnvironmentType != EAT_EDITOR)
		{
			GameObjects* obj = new GameObjects(Db);

			obj->SetName((*it)->Name);
			obj->SetType((*it)->GameObjectType);
			obj->SetOrientation(StringConverter::toString((*it)->Node->getOrientation()));
			obj->SetPosition(StringConverter::toString((*it)->Node->getPosition()));

			if(obj->insert() == 0)
				return false;
		}
	}

	return true;
}

bool CSerializer::SaveAiPaths(Database* Db)
{
	AI::PathDefinition paths;
	AI::CCharacterStateManager::Instance()->GetAllPaths(paths);
	for(auto it = paths.cbegin(); it != paths.cend(); it++)
	{
		AiPaths* path = new AiPaths(Db);

		// Format our list of vector points
		String allPoints;
		Vector<Vector3> points = (*it).second;
		for(u32 i = 0; i < points.size(); i++)
		{
			allPoints += StringConverter::toString(points[i].x) + ",";
			allPoints += StringConverter::toString(points[i].y) + ",";
			allPoints += StringConverter::toString(points[i].z);
			allPoints += ";";
		}

		path->SetName((*it).first);
		path->SetVectors(allPoints);

		if(path->insert() == 0)
			return false;
	}

	return true;
}

bool CSerializer::SaveAStarGrid(Database* Db)
{
	int nodeId = 1;
	auto nodes = CAStarGrid::Instance()->GetNodes();
	for(auto it = nodes->cbegin(); it != nodes->cend(); it++)
	{
		String str;
		auto node = new AStarNodes(Db);

		// Get the position
		str += StringConverter::toString((*it)->GetPosition().x) + ",";
		str += StringConverter::toString((*it)->GetPosition().y) + ",";
		str += StringConverter::toString((*it)->GetPosition().z);
		str += ";";
		node->SetPosition(str);

		// Get the neighbors
		str.clear();
		Vector<CAStarNode*>* connections = (*it)->GetConnections();
		for(auto it2 = connections->cbegin(); it2 != connections->cend(); it2++)
		{
			str += StringConverter::toString((*it2)->GetNodeId()) + ",";
		}
		str += ";";
		node->SetNeighbors(str);
		
		node->SetNodeid((*it)->GetNodeId());

		if(node->insert() == 0)
			return false;
		nodeId++;
	}

	return true;
}

bool CSerializer::SaveSpawnPoints(Database* Db)
{
	auto spawnPoints = CSpawnManager::Instance()->GetAllSpawnPoints();
	for(auto it = spawnPoints.cbegin(); it != spawnPoints.cend(); it++)
	{
		auto spawnPoint = new DAL::SpawnPoints(Db);

		spawnPoint->SetId((*it).second->Id);
		spawnPoint->SetCooldown((*it).second->CoolDown);
		spawnPoint->SetPosition(StringConverter::toString((*it).second->Position));
		spawnPoint->SetTeam((u32)(*it).second->Team);

		if(spawnPoint->insert() == 0)
			return false;
	}

	return true;
}

bool CSerializer::SaveBuildings(Database* Db)
{
	auto buildings = CGameObjectManager::Instance()->GetAllBuildings();
	for(auto it = buildings.cbegin(); it != buildings.cend(); it++)
	{
		auto building = new DAL::Buildings(Db);

		building->SetBuildingcategory((s32)(*it)->GetCategory());
		building->SetBuildingstate((s32)(*it)->GetState());
		building->SetHealth((*it)->GetHealth());
		building->SetName((*it)->GetName());
		building->SetPosition(StringConverter::toString((*it)->GetPosition()));
		building->SetTeam((s32)(*it)->GetTeam());
		building->SetBuildingtype((*it)->GetBuildingType());

		if(building->insert() == 0)
			return false;
	}

	return true;
}

bool CSerializer::SaveInventoryProfiles()
{
	// Only need to get the profiles of everything, not the individual items
	Vector<CItemProfile*> list;
	CItemsManager::Instance()->GetItemProfiles(list);

	// Save all weapon profiles first
	for(auto it = list.cbegin(); it != list.cend(); it++)
	{
		if((*it)->InventoryType == EIT_WEAPON)
		{
			auto profile = static_cast<CWeaponProfile*>((*it));
			Vector<TAG_ELEMENT> tag;
			tag.push_back(TAG_ELEMENT("Name", profile->Name));
			tag.push_back(TAG_ELEMENT("disp_name", profile->Desc));
			tag.push_back(TAG_ELEMENT("semi", StringConverter::toString(profile->isSemi)));
			tag.push_back(TAG_ELEMENT("burst", StringConverter::toString(profile->isBurst)));
			tag.push_back(TAG_ELEMENT("auto", StringConverter::toString(profile->isAuto)));
			tag.push_back(TAG_ELEMENT("mag", profile->MagazineProfile.Name));
			tag.push_back(TAG_ELEMENT("mesh", profile->MeshName));
			tag.push_back(TAG_ELEMENT("overlay", profile->OverlayName));
			tag.push_back(TAG_ELEMENT("accuracy", StringConverter::toString(profile->Accuracy)));
			tag.push_back(TAG_ELEMENT("power", StringConverter::toString(profile->Power)));
			tag.push_back(TAG_ELEMENT("scale", StringConverter::toString(profile->Scale)));
			tag.push_back(TAG_ELEMENT("range", StringConverter::toString(profile->Range)));
		
			m_Elements.push_back(MASTER_ELEMENT("Weapon", tag));
		}
	}

	// Save all magazine profiles next
	for(auto it = list.cbegin(); it != list.cend(); it++)
	{
		if((*it)->InventoryType == EIT_MAGAZINE)
		{
			CMagazineProfile* profile = static_cast<CMagazineProfile*>((*it));
			Vector<TAG_ELEMENT> tag;
			tag.push_back(TAG_ELEMENT("Name", profile->Name));
			tag.push_back(TAG_ELEMENT("disp_name", profile->Desc));
			tag.push_back(TAG_ELEMENT("projectiles", profile->ProjectileProfile.Name));
			tag.push_back(TAG_ELEMENT("capacity", StringConverter::toString(profile->Capacity)));
			tag.push_back(TAG_ELEMENT("mesh", profile->MeshName));
		
			m_Elements.push_back(MASTER_ELEMENT("Magazine", tag));
		}
	}

	// Save all projectile profiles next
	for(auto it = list.cbegin(); it != list.cend(); it++)
	{
		if((*it)->InventoryType == EIT_PROJECTILE)
		{
			CProjectileProfile* profile = static_cast<CProjectileProfile*>((*it));
			Vector<TAG_ELEMENT> tag;
			tag.push_back(TAG_ELEMENT("Name", profile->Name));
			tag.push_back(TAG_ELEMENT("disp_name", profile->Desc));
			tag.push_back(TAG_ELEMENT("damage", StringConverter::toString(profile->Damage)));
			tag.push_back(TAG_ELEMENT("penetrating", StringConverter::toString(profile->isPenetrate)));
			tag.push_back(TAG_ELEMENT("muzzle_velocity", StringConverter::toString(profile->Speed)));
			tag.push_back(TAG_ELEMENT("mesh", profile->MeshName));
			tag.push_back(TAG_ELEMENT("pitch", 0));		// TODO: not implemented yet
			tag.push_back(TAG_ELEMENT("roll", 0));		// TODO: not implemented yet
			tag.push_back(TAG_ELEMENT("bbbullet", profile->BillboardBullet));
			tag.push_back(TAG_ELEMENT("bbflash", profile->BillboardFlash));
		
			m_Elements.push_back(MASTER_ELEMENT("Projectile", tag));
		}
	}

	// Save all tool profiles next
	for(auto it = list.cbegin(); it != list.cend(); it++)
	{
		// TODO: no tools created yet
	}

	return true;
}

bool CSerializer::SavePhysicsProfiles()
{
	Core::Physics::PhysicsProfileList list;
	Physics::CPhysicsManager::Instance()->GetPhysicsProfileList(list);
	for(auto it = list.cbegin(); it != list.cend(); it++)
	{
		// Don't save built in profiles
		if((*it).first != Physics::CPhysicsManager::DEFAULT_HEAVY_CUBE &&
			(*it).first != Physics::CPhysicsManager::DEFAULT_HEAVY_SPHERE &&
			(*it).first != Physics::CPhysicsManager::DEFAULT_LIGHT_CUBE &&
			(*it).first != Physics::CPhysicsManager::DEFAULT_LIGHT_SPHERE &&
			(*it).first != Physics::CPhysicsManager::DEFAULT_MEDIUM_CUBE &&
			(*it).first != Physics::CPhysicsManager::DEFAULT_MEDIUM_SPHERE)
		{
			String shape;
			if((*it).second->GetShape() == Core::Physics::SHAPE_CUBE)
				shape = "cube";
			else if((*it).second->GetShape() == Core::Physics::SHAPE_SPHERE)
				shape = "sphere";
			else if((*it).second->GetShape() == Core::Physics::SHAPE_CAPSULE)
				shape = "cube";
			else if((*it).second->GetShape() == Core::Physics::SHAPE_CYLINDER)
				shape = "cylinder";
			else if((*it).second->GetShape() == Core::Physics::SHAPE_CONE)
				shape = "cone";
			else if((*it).second->GetShape() == Core::Physics::SHAPE_STATIC_TRIMESH)
				shape = "statictrimesh";
			else if((*it).second->GetShape() == Core::Physics::SHAPE_TRIMESH)
				shape = "trimesh";
			else if((*it).second->GetShape() == Core::Physics::SHAPE_PLANE)
				shape = "plane";
			else
				return false;

			Vector<TAG_ELEMENT> tag;
			tag.push_back(TAG_ELEMENT("Name", (*it).first.c_str()));
			tag.push_back(TAG_ELEMENT("Shape", shape));
			tag.push_back(TAG_ELEMENT("Friction", StringConverter::toString((*it).second->GetFriction())));
			tag.push_back(TAG_ELEMENT("Mass", StringConverter::toString((*it).second->GetMass())));
			tag.push_back(TAG_ELEMENT("Density", StringConverter::toString((*it).second->GetDensity())));
			tag.push_back(TAG_ELEMENT("Size", StringConverter::toString((*it).second->GetSize())));
			tag.push_back(TAG_ELEMENT("Direction", StringConverter::toString((*it).second->GetDirection())));
			tag.push_back(TAG_ELEMENT("Radius", StringConverter::toString((*it).second->GetRadius())));

			m_Elements.push_back(MASTER_ELEMENT("PhysicsProfile", tag));
		}
	}

	return true;
}

bool CSerializer::SaveStaticData(Database* Db)
{
	//// Combine the xml tags
	//String xml;
	//for(auto element = m_Elements.cbegin(); element != m_Elements.cend(); element++)
	//{
	//	xml += "<" + (*element).TagName + " ";
	//	for(auto it = (*element).Elements.cbegin(); it != (*element).Elements.cend(); it++)
	//	{
	//		xml += (*it).Name + String("=\"") + (*it).Value + String("\" ");
	//	}
	//	xml += String("></") + (*element).TagName + String(">") + "\r\n";
	//}

	auto staticData = new StaticData(Db);
	String data = CGameManager::Instance()->GetStaticData();
	if(data.length() == 0)
	{
		data = "<SceneManager ambient=\"0.361333 0.361333 0.361333 3\" fogcolor=\"0.5 0.5 0.5 1\" fogdensity=\"100\" fogend=\"5000\" fogstart=\"1000\" "
			"name=\"MySceneManager\" skyboxactive=\"false\" skyboxdistance=\"5000\" skyboxmaterial=\"\" scenemanagertype=\"OctreeSceneManager\" "
			"fogmode=\"FOG_LINEAR\"></SceneManager>"
			"<Viewport color=\"0 0 0 1\" compositor0enabled=\"true\" compositor0name=\"\" name=\"Viewport1\" parent=\"\"></Viewport>"
			"<Camera name=\"Camera1\" type=\"god\" clipdistance=\"0.1 59994\" default=\"true\" fov=\"0.785398\" lookat=\"0 0 0\" orientation=\"0 0 1 0\" parent=\"\" position=\"0 150 200\"></Camera>"
			"<Weapon name=\"weapon1\" disp_name=\"M4 Test1\" semi=\"true\" burst=\"false\" auto=\"true\" mag=\"9x19mm_15\" rof=\"80\" mesh=\"m4a1_1.mesh\" overlay=\"Soldier/Target\" accuracy=\"80\" power=\"25\" scale=\"1.0 1.0 1.0\" range=\"100\" />"
			"<Magazine name=\"9x19mm_15\" disp_name=\"9x19mm 15 round magazine\" projectiles=\"9x19mm_JHP\" capacity=\"150\" mesh=\"\"></Magazine>"
			"<Projectile name=\"9x19mm_JHP\" disp_name=\"9x19mm Jacketed Hollow Point\" damage=\"100\" penetrating=\"false\" muzzle_velocity=\"350\" mesh=\"\" pitch=\"90\" roll=\"0\" bbbullet=\"Bullet\" bbflash=\"BulletSource\"></Projectile>"
			"<PlaneTerrain normal=\"0 1 0\" />"
			"<Caelum name=\"CaelumSky\" timeday=\"1\" timehour=\"12\" timeminute=\"0\" timemonth=\"1\" timesec=\"0\" timespeed=\"0\" "
			"timeyear=\"2000\" isclouds=\"true\" layerofclouds=\"3452816845\" fogdenmultiplier=\"4294967294\" ismanagefog=\"false\" "
			"layer=\"0\" issinglelightsource=\"false\" issingleshadowsource=\"false\" ismanageambientlight=\"true\" "
			"minambientlight=\"0.1 0.1 0.3 1\" moonambientmultipler=\"0.2 0.2 0.2 1\" moonattmultipler=\"1\" moonattdistance=\"100000\" "
			"moonattlinearmultipler=\"0\" moonquadmultipler=\"0\" ismoonautodisable=\"true\" ismooncastshadow=\"true\" "
			"moondiffusemultipler=\"1 1 0.9 1\" ismoonenabled=\"true\" moonspecularmultipler=\"1 1 1 1\" observerlatitude=\"45\" "
			"observerlongitude=\"0\" isstarsenabled=\"true\" starsmag0pixelsize=\"16\" starsmagscale=\"2.51189\" starsmaxpixelsize=\"6\" "
			"starsminpixelsize=\"4\" sunambientmultipler=\"0.5 0.5 0.5 1\" sunattmultipler=\"1\" sundistance=\"100000\" "
			"sunattlinearmultipler=\"0\" sunquadmultipler=\"0\" issunautodisable=\"true\" issuncastshadow=\"true\" suncolor=\"0 0 0\" "
			"sundiffusemultipler=\"0 0 0 1\" issunenabled=\"true\" sunlightcolor=\"0 0 0\" sunposition=\"-309.9 8734.08 -21656.1\" "
			"sunspecularmultipler=\"0 0 0 1\">"
			"</Caelum>"
			"<BillBoard name=\"Bullet\" type=\"0\" poolsize=\"100\" material=\"blue_bullet\" width=\"1.05\" height=\"1.05\" />"
			"<BillBoard name=\"BulletSource\" type=\"0\" poolsize=\"100\" material=\"blue_bullet_source\" width=\"1.25\" height=\"1.25\" ></BillBoard>";
	}

	staticData->SetXmldata(data);
	return staticData->insert() > 0;
}
