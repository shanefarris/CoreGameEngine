#ifndef _OGREODEJOINT_H_
#define _OGREODEJOINT_H_

#include "PreReqs.h"

namespace Ode 
{
	enum JointType
	{
		Type_BallJoint					= dJointTypeBall,
		Type_HingeJoint					= dJointTypeHinge,
		Type_SliderJoint				= dJointTypeSlider,
		Type_UniversalJoint				= dJointTypeUniversal,
		Type_Suspension_Joint			= dJointTypeHinge2,
		Type_FixedJoint					= dJointTypeFixed,
		Type_AngularMotorJoint			= dJointTypeAMotor,
		Type_PlanarJoint				= dJointTypePlane2D,
		Type_SliderHingeJoint			= dJointTypePR,
		Type_SliderUniversalJoint		= dJointTypePU,
		Type_PistonJoint				= dJointTypePiston
	};

	enum JointParameter
	{
		Parameter_LowStop				= dParamLoStop,
		Parameter_HighStop				= dParamHiStop,
		Parameter_MotorVelocity			= dParamVel,
		Parameter_MaximumForce			= dParamFMax,
		Parameter_FudgeFactor			= dParamFudgeFactor,
		Parameter_Bounceyness			= dParamBounce,
		Parameter_CFM					= dParamCFM,
		Parameter_ERP					= dParamERP,
		Parameter_StopERP				= dParamStopERP,
		Parameter_StopCFM				= dParamStopCFM,
		Parameter_SuspensionERP			= dParamSuspensionERP, // SuspensionJoint
		Parameter_SuspensionCFM			= dParamSuspensionCFM  // SuspensionJoint
	};

	class JointGroup
	{
		friend class World;
		friend class Joint;

	public:
        JointGroup(World *world);
		virtual ~JointGroup();

		void empty();

		dJointGroupID getJointGroupID() const;

	protected:
        dJointGroupID _joint_group;
        World *_world;
	};

	class Joint
    {
		friend class World;

	public:
		Joint(World *world, const JointGroup* group = 0);
		virtual ~Joint();

		JointType getType(); 

		void registerJoint();

		void detach();
		virtual void attach(const Body* body);
		virtual void attach(const Body* body_a,const Body* body_b); 

		Body* getFirstBody(); 
		Body* getSecondBody(); 
		
		static bool areConnected(const Body* body_a,const Body* body_b); 
		static bool areConnectedExcluding(const Body* body_a,const Body* body_b, JointType joint_type); 
	
		void enableFeedback(); 
		void disableFeedback(); 
		const Vector3& getFirstForce();
		const Vector3& getFirstTorque();
		const Vector3& getSecondForce();
		const Vector3& getSecondTorque();

		virtual void setAnchor(const Vector3& position);
		virtual const Vector3& getAnchor();
		virtual const Vector3& getAnchorError();
		virtual void setAxis(const Vector3& axis);
		virtual const Vector3& getAxis();
		virtual void setAdditionalAxis(const Vector3& axis);
		virtual const Vector3& getAdditionalAxis();
		virtual Ogre::Real getAngle();
		virtual Ogre::Real getAngleRate();
		virtual Ogre::Real getPosition();
		virtual Ogre::Real getPositionRate();

		virtual void setParameter(JointParameter parameter,Ogre::Real value,int axis = 1);
		virtual Ogre::Real getParameter(JointParameter parameter,int axis = 1);

		dJointID getJointID();

		virtual void addTorque(Ogre::Real torque, Ogre::Real torque2 = 0.0, Ogre::Real torque3 = 0.0);
		virtual void addForce(Ogre::Real force, Ogre::Real force2 = 0.0, Ogre::Real force3 = 0.0);

		dWorldID getWorldID();
		dJointGroupID getJointGroupID(const JointGroup* group) const;

	protected:
		dJointID _joint;
		dJointFeedback _feedback;
		Vector3 _axis,_anchor,_anchor_error,_additional_axis;
        Vector3 _first_force,_first_torque,_second_force,_second_torque;
        World *_world;
	};

	class BallJoint:public Joint
	{
	public:
		BallJoint(World *world, const JointGroup* group = 0);
		~BallJoint();

		virtual void setAnchor(const Vector3& position);
		virtual const Vector3& getAnchor();
		virtual const Vector3& getAnchorError();
		
		// as of ode-0.9 can set Parameter_CFM and Parameter_ERP to make the joint springy, an axis value isn't needed
		virtual void setParameter(JointParameter parameter, Ogre::Real value,int axis = 1);
		virtual Ogre::Real getParameter(JointParameter parameter,int axis = 1);
	};

	class HingeJoint:public Joint
	{
	public:
		HingeJoint(World *world, const JointGroup* group = 0);
		~HingeJoint();

		virtual void setAnchor(const Vector3& position);
		virtual const Vector3& getAnchor();
		virtual const Vector3& getAnchorError();
		virtual void setAxis(const Vector3& axis);
		virtual const Vector3& getAxis();
		virtual Ogre::Real getAngle();
		virtual Ogre::Real getAngleRate();

		virtual void setParameter(JointParameter parameter, Ogre::Real value,int axis = 1);
		virtual Ogre::Real getParameter(JointParameter parameter,int axis = 1);

		virtual void addTorque(Ogre::Real torque, Ogre::Real torque2 = 0.0, Ogre::Real torque3 = 0.0);
	};

	class SliderJoint:public Joint
	{
	public:
		SliderJoint(World *world, const JointGroup* group = 0);
		~SliderJoint();

		virtual void setAxis(const Vector3& axis);
		virtual const Vector3& getAxis();
		virtual Ogre::Real getPosition();
		virtual Ogre::Real getPositionRate();

		virtual void setParameter(JointParameter parameter, Ogre::Real value,int axis = 1);
		virtual Ogre::Real getParameter(JointParameter parameter, int axis = 1);

		virtual void addForce(Ogre::Real force, Ogre::Real force2 = 0.0, Ogre::Real force3 = 0.0);
	};

	class UniversalJoint:public Joint
	{
	public:
		UniversalJoint(World *world, const JointGroup* group = 0);
		~UniversalJoint();

		virtual void setAnchor(const Vector3& position);
		virtual const Vector3& getAnchor();
		virtual const Vector3& getAnchorError();
		virtual void setAxis(const Vector3& axis);
		virtual const Vector3& getAxis();
		virtual void setAdditionalAxis(const Vector3& axis);
		virtual const Vector3& getAdditionalAxis();

		virtual void setParameter(JointParameter parameter, Ogre::Real value, int axis = 1);
		virtual Ogre::Real getParameter(JointParameter parameter,int axis = 1);

		virtual void addTorque(Ogre::Real torque, Ogre::Real torque2 = 0.0, Ogre::Real torque3 = 0.0);
	};

	class FixedJoint:public Joint
	{
	public:
		FixedJoint(World *world, const JointGroup* group = 0);
		~FixedJoint();

		virtual void attach(const Body* body);
		virtual void attach(const Body* body_a,const Body* body_b); 
	};

	class SuspensionJoint:public Joint
	{
	public:
		SuspensionJoint(World *world, const JointGroup* group = 0);
		~SuspensionJoint();

		virtual void setAnchor(const Vector3& position);
		virtual const Vector3& getAnchor();
		virtual const Vector3& getAdditionalAnchor();
		virtual const Vector3& getAnchorError();
		virtual void setAxis(const Vector3& axis);
		virtual const Vector3& getAxis();
		virtual void setAdditionalAxis(const Vector3& axis);
		virtual const Vector3& getAdditionalAxis();
		virtual Ogre::Real getAngle();
		virtual Ogre::Real getAngleRate();
		virtual Ogre::Real getPositionRate();

		virtual void setParameter(JointParameter parameter, Ogre::Real value,int axis = 1);
		virtual Ogre::Real getParameter(JointParameter parameter,int axis = 1);

		virtual void addTorque(Ogre::Real torque, Ogre::Real torque2 = 0.0, Ogre::Real torque3 = 0.0);

	protected:
		Vector3 _anchor2;
	};

	class AngularMotorJoint:public Joint
	{
	public:
		enum Mode
		{
			Mode_UserAngularMotor	= dAMotorUser,
			Mode_EulerAngularMotor	= dAMotorEuler 
		};

		enum RelativeOrientation
		{
			RelativeOrientation_GlobalFrame = 0,
			RelativeOrientation_FirstBody	= 1,		
			RelativeOrientation_SecondBody	= 2
		};

	public:
		AngularMotorJoint(World *world, const JointGroup* group = 0);
		~AngularMotorJoint();

		void setMode(AngularMotorJoint::Mode mode);
		AngularMotorJoint::Mode getMode(); 

		void setAxisCount(int axes);
		int getAxisCount(); 

		void setAxis(int axis_number,AngularMotorJoint::RelativeOrientation orientation,const Vector3& axis);
		const Vector3& getAxis(int axis_number);
		AngularMotorJoint::RelativeOrientation getAxisRelativeOrientation(int axis_number); 

		void setAngle(int axis, Ogre::Real angle); 
		Ogre::Real getAngle(int axis); 
		Ogre::Real getAngleRate(int axis); 

		virtual void setParameter(JointParameter parameter, Ogre::Real value,int axis = 1);
		virtual Ogre::Real getParameter(JointParameter parameter,int axis = 1);

		virtual void addTorque(Ogre::Real torque, Ogre::Real torque2 = 0.0, Ogre::Real torque3 = 0.0);
	};

	/** Planar joints are for 2D physics in the x, y plane wth z=0
	*/
	class PlanarJoint:public Joint
	{
	public:
		PlanarJoint(World *world, const JointGroup* group = 0);
		~PlanarJoint();

		virtual void setParameterX(JointParameter parameter, Ogre::Real value,int axis = 1);
		virtual void setParameterY(JointParameter parameter, Ogre::Real value,int axis = 1);
		virtual void setParameterAngle(JointParameter parameter, Ogre::Real value,int axis = 1);
	};
	
	
	/** A prismatic and rotoide joint (ODE_API JointPR) combines a Slider (prismatic) and a Hinge (rotoide). 
		It can be used to decrease the number of bodies in a simulation. 
		Usually you cannot attach 2 ODE joints together they need a body in between. 
		An example of use of this type of joint can be in the creation of a hydraulic piston.
		
		The 2 axies must not be parallel. Since this is a new joint only when the 2 joint are at 
		90deg of each other was fully tested.
	*/
	class SliderHingeJoint:public Joint
	{
	public:
		SliderHingeJoint(World *world, const JointGroup* group = 0);
		~SliderHingeJoint();
		
		virtual void setAnchor(const Vector3& position);
		virtual const Vector3& getAnchor();
		
		// Equivalent to getting the Slider's extension
		virtual Ogre::Real getPosition();
		virtual Ogre::Real getPositionRate();
		
		// Set the axis for the Slider articulation
		virtual void setAxis(const Vector3& axis);
		// Get the axis for the Slider articulation
		virtual const Vector3& getAxis();
		// Set the axis for the Hinge articulation. 
		virtual void setAdditionalAxis(const Vector3& axis);
		// Get the axis for the Hinge articulation
		virtual const Vector3& getAdditionalAxis();
		
		// Set joint parameter axis = 3 for Hinge
		virtual void setParameter(JointParameter parameter, Ogre::Real value,int axis = 1);
		virtual Ogre::Real getParameter(JointParameter parameter,int axis = 1);
		
		// Applies the torque about the Hinge axis of the joint 
		virtual void addTorque(Ogre::Real torque, Ogre::Real torque2 = 0.0, Ogre::Real torque3 = 0.0);
	};
	
	
		
	/** "A piston joint is similar to a Slider joint except that rotation around the translation axis is possible."
	*/
	class PistonJoint : public Joint
	{
	public:
		PistonJoint(World *world, const JointGroup* group = 0);
		
		// "The joint will try to keep the distance of this point fixed with respect to body2. 
		// The input is specified in world coordinates. 
		// If there is no body attached to the joint this function has not effect."
		virtual void setAnchor(const Vector3& position);
		virtual const Vector3& getAnchor();
		virtual const Vector3& getAnchorError();
		
		virtual void setAxis(const Vector3& axis);
		virtual const Vector3& getAxis();
		// "This function set prismatic axis of the joint and also set the position of the joint."
		virtual void setAxisDelta(const Vector3& axis, const Vector3& initalPosition);
		
		// "Get the piston linear position.
		// When the anchor is set, the current position of body1 and the anchor is examined and that 
		// position will be the zero position"		
		virtual Ogre::Real getPosition();
		virtual Ogre::Real getPositionRate();
		
		// "Get the angle and the time derivative of this value. 
		// The angle is measured between the two bodies, or between the body and the static environment. 
		// The angle will be between -pi..pi. 
		// The only possible axis of rotation is the one defined by the dJointSetPistonAxis.
		// When the piston anchor or axis is set, the current position of the attached bodies is examined 
		// and that position will be the zero angle."
		virtual Ogre::Real getAngle();
		virtual Ogre::Real getAngleRate();
		
		// "This function create a force inside the piston and this force will be applied on the 2 bodies.
		// Then	force is apply to the center of mass of each body and the orientation of the force vector is 
		// along the axis of the piston"
		// One axis so only the first force is used
		virtual void addForce(Ogre::Real force, Ogre::Real force2 = 0.0, Ogre::Real force3 = 0.0);
		
		// Set joint parameter
		virtual void setParameter(JointParameter parameter, Ogre::Real value,int axis = 1);
		virtual Ogre::Real getParameter(JointParameter parameter,int axis = 1);
	};
}

#endif 
