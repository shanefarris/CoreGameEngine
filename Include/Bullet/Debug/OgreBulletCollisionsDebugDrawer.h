#ifndef _OgreBulletCollisions_DebugDrawer_H_
#define _OgreBulletCollisions_DebugDrawer_H_

#include "OgreBulletCollisionsPreRequisites.h"

#include "Debug/OgreBulletCollisionsDebugLines.h"

namespace OgreBulletCollisions
{
	//------------------------------------------------------------------------------------------------
	class  CORE_EXPORT DebugDrawer : public DebugLines, public btIDebugDraw
	{
	public:
        DebugDrawer();
		virtual ~DebugDrawer();


        virtual void	setDebugMode(int mode){mDebugMode = mode;};
        virtual int		getDebugMode() const { return mDebugMode;};

        virtual void	drawLine(const btVector3& from,const btVector3& to,const btVector3& color);
        virtual void	drawContactPoint(const btVector3& PointOnB,const btVector3& normalOnB,
            btScalar distance,int lifeTime,const btVector3& color);

        void drawAabb(const Ogre::Vector3& from,const Ogre::Vector3& to,const Ogre::Vector3& color);
        void drawLine(const Ogre::Vector3& from,const Ogre::Vector3& to,const Ogre::Vector3& color);
        void drawContactPoint(const Ogre::Vector3& PointOnB,const Ogre::Vector3& normalOnB,
            Ogre::Real distance,int lifeTime,const Ogre::Vector3& color);

        void setDrawAabb(bool enable);
        void setDrawWireframe(bool enable);
        void setDrawFeaturesText(bool enable);
        void setDrawContactPoints(bool enable);
        void setNoDeactivation(bool enable);
        void setNoHelpText(bool enable);
        void setDrawText(bool enable);
        void setProfileTimings(bool enable);
        void setEnableSatComparison(bool enable);
        void setDisableBulletLCP (bool enable);
        void setEnableCCD(bool enable);

        bool doesDrawAabb () const;
        bool doesDrawWireframe () const;
        bool doesDrawFeaturesText () const;
        bool doesDrawContactPoints () const;
        bool doesNoDeactivation () const;
        bool doesNoHelpText () const;
        bool doesDrawText () const;
        bool doesProfileTimings () const;
        bool doesEnableSatComparison () const;
        bool doesDisableBulletLCP () const;
        bool doesEnableCCD () const;

        void drawAabb(const btVector3& from,const btVector3& to,const btVector3& color);

		// TODO
		void	draw3dText(const btVector3& location,const char* textString);

		void	reportErrorWarning(const char* warningString);
	protected:
        int mDebugMode;
	};
}

#endif //_OgreBulletCollisions_DebugDrawer_H_

