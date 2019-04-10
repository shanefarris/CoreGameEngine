#include "CWorld.h"
#include "IEnvironment.h"
#include "CSkySystem.h"
#include "CTerrainSystem.h"
#include "CVegetationSystem.h"
#include "CWaterSystem.h"
#include "CNatureManager.h"
#include "Structures.h"
#include "IO/CoreLogging.h"

#include "OgreControllerManager.h"

using namespace Core;
using namespace Core::Nature;

CWorld::CWorld(Core::HYDRAX* HydraxSettings, Core::CAELUM* CealumSettings, Core::TERRAIN_TYPE* TerrainSettings) 
	: isPaused(false),  
	m_Sky(nullptr), 
	m_Vegetation(nullptr), 
	m_Rain(nullptr),
	m_Terrain(nullptr)
{
	CORE_LOG("*** Initialising world ***");

	// Skybox
	if(!m_Sky && CealumSettings)
	{
		m_Sky = new CSkySystem();
		if(m_Sky)
		{
			if(CealumSettings)
				m_Sky->Initialise(CealumSettings);
			else
				m_Sky->Initialise();
			m_Environments.push_back(m_Sky);
		}
	}

	// Water
	if(!CNatureManager::Instance()->GetWaterSystem() && HydraxSettings)
	{
		auto water = new CWaterSystem();
		if(water)
		{
			if(HydraxSettings)
				water->Initialise(HydraxSettings);
			else
				water->Initialise();
			
			// We don't add it in the environment list, the nature manager will update it, and shut it down.
			CNatureManager::Instance()->SetWaterSystem(water);
		}
	}

	// Terrain
	if(!m_Terrain && TerrainSettings)
	{
		// terrain settings is for either height map or paged terrain
		m_Terrain = new CTerrainSystem();
		m_Terrain->Load(TerrainSettings);
	}

	// Paged geometry
	m_Vegetation = new CVegetationSystem(m_Terrain);
	m_Environments.push_back(m_Vegetation);
}

CWorld::~CWorld()
{
	Shutdown();
}

void CWorld::Shutdown()
{
	try
	{
		CORE_LOG("*** Shutting down world ***");

		// Shut down all subsystems
		for(auto it = m_Environments.begin(); it != m_Environments.end(); it++)
		{
			auto environment = (*it);
			environment->Shutdown();
			CORE_DELETE(environment);
		}
		m_Environments.clear();

		if(m_Terrain)
			m_Terrain->Shutdown();
		CORE_DELETE(m_Terrain);
	}
	catch(std::exception& e)
	{
		CORE_ASSERT(false);
		throw(e);
	}
	catch(...)
	{
		throw("Error in CWorld::Shutdown()");
	}
}

void CWorld::Pause()
{
	for(auto it = m_Environments.cbegin(); it != m_Environments.cend(); it++)
	{
		(*it)->Pause();
	}

	Ogre::ControllerManager::getSingleton().setTimeFactor(0);
	isPaused = true;
}

void CWorld::Resume()
{
	for(auto it = m_Environments.cbegin(); it != m_Environments.cend(); it++)
	{
		(*it)->Resume();
	}

	Ogre::ControllerManager::getSingleton().setTimeFactor(1);
	isPaused = false;
}

void CWorld::Update(const f32& elapsed)
{
	for(auto it = m_Environments.cbegin(); it != m_Environments.cend(); it++)
	{
		(*it)->Update(elapsed);
	}
}

void CWorld::AddPagedGeometry(Core::GEO_SET* GeoSet)
{
	if(m_Vegetation)
		m_Vegetation->AddPagedGeometry(GeoSet);
}