#include "EntityInformer.h"
#include "Body.h"
#include "Geometry.h"
#include "Mass.h"
#include "EigenSolver.h"
#include "TriangleMeshDataManager.h"

using namespace Ode;
using namespace Ogre;

void EntityInformer::addVertexData(const VertexData *vertex_data, const VertexData *blended_data, const Mesh::IndexMap *indexMap)
{
	if (!vertex_data) 
        return;

	const VertexData *data = (blended_data) ? blended_data: vertex_data;

	const unsigned int prev_size = _vertex_count;
    _vertex_count += (unsigned int)data->vertexCount;

    Vector3* tmp_vert = new Vector3[_vertex_count];
	if (_vertices)
	{
		memcpy(tmp_vert,_vertices,sizeof(Vector3) * prev_size);
		delete[] _vertices;
	}
	_vertices = tmp_vert;

	// Get the positional buffer element
    {	
        const VertexElement* posElem = data->vertexDeclaration->findElementBySemantic(VES_POSITION);			
        HardwareVertexBufferSharedPtr vbuf = data->vertexBufferBinding->getBuffer(posElem->getSource());
        const unsigned int vSize = (unsigned int)vbuf->getVertexSize();

	    unsigned char* vertex = static_cast<unsigned char*>(vbuf->lock(HardwareBuffer::HBL_READ_ONLY));
	    float* pReal;
        Vector3 * curVertices = &_vertices[prev_size];
        const unsigned int vertexCount = (unsigned int)data->vertexCount;
	    for(unsigned int j = 0; j < vertexCount; ++j)
	    {
		    posElem->baseVertexPointerToElement(vertex, &pReal);
            vertex += vSize;

		    curVertices->x = (*pReal++);
		    curVertices->y = (*pReal++);
		    curVertices->z = (*pReal++);

		    *curVertices = _transform * (*curVertices);
            
            curVertices++;
        }
	    vbuf->unlock();
    }

	// Get the bone index element
	if (_entity && _entity->hasSkeleton())
	{

        MeshPtr mesh = _entity->getMesh ();

		const VertexElement* bneElem = vertex_data->vertexDeclaration->findElementBySemantic(VES_BLEND_INDICES);
		assert (bneElem);
		{
            HardwareVertexBufferSharedPtr vbuf = vertex_data->vertexBufferBinding->getBuffer(bneElem->getSource());
            const unsigned int vSize = (unsigned int)vbuf->getVertexSize();
			unsigned char* vertex = static_cast<unsigned char*>(vbuf->lock(HardwareBuffer::HBL_READ_ONLY));

			unsigned char* pBone;

            if (!_bone_mapping)
                _bone_mapping = new BoneMapping();	
            BoneMapping::iterator i;

            Vector3 * curVertices = &_vertices[prev_size];
            
            const unsigned int vertexCount = (unsigned int)vertex_data->vertexCount;
			for(unsigned int j = 0; j < vertexCount; ++j)
			{
				bneElem->baseVertexPointerToElement(vertex, &pBone);
                vertex += vSize;
               
                const unsigned char currBone = (indexMap) ? (*indexMap)[*pBone] : *pBone;
				i = _bone_mapping->find (currBone);
				Vector3Array* l = 0;
				if (i == _bone_mapping->end())
				{
					l = new Vector3Array;
					_bone_mapping->insert(BoneMappingKey(currBone, l));
				}						
				else 
                {
                    l = i->second;
                }

				l->push_back(*curVertices);

                curVertices++;
			}
			vbuf->unlock();
		}
	}
}

void EntityInformer::addIndexData(IndexData *data, const u32 offset)
{
    const u32 prev_size = _index_count;
    _index_count += (u32)data->indexCount;

	TriangleIndex* tmp_ind = new TriangleIndex[_index_count];
	if (_indices)
	{
		memcpy (tmp_ind, _indices, sizeof(u32) * prev_size);
		delete[] _indices;
	}
	_indices = tmp_ind;

	const u32 numTris = (u32)data->indexCount / 3;
	HardwareIndexBufferSharedPtr ibuf = data->indexBuffer;	
	const bool use32bitindexes = (ibuf->getType() == HardwareIndexBuffer::IT_32BIT);
    u32 index_offset = prev_size;

	if (use32bitindexes) 
    {
        const u32* pInt = static_cast<u32*>(ibuf->lock(HardwareBuffer::HBL_READ_ONLY));
        for(u32 k = 0; k < numTris; ++k)
        {
            _indices[index_offset ++] = offset + *pInt++;
            _indices[index_offset ++] = offset + *pInt++;
            _indices[index_offset ++] = offset + *pInt++;
        }
        ibuf->unlock();
    }
	else 
    {
        const u16* pShort = static_cast<u16*>(ibuf->lock(HardwareBuffer::HBL_READ_ONLY));
		for(u32 k = 0; k < numTris; ++k)
        {
            _indices[index_offset ++] = offset + static_cast<u32> (*pShort++);
            _indices[index_offset ++] = offset + static_cast<u32> (*pShort++);
            _indices[index_offset ++] = offset + static_cast<u32> (*pShort++);
        }
        ibuf->unlock();
    }

}

void EntityInformer::addEntity(Entity *entity, const Matrix4 &transform)
{
	// Each entity added need to reset size and radius
	// next time getRadius and getSize are asked, they're computed.
	_size  = Vector3(-1,-1,-1);
	_radius = -1;

	_entity = entity;
	_node = (SceneNode*)(_entity->getParentNode());
	_transform = transform;

	const bool isSkeletonAnimated = _entity->hasSkeleton();
	//const bool isHWanimated = isSkeletonAnimated && entity->isHardwareAnimationEnabled();
	if (isSkeletonAnimated)
	{
		_entity->addSoftwareAnimationRequest(false);
		_entity->_updateAnimation();
	}


	if (_entity->getMesh()->sharedVertexData)
	{
		if (!isSkeletonAnimated)
			addVertexData (_entity->getMesh()->sharedVertexData);
		else
			addVertexData (_entity->getMesh()->sharedVertexData, 
			_entity->_getSkelAnimVertexData(),
			&_entity->getMesh()->sharedBlendIndexToBoneIndexMap); 
	}

	for(u32 i = 0;i < _entity->getNumSubEntities(); ++i)
	{
		SubMesh *sub_mesh = _entity->getSubEntity(i)->getSubMesh();

		if (!sub_mesh->useSharedVertices)
		{
			addIndexData(sub_mesh->indexData,_vertex_count);

			if (!isSkeletonAnimated)
				addVertexData (sub_mesh->vertexData);
			else
				addVertexData (sub_mesh->vertexData, 
				_entity->getSubEntity(i)->_getSkelAnimVertexData(),
				&sub_mesh->blendIndexToBoneIndexMap); 
		}
		else 
		{
			addIndexData (sub_mesh->indexData);
		}

	}

	if (isSkeletonAnimated) 
		_entity->removeSoftwareAnimationRequest(false);
}

void EntityInformer::addMesh(const MeshPtr &mesh, const Matrix4 &transform)
{
	// Each entity added need to reset size and radius next time getRadius and getSize are asked, they're computed.
	_size  = Vector3(-1,-1,-1);
	_radius = -1;

	_transform = transform;

	if (mesh->hasSkeleton ())
		LogManager::getSingleton().logMessage("EntityInformer::addMesh : Mesh " + mesh->getName () + " as skeleton but added to trimesh non animated");

	if (mesh->sharedVertexData)
	{
		addVertexData (mesh->sharedVertexData);
	}

	for(u32 i = 0; i < mesh->getNumSubMeshes(); ++i)
	{
		SubMesh *sub_mesh = mesh->getSubMesh(i);

		if (!sub_mesh->useSharedVertices)
		{
			addIndexData(sub_mesh->indexData, _vertex_count);
			addVertexData (sub_mesh->vertexData);
		}
		else 
		{
			addIndexData (sub_mesh->indexData);
		}

	}
}

EntityInformer::EntityInformer(Entity *entity, const Matrix4 &transform) 
	:_vertices (nullptr),
	_indices (nullptr),
	_vertex_count (0),
	_index_count (0),
	_size (Vector3(-1,-1,-1)),
	_center (Vector3(-1,-1,-1)),
	_radius (-1.0f),
	_bone_mapping (nullptr)
{
	addEntity(entity, transform);	
}

EntityInformer::EntityInformer() :
		_vertices (nullptr),
		_indices (nullptr),
		_vertex_count (0),
		_index_count (0),
		_size (Vector3(-1,-1,-1)),
		_center (Vector3(-1,-1,-1)),
		_radius (-1.0f),
        _bone_mapping (nullptr)
{
	 
}

f32 EntityInformer::getRadius()
{
	if (_radius == (-1))
	{
		getSize();
		_radius = (std::max(_size.x,std::max(_size.y,_size.z)) * 0.5f);
	}
	return _radius;
}

Vector3 EntityInformer::getSize()
{
    const u32 vCount = getVertexCount();
	if (_size == Vector3(-1,-1,-1) && vCount > 0)
	{

		const Vector3 * const v = getVertices();

        Vector3 vmin(v[0]);
        Vector3 vmax(v[0]);

		for(u32 j = 1; j < vCount; j++)
		{
			vmin.x = std::min(vmin.x, v[j].x);
			vmin.y = std::min(vmin.y, v[j].y);
			vmin.z = std::min(vmin.z, v[j].z);

			vmax.x = std::max(vmax.x, v[j].x);
			vmax.y = std::max(vmax.y, v[j].y);
			vmax.z = std::max(vmax.z, v[j].z);
		}

		_size.x = vmax.x - vmin.x;
		_size.y = vmax.y - vmin.y;
		_size.z = vmax.z - vmin.z;

		_center.x = vmin.x + _size.x * 0.5f;
		_center.y = vmin.y + _size.y * 0.5f;
		_center.z = vmin.z + _size.z * 0.5f;

	}
	return _size;
}

Vector3 EntityInformer::getCenter()
{
	const u32 vCount = getVertexCount();
	if (_center == Vector3(-1,-1,-1) && vCount > 0)
	{
		getSize();
	}
	return _center;
}

const Vector3* EntityInformer::getVertices()
{
	return _vertices;
}

u32 EntityInformer::getVertexCount()
{
	return _vertex_count;
}

const TriangleIndex* EntityInformer::getIndices()
{
	return _indices;
}

u32 EntityInformer::getIndexCount()
{
	return _index_count;
}

Body* EntityInformer::createSingleDynamicSphere(const f32& mass, World *world, Space* space)
{
	const f32 rad = getRadius();

	assert((rad > 0.0f) && ("Sphere radius must be greater than zero"));

	Body* body = new Body(world, "Ode::Body_" + _entity->getName());
	body->setMass(SphereMass(mass, rad));

	SphereGeometry* geom = new SphereGeometry(rad, world, space);
	geom->setBody(body);

	body->setPosition(_node->_getDerivedPosition());
	body->setOrientation(_node->_getDerivedOrientation());

	_node->attachObject(body);

	return body;
}

Body* EntityInformer::createSingleDynamicBox(const f32& mass, World *world, Space* space)
{
	const Vector3 sz = getSize();

	assert((sz.x > 0.0f) && (sz.y > 0.0f) && (sz.y > 0.0f) && 
        ("Size of box must be greater than zero on all axes"));

	Body* body = new Body(world, "Ode::Body_" + _node->getName());
	body->setMass(BoxMass(mass,sz));

	BoxGeometry* geom = new BoxGeometry(sz, world, space);
	geom->setBody(body);

	body->setPosition(_node->_getDerivedPosition());
	body->setOrientation(_node->_getDerivedOrientation());

	_node->attachObject(body);

	return body;
}

TriangleMeshGeometry* EntityInformer::createStaticTriangleMesh(World *world, Space* space)
{
	assert(_vertex_count && (_index_count >= 6) && 
        ("Mesh must have some vertices and at least 6 indices (2 triangles)"));

	return new TriangleMeshGeometry(_vertices, _vertex_count,_indices, _index_count, world, space);
}

BoxGeometry* EntityInformer::createSingleStaticBox(World *world, Space* space)
{
	BoxGeometry* geom = new BoxGeometry(getSize(), world, space);

	geom->setPosition(_node->_getDerivedPosition());
	geom->setOrientation(_node->_getDerivedOrientation());

	return geom;
}

bool EntityInformer::getBoneVertices(u8 bone, u32 &vertex_count, Vector3* &vertices)
{
	BoneMapping::iterator i = _bone_mapping->find(bone);
	
    if (i == _bone_mapping->end()) 
        return false;

	if (i->second->empty()) 
        return false;

    vertex_count = (u32)i->second->size() + 1;

	vertices = new Vector3[vertex_count];
	vertices[0] = _entity->_getParentNodeFullTransform() *  _entity->getSkeleton()->getBone(bone)->_getDerivedPosition();

	u32 o = 1;
	for(auto j = i->second->begin(); j != i->second->end(); ++j,++o) 
    {
        vertices[o] = (*j);
    }       
	return true;
}

BoxGeometry* EntityInformer::createAlignedBox(u8 bone, World *world, Space* space)
{
	u32 vertex_count;
	Vector3* vertices;
	if (!getBoneVertices(bone, vertex_count, vertices)) 
        return 0;

	Vector3 min_vec(vertices[0]);
	Vector3 max_vec(vertices[0]);

	for(u32 j = 1; j < vertex_count ;j++)
	{
		min_vec.x = std::min(min_vec.x,vertices[j].x);
		min_vec.y = std::min(min_vec.y,vertices[j].y);
		min_vec.z = std::min(min_vec.z,vertices[j].z);

		max_vec.x = std::max(max_vec.x,vertices[j].x);
		max_vec.y = std::max(max_vec.y,vertices[j].y);
		max_vec.z = std::max(max_vec.z,vertices[j].z);
	}
    const Vector3 maxMinusMin(max_vec - min_vec);
    BoxGeometry* box = new BoxGeometry(maxMinusMin, world, space);

    const Vector3 pos(min_vec.x + (maxMinusMin.x * 0.5f),
                      min_vec.y + (maxMinusMin.y * 0.5f),
                      min_vec.z + (maxMinusMin.z * 0.5f));

	box->setPosition(pos);

	delete[] vertices;

	return box;
}

BoxGeometry* EntityInformer::createOrientedBox(u8 bone, World *world, Space* space)
{

#define TESTOOB
#ifdef TESTOOB
	u32 vertex_count;
	Vector3* vertices;
	if (!getBoneVertices(bone, vertex_count, vertices))
		return 0;

	Vector3 box_kCenter(Vector3::ZERO);
	Vector3 box_akAxis[3];
	f32 box_afExtent[3];

	//   EigenSolver::GaussPointsFit (vertex_count-1, &vertices[1], box_kCenter, box_akAxis, box_afExtent);

	f32 invVertexCount=1.0f / (f32)vertex_count;
	for(size_t c = 0; c< vertex_count; c++)
	{
		box_kCenter+=vertices[c];
	}

	box_kCenter*=invVertexCount;

	Quaternion orient=_entity->getSkeleton()->getBone(bone)->_getDerivedOrientation();
	orient.ToAxes(box_akAxis);


	// Let C be the box center and let U0, U1, and U2 be the box axes.  Each
	// input point is of the form X = C + y0*U0 + y1*U1 + y2*U2.  The
	// following code computes min(y0), max(y0), min(y1), max(y1), min(y2),
	// and max(y2).  The box center is then adjusted to be
	//   C' = C + 0.5*(min(y0)+max(y0))*U0 + 0.5*(min(y1)+max(y1))*U1 +
	//        0.5*(min(y2)+max(y2))*U2

	Vector3 kDiff (vertices[1] - box_kCenter);
	f32 fY0Min = kDiff.dotProduct(box_akAxis[0]), fY0Max = fY0Min;
	f32 fY1Min = kDiff.dotProduct(box_akAxis[1]), fY1Max = fY1Min;
	f32 fY2Min = kDiff.dotProduct(box_akAxis[2]), fY2Max = fY2Min;

	for (u32 i = 2; i < vertex_count; i++)
	{
		kDiff = vertices[i] - box_kCenter;

		const f32 fY0 = kDiff.dotProduct(box_akAxis[0]);
		if ( fY0 < fY0Min )
			fY0Min = fY0;
		else if ( fY0 > fY0Max )
			fY0Max = fY0;

		const f32 fY1 = kDiff.dotProduct(box_akAxis[1]);
		if ( fY1 < fY1Min )
			fY1Min = fY1;
		else if ( fY1 > fY1Max )
			fY1Max = fY1;

		const f32 fY2 = kDiff.dotProduct(box_akAxis[2]);
		if ( fY2 < fY2Min )
			fY2Min = fY2;
		else if ( fY2 > fY2Max )
			fY2Max = fY2;
	}

	box_afExtent[0] = 0.5f * (fY0Max - fY0Min);
	box_afExtent[1] = 0.5f * (fY1Max - fY1Min);
	box_afExtent[2] = 0.5f * (fY2Max - fY2Min);

	box_kCenter += (0.5f * (fY0Max+fY0Min))*box_akAxis[0] +
		(0.5f * (fY1Max+fY1Min))*box_akAxis[1] +
		(0.5f * (fY2Max+fY2Min))*box_akAxis[2];

	BoxGeometry *geom = new BoxGeometry(Vector3(box_afExtent[0] * 2.0f,
		box_afExtent[1] * 2.0f,
		box_afExtent[2] * 2.0f),
		world, space);
	geom->setOrientation(Quaternion(box_akAxis[0], box_akAxis[1], box_akAxis[2]));
	geom->setPosition(box_kCenter);
	return geom; 
#else
	u32 vertex_count;
	Vector3* vertices;
	if (!getBoneVertices(bone, vertex_count, vertices)) 
		return 0;

	Vector3 box_kCenter;
	Vector3 box_akAxis[3];
	f32 box_afExtent[3];

	EigenSolver::GaussPointsFit (vertex_count, vertices, box_kCenter, box_akAxis, box_afExtent);

	// Let C be the box center and let U0, U1, and U2 be the box axes.  Each
	// input point is of the form X = C + y0*U0 + y1*U1 + y2*U2.  The
	// following code computes min(y0), max(y0), min(y1), max(y1), min(y2),
	// and max(y2).  The box center is then adjusted to be
	//   C' = C + 0.5*(min(y0)+max(y0))*U0 + 0.5*(min(y1)+max(y1))*U1 +
	//        0.5*(min(y2)+max(y2))*U2

	Vector3 kDiff (vertices[0] - box_kCenter);
	f32 fY0Min = kDiff.dotProduct(box_akAxis[0]), fY0Max = fY0Min;
	f32 fY1Min = kDiff.dotProduct(box_akAxis[1]), fY1Max = fY1Min;
	f32 fY2Min = kDiff.dotProduct(box_akAxis[2]), fY2Max = fY2Min;

	for (u32 i = 1; i < vertex_count; i++)
	{
		kDiff = vertices[i] - box_kCenter;

		const f32 fY0 = kDiff.dotProduct(box_akAxis[0]);
		if ( fY0 < fY0Min )
			fY0Min = fY0;
		else if ( fY0 > fY0Max )
			fY0Max = fY0;

		const f32 fY1 = kDiff.dotProduct(box_akAxis[1]);
		if ( fY1 < fY1Min )
			fY1Min = fY1;
		else if ( fY1 > fY1Max )
			fY1Max = fY1;

		const f32 fY2 = kDiff.dotProduct(box_akAxis[2]);
		if ( fY2 < fY2Min )
			fY2Min = fY2;
		else if ( fY2 > fY2Max )
			fY2Max = fY2;
	}

	box_afExtent[0] = 0.5f * (fY0Max - fY0Min);
	box_afExtent[1] = 0.5f * (fY1Max - fY1Min);
	box_afExtent[2] = 0.5f * (fY2Max - fY2Min);

	box_kCenter += (box_afExtent[0])*box_akAxis[0] +
		(box_afExtent[1])*box_akAxis[1] +
		(box_afExtent[2])*box_akAxis[2];

	BoxGeometry *geom = new BoxGeometry(Vector3(box_afExtent[0] * 2.0f,
		box_afExtent[1] * 2.0f,
		box_afExtent[2] * 2.0f),
		world, space);
	geom->setOrientation(Quaternion(box_akAxis[0],box_akAxis[1],box_akAxis[2]));
	geom->setPosition(box_kCenter);
	return geom;
#endif
}

CapsuleGeometry* EntityInformer::createOrientedCapsule(unsigned char bone, World *world, Space* space)
{
	u32 vertex_count;
	Vector3* vertices;

	if (!getBoneVertices(bone,vertex_count,vertices)) 
        return 0;

	Vector3 cap_orig;
	Vector3 cap_dir;
	f32 cap_rad;

	Vector3 line_orig;
	Vector3 line_dir;

	EigenSolver::orthogonalLineFit (vertex_count, vertices, line_orig, line_dir);

	f32 fMaxRadiusSqr = 0.0f;
    for (u32 c = 0; c < vertex_count; c++)
    {
		const f32 fRadiusSqr = EigenSolver::SqrDistance(vertices[c], line_orig, line_dir);
        if ( fRadiusSqr > fMaxRadiusSqr ) 
            fMaxRadiusSqr = fRadiusSqr;
    }

    Vector3 kU, kV, kW = line_dir;
	EigenSolver::GenerateOrthonormalBasis (kU, kV, kW, true);

	f32 fMin = FLT_MAX, fMax = -fMin;
    for (u32 c = 0; c < vertex_count; c++)
    {
        const  Vector3 kDiff (vertices[c] - line_orig);
        const f32 fU = kU.dotProduct (kDiff);
        const f32 fV = kV.dotProduct (kDiff);
        const f32 fW = kW.dotProduct (kDiff);
        const f32 fDiscr = fMaxRadiusSqr - (fU*fU + fV*fV);
        const f32 fRadical = sqrtf(fabs(fDiscr));

        fMin = std::min(fW + fRadical, fMin);
        fMax = std::max(fW - fRadical, fMax);
    }

    if ( fMin < fMax )
    {
        cap_orig = line_orig + fMin*line_dir;
        cap_dir = (fMax-fMin)*line_dir;
    }
    else
    {
        // enclosing capsule is really a sphere
        cap_orig = line_orig + (0.5f * fMin+fMax) * line_dir;
        //----------------------------
        cap_dir = Vector3::ZERO;
        //cap_dir = (fMax-fMin)*line_dir;
    }

    cap_rad = sqrtf(fMaxRadiusSqr);

    CapsuleGeometry* geom = nullptr;
    const f32 cap_dirLength = cap_dir.length();
    if (cap_rad > 0 && cap_dirLength > 0)
    {
		const Vector3 orig_axis (Vector3::UNIT_Z);
        const Vector3 reqd_axis (cap_dir.normalisedCopy());
        const Vector3 rot_axis (orig_axis.crossProduct(reqd_axis));
        const f32 cos_ang = orig_axis.dotProduct(reqd_axis);
		f32 ang = acos(cos_ang);
        if (cos_ang < 0.0f) 
            ang -= M_PI;

        const Quaternion orient = Quaternion(Radian(ang),rot_axis);

        geom = new CapsuleGeometry(cap_rad, cap_dirLength, world, space);
        geom->setOrientation(orient);
        geom->setPosition(cap_orig + (reqd_axis * (cap_dirLength * 0.5f)));
    }
	return geom;
}

EntityInformer::~EntityInformer()
{
	delete[] _vertices;
	delete[] _indices;

	if (_bone_mapping)
	{
		for(auto i = _bone_mapping->begin(); i != _bone_mapping->end(); ++i)
		{
			delete i->second;
		}
		delete _bone_mapping;
	}
}

EntityInformerReuse::EntityInformerReuse(Entity *entity, const Vector3 &scale, bool forceRecreate) : EntityInformer()
{
	_transform.makeTransform(Vector3::ZERO, scale, Quaternion::IDENTITY);
	
	if(!forceRecreate)
		_dataPtr = TriangleMeshDataManager::getSingleton().getTriangleMeshData(entity->getMesh()->getName(), scale);

	if(_dataPtr.isNull()) 
	{
		EntityInformer::addEntity(entity, _transform);
		
		_dataPtr = new TriangleMeshData(entity->getMesh()->getName(), scale, _vertices, _vertex_count, _indices, _index_count);
		TriangleMeshDataManager::getSingleton().addTriangleMeshData(entity->getMesh()->getName(), _dataPtr, scale);
	}
}

EntityInformerReuse::EntityInformerReuse(const MeshPtr &mesh, const Vector3 &scale, bool forceRecreate) : EntityInformer()
{
	_entity = NULL;
	
	_transform.makeTransform(Vector3::ZERO, scale, Quaternion::IDENTITY);
	
	if(!forceRecreate)
		_dataPtr = TriangleMeshDataManager::getSingleton().getTriangleMeshData(mesh->getName(), scale);
	
	if(_dataPtr.isNull()) 
	{
		EntityInformer::addMesh(mesh, _transform);
		
		_dataPtr = new TriangleMeshData(mesh->getName(), scale, _vertices, _vertex_count, _indices, _index_count);
		TriangleMeshDataManager::getSingleton().addTriangleMeshData(mesh->getName(), _dataPtr, scale);
	}
}

EntityInformerReuse::~EntityInformerReuse()
{
}

TriangleMeshGeometry* EntityInformerReuse::createStaticTriangleMesh(World *world, Space* space)
{
	return new TriangleMeshGeometry(_dataPtr, world, space);
}

TriangleMeshGeometry* EntityInformerReuse::recreateStaticTriangleMesh(TriangleMeshGeometry* geom)
{
	geom->changeTriangleMeshData(_dataPtr);
	return geom;
}
