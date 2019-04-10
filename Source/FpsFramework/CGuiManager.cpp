#include "CGuiManager.h"
#include "CCameraManager.h"
#include "CPluginManager.h"
#include "IGuiStrategy.h"

// Default strategy
#include "CGuiStrategy_Default.h"

// Used for the default strategy
#include "Gui3D/Gorilla.h"

// Plugin support
#include "Plugins/IGuiStrategyFactory.h"

#include "IO/CoreLogging.h"

#define DEFAULT_STRATEGY "DEFAULT"

using namespace Core::GUI;

CGuiManager* CGuiManager::GuiManager = nullptr;

CGuiManager* CGuiManager::Instance()
{
	if(GuiManager == nullptr)
		GuiManager = new CGuiManager();
	return GuiManager;
}

CGuiManager::CGuiManager() : m_DefaultStrategy(nullptr)
{
	m_GorillaAtlases[EGA_DEFAULT] = "dejavu";

	// Save our strategies
	m_Factories = CPluginManager::Instance()->GetGuiFactories();
}

CGuiManager::~CGuiManager()
{
	try
	{
		for(auto it = m_Strategies.begin(); it != m_Strategies.end(); it++)
		{
			CORE_DELETE(it->second);
		}
		m_Strategies.clear();
	}
	catch(std::exception& e)
	{
		CORE_ASSERT(false);
		throw(e);
	}
	catch(...)
	{
		throw("Error in ~CGuiManager()");
	}
}

void CGuiManager::SetDefaultStrategy(const char* Name)
{
	if(m_Strategies.find(Name) != m_Strategies.end())
		m_DefaultStrategy = m_Strategies[Name];
}

IGuiStrategy* CGuiManager::CreateStrategy(const char* Name)
{
	IGuiStrategy* strategy = nullptr;

	// Delete the current strategy if one exists
	DeleteStrategy(Name);

	// Is the Name the default strategy?
	if(String(Name) == DEFAULT_STRATEGY)
	{
		// Create the default strategy
		strategy = new CGuiStrategy_Default();
		strategy->Initialize();
		m_Strategies[DEFAULT_STRATEGY] = strategy;

		// Set as the default strategy if one is not set already
		if(!m_DefaultStrategy)
			m_DefaultStrategy = strategy;

		return strategy;
	}

	// Look for the strategy in the loaded plugins
	for(auto it = m_Factories.cbegin(); it != m_Factories.cend(); it++)
	{
		if((*it)->GuiStrategyType == Name)
		{
			strategy = (*it)->CreateStrategy();
			strategy->Initialize();
			m_Strategies[Name] = strategy;

			// Set as the default strategy if one is not set already
			if(!m_DefaultStrategy)
				m_DefaultStrategy = strategy;

			break;
		}
	}

	return strategy;
}

IGuiStrategy* CGuiManager::GetStrategy()
{
	return m_DefaultStrategy;
}

IGuiStrategy* CGuiManager::GetStrategy(const char* Name)
{
	if(m_Strategies.find(Name) != m_Strategies.end())
		return m_Strategies[Name];
	return nullptr;
}

void CGuiManager::DeleteStrategy(const char* Name)
{
	if(m_Strategies.find(Name) != m_Strategies.end())
	{
		IGuiStrategy* strategy = m_Strategies[Name];

		if(m_DefaultStrategy == strategy)
			m_DefaultStrategy = nullptr;

		CORE_DELETE(strategy);
		m_Strategies.erase(Name);
	}

	// Set the default strategy if one is not set
	for(auto it = m_Strategies.cbegin(); it != m_Strategies.cend(); it++)
	{
		m_DefaultStrategy = (*it).second;
	}
}

Gorilla::Silverback* CGuiManager::GetSilverback()
{
	return Gorilla::Silverback::getSingletonPtr();
}

void CGuiManager::LoadAtlas(E_GORILLA_ATLAS Atlas)
{
	auto atlas = m_GorillaAtlases.find(Atlas);
	if(atlas != m_GorillaAtlases.end())
	{
		GetSilverback()->loadAtlas((*atlas).second);
		m_GorillaAtlases.erase(atlas);
	}
}