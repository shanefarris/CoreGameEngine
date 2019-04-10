
#pragma once

#include "Ogre.h"
#include "NxOgre\NxOgre.h"
#include "Nxp.h"
#include "NxD6Joint.h"
#include "NxD6JointDesc.h"
#include "Defines.h"
#include <vector>

using namespace Ogre;
using namespace NxOgre;
using namespace NxOgre::Enums;

struct sD6Joint
{
	NxD6Joint *mJoint;
	NxD6JointDesc mDescription;
};


struct sBoneActorBind
{
	Ogre::Bone *mBone;
	NxOgre::Actor *mActor;
	sBoneActorBind *mParent;
	Ogre::String mParentBoneName;
	bool mRagdollByParent;
	sD6Joint mJoint;
	Ogre::Vector3 mLocalAxis;
	float mBoneLength;
	bool mHinge;
	float mSwing;
	float mTwistMax;
	float mTwistMin;
	Ogre::Quaternion mBoneGlobalBindOrientation;
	Ogre::Quaternion mBoneActorGlobalBindOrientationInverse;
};

struct sBoneActorBindConfig
{
	Ogre::String mBoneName;
	Ogre::String mParentBoneName;
	bool mRagdollByParent;
	float mBoneLength;
	float mRadius;
	bool mHinge;
	float mSwing;
	float mTwistMax;
	float mTwistMin;
};

class CORE_EXPORT Ragdoll
{
private:
	Ogre::SceneNode *mNode;
	Ogre::SceneManager *mOgreSceneMgr;
	NxOgre::Scene *mNxOgreScene;
	std::vector<sD6Joint> mJoints;
	std::vector<sBoneActorBind> mSkeleton;
	Ogre::Entity *mEntity;
	Ogre::AnimationState *mAnimationState;
	bool mControlledByActors;

	/*
	CreateDummySkeleton creates a ragdoll skeleton from scratch.
	They are only used the first time the ragdoll is created, after that a config file will be exported.
	*/
	std::vector<sBoneActorBindConfig> CreateDummySkeleton();

	void CreateJoints();

	/*
	Creates a skeleton from a config file.
	*/
	void CreateSkeleton(std::vector<sBoneActorBindConfig> config);

	Ogre::Bone* GetRealParent(Ogre::Bone *bone);

	void UpdateBoneActors();
	void UpdateVisualBones();
	void SetAllBonesToManualControl(bool manual);
	void ResetBones();

public:
	Ragdoll(Ogre::SceneManager *ogreSceneMgr, NxOgre::Scene *nxOgreScene, Ogre::String name, Ogre::String meshname, Ogre::Vector3 scale = Ogre::Vector3(1,1,1));
	~Ragdoll(void);

	void SetControlToActors();
	void SetControlToBones();

	Ogre::SceneNode* GetNode() { return mNode; }
	Ogre::Entity* GetEntity() { return mEntity; }

	void SetAnimationState(Ogre::String statename);

	void Update(float _time);
};
