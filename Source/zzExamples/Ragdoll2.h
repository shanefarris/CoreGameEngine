//#include "Ogre.h"
//#include "NxOgre\NxOgre.h"
//#include "Nxp.h"
//#include "NxD6Joint.h"
//#include "NxD6JointDesc.h"
//#include "Defines.h"
//#include <vector>
//
//struct PHYSX_BONE
//{
//public:
//   PHYSX_BONE(NxActor* Actor, Bone* Bone);
//   void SetOgreBone(Bone* pBone);
//   void SetPhysxBone(NxActor* Actor);
//
//   NxActor* pPhysxBone;
//   Quaternion PhysxBindOrientationInverse;
//   Bone* pOgreBone;
//   Quaternion OgreGlobalBindOrientation;
//};
//
//PHYSX_BONE::PHYSX_BONE(NxActor* Actor, Bone* Bone)
//{
//   SetPhysxBone(Actor);
//   SetOgreBone(Bone);
//}
//
//void PHYSX_BONE::SetOgreBone(Bone* pBone)
//{
//   pOgreBone = pBone;
//   OgreGlobalBindOrientation = pBone->_getDerivedOrientation();
//}
//
//void PHYSX_BONE::SetPhysxBone(NxActor* Actor)
//{
//   pPhysxBone = Actor;
//   PhysxBindOrientationInverse = Actor->getGlobalOrientationQuat().Inverse();
//}
//
//vector<PHYSX_BONE> m_RagDollBones;
//vector<NxJoint* > m_RagDollJoints;
//Entity* m_pEntity = NULL;
//
//// ***************************************************************************************
//
//void CreateRagDoll()
//{
//   float Density = 1;
//
//   SkeletonInstance* pSkeleton = m_pEntity->getSkeleton();
//
//   // BONE POSITIONS
//   Vector3 RootPos = pSkeleton->getBone("root")->_getDerivedPosition();
//   Vector3 VertPos = pSkeleton->getBone("vertebre_1")->_getDerivedPosition();
//   Vector3 NeckPos = pSkeleton->getBone("cou")->_getDerivedPosition();
//
//   Vector3 LeftLegPos = pSkeleton->getBone("hanche_gauche")->_getDerivedPosition();
//   Vector3 RightLegPos = pSkeleton->getBone("hanche_droite")->_getDerivedPosition();
//   Vector3 LeftKneePos = pSkeleton->getBone("tibia_gauche")->_getDerivedPosition();
//   Vector3 RightKneePos = pSkeleton->getBone("tibia_droite")->_getDerivedPosition();
//   Vector3 LeftAnklePos = pSkeleton->getBone("cheville_gauche")->_getDerivedPosition();
//   Vector3 RightAnklePos = pSkeleton->getBone("cheville_droite")->_getDerivedPosition();
//
//   Vector3 LeftArmPos = pSkeleton->getBone("bras_gauche")->_getDerivedPosition();
//   Vector3 RightArmPos = pSkeleton->getBone("bras_droite")->_getDerivedPosition();
//   Vector3 LeftElbowPos = pSkeleton->getBone("grandavantbras_gauche")->_getDerivedPosition();
//   Vector3 RightElbowPos = pSkeleton->getBone("grandavantbras_droite")->_getDerivedPosition();
//   Vector3 LeftWristPos = pSkeleton->getBone("poignet_gauche")->_getDerivedPosition();
//   Vector3 RightWristPos = pSkeleton->getBone("poignet_droite")->_getDerivedPosition();
//
//   // CREATE ACTOR SHAPES
//   NxActor* Torso = GAME->CreateBox(RootPos-Vector3(1, 0, 1), RootPos+Vector3(1, 2, 1), RootPos, Density);
//   NxActor* UpperTorso = GAME->CreateBox(RootPos-Vector3(1.6, -2, 1), RootPos+Vector3(1.6, 4, 1.5), VertPos, Density);
//   NxActor* Head = GAME->CreateSphere(NeckPos+Vector3(0, 0.1, 0.4), 1, NeckPos, Density);
//
//   NxActor* LeftLeg = GAME->CreateCapsule(LeftLegPos, LeftKneePos, 0.5, Density);
//   NxActor* RightLeg = GAME->CreateCapsule(RightLegPos, RightKneePos, 0.5, Density);
//   NxActor* LeftLowerLeg = GAME->CreateCapsule(LeftKneePos, LeftAnklePos, 0.5, Density);
//   NxActor* RightLowerLeg = GAME->CreateCapsule(RightKneePos, RightAnklePos, 0.5, Density);
//   NxActor* LeftFoot = GAME->CreateBox(LeftAnklePos-Vector3(0.5, 0.4, 0), LeftAnklePos+Vector3(0.5, 0, 2.2), LeftAnklePos, Density);
//   NxActor* RightFoot = GAME->CreateBox(RightAnklePos-Vector3(0.5, 0.4, 0), RightAnklePos+Vector3(0.5, 0, 2.2), RightAnklePos, Density);
//
//   NxActor* LeftArm = GAME->CreateCapsule(LeftArmPos, LeftElbowPos, 0.75, Density);
//   NxActor* RightArm = GAME->CreateCapsule(RightArmPos, RightElbowPos, 0.75, Density);
//   NxActor* LeftFrontArm = GAME->CreateCapsule(LeftElbowPos, LeftWristPos, 0.75, Density);
//   NxActor* RightFrontArm = GAME->CreateCapsule(RightElbowPos, RightWristPos, 0.75, Density);
//   NxActor* LeftHand = GAME->CreateBox(LeftWristPos-Vector3(0, 0.2, 0.4), LeftWristPos+Vector3(1.5, 0.2, 0.4), LeftWristPos, Density);
//   NxActor* RightHand = GAME->CreateBox(RightWristPos-Vector3(1.5, 0.2, 0.4), RightWristPos+Vector3(0, 0.2, 0.4), RightWristPos, Density);
//
//   // ADD ACTORS
//   m_RagDollBones.push_back(PHYSX_BONE(Torso, pSkeleton->getBone("root")));
//   m_RagDollBones.push_back(PHYSX_BONE(UpperTorso, pSkeleton->getBone("vertebre_1")));
//   m_RagDollBones.push_back(PHYSX_BONE(Head, pSkeleton->getBone("cou")));
//
//   m_RagDollBones.push_back(PHYSX_BONE(LeftLeg, pSkeleton->getBone("hanche_gauche")));
//   m_RagDollBones.push_back(PHYSX_BONE(RightLeg, pSkeleton->getBone("hanche_droite")));
//   m_RagDollBones.push_back(PHYSX_BONE(LeftLowerLeg, pSkeleton->getBone("tibia_gauche")));
//   m_RagDollBones.push_back(PHYSX_BONE(RightLowerLeg, pSkeleton->getBone("tibia_droite")));
//   m_RagDollBones.push_back(PHYSX_BONE(LeftFoot, pSkeleton->getBone("cheville_gauche")));
//   m_RagDollBones.push_back(PHYSX_BONE(RightFoot, pSkeleton->getBone("cheville_droite")));
//
//   m_RagDollBones.push_back(PHYSX_BONE(LeftArm, pSkeleton->getBone("bras_gauche")));
//   m_RagDollBones.push_back(PHYSX_BONE(RightArm, pSkeleton->getBone("bras_droite")));
//   m_RagDollBones.push_back(PHYSX_BONE(LeftFrontArm, pSkeleton->getBone("grandavantbras_gauche")));
//   m_RagDollBones.push_back(PHYSX_BONE(RightFrontArm, pSkeleton->getBone("grandavantbras_droite")));
//   m_RagDollBones.push_back(PHYSX_BONE(LeftHand, pSkeleton->getBone("poignet_gauche")));
//   m_RagDollBones.push_back(PHYSX_BONE(RightHand, pSkeleton->getBone("poignet_droite")));
//
//   // CREATE JOINTS
//   m_RagDollJoints.push_back(GAME->CreateBodyRevoluteJoint(Torso.get(), UpperTorso.get(), VertPos, Vector3::UNIT_Y, -0.25*NxPi, 0.25*NxPi));
//   m_RagDollJoints.push_back(GAME->CreateBodySphericalJoint(UpperTorso.get(), Head.get(), NeckPos, Vector3::UNIT_Z, 0.1*NxPi, 0.1*NxPi));
//
//   m_RagDollJoints.push_back(GAME->CreateBodySphericalJoint(Torso.get(), LeftLeg.get(), LeftLegPos, (LeftKneePos-LeftLegPos).normalisedCopy(), 0.25*NxPi, 0.25*NxPi));
//   m_RagDollJoints.push_back(GAME->CreateBodySphericalJoint(Torso.get(), RightLeg.get(), RightLegPos, (RightKneePos-RightLegPos).normalisedCopy(), 0.25*NxPi, 0.25*NxPi));
//   m_RagDollJoints.push_back(GAME->CreateBodyRevoluteJoint(LeftLeg.get(), LeftLowerLeg.get(), LeftKneePos, Vector3::UNIT_X, -NxPi, 0));
//   m_RagDollJoints.push_back(GAME->CreateBodyRevoluteJoint(RightLeg.get(), RightLowerLeg.get(), RightKneePos, Vector3::UNIT_X, -NxPi, 0));
//   m_RagDollJoints.push_back(GAME->CreateBodyRevoluteJoint(LeftLowerLeg.get(), LeftFoot.get(), LeftKneePos, Vector3::UNIT_X, -0.1*NxPi, 0.1*NxPi));
//   m_RagDollJoints.push_back(GAME->CreateBodyRevoluteJoint(RightLowerLeg.get(), RightFoot.get(), RightKneePos, Vector3::UNIT_X, -0.1*NxPi, 0.1*NxPi));
//
//   m_RagDollJoints.push_back(GAME->CreateBodySphericalJoint(UpperTorso.get(), LeftArm.get(), LeftArmPos, Vector3::UNIT_X, 0.4*NxPi, 0.25*NxPi));
//   m_RagDollJoints.push_back(GAME->CreateBodySphericalJoint(UpperTorso.get(), RightArm.get(), RightArmPos, -Vector3::UNIT_X, 0.4*NxPi, 0.25*NxPi));
//   m_RagDollJoints.push_back(GAME->CreateBodyRevoluteJoint(LeftArm.get(), LeftFrontArm.get(), LeftElbowPos, Vector3::UNIT_Y, 0, NxPi));
//   m_RagDollJoints.push_back(GAME->CreateBodyRevoluteJoint(RightArm.get(), RightFrontArm.get(), RightElbowPos, -Vector3::UNIT_Y, 0, NxPi));
//   m_RagDollJoints.push_back(GAME->CreateBodySphericalJoint(LeftFrontArm.get(), LeftHand.get(), LeftWristPos, Vector3::UNIT_X, 0.5*NxPi, 0.25*NxPi));
//   m_RagDollJoints.push_back(GAME->CreateBodySphericalJoint(RightFrontArm.get(), RightHand.get(), RightWristPos, -Vector3::UNIT_X, 0.5*NxPi, 0.25*NxPi));
//
//}
////
////// **********************************************************************************************
////void CPlayer::FitMeshToRagDoll()
////{
////   vector<PHYSX_BONE>::iterator itBone;
////   Quaternion PhysxRotation, OgreGlobalQuat, NodeRotationInverse = m_pNode->getOrientation().Inverse();
////   for (itBone = m_RagDollBones.begin(); itBone != m_RagDollBones.end(); ++itBone)
////   {
////      PhysxRotation = Convert(itBone->pPhysxBone->getGlobalOrientationQuat())*itBone->PhysxBindOrientationInverse;
////      Quaternion ParentInverse = NodeRotationInverse;
////      if (itBone->pOgreBone->getParent())
////         ParentInverse = itBone->pOgreBone->getParent()->_getDerivedOrientation().Inverse() * NodeRotationInverse;
////      else
////         m_pNode->setPosition(Convert(itBone->pPhysxBone->getGlobalPosition()) - m_pNode->getOrientation()*itBone->pOgreBone->getPosition());
////      OgreGlobalQuat = PhysxRotation * itBone->OgreGlobalBindOrientation;
////      itBone->pOgreBone->setOrientation(ParentInverse * OgreGlobalQuat);
////   }
////}
////
////void CPlayer::FitRagDollToMesh()
////{
////   vector<PHYSX_BONE>::iterator itBone;
////   Quaternion PhysxRotation, OgreGlobalQuat;
////   Vector3 OgrePosition;
////   for (itBone = m_RagDollBones.begin(); itBone != m_RagDollBones.end(); ++itBone)
////   {
////      OgrePosition = (m_pNode->getOrientation() * itBone->pOgreBone->_getDerivedPosition()) + m_pNode->getPosition();
////      OgreGlobalQuat = itBone->pOgreBone->_getDerivedOrientation() * itBone->OgreGlobalBindOrientation.Inverse();
////      PhysxRotation = OgreGlobalQuat * itBone->PhysxBindOrientationInverse.Inverse();
////      itBone->pPhysxBone->setGlobalPosition(Convert(OgrePosition));
////      itBone->pPhysxBone->setGlobalOrientationQuat(Convert(m_pNode->getOrientation() * PhysxRotation));
////   }
////}
////
////// ***************************************************************************************************
////void CPlayer::SetRagDoll(bool bRagDoll)
////{
////   m_bRagDoll = bRagDoll;
////   if (bRagDoll)
////   {
////      FitRagDollToMesh();
////   }
////   SkeletonInstance* pSkeleton = m_pEntity->getSkeleton();
////   Skeleton::BoneIterator BoneIter = pSkeleton->getBoneIterator();
////   Bone* pBone;
////   while (BoneIter.hasMoreElements())
////   {
////      pBone = BoneIter.getNext();
////      pBone->setManuallyControlled(bRagDoll);
////      if (bRagDoll)
////         pBone->reset();
////   }
////   if (bRagDoll)
////   {
////      m_UpperAnimation = "";
////      m_LowerAnimation = "";
////      AnimationStateSet *set = m_pEntity->getAllAnimationStates();
////      AnimationStateIterator it = set->getAnimationStateIterator();
////      AnimationState *anim;
////      while(it.hasMoreElements())
////      {
////         anim = it.getNext();
////         anim->setEnabled(false);
////         anim->setWeight(0);
////      }
////   }
////   else
////   {
////      pSkeleton->getBone("vertebre_1")->setManuallyControlled(true);
////   }
////   vector<PHYSX_BONE>::iterator itBone;
////   for (itBone = m_RagDollBones.begin(); itBone != m_RagDollBones.end(); ++itBone)
////   {
////      if (bRagDoll)
////      {
////         itBone->pPhysxBone->clearActorFlag(NX_AF_DISABLE_COLLISION);
////         itBone->pPhysxBone->clearBodyFlag(NX_BF_KINEMATIC);
////         itBone->pPhysxBone->wakeUp();
////      }
////      else
////      {
////         itBone->pPhysxBone->raiseActorFlag(NX_AF_DISABLE_COLLISION);
////         itBone->pPhysxBone->raiseBodyFlag(NX_BF_KINEMATIC);
////         itBone->pPhysxBone->putToSleep();
////      }
////   }
////}