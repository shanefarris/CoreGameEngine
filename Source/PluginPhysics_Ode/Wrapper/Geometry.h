#ifndef _OGREODEGEOMETRY_H_
#define _OGREODEGEOMETRY_H_

#include "PreReqs.h"
#include "TriangleMeshData.h"
#include "OgreMovableObject.h"
#include "OgreRenderable.h"

namespace Ogre
{
	class Terrain;
	class TerrainGroup;
}

namespace Core
{
	namespace Physics
	{
		enum E_BODY_TYPE;
		struct SPhysicsRayCastReport;
	}
}

namespace Ode 
{
    /** 
    This object is the base class for all Geometry objects in OgreOde.
    @remarks
        This object is tied either to a Body (acting as collision proxy for a physic object) 
        or to a Entity Object (which then is physically "static")
    @remarks
        It extends the OGRE UserDefinedObject to allow reverse links from Entity.
        Note that this class does not override the UserDefinedObject's getTypeId method 
        because this class is abstract.
    */  

	class TerrainGeometryHeightListener;
	class PagedTerrainGeometryHeightListener;

	enum GeometryClass
	{
		Class_Sphere		= dSphereClass,
		Class_Box			= dBoxClass,
		Class_Capsule		= dCapsuleClass,
		Class_Cylinder		= dCCylinderClass,
		Class_InfinitePlane = dPlaneClass,
		Class_Ray			= dRayClass,
		Class_TriangleMesh	= dTriMeshClass,
		Class_Terrain		= dHeightfieldClass,
		Class_Convex		= dConvexClass,
		Class_Transform		= dGeomTransformClass,
		Class_NoGeometry
	};

    class Geometry : public MovableObject
	{
		friend class Space;
        friend class World;
        friend class Body;
		friend class TransformGeometry;

	public:
        Geometry(World *world,  Space* space = 0);
		virtual ~Geometry();

		virtual void                        setBody(Body* body);
		Body*                               getBody(); 
		Space*                              getSpace(); 
		GeometryClass						getClass() const; 
		virtual void                        setPosition(const Vector3& position);
		virtual void                        setOrientation(const Quaternion& orientation);	
		virtual const Vector3&				getPosition();
		virtual const Quaternion&			getOrientation();
		virtual const AxisAlignedBox&		getAxisAlignedBox(); 
		void                                enable();
		void                                disable();
		bool                                isEnabled(); 
        void                                setCategoryBitfield(unsigned long bits); 
        void                                setCollisionBitfield(unsigned long bits); 
		ul32						getCategoryBitfield(); 
		ul32						getCollisionBitfield(); 
		void								setCustomListener(CollisionListener* listener);
		void                                setMaxContacts(unsigned int max_contacts);
		u32                        getMaxContacts() const;
		u32                        getContactHighWaterMark() const;
		void                                setEncapsulator(Geometry* encapsulator);
		Geometry*                           getEncapsulator(){return _encapsulator;}
		void                                setUserData(size_t user_data){_user_data = user_data;}
		size_t								getUserData() const {return _user_data;}
		dGeomID								getGeometryID() const;
		virtual void                        notify(Body* body);
        virtual void                        setDebug(const bool debug);
        virtual void                        createDebugObject();
        virtual void                        destroyDebugObject();
        void                                reparentDebugObject(Node* node);
        virtual void                        setDebugContact(const bool debug);
        void                                updateDebugContact();
		void                                clearOffset();
		s32                                 isOffset();
		void                                setOffsetPosition (const Vector3 &position);
		void                                setOffsetQuaternion(const Quaternion &orientation);
		void                                setOffsetWorldPosition(const Vector3 &position);		
		void                                setOffsetWorldQuaternion(const Quaternion &orientation) ;
		Vector3								getOffsetPosition();
		Quaternion							getOffsetQuaternion();
		inline void*						GetCustomData() { return m_CustomData; }
		inline void							SetCustomData(void* CustomData) { m_CustomData = CustomData; }
		inline Core::Physics::E_BODY_TYPE	GetBodyType() { return m_BodyType; }
		inline void							SetBodyType(Core::Physics::E_BODY_TYPE BodyType) { m_BodyType = BodyType; }

		int collide(Geometry* geometry, CollisionListener* listener = 0);

		virtual const	AxisAlignedBox& getBoundingBox(void) const	{return _bounding_box; };
		static const	String MovableType;
		virtual const	String& getMovableType() const { return MovableType; }; 	
		virtual f32		getBoundingRadius(void) const { return 0.0f; }
		virtual void	_updateRenderQueue(RenderQueue* queue) { }
		virtual void	visitRenderables(Renderable::Visitor* visitor, bool debugRenderables = false) { }
		virtual void	_notifyAttached(Node* parent, bool isTagPoint = false);
		virtual void	_notifyMoved();		//sets mGeometry position and orientation to match mParentNode's

	protected:
		void			   registerGeometry();
		dSpaceID		   getSpaceID(Space* space) const;
		String			   mName;
		dGeomID			   _geom;
		u32                _max_contacts;
        u32                _contact_high_water_mark;
        u32                _last_contact_num;
		static s32		   _geometry_count;
		dContact*		   _contacts;
		size_t			   _user_data;
		DebugObject*	   _debug_obj;
        Node*			   _debug_node;
        DebugContact**	   _debug_contacts;
		Geometry*		   _encapsulator;
		AxisAlignedBox	   _bounding_box;
		Quaternion		   _orientation;
		Vector3			   _position;
		World*			   _world;
		CollisionListener* _custom_listener;
		void*			   m_CustomData;
		Core::Physics::E_BODY_TYPE	m_BodyType;
	};

	//------------------------------------------------------------------------------------------------
    class SphereGeometry:public Geometry
	{
	public:
		SphereGeometry(const f32& radius, World *world, Space* space = 0);
		~SphereGeometry();

		virtual void createDebugObject();

		void setRadius(const f32& radius);
		f32  getRadius();
        f32  getPointDepth(const Vector3& point);  
	};

	//------------------------------------------------------------------------------------------------
	class BoxGeometry:public Geometry
	{
	public:
		BoxGeometry(const Vector3& size,  World *world, Space* space = 0);
		~BoxGeometry();

		virtual void createDebugObject();

		void setSize(const Vector3& size);
		const Vector3& getSize();
		f32 getPointDepth(const Vector3& point);

	protected:
		Vector3 _size;
	};

	//------------------------------------------------------------------------------------------------
	class InfinitePlaneGeometry:public Geometry
	{
	public:
		InfinitePlaneGeometry(const Plane& plane, World *world, Space* space = 0);
		~InfinitePlaneGeometry();

		void setDefinition(const Plane& plane);
		const Plane& getDefinition();
		f32 getPointDepth(const Vector3& point);

		void setPosition(const Vector3& position);
		void setOrientation(const Quaternion& orientation);	
		const Vector3& getPosition();
		const Quaternion& getOrientation();
		const AxisAlignedBox& getAxisAlignedBox(); 

	protected:
		Plane _plane;
    };
    //------------------------------------------------------------------------------------------------
	class CapsuleGeometry:public Geometry
	{
	public:
		CapsuleGeometry(const f32& radius, const f32& length, World *world, Space* space = 0);
		~CapsuleGeometry();

		virtual void createDebugObject();
 
		void setDefinition(const f32& radius, const f32& length);
		f32  getRadius();
		f32  getLength();
		f32  getPointDepth(const Vector3& point);

	};
	//------------------------------------------------------------------------------------------------
	class CylinderGeometry:public Geometry
	{
	public:
		CylinderGeometry(const f32& radius, const f32& length, World *world, Space* space = 0);
		~CylinderGeometry();

		virtual void createDebugObject();

		void setDefinition(const f32& radius, const f32& length);
		f32  getRadius();
		f32  getLength();
		f32  getPointDepth(const Vector3& point);

	};
	//------------------------------------------------------------------------------------------------
	class RayGeometry:public Geometry
	{
	public:
		RayGeometry(const f32& length, World *world, Space* space = 0);
		~RayGeometry();

		virtual void createDebugObject();
		
		void  setLength(const f32& length);
		f32   getLength();
		void  setDefinition(const Vector3& start, const Vector3& direction);
		const Vector3& getStart();
		const Vector3& getDirection();
		void  setClosestHit(bool Closest);

		Core::Physics::SPhysicsRayCastReport* GetRayCastReport() { return _report; }
		void SetRayCastReport(Core::Physics::SPhysicsRayCastReport* Report) { _report = Report; }

	protected:
		Vector3 _direction;
		Vector3 _start;
		Core::Physics::SPhysicsRayCastReport* _report;
	};

	//------------------------------------------------------------------------------------------------
	class TransformGeometry:public Geometry
	{
	public:
		TransformGeometry(World *world, Space* space);
		~TransformGeometry();

		virtual void createDebugObject();
		virtual void destroyDebugObject();

		void setEncapsulatedGeometry(Geometry* geometry);
		Geometry* getEncapsulatedGeometry() const;

	};
	//------------------------------------------------------------------------------------------------
	class TriangleMeshCollisionListener
	{
	public:
		TriangleMeshCollisionListener() { }
		virtual ~TriangleMeshCollisionListener() { }

		virtual bool collide(TriangleMeshGeometry* triangle_mesh, Geometry* geometry, int triangle) { return true; }
	};

	//------------------------------------------------------------------------------------------------
	class TriangleMeshIntersectionListener
	{
	public:
		TriangleMeshIntersectionListener() { }
		virtual ~TriangleMeshIntersectionListener() { }

		virtual void intersect(TriangleMeshGeometry* triangle_mesh, Geometry* geometry, const s32* triangles, s32 triangle_count) { }
	};

	//------------------------------------------------------------------------------------------------
	class TriangleMeshRayListener
	{
	public:
		TriangleMeshRayListener() { }
		virtual ~TriangleMeshRayListener() { }

		virtual bool collide(TriangleMeshGeometry* triangle_mesh, RayGeometry* ray, s32 triangle, const Vector3& uv) { return true; }
	};

	//------------------------------------------------------------------------------------------------
	struct TriangleMeshTriangle
	{
		Vector3 v0;
		Vector3 v1;
		Vector3 v2;
	};

	//------------------------------------------------------------------------------------------------
	class TriangleMeshGeometry:public Geometry
	{
	public:
		TriangleMeshGeometry(const Vector3* vertices, u32 vertex_count, const TriangleIndex* indices, u32 index_count, World *world, Space* space = 0);
		TriangleMeshGeometry(TriangleMeshDataPtr dataPtr, World *world, Space* space = 0);
		
		void changeTriangleMeshData(TriangleMeshDataPtr dataPtr);
		
		TriangleMeshDataPtr getTriangleMeshData() { return _dataPtr; }
		
		~TriangleMeshGeometry();

		Vector3 getPoint(u32 index, const Vector3& uv);
		TriangleMeshTriangle getTriangle(s32 index);

		void clearTemporalCoherenceCache(); 
		void enableTemporalCoherence(GeometryClass geometry_class,bool enable); 
		bool isTemporalCoherenceEnabled(GeometryClass geometry_class);

		static s32 _collisionCallback(dGeomID mesh, dGeomID object, s32 triangle);
		void setCollisionListener(TriangleMeshCollisionListener* collision_listener);

		static void _intersectionCallback(dGeomID mesh, dGeomID object, const int* triangles, s32 triangle_count);
		void setIntersectionListener(TriangleMeshIntersectionListener* intersection_listener); 

		static s32 _rayCallback(dGeomID mesh, dGeomID ray, s32 triangle, dReal u, dReal v);
		void setRayListener(TriangleMeshRayListener* ray_listener); 

		virtual void createDebugObject();

	protected:
		dTriMeshDataID	_data;
		dVector3*		_vertices;
		u32*			_indices;
		u32				_vertex_count;
        u32				_index_count;

		TriangleMeshDataPtr					_dataPtr;
		TriangleMeshCollisionListener*		_collision_listener;
		TriangleMeshIntersectionListener*	_intersection_listener;
		TriangleMeshRayListener*			_ray_listener;
	};

	//------------------------------------------------------------------------------------------------
	class ConvexGeometry : public Geometry
	{
	public:
		ConvexGeometry(const Vector3* vertices, u32 vertex_count, const u32* indices, u32 index_count, World *world, Space* space = 0);
		~ConvexGeometry();

		virtual void createDebugObject();

	protected:
		dReal*	_vertices;
		u32*	_indices;
		u32		_vertex_count;
		u32		_index_count;
	};

	//------------------------------------------------------------------------------------------------
	class TerrainGeometry : public Geometry, public RaySceneQueryListener
	{
	public:
		// Used for height terrain
        TerrainGeometry(World *world, 
                        Space* space,
                        const Vector3 &scale,
                        s32 nodes_per_sideX,
                        s32 nodes_per_sideY,
                        const f32& worldSizeX,
                        const f32& worldSizeZ,
                        bool centered,
                        const f32& thickness = 10.0f);

		// Used for paged terrain
		TerrainGeometry(World *world, 
                        Space* space,
                        int nodes_per_sideX,
                        int nodes_per_sideY,
						f32 worldSizeX,
                        f32 worldSizeZ,
                        f32 thickness = 10.0f);

		~TerrainGeometry();

		f32 getPointDepth(const Vector3& point);
		const Vector3& getPosition();
		const Quaternion& getOrientation();
		
		static dReal _heightCallback(void* data, dReal x, dReal z);
		static dReal _heightCallback(void* data, int x, int z);
		void setHeightListener(TerrainGeometryHeightListener* listener);

        inline f32 getHeightAt(const Vector3& position)
        {
            _num_query++;
            const Vector3 pos (position.x * _sample_width - (_centered?_halfWorldSizeX:0),
                position.y,
                position.z * _sample_height - (_centered?_halfWorldSizeZ:0)); 
            _ray.setOrigin(pos);
            _ray_query->setRay(_ray);
            _distance_to_terrain = static_cast<f32>(0.0f);
            _ray_query->execute(this);
            return position.y - _distance_to_terrain;
        }

		bool queryResult(MovableObject *obj, f32 distance);
		bool queryResult(SceneQuery::WorldFragment *fragment, f32 distance);

        size_t getNumQueries() const {return _num_query;};
        void resetNumQueries(){_num_query = 0;};

	protected:
		f32		_max_height;
		f32		_distance_to_terrain;
		f32		_sample_width, _sample_height;		
		Ray		_ray;
        bool	_centered;
        f32		_halfWorldSizeX; 
        f32		_halfWorldSizeZ;
        size_t	_num_query;
		bool	isPaged;
		RaySceneQuery* _ray_query;
		TerrainGeometryHeightListener* _listener;
    };

	//------------------------------------------------------------------------------------------------
	class PagedTerrainGeometry : public Geometry
	{
	public:
		// Used for paged terrain
		PagedTerrainGeometry(World *world, Space* space, Terrain* TerrainPage, TerrainGroup* Group);

		~PagedTerrainGeometry() { }

		const Vector3& getPosition();
		const Quaternion& getOrientation();
		
		static dReal _heightCallback(void* data, dReal x, dReal z);
		static dReal _heightCallback(void* data, s32 x, s32 z);

		void setHeightListener(PagedTerrainGeometryHeightListener* listener);

        inline f32 getHeightAt(const Vector3& position);

        const String& getTypeName(void) const { static String sName("Geometry Paged Terrain"); return sName; }

	protected:
		TerrainGroup*						m_TerrainGroup;
		f32									maxHeight;
		PagedTerrainGeometryHeightListener* _listener;
    };
    //------------------------------------------------------------------------------------------------
    class PlaneBoundedRegionGeometryPlaneListener
    {
    public:
        PlaneBoundedRegionGeometryPlaneListener() { }
        virtual ~PlaneBoundedRegionGeometryPlaneListener() { }

        virtual Vector<Plane>* planesAt(const Vector3& position) = 0;
    };

    //------------------------------------------------------------------------------------------------
    class PlaneBoundedRegionGeometry:public Geometry, public RaySceneQueryListener
    {
    public:
        PlaneBoundedRegionGeometry(World *world, Space* space, const AxisAlignedBox &scale);

        ~PlaneBoundedRegionGeometry();

        f32   getPointDepth(const Vector3& point);
        const Vector3& getPosition();
        const Quaternion& getOrientation();

        static Vector<Plane> * _planeCallback(void* data, dReal x, dReal z);
        static Vector<Plane> * _planeCallback(void* data, s32 x, s32 z);
        void   setPlaneListener(PlaneBoundedRegionGeometryPlaneListener* listener);

        inline Vector<Plane>* planesAt(const Vector3& position)
        {
            _num_query++;
//             const Vector3 pos (position.x * _sample_width - (_centered?_halfWorldSizeX:0),
//                                     position.y,
//                                     position.z * _sample_height - (_centered?_halfWorldSizeZ:0)); 
//             _ray.setOrigin(pos);
//             _ray_query->setRay(_ray);
//             _distance_to_terrain = static_cast<Real>(0.0);
//             _ray_query->execute(this);

            return _last_query_results;

        }

        bool queryResult(MovableObject *obj, const f32& distance);
        bool queryResult(SceneQuery::WorldFragment *fragment, const f32& distance);

        size_t getNumQueries() const { return _num_query; }
        void   resetNumQueries() { _num_query = 0; }

    protected:
        f32		_max_height;
        f32		_distance_to_terrain;
        f32		_sample_width, _sample_height;
        Ray		_ray;        
        bool	_centered;
        f32		_halfWorldSizeX; 
        f32		_halfWorldSizeZ;
        size_t	_num_query;

		RaySceneQuery*	_ray_query;
        Vector<Plane>*	_last_query_results;
		PlaneBoundedRegionGeometryPlaneListener* _listener;
    };
}

#endif
