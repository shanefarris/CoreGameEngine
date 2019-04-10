#ifndef _OGREODEENTITYINFORMER_H_
#define _OGREODEENTITYINFORMER_H_

#include "PreReqs.h"
#include "OgreMesh.h"
#include "TriangleMeshData.h"

namespace Ode 
{
    class EntityInformer
    {
	public:
		EntityInformer(Entity *entity,const Matrix4 &transform = Matrix4::IDENTITY);
		EntityInformer();
		~EntityInformer();

		void addEntity(Entity *entity,const Matrix4 &transform = Matrix4::IDENTITY);
		// Cannot be animated. 
		void addMesh(const MeshPtr &mesh, const Matrix4 &transform = Matrix4::IDENTITY);

		f32		getRadius();
		Vector3 getSize();
		Vector3 getCenter();

		Body* createSingleDynamicSphere(const f32& mass, World *world, Space* space = nullptr);
		Body* createSingleDynamicBox(const f32& mass, World *world, Space* space = nullptr);

		TriangleMeshGeometry* createStaticTriangleMesh(World *world, Space* space = nullptr);
		BoxGeometry* createSingleStaticBox(World *world, Space* space = nullptr);

		CapsuleGeometry* createOrientedCapsule(u8 bone, World *world, Space* space = nullptr);
		BoxGeometry* createOrientedBox(u8 bone, World *world, Space* space = nullptr);
		BoxGeometry* createAlignedBox(u8 bone, World *world, Space* space = nullptr);

		const Vector3*  getVertices();
		u32				getVertexCount();
		u32				getIndexCount();
		const TriangleIndex* getIndices();

	protected:
        void addVertexData(const VertexData *vertex_data, const VertexData *blended_data = nullptr, const Mesh::IndexMap *indexMap = nullptr);
		void addIndexData(IndexData *data, const u32 offset = 0);
		bool getBoneVertices(u8 bone, u32 &vertex_count, Vector3* &vertices);

		Entity*			_entity;
		SceneNode*		_node;
		Matrix4			_transform;
		f32				_radius;
		u32				_vertex_count;
		u32				_index_count;
		Vector3			_size;
		Vector3			_center;
        Vector3*		_vertices;
		TriangleIndex*	_indices; 
		BoneMapping*	_bone_mapping;
	};

	/** Class may create a TriangleMeshDataPtr, store and reuses it with TriangleMeshDataManager.
		This can limit the number of instances of the mesh data at a given scale to one.
		Since TriangleMeshGeometry is created using TriangleMeshDataPtr, have the advantage that 
		the TriangleMeshDataPtr can be changed without having to recreate the TriangleMeshGeometry see 
		TriangleMeshGeometry::changeTriangleMeshData().
		When TriangleMeshGeometry is created it is created at the origin with an identity orientation.
	*/
	class EntityInformerReuse : public EntityInformer
	{

	public:
		// forceRecreate will force the creation of a TriangleMeshDataPtr, use only when the mesh has undergone some change
		EntityInformerReuse(Entity *entity, const Vector3 &scale = Vector3::UNIT_SCALE, bool forceRecreate = false);
		EntityInformerReuse(const MeshPtr &mesh, const Vector3 &scale = Vector3::UNIT_SCALE, bool forceRecreate = false);
		
		~EntityInformerReuse();
		
		// Creates TriangleMeshGeometry using TriangleMeshDataPtr 
		TriangleMeshGeometry* createStaticTriangleMesh(World *world, Space* space = nullptr);
		
		// Recreates any TriangleMeshGeometry with the TriangleMeshDataPtr
		TriangleMeshGeometry* recreateStaticTriangleMesh(TriangleMeshGeometry* geom);
		
		// Shouldn't be adding Entity or Mesh, one TriangleMeshData per Mesh/Entity for any scale.
		virtual void addEntity(Entity *entity,const Matrix4 &transform = Matrix4::IDENTITY) { }
		virtual void addMesh(const MeshPtr &mesh, const Matrix4 &transform = Matrix4::IDENTITY) { }
		
		TriangleMeshDataPtr getTriangleMeshDataPtr() { return _dataPtr; }
		
	protected:
		TriangleMeshDataPtr _dataPtr;
	};

}

#endif


