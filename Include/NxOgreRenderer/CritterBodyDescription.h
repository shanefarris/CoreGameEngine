#ifdef _DEBUG                                                                                   

#ifndef CRITTER_BODYDESCRIPTION_H
#define CRITTER_BODYDESCRIPTION_H

#include "CritterStable.h"
#include "CritterCommon.h"

                                                                                       

namespace Critter
{

class CritterPublicClass BodyDescription : public NxOgre::RigidBodyDescription
{
  
 public:
  
  /** \brief OGRE3DPrototype constructor
  */
  BodyDescription();
  
  /** \brief OGRE3DPrototype destructor
  */
 ~BodyDescription();
  
  /** \brief Reset the RigidBodyPrototype and OGRE3D bits to it's default state.
  */
  void reset();
  
  /** \brief Does the prototype's variables are in the range of acceptable values?
  */
  bool valid();
  
  /** \brief SceneNode to use, or nullptr to create.
  */
  Ogre::SceneNode* mNode;
  
  /** \brief What to do the Node when the Body is destroyed.
  \default Enums::SceneNodeDestructorBehaviour_Destroy
  */
  Enums::SceneNodeDestructorBehaviour mSceneNodeDestructorBehaviour;

  /** \brief Drawing priority
  */
  NxOgre::Enums::Priority mRenderPriority;
  
};

} // namespace

                                                                                       

#endif

#endif