#include "CGameManager.h"
#include "CGame.h"
#include "CCameraManager.h"
#include "CEffectsManager.h"
#include "CItemsManager.h"
#include "CGameObjectManager.h"
#include "Audio/CSoundManager.h"
#include "Audio/CListener.h"
#include "CBillboardManager.h"
#include "CPhysicsManager.h"
#include "IPhysicsStrategy.h"
#include "CNatureManager.h"
#include "CConfiguration.h"
#include "CSerializer.h"
#include "CSceneImporter.h"
#include "ICamera.h"
#include "IO/CFileSystem.h"
#include "Terrain/OgreTerrainGroup.h"

#include "IO/CoreLogging.h"

#include "RTShaderSystem/OgreRTShaderSystem.h"
#include "OgreRoot.h"
#include "OgreGpuProgramManager.h"
#include "OgreMaterialManager.h"
#include "OgreAnimation.h"
#include "OgreOverlayManager.h"
#include "OgreOverlaySystem.h"

// Setup compilation options
#include "CompilerConfig.h"

#ifdef COMPILE_EFFECT_FIRE
#include "Effects/Fire/OgreShaderParticleRenderer.h"
#include "Effects/Fire/OgreBoxEmitterFactory.h"
#endif

using namespace Core;
using namespace Core::Physics;

CGameManager* CGameManager::GameManager = nullptr;

CGameManager* CGameManager::Instance()
{
	if(GameManager == nullptr)
		GameManager = new CGameManager();
	return GameManager;
}

CGameManager::CGameManager() 
	: m_EngineDevice(nullptr), 
	m_SceneManager(nullptr), 
	m_RenderWindow(nullptr),
	m_GameObjectManager(nullptr), 
	m_CameraManager(nullptr), 
	m_ItemsManager(nullptr), 
	m_NatureManager(nullptr), 
	m_EffectsManager(nullptr), 
	m_BillboardManager(nullptr),
	m_SceneImporter(nullptr),
	m_PhysicsManager(nullptr),
	m_Game(nullptr)
{
	m_Timer = new Timer();
	isShouldQuit = false;
	isConsoleOpened = false;
	Initialize();
}

CGameManager::~CGameManager()
{
	Shutdown();
}

void CGameManager::Initialize()
{
	Configuration = CConfiguration::Instance();
	Configuration->LoadConfig(false);
	m_SceneImporter = new CSceneImporter();
	InitializeEngine();
}

void CGameManager::InitializeEngine()
{
#if 0
	auto logManager = new LogManager();
	logManager->createLog("./", true, false, false);
#endif
	m_EngineDevice = new EngineDevice("", "");

	if(Configuration)
	{
		// Set our default base resource names
		m_BaseResourceName = Configuration->BaseResourceName;
		m_BaseAudioResourceName = Configuration->BaseAudioResourceName;

		//// Set default shader language
		//RTShader::ShaderGenerator::initialize();
		//Ogre::RTShader::ShaderGenerator::getSingletonPtr()->setTargetLanguage("cg");

		// Get directory list
		for(u16 i = 0; i < Configuration->FolderList.size(); i++)
		{
			ResourceGroupManager::getSingleton().addResourceLocation(
				Configuration->FolderList[i].Name.c_str(),	
				"FileSystem",	
				Configuration->FolderList[i].Group.c_str());
		}

		// Load zips
		// Get directory list
		for(u16 i = 0; i < Configuration->ZipList.size(); i++)
		{
			const char* fileName = Configuration->ZipList[i].Name.c_str();
			const char* group = Configuration->ZipList[i].Group.c_str();
			if(IO::CFileSystem::IsFileExist(fileName))
			{
				if(!ResourceGroupManager::getSingleton().resourceGroupExists(group))
					ResourceGroupManager::getSingleton().createResourceGroup(group);
				ResourceGroupManager::getSingleton().addResourceLocation(fileName, "Zip", group, true);
			}
		}
	}
	// This should not happen, but load defaults anyway
	else
	{
		CORE_THROW("Unable to find configuration", "CGameManager::InitializeEngine");
	}

	// Get the default database name and directory
	m_DefaultDatabaseName = Configuration->DatabaseLocation + "/" + Configuration->DefaultDatabaseName;

	// These plugins need to be in a specific order :(
	m_EngineDevice->loadPlugin(Configuration->VideoDriver);
	for(u32 i = 0; i < Configuration->RenderPlugins.size() + 1; i++)
	{
		auto plugin = Configuration->RenderPlugins.find(i);
		if(plugin != Configuration->RenderPlugins.end())
		{
			m_EngineDevice->loadPlugin(plugin->second);
		}
	}
	//m_EngineDevice->loadPlugin(PLUGIN_THEORA_MANAGER);

	RenderSystem* selectedRenderSystem = m_EngineDevice->getAvailableRenderers().at(0);
	m_EngineDevice->setRenderSystem(selectedRenderSystem);
	selectedRenderSystem->setConfigOption("Full Screen", Configuration->EnableFullscreen);   

	selectedRenderSystem->setConfigOption("Video Mode", 
		String(Configuration->VideoModeX) + " x " + 
		String(Configuration->VideoModeY) + " @ " + 
		String(Configuration->VideoDepth) + "-bit colour");

	m_RenderWindow = m_EngineDevice->initialise(true, "Core");

	if (m_EngineDevice->getRenderSystem()->getCapabilities()->hasCapability(RSC_VERTEX_PROGRAM) == false)
	{
		CORE_THROW("Your video card doesn't support batching", "CGameManager::InitializeEngine");
	}

	// Check prerequisites first
	const RenderSystemCapabilities* caps = m_EngineDevice->getRenderSystem()->getCapabilities();
	if (!caps->hasCapability(RSC_VERTEX_PROGRAM) || !(caps->hasCapability(RSC_FRAGMENT_PROGRAM)))
	{
		isSupportShaders = false;
	}
	else
	{
		if (selectedRenderSystem->getName().substr(0, 6) == "OpenGL")
		{
			if (!GpuProgramManager::getSingleton().isSyntaxSupported("arbvp1") ||
				!GpuProgramManager::getSingleton().isSyntaxSupported("arbfp1"))
			{
				isSupportShaders = false;
			}
			else
			{
				isSupportShaders = true;
			}
		}
		std::cerr << selectedRenderSystem->getName().substr(0, 8) << std::endl;
		if (selectedRenderSystem->getName().substr(0, 8) == "Direct3D")
		{
			if (!GpuProgramManager::getSingleton().isSyntaxSupported("vs_1_1") ||
				!GpuProgramManager::getSingleton().isSyntaxSupported("ps_1_4") ||
				!GpuProgramManager::getSingleton().isSyntaxSupported("ps_2_0") ||
				!GpuProgramManager::getSingleton().isSyntaxSupported("ps_2_x"))
			{
				isSupportShaders = false;
			}
			else
			{
				isSupportShaders = true;
			}
		}
	}

	// Set texture and animation parameters
	TextureManager::getSingleton().setDefaultNumMipmaps(MIP_UNLIMITED);
	MaterialManager::getSingleton().setDefaultTextureFiltering(TFO_ANISOTROPIC);
	MaterialManager::getSingleton().setDefaultAnisotropy(16);
	Animation::setDefaultInterpolationMode(Animation::IM_SPLINE);

#ifdef COMPILE_EFFECT_FIRE
	auto mParticleSystemRendererFact = new ShaderParticleRendererFactory();
	auto mParticleEmitterFact = new BoxEmitterFactory();
	ParticleSystemManager::getSingleton().addRendererFactory(mParticleSystemRendererFact);
	ParticleSystemManager::getSingleton().addEmitterFactory(mParticleEmitterFact);
#endif

	// Must be called after the rendering system is setup
	ResourceGroupManager::getSingleton().initialiseAllResourceGroups();

	// Default scene manager
	m_SceneManager = m_EngineDevice->createSceneManager(ST_EXTERIOR_FAR);
	m_SceneManager->setAmbientLight(Ogre::ColourValue(0.5, 0.5, 0.5));
	m_SceneManager->setShadowTechnique(Ogre::SHADOWTYPE_TEXTURE_MODULATIVE);

	// Set default animation interpolation
	Animation::setDefaultInterpolationMode(Animation::IM_LINEAR);
	Animation::setDefaultRotationInterpolationMode(Animation::RIM_LINEAR);

	// Overlay System
	m_OverlaySystem = new OverlaySystem();
	m_SceneManager->addRenderQueueListener(m_OverlaySystem);

	assert(_CrtCheckMemory());
}

EngineDevice* CGameManager::GetEngineDevice()
{
	return m_EngineDevice;
}

SceneManager* CGameManager::GetSceneManager()
{
	return m_SceneManager;
}

RenderWindow* CGameManager::GetRenderWindow()
{
	return m_RenderWindow;
}

Timer* CGameManager::GetTimer()
{
	return m_Timer;
}

E_DRIVER_TYPE CGameManager::GetVideoDeviceType()
{
	return Configuration->DriverType;
}

void CGameManager::SetEngineDevice(EngineDevice* e)
{
	m_EngineDevice = e;
}

void CGameManager::SetSceneManager(SceneManager* s)
{
	m_SceneManager = s;
}

void CGameManager::SetRenderWindow(RenderWindow* r)
{
	m_RenderWindow = r;
}

void CGameManager::SetGame(CGame* Game)
{
	m_Game = Game;
}

void CGameManager::SetBaseResourceName(const String& ResourceName)
{
	m_BaseResourceName = ResourceName;
}

void CGameManager::AddResourceArchive(const char* FileName, const char* GroupName)
{
	if(IO::CFileSystem::IsFileExist(FileName))
	{
		if(!ResourceGroupManager::getSingleton().resourceGroupExists(GroupName))
			ResourceGroupManager::getSingleton().createResourceGroup(GroupName);
		ResourceGroupManager::getSingleton().addResourceLocation(FileName, "Zip", GroupName, true);
		ResourceGroupManager::getSingleton().initialiseResourceGroup(GroupName);
	}
}

void CGameManager::RemoveResourceArchive(const char* FileName, const char* GroupName)
{
	ResourceGroupManager::getSingleton().unloadResourceGroup(GroupName);
	ResourceGroupManager::getSingleton().removeResourceLocation(FileName, GroupName);
}

void CGameManager::AdvanceGameState()
{
	if(m_Game)
	{
		m_Game->AdvanceState();
	}
}

void CGameManager::UpdateGame(const f32& elapsedTime)
{
	if(m_PhysicsManager->GetStrategy())
		m_PhysicsManager->GetStrategy()->Update(elapsedTime);
	m_CameraManager->Update(elapsedTime);
	m_GameObjectManager->Update(elapsedTime);
	m_NatureManager->Update(elapsedTime);
	m_ItemsManager->Update(elapsedTime);
	m_EffectsManager->Update(elapsedTime);
	m_BillboardManager->Update(elapsedTime);

	// Update the location of the listener for the sound manager
	Sound::CSoundManager::Instance()->GetListener()->SetPosition(m_CameraManager->GetCameraPos());
}

void CGameManager::Shutdown()
{
	try
	{
		//CORE_DELETE(m_OverlaySystem);  TODO: how do I destroy this?
		CORE_DELETE(Configuration);
		CORE_DELETE(m_Timer);
		CORE_DELETE(m_SceneImporter);

		if(m_EngineDevice)
		{
			//m_EngineDevice->destroySceneManager(m_SceneManager);
			m_EngineDevice->shutdown();
			m_EngineDevice = nullptr;
		}
	}
	catch(std::exception& e)
	{
		CORE_ASSERT(false);
		throw(e);
	}
	catch(...)
	{
		throw("Error in CGameManager::Shutdown()");
	}
}

void CGameManager::SetQuit(bool quit)
{
	isShouldQuit = quit;
}

bool CGameManager::GetQuit()
{
	return isShouldQuit;
}

bool CGameManager::SaveGame(const char* FileName)
{
	CSerializer serializer;
	return serializer.SaveGame(FileName);
}

bool CGameManager::LoadGame(const char* FileName, const String& ResourceGroupName)
{
	if(!m_SceneImporter)
		m_SceneImporter = new CSceneImporter();
	return m_SceneImporter->ImportScene(FileName, ResourceGroupName);
}

const char* CGameManager::GetBaseResourceName()
{
	return m_BaseResourceName.c_str();
}

void CGameManager::SetBaseAudioResourceName(const String& ResourceName)
{
	m_BaseAudioResourceName = ResourceName;
}

const char* CGameManager::GetBaseAudioResourceName()
{
	return m_BaseAudioResourceName.c_str();
}

const char* CGameManager::GetScriptPath()
{
	return Configuration->ScriptPath.c_str();
}

const char* CGameManager::GetDefaultPhysicsStrategy()
{
	return Configuration->DefaultPhysicsStrategy.c_str();
}

const char* CGameManager::GetDefaultDatabaseName()
{
	return m_DefaultDatabaseName.c_str();
}

SceneManager* CGameManager::CreateScene(const char* SceneType, const char* SceneName)
{
	// Ensure the sound manager is not in the middle of loading sounds
	while(Sound::CSoundManager::Instance()->GetIsBaseSoundsLoading())
	{
		Sleep(100);
	}

	// Save the cameras
	Vector<E_CAMERA_MODE> cameraModes;
	if(m_SceneManager && m_CameraManager)
	{
		auto tempCameras = m_CameraManager->GetCameras();
		for(auto it = tempCameras.cbegin(); it != tempCameras.cend(); it++)
		{
			cameraModes.push_back((*it)->GetMode());
		}

		m_CameraManager->RemoveAllCameras();
	}

	// Shutdown the nature manager
	Nature::CNatureManager::Instance()->Shutdown();

	// Shutdown the game object manager
	CGameObjectManager::Instance()->Shutdown();

	// Shutdown the camera manager even if we haven't used it yet.  The scene loader may have intialized it.
	CCameraManager::Instance()->Shutdown();

	// Shutdown and remove all billboards.
	CBillboardManager::Instance()->Shutdown();

	// Shutdown and remove all inventory
	CItemsManager::Instance()->Shutdown();

	// Shutdown and remove physics
	CPhysicsManager::Instance()->DeleteStrategy();

	// Remove the scene manager
	m_SceneManager->clearScene();
	m_EngineDevice->destroySceneManager(m_SceneManager);

	// Create the scene
	if(!SceneName)
		return nullptr;
	else
		m_SceneManager = m_EngineDevice->createSceneManager(SceneType, SceneName);

	// Add the cameras back
	if(m_CameraManager)
	{
		for(auto it = cameraModes.cbegin(); it != cameraModes.cend(); it++)
		{
			m_CameraManager->CreateCamera((*it));
		}
	}

	m_SceneManager->addRenderQueueListener(m_OverlaySystem);

	// Start the camera manager using this scene manager for the camera and viewport
	CCameraManager::Instance()->Restart();

	m_GameObjectManager = CGameObjectManager::Instance();
	if(!m_GameObjectManager)
	{
		CORE_THROW("Could not set CGameObjectManager.", "CGameManager::CreateScene");
	}

	m_CameraManager = CCameraManager::Instance();
	if(!m_CameraManager)
	{
		CORE_THROW("Could not set CCameraManager.", "CGameManager::CreateScene");
	}
	else
	{
		if(m_CameraManager->GetCameras().size() == 0)
			m_CameraManager->CreateCamera(ECM_GOD);		// Create default camera
	}

	m_ItemsManager = CItemsManager::Instance();
	if(!m_ItemsManager)
	{
		CORE_THROW("Could not set CItemsManager.", "CGameManager::CreateScene");
	}

	// Re-initialize the effects manager
	//m_EffectsManager->ReInit();
	m_EffectsManager = Effects::CEffectsManager::Instance();
	if(!m_EffectsManager)
	{
		CORE_THROW("Could not set CEffectsManager.", "CGameManager::CreateScene");
	}

	m_NatureManager = Nature::CNatureManager::Instance();
	if(!m_NatureManager)
	{
		CORE_THROW("Could not set CNatureManager.", "CGameManager::CreateScene");
	}

	m_BillboardManager = CBillboardManager::Instance();
	if(!m_BillboardManager)
	{
		CORE_THROW("Could not set CBillboardManager.", "CGameManager::CreateScene");
	}

	m_PhysicsManager = CPhysicsManager::Instance();
	if(!m_PhysicsManager)
	{
		CORE_THROW("Could not set CPhysicsManager.", "CGameManager::CreateScene");
	}

	return m_SceneManager;
}