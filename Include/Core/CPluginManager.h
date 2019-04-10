#ifndef __CPLUGINMANAGER_H__
#define __CPLUGINMANAGER_H__

#include "Defines.h"

#if defined(_WIN32)
#include "Windows.h"
#define LIB_INSTANCE HINSTANCE&
#else
#define LIB_INSTANCE 
#endif

namespace Core
{
	namespace Plugin
	{
		class IConsoleParser;
		class IGameObjectFactory;
		class IMissionFactory;
		class IAiStateFactory;
		class IPlayerFactory;
		class IBuildingFactory;
		class IParticleFactory;
		class ICameraFactory;
		class IPostEffectFactory;
		class IPhysicsStrategyFactory;
		class INetworkingFactory;
		class IGuiStrategyFactory;
	}

	class CORE_EXPORT CPluginManager
	{
	private:
		CPluginManager();

		void LoadPlugins();
		void LoadGameObject(LIB_INSTANCE hMod);
		void LoadConsole(LIB_INSTANCE hMod);
		void LoadMission(LIB_INSTANCE hMod);
		void LoadAiState(LIB_INSTANCE hMod);
		void LoadPlayer(LIB_INSTANCE hMod);
		void LoadBuilding(LIB_INSTANCE hMod);
		void LoadParticle(LIB_INSTANCE hMod);
		void LoadCamera(LIB_INSTANCE hMod);
		void LoadPostEffect(LIB_INSTANCE hMod);
		void LoadPhysics(LIB_INSTANCE hMod);
		void LoadNetwork(LIB_INSTANCE hMod);
		void LoadGui(LIB_INSTANCE hMod);

		static CPluginManager* PluginManager;

		// Plugin lists
		Vector<Plugin::IGameObjectFactory*>			m_GameObjectFactories;
		Vector<Plugin::IConsoleParser*>				m_ConsoleFactories;
		Vector<Plugin::IMissionFactory*>			m_MissionFactories;
		Vector<Plugin::IAiStateFactory*>			m_AiStateFactories;
		Vector<Plugin::IPlayerFactory*>				m_PlayerFactories;
		Vector<Plugin::IBuildingFactory*>			m_BuildingFactories;
		Vector<Plugin::IParticleFactory*>			m_ParticleFactories;
		Vector<Plugin::ICameraFactory*>				m_CameraFactories;
		Vector<Plugin::IPostEffectFactory*>			m_PostEffectFactories;
		Vector<Plugin::IPhysicsStrategyFactory*>	m_PhysicsFactories;
		Vector<Plugin::INetworkingFactory*>			m_NetworkingFactories;
		Vector<Plugin::IGuiStrategyFactory*>		m_GuiFactories;

	public:
		static CPluginManager* Instance();
		~CPluginManager();

		bool LoadPlugin(const char* FileName);

		inline Vector<Plugin::IGameObjectFactory*>&		 GetGameObjectFactories();
		inline Vector<Plugin::IConsoleParser*>&			 GetConsoleFactories();
		inline Vector<Plugin::IMissionFactory*>&		 GetMissionFactories();
		inline Vector<Plugin::IAiStateFactory*>&		 GetAiStateFactories();
		inline Vector<Plugin::IPlayerFactory*>&			 GetPlayerFactories();
		inline Vector<Plugin::IBuildingFactory*>&		 GetBuildingFactories();
		inline Vector<Plugin::IParticleFactory*>&		 GetParticleFactories();
		inline Vector<Plugin::ICameraFactory*>&			 GetCameraFactories();
		inline Vector<Plugin::IPostEffectFactory*>&		 GetPostEffectFactories();
		inline Vector<Plugin::IPhysicsStrategyFactory*>& GetPhysicsFactoryies();
		inline Vector<Plugin::INetworkingFactory*>&		 GetNetworkingFactories();
		inline Vector<Plugin::IGuiStrategyFactory*>&	 GetGuiFactories();

	};
}

#endif // __CPLUGINMANAGER_H__