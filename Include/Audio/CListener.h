#ifndef __SOUNDENGINE_LISTENER_H__
#define __SOUNDENGINE_LISTENER_H__

#include "SoundEnginePrereqs.h"
#include "OgreMovableObject.h"
#include "OgreSingleton.h"

namespace Sound 
{
	/**
	 * CListener.
	 * @remarks
	 * There is only ever one listener in the scene and it is created
	 * when the CSoundManager is initialized.  To Get the reference to
	 * the listener use CSoundManager::GetListener.  The listener can 
	 * be attached to an Ogre::SceneNode or placed at some point in space.
	 *
	 * @see Ogre::MovableObject
	 * @see Ogre::Singleton
	 */
	class CORE_EXPORT CListener : public Ogre::MovableObject
	{
	protected:
		CListener();

		// Normal Constructor. Should not be called directly! Use CSoundManager::GetListener 
		CListener(const String& name);

	public:
		virtual ~CListener();

		static CListener* Instance();

		/** 
		 * Sets the gain. 
		 * @param gain The gain where 1.0 is full volume and 0.0 is off
		 * @note Gain should be positive
		 */
		void SetGain(f32 gain);

		/** Returns the gain. */
		f32 GetGain() const { return m_Gain; }

		/**
		 * Sets the position of the listener.
		 * @param x The x part of the position
		 * @param y The y part of the position
		 * @param z The z part of the position
		 * @note The position will be overridden if the listener is attached to a SceneNode
		 */
		void SetPosition(f32 x, f32 y, f32 z);

		/**
		 * Sets the position of the listener.
		 * @param vec The new postion for the listener.
		 * @note The position will be overridden if the listener is attached to a SceneNode
		 */
		void SetPosition(const Vector3& vec);

		/** Returns the position of the sound. */
		const Vector3& GetPosition() const {return m_Position;}

		/**
		 * Sets the direction of the listener.
		 * @param x The x part of the direction vector
		 * @param y The y part of the direction vector
		 * @param z The z part of the direction vector
		 * @note The direction will be overridden if the listener is attached to a SceneNode
		 */
		void SetDirection(f32 x, f32 y, f32 z);

		/**
		 * Sets the direction of the listener.
		 * @param vec The direction vector.
		 * @note The direction will be overridden if the listener is attached to a SceneNode
		 */
		void SetDirection(const Vector3& vec);

		/** Returns the direction of the sound. */
		const Vector3& GetDirection() const { return m_Direction; }

		/**
		 * Sets the velocity of the listener.
		 * @param x The x part of the velocity vector
		 * @param y The y part of the velocity vector
		 * @param z The z part of the velocity vector
		 */
		void SetVelocity(f32 x, f32 y, f32 z);

		/**
		 * Sets the velocity of the listener.
		 * @param vec The velocity vector.
		 */
		void SetVelocity(const Vector3& vec);

		/** Returns the velocity of the sound. */
		const Vector3& GetVelocity() const { return m_Velocity; }

		/** Returns the position of the sound including any transform from nodes it is attached to. */
		const Vector3& GetDerivedPosition() const;

		/** Returns the direction of the sound including any transform from nodes it is attached to. */
		const Vector3& GetDerivedDirection() const;

		/** Overridden from MovableObject */
		const String& getMovableType() const;

		/** Overridden from MovableObject */
		const Ogre::AxisAlignedBox& getBoundingBox() const;

		/** Overridden from MovableObject */
		f32 getBoundingRadius() const { return 0; /* Not Visible */ } 

		/** Overridden from MovableObject */
		void _updateRenderQueue(Ogre::RenderQueue* queue);

		/** Overridden from MovableObject */
		void _notifyAttached(Ogre::Node* parent, bool isTagPoint = false);

		/** Overridden from MovableObject */
		virtual void visitRenderables(Ogre::Renderable::Visitor* visitor, bool debugRenderables = false){}

	protected:

		static CListener* Listener;

		// Internal method for synchronising with parent node (if any)
		virtual void Update() const;
		// This is called each frame to update the position, direction, etc
		void UpdateListener();
		// Convienance method to reset the sound state
		void InitListener();

		mutable Vector3 m_DerivedPosition;				// Postion taking into account the parent node
		mutable Vector3 m_DerivedDirection;				// Direction taking into account the parent node
		mutable Ogre::Quaternion m_LastParentOrientation;	// Stored versions of parent orientation
		mutable Vector3 m_LastParentPosition;			// Stored versions of parent position

		f32 m_Gain;
		Vector3 m_Position;
		Vector3 m_Direction;
		Vector3 m_Velocity;
		Vector3 m_Up;
		ALfloat mOrientation[6];
		mutable bool m_LocalTransformDirty;					// Is the local transform dirty?

		friend class CSoundManager;
		friend class ListenerFactory;
	};

	/** Factory object for creating the listener */
	class ListenerFactory : public Ogre::MovableObjectFactory
	{
	public:
		ListenerFactory() {}
		~ListenerFactory() {}

		static String FACTORY_TYPE_NAME;

		const String& getType() const;
		void destroyInstance(Ogre::MovableObject* obj);

	protected:
		Ogre::MovableObject* createInstanceImpl(const String& name, const Ogre::NameValuePairList* params = 0);

	};

} // Namespace

#endif
