#include "Geometry.h"
#include "World.h"
#include "Space.h"
#include "Body.h"
#include "Collision.h"
#include "DebugObject.h"
#include "DebugContact.h"

#include "TriangleMeshData.h"
#include "TriangleMeshDataManager.h"

using namespace Ode;
using namespace Ogre;


//------------------------------------------------------------------------------------------------
TriangleMeshData::TriangleMeshData(String name,
								   Vector3 scale,
								   const Vector3* vertices,
								   unsigned int vertex_count,
								   const TriangleIndex* indices,
								   unsigned int index_count
								   ) : 
    _vertex_count (vertex_count),
    _index_count (index_count)
{
	_name = name;
	_scale = scale;
	_vertex_count = vertex_count;
	_index_count = index_count;
	_vertices = new dVector3[vertex_count];
	_indices = new TriangleIndex[index_count];

	for(unsigned int i = 0;i < vertex_count;i++)
	{
		_vertices[i][0] = (dReal)vertices[i].x;
		_vertices[i][1] = (dReal)vertices[i].y;
		_vertices[i][2] = (dReal)vertices[i].z;
	}

	memcpy(_indices, indices, sizeof(unsigned int) * index_count);

	_data = dGeomTriMeshDataCreate(); 
	dGeomTriMeshDataBuildSimple(_data, (const dReal*)_vertices, (int)vertex_count, (dTriIndex*)_indices, (int)index_count); 
	
}




//------------------------------------------------------------------------------------------------
TriangleMeshData::~TriangleMeshData()
{

	//printf ("destroy TriangleMeshData\n");
	
	dGeomTriMeshDataDestroy(_data);
	
	TriangleMeshDataManager::getSingleton().removeTriangleMeshData(_name, _scale);
	
	delete[] _vertices;
	delete[] _indices;
}


