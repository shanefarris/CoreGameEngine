#include "CSkySystem.h"
#include "CWorld.h"
#include "CGameManager.h"
#include "CCameraManager.h"
#include "Structures.h"
#include "IO/CoreLogging.h"

#include "Caelum/Caelum.h"

using namespace Core::Nature;

CSkySystem::CSkySystem() : m_CaelumSystem(nullptr), mSpeedFactor(25), mPaused(false)
{
	EnvironmentType = EET_SKY;
}

CSkySystem::~CSkySystem()
{
	// Always perform Shutdown
	Shutdown();
}

void CSkySystem::Initialise()
{
	CORE_LOG("*** Initialising sky ***");

	// Some stuff from graphics manager
	auto sceneManager = CGameManager::Instance()->GetSceneManager();
	auto viewport = CCameraManager::Instance()->GetViewport();

	// Create Caelum system
	Caelum::CaelumSystem::CaelumComponent   componentMask = static_cast<Caelum::CaelumSystem::CaelumComponent> (	
		Caelum::CaelumSystem::CAELUM_COMPONENT_SUN |
		Caelum::CaelumSystem::CAELUM_COMPONENT_MOON |
		Caelum::CaelumSystem::CAELUM_COMPONENT_SKY_DOME |
		//Caelum::CaelumSystem::CAELUM_COMPONENT_IMAGE_STARFIELD |
		Caelum::CaelumSystem::CAELUM_COMPONENT_POINT_STARFIELD |
		Caelum::CaelumSystem::CAELUM_COMPONENT_CLOUDS |
		0);
	m_CaelumSystem = new Caelum::CaelumSystem(CGameManager::Instance()->GetEngineDevice(), sceneManager, componentMask);

	// Attach Caelum to the viewport
	m_CaelumSystem->attachViewport(viewport);

	// Manage ambient light
	m_CaelumSystem->setManageAmbientLight(true);
	m_CaelumSystem->setMinimumAmbientLight(ColourValue(.2f, .2f, .2f));
	m_CaelumSystem->getSun()->setAmbientMultiplier(ColourValue(0, 0, 0));
	m_CaelumSystem->getSun()->setDiffuseMultiplier(ColourValue(0, 0, 0));

	// Manage scene fog
	m_CaelumSystem->setManageSceneFog(false);

	// Set universal clock scale
	m_CaelumSystem->getUniversalClock()->setTimeScale(mSpeedFactor);

	// Set universal clock to a specific date, midnight for the moment
	m_CaelumSystem->getUniversalClock()->setGregorianDateTime(2008, 5, 27, 12, 10, 05);

	// Add Caelum as RenderTargerListener to let it track camera changes
	CGameManager::Instance()->GetRenderWindow()->addListener(m_CaelumSystem);
}

void CSkySystem::Initialise(Core::CAELUM* CealumSettings)
{
	CORE_LOG("*** Initialising sky ***");

	// Some stuff from graphics manager
	auto sceneManager = CGameManager::Instance()->GetSceneManager();
	auto viewport = CCameraManager::Instance()->GetViewport();

	// Create Caelum system
	Caelum::CaelumSystem::CaelumComponent   componentMask = static_cast<Caelum::CaelumSystem::CaelumComponent> (	
		Caelum::CaelumSystem::CAELUM_COMPONENT_SUN |
		Caelum::CaelumSystem::CAELUM_COMPONENT_MOON |
		Caelum::CaelumSystem::CAELUM_COMPONENT_SKY_DOME |
		Caelum::CaelumSystem::CAELUM_COMPONENT_POINT_STARFIELD |
		Caelum::CaelumSystem::CAELUM_COMPONENT_CLOUDS |
		0);
	m_CaelumSystem = new Caelum::CaelumSystem(CGameManager::Instance()->GetEngineDevice(), sceneManager, componentMask);

	// Attach Caelum to the viewport
	m_CaelumSystem->attachViewport(viewport);

	// Set universal clock to a specific date, midnight for the moment
	//auto universalClock = m_CaelumSystem->getUniversalClock();
	//if(universalClock)
	//{
	//	universalClock->setGregorianDateTime(
	//		CealumSettings->TimeYear, 
	//		CealumSettings->TimeMonth, 
	//		CealumSettings->TimeDay, 
	//		CealumSettings->TimeHour, 
	//		CealumSettings->TimeMinute, 
	//		CealumSettings->TimeSec);
	//}

	// Minimum ambient light
	m_CaelumSystem->setMinimumAmbientLight(CealumSettings->MinAmbientLight);

	// Fog density multiplier
	m_CaelumSystem->setSceneFogDensityMultiplier((f32)CealumSettings->FogDenMultiplier);
	//sky->setGlobalFogDensityMultiplier

	// Manage scene fog
	m_CaelumSystem->setManageSceneFog(false);

	// Sun options
	Caelum::BaseSkyLight* sun = m_CaelumSystem->getSun();
	if (sun)
	{
		sun->setAmbientMultiplier(CealumSettings->SunAmbientMultipler);
		sun->setDiffuseMultiplier(CealumSettings->SunDiffuseMultipler);
		sun->setSpecularMultiplier(CealumSettings->SunSpecularMultipler);
	}

	// Moon options
	Caelum::Moon* moon = m_CaelumSystem->getMoon();
	if (moon)
	{
		//moon->setPhase(StringConverter::parseReal
		moon->setAmbientMultiplier(CealumSettings->MoonAmbientMultipler);
		moon->setDiffuseMultiplier(CealumSettings->MoonDiffuseMultipler);
		moon->setSpecularMultiplier(CealumSettings->MoonSpecularMultipler);
	}

	// Starfield observer position
	Caelum::PointStarfield* starfield = m_CaelumSystem->getPointStarfield();
	if (starfield)
	{
		starfield->setMagnitudeScale(CealumSettings->StarsMagScale);
		starfield->setMag0PixelSize((f32)CealumSettings->StarsMag0PixelSize);
		starfield->setMinPixelSize((f32)CealumSettings->StarsMinPixelSize);
		starfield->setMaxPixelSize((f32)CealumSettings->StarsMaxPixelSize);
		starfield->setObserverLatitude(Degree((f32)CealumSettings->ObserverLatitude));
		starfield->setObserverLongitude(Degree((f32)CealumSettings->ObserverLongitude));
	}

	// Skydome options
	Caelum::SkyDome* skydome = m_CaelumSystem->getSkyDome();
	if (skydome)
	{
		skydome->setHazeEnabled(false);
	}
}

void CSkySystem::Shutdown()
{
	try
	{
		CORE_LOG("*** Shutting down sky ***");

		// Remove Caelum as RenderTargetListener
		CGameManager::Instance()->GetRenderWindow()->removeListener(m_CaelumSystem);

		// We don't need to perform Shutdown if Caelum is not initialised
		if (!m_CaelumSystem)
			return;

		// Drop CRainSystem as a Caelum precipitation controller
		//m_CaelumSystem->setPrecipitationController(nullptr);
		//CORE_DELETE(mController);

		// Shutdown Caelum
		m_CaelumSystem->shutdown(false);

		// Free memory
		CORE_DELETE(m_CaelumSystem);
		m_CaelumSystem = nullptr;
	}
	catch(std::exception& e)
	{
		CORE_ASSERT(false);
		throw(e);
	}
	catch(...)
	{
		throw("Error in CSkySystem::Shutdown()");
	}
}

bool CSkySystem::IsInitialised() const
{
	return (m_CaelumSystem != nullptr);
}

void CSkySystem::Pause()
{
	mPaused = true;
}

void CSkySystem::Resume()
{
	mPaused = false;
}

void CSkySystem::Update(const f32& elapsed)
{
	// Can't continue if we're not initialised
	if (!m_CaelumSystem)
		return;

	// Pause or Resume sky
	//m_CaelumSystem->getUniversalClock()->setTimeScale(mPaused ? 0 : mSpeedFactor);

	// If not paused Update sky
	if (!mPaused)
	{
		m_CaelumSystem->notifyCameraChanged(CCameraManager::Instance()->GetCamera());
		//m_CaelumSystem->updateSubcomponents(elapsed);
	}
}

void CSkySystem::CameraChanged()
{
	// Can't continue if we're not initialised
	if (!m_CaelumSystem)
		return;

	// If not paused notify camera changes
	if (!mPaused)
		m_CaelumSystem->notifyCameraChanged(CCameraManager::Instance()->GetCamera());
}

bool CSkySystem::IsNight() const
{
	return (CGameManager::Instance()->GetSceneManager()->getAmbientLight().r <= 0.15);
}

Vector3 CSkySystem::GetSunDirection() const
{
	if (!m_CaelumSystem)
		return Vector3::ZERO;
	if (!m_CaelumSystem->getSun())
		return Vector3::ZERO;

	return CCameraManager::Instance()->GetCamera()->getPosition() - (m_CaelumSystem->getSun()->getLightDirection() * 100000);
}

ColourValue CSkySystem::GetSunColour() const
{
	if (!m_CaelumSystem)
		return ColourValue::ZERO;
	if (!m_CaelumSystem->getSun())
		return ColourValue::ZERO;

	return m_CaelumSystem->getSun()->getLightColour();
}

ColourValue CSkySystem::GetSunLightColour() const
{
	Caelum::LongReal julian = m_CaelumSystem->getUniversalClock()->getJulianDay();
	return m_CaelumSystem->getSunLightColour((f32)julian, m_CaelumSystem->getSunDirection(julian));
}

Vector3 CSkySystem::GetMoonDirection() const
{
	if (!m_CaelumSystem)
		return Vector3::ZERO;
	if (!m_CaelumSystem->getMoon())
		return Vector3::ZERO;
	return CCameraManager::Instance()->GetCamera()->getPosition() - (m_CaelumSystem->getMoon()->getLightDirection() * 100000);
}

ColourValue CSkySystem::GetMoonColour() const
{
	if (!m_CaelumSystem)
		return ColourValue::ZERO;
	if (!m_CaelumSystem->getMoon())
		return ColourValue::ZERO;
	return m_CaelumSystem->getMoon()->getLightColour();
}

ColourValue CSkySystem::GetMoonLightColour() const
{
	Caelum::LongReal julian = m_CaelumSystem->getUniversalClock()->getJulianDay();
	return m_CaelumSystem->getMoonLightColour(m_CaelumSystem->getMoonDirection(julian));
}
