#ifndef __CCAMERASTRATEGY_H__
#define __CCAMERASTRATEGY_H__

#include "Defines.h"
#include "CoreStructures.h"
#include "CCameraManager.h"

namespace Core
{
	class ICamera
	{
		friend CCameraManager;

	protected:
		CCameraManager* m_CameraManager;

		Camera*			m_Camera;				// Ogre camera
		SceneNode*		m_TargetNode;			// The camera target
		SceneNode*		m_CameraNode;			// The camera itself
		E_CAMERA_MODE	m_Mode;					// Camera mode
		String			Name;
		f32				m_MouseRotationScale;
		f32				m_MoveSpeed;
		bool			isEnabled;				// If the camera should be updated or not
		bool			isPlayerFriendly;		// Is the camera controlled by the player or modifies the player

	public:
		ICamera() : m_CameraNode(0), m_TargetNode(0), m_Camera(0)
		{ 
			m_CameraManager = CCameraManager::Instance(); 

			m_Camera = m_CameraManager->GetCamera();
			m_CameraNode = m_CameraManager->GetCameraNode();
			m_TargetNode = m_CameraManager->GetTargetNode();

			m_MouseRotationScale = 0.13f;
			m_MoveSpeed = 1000.0f;
			isEnabled = true;
			isPlayerFriendly = false;
		}

		inline E_CAMERA_MODE GetMode() { return m_Mode; }
		inline bool GetIsPlayerFriendly() { return isPlayerFriendly; }

		inline void SetEnabled(bool Enabled) { isEnabled = Enabled; }
		inline void SetMoveSpeed(const f32& Speed) { m_MoveSpeed = Speed; }

		virtual void InstantUpdate(const Vector3& cameraPosition, const Vector3& targetPosition) = 0;
		virtual void Update(const f32& elapsedTime) = 0;
	};
}

#endif // __CCAMERASTRATEGY_H__