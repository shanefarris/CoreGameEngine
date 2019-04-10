#ifndef __CGAMEOBJECT_H__
#define __CGAMEOBJECT_H__

#include "Defines.h"

#include "OgreVector3.h"
#include "OgreQuaternion.h"

namespace Core
{
	struct SoundToAnimation;
	enum   E_LOAD_TYPE;
	enum   E_ANIM_STATE;
	enum   ENVIRONMENT_ATTRIBUTE_TYPE;

	namespace Physics
	{
		class CPhysicsProfile;
	}

	class CORE_EXPORT CGameObject
	{
	public:
		CGameObject(const char* Name, CGameObject* Parent = nullptr);
		virtual ~CGameObject();

		void SetIsUpdatable(bool Value);
		void SetPosition(const Vector3& Position);
		void SetAnimationState(E_ANIM_STATE State);
		void SetAnimationMappings(const Map<E_ANIM_STATE, SoundToAnimation*>& AnimationMaps, bool Loop);

		void AttachChild(CGameObject* Child, const Quaternion& Rotation = Quaternion::IDENTITY, const Vector3& OffsetPosition = Vector3::ZERO);
		void AttachChild(CGameObject* Child, const String& BoneName, const Quaternion& Rotation = Quaternion::IDENTITY, const Vector3& OffsetPosition = Vector3::ZERO);
		void DetachChild(CGameObject* Child);

		void SetEnabled(bool IsEnabled);					// Set visible and update (and children)
		void Reset();										// Resets state

		virtual void Update(const f32& elapsedTime);

		E_LOAD_TYPE GetLoadType() { return m_LoadType; }
		void		SetLoadType(E_LOAD_TYPE LoadType) { m_LoadType = LoadType; }

		String			 Name;
		String			 GameObjectType;
		SceneNode*		 Node;
		Entity*			 Entity;
		void*			 AttachedData;	 
		Physics::CPhysicsProfile*	PhysicsProfile;
		ENVIRONMENT_ATTRIBUTE_TYPE	EnvironmentType;

	protected:
		virtual void UpdateAnimation(const f32& elapsedTime);

		bool				isEnabled;						// Disabling will make it not visible, no update, and the same with the children
		bool				isLoop;							// Loop the animation
		bool				isAnimationDirty;				// Does the current animation state need to be changed.
		AnimationState*		m_AnimationState;				// Used for animation state
		E_ANIM_STATE		m_AnimState;					// What the state should be
		E_ANIM_STATE		m_CurrAnimState;				// The current state, if diff then anim state, update it
		E_LOAD_TYPE			m_LoadType;						// Defermines if we use static geometry, an instance manager, or a plain entity, INSTANCE by default.

		CGameObject*			m_Parent;
		Vector<CGameObject*>	m_Children;

		// Maps the animaiton from ogre to the state and the sound for the animation
		Map<E_ANIM_STATE, SoundToAnimation*> m_AnimationMaps;
	};

	class CORE_EXPORT CDummyGameObject : public CGameObject
	{
	public:
		CDummyGameObject();
		CDummyGameObject(const char* Name, SceneNode* n, Ogre::Entity* e);
	};
}

#endif // __CGAMEOBJECT_H__