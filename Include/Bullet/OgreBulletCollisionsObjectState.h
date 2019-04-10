#ifndef _OGREBULLETCOLLISIONS_ObjectState_H
#define _OGREBULLETCOLLISIONS_ObjectState_H

#include "OgreBulletCollisionsPreRequisites.h"

namespace OgreBulletCollisions
{
    class CORE_EXPORT ObjectState : public btMotionState
    {
    public:
	    ObjectState(Object *parent);
	    ~ObjectState();
    	
	    virtual void getWorldTransform(btTransform& worldTrans ) const;
        virtual void setWorldTransform(const btTransform& worldTrans);	

    private:
        Object      *mObject;
        btTransform  mWorldTrans;
    };
}
#endif //_OGREBULLETCOLLISIONS_ObjectState_H

