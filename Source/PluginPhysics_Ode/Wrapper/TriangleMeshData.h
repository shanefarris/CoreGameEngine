#ifndef __OgreOdeTriangleMeshData_H__
#define __OgreOdeTriangleMeshData_H__

#include "PreReqs.h"
#include "OgreSceneQuery.h"

namespace Ogre
{
	class RaySceneQuery;
}

namespace Ode
{
	/** Stores triangle mesh data once and shares it between all geoms that require it
	*/
	class TriangleMeshData
	{
	public:

		TriangleMeshData(Ogre::String name, Vector3 scale, const Vector3* vertices, unsigned int vertex_count, const TriangleIndex* indices, unsigned int index_count);

		virtual ~TriangleMeshData();
		
		Ogre::String getMeshName(){ return _name; }
		
		Vector3 getScale(){ return _scale; }

		dTriMeshDataID getData(){ return _data; }

		dVector3* getVertices(){ return _vertices; }

		TriangleIndex* getIndices(){ return _indices; }
	
		unsigned int getVertexCount(){ return _vertex_count; }

		unsigned int getIndexCount(){ return _index_count; }		
		
	protected:
	
		Ogre::String _name;
		Vector3 _scale;
		dTriMeshDataID _data;
		dVector3* _vertices;
		TriangleIndex* _indices;
		unsigned int _vertex_count;
        unsigned int _index_count;
	};

	/** SharedPtr of TriangleMeshData
	*/
	class TriangleMeshDataPtr : public Ogre::SharedPtr<TriangleMeshData> 
	{
	public:
		TriangleMeshDataPtr() : Ogre::SharedPtr<TriangleMeshData>() {}
		TriangleMeshDataPtr(TriangleMeshData* rep) : Ogre::SharedPtr<TriangleMeshData>(rep) {}
		TriangleMeshDataPtr(const TriangleMeshDataPtr& r) : Ogre::SharedPtr<TriangleMeshData>(r) {} 
	};
	
}

#endif //__OgreOdeTriangleMeshData_H__


