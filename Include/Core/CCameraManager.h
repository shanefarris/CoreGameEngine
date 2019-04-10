// Create and manage only one camera for now (had problems with compositors with multiple cameras).  But can attach and detach to different nodes if needed

#ifndef __CCAMERAMANAGER_H__
#define __CCAMERAMANAGER_H__

#include "Defines.h"

namespace Core
{
	class ICamera;
	class CPluginManager;
	enum E_CAMERA_MODE;

	namespace Plugin
	{
		class ICameraFactory;
	}

	class CORE_EXPORT CCameraManager
	{
	private:
		CCameraManager();

		static CCameraManager*	CameraManager;
		ICamera*				m_CurrCamera;				// Current ICamera in use
		Camera*					m_OgreCamera;				// Ogre camera
		Viewport*				m_Viewport;
		bool					isViewportSetup;			// Have we setup the one and only viewport yet
		Vector<ICamera*>		m_Cameras;					// List of ICameras
		Core::CPluginManager*	m_PluginManager;			// Plugins
		SceneNode*				m_CameraNode;
		SceneNode*				m_TargetNode;
		f32						m_FarClipDistance;

		void SetPlayerVisible();
		void _SetupViewport();								// Creates the one and only ogre viewport
		void _CreateCamera();								// Creates the one and only ogre camera
		s32  CreatePluginCamera(E_CAMERA_MODE Type, SceneNode* Parent = nullptr);

	public:
		static CCameraManager* Instance();
		~CCameraManager();
		
		inline E_CAMERA_MODE		GetMode();				// Gets the mode of the current camera
		inline Camera*				GetCamera();			// Gets the Ogre camera
		inline Viewport*			GetViewport();
		inline const Vector3		GetCameraPos();			// Position of current camera
		inline Vector<ICamera*>&	GetCameras();			// Returns a list of all the ICameras loaded
		inline bool					GetIsPlayerFriendly();	// Is the camera effecting the movement of the human player
		inline SceneNode*			GetCameraNode();
		inline SceneNode*			GetTargetNode();
		inline f32					GetFarClipDistance();

		inline void SetMoveSpeed(const f32& Speed);
		inline void SetEnabled(bool Enabled);
		inline void SetCameraPos(Vector3& Pos);
		void		SetCurrCamera(u32 Index);

		bool IsHaveMode(E_CAMERA_MODE Mode);				// Do we have a camera of this mode type loaded
		void RemoveAllCameras();							// Delete the list of ICamera
		void Shutdown();									// Used to shutdown the ogre camera and viewport, and create a new set
		void Restart();										// Restarts an already initialized camera manager, creating the camera and viewport

		// Creates a ICamera of this mode
		s32  CreateCamera(E_CAMERA_MODE Type, SceneNode* Parent = nullptr);	

		void Update(const f32& elapsedTime);
		void Update(const f32& elapsedTime, E_CAMERA_MODE Mode);

	};
}

#endif // __CCAMERAMANAGER_H__