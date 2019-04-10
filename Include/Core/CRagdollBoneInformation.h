#ifndef __CRAGDOLLBONEINFORMATION_H__
#define __CRAGDOLLBONEINFORMATION_H__

namespace Core
{
namespace Physics
{
	class CAnatomyFineTune
	{
	public:
		CAnatomyFineTune() : radius(6), mass(100.0f) { }
		CAnatomyFineTune(f32 radius, f32 mass) : radius(radius), mass(mass) { }

		f32 radius;
		f32 mass;
	};
	
	class CRagdollBoneInformation
	{
	public:
		String head[2];

		String leftArm[2];
		String leftForearm[2];
		String rightArm[2];
		String rightForearm[2];

		String upperTorso[2];
		String lowerTorso[2];

		String leftThigh[2];
		String leftShin[2];

		String rightThigh[2];
		String rightShin[2];

		// Head
		CAnatomyFineTune headTune;

		// Left Arm
		CAnatomyFineTune leftArmTune;
		CAnatomyFineTune leftForearmTune;

		// Right Arm
		CAnatomyFineTune rightArmTune;
		CAnatomyFineTune rightForearmTune;

		// Torso
		CAnatomyFineTune upperTorsoTune;
		CAnatomyFineTune lowerTorsoTune;

		// Leg
		CAnatomyFineTune leftThighTune;
		CAnatomyFineTune leftShinTune;
		CAnatomyFineTune rightThighTune;
		CAnatomyFineTune rightShinTune;

		String	ConfigFile;				// Used for Ode config xml
		String	ConfigOptions[1];		// Options to search of in the xml config file
	};
	
}
}

#endif // __CRAGDOLLBONEINFORMATION_H__