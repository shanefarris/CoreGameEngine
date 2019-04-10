#ifdef _DEBUG                                                                                

#ifndef CRITTER_TERRAINDESCRIPTION_H
#define CRITTER_TERRAINDESCRIPTION_H

#include "CritterStable.h"
#include "CritterCommon.h"

                                                                                       

namespace Critter
{

class CritterPublicClass TerrainDescription : public NxOgre::RigidBodyDescription
{

 public:

  /** \brief OGRE3DPrototype constructor
  */
  TerrainDescription();

  /** \brief OGRE3DPrototype destructor
  */
 ~TerrainDescription();

  /** \brief Reset the RigidBodyPrototype and OGRE3D bits to it's default state.
  */
  void reset();

  /** \brief Does the prototype's variables are in the range of acceptable values?
  */
  bool valid();

  /*! variable. Enable Smooth Sphere Collisions on the Terrain
  */
  bool mSmoothSphereCollisions;

  /*! variable. mMaterialRanges
      desc.
          Which material index to assign to once a height is below that range.
      example.
          // Below 16384, I want material 3
          // Below 10000, I want material 6
          // Below 400, I want material 2
          // Otherwise I want desc.mDefaultMaterial
          desc.mMaterialRanges[16384] = 3;
          desc.mMaterialRanges[10000] = 6;
          desc.mMaterialRanges[400] = 2;
      default.
          Map is empty (ues mDefaultMaterial)
  */
  std::map<unsigned short, NxOgre::MaterialIdentifier> mMaterialRanges;

  /*! variable. mDefaultMaterial
      desc.
          Which material index to assign to by default.
      default.
          0
  */
  NxOgre::MaterialIdentifier mDefaultMaterial;

  /*! variable. mHoleMaterial
      desc.
          Which material index to assign to holes in the material.
      note.
          This can be used with ranges to give an abnormal shape of the heightfield.
      default.
          65535
  */
  NxOgre::MaterialIdentifier mHoleMaterial;

};

} // namespace

                                                                                       

#endif


#endif