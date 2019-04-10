#ifndef _OGREODEBODY_H_
#define _OGREODEBODY_H_

#include "PreReqs.h"
#include "OgreMovableObject.h"
#include "OgreRenderable.h"
#include "OgreSceneQuery.h"

namespace Ogre
{
	class AxisAlignedBox;
}

namespace Ode 
{
	class BodyState
	{
	public:
		BodyState() { }
		BodyState(const Vector3	&position, const Quaternion &orientation);

        void operator=(const BodyState &other);
		bool operator==(const BodyState &other) const;
		bool operator!=(const BodyState &other) const;

		// compare with another physics state for "significant" differences. used for detecting position or orientation snaps which need smoothing.
		bool isDifferent(const BodyState &other, const f32 threshold = f32(0.01)) const;

        void interpolate(const BodyState * const _previous_state, const BodyState * const _current_state, const f32 alpha);

		Vector3			_position;
		Quaternion	_orientation;
	};

	template <class T> class CircularBuffer
	{
	public:
		CircularBuffer() : head (0), tail (0) { }

		void resize(const size_t size)
		{
			head = 0;
			tail = 0;
			buffers.resize(size);
		}

		size_t size()
		{
			int count = (int)head - (int)tail;
			if (count<0 )
				count += (int) buffers.size();
			return (size_t) count;
		}

		void add(const T &buffer)
		{
			buffers[head] = buffer;
			next(head);
		}

		void remove()
		{
			assert(!empty());
			next(tail);
		}

		T& oldest()
		{
			assert(!empty());
			return buffers[tail];
		}

		T& newest()
		{
			assert(!empty());
			int index = (int)head - 1;
			if (index == -1)
				index = (int) buffers.size() - 1;

			assert(index<(size_t)buffers.size());
			return buffers[index];
		}

		T& almostNewest()
		{
			assert(buffers.size() > 1);
			int index = (int)head - 2;
			if (index == -1)
				index = (int) buffers.size() - 1;

			assert(index<(size_t)buffers.size());
			return buffers[index];
		}

		bool empty() const
		{
			return head == tail;
		}

		void next(size_t &index)
		{
			if (index  == (size_t)buffers.size()) 
				index -= (size_t)buffers.size();
			else
				index ++;
		}

		void previous(size_t &index)
		{			
			if ((int)index - 1 < 0)
				index += (size_t)buffers.size();
			else
				index --;
		}

		T& operator[](size_t index)
		{
			assert(index<(size_t)buffers.size());
			return buffers[index];
		}

	public:
		size_t head;
		size_t tail;

	private:
		std::vector<T> buffers;
	};
    
	// This object is the class defining a for all Dynamically physical objects in OgreOde. 
	// This object is tied attached to a scene node, or/and tied a Entity Object using UserDefinedObject
	class __declspec(dllexport) Body : public MovableObject
    {
		friend class Joint;
		friend class World;
		friend class Geometry;

	public:
		Body(World *world, const String& name = StringUtil::BLANK);
		~Body();

        static const String MovableType;

		inline void _historyResize(const size_t size);
		inline void updateParentNode();
		inline void updatePreviousState();
		inline void updateCurrentState();
		inline void updateDrawState ();
		inline void interpolateDrawState(const f32 alpha);
		inline void synchronise();

		inline void deriveLocation();

		// Position/Oriention/Rotation
		void setPosition(const Vector3& position); 
		void setOrientation(const Quaternion& orientation); 
		inline const Vector3& getPosition() const;
		inline const Quaternion& getOrientation() const;
		inline void updatePosition(BodyState * const bodystate);
        inline void updateOrientation(BodyState * const bodystate);

		// Velocity
		inline void setLinearVelocity(const Vector3& linear_velocity); 
		inline void setAngularVelocity(const Vector3& angular_velocity); 
		inline void setMaxAngularSpeed(const f32& speed);
		inline f32  getMaxAngularSpeed();
		const Vector3& getLinearVelocity(); 
		const Vector3& getAngularVelocity(); 

		// MovableObject methods
		inline const String& getMovableType() const; 
        void _notifyAttached(Node* parent,bool isTagPoint = false);
		inline const String& getName(void) const;
		inline void _notifyCurrentCamera(Camera* camera);
		inline const AxisAlignedBox& getBoundingBox(void) const;
		inline f32 getBoundingRadius(void) const;
        inline void _updateRenderQueue(RenderQueue* queue);
		inline void visitRenderables(Renderable::Visitor* visitor, bool debugRenderables = false) { }

		inline void setMass(const Mass& mass);
		const Mass& getMass();

		// Force/Torque
		inline void addForce(const Vector3& force); 
		inline void addTorque(const Vector3& torque); 
		inline void addRelativeForce(const Vector3& force); 
		inline void addRelativeTorque(const Vector3& torque); 
		inline void addForceAt(const Vector3& force,const Vector3& position); 
		inline void addForceAtRelative(const Vector3& force,const Vector3& position); 
		inline void addRelativeForceAt(const Vector3& force,const Vector3& position); 
		inline void addRelativeForceAtRelative(const Vector3& force,const Vector3& position); 

		inline const Vector3& getForce(); 
        inline const Vector3& getTorque(); 
        inline void setForce(const Vector3&); 
        inline void setTorque(const Vector3&); 

		inline Vector3 getPointWorldPosition(const Vector3& position);	// Given a point on a body, get that point's position in the world
		inline Vector3 getPointWorldVelocity(const Vector3& position);	// Given a point on a body, get that point's velocity in the world
		inline Vector3 getPointBodyPosition(const Vector3& position);
		inline Vector3 getVectorToWorld(const Vector3& vector);
		inline Vector3 getVectorFromWorld(const Vector3& vector);
		inline Vector3 getPointVelocity(const Vector3& position);		// Given a point (in the world), get that point's velocity in the world with respect to the body
																				// i.e. convert the global point to a relative point on the body and compute the velocity of that
																				// point on the body
		inline void wake();
		inline void sleep(); 
		inline bool isAwake() const { return _isEnabled; }
		inline void setAutoSleep(bool auto_sleep);
		inline bool getAutoSleep(); 
		inline void setAutoSleepLinearThreshold(const f32& linear_threshold);
		inline f32  getAutoSleepLinearThreshold(); 
		inline void setAutoSleepAngularThreshold(const f32& angular_threshold);
		inline f32  getAutoSleepAngularThreshold(); 
		inline void setAutoSleepSteps(int steps);
		inline int  getAutoSleepSteps(); 
		inline void setAutoSleepTime(const f32& time);
		inline f32  getAutoSleepTime(); 
		inline void setAutoSleepDefaults();

		inline void setFiniteRotationMode(bool on); 
		inline bool getFiniteRotationMode(); 
		inline void setFiniteRotationAxis(const Vector3& axis); 
		const Vector3& getFiniteRotationAxis(); 

        inline int getJointCount(); 
		inline Joint* getJoint(int index); 

		inline void setModifyParentOrientation(bool bModify);

        inline void addGeometry(Geometry *g); 
        void removeGeometry(Geometry *g); 
        inline size_t getGeometryCount(); 
        inline Geometry* getGeometry(s32 index);
        inline GeometryArray* getGeometries();

		inline void setAffectedByGravity(bool on);
		inline bool getAffectedByGravity(); 

		// Damping
		inline void setDamping(const f32& linear_damping, const f32& angular_damping);
		inline void setLinearDamping(const f32& linear_damping);
		inline void setAngularDamping(const f32& angular_damping);
		inline void setLinearDampingThreshold(const f32& threshold);
		inline void setAngularDampingThreshold(const f32& threshold);
		inline f32 getLinearDamping();
		inline f32 getAngularDamping();
		inline f32 getLinearDampingThreshold();
		inline f32 getAngularDampingThreshold();

		inline void setUserData(size_t user_data);
		inline size_t getUserData();

		inline void setDebug(const bool debug);

        // Return a string identifying the type of user defined object. Used to differentiate between different Bodies, Geometries and prefab_object
        const String& getTypeName(void) const { static String sName("Body"); return sName; }

        bool collide(void* data, Geometry *g);
        bool collide(void* data, Body *b);
        bool collidePlaneBounds(void* data, SceneQuery::WorldFragment *);

	protected:
		inline dBodyID getBodyID() const;
		void destroyDebugNode();
		void addDebugNode(Node* node);
		void recursiveSetMode(SceneNode* node);
		void applyDamping();

	protected:
		dBodyID			_body;
		String			_name;
		Node*			_debug_node;
		static int		_body_count;
		Vector3			_linear_vel;
		Vector3			_angular_vel;
		Vector3			_finite_axis;
		Vector3			_force;
		Vector3			_torque;
		Mass*			_mass;
		BodyState		_draw_state;
		bool			_is_damped;
		bool			_is_linear_damped;
		dReal			_linear_damping;
		bool			_is_angular_damped;
		dReal			_angular_damping;
		size_t			_user_data;
		GeometryArray	_geometries;			// Collision proxies, must be set up if collision enabled
		World*			_world;
		AxisAlignedBox	_bounding_box;

		// Major members
		bool			_isEnabled;
		bool			_modify_parent_orientation; 

        CircularBuffer<BodyState *> _state_history;
	};
}

#endif
