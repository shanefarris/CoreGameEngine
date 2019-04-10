#ifdef _DEBUG                                                                               

#ifndef CRITTER_PARTICLERENDERABLE_H
#define CRITTER_PARTICLERENDERABLE_H

#include "CritterStable.h"
#if NxOgreHasFluids == 1
#include "CritterCommon.h"

                                                                                       

namespace Critter
{

class CritterPublicClass ParticleRenderable : public NxOgre::UserExtendedClassAllocatable, public NxOgre::Renderable
{
  
  friend class RenderSystem;
    
  public:
    
  public:
     
     void  drawSoftBodySimple(NxOgre::MeshRenderable*, const NxOgre::Bounds3&) {}
     void  drawCloth(NxOgre::MeshRenderable*, const NxOgre::Bounds3&) {}
     void  drawClothFast(NxOgre::MeshRenderable*, const NxOgre::Bounds3&) {}
     void  drawVisualDebugger(NxOgre::VisualDebuggerMeshData*) {}
     
     /** \brief Text
     */
     void                                      drawFluid(NxOgre::PhysXParticleData*, const NxOgre::Bounds3&);
     
     /** \brief Get the Node.
     */
     Ogre::SceneNode*                          getNode();
     
     /** \brief Get the SceneManager used.
     */
     RenderSystem*                       getRenderSystem();

     /** \brief
     */
     Ogre::ParticleSystem*                     getParticleSystem();

     /** \brief
     */
     ParticleRenderable(const Ogre::String& material, RenderSystem*);
     
     /** \brief
     */
    ~ParticleRenderable();
     
  protected:
     
     void                   initialise(NxOgre::Fluid* fluid);
     
  protected:
     
     /** \brief SceneNode appointed to this OGRE3DPointRenderable.
     */
     Ogre::SceneNode*       mNode;
     
     /** \brief RenderSystem
     */
     RenderSystem*    mRenderSystem;
     
     /** \brief
     */
     Ogre::ParticleSystem*  mParticleSystem;
     
     /** \brief
     */
     Ogre::String           mMaterialName;
     
     /** \brief
     */
     NxOgre::Fluid*         mFluid;
     
};



} // namespace Critter

                                                                                       

#endif

#endif

#endif