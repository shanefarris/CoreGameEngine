#ifndef _OgreBulletCollisions_DEBUGLines_H_
#define _OgreBulletCollisions_DEBUGLines_H_

#include "OgreBulletCollisionsPreRequisites.h"

namespace OgreBulletCollisions
{
    //------------------------------------------------------------------------------------------------
    class CORE_EXPORT DebugLines:public Ogre::SimpleRenderable
    {
    public:
        DebugLines(void);
        ~DebugLines(void);

        void addLine (const Ogre::Vector3 &start,const Ogre::Vector3 &end)
        {
            clear ();

            _points.push_back (start);
            _points.push_back (end);
        }

        void addLine(Ogre::Real start_x, Ogre::Real start_y, Ogre::Real start_z, 
            Ogre::Real end_x, Ogre::Real end_y, Ogre::Real end_z)
        {
            addLine (Ogre::Vector3(start_x,start_y,start_z),
                Ogre::Vector3(end_x,end_y,end_z));
        }

        void addPoint (const Ogre::Vector3 &pt)
        {
            clear();

            _points.push_back(pt);
        }

        void addPoint (Ogre::Real x, Ogre::Real y, Ogre::Real z)
        {
            addPoint (Ogre::Vector3(x, y, z));
        }

        void draw ();
        void clear ();

        Ogre::Real getSquaredViewDepth (const Ogre::Camera *cam) const;
        Ogre::Real getBoundingRadius (void) const;

    protected:

        Vector3Array _points;
        bool _drawn;

        static bool _materials_created;
    };
}
#endif //_OgreBulletCollisions_DEBUGLines_H_

