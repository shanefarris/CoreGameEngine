#ifndef _OGREODEWORLD_H_
#define _OGREODEWORLD_H_

#include "Core/Defines.h"
#include "ode/ode.h"
#include "OgreVector3.h"

namespace Ode 
{
	class Body;
	class JointGroup;
	class Joint;
	class Space;
	class Geometry;
	class StepHandler;
	class CollisionListener;

	/** The main class which you will use to simulate your world.
     * 
	 * This is the core class of OgreOde, it is directly analogous to the ODE world except that
	 * in OgreOde you can have only one world, which is why it is Singleton.
	 *
	 * A World is a container for all the bodies and geometries in you simulation. You also
	 * use it to set global options for things like gravity, ERP, CFM and automatic sleeping.
	 * Also, the World is what you step when you want to advance your simulation by a certain time
	 * period.
	 */
	class __declspec(dllexport) World
    {
        friend class Body;
		friend class JointGroup;
		friend class Joint;
		friend class Space;
		friend class Geometry;
		friend class StepHandler;

	public:
		/** Construct a new World.
		 * 
		 * You will need to call this to create the World into which you cabn place your physical objects.
		 * The World requires a reference to the scene manager you are using in order to create things
		 * like nodes for debug objects and to obtain configuration options for world geometry.
		 */
		World(SceneManager* manager);
		~World();

		void setGravity(const Vector3& gravity = Vector3::ZERO);
		const Vector3& getGravity();

		void setHistorySize(size_t historySize);
		size_t getHistorySize() const;

		void setERP(const f32& erp = 0.2);
		f32 getERP();
		void setCFM(const f32& cfm = 10e-5);
		f32 getCFM();

		void setContactCorrectionVelocity(const f32& velocity = 0.1);
		f32  getContactCorrectionVelocity();
		void setContactSurfaceLayer(const f32& layer = 0.001);
		f32  getContactSurfaceLayer();

		void setAutoSleep(bool auto_sleep = false);
		bool getAutoSleep();
		void setAutoSleepLinearThreshold(const f32& linear_threshold = 0.01);
		f32  getAutoSleepLinearThreshold();
		void setAutoSleepAngularThreshold(const f32& angular_threshold = 0.01);
		f32  getAutoSleepAngularThreshold();
		void setAutoSleepSteps(int steps = 10);
		int  getAutoSleepSteps();
		void setAutoSleepTime(const f32& time = 0);
		f32  getAutoSleepTime(); 
        void setAutoSleepAverageSamplesCount(unsigned int  time = 10);
        int  getAutoSleepAverageSamplesCount();
		inline void step(const f32& stepsize); 
        inline void quickStep(const f32& stepsize);

		void setQuickStepIterations(int iterations);
		int  getQuickStepIterations();

		Body* findBody(Ogre::SceneNode* node);
		Body* findBody(const String& name);

		inline void clearContacts();

		void setCollisionListener(CollisionListener* collision_listener);
		CollisionListener* getCollisionListener();

		// Debug
		void setShowDebugGeometries(bool show);
        bool getShowDebugGeometries() { return _show_debug_geoms; }
        void setShowDebugContact(bool show);
        bool getShowDebugContact() { return _show_debug_contact; }

		inline void notifyGeometry(Body* body);

		Space* getDefaultSpace() { return _default_space; }
		void setDefaultSpace(Space* space);

		inline SceneManager* getSceneManager() { return _manager; }

		// Damping
		void setDamping(const f32& linear_damping, const f32& angular_damping);
		f32  getLinearDamping();
		f32  getAngularDamping();
		f32  getLinearDampingThreshold();
		f32  setAngularDampingThreshold();
		void setLinearDampingThreshold(const f32& Threshold);
		void setAngularDampingThreshold(const f32& Threshold);

//dReal dWorldGetLinearDampingThreshold (dWorldID);
//dReal dWorldGetAngularDampingThreshold (dWorldID);
//void dWorldSetLinearDampingThreshold (dWorldID, dReal threshold);
//void dWorldSetAngularDampingThreshold (dWorldID, dReal threshold);

		// Maximum angular speed
		f32  GetMaxAngularSpeed();
		void SetMaxAngularSpeed(const f32& max_speed);

		inline void synchronise();
	
		inline void updateDrawState();
		inline void updatePreviousState();
		inline void updateCurrentState();
		inline void interpolateDrawState(const f32& alpha);

		inline void		 AddBody(Body* body);
		inline void		 RemoveBody(dBodyID BodyId);

		inline void		 AddJoint(Joint* join);
		inline void		 RemoveJoint(dJointID JoinId);
		inline Joint*	 GetJoint(dJointID JoinId);

		inline void		 AddJoinGroup(JointGroup* joinGroup);
		inline void		 RemoveJoinGroup(dJointGroupID JoinGroupId);

		inline void		 AddGeometry(Geometry* geometry);
		inline void		 RemoveGeometry(dGeomID GeometryId);
		inline Geometry* GetGeometry(dGeomID GeometryId);

		inline void		 AddSpace(Space* space);
		inline void		 RemoveSpace(dSpaceID SpaceId);
		inline Space*	 GetSpace(dSpaceID SpaceId);

        inline dWorldID	 getWorldID();

	protected:
        inline dJointGroupID getContactGroupID();
		static void  collisionCallback(void *data, dGeomID geom_a, dGeomID geom_b);

	protected:
		dWorldID						_world;
		dJointGroupID					_contacts;
		Space*							_default_space;
		static CollisionListener*		_collision_listener;
		Map<dBodyID, Body*>				_body_list;
		Map<dJointID, Joint*>			_joint_list;
		Map<dJointGroupID, JointGroup*> _joint_group_list;
		Map<dGeomID, Geometry*>			_geometry_list;
		Map<dSpaceID, Space*>			_space_list;
        bool							_show_debug_geoms;
        bool							_show_debug_contact;
		SceneManager*        			_manager;
		Vector3							_gravity;
		f32								_linear_damping;
		f32								_angular_damping;
		size_t							_history_size;
	};

}
#endif
