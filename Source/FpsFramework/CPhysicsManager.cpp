#include "CPhysicsManager.h"
#include "IPhysicsStrategy.h"
#include "CPhysicsProfile.h"
#include "CPluginManager.h"
#include "IO/CoreLogging.h"

#include "Plugins\IPhysicsStrategyFactory.h"

using namespace Core::Physics;

CPhysicsManager* CPhysicsManager::PhysicsManager = nullptr;
const char* CPhysicsManager::DEFAULT_LIGHT_CUBE = "DEFAULT_LIGHT_CUBE";
const char* CPhysicsManager::DEFAULT_MEDIUM_CUBE = "DEFAULT_MEDIUM_CUBE";
const char* CPhysicsManager::DEFAULT_HEAVY_CUBE = "DEFAULT_HEAVY_CUBE";
const char* CPhysicsManager::DEFAULT_LIGHT_SPHERE = "DEFAULT_LIGHT_SPHERE";
const char* CPhysicsManager::DEFAULT_MEDIUM_SPHERE = "DEFAULT_MEDIUM_SPHERE";
const char* CPhysicsManager::DEFAULT_HEAVY_SPHERE = "DEFAULT_HEAVY_SPHERE";

CPhysicsManager* CPhysicsManager::Instance()
{
	if(PhysicsManager == nullptr)
		PhysicsManager = new CPhysicsManager();
	return PhysicsManager;
}

CPhysicsManager::CPhysicsManager() : m_CurrStrategy(nullptr)
{
	String name;

	// Default cubes
	auto lightCube = new CPhysicsProfile();
	lightCube->SetMass(1.0f);
	lightCube->SetDensity(0.1f);
	lightCube->SetFriction(10.0f);
	lightCube->SetBodyType(NONE);
	lightCube->SetShape(SHAPE_CUBE);
	lightCube->SetSize(DEFAULT_PROFILE_SIZE);
	name = String(DEFAULT_LIGHT_CUBE);
	m_PhysicsProfiles[name] = lightCube;

	auto mediumCube = new CPhysicsProfile();
	mediumCube->SetMass(50.0f);
	mediumCube->SetDensity(1.0f);
	mediumCube->SetFriction(10.0f);
	mediumCube->SetBodyType(NONE);
	mediumCube->SetShape(SHAPE_CUBE);
	mediumCube->SetSize(DEFAULT_PROFILE_SIZE);
	name = String(DEFAULT_MEDIUM_CUBE);
	m_PhysicsProfiles[name] = mediumCube;

	auto heavyCube = new CPhysicsProfile();
	heavyCube->SetMass(500.0f);
	heavyCube->SetDensity(1.0f);
	heavyCube->SetFriction(10.0f);
	heavyCube->SetBodyType(NONE);
	heavyCube->SetShape(SHAPE_CUBE);
	heavyCube->SetSize(DEFAULT_PROFILE_SIZE);
	name = String(DEFAULT_HEAVY_CUBE);
	m_PhysicsProfiles[name] = heavyCube;

	// Default spheres
	auto lightSphere = new CPhysicsProfile();
	lightSphere->SetMass(1.0f);
	lightSphere->SetDensity(0.1f);
	lightSphere->SetFriction(10.0f);
	lightSphere->SetBodyType(NONE);
	lightSphere->SetShape(SHAPE_SPHERE);
	lightSphere->SetRadius(DEFAULT_PROFILE_RADIUS);
	name = String(DEFAULT_LIGHT_SPHERE);
	m_PhysicsProfiles[name] = lightSphere;

	auto mediumSphere = new CPhysicsProfile();
	mediumSphere->SetMass(50.0f);
	mediumSphere->SetDensity(1.0f);
	mediumSphere->SetFriction(10.0f);
	mediumSphere->SetBodyType(NONE);
	mediumSphere->SetShape(SHAPE_SPHERE);
	mediumSphere->SetRadius(DEFAULT_PROFILE_RADIUS);
	name = String(DEFAULT_MEDIUM_SPHERE);
	m_PhysicsProfiles[name] = mediumSphere;

	auto heavySphere = new CPhysicsProfile();
	heavySphere->SetMass(500.0f);
	heavySphere->SetDensity(1.0f);
	heavySphere->SetFriction(10.0f);
	heavySphere->SetBodyType(NONE);
	heavySphere->SetShape(SHAPE_SPHERE);
	heavySphere->SetRadius(DEFAULT_PROFILE_RADIUS);
	name = String(DEFAULT_HEAVY_SPHERE);
	m_PhysicsProfiles[name] = heavySphere;

	// Save our strategies
	m_Strategies = CPluginManager::Instance()->GetPhysicsFactoryies();
}

CPhysicsManager::~CPhysicsManager()
{
	try
	{
		// Remove profiles
		for(auto it = m_PhysicsProfiles.begin(); it != m_PhysicsProfiles.end(); it ++)
		{
			CORE_DELETE(it->second);
		}

		CORE_DELETE(m_CurrStrategy);
	}
	catch(std::exception& e)
	{
		CORE_ASSERT(false);
		throw(e);
	}
	catch(...)
	{
		throw("Error in ~CMissionManager()");
	}
}

IPhysicsStrategy* CPhysicsManager::CreateStrategy(const char* Label)
{
	// Delete the current strategy if one exists
	DeleteStrategy();

	for(auto it = m_Strategies.cbegin(); it != m_Strategies.cend(); it++)
	{
		if((*it)->Label == Label)
		{
			m_CurrStrategy = (*it)->GetStrategy();
		}
	}

	return m_CurrStrategy;
}

IPhysicsStrategy* CPhysicsManager::GetStrategy() const
{
	return m_CurrStrategy;
}

void CPhysicsManager::DeleteStrategy()
{
	CORE_DELETE(m_CurrStrategy);
}

void CPhysicsManager::Update(const f32& elapsedTime) const
{
	if(m_CurrStrategy)
		m_CurrStrategy->Update(elapsedTime);
}

void CPhysicsManager::AddPhysicsProfile(const char* ProfileName, CPhysicsProfile* Profile)
{
	String name = ProfileName;
	if(m_PhysicsProfiles.find(name) == m_PhysicsProfiles.end())
	{
		m_PhysicsProfiles[name] = Profile;
	}
}

void CPhysicsManager::GetPhysicsProfileList(PhysicsProfileList& ProfileList) const
{
	ProfileList = m_PhysicsProfiles;
}

CPhysicsProfile* CPhysicsManager::GetPhysicsProfile(const char* ProfileName) const
{
	String name = ProfileName;
	for(auto it = m_PhysicsProfiles.cbegin(); it != m_PhysicsProfiles.cend(); it++)
	{
		if((*it).first == name)
			return (*it).second;
	}
	return nullptr;
	
}