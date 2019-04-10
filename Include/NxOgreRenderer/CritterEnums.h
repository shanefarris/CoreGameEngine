#ifdef _DEBUG
                                                                                       

#ifndef CRITTER_ENUMS_H
#define CRITTER_ENUMS_H

                                                                                       

namespace Critter
{

                                                                                       

namespace Enums
{

                                                                                       

enum SceneNodeDestructorBehaviour
{
 SceneNodeDestructorBehaviour_Destroy, //< \brief Destroy the SceneNode, it's children, and it's movable objects.
 SceneNodeDestructorBehaviour_Remove, //< \brief Remove itself from the Root SceneNode.
 SceneNodeDestructorBehaviour_Inherit //< \brief Use the behaviour as given by the class.
};

enum ClassTypes
{
 _OgreResource          = NxOgre::Classes::RENDERSYSTEMS_CLASSES_BEGIN + 1500,
 _OgreResourceProtocol,

};

enum RigidBodyTypes
{
 RigidBodyType_Body          = NxOgre::Enums::RigidBodyType_USER_BEGIN + 8371,
 RigidBodyType_KinematicBody,
 RigidBodyType_AnimatedCharacter
};

enum FluidRenderableType
{
 FluidType_Position     = NxOgre::Enums::RenderableType_ParticlePoints,
 FluidType_Velocity     = FluidType_Position + 100,
 FluidType_OgreParticle = FluidType_Position + 101,
};

enum AnimatedCharacterState
{
 AnimatedCharacterState_Idle,
 AnimatedCharacterState_Walk,
 AnimatedCharacterState_Run,
 AnimatedCharacterState_JumpBegin,
 AnimatedCharacterState_JumpLoop,
 AnimatedCharacterState_JumpEnd,
 AnimatedCharacterState_FallBegin,
 AnimatedCharacterState_FallLoop,
 AnimatedCharacterState_FallEnd,
};

                                                                                       

} // enums

                                                                                       

} // critter

                                                                                       

#endif


#endif