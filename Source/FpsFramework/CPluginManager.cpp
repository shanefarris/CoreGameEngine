#include "CPluginManager.h"
#include "CConfiguration.h"
#include "CUtility.h"
#include "IO/CoreLogging.h"

// Plugins
#include "Plugins\PluginTypes.h"
#include "Plugins\IGameObjectFactory.h"
#include "Plugins\IConsoleParser.h"
#include "Plugins\IMissionFactory.h"
#include "Plugins\IAiStateFactory.h"
#include "Plugins\IPlayerFactory.h"
#include "Plugins\IBuildingFactory.h"
#include "Plugins\IParticleFactory.h"
#include "Plugins\ICameraFactory.h"
#include "Plugins\IPostEffectFactory.h"
#include "Plugins\IPhysicsStrategyFactory.h"
#include "Plugins\INetworkingFactory.h"
#include "Plugins\IGuiStrategyFactory.h"

// Ogre
#include "OgreStringConverter.h"

#if defined(_WIN32)
#define CALL_ENTRYPOINT GetProcAddress
#else
#define CALL_ENTRYPOINT
#endif

using namespace Core;
using namespace Core::Plugin;

#define GET_FUNC "GetFactories"

typedef E_PLUGIN		(*PluginTypeFunc)();
typedef IConsoleParser* (*GetConsoleParserFunc)();
typedef void			(*GetGameObjectFactoriesFunc)(Vector<IGameObjectFactory*>&);
typedef void			(*GetMissionFactoriesFunc)(Vector<IMissionFactory*>&);
typedef void			(*GetAiStateFactoriesFunc)(Vector<IAiStateFactory*>&);
typedef void			(*GetPlayerFactoriesFunc)(Vector<IPlayerFactory*>&);
typedef void			(*GetBuildingFactoriesFunc)(Vector<IBuildingFactory*>&);
typedef void			(*GetParticleFactoriesFunc)(Vector<IParticleFactory*>&);
typedef void			(*GetCameraFactoriesFunc)(Vector<ICameraFactory*>&);
typedef void			(*GetPostEffectFactoriesFunc)(Vector<IPostEffectFactory*>&);
typedef void			(*GetPhysicsStrategyFactoriesFunc)(Vector<IPhysicsStrategyFactory*>&);
typedef void			(*GetNetworkStrategyFactoriesFunc)(Vector<INetworkingFactory*>&);
typedef void			(*GetGuiStrategyFactoriesFunc)(Vector<IGuiStrategyFactory*>&);

CPluginManager* CPluginManager::PluginManager = nullptr;

CPluginManager* CPluginManager::Instance()
{
	if(PluginManager == nullptr)
		PluginManager = new CPluginManager();
	return PluginManager;
}

CPluginManager::CPluginManager() 
{
	LoadPlugins();
}

CPluginManager::~CPluginManager()
{
	try
	{
		// Remove all plugins
		for(auto it = m_GameObjectFactories.begin(); it != m_GameObjectFactories.end(); it ++)
			CORE_DELETE((*it));

		// Console Parsers
		for(auto it = m_ConsoleFactories.begin(); it != m_ConsoleFactories.end(); it ++)
			CORE_DELETE((*it));

		for(auto it = m_MissionFactories.begin(); it != m_MissionFactories.end(); it ++)
			CORE_DELETE((*it));

		for(auto it = m_AiStateFactories.begin(); it != m_AiStateFactories.end(); it ++)
			CORE_DELETE((*it));

		for(auto it = m_PlayerFactories.begin(); it != m_PlayerFactories.end(); it ++)
			CORE_DELETE((*it));

		for(auto it = m_BuildingFactories.begin(); it != m_BuildingFactories.end(); it ++)
			CORE_DELETE((*it));

		for(auto it = m_ParticleFactories.begin(); it != m_ParticleFactories.end(); it ++)
			CORE_DELETE((*it));

		for(auto it = m_CameraFactories.begin(); it != m_CameraFactories.end(); it ++)
			CORE_DELETE((*it));

		for(auto it = m_PostEffectFactories.begin(); it != m_PostEffectFactories.end(); it ++)
			CORE_DELETE((*it));

		for(auto it = m_PhysicsFactories.begin(); it != m_PhysicsFactories.end(); it ++)
			CORE_DELETE((*it));

		for(auto it = m_NetworkingFactories.begin(); it != m_NetworkingFactories.end(); it ++)
			CORE_DELETE((*it));

		for(auto it = m_GuiFactories.begin(); it != m_GuiFactories.end(); it ++)
			CORE_DELETE((*it));
	}
	catch(std::exception& e)
	{
		CORE_ASSERT(false);
		throw(e);
	}
	catch(...)
	{
		throw("Error in ~CPluginManager()");
	}
}

bool CPluginManager::LoadPlugin(const char* FileName)
{
	String msg = "*** Loading core plugin " + String(FileName) + " ***";
	CORE_LOG(msg.c_str());

	PluginTypeFunc _PluginTypeFunc;

#if defined(_WIN32)
	auto hMod = LoadLibrary (FileName);

	if(!hMod)
	{
		DWORD dw = GetLastError(); 
		String err = "LoadLibrary failed for: ";
		err += FileName;
		err += " error code : ";
		err += StringConverter::toString(dw);
		CORE_ERR(err.c_str());
		return false;
	}

#else
	throw("CPluginManager::LoadPlugin not implemented for this OS");
#endif

	_PluginTypeFunc = (PluginTypeFunc)CALL_ENTRYPOINT(hMod, "GetPluginType");

	if(_PluginTypeFunc)
	{
		E_PLUGIN type = _PluginTypeFunc();
		switch(type)
		{
		case EP_OBJECT_FACTORY:
			LoadGameObject(hMod);
			break;
		case EP_CONSOLE:
			LoadConsole(hMod);
			break;
		case EP_MISSION:
			LoadMission(hMod);
			break;
		case EP_AI_STATE:
			LoadAiState(hMod);
			break;
		case EP_PLAYER:
			LoadPlayer(hMod);
			break;
		case EP_BUILDING:
			LoadBuilding(hMod);
			break;
		case EP_PARTICLE:
			LoadParticle(hMod);
			break;
		case EP_CAMERA:
			LoadCamera(hMod);
			break;
		case EP_POSTEFFECT:
			LoadPostEffect(hMod);
			break;
		case EP_PHYSICSSTRATEGY:
			LoadPhysics(hMod);
			break;
		case EP_NETWORKING:
			LoadNetwork(hMod);
			break;
		case EP_GUISTRATEGY:
			LoadGui(hMod);
			break;
		default:
			msg = "*** could not load plugin: " + String(FileName);
			CORE_ERR(msg.c_str());
			return false;
		}
	}
	else
	{
		return false;
	}

	return true;
}

void CPluginManager::LoadPlugins()
{
#if _DEBUG
	Vector<String> paths;
	paths.push_back("../../Bin/Debug/Plugins");
#else
	Vector<String> paths = CConfiguration::Instance()->PluginPaths;
#endif

	// Search each directory
	for(u32 i = 0; i < paths.size(); i++)
	{
		Vector<String> files;
		CUtility::SearchDirectory(files, paths[i], "dll", false);

		// Load all dll's found in the directory
		for(u32 j = 0; j < files.size(); j++)
		{
			if(!LoadPlugin(files[j].c_str()))
			{
				CORE_LOG(String("Unable to load plugin: " + files[j]).c_str());
			}
		}
	}
}

void CPluginManager::LoadGameObject(LIB_INSTANCE hMod)
{
	auto func = (GetGameObjectFactoriesFunc)CALL_ENTRYPOINT(hMod, GET_FUNC);
	if(func)
	{
		func(m_GameObjectFactories);
	}
}

void CPluginManager::LoadConsole(LIB_INSTANCE hMod)
{
	auto func = (GetConsoleParserFunc)CALL_ENTRYPOINT(hMod, GET_FUNC);
	if(func)
	{
		IConsoleParser* parser = func();
		if(parser)
			m_ConsoleFactories.push_back(parser);
	}
}

void CPluginManager::LoadMission(LIB_INSTANCE hMod)
{
	auto func = (GetMissionFactoriesFunc)CALL_ENTRYPOINT(hMod, GET_FUNC);
	if(func)
	{
		func(m_MissionFactories);
	}
}

void CPluginManager::LoadAiState(LIB_INSTANCE hMod)
{
	auto func = (GetAiStateFactoriesFunc)CALL_ENTRYPOINT(hMod, GET_FUNC);
	if(func)
	{
		func(m_AiStateFactories);
	}
}

void CPluginManager::LoadPlayer(LIB_INSTANCE hMod)
{
	auto func = (GetPlayerFactoriesFunc)CALL_ENTRYPOINT(hMod, GET_FUNC);
	if(func)
	{
		func(m_PlayerFactories);
	}
}

void CPluginManager::LoadBuilding(LIB_INSTANCE hMod)
{
	auto func = (GetBuildingFactoriesFunc)CALL_ENTRYPOINT(hMod, GET_FUNC);
	if(func)
	{
		func(m_BuildingFactories);
	}
}

void CPluginManager::LoadParticle(LIB_INSTANCE hMod)
{
	auto func = (GetParticleFactoriesFunc)CALL_ENTRYPOINT(hMod, GET_FUNC);
	if(func)
	{
		func(m_ParticleFactories);
	}
}

void CPluginManager::LoadCamera(LIB_INSTANCE hMod)
{
	auto func = (GetCameraFactoriesFunc)CALL_ENTRYPOINT(hMod, GET_FUNC);
	if(func)
	{
		func(m_CameraFactories);
	}
}

void CPluginManager::LoadPostEffect(LIB_INSTANCE hMod)
{
	auto func = (GetPostEffectFactoriesFunc)CALL_ENTRYPOINT(hMod, GET_FUNC);
	if(func)
	{
		func(m_PostEffectFactories);
	}
}

void CPluginManager::LoadPhysics(LIB_INSTANCE hMod)
{
	auto func = (GetPhysicsStrategyFactoriesFunc)CALL_ENTRYPOINT(hMod, GET_FUNC);
	if(func)
	{
		func(m_PhysicsFactories);
	}
}

void CPluginManager::LoadNetwork(LIB_INSTANCE hMod)
{
	auto func = (GetNetworkStrategyFactoriesFunc)CALL_ENTRYPOINT(hMod, GET_FUNC);
	if(func)
	{
		func(m_NetworkingFactories);
	}
}

void CPluginManager::LoadGui(LIB_INSTANCE hMod)
{
	auto func = (GetGuiStrategyFactoriesFunc)CALL_ENTRYPOINT(hMod, GET_FUNC);
	if(func)
	{
		func(m_GuiFactories);
	}
}

Vector<Core::Plugin::IGameObjectFactory*>& CPluginManager::GetGameObjectFactories()
{
	return m_GameObjectFactories;
}

Vector<Core::Plugin::IConsoleParser*>& CPluginManager::GetConsoleFactories()
{
	return m_ConsoleFactories;
}

Vector<Core::Plugin::IMissionFactory*>& CPluginManager::GetMissionFactories()
{
	return m_MissionFactories;
}

Vector<Core::Plugin::IAiStateFactory*>& CPluginManager::GetAiStateFactories()
{
	return m_AiStateFactories;
}

Vector<Core::Plugin::IPlayerFactory*>& CPluginManager::GetPlayerFactories()
{
	return m_PlayerFactories;
}

Vector<Core::Plugin::IBuildingFactory*>& CPluginManager::GetBuildingFactories()
{
	return m_BuildingFactories;
}

Vector<Core::Plugin::IParticleFactory*>& CPluginManager::GetParticleFactories()
{
	return m_ParticleFactories;
}

Vector<Core::Plugin::ICameraFactory*>& CPluginManager::GetCameraFactories()
{
	return m_CameraFactories;
}

Vector<Core::Plugin::IPostEffectFactory*>& CPluginManager::GetPostEffectFactories()
{
	return m_PostEffectFactories;
}

Vector<Core::Plugin::IPhysicsStrategyFactory*>& CPluginManager::GetPhysicsFactoryies()
{
	return m_PhysicsFactories;
}

Vector<Core::Plugin::INetworkingFactory*>& CPluginManager::GetNetworkingFactories()
{
	return m_NetworkingFactories;
}

Vector<Core::Plugin::IGuiStrategyFactory*>& CPluginManager::GetGuiFactories()
{
	return m_GuiFactories;
}