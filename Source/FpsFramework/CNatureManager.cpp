#include "CNatureManager.h"
#include "CWorld.h"
#include "CWaterSystem.h"
#include "CTerrainSystem.h"
#include "Structures.h"
#include "CGameManager.h"
#include "IO/CoreLogging.h"

#include "Terrain/OgreTerrainGroup.h"
#include "Hydrax/Hydrax.h"

using namespace Core;
using namespace Core::Nature;

CNatureManager* CNatureManager::NatureManager = nullptr;

CNatureManager* CNatureManager::Instance()
{
	if(NatureManager == nullptr)
		NatureManager = new CNatureManager();
	return NatureManager;
}

CNatureManager::CNatureManager() : m_CurrWorld(nullptr), m_Water(nullptr)
{
	Initialize();
}

CNatureManager::~CNatureManager()
{
	Shutdown();

	if(m_Water)
	{
		m_Water->Shutdown();
		CORE_DELETE(m_Water);
	}
}

void CNatureManager::Shutdown()
{
	try
	{
		for(auto it = m_Worlds.begin(); it != m_Worlds.end(); it++)
			CORE_DELETE((*it));
		m_Worlds.clear();
	
		if(m_Water)
		{
			if(m_Water->GetHydrax())
			{
				m_Water->GetHydrax()->setVisible(false);
			}
		}
	}
	catch(std::exception& e)
	{
		CORE_ASSERT(false);
		throw(e);
	}
	catch(...)
	{
		throw("Error in CNatureManager::Shutdown()");
	}
}

bool CNatureManager::Initialize()
{
	m_SceneManager = CGameManager::Instance()->GetSceneManager();
	m_TerrainGroup = nullptr;
	return true;
}

bool CNatureManager::CreateWorld(HYDRAX* HydraxSettings, CAELUM* CealumSettings, Core::TERRAIN_TYPE* TerrainSettings, String ResourceGroupName) 
{ 
	m_ResourceGroupName = ResourceGroupName;

	// Add the world to the vector
	m_CurrWorld = new CWorld(HydraxSettings, CealumSettings, TerrainSettings); 
	m_Worlds.push_back(m_CurrWorld);

	return m_CurrWorld != nullptr;
}

bool CNatureManager::DestroyWorld(CWorld* World)
{
	if(World)
	{
		World->Shutdown();
		
		u32 i = 0;
		for(; i < m_Worlds.size(); i++)
		{
			if(World == m_Worlds[i])
				break;
		}
		if(i < m_Worlds.size())
			m_Worlds.erase(m_Worlds.begin() + i);
			
		CORE_DELETE(World);
	}
	
	return true;
}

void CNatureManager::Update(const f32& elapsedTime)
{
	if(m_CurrWorld)
		m_CurrWorld->Update(elapsedTime);

	if(m_Water)
		m_Water->Update(elapsedTime);
}

CWorld* CNatureManager::GetWorld()
{
	return m_CurrWorld;
}

String CNatureManager::GetResourceGroupName()
{
	return m_ResourceGroupName;
}

MovablePlane* CNatureManager::GetBottomPlane()
{
	if(m_CurrWorld)
		if(m_CurrWorld->GetTerrainSystem())
			return m_CurrWorld->GetTerrainSystem()->GetPlane();
	return nullptr;
}

void CNatureManager::SetWaterSystem(CWaterSystem* WaterSystem)
{
	m_Water = WaterSystem;
}

CWaterSystem* CNatureManager::GetWaterSystem() 
{ 
	return m_Water; 
}

TerrainGroup* CNatureManager::GetTerrainGroup()
{
	return m_TerrainGroup;
}

void CNatureManager::SetTerrainGroup(TerrainGroup* Terrain)
{
	m_TerrainGroup = Terrain;
}

f32 CNatureManager::GetTerrainHeightAt(const Ray& MouseRay)
{
	if(m_TerrainGroup)
	{
		TerrainGroup::RayResult rayResult = m_TerrainGroup->rayIntersects(MouseRay);
		if (rayResult.hit)
			return rayResult.position.y;
	}
	else
	{
		return 0;
	}
	return -9999;
}

f32 CNatureManager::GetTerrainHeightAt(const f32 x, const f32 z)
{
	Ray mouseRay = Ogre::Ray(Vector3(x, 1000, z), Vector3::NEGATIVE_UNIT_Y);

	// Test paged terrain first
	if(m_TerrainGroup)
	{
		TerrainGroup::RayResult rayResult = m_TerrainGroup->rayIntersects(mouseRay);
		if (rayResult.hit)
			return rayResult.position.y;
	}
	else
	{
		//// Plane test
		//RaySceneQuery* mRayScnQuery = m_SceneManager->createRayQuery(Ray());
		//mRayScnQuery->setRay(mouseRay);
		//RaySceneQueryResult& result = mRayScnQuery->execute();
		//for(RaySceneQueryResult::iterator iter = result.begin();
		//	iter != result.end();
		//	iter++)
		//{
		//	if(iter->movable)
		//	{ 
		//		if(iter->movable->getName().find(PLANE_ENTITY_NAME))
		//		{
		//			return mouseRay.getPoint(iter->distance).y;
		//		}
		//	}
		//}
		return 0;
	}
	return -9999;
}

Vector3	CNatureManager::GetTerrainPosition(const Ray& MouseRay)
{
	// Test paged terrain first
	if(m_TerrainGroup)
	{
		TerrainGroup::RayResult rayResult = m_TerrainGroup->rayIntersects(MouseRay);
		if (rayResult.hit)
			return rayResult.position;
	}
	else
	{
		auto pos = MouseRay.getPoint(0.0f);
		pos.y = 0;
		return pos;
	}
	return INVALID_POS;
}

void CNatureManager::AddPagedGeometry(Core::GEO_SET* GeoSet)
{
	if(m_CurrWorld)
		m_CurrWorld->AddPagedGeometry(GeoSet);
}