
#ifndef _OgreBulletCollisions_DEBUGOBJECT_H_
#define _OgreBulletCollisions_DEBUGOBJECT_H_

#include "OgreBulletCollisionsPreRequisites.h"

#include "Debug/OgreBulletCollisionsDebugLines.h"

namespace OgreBulletCollisions
{
	//------------------------------------------------------------------------------------------------
	class CORE_EXPORT DebugCollisionShape : public DebugLines
	{
	public:
		enum Mode
		{
			Mode_Unknown,
			Mode_Enabled,
			Mode_Disabled,
			Mode_Static
        };

	public:
        /** DebugCollisionShape ctor
        */
        DebugCollisionShape(CollisionShape * shape, 
                            DebugCollisionShape::Mode mode = DebugCollisionShape::Mode_Enabled);
		/** ~DebugCollisionShape ctor
		*/
        virtual ~DebugCollisionShape();
        // mStatemode getter
        DebugCollisionShape::Mode getStatemode() const { return mStatemode; }
        // mStatemode setter
        void setStatemode(DebugCollisionShape::Mode val);
        // mIsVisual getter
        bool getIsVisual() const;
        // mIsVisual setter
        void setIsVisual(bool val);

	protected:
        DebugCollisionShape::Mode mStatemode;
        bool                      mIsVisual;


	};
	//------------------------------------------------------------------------------------------------
	class CORE_EXPORT RayDebugShape:public DebugLines
	{
	public:
		RayDebugShape(const Ogre::Vector3& start,const Ogre::Vector3& direction,const Ogre::Real length);
		void setDefinition(const Ogre::Vector3& start,const Ogre::Vector3& direction,const Ogre::Real length);
		virtual ~RayDebugShape();
    };
    //------------------------------------------------------------------------------------------------
}

#endif //_OgreBulletCollisions_DEBUGOBJECT_H_


