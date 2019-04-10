#ifndef __CRAGDOLL_PHYX_H__
#define __CRAGDOLL_PHYX_H__

#include "Defines.h"
#include "NxOgre\NxOgre.h"

namespace Core
{
namespace Physics
{
	struct BoneBind
	{
		Bone* bone;
		NxOgre::Actor* BoneActor;


		Vector3 BAoffset;
		String name;

		Quaternion BoneGlobalBindOrientation;
		Quaternion BoneActorGlobalBindOrientationInverse;
	};

	class CORE_EXPORT CRagdoll
	{
	protected:
		//Bone Actors and skeleton bones

		/*
		assuming we need only 15 Bone Actors to control the body

		(Head, Torso, Pelvis,
		LeftUpArm, LeftLoArm, LeftHand,
		RightUpArm, RightoArm, RightHand,
		LeftUpLeg, LeftLoLeg, LeftFoot,
		RightUpLeg, RightLoLeg, RightFoot)

		they must be named exactly like this.
		*/

		BoneBind								m_BoneBoneActorBind[15];
		std::map<String, NxOgre::Joint*>	m_Joints;
		SceneNode*						m_CharacterNode;
		NxOgre::Scene*							m_PHYSScene;
		String						m_CharacterID;
		// Wikipedia claims that normal human body has a density of 985, so its a default value ;)
		f32								m_BodyDensity;
		int										m_BonesCounter;
		BoneBind*								m_PositionControllingBone;
		bool									m_ControlToBones;
		bool									m_ControlToBoneActors;
		bool									m_ConstantlyUpdateBoneActors;

	public:
	   //creates ragdoll/collision shapes for character based on definition from file
	   CRagdoll(String fileName, SceneNode* characterSN, String id, NxOgre::Scene* PHXScene, f32 bodyDensity=985);

	   /*
	   this does NOT create a rag doll!
	   Use it for diagnostics only, it saves to a file of a given name
	   all the bones in the skeleton (their names) and their lenght's.
	   */
	   CRagdoll(String outFileName, SceneNode* characterSN);

	   //Bones from skeleton/animation have control over Bone Actors (collision bodies)
	   void setControlToBones();

	   //Bone Actors have control over animation via skeleton bones (real ragdoll)
	   void setControlToBoneActors();

	   //Bone Actors need to be updated every rendering loop? Use with setControlToBones().
	   void setConstantlyUpdateBoneActors(bool c) { m_ConstantlyUpdateBoneActors=c;};

	   bool getConstantlyUpdateBoneActors() { return m_ConstantlyUpdateBoneActors;};

	   //call this to update simulation
	   void update();

	   /*
	   By default, the position of character node is controlled by the skeleton root bone,
	   if its controlled by an Bone Actor. If not, the bone that is controlled by
	   "Pelvis" Bone Actor is chosen.

	   Here you can override this and set the bone you want to use for controlling
	   character by specifying its name.
	   */
	   void setCharacterPositionControllingBone(String n);

	protected:
	   void updateBoneActors();
	   void updateBones();
	   BoneBind* getBoneBoneActorBindByName(String n);

	   //Helper's
	   void _setControlToBones();
	   void _setControlToBoneActors();
	   void _parseSectionData(String secName, std::map<String, String> section);

	   void setRagdollBindPose();
	   
	   //performs bone->setManuallyControlled(manual) on every bone in skeleton
	   void setAllBonesToManualControll(bool manual);
	   
	   //performs bone->reset() on every bone in skeleton
	   void resetAllBones();
	   
	   void addJoints();
	}; 
}
}

#endif // __CRAGDOLL_PHYX_H__