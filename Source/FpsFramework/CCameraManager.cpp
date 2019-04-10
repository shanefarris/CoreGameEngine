#include "CCameraManager.h"
#include "ICamera.h"
#include "CInputManager.h"
#include "CGameManager.h"
#include "CGameObjectManager.h"
#include "CPluginManager.h"
#include "Plugins\ICameraFactory.h"
#include "CPlayer.h"
#include "CCameraSpring.h"
#include "CCameraGod.h"
#include "CCameraChase.h"
#include "CCameraFps.h"
#include "IO/CoreLogging.h"

#include "OgreStringConverter.h"
#include "OgreRenderWindow.h"
#include "OgreViewport.h"
#include "OgreColourValue.h"
#include "OgreCamera.h"
#include "OgreSceneNode.h"
#include "OgreSceneManager.h"
#include "OgreRoot.h"
#include "OgreRenderSystemCapabilities.h"

using namespace Core;

CCameraManager* CCameraManager::CameraManager = nullptr;

CCameraManager* CCameraManager::Instance()
{
	if(CameraManager == nullptr)
		CameraManager = new CCameraManager();
	return CameraManager;
}

CCameraManager::CCameraManager() : m_OgreCamera(0), m_Viewport(0), m_CurrCamera(0), isViewportSetup(false), m_FarClipDistance(50000.0f)
{
	m_PluginManager = CPluginManager::Instance();
}

CCameraManager::~CCameraManager()
{
	Shutdown();

	// Remove all the custom cameras
	for(auto it = m_Cameras.begin(); it != m_Cameras.end(); it++)
		CORE_DELETE((*it));
}

s32 CCameraManager::CreateCamera(E_CAMERA_MODE Type, SceneNode* Parent)
{
	ICamera* camera = nullptr;
	String name = "Camera_" + StringConverter::toString(m_Cameras.size());

	// Ensure our camera and view port are setup
	_CreateCamera();
	_SetupViewport();

	// Check for built-in cameras first
	if(Type == ECM_CHASE)
	{
		// Make sure we can see the player
		if(CGameObjectManager::Instance()->GetHumanPlayer())
			CGameObjectManager::Instance()->GetHumanPlayer()->SetVisible(true);

		camera = new CCameraChase(name.c_str(), Parent);
	}
	else if(Type == ECM_FPS)
	{
		// The player need to exist first
		if(CGameObjectManager::Instance()->GetHumanPlayer())
		{
			CGameObjectManager::Instance()->GetHumanPlayer()->SetVisible(false);
			camera = new CCameraFps(name.c_str(), Parent);
		}
	}
	else if(Type == ECM_GOD)
	{
		// Make sure we can see the player
		SetPlayerVisible();
		camera = new CCameraGod(name.c_str(), Parent);
	}
	else if(Type == ECM_SPRING)
	{
		// Make sure we can see the player
		SetPlayerVisible();
		camera = new CCameraSpring(name.c_str(), Parent);
	}

	if(camera)
	{
		m_Cameras.push_back(camera);
		m_CurrCamera = camera;
		return (s32)m_Cameras.size() - 1;
	}

	// Check for plugin cameras
	return CreatePluginCamera(Type, Parent);
}

s32 CCameraManager::CreatePluginCamera(E_CAMERA_MODE Type, SceneNode* Parent)
{
	// Find the camera plugin
	auto cameraPlugins = m_PluginManager->GetCameraFactories();
	for(u32 i = 0; i < cameraPlugins.size(); i++)
	{
		if(cameraPlugins[i]->Type == Type)
		{
			// Create the camera type
			String name = "Camera_" + StringConverter::toString(m_Cameras.size());
			ICamera* camera = cameraPlugins[i]->GetCamera(name.c_str());
			if(camera)
			{
				if(Type == ECM_FIXED || Type == ECM_FREE || Type == ECM_RTS)
				{
					SetPlayerVisible();
				}

				m_Cameras.push_back(camera);
				m_CurrCamera = camera;

				return (s32)m_Cameras.size() - 1;
			}
		}
	}
	return -1;
}

void CCameraManager::_SetupViewport()
{
	if(!isViewportSetup)
	{
		if(!m_OgreCamera)
		{
			_CreateCamera();
		}

		// Setup viewport
		if(CGameManager::Instance()->GetRenderWindow()->getNumViewports() == 0)
		{
			// Create one viewport, entire window
			m_Viewport = CGameManager::Instance()->GetRenderWindow()->addViewport(m_OgreCamera);
			m_Viewport->setBackgroundColour(ColourValue(0, 0, 0));
					       
			// Alter the camera aspect ratio to match the viewport
			m_OgreCamera->setAspectRatio(f32(m_Viewport->getActualWidth()) / f32(m_Viewport->getActualHeight()));
		}
		else
		{
			m_Viewport->setCamera(m_OgreCamera);
		}

		// Alter the camera aspect ratio to match the viewport
		m_OgreCamera->setAspectRatio(f32(m_Viewport->getActualWidth()) / f32(m_Viewport->getActualHeight()));
		isViewportSetup = true;
	}
	
}

void CCameraManager::Update(const f32& elapsedTime) 
{
	m_CurrCamera->Update(elapsedTime);
}

void CCameraManager::Update(const f32& elapsedTime, E_CAMERA_MODE Mode) 
{
	m_CurrCamera->Update(elapsedTime);
}

void CCameraManager::RemoveAllCameras()
{
	for(auto it = m_Cameras.cbegin(); it != m_Cameras.cend(); it++)
	{
		if((*it))
			delete (*it);		// User regular delete because this is a const.
	}
	
	m_CurrCamera = nullptr;
	m_Cameras.clear();
	m_CameraNode->setPosition(Vector3(0, 0, 0));
}

void CCameraManager::Shutdown()
{
	try
	{
		if(m_OgreCamera)
		{
			auto sm = CGameManager::Instance()->GetSceneManager();
			sm->destroyAllCameras();
			sm->destroySceneNode(m_CameraNode);
			sm->destroySceneNode(m_TargetNode);

			m_CameraNode = nullptr;
			m_TargetNode = nullptr;
		}
	
		if(m_Viewport)
		{
			CGameManager::Instance()->GetRenderWindow()->removeAllViewports();
		}

		isViewportSetup = false;
		m_Viewport = nullptr;
		m_OgreCamera = nullptr;

		for(auto it = m_Cameras.begin(); it != m_Cameras.end(); it++)
		{
			CORE_DELETE((*it));
		}
	}
	catch(std::exception& e)
	{
		CORE_ASSERT(false);
		throw(e);
	}
	catch(...)
	{
		throw("Error in CCameraManager::Shutdown()");
	}
}

void CCameraManager::Restart()
{
	_CreateCamera();
	_SetupViewport();
}

void CCameraManager::_CreateCamera()
{
	// Create a default camera
	if(!m_OgreCamera)
	{
		SceneManager* sm = CGameManager::Instance()->GetSceneManager();
		m_OgreCamera = sm->createCamera("camera_main");
		m_OgreCamera->setQueryFlags(0);

		// Create the camera's node structure
		m_CameraNode = sm->getRootSceneNode()->createChildSceneNode("camera_main_node");
		m_TargetNode = sm->getRootSceneNode()->createChildSceneNode("camera_main_target");

		// Attach the Ogre camera to the camera node
		m_CameraNode->attachObject(m_OgreCamera);

		m_OgreCamera->setNearClipDistance(0.1f);
		m_OgreCamera->setAutoAspectRatio(true);

		if (CGameManager::Instance()->GetEngineDevice()->getRenderSystem()->getCapabilities()->hasCapability(RSC_INFINITE_FAR_PLANE))
			m_FarClipDistance = 99999 * 6;

		m_OgreCamera->setFarClipDistance(m_FarClipDistance);
	}
}

bool CCameraManager::IsHaveMode(E_CAMERA_MODE Mode)
{
	for(auto it = m_Cameras.cbegin(); it != m_Cameras.cend(); it++)
	{
		if((*it)->GetMode() == Mode)
			return true;
	}
	return false;
}

#pragma region GET/SET

void CCameraManager::SetCameraPos(Vector3& Pos)	
{ 
	if(m_CameraNode)
		m_CameraNode->setPosition(Pos);
	else if(m_OgreCamera)
		m_OgreCamera->setPosition(Pos);
}

void CCameraManager::SetPlayerVisible()
{
	if(CGameObjectManager::Instance()->GetHumanPlayer())
		CGameObjectManager::Instance()->GetHumanPlayer()->SetVisible(true);
}

const Vector3 CCameraManager::GetCameraPos()					
{ 
	if(m_CameraNode)
		return m_CameraNode->getPosition();
	else if(m_OgreCamera)
		return m_OgreCamera->getPosition();

	return INVALID_POS;
}

E_CAMERA_MODE CCameraManager::GetMode()
{
	if(m_CurrCamera)
		return m_CurrCamera->m_Mode;
	return ECM_NONE;
}

void CCameraManager::SetCurrCamera(u32 Index)
{
	if(m_Cameras.size() >= Index)
		m_CurrCamera = m_Cameras[Index];
}

Camera* CCameraManager::GetCamera()   
{ 
	return m_OgreCamera; 
}

Viewport* CCameraManager::GetViewport() 
{ 
	return m_Viewport; 
}

Vector<ICamera*>& CCameraManager::GetCameras() 
{ 
	return m_Cameras; 
}

bool CCameraManager::GetIsPlayerFriendly()
{
	if(m_CurrCamera)
		return m_CurrCamera->GetIsPlayerFriendly();

	return false;
}

void CCameraManager::SetMoveSpeed(const f32& Speed)
{
	if(m_CurrCamera)
		m_CurrCamera->SetMoveSpeed(Speed);
}

void CCameraManager::SetEnabled(bool Enabled) 
{ 
	if(m_CurrCamera)
		m_CurrCamera->SetEnabled(Enabled);
}

SceneNode* CCameraManager::GetCameraNode()
{
	return m_CameraNode;
}

SceneNode* CCameraManager::GetTargetNode()
{
	return m_TargetNode;
}

 f32 CCameraManager::GetFarClipDistance()
 {
	 return m_FarClipDistance;
 }

#pragma endregion