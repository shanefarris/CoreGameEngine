#ifndef _OGREBULLETCOLLISIONS_CollisionObject_H
#define _OGREBULLETCOLLISIONS_CollisionObject_H

#include "OgreBulletCollisionsPreRequisites.h"
#include "OgreBulletCollisionsWorld.h"

namespace OgreBulletCollisions
{
    // -------------------------------------------------------------------------
    /*!
	 * \brief
	 * 
	 * Object is the Basic Bullet Collision representation of an Physical thing in
     * a scene. It does need a Shape Object to know its "Geometrics" Bounds.
	 * 
	 * \remarks
	 * Objects doesn't need to be represented by a Visible 3D mesh.
	 * 
	 * \see
	 * Ogre::MovableObject | Ogre::UserDefinedObject | OgreBulletDynamics::RigidBody
	 */
	class CORE_EXPORT Object : public Ogre::MovableObject, public Ogre::UserDefinedObject
    {
    public:
        Object(const Ogre::String &name,  CollisionsWorld *world, bool init);

        virtual ~Object();

        // override Movables
		void visitRenderables(Ogre::Renderable::Visitor* visitor, bool debugRenderables);

        virtual const Ogre::String& getMovableType() const; 
        virtual void _notifyAttached(Ogre::Node* parent,bool isTagPoint = false);
        //virtual const Ogre::String& getName(void) const {return mName};
        virtual void _notifyCurrentCamera(Ogre::Camera* camera);
        virtual const Ogre::AxisAlignedBox& getBoundingBox(void) const;
        virtual Ogre::Real getBoundingRadius(void) const;
        virtual void _updateRenderQueue(Ogre::RenderQueue* queue);

        inline const Ogre::Vector3 &getWorldPosition() const {return mRootNode->_getDerivedPosition();};
		inline const Ogre::Quaternion &getWorldOrientation() const {return mRootNode->_getDerivedOrientation();};

        inline void setPosition(const Ogre::Vector3 &p) {mRootNode->setPosition (p);};
        inline void setOrientation(const Ogre::Quaternion &q)  {return mRootNode->setOrientation (q);};

        inline void setPosition(const Ogre::Real x, const Ogre::Real y, const Ogre::Real z) {mRootNode->setPosition (x,y,z);};
        inline void setOrientation(const Ogre::Real x, const Ogre::Real y, const Ogre::Real z, const Ogre::Real w)  {return mRootNode->setOrientation (x,y,z,w);};

        virtual void setPosition(const btVector3 &pos);
        virtual void setOrientation(const btQuaternion &quat);
        virtual void setTransform(const btVector3 &pos, const btQuaternion &quat);
        virtual void setTransform(const btTransform& worldTrans);

        inline btCollisionObject*  getBulletObject() const { return mObject;};
        inline btCollisionWorld*  getBulletCollisionWorld() const { return mWorld->getBulletCollisionWorld ();};
        inline CollisionsWorld*  getCollisionWorld() const { return mWorld;};
        
        inline CollisionShape *getShape() const{ return mShape;};
        inline DebugCollisionShape* getDebugShape() const{ return mDebugShape;};

        void setShape(CollisionShape *shape, 
            const Ogre::Vector3 &pos, 
            const Ogre::Quaternion &quat);
        void showDebugShape(bool show);

		Ogre::SceneNode *getRootNode() { return mRootNode; }

    protected:
        Ogre::SceneNode*        mRootNode;
        Ogre::SceneNode*        mShapeNode;
        Ogre::SceneNode*        mDebugNode;
        ObjectState   *         mState;
        CollisionsWorld*        mWorld;
        btCollisionObject*      mObject;
        Ogre::AxisAlignedBox    mBounds;
        CollisionShape*         mShape;
        DebugCollisionShape *   mDebugShape;

    public:
        static const Ogre::String mMovableType;
    };
    // -------------------------------------------------------------------------
}
#endif //_OGREBULLETCOLLISIONS_CollisionObject_H

