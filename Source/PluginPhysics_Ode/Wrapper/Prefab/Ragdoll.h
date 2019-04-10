#ifndef _OGREODERAGDOLL_H_
#define _OGREODERAGDOLL_H_

#include "Core/Defines.h"
#include "PrefabObject.h"
#include "../Collision.h"

#include "OgreEntity.h"
#include "OgreMatrix4.h"

namespace Ode 
{
	class Geometry;
	class SimpleSpace;
	class JointGroup;
	class EntityInformer;
	class AngularMotorJoint;
	enum JointType;
	enum GeometryClass;

    class Ragdoll : public Object, public Entity, public CollisionListener
    {
        friend class RagdollFactory;

    public:
        class PhysicalBone;
        typedef Vector<Ragdoll::PhysicalBone*> RagdollPhysicalBoneList;

    public:
		class PhysicalBone 
		{
		public:
			PhysicalBone();
			~PhysicalBone();

		public:
			Body*					_body;
			Geometry*				_geometry;
			Vector3					_original_position;
			Quaternion				_original_orientation;
			Bone*					_bone;
			PhysicalBone*			_parent_bone;
			RagdollPhysicalBoneList	_child_bones;
			Joint*					_joint;
			AngularMotorJoint*		_motor;
		};

		class BoneSettings
		{
		public:
			enum Collapse
			{
				Collapse_None,
				Collapse_Up,
				Collapse_Down
			};

		public:
			BoneSettings();
			~BoneSettings();

		public:
			GeometryClass	_geometry_class;
			JointType		_joint_type;
			Vector3			_primary_axis;
			Vector3			_secondary_axis;
			Collapse		_collapse;
			f32				_mass;
			f32				_radius;
			f32				_primary_histop;
			f32				_primary_lostop;
			f32				_secondary_histop;
			f32				_secondary_lostop;
			f32				_linear_damping;
			f32				_angular_damping;
		};

	public:
		void setDefaultBoneSettings(const Ragdoll::BoneSettings &settings);
		const Ragdoll::BoneSettings &getDefaultBoneSettings() { return _default_bone_settings; }
		
		void setBoneSettings(const String& bone_name,const Ragdoll::BoneSettings &settings);
		void setSelfCollisions(bool collide);

        void takePhysicalControl(World* world, Space* space, bool static_geometry = false);
		void turnToStone();

		void sleep();
		void sleep(Ragdoll::PhysicalBone* bone);

		void wake();
		void wake(Ragdoll::PhysicalBone* bone);

		bool isAwake();
		bool isAwake(Ragdoll::PhysicalBone* bone);

		void releasePhysicalControl();

		bool isPhysical()const { return _is_physical; }
		bool isStatic()const { return _is_static; }

		~Ragdoll();

		void update();

        virtual const AxisAlignedBox& getBoundingBox(void) const;

		bool pickTrimesh(RayGeometry *ray, Body* &body, Vector3 &position, World *world, Space* space);
		bool pickRagdoll(RayGeometry *ray, Body* &body, Vector3 &position);
		bool collision(Contact* contact);

		f32	_timeSincePhysical;

	protected:
		Ragdoll(const String& name, MeshPtr& ptr); 

		void createBoneBody(Bone *bone, Ragdoll::PhysicalBone *parent, bool static_geometry);
		void updatePhysicalBone(Ragdoll::PhysicalBone *physical_bone, const Matrix4 &this_trans, const Matrix4 &base_trans);

		void turnToStone(Ragdoll::PhysicalBone* bone);
		void releasePhysicalControl(Ragdoll::PhysicalBone* bone);
		void setRecursiveManuallyControlled(Bone* bone, const bool val);

		void pick(Ragdoll::PhysicalBone *bone, RayGeometry *ray);

		RagdollPhysicalBoneList	_root_bones;
		Ragdoll::BoneSettings	_default_bone_settings;
		Matrix4					_node_trans;
		Matrix4					_node_trans_inv;
		Quaternion				_node_orient;
		Vector3					_node_posn;
		EntityInformer*			_ei;
		SimpleSpace*			_space;
        JointGroup*				_joint_group;
		bool					_is_static;
		bool					_is_physical;

		Map<String, Ragdoll::BoneSettings>	_bone_settings;
		Vector<std::pair<Body*,Vector3> >	_hit_list;
	};

	/** Factory object for creating Ragdoll instances */
	class RagdollFactory : public MovableObjectFactory
	{
	protected:
		MovableObject* createInstanceImpl(const String& name, const NameValuePairList* params);
	public:
		RagdollFactory() { }
		~RagdollFactory() { }

		static String FACTORY_TYPE_NAME;

		const String& getType(void) const;
		void destroyInstance( MovableObject* obj); 
	}; 
}

#endif
