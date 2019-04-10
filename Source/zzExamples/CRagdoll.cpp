#include "CRagdoll.h"
#include "Nxp.h"
#include "NxActor.h"

using namespace Core;
using namespace Core::Physics;

CRagdoll::CRagdoll(String fileName, SceneNode *characterSN, String id, NxOgre::Scene *PHXScene, f32 bodyDensity)
{
   m_CharacterNode = characterSN;
   m_PHYSScene=PHXScene;
   m_CharacterID=id;
   m_PositionControllingBone=NULL;
   m_BodyDensity=bodyDensity;
   m_BonesCounter=0;

   ConfigFile mRagDollCfgFile;
   mRagDollCfgFile.loadFromResourceSystem(fileName, "General");
   
   ConfigFile::SectionIterator seci = mRagDollCfgFile.getSectionIterator();

    String secName, paramName, valueName;

    while (seci.hasMoreElements())
    {
      secName = seci.peekNextKey();
        ConfigFile::SettingsMultiMap *settings = seci.getNext();
        ConfigFile::SettingsMultiMap::iterator i;

      std::map<String, String> sectionData;
       
      for (i = settings->begin(); i != settings->end(); ++i)
        {
         paramName = i->first;
            valueName = i->second;

         sectionData[paramName]=valueName;
               
        }
      if (secName!="")
	  {
         _parseSectionData(secName, sectionData);
	  }

	  
     }

   if (m_BonesCounter==15)
   {

      setControlToBones();
      setAllBonesToManualControll(true);
      setRagdollBindPose();
   
      setAllBonesToManualControll(false);

      addJoints();

      //...as we dont have root bone attached to Bone Actor, we use Pelvis BA instead
      if (!m_PositionControllingBone)
         m_PositionControllingBone=getBoneBoneActorBindByName("Pelvis");

   }
   else
	LogManager::getSingleton().logMessage( "Not enough bones declared in file: " + fileName + ". CRagdoll was not created!" );
}

void CRagdoll::_parseSectionData( String secName, std::map<String, String> section )
{
   Vector3 dimensions = StringConverter::parseVector3( section["dimensions"] );
   Vector3 offset = StringConverter::parseVector3( section["offset"] );

   Entity* ent = ( Entity* ) m_CharacterNode->getAttachedObject( 0 );

   m_BoneBoneActorBind[m_BonesCounter].name = secName;
   m_BoneBoneActorBind[m_BonesCounter].bone = ent->getSkeleton()->getBone( section["boneName"] );
   m_BoneBoneActorBind[m_BonesCounter].BAoffset = offset;

   NxOgre::RigidBodyDescription desc;
   //desc.reset();
   desc.mMass = 0.0;
   desc.mDensity = m_BodyDensity;
   desc.mType = NxOgre::Enums::RigidBodyType_Dynamic;
   desc.mBodyFlags = NxOgre::Enums::ActorFlags_DisableCollision;
   
   NxOgre::Actor* actor = NULL;
   if (section["actorShape"]==String("sphere"))
   {
	   actor = m_BoneBoneActorBind[m_BonesCounter].BoneActor = m_PHYSScene->createActor(
		  new NxOgre::Sphere(dimensions.x), Matrix44_Identity,
		  desc);
	   actor->setAngularDamping(actor->getAngularDamping() * 2);
	   actor->setLinearDamping(actor->getLinearDamping() * 2);
	   actor->setSleepAngularVelocity(actor->getSleepAngularVelocity() * 2);
	   actor->setSleepLinearVelocity(actor->getSleepLinearVelocity() * 2);
   }

   if (section["actorShape"]==String("cube"))
   {
	  actor = m_BoneBoneActorBind[m_BonesCounter].BoneActor = m_PHYSScene->createActor(
		  new NxOgre::Box(dimensions.x,dimensions.y,dimensions.z), Matrix44_Identity,
		  desc);
	  actor->setAngularDamping(actor->getAngularDamping() * 2);
	  actor->setLinearDamping(actor->getLinearDamping() * 2);
	  actor->setSleepAngularVelocity(actor->getSleepAngularVelocity() * 2);
	  actor->setSleepLinearVelocity(actor->getSleepLinearVelocity() * 2);
   }
      
   if (section["actorShape"]==String("capsule"))
   {
	  actor = m_BoneBoneActorBind[m_BonesCounter].BoneActor = m_PHYSScene->createActor(
		  new NxOgre::Capsule(dimensions.x,dimensions.y), Matrix44_Identity,
		  desc);
	  actor->setAngularDamping(actor->getAngularDamping() * 2);
	  actor->setLinearDamping(actor->getLinearDamping() * 2);
	  actor->setSleepAngularVelocity(actor->getSleepAngularVelocity() * 2);
	  actor->setSleepLinearVelocity(actor->getSleepLinearVelocity() * 2);
   }

   //he have found a root bone - use it for character positioning
   if (!m_BoneBoneActorBind[m_BonesCounter].bone->getParent())
      m_PositionControllingBone=&m_BoneBoneActorBind[m_BonesCounter];
   else
   {
	   String test = m_BoneBoneActorBind[m_BonesCounter].bone->getParent()->getName();
	   test = m_BoneBoneActorBind[m_BonesCounter].bone->getName();
	   int i = 0;
   }

   m_BonesCounter++;
}

void CRagdoll::setControlToBones()
{
   m_ControlToBones=true;

   m_ControlToBoneActors=false;
   _setControlToBones();
}

void CRagdoll::setControlToBoneActors()
{
   m_ControlToBoneActors=true;

   m_ControlToBones=false;
   _setControlToBoneActors();
}

void CRagdoll::_setControlToBones()
{
   for (int i=0; i<15; i++)
   {
	   m_BoneBoneActorBind[i].BoneActor->getNxActor()->raiseActorFlag( NX_AF_DISABLE_COLLISION );
	   m_BoneBoneActorBind[i].BoneActor->getNxActor()->raiseBodyFlag( NX_BF_KINEMATIC );
      m_BoneBoneActorBind[i].BoneActor->putToSleep();
   }
}

void CRagdoll::_setControlToBoneActors()
{
	updateBoneActors();
	setAllBonesToManualControll(true);
	resetAllBones();

	//disabling all animations
	Entity* e = ( Entity* ) m_CharacterNode->getAttachedObject( 0 );
	AnimationStateSet* set = e->getAllAnimationStates();
	AnimationStateIterator it = set->getAnimationStateIterator();
	AnimationState *anim;
     
	while( it.hasMoreElements() )
	{
		anim = it.getNext();
		anim->setTimePosition( 0 );
		anim->setEnabled( false );
		anim->setWeight( 0 );
	}
   
	for( int i = 0; i < 15; i++ )
	{
		m_BoneBoneActorBind[i].BoneActor->getNxActor()->clearActorFlag(NX_AF_DISABLE_COLLISION);
		m_BoneBoneActorBind[i].BoneActor->getNxActor()->clearBodyFlag(NX_BF_KINEMATIC);
		m_BoneBoneActorBind[i].BoneActor->wakeUp(Real(20.0 * 0.02));
		m_BoneBoneActorBind[i].BoneActor->setAngularDamping(1.0);
		m_BoneBoneActorBind[i].BoneActor->setLinearDamping(1.0);      
	}
}

void CRagdoll::updateBoneActors()
{
	Vector3 OgrePosition;
	Quaternion PhysxRotation, OgreGlobalQuat;
	
	for( int i = 0; i < 15; i++ )
	{
		//Get parent and child Positions   
		Vector3 bonePos =  m_BoneBoneActorBind[i].bone->_getDerivedPosition();
		Vector3 nextBonePos = m_BoneBoneActorBind[i].bone->getChild(0)->_getDerivedPosition();

		//get vector difference between parent and child
		Vector3 difference = nextBonePos - bonePos;
		Vector3 forward = difference.normalisedCopy();

		//Get bone Orientation and re-align
		Quaternion new_orient = Vector3::UNIT_Y.getRotationTo( forward );

		//mid point of bone
		Vector3 pos = bonePos + ( forward * ( difference.length() * 0.5f ) );

		//adjust Bone Actor placement
		pos.x += m_BoneBoneActorBind[i].BAoffset.x;
		pos.y += m_BoneBoneActorBind[i].BAoffset.y;
		pos.z += m_BoneBoneActorBind[i].BAoffset.z;

		//update Bone Actor
		m_BoneBoneActorBind[i].BoneActor->setGlobalPosition( pos + m_CharacterNode->_getDerivedPosition());
		m_BoneBoneActorBind[i].BoneActor->setGlobalOrientation( NxOgre::Matrix33(new_orient) );      
	}
}

void CRagdoll::updateBones()
{
	Quaternion PhysxRotation, OgreGlobalQuat, NodeRotationInverse = m_CharacterNode->getParentSceneNode()->getOrientation().Inverse();

	// Loop through all bones
	for( int i = 0; i < 15; i++ )
	{
		PhysxRotation = m_BoneBoneActorBind[i].BoneActor->getGlobalOrientationQuat().as<Quaternion>() * m_BoneBoneActorBind[i].BoneActorGlobalBindOrientationInverse;

		Ogre::Quaternion ParentInverse = NodeRotationInverse;

		if ( m_BoneBoneActorBind[i].bone->getParent() )
			ParentInverse = m_BoneBoneActorBind[i].bone->getParent()->_getDerivedOrientation().Inverse() * NodeRotationInverse;
		else
		{
			reVector3Df pos = m_BoneBoneActorBind[i].BoneActor->getGlobalPosition().as<reVector3Df>() - 
				m_CharacterNode->getParentSceneNode()->getOrientation() * 
				m_BoneBoneActorBind[i].bone->getPosition();
			m_CharacterNode->getParentSceneNode()->setPosition( pos);
		}

		OgreGlobalQuat = PhysxRotation * m_BoneBoneActorBind[i].BoneGlobalBindOrientation;

		m_BoneBoneActorBind[i].bone->setOrientation( ParentInverse * OgreGlobalQuat ); 
	}

	Ogre::Vector3 newPos = m_PositionControllingBone->BoneActor->getGlobalPosition().as<reVector3Df>() - 
		m_CharacterNode->getParentSceneNode()->getOrientation() * 
		m_PositionControllingBone->bone->getPosition() - m_PositionControllingBone->BAoffset;

	m_CharacterNode->getParentSceneNode()->setPosition( newPos );
}

void CRagdoll::update()
{
   if (m_ControlToBones)
      updateBoneActors();

   if (m_ControlToBoneActors)
      updateBones();
}

void CRagdoll::addJoints()
{
	NxOgre::RevoluteJointDescription rjd;
		NxOgre::JointLimitPairDescription rjdLimit;
			NxOgre::JointLimitDescription limit1;
			limit1.mValue = -0.75*NxPi;

			NxOgre::JointLimitDescription limit2;
			limit2.mValue = 0;

	rjdLimit.first = limit1;
	rjdLimit.second = limit2;
	rjd.mLimit = rjdLimit;
	rjd.mJointFlags = 0;

	NxOgre::SphericalJointDescription sjd;
	sjd.mJointFlags = 0;
		NxOgre::JointLimitDescription limit3;
		limit3.mValue = -(NxReal)0.025*NxPi;
		limit3.mRestitution = 0.5;
		NxOgre::JointLimitDescription limit4;
		limit4.mValue = (NxReal)0.025*NxPi;
		limit4.mRestitution = 1;
	sjd.mTwistLimit.first = limit3;
	sjd.mTwistLimit.second = limit4;
	sjd.mSwingLimit.mValue = (NxReal)0.15*NxPi;
	sjd.mSwingLimit.mRestitution = 0.5;
	sjd.mTwistSpring.mDamper = 1;
	sjd.mTwistSpring.mSpring = 0.5;
	sjd.mSwingSpring.mDamper = 1;
	sjd.mSwingSpring.mSpring = 0.5;
	sjd.mProjectionDistance = 0.15;
	sjd.mProjectionMode = NxOgre::Enums::JointProjectionMode_Point_MiniumDistance;

	NxOgre::SphericalJointDescription sjd2 = sjd;
	sjd2.mSwingLimit.mValue = 0.45*NxPi;
	NxOgre::JointLimitDescription limit5;
		limit5.mValue = -(NxReal)0.15*NxPi; 
		NxOgre::JointLimitDescription limit6;
		limit6.mValue = (NxReal)0.15*NxPi;
	sjd2.mTwistLimit.first = limit5;
	sjd2.mTwistLimit.second = limit6;

	NxOgre::JointDescription chestDesc;
	chestDesc.mJointFlags = 0;
   
	NxOgre::Joint* joint = NULL;

	//Neck
	joint = m_PHYSScene->createSphericalJoint(
		getBoneBoneActorBindByName("Head")->BoneActor,
		getBoneBoneActorBindByName("Torso")->BoneActor, sjd /*,pos ,sphJointParam*/);
	joint->setGlobalAxis(Vector3::UNIT_Y);
   
	//Chest
	joint = m_PHYSScene->createFixedJoint(
		getBoneBoneActorBindByName("Torso")->BoneActor,
		getBoneBoneActorBindByName("Pelvis")->BoneActor, chestDesc);
	//joint->setGlobalAxis(Vector3::UNIT_Y);

	//Left Leg
	joint=m_PHYSScene->createSphericalJoint(
		getBoneBoneActorBindByName("Pelvis")->BoneActor,
		getBoneBoneActorBindByName("LeftUpLeg")->BoneActor, sjd /*,pos,sphJointParam*/);
	joint->setGlobalAxis(Vector3::NEGATIVE_UNIT_Y);
   
	//Left knee
	joint = m_PHYSScene->createRevoluteJoint(
		getBoneBoneActorBindByName("LeftUpLeg")->BoneActor,
		getBoneBoneActorBindByName("LeftLoLeg")->BoneActor, rjd/*,-Vector3::UNIT_X,pos,jp*/);

	//Left ankle
	joint = m_PHYSScene->createRevoluteJoint(
		getBoneBoneActorBindByName("LeftLoLeg")->BoneActor,
		getBoneBoneActorBindByName("LeftFoot")->BoneActor, rjd/*,Vector3::UNIT_X,pos,jp*/);

	//Right Leg
	joint = m_PHYSScene->createSphericalJoint(
		getBoneBoneActorBindByName("Pelvis")->BoneActor,
		getBoneBoneActorBindByName("RightUpLeg")->BoneActor, sjd /*,pos,sphJointParam*/);
	joint->setGlobalAxis(Vector3::NEGATIVE_UNIT_Y);

	//Right knee
	joint = m_PHYSScene->createRevoluteJoint(
		getBoneBoneActorBindByName("RightUpLeg")->BoneActor,
		getBoneBoneActorBindByName("RightLoLeg")->BoneActor, rjd /*,-Vector3::UNIT_X,pos,jp*/);
   
	//Right ankle
	joint = m_PHYSScene->createRevoluteJoint(
		getBoneBoneActorBindByName("RightLoLeg")->BoneActor,
		getBoneBoneActorBindByName("RightFoot")->BoneActor, rjd /*,Vector3::UNIT_X,pos,jp*/);

	//Left shoulder
	joint = m_PHYSScene->createSphericalJoint(
		getBoneBoneActorBindByName("Torso")->BoneActor,
		getBoneBoneActorBindByName("LeftUpArm")->BoneActor, sjd2 /*, pos, sphJointParam2*/);
	joint->setGlobalAxis(Vector3::UNIT_X);
   
	//Left elbow
	joint = m_PHYSScene->createRevoluteJoint(
		getBoneBoneActorBindByName("LeftUpArm")->BoneActor,
		getBoneBoneActorBindByName("LeftLoArm")->BoneActor, rjd /*,Vector3::UNIT_Y,pos,jp*/);

	//Left hand
	joint = m_PHYSScene->createSphericalJoint(
		getBoneBoneActorBindByName("LeftLoArm")->BoneActor,
		getBoneBoneActorBindByName("LeftHand")->BoneActor, sjd /*, pos, sphJointParam*/);

	//Right shoulder
	joint = m_PHYSScene->createSphericalJoint(
		getBoneBoneActorBindByName("Torso")->BoneActor,
		getBoneBoneActorBindByName("RightUpArm")->BoneActor, sjd2 /*, pos, sphJointParam2*/);
	joint->setGlobalAxis(Vector3::NEGATIVE_UNIT_X);

	//Right elbow
	joint = m_PHYSScene->createRevoluteJoint(
		getBoneBoneActorBindByName("RightUpArm")->BoneActor,
		getBoneBoneActorBindByName("RightLoArm")->BoneActor, rjd /*,Vector3::UNIT_Y,pos,jp*/);

	//Right hand
	joint = m_PHYSScene->createSphericalJoint(
		getBoneBoneActorBindByName("RightLoArm")->BoneActor,
		getBoneBoneActorBindByName("RightHand")->BoneActor, sjd /*, pos,sphJointParam*/); 
}

void CRagdoll::setRagdollBindPose()
{
   updateBoneActors();
   for (int i=0; i<15; i++)
   {   
      m_BoneBoneActorBind[i].BoneGlobalBindOrientation = m_BoneBoneActorBind[i].bone->_getDerivedOrientation();
	  m_BoneBoneActorBind[i].BoneActorGlobalBindOrientationInverse =
		  NxOgre::Quat::invert(m_BoneBoneActorBind[i].BoneActor->getGlobalOrientationQuat()).as<Quaternion>();
   }
}

void CRagdoll::setAllBonesToManualControll(bool manual)
{
   Entity* e = (Entity*) m_CharacterNode->getAttachedObject( 0 );
   SkeletonInstance* skeletonInst = e->getSkeleton();
   Skeleton::BoneIterator boneI=skeletonInst->getBoneIterator();

   while(boneI.hasMoreElements())
      boneI.getNext()->setManuallyControlled(manual);   
}

void CRagdoll::resetAllBones()
{
   Entity* e = (Entity*) m_CharacterNode->getAttachedObject( 0 );
   SkeletonInstance* skeletonInst = e->getSkeleton();
   Skeleton::BoneIterator boneI=skeletonInst->getBoneIterator();

   while(boneI.hasMoreElements())
      boneI.getNext()->reset();   
}

BoneBind* CRagdoll::getBoneBoneActorBindByName(String n)
{
   for (int i=0; i<15; i++)
   {
      if (m_BoneBoneActorBind[i].name==n)
         return &m_BoneBoneActorBind[i];
   }

   return NULL;
}

void CRagdoll::setCharacterPositionControllingBone(String n)
{
   m_PositionControllingBone=getBoneBoneActorBindByName(n);
}

CRagdoll::CRagdoll(String outFileName, SceneNode* characterSN)
{
   std::ofstream file(outFileName.c_str());
   if (file)
   {
      Entity* e=(Entity*)characterSN->getAttachedObject(0);
      SkeletonInstance* skeletonInst = e->getSkeleton();
      Skeleton::BoneIterator boneI=skeletonInst->getBoneIterator();

      file<<"Creating bone lenght information from:\n";
      file<<"Mesh name: "<<e->getMesh()->getName()<<"\n";
      file<<"Skeleton name: "<<skeletonInst->getName()<<"\n\n";

      while(boneI.hasMoreElements())
      {
         Bone* bone=boneI.getNext();
         String bName=bone->getName();

         if (bone->getChild(0))
         {
         Vector3 curr = bone->_getDerivedPosition();
         Vector3 next = bone->getChild(0)->_getDerivedPosition();
 
         Vector3 difference = next-curr;
      
         //length of bone
         f32 lenght = difference.length();

         file<<bName<<"\t\t\t=\t"<<StringConverter::toString(lenght,3)<<"\n";
         if (!bone->getParent())
            file<<bName<<" is a Root Bone!\n";
         }
      }
   }
} 