
#include "Ragdoll.h"
#include "NxScene.h"
#include "NxUserContactReport.h"
#include "NxMat33.h"
#include "NxVec3.h"
#include "NxQuat.h"
#include <fstream>

Ragdoll::~Ragdoll(void)
{
	mOgreSceneMgr->destroySceneNode(mNode);
	mOgreSceneMgr->destroyEntity(mEntity);
}

Ragdoll::Ragdoll(Ogre::SceneManager *ogreSceneMgr, NxOgre::Scene *nxOgreScene, Ogre::String name, Ogre::String meshname, Ogre::Vector3 scale)
{
	mOgreSceneMgr = ogreSceneMgr;
	mNxOgreScene = nxOgreScene;
	mNode = mOgreSceneMgr->getRootSceneNode()->createChildSceneNode();
	mNode->scale(scale);
	mEntity = mOgreSceneMgr->createEntity(name, meshname);
	mNode->attachObject(mEntity);
	mNode->setPosition(0, 10, 0);
	ResetBones();
	if (Ogre::ResourceGroupManager::getSingleton().resourceExists("General", mEntity->getMesh()->getName() + ".bones"))
	{
		std::vector<sBoneActorBindConfig> bones;
		Ogre::ConfigFile cf;
		cf.loadFromResourceSystem(mEntity->getMesh()->getName() + ".bones", "General");
		Ogre::ConfigFile::SectionIterator seci = cf.getSectionIterator();
		Ogre::String secName;
		while (seci.hasMoreElements())
		{
			secName = seci.peekNextKey();
			Ogre::ConfigFile::SettingsMultiMap *Settings = seci.getNext();
			if (secName.find("Bone") != Ogre::String::npos)
			{
				Ogre::String bonename, boneparentname, shaperadius, shapelength, hinge, swing, twistmax, twistmin, ragdollcontrolbyparent;
				Ogre::ConfigFile::SettingsMultiMap::iterator i;
				for (i = Settings->begin(); i != Settings->end(); ++i)
				{
					if (i->first == "BoneName") bonename = i->second;
					if (i->first == "BoneParentName") boneparentname = i->second;
					if (i->first == "BoneLength") shapelength = i->second;
					if (i->first == "Radius") shaperadius = i->second;
					if (i->first == "Hinge") hinge = i->second;
					if (i->first == "Swing") swing = i->second;
					if (i->first == "TwistMax") twistmax = i->second;
					if (i->first == "TwistMin") twistmin = i->second;
					if (i->first == "RagdollControlByParent") ragdollcontrolbyparent = i->second;	//Fix for jaiqua
				}
				if (bonename == "" || boneparentname == "" || shaperadius == "" || hinge == "" || swing == "" || twistmax == "" || twistmin == "") continue;
				sBoneActorBindConfig boneconfig;
				boneconfig.mBoneName = bonename;
				boneconfig.mParentBoneName = boneparentname;
				boneconfig.mBoneLength = Ogre::StringConverter::parseReal(shapelength);
				boneconfig.mRadius = Ogre::StringConverter::parseReal(shaperadius);
				boneconfig.mHinge = Ogre::StringConverter::parseBool(hinge);
				boneconfig.mSwing = Ogre::StringConverter::parseReal(swing);
				boneconfig.mTwistMax = Ogre::StringConverter::parseReal(twistmax);
				boneconfig.mTwistMin = Ogre::StringConverter::parseReal(twistmin);
				boneconfig.mRagdollByParent = false;
				if (ragdollcontrolbyparent != "") boneconfig.mRagdollByParent = Ogre::StringConverter::parseBool(ragdollcontrolbyparent);
				bones.push_back(boneconfig);
			}
		}	
		CreateSkeleton(bones);
	}
	else
	{
		Ogre::LogManager::getSingleton().logMessage("Could not find " + mEntity->getMesh()->getName() + ".bones, generating new...");
		std::vector<sBoneActorBindConfig> boneconfig = CreateDummySkeleton();
		std::fstream f;
		f.open((mEntity->getMesh()->getName() + ".bones").c_str(), std::ios::out | std::ios::trunc);
		for (std::vector<sBoneActorBindConfig>::iterator i = boneconfig.begin(); i != boneconfig.end(); i++)
		{
			f << "[Bone_" << (*i).mBoneName.c_str() << "]" << std::endl;
			f << "BoneName = " << (*i).mBoneName.c_str() << std::endl;
			if ((*i).mParentBoneName != "") f << "BoneParentName = " << (*i).mParentBoneName.c_str() << std::endl;
			else f << "BoneParentName = None" << std::endl;
			f << "BoneLength = " << (*i).mBoneLength << std::endl;
			f << "Radius = 0.7f" << std::endl;
			//f << "LocalAxis = " << Ogre::StringConverter::toString((*i).mLocalAxis) << std::endl;
			f << "Hinge = False" << std::endl;
			f << "Swing = 10.0f" << std::endl;
			f << "TwistMax = 20.0f" << std::endl;
			f << "TwistMin = -20.0f" << std::endl;
			f << std::endl;
		}
		f.close();
		CreateSkeleton(boneconfig);
	}
	mAnimationState = 0;
	SetControlToBones();
}

Ogre::Bone* Ragdoll::GetRealParent(Ogre::Bone *bone)
{
	Ogre::Bone *node = bone;
	bool found = false;
	while (node->getParent())
	{
		node = (Ogre::Bone*)node->getParent();
		if (node->_getDerivedPosition() != bone->_getDerivedPosition()) return node;
	}
	return node;
}

void Ragdoll::CreateSkeleton(std::vector<sBoneActorBindConfig> config)
{
	Ogre::Vector3 scale = mEntity->getParentSceneNode()->_getDerivedScale();
	for (std::vector<sBoneActorBindConfig>::iterator i = config.begin(); i != config.end(); i++)
	{
		Ogre::Bone *bone = mEntity->getSkeleton()->getBone((*i).mBoneName);
		Ogre::Vector3 mypos = bone->_getDerivedPosition();
		Ogre::Vector3 parentpos = mEntity->getParentSceneNode()->_getDerivedPosition();
		if ((*i).mParentBoneName != "None") parentpos = mEntity->getSkeleton()->getBone((*i).mParentBoneName)->_getDerivedPosition();
		if ((*i).mBoneLength == 0.0f)
		{
			Ogre::LogManager::getSingleton().logMessage("Error in Ragdoll::CreateSkeleton: Bone length for " + (*i).mBoneName + " is 0.");
			continue;
		}
		sBoneActorBind bone_actor_bind;
		bone_actor_bind.mBone = bone;
		//NxOgre::ActorParams ap;
		//ap.setToDefault();
		//ap.mMass = 10.0f;
		//ap.mDensity = 0.0f;
		NxOgre::RigidBodyDescription ap;
		ap.mMass = 10.0;
		ap.mDensity = 0.0f;
		ap.mType = NxOgre::Enums::RigidBodyType_Dynamic;
		ap.mBodyFlags = NX_BF_VISUALIZATION;

		float capsule_radius = (*i).mRadius * ((scale.x + scale.y + scale.z) / 3);
		if (capsule_radius <= 0.1f) 
			capsule_radius = 0.1f;
		float capsule_height = (*i).mBoneLength - capsule_radius * 2.0f;
		if (capsule_height <= 0.0f) 
			capsule_height = 0.2f;

		Ogre::Quaternion q;
		q.FromAngleAxis(Ogre::Radian(Ogre::Degree(90)), Ogre::Vector3(0,0,1));
		bone_actor_bind.mActor = mNxOgreScene->createActor(new NxOgre::Capsule(capsule_radius, capsule_height), Matrix44_Identity, ap);
		bone_actor_bind.mActor->setSolverIterationCount(12);
		bone_actor_bind.mParent = 0;
		bone_actor_bind.mParentBoneName = (*i).mParentBoneName;
		bone_actor_bind.mSwing = (*i).mSwing;
		bone_actor_bind.mTwistMin = (*i).mTwistMin;
		bone_actor_bind.mTwistMax = (*i).mTwistMax;
		bone_actor_bind.mRagdollByParent = (*i).mRagdollByParent;
		bone_actor_bind.mBoneGlobalBindOrientation = bone_actor_bind.mBone->_getDerivedOrientation();
		bone_actor_bind.mBoneActorGlobalBindOrientationInverse = NxOgre::Quat::invert(bone_actor_bind.mActor->getGlobalOrientationQuat()).as<Quaternion>(); 
		mSkeleton.push_back(bone_actor_bind);
	}
	if (mSkeleton.size() != config.size())
	{
		Ogre::LogManager::getSingleton().logMessage("Error in Ragdoll::CreateSkeleton: Invalid bone configuration, canceling skeleton generation...");
		return;
	}
	for (std::vector<sBoneActorBind>::iterator i = mSkeleton.begin(); i != mSkeleton.end(); i++)
	{
		for (std::vector<sBoneActorBind>::iterator x = mSkeleton.begin(); x != mSkeleton.end(); x++)
		{
			if ((*i).mParentBoneName == (*x).mBone->getName()) (*i).mParent = &(*x);
		}
	}
	CreateJoints();
}

std::vector<sBoneActorBindConfig> Ragdoll::CreateDummySkeleton()
{
	std::vector<sBoneActorBindConfig> returner;
    Ogre::SkeletonInstance* skeletonInst = mEntity->getSkeleton();
	Ogre::Skeleton::BoneIterator boneI=skeletonInst->getBoneIterator();
	Ogre::Vector3 scale = mEntity->getParentSceneNode()->_getDerivedScale();
	while(boneI.hasMoreElements())
	{
		Ogre::Bone* bone=boneI.getNext();
		bone->getOrientation();
		bone->_getDerivedOrientation();
		bone->getInheritOrientation();
		Ogre::String bName=bone->getName();

		Ogre::Vector3 difference;
		Ogre::Vector3 mypos = bone->_getDerivedPosition();
		if (bone->getParent())
		{
			Ogre::Vector3 parentpos = GetRealParent(bone)->_getDerivedPosition();
			difference = mypos - parentpos;
		}
		if (bone->getChild(0))
		{
			Ogre::Vector3 childpos = bone->getChild(0)->_getDerivedPosition();
			if (childpos == mypos) continue;
			difference = childpos - mypos;
		}
		difference = difference * scale;
		float boneLength = difference.length();
		if (boneLength == 0.0f) continue;
		else
		{	
			Ogre::LogManager::getSingleton().logMessage(bone->getName() + " - " + Ogre::StringConverter::toString(boneLength));

			sBoneActorBindConfig bone_actor_bind;
			bone_actor_bind.mBoneName = bone->getName();
			bone_actor_bind.mParentBoneName = "None";
			bone_actor_bind.mSwing = 10.0f;
			bone_actor_bind.mTwistMin = -20.0f;
			bone_actor_bind.mTwistMax = 20.0f;
			bone_actor_bind.mBoneLength = boneLength;
			bone_actor_bind.mRagdollByParent = false;
			returner.push_back(bone_actor_bind);

		}
	}
	for (std::vector<sBoneActorBindConfig>::iterator i = returner.begin(); i != returner.end(); i++)
	{
		Ogre::Bone *bone = mEntity->getSkeleton()->getBone((*i).mBoneName);
		if (bone->getParent() == 0) continue;
		Ogre::Bone *node = GetRealParent(bone);
		for (std::vector<sBoneActorBindConfig>::iterator x = returner.begin(); x != returner.end(); x++)
		{
			Ogre::Bone *xBone = mEntity->getSkeleton()->getBone((*x).mBoneName);
			if ((*x).mParentBoneName != "None")
			{
				if ((*x).mParentBoneName == (*i).mBoneName) continue;
			}
			if (node->getName() == (*x).mBoneName)
			{
				(*i).mParentBoneName = (*x).mBoneName;
				break;
			}
			else if (node->getChild(0) && xBone->getParent())
			{
				if (node->getName() == xBone->getParent()->getName() && (*i).mBoneName != (*x).mBoneName)
				{
					(*i).mParentBoneName = (*x).mBoneName;
					break;
				}
			}
		}
	}
	return returner;
}

void Ragdoll::CreateJoints()
{
	Ogre::Vector3 scale = mEntity->getParentSceneNode()->_getDerivedScale();
	int counter = 0;
	for (std::vector<sBoneActorBind>::iterator i = mSkeleton.begin(); i != mSkeleton.end(); i++)
	{
		if ((*i).mParent == 0) continue;
		mNxOgreScene->getScene()->setActorPairFlags(*(*i).mParent->mActor->getNxActor(), *(*i).mActor->getNxActor(), NX_IGNORE_PAIR);
		NxD6JointDesc d6Desc;
		d6Desc.actor[0] = (*i).mParent->mActor->getNxActor();
		d6Desc.actor[1] = (*i).mActor->getNxActor();
		Ogre::Vector3 position = (*i).mBone->_getDerivedPosition();
		Ogre::Quaternion orientation = (*i).mBone->_getDerivedOrientation();
		if (orientation != Ogre::Quaternion())
		{
			int debug = 0;
		}
		if ((*i).mParent)
		{
			position = position - (*i).mParent->mBone->_getDerivedPosition();
			position  = (*i).mParent->mBone->getInitialOrientation().Inverse() * position;
			orientation = (*i).mParent->mBone->_getDerivedOrientation().Inverse() * orientation;
		}
		position = position * scale;

		Ogre::LogManager::getSingleton().logMessage("Creating joint: " + (*i).mParent->mBone->getName() + " + " + (*i).mBone->getName());

		// TODO
		NxOgre::Matrix44 basePose = NxOgre::Matrix44((*i).mActor->getGlobalPosition(), (*i).mActor->getGlobalOrientationQuat());
		basePose.translationIdentity();
		NxOgre::Matrix44 localPose = NxOgre::Matrix44(position, orientation);
		localPose.translationIdentity();
		d6Desc.localAxis[0] = NxOgre::Vec3( localPose * NxVec3(1.0f,0.0f,0.0f)).as<NxVec3>();
		d6Desc.localAxis[1]=NxVec3(1.0f,0.0f,0.0f);
		d6Desc.localNormal[0]= NxOgre::Vec3(localPose * NxVec3(0.0f,1.0f,0.0f)).as<NxVec3>();
		d6Desc.localNormal[1]=NxVec3(0.0f,1.0f,0.0f);
		d6Desc.setGlobalAnchor(NxOgre::Vec3(basePose * NxOgre::Vec3(0.0f,0.0f,0.0f)).as<NxVec3>());
		d6Desc.xMotion = NX_D6JOINT_MOTION_LOCKED;
		d6Desc.yMotion = NX_D6JOINT_MOTION_LOCKED;
		d6Desc.zMotion = NX_D6JOINT_MOTION_LOCKED;
		d6Desc.twistMotion = NX_D6JOINT_MOTION_FREE;
		if ((*i).mHinge)
		{
			d6Desc.swing1Motion = NX_D6JOINT_MOTION_LOCKED;
			d6Desc.swing2Motion = NX_D6JOINT_MOTION_LOCKED;
		}
		else
		{
			d6Desc.swing1Motion = NX_D6JOINT_MOTION_FREE;
			d6Desc.swing2Motion = NX_D6JOINT_MOTION_FREE;
		}

		d6Desc.flags|=NX_D6JOINT_SLERP_DRIVE;
		d6Desc.slerpDrive.driveType=NX_D6JOINT_DRIVE_POSITION;// | NX_D6JOINT_DRIVE_VELOCITY;
		d6Desc.slerpDrive.forceLimit=0.0f; //Not used with the current drive model.
		d6Desc.slerpDrive.spring=250.0f;
		d6Desc.slerpDrive.damping=0.01f;

        d6Desc.twistMotion = NX_D6JOINT_MOTION_LIMITED;
		d6Desc.twistLimit.low.value=NxMath::degToRad((*i).mTwistMin);
		d6Desc.twistLimit.low.damping=0.5f;
		d6Desc.twistLimit.low.restitution=0.0f;
		d6Desc.twistLimit.low.spring=0.0f;
		d6Desc.twistLimit.high.value=NxMath::degToRad((*i).mTwistMax);
		d6Desc.twistLimit.high.damping=0.5f;
		d6Desc.twistLimit.high.restitution=0.0f;
		d6Desc.twistLimit.high.spring=0.0f;

        d6Desc.swing1Motion = NX_D6JOINT_MOTION_LIMITED;
		d6Desc.swing1Limit.value=NxMath::degToRad((*i).mSwing);
		d6Desc.swing1Limit.damping=0.5f;
		d6Desc.swing1Limit.restitution=0.0f;

        d6Desc.swing2Motion = NX_D6JOINT_MOTION_LIMITED;
		d6Desc.swing2Limit.value=NxMath::degToRad((*i).mSwing);
		d6Desc.swing2Limit.damping=0.5f;
		d6Desc.swing2Limit.restitution=0.0f;

		NxD6Joint *d6Joint=(NxD6Joint*)mNxOgreScene->getScene()->createJoint(d6Desc);
		sD6Joint joint;
		joint.mJoint = d6Joint;
		joint.mDescription = d6Desc;
		(*i).mJoint = joint;
		counter++;
	}
	Ogre::LogManager::getSingleton().logMessage(Ogre::StringConverter::toString(counter) + " Joints wurden erstellt.");
}

void Ragdoll::UpdateBoneActors()
{
	Ogre::Vector3 scale = mEntity->getParentSceneNode()->_getDerivedScale();
	for (std::vector<sBoneActorBind>::iterator i = mSkeleton.begin(); i != mSkeleton.end(); i++)
	{
		//update Bone Actor
		(*i).mActor->setGlobalPosition(((*i).mBone->_getDerivedPosition() * scale) +  mEntity->getParentSceneNode()->_getDerivedPosition());  
		if ((*i).mParent)
		{
			Ogre::Quaternion orientation = (*i).mBone->_getDerivedOrientation();
			orientation = (*i).mParent->mBone->_getDerivedOrientation().Inverse() * orientation;
			(*i).mJoint.mJoint->setDriveOrientation(NxOgre::Quat(orientation).as<NxQuat>());
		}
		else
		{
			(*i).mActor->setGlobalOrientationQuat(NxOgre::Quat((*i).mBone->_getDerivedOrientation()));
		}

	} 
}

void Ragdoll::UpdateVisualBones()
{
	Ogre::Quaternion PhysxRotation, OgreGlobalQuat, NodeRotation = mEntity->getParentSceneNode()->_getDerivedOrientation();
	for (std::vector<sBoneActorBind>::iterator i = mSkeleton.begin(); i != mSkeleton.end(); i++)
	{
		Ogre::Bone *bone = (*i).mBone;
		if ((*i).mRagdollByParent == true)
		{
			bone = (Ogre::Bone*)(*i).mBone->getParent();
			(*i).mBone->setOrientation(Ogre::Quaternion());
		}
		PhysxRotation = (*i).mActor->getGlobalOrientationQuat().as<Quaternion>() * (*i).mBoneActorGlobalBindOrientationInverse;
		OgreGlobalQuat = PhysxRotation * (*i).mBoneGlobalBindOrientation;
		Ogre::Quaternion ParentInverse = NodeRotation.Inverse();
		if (bone->getParent())
		{
			ParentInverse = (NodeRotation * bone->getParent()->_getDerivedOrientation()).Inverse();
		}
		if ((*i).mParent == 0)
		{
			Ogre::Vector3 newPos = (*i).mActor->getGlobalPosition().as<Vector3>() - 
				(mEntity->getParentSceneNode()->_getDerivedOrientation() * 
				(bone->_getDerivedPosition() * mEntity->getParentSceneNode()->getScale()));
			mEntity->getParentSceneNode()->setPosition(newPos);
		}
		bone->setOrientation(ParentInverse * OgreGlobalQuat);
	}
}

void Ragdoll::SetAllBonesToManualControl(bool manual)
{
   Ogre::SkeletonInstance* skeletonInst = mEntity->getSkeleton();
   Ogre::Skeleton::BoneIterator boneI=skeletonInst->getBoneIterator();

   while(boneI.hasMoreElements())
   {
	   Ogre::Bone *bone = boneI.getNext();
	   bone->setManuallyControlled(manual);  
   }

}

void Ragdoll::ResetBones()
{
   Ogre::SkeletonInstance* skeletonInst = mEntity->getSkeleton();
   Ogre::Skeleton::BoneIterator boneI=skeletonInst->getBoneIterator();

   while(boneI.hasMoreElements())
	   boneI.getNext()->reset();
}

void Ragdoll::SetControlToActors()
{
	mControlledByActors = true;
	Ogre::AnimationStateSet* set = mEntity->getAllAnimationStates();
	Ogre::AnimationStateIterator it = set->getAnimationStateIterator();
	Ogre::AnimationState *anim = 0;   
	while(it.hasMoreElements())
	{
		anim = it.getNext();
		anim->setLoop(false);
        anim->setEnabled(false);
        anim->setWeight(0);
     }

	SetAllBonesToManualControl(true);
	ResetBones();
	for (std::vector<sBoneActorBind>::iterator i = mSkeleton.begin(); i != mSkeleton.end(); i++)
	{
		(*i).mActor->getNxActor()->clearBodyFlag(NxBodyFlag::NX_BF_FROZEN_POS);
		if ((*i).mParent)
		{
			(*i).mJoint.mDescription.slerpDrive.driveType=0;
			(*i).mJoint.mDescription.slerpDrive.forceLimit=0.0f;
			(*i).mJoint.mDescription.slerpDrive.spring=0.0f;
			(*i).mJoint.mDescription.slerpDrive.damping=0.0f;
			(*i).mJoint.mJoint->loadFromDesc((*i).mJoint.mDescription);
		}
	}
}

void Ragdoll::SetControlToBones()
{
	mControlledByActors = false;
	SetAllBonesToManualControl(false);
	for (std::vector<sBoneActorBind>::iterator i = mSkeleton.begin(); i != mSkeleton.end(); i++)
	{
		// TODO ?
		//(*i).mActor->raiseActorFlag(NxActorFlag::NX_AF_DISABLE_RESPONSE);
		(*i).mActor->getNxActor()->raiseBodyFlag(NxBodyFlag::NX_BF_FROZEN_POS);
		if ((*i).mParent)
		{
			(*i).mJoint.mDescription.slerpDrive.driveType=NX_D6JOINT_DRIVE_POSITION;
			(*i).mJoint.mDescription.slerpDrive.forceLimit=0.0f;
			(*i).mJoint.mDescription.slerpDrive.spring=250.0f;
			(*i).mJoint.mDescription.slerpDrive.damping=0.0f;
			(*i).mJoint.mJoint->loadFromDesc((*i).mJoint.mDescription);
		}
	}
}

void Ragdoll::SetAnimationState(Ogre::String statename)
{
	mAnimationState = mEntity->getAnimationState(statename);
	mAnimationState->setLoop(true);
	mAnimationState->setEnabled(true);
}

void Ragdoll::Update(float _time)
{
	if (mControlledByActors)
	{
		UpdateVisualBones();
	}
	else
	{
		if (mAnimationState)
		{
			mAnimationState->addTime(_time);
		}
		UpdateBoneActors();
	}
}