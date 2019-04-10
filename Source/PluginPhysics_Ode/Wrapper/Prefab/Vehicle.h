#ifndef _OGREODEVEHICLE_H_
#define _OGREODEVEHICLE_H_

#include "Core/Defines.h"
#include "PrefabObject.h"
#include "OgreVector3.h"

namespace Ode
{
	class World;
	class Space;
	class Body;
	class Contact;
	class Geometry;
	class SimpleSpace;
	class SuspensionJoint;
	class TransformGeometry;
}

namespace Ode 
{
    class Vehicle : public Object
    {
	public:
		class Engine
		{
		public:
			Engine();
			~Engine();

            void setInputs(const f32& throttle_position, const f32& brake_position);
            void setInputs(const f32& throttle_brake);
			void setInputs(bool throttle, bool brake);
			
			f32 getBrakeForce();
			f32 getPowerAtRPM(const f32& rpm);
			f32 getDesiredRPM();

			void update(const f32& time);

			// Manual gearbox
			void changeUp();
			void changeDown();
			void setGear(char code);
			void setGear(unsigned int i);

			// Information functions
			f32  getRevFactor();
			char getGearCode();
		
			// Engine parameters
			void setRevLimit(const f32& rpm);
			void setTorque(f32* torque, u32 samples);
			void setTorque(const f32& constant);
			void setTorque(const f32& minimum, const f32& maximum);

			// Braking parameters
			void setBrakeForce(const f32& force);

			// Drivetrain parameters
			void addGear(const f32& ratio, char code);
            void setFinalDrive(const f32& ratio);
			void setAutoShiftRevs(const f32& up, const f32& down);
			void setAutoBox(bool automatic);

		protected:
			Vector<std::pair<char, f32> > _gears;
			u32					          _current_gear_num;
			std::pair<char, f32>		  _current_gear;
			f32*					      _torque_curve;
			u32					          _curve_length;
			f32						      _rev_limit,_throttle_position;
			f32							  _brake_position;
			f32							  _wheel_rpm;
			f32							  _inv_rev_limit;
			f32						      _brake_force;
			f32						      _final_drive;
			f32						      _shift_up,_shift_down;
			bool						  _auto_box;
		};

		class Wheel : public Object
		{
		public:
			static const f32 FudgeFactor;

            Wheel(Vehicle* vehicle, const String& name, const String& mesh, const Vector3& position, const f32& mass, World *world, Space* space);
			~Wheel();

			void setFactors(const f32& steer, const f32& power, const f32& brake);
			void setContact(const f32& bouncyness, const f32& friction, const f32& fds)
			{
				_bouncyness = bouncyness;
				_friction = friction;
				_fds = fds;
			}

			void setSteerFactor(const f32& factor);
			void setSteerLimit(const f32& limit);
			void setSteerForce(const f32& force) { _steer_force = force; }
			void setSteerSpeed(const f32& speed) { _steer_speed = speed; }
			void setSteer(const f32& position);
			
			void setPowerFactor(const f32& power) { _power_factor = power; }
			void setBrakeFactor(const f32& brake) { _brake_factor = brake; }

			void setSuspension(const f32& spring_constant, const f32& damping_constant, const f32& step_size);

			const Vector3& getPosition();
			const Quaternion& getOrientation();
			void setPosition(const Vector3& position);

			f32 getRPM();
			f32 getSteer();

			void update(const f32& power_force, const f32& desired_rpm, const f32& brake_force);
	
            SceneNode* getSceneNode() { return _node; }
			Entity*	   getEntity() { return _entity; }
            Body*	   getBody() { return _body; }

			Geometry* getGeometry() { return _geometry; }

            f32 getRadius()const{return _radius;}

			void snapOff();

			void setupTyreContact(Contact* contact);

		protected:
			void adjustJointParameters();

			SceneNode*		  _node;
			Entity*			  _entity;
			f32				  _steer_factor;
			f32				  _steer_limit;
			f32				  _steer_force;
			f32				  _steer_speed;
			f32				  _power_factor;
			f32				  _brake_factor;
			f32				  _spring,_damping,_step;
			f32				  _bouncyness,_friction,_fds;
			f32				  _radius;
            Body*			  _body;
            Geometry*		  _geometry;
            SuspensionJoint*  _joint;
            String			  _name;
			Vehicle*		  _owner;
		};

	public:
        Vehicle(const String& name, const String& mesh, const f32& mass, World *world, Space* space, const Vector3& offset = Vector3::ZERO, Geometry* geometry = 0);
        Vehicle(const String& name, World *world, Space* space = 0, Geometry* geometry = 0);
		~Vehicle();

        Vehicle::Wheel* addWheel(const String& mesh,const Vector3& position, const f32& mass);
		Vehicle::Wheel*	findWheel(Geometry* geometry);
		static bool handleTyreCollision(Contact* contact);
		void load(const String& filename, const String& definition_name = StringUtil::BLANK);
		bool isAntiSwayEnabled()const { return _antisway; }
		void enableAntiSway(bool enable) { _antisway = enable; }

		virtual void		applyAntiSwayBarForces();
		void				update(const f32& time);

		const Vector3&		getPosition();
		const Quaternion&	getOrientation();
		const String&		getName() { return _name; }
		void				setPosition(const Vector3& position);
		void				setSuspension(const f32& spring_constant, const f32& damping_constant, const f32& step_size);
		void				setInputs(const f32& steering, const f32& throttle, const f32& brake);
		void				setInputs(const f32& steering, const f32& throttle_brake);
		void				setInputs(bool left, bool right, bool throttle, bool brake);
		void				setSteering(const f32& steering_position);
		Entity*				getEntity(){ return _entity; }
		void				setEntity(Entity *e){ _entity = e; }
        Body*		getBody(){ return _body; }
		SceneNode*			getSceneNode() { return _node; }
		Vehicle::Wheel*		getWheel(u32 i) { return _wheels[i]; }
		u32					getWheelCount() const { return (u32)_wheels.size(); }
        void				setTransNode(Ogre::SceneNode *s) { _trans_node = s; }
		SceneNode*			getTransNode(){return _trans_node;}
        Geometry*	getGeometry(){ return _geometry; }
		void				setGeometry(Geometry*g) { _geometry = g; }
		Engine*				getEngine(){ return _engine; }		
		Space*		getSpace();
        Vector3				getOffset() { return _offset ;}
		void				setOffset(const Vector3 &of);
		f32					getVelocity();
		void				setSwayForce(const f32& swayForce) { _swayForce = swayForce; }
		void				setSwayForceLimit(u32 swayForceLimit) { _swayForceLimit = swayForceLimit; }
		void				setSwayForceRate(const f32& swayRate) { _swayRate = swayRate; }
		f32					getSwayForce (const f32& swayForce) const { return _swayForce; }
		u32					getSwayForceLimit(u32 swayForceLimit) const { return _swayForceLimit; }
		f32					getSwayForceRate(const f32& swayRate) const { return _swayRate; }
		TransformGeometry*	getTransformGeometry() { return _transform; }
		void						setTransformGeometry(TransformGeometry*g) { _transform = g; }

	protected:
		SceneNode*					_node;
		SceneNode*					_trans_node;
		Entity*						_entity;
        Body*				_body;
        TransformGeometry*	_transform;
        Geometry*			_geometry;
		String						_name;
        SimpleSpace*		_space;
        Vector3						_offset;
		Vector3						_lastPosition;
		Engine*						_engine;
		bool						_antisway;
		f32							_swayForce;
		u32							_swayForceLimit;
		f32							_swayRate;
		f32							_swayLastUpdate;
		Vector<Vehicle::Wheel*>		_wheels;
	};
}

#endif

