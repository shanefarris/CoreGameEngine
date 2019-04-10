#include "CWorld.h"
#include "CWaterSystem.h"
#include "CSkySystem.h"
#include "CTerrainSystem.h"
#include "CGameManager.h"
#include "CCameraManager.h"
#include "Structures.h"
#include "IO/CoreLogging.h"

#include "Hydrax/Hydrax.h"
#include <Hydrax/Perlin.h>
#include <Hydrax/ProjectedGrid.h>

using namespace Core::Nature;

CWaterSystem::CWaterSystem()
	: mInitialised(false), 
	mPaused(false), 
	mNode(nullptr), 
	mEntity(nullptr), 
	mSky(nullptr)
{
	EnvironmentType = EET_HYDRAX;
}

CWaterSystem::~CWaterSystem()
{
	Shutdown();
}

void CWaterSystem::Initialise()
{
	// Create hydrax using default values
	CORE_LOG("*** Initialising water ***");

	mInitialised = true;

    // Create Hydrax object
	mHydrax = new Hydrax::Hydrax(CGameManager::Instance()->GetSceneManager(), 
								CCameraManager::Instance()->GetCamera(), 
								CCameraManager::Instance()->GetViewport());

	// Create our projected grid module 
	m_Perlin = new Hydrax::Noise::Perlin();
	m_Module = new Hydrax::Module::ProjectedGrid(// Hydrax parent pointer
			                                    mHydrax,
												// Noise module
			                                    m_Perlin,
												// Base plane
			                                    Ogre::Plane(Ogre::Vector3(0,1,0), Ogre::Vector3(0,0,0)),
												// Normal mode
												Hydrax::MaterialManager::NM_VERTEX,
												// Projected grid options
										        Hydrax::Module::ProjectedGrid::Options(/*Generic one*/));

	// Set our module
	mHydrax->setModule(static_cast<Hydrax::Module::Module*>(m_Module));

	// Load all parameters from config file
	// Remarks: The config file must be in Hydrax resource group.
	// All parameters can be set/updated directly by code(Like previous versions),
	// but due to the high number of customizable parameters, since 0.4 version, Hydrax allows save/load config files.
	mHydrax->loadCfg("Hydrax.hdx");

    // Create water
    mHydrax->create();
	mHydrax->setPosition(Ogre::Vector3(500, 5, 500));

	std::vector<Ogre::RenderQueueGroupID> caelumskyqueue;
	caelumskyqueue.push_back(static_cast<Ogre::RenderQueueGroupID>(Ogre::RENDER_QUEUE_SKIES_EARLY + 2));
	mHydrax->getRttManager()->setDisableReflectionCustomNearCliplPlaneRenderQueues (caelumskyqueue);
}

void CWaterSystem::Initialise(Core::HYDRAX* Settings)
{
	// Create hydrax using default values
	CORE_LOG("*** Initialising water ***");

	mInitialised = true;

    // Create Hydrax object
	mHydrax = new Hydrax::Hydrax(CGameManager::Instance()->GetSceneManager(), CCameraManager::Instance()->GetCamera(), CCameraManager::Instance()->GetViewport());

	// Normal mode
	auto normMode = Hydrax::MaterialManager::NM_RTT;

	// Perlin
	Hydrax::Noise::Perlin::Options perlin;
	perlin.Animspeed = Settings->PerlinAnimSpeed;
	perlin.Falloff = Settings->PerlinFalloff;
	perlin.GPU_LODParameters = Settings->PerlinGpuLod;
	perlin.GPU_Strength = Settings->PerlinGpuStrength;
	perlin.Octaves = Settings->PerlinOctaves;
	perlin.Scale = Settings->PerlinScale;
	perlin.Timemulti = Settings->PerlinTimeMulti;

	// PG options
	Hydrax::Module::ProjectedGrid::Options opt;
	opt.ChoppyStrength = Settings->PgmoduleChoppyStrength;
	opt.ChoppyWaves = true;		// TODO: add data driven
	opt.Complexity = Settings->PgmoduleComplexity;
	opt.Elevation = (f32)Settings->PgmoduleElevation;
	opt.ForceRecalculateGeometry = false;
	opt.Smooth = false;
	opt.Strength = (f32)Settings->PgmoduleStrength;
	
	// setup module
	m_Perlin = new Hydrax::Noise::Perlin(perlin);
	m_Module = new Hydrax::Module::ProjectedGrid(mHydrax,
												m_Perlin,
			                                    Ogre::Plane(Ogre::Vector3(0,1,0), Vector3(0, 0, 0)),
												normMode,
												opt);
	mHydrax->setModule(static_cast<Hydrax::Module::Module*>(m_Module));

	// Set all components for now
	auto comp = Hydrax::HYDRAX_COMPONENTS_ALL;
	mHydrax->setComponents(comp);

	// Caustics
	mHydrax->setCausticsEnd(Settings->CausticsEnd);
	mHydrax->setCausticsPower((f32)Settings->CausticsPower);
	mHydrax->setCausticsScale((f32)Settings->CausticsScale);

	// Foam
	mHydrax->setFoamMaxDistance(Settings->FoamMaxDistance);
	mHydrax->setFoamScale(Settings->FoamScale);
	mHydrax->setFoamStart(Settings->FoamStart);
	mHydrax->setFoamTransparency(Settings->FoamTransparency);

	mHydrax->setWaterColor(Vector3(0.139765f, 0.359464f, 0.425373f));	// TODO
	//mHydrax->setDepthLimit(Settings->DepthLimit);		// TODO
	mHydrax->setDepthLimit(0.0f);
	mHydrax->setFullReflectionDistance(Settings->FullReflectionDistance);
	mHydrax->setGlobalTransparency(Settings->GlobalTransparency);
	mHydrax->setGodRaysExposure(Settings->GodraysExposure);
	mHydrax->setGodRaysIntensity(Settings->GodraysIntensity);
	mHydrax->setNormalDistortion(Settings->NormalDistortion);
	mHydrax->setPlanesError((f32)Settings->PlanesError);
	mHydrax->setPosition(Settings->Position);
	mHydrax->setShaderMode(Hydrax::MaterialManager::SM_CG /*Settings->ShaderMode*/);	// TODO: set to Cg for now
	mHydrax->setSmoothPower(Settings->SmoothPower);
	mHydrax->setSunArea(Settings->SunArea);
	mHydrax->setSunColor(Vector3(1,1,1));		// TODO
	mHydrax->setSunPosition(Settings->SunPosition);
	mHydrax->setSunStrength(Settings->SunStrength);

    // Create water
    mHydrax->create();

	std::vector<Ogre::RenderQueueGroupID> caelumskyqueue;
	caelumskyqueue.push_back(static_cast<Ogre::RenderQueueGroupID>(Ogre::RENDER_QUEUE_SKIES_EARLY + 2));
	mHydrax->getRttManager()->setDisableReflectionCustomNearCliplPlaneRenderQueues (caelumskyqueue);
}

void CWaterSystem::Shutdown()
{
	try
	{
		CORE_LOG("*** Shutting down water ***");

		// TODO: Don't know how to shutdown the hydrax object
		//CORE_DELETE(mHydrax);

		CORE_DELETE(m_Module);

		// Destroy scene node
		if (mNode)
		{
			mNode->detachAllObjects();
			mNode->getParentSceneNode()->removeAndDestroyChild(mNode->getName());
			mNode = nullptr;
		}

		// Destroy mesh and entity
		if (mEntity)
		{
			MeshManager::getSingleton().remove("WaterPlane");
			CGameManager::Instance()->GetSceneManager()->destroyEntity(mEntity);
			mEntity = nullptr;
		}

		mInitialised = false;
	}
	catch(std::exception& e)
	{
		CORE_ASSERT(false);
		throw(e);
	}
	catch(...)
	{
		throw("Error in CWaterSystem::Shutdown()");
	}
}

void CWaterSystem::Pause()
{
	mPaused = true;
}

void CWaterSystem::Resume()
{
	mPaused = false;
}

void CWaterSystem::Update(const f32& elapsed)
{
	// No Update if we're paused
	if (mPaused)
		return;

	// Update Hydrax
	if(mHydrax)
		mHydrax->update(elapsed);

#if 0

	if (mSky && mHydrax &&
		mHydrax->isComponent(Hydrax::HYDRAX_COMPONENT_SUN))
	{
		ColourValue colour;

		// TODO:
		//mHydrax->setSunArea();
		//mHydrax->setSunStrength();
	
		if (mSky->IsNight())
		{
			// Set sun position from the sky system
			mHydrax->setSunPosition(mSky->GetMoonDirection());

			// Set sun color from the sky system
			colour = mSky->GetMoonColour();
			mHydrax->setSunColor(Vector3(colour.r, colour.g, colour.b));

			// Set water colour (prefer the blue component)
			colour = mSky->GetMoonLightColour();
			mHydrax->setWaterColor(Vector3(colour.r, colour.g, colour.b + 0.1));
		}
		else
		{
			// Set sun position from the sky system
			mHydrax->setSunPosition(mSky->GetSunDirection());

			// Set sun color from the sky system
			colour = mSky->GetSunColour();
			mHydrax->setSunColor(Vector3(colour.r, colour.g, colour.b));

			// Set water colour (prefer the blue component)
			mHydrax->setWaterColor(Vector3(colour.r, colour.g, colour.b + 0.1));
		}
	}
	
#endif
	
}

void CWaterSystem::Save(const String& stage)
{
}
