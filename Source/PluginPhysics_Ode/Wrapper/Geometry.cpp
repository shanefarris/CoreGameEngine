#include "Geometry.h"
#include "World.h"
#include "Space.h"
#include "Body.h"
#include "Collision.h"
#include "DebugObject.h"
#include "DebugContact.h"

#include "Terrain/OgreTerrain.h"
#include "Terrain/OgreTerrainGroup.h"

using namespace Ode;
using namespace Ogre;

int Geometry::_geometry_count = 0;
const String Geometry::MovableType = "OgreOde_Geometry";


Geometry::Geometry(World *world, Space* space):
	_contact_high_water_mark (0),
    _last_contact_num(0),
	_max_contacts (32),
    _debug_contacts (nullptr),
	_contacts (nullptr),
	_encapsulator (nullptr),
	_debug_obj (nullptr),
	_debug_node (nullptr),
	_user_data (0),
	_geom (nullptr),
    _world(world),
	_custom_listener(nullptr),
	m_CustomData(nullptr)
{
	mName = "";
}

Geometry::~Geometry()
{
    destroyDebugObject();

    delete[] _contacts;
    if (_debug_contacts)
    {         
        for (u32 i = 0; i < _max_contacts; i++)
            delete _debug_contacts[i];
        delete [] _debug_contacts;
    }

    if (_geom)
    {
        _world->RemoveGeometry(_geom);
        dGeomDestroy(_geom); 
    }
}

dGeomID Geometry::getGeometryID() const
{
	return _geom;
}

void Geometry::setEncapsulator(Geometry* encapsulator)
{
	_encapsulator = encapsulator;

	if (_world->getShowDebugGeometries())
	{
		reparentDebugObject(encapsulator->_debug_node);
	}
}

void Geometry::reparentDebugObject(Node* node)
{
	if ((node) && (_debug_node) && (_debug_node->getParent() != node))
	{
		SceneNode* parent = static_cast<SceneNode*>(_debug_node->getParent());
		parent->removeChild(_debug_node->getName());
		node->addChild(_debug_node);

		_debug_node->setPosition(getPosition());
		_debug_node->setOrientation(getOrientation());
	}
}

void Geometry::createDebugObject()
{
	if (!_debug_node)
	{
		SceneNode* parent = _world->_manager->getRootSceneNode();
		_debug_node = static_cast<Node*>(parent->createChildSceneNode(String("Ode::Geometry_") + StringConverter::toString(_geometry_count) + String("_Debug"))); 

        if (_debug_obj)
        {
            static_cast<SceneNode*>(_debug_node)->attachObject(_debug_obj);
        }

        if (getBody())
        {
            static_cast<SceneNode*>(_debug_node->getParent())->removeChild(_debug_node->getName());
            getBody()->addDebugNode(_debug_node);
            if (_debug_obj) 
				_debug_obj->setMode(DebugObject::Mode_Enabled);
			
			//reposition the debug node if the geometry has an offset
			if(isOffset())
				_debug_node->setPosition(getOffsetPosition()); 
        }
		else if (_encapsulator)
		{
			reparentDebugObject(_encapsulator->_debug_node);
		}
		else
		{
			if (_debug_obj) 
                _debug_obj->setMode(DebugObject::Mode_Static);
			
			_debug_node->setPosition(getPosition());
			_debug_node->setOrientation(getOrientation());
		}
		_geometry_count++;
	}
}

void Geometry::destroyDebugObject()
{
	if (_debug_node)
    {

        SceneNode* sn = static_cast<SceneNode*>(_debug_node);
        sn->removeAndDestroyAllChildren ();
        sn = static_cast<SceneNode*>(_debug_node->getParent());
        sn->removeAndDestroyChild(_debug_node->getName());
		_debug_node = 0;
	}

	if (_debug_obj)
	{
		delete _debug_obj;
		_debug_obj = 0;
	}
}

void Geometry::registerGeometry()
{
	dGeomSetData(_geom, (void*)this);
	assert(_world);
    _world->AddGeometry(this);

    if (_world->getShowDebugGeometries()) 
        createDebugObject();

    setMaxContacts (_max_contacts);
}

dSpaceID Geometry::getSpaceID(Space* space) const
{
	if (!space) 
		return 0;
	return space->getSpaceID();
}

void Geometry::setBody(Body* body)
{
	destroyDebugObject();
    if (body)
    {
        body->addGeometry (this);
        dGeomSetBody(_geom, body->getBodyID()); 
    }
    else
    {
        dGeomSetBody(_geom, 0); 
    }
	if (_world->getShowDebugGeometries()) 
        createDebugObject();
}

Body* Geometry::getBody()
{
	const dBodyID body = dGeomGetBody(_geom);
	if (!body) 
		return nullptr;
	else return (Body*)dBodyGetData(body); 
}

void Geometry::notify(Body* body)
{
	if (getBody() == body)
	{
		destroyDebugObject();
	}
}

void Geometry::setDebug(const bool debug)
{
    destroyDebugObject();
    if (debug) 
        createDebugObject();    
}

void Geometry::setDebugContact(const bool debug)
{    
    if (_debug_contacts)
    {
        for (u32 i = 0; i < _max_contacts; i++)
            delete _debug_contacts[i];
        delete [] _debug_contacts;
        _debug_contacts = 0;
    }
    if (debug) 
    {
        _debug_contacts = new DebugContact*[_max_contacts];
        for (u32 i = 0; i < _max_contacts; i++)
            _debug_contacts[i] = new DebugContact(StringConverter::toString((size_t)_geom) + 
                                                    "_Contact_" + 
                                                    StringConverter::toString(i),
                                                    _world);
    }
}

void Geometry::setPosition(const Vector3& position)
{
    dGeomSetPosition(_geom, (dReal)position.x, (dReal)position.y, (dReal)position.z);

    if ((_debug_node) && ((!getBody()) || (_encapsulator)))
        _debug_node->setPosition(position);
}

void Geometry::setOrientation(const Quaternion& orientation)
{
	dQuaternion q;
	q[0] = (dReal)orientation.w;
	q[1] = (dReal)orientation.x;
	q[2] = (dReal)orientation.y;
	q[3] = (dReal)orientation.z;
	dGeomSetQuaternion(_geom,q); 

	if ((_debug_node)&& ((!getBody()) || (_encapsulator))) _debug_node->setOrientation(orientation);
}

const Vector3& Geometry::getPosition()
{
	const dReal* position = dGeomGetPosition(_geom);
	_position.x = (f32)position[0];
	_position.y = (f32)position[1];
	_position.z = (f32)position[2];
	return _position;
}

const Quaternion& Geometry::getOrientation()
{
	dQuaternion orientation;
	dGeomGetQuaternion(_geom,orientation); 
	_orientation.w = (f32)orientation[0];
	_orientation.x = (f32)orientation[1];
	_orientation.y = (f32)orientation[2];
	_orientation.z = (f32)orientation[3];
	return _orientation;
}

const AxisAlignedBox& Geometry::getAxisAlignedBox()
{
	dReal aabb[6];
	dGeomGetAABB(_geom,aabb);
	_bounding_box.setExtents((f32)aabb[0], (f32)aabb[2], (f32)aabb[4], (f32)aabb[1], (f32)aabb[3], (f32)aabb[5]);
	return _bounding_box;
}

Space* Geometry::getSpace()
{
	if (dGeomGetSpace(_geom) == 0) 
	{
		// not in any space
		return nullptr;
	}

	return (Space*)_world->GetSpace(dGeomGetSpace(_geom));
}

void Geometry::enable()
{
	dGeomEnable(_geom);
}

void Geometry::disable()
{
	dGeomDisable(_geom); 
}

bool Geometry::isEnabled()
{
	return dGeomIsEnabled(_geom) != 0; 
}

GeometryClass Geometry::getClass() const
{
	return (GeometryClass)dGeomGetClass(_geom);
}

void Geometry::setCategoryBitfield(ul32 bits)
{
	dGeomSetCategoryBits(_geom,bits); 
}

void Geometry::setCollisionBitfield(ul32 bits)
{
	dGeomSetCollideBits(_geom,bits); 
}

ul32 Geometry::getCategoryBitfield()
{
	return dGeomGetCategoryBits(_geom); 
}

ul32 Geometry::getCollisionBitfield()
{
	return dGeomGetCollideBits(_geom); 
}

s32 Geometry::collide(Geometry* geometry, CollisionListener* listener)
{
	const u32 num_contacts = (u32)dCollide(_geom, geometry->getGeometryID(), _max_contacts, &(_contacts[0].geom), sizeof(dContact));
	if (num_contacts)
	{
		CollisionListener* _listener = nullptr;
		if(_custom_listener)
			_listener = _custom_listener;
		else
			_listener = listener;

		_contact_high_water_mark = std::max(_contact_high_water_mark,num_contacts);

		Contact contact;
		
		const dWorldID wid = _world->getWorldID();
		const dJointGroupID cid = _world->getContactGroupID();
		const dBodyID b1 = dGeomGetBody(_geom);
		const dBodyID b2 = dGeomGetBody(geometry->getGeometryID());

		if (_listener)
		{
			for(u32 i = 0; i < num_contacts; i++)
			{
				contact.setContact (&_contacts[i]);

				if (_listener->collision(&contact))
				{
					dJointAttach(dJointCreateContact(wid, cid, &_contacts[i]), b1, b2);
                } 
			}
		}
		else
		{
			for(u32 i = 0; i < num_contacts; i++)
			{
				contact.setContact (&_contacts[i]);
				dJointAttach(dJointCreateContact(wid, cid, &_contacts[i]), b1, b2);
			}
		} 
    }
    _last_contact_num = num_contacts;
	return num_contacts;
}

void Geometry::setCustomListener(CollisionListener* listener) 
{ 
	_custom_listener = listener; 
}

void Geometry::updateDebugContact()
{
    assert (_world->getShowDebugContact ());
    assert (_debug_contacts);
    {
        u32 k = 0;
        while (k < _max_contacts)
        {
            _debug_contacts[k++]->setEnabled(false);
        }

        if (_last_contact_num)
        {
            Contact contact;
            for(u32 i = 0; i < _last_contact_num; i++)
            {
                k = 0;
                while (k < _max_contacts)
                {
                    if (_debug_contacts[k]->isEnabled() == false)
                        break;
                    k++;
                }
                assert (k < _max_contacts);

                _debug_contacts[k]->setEnabled(true);
                contact.setContact (&_contacts[i]);
                _debug_contacts[k]->update (&contact);
            }
        }
    }
    _last_contact_num = 0;
 }

u32 Geometry::getMaxContacts() const
{
	return _max_contacts;
}

void Geometry::setMaxContacts(u32 max_contacts)
{
	delete[] _contacts;
	_contacts = new dContact[max_contacts];

    if (_world->getShowDebugContact ())
    {
        if (_debug_contacts)
        {         
            for (u32 i = 0; i < _max_contacts; i++)
                delete _debug_contacts[i];
            delete [] _debug_contacts;
        }
        _debug_contacts = new DebugContact * [max_contacts];
        for (u32 i = 0; i < max_contacts; i++)
            _debug_contacts[i] = new DebugContact(StringConverter::toString((size_t)_geom)  
			+ "_Contact_" 
			+ StringConverter::toString(i),
            _world);
    }
    _max_contacts = max_contacts;
}

u32 Geometry::getContactHighWaterMark() const
{
	return _contact_high_water_mark;
}

void Geometry::clearOffset()
{
	dGeomClearOffset(_geom);
}

s32 Geometry::isOffset()
{
	return dGeomIsOffset(_geom);
}

void Geometry::setOffsetPosition (const Vector3 &pos)
{
	dGeomSetOffsetPosition (_geom, pos.x, pos.y, pos.z);

	//move the debug object when setting offset if we have a body only
	if ((_debug_node)&& ((getBody())/* || (_encapsulator)*/))
		_debug_node->setPosition(getOffsetPosition()); 
}

void Geometry::setOffsetQuaternion(const Quaternion &quat) 
{
	dQuaternion q;
	q[0] = (dReal)quat.w; 
	q[1] = (dReal)quat.x; 
	q[2] = (dReal)quat.y; 
	q[3] = (dReal)quat.z;
	dGeomSetOffsetQuaternion (_geom, q);

	if ((_debug_node) && ((getBody())/* || (_encapsulator)*/))
		_debug_node->setOrientation(getOffsetQuaternion()); 
}

void Geometry::setOffsetWorldPosition(const Vector3 &pos) 
{
	dGeomSetOffsetWorldPosition(_geom, (dReal)pos.x, (dReal)pos.y, (dReal)pos.z);

	//move the debug object when setting offset if we have a body only
	if ((_debug_node) && ((getBody())/* || (_encapsulator)*/))
		_debug_node->setPosition(getOffsetPosition()); 
}

void Geometry::setOffsetWorldQuaternion(const Quaternion &quat) 
{
	dQuaternion q;
	q[0] = (dReal)quat.w; 
	q[1] = (dReal)quat.x; 
	q[2] = (dReal)quat.y; 
	q[3] = (dReal)quat.z;
	dGeomSetOffsetWorldQuaternion (_geom, q);

	if ((_debug_node) && ((getBody())/* || (_encapsulator)*/))
		_debug_node->setOrientation(getOffsetQuaternion()); 
}

Vector3 Geometry::getOffsetPosition() 
{
	const dReal* p =  dGeomGetOffsetPosition (_geom);
	return Vector3((f32)p[0], (f32)p[1], (f32)p[2]);
}

Quaternion Geometry::getOffsetQuaternion() 
{
	dQuaternion q;
	dGeomGetOffsetQuaternion (_geom, q);
	return Quaternion((f32)q[0], (f32)q[1], (f32)q[2], (f32)q[3]);
}

void Geometry::_notifyAttached(Node* parent, bool isTagPoint)
{
	MovableObject::_notifyAttached(parent, isTagPoint);
	reparentDebugObject(parent);
}

void Geometry::_notifyMoved()
{
	MovableObject::_notifyMoved();
		
	if (!getBody())
	{
		setPosition(mParentNode->_getDerivedPosition());
		setOrientation(mParentNode->_getDerivedOrientation());
	}
}

SphereGeometry::SphereGeometry(const f32& radius, World *world, Space* space) : Geometry(world, space)
{
	_geom = dCreateSphere(getSpaceID(space),(dReal)radius); 
	registerGeometry();
}

void SphereGeometry::setRadius(const f32& radius)
{
	dGeomSphereSetRadius(_geom,(dReal)radius);
}

f32 SphereGeometry::getRadius()
{
	return (f32)dGeomSphereGetRadius(_geom); 
}

f32 SphereGeometry::getPointDepth(const Vector3& point)
{
	return (f32)dGeomSpherePointDepth(_geom,(dReal)point.x,(dReal)point.y,(dReal)point.z); 
}

void SphereGeometry::createDebugObject()
{
	_debug_obj = new SphereDebugObject(getRadius());
	Geometry::createDebugObject();
}

SphereGeometry::~SphereGeometry()
{
}

BoxGeometry::BoxGeometry(const Vector3& size, World *world, Space* space) : Geometry(world, space)
{
	_geom = dCreateBox(getSpaceID(space),(dReal)size.x,(dReal)size.y,(dReal)size.z); 
	registerGeometry();
}

void BoxGeometry::setSize(const Vector3& size)
{
	dGeomBoxSetLengths(_geom,(dReal)size.x,(dReal)size.y,(dReal)size.z); 
}

const Vector3& BoxGeometry::getSize()
{
	dVector3 result;
	dGeomBoxGetLengths(_geom,result); 
	_size.x = (f32)result[0];
	_size.y = (f32)result[1];
	_size.z = (f32)result[2];
	return _size;
}

f32 BoxGeometry::getPointDepth(const Vector3& point)
{
	return (f32)dGeomBoxPointDepth(_geom,(dReal)point.x,(dReal)point.y,(dReal)point.z); 
}

void BoxGeometry::createDebugObject()
{
	_debug_obj = new BoxDebugObject(getSize());
	Geometry::createDebugObject();	
}

BoxGeometry::~BoxGeometry()
{
}

InfinitePlaneGeometry::InfinitePlaneGeometry(const Plane& plane,World *world, Space* space) : Geometry(world, space)
{
	_geom = dCreatePlane(getSpaceID(space), (dReal)plane.normal.x, (dReal)plane.normal.y, (dReal)plane.normal.z, (dReal)-plane.d); 
	registerGeometry();
}

void InfinitePlaneGeometry::setDefinition(const Plane& plane)
{
	dGeomPlaneSetParams(_geom, (dReal)plane.normal.x, (dReal)plane.normal.y, (dReal)plane.normal.z, (dReal) - plane.d); 
}

const Plane& InfinitePlaneGeometry::getDefinition()
{
	dVector4 result;
	dGeomPlaneGetParams(_geom,result); 
	_plane.normal.x = (f32)result[0];
	_plane.normal.y = (f32)result[1];
	_plane.normal.z = (f32)result[2];
	_plane.d = (f32)-result[3];
	return _plane;
}

f32 InfinitePlaneGeometry::getPointDepth(const Vector3& point)
{
	return (f32)dGeomPlanePointDepth(_geom, (dReal)point.x, (dReal)point.y, (dReal)point.z); 
}

void InfinitePlaneGeometry::setPosition(const Vector3& position)
{
}

void InfinitePlaneGeometry::setOrientation(const Quaternion& orientation)
{
}

const Vector3& InfinitePlaneGeometry::getPosition()
{
	return Vector3::ZERO;
}

const Quaternion& InfinitePlaneGeometry::getOrientation()
{
	return Quaternion::ZERO;
}

const AxisAlignedBox& InfinitePlaneGeometry::getAxisAlignedBox()
{
	return _bounding_box;
}

InfinitePlaneGeometry::~InfinitePlaneGeometry()
{
}

CapsuleGeometry::CapsuleGeometry(const f32& radius, const f32& length, World *world, Space* space) : Geometry(world, space)
{
	_geom = dCreateCapsule(getSpaceID(space), (dReal)radius, (dReal)length);
	registerGeometry();
}

void CapsuleGeometry::setDefinition(const f32& radius, const f32& length)
{
	dGeomCapsuleSetParams(_geom, (dReal)radius, (dReal)length);
}

f32 CapsuleGeometry::getRadius()
{
	dReal radius;
	dReal length;
	dGeomCapsuleGetParams(_geom, &radius, &length); 
	return (f32)radius;
}

f32 CapsuleGeometry::getLength()
{
	dReal radius;
	dReal length;
	dGeomCapsuleGetParams(_geom, &radius, &length); 
	return (f32)length;
}

f32 CapsuleGeometry::getPointDepth(const Vector3& point)
{
	return (f32)dGeomCapsulePointDepth(_geom, (dReal)point.x, (dReal)point.y, (dReal)point.z); 
}

void CapsuleGeometry::createDebugObject()
{
	_debug_obj = new CapsuleDebugObject(getRadius(), getLength());
	Geometry::createDebugObject();
}

CapsuleGeometry::~CapsuleGeometry()
{
}

CylinderGeometry::CylinderGeometry(const f32& radius, const f32& length, World *world, Space* space) : Geometry(world, space)
{
	_geom = dCreateCCylinder(getSpaceID(space), (dReal)radius, (dReal)length);
	registerGeometry();
}

void CylinderGeometry::setDefinition(const f32& radius, const f32& length)
{
	dGeomCCylinderSetParams(_geom, (dReal)radius, (dReal)length);
}

f32 CylinderGeometry::getRadius()
{
	dReal radius;
	dReal length;
	dGeomCCylinderGetParams(_geom, &radius, &length); 
	return (f32)radius;
}

f32 CylinderGeometry::getLength()
{
	dReal radius;
	dReal length;
	dGeomCCylinderGetParams(_geom, &radius, &length); 
	return (f32)length;
}

f32 CylinderGeometry::getPointDepth(const Vector3& point)
{
	return (f32)dGeomCCylinderPointDepth(_geom, (dReal)point.x, (dReal)point.y, (dReal)point.z); 
}

void CylinderGeometry::createDebugObject()
{
	_debug_obj = new CylinderDebugObject(getRadius(), getLength());
	Geometry::createDebugObject();
}

CylinderGeometry::~CylinderGeometry()
{
}

RayGeometry::RayGeometry(const f32& length,World *world, Space* space) : Geometry(world, space)
{
	_report = nullptr;	// Means it hasn't hit anything yet
	_geom = dCreateRay(getSpaceID(space),(dReal)length);
	registerGeometry();
}

void RayGeometry::createDebugObject()
{
	_debug_obj = new RayDebugObject(getStart(), getDirection(), getLength());
	Geometry::createDebugObject();
	if (_debug_node)
	{
		_debug_node->setPosition(Vector3::ZERO);
		_debug_node->setOrientation(Quaternion::IDENTITY);
	}
}

void RayGeometry::setLength(const f32& length)
{
	dGeomRaySetLength(_geom, (dReal)length); 
}

f32 RayGeometry::getLength()
{
	return (f32)dGeomRayGetLength(_geom); 
}

void RayGeometry::setDefinition(const Vector3& start,const Vector3& direction)
{
	dGeomRaySet(_geom,
					(dReal)start.x,(dReal)start.y,(dReal)start.z,
					(dReal)direction.x,(dReal)direction.y,(dReal)direction.z);

	if ((_debug_node) && ((!getBody()) || (_encapsulator))) 
		(static_cast<RayDebugObject *>(_debug_obj))->setDefinition(start, direction, (f32)dGeomRayGetLength(_geom));

}

const Vector3& RayGeometry::getStart()
{
	dVector3 start;
	dVector3 direction;
	dGeomRayGet(_geom,start,direction); 
	_start.x = (f32)start[0];
	_start.y = (f32)start[1];
	_start.z = (f32)start[2];
	return _start;
}

const Vector3& RayGeometry::getDirection()
{
	dVector3 start;
	dVector3 direction;
	dGeomRayGet(_geom,start,direction); 
	_direction.x = (f32)direction[0];
	_direction.y = (f32)direction[1];
	_direction.z = (f32)direction[2];
	return _direction;
}

void RayGeometry::setClosestHit(bool Closest)
{
	int closest = Closest == true ? 1 : 0;
	dGeomRaySetClosestHit(_geom, closest);
}

RayGeometry::~RayGeometry()
{
}

TransformGeometry::TransformGeometry(World *world, Space* space) : Geometry(world, space)
{
	_geom = dCreateGeomTransform(getSpaceID(space)); 
	dGeomTransformSetCleanup(_geom, 0);
	dGeomTransformSetInfo(_geom, 1);
	registerGeometry();
}

void TransformGeometry::setEncapsulatedGeometry(Geometry* geometry)
{
	dGeomTransformSetGeom(_geom,geometry->getGeometryID()); 
	destroyDebugObject();
	if (_world->getShowDebugGeometries()) 
		createDebugObject();	

	geometry->setEncapsulator(this);
}

void TransformGeometry::createDebugObject()
{
	Geometry::createDebugObject();
	if (getEncapsulatedGeometry())
	{
		getEncapsulatedGeometry()->destroyDebugObject();
		getEncapsulatedGeometry()->createDebugObject();
	}
}

void TransformGeometry::destroyDebugObject()
{
	if (getEncapsulatedGeometry()) getEncapsulatedGeometry()->destroyDebugObject();
	Geometry::destroyDebugObject();
}

Geometry* TransformGeometry::getEncapsulatedGeometry() const
{
	dGeomID id = dGeomTransformGetGeom(_geom);
	if (id == 0) return 0;
	else return (Geometry*)dGeomGetData(id); 
}

TransformGeometry::~TransformGeometry()
{
}

TriangleMeshGeometry::TriangleMeshGeometry(const Vector3* vertices, u32 vertex_count, const TriangleIndex* indices, u32 index_count, World *world, Space* space) 
	: Geometry(world, space),
	_vertex_count (vertex_count),
    _index_count (index_count)
{
	_vertex_count = vertex_count;
	_index_count = index_count;
	_vertices = new dVector3[vertex_count];
	_indices = new u32[index_count];

	for(u32 i = 0; i < vertex_count; i++)
	{
		_vertices[i][0] = (dReal)vertices[i].x;
		_vertices[i][1] = (dReal)vertices[i].y;
		_vertices[i][2] = (dReal)vertices[i].z;
	}

	memcpy(_indices,indices,sizeof(u32) * index_count);
	_data = dGeomTriMeshDataCreate(); 
	dGeomTriMeshDataBuildSimple(_data, (const dReal*)_vertices, (s32)vertex_count, _indices, (s32)index_count); 

	_geom = dCreateTriMesh(getSpaceID(space), _data, 0, 0, 0);
	registerGeometry();
	_collision_listener = nullptr;
}

TriangleMeshGeometry::TriangleMeshGeometry(TriangleMeshDataPtr dataPtr, World *world, Space* space) 
	: Geometry(world, space)
{
	// increases the referance count
	_dataPtr		= dataPtr;	
	_data			= dataPtr.getPointer()->getData();
	_vertex_count	= dataPtr.getPointer()->getVertexCount();
	_index_count	= dataPtr.getPointer()->getIndexCount();
	_vertices		= dataPtr.getPointer()->getVertices();
	_indices		= (unsigned int*) dataPtr.getPointer()->getIndices();
	
	_geom = dCreateTriMesh(getSpaceID(space), _data, 0, 0, 0);
	registerGeometry();
	_collision_listener = nullptr;
}

void TriangleMeshGeometry::changeTriangleMeshData(TriangleMeshDataPtr dataPtr)
{
	if(dataPtr.isNull() == false)
	{
		_dataPtr		= dataPtr;
		_data			= dataPtr.getPointer()->getData();
		_vertex_count	= dataPtr.getPointer()->getVertexCount();
		_index_count	= dataPtr.getPointer()->getIndexCount();
		_vertices		= dataPtr.getPointer()->getVertices();
		_indices		= (u32*) dataPtr.getPointer()->getIndices();
	
		dGeomTriMeshSetData(_geom, _data);
	
		if (_world->getShowDebugGeometries())
		{
			destroyDebugObject();
			createDebugObject();
		}
	}
	else
	{
		_dataPtr		= dataPtr;		
		_data			= nullptr;
		_vertex_count	= 0;
		_index_count	= 0;
		_vertices		= nullptr;
		_indices		= nullptr;
		
		dGeomTriMeshSetData(_geom, _data);
		
		if (_world->getShowDebugGeometries())
		{
			destroyDebugObject();
			createDebugObject();
		}
	}
}

Vector3 TriangleMeshGeometry::getPoint(u32 index, const Vector3& uv)
{
	dVector3 out;
	dGeomTriMeshGetPoint(_geom, (s32) index, (dReal)uv.x, (dReal)uv.y, out); 
	return Vector3((f32)out[0], (f32)out[1], (f32)out[2]);
}

TriangleMeshTriangle TriangleMeshGeometry::getTriangle(s32 index)
{
	dVector3 v0;
	dVector3 v1;
	dVector3 v2;
	dGeomTriMeshGetTriangle(_geom,(s32)index, &v0, &v1, &v2); 
	
	TriangleMeshTriangle tri;
	tri.v0.x = (f32)v0[0]; tri.v0.y = (f32)v0[1]; tri.v0.z = (f32)v0[2];
	tri.v1.x = (f32)v1[0]; tri.v1.y = (f32)v1[1]; tri.v1.z = (f32)v1[2];
	tri.v2.x = (f32)v2[0]; tri.v2.y = (f32)v2[1]; tri.v2.z = (f32)v2[2];
	
	return tri;
}

void TriangleMeshGeometry::clearTemporalCoherenceCache()
{
	dGeomTriMeshClearTCCache(_geom); 
}

void TriangleMeshGeometry::enableTemporalCoherence(GeometryClass geometry_class, bool enable)
{
	assert((geometry_class == Class_Sphere) || (geometry_class == Class_Box));
	dGeomTriMeshEnableTC(_geom, (s32)geometry_class, (enable) ? 1 : 0); 
}

bool TriangleMeshGeometry::isTemporalCoherenceEnabled(GeometryClass geometry_class)
{
	return ((dGeomTriMeshIsTCEnabled(_geom, (int)geometry_class)) ? true : false);
}

s32 TriangleMeshGeometry::_collisionCallback(dGeomID mesh,dGeomID object, s32 triangle)
{
	TriangleMeshGeometry* trimesh = (TriangleMeshGeometry*)dGeomGetData(mesh);
	if (trimesh->_collision_listener)
	{
		Geometry* geometry = (object)?((Geometry*)dGeomGetData(object)) : 0;
		return ((trimesh->_collision_listener->collide(trimesh,geometry,triangle)) ? 1 : 0);
	}
	return 1;
}

void TriangleMeshGeometry::setCollisionListener(TriangleMeshCollisionListener* collision_listener)
{
	_collision_listener = collision_listener;
	dGeomTriMeshSetCallback(_geom, (_collision_listener) ? TriangleMeshGeometry::_collisionCallback : nullptr); 
}

void TriangleMeshGeometry::_intersectionCallback(dGeomID mesh, dGeomID object, const s32* triangles, s32 triangle_count)
{
	TriangleMeshGeometry* trimesh = (TriangleMeshGeometry*)dGeomGetData(mesh);
	if (trimesh->_intersection_listener)
	{
		Geometry* geometry = (object)?((Geometry*)dGeomGetData(object)) : nullptr;
		trimesh->_intersection_listener->intersect(trimesh, geometry, triangles, triangle_count);
	}
}

void TriangleMeshGeometry::setIntersectionListener(TriangleMeshIntersectionListener* intersection_listener)
{
	_intersection_listener = intersection_listener;
	dGeomTriMeshSetArrayCallback(_geom, (_intersection_listener) ? TriangleMeshGeometry::_intersectionCallback : nullptr); 
}

int TriangleMeshGeometry::_rayCallback(dGeomID mesh, dGeomID ray, s32 triangle, dReal u,dReal v)
{
	TriangleMeshGeometry* trimesh = (TriangleMeshGeometry*)dGeomGetData(mesh);
	if (trimesh->_ray_listener)
	{
		RayGeometry* ray_geometry = (ray) ? ((RayGeometry*)dGeomGetData(ray)) : nullptr;
		return ((trimesh->_ray_listener->collide(trimesh, ray_geometry, triangle, Vector3((f32)u, (f32)v, 0.0f))) ? 1 : 0);
	}
	return 1;
}

void TriangleMeshGeometry::setRayListener(TriangleMeshRayListener* ray_listener)
{
	_ray_listener = ray_listener;
	dGeomTriMeshSetRayCallback(_geom,(_ray_listener)?TriangleMeshGeometry::_rayCallback:0); 
}

void TriangleMeshGeometry::createDebugObject()
{
	if (_index_count != 0)
	{
		_debug_obj = new TriangleMeshDebugObject((_index_count / 3) * 6);
		TriangleMeshDebugObject* obj = static_cast<TriangleMeshDebugObject*>(_debug_obj);

		obj->beginDefinition();
		for(u32 i = 0, j = 0; i < _index_count; i += 3, j += 6)
		{
			obj->setVertex(j,Vector3((f32)_vertices[_indices[i]][0],(f32)_vertices[_indices[i]][1],(f32)_vertices[_indices[i]][2]));
			obj->setVertex(j+1,Vector3((f32)_vertices[_indices[i+1]][0],(f32)_vertices[_indices[i+1]][1],(f32)_vertices[_indices[i+1]][2]));

			obj->setVertex(j+2,Vector3((f32)_vertices[_indices[i+1]][0],(f32)_vertices[_indices[i+1]][1],(f32)_vertices[_indices[i+1]][2]));
			obj->setVertex(j+3,Vector3((f32)_vertices[_indices[i+2]][0],(f32)_vertices[_indices[i+2]][1],(f32)_vertices[_indices[i+2]][2]));

			obj->setVertex(j+4,Vector3((f32)_vertices[_indices[i+2]][0],(f32)_vertices[_indices[i+2]][1],(f32)_vertices[_indices[i+2]][2]));
			obj->setVertex(j+5,Vector3((f32)_vertices[_indices[i]][0],(f32)_vertices[_indices[i]][1],(f32)_vertices[_indices[i]][2]));
		}
		obj->endDefinition();

		Geometry::createDebugObject();
	}
}

TriangleMeshGeometry::~TriangleMeshGeometry()
{
	if (_dataPtr.isNull())
	{
		dGeomTriMeshDataDestroy(_data); 
		delete[] _vertices;
		delete[] _indices;
	}
}

ConvexGeometry::ConvexGeometry(const Vector3* vertices, u32 vertex_count, const u32* indices, u32 index_count, World *world, Space* space) 
	: Geometry(world, space),
    _vertex_count (vertex_count),
    _index_count (index_count)
{
	_vertices = new dReal[vertex_count*3];
	_indices = new u32[index_count];

	for(u32 i = 0;i < vertex_count;i++)
	{
		_vertices[i*3 + 0] = (dReal)vertices[i].x;
		_vertices[i*3 + 1] = (dReal)vertices[i].y;
		_vertices[i*3 + 2] = (dReal)vertices[i].z;
	}

	memcpy(_indices,indices,sizeof(u32) * index_count);

	_geom = dCreateConvex (getSpaceID(space),
		0, //dReal *_planes,
		0, //unsigned int _planecount,
		_vertices,
		vertex_count,
		0); //unsigned int *_polygons)

	registerGeometry();
}

void ConvexGeometry::createDebugObject()
{
	_debug_obj = new TriangleMeshDebugObject((_index_count / 3) * 6);
	TriangleMeshDebugObject* obj = static_cast<TriangleMeshDebugObject*>(_debug_obj);

	obj->beginDefinition();
	for(u32 i = 0, j = 0; i < _index_count; i += 3,j += 6)
	{
		obj->setVertex(j,Vector3((f32)_vertices[_indices[i]*3 + 0],(f32)_vertices[_indices[i]*3 + 1],(f32)_vertices[_indices[i]*3 + 2]));
		obj->setVertex(j+1,Vector3((f32)_vertices[_indices[i+1]*3 + 0],(f32)_vertices[_indices[i+1]*3 + 1],(f32)_vertices[_indices[i+1]*3 + 2]));

		obj->setVertex(j+2,Vector3((f32)_vertices[_indices[i+1]*3 + 0],(f32)_vertices[_indices[i+1]*3 + 1],(f32)_vertices[_indices[i+1]*3 + 2]));
		obj->setVertex(j+3,Vector3((f32)_vertices[_indices[i+2]*3 + 0],(f32)_vertices[_indices[i+2]*3 + 1],(f32)_vertices[_indices[i+2]*3 + 2]));

		obj->setVertex(j+4,Vector3((f32)_vertices[_indices[i+2]*3 + 0],(f32)_vertices[_indices[i+2]*3 + 1],(f32)_vertices[_indices[i+2]*3 + 2]));
		obj->setVertex(j+5,Vector3((f32)_vertices[_indices[i]*3 + 0],(f32)_vertices[_indices[i]*3 + 1],(f32)_vertices[_indices[i]*3 + 2]));
	}
	obj->endDefinition();

	Geometry::createDebugObject();
}

ConvexGeometry::~ConvexGeometry()
{
	delete[] _vertices;
	delete[] _indices;
}

TerrainGeometry::TerrainGeometry(World *world, Space* space, const Vector3 &scale, s32 nodes_per_sideX, s32 nodes_per_sideY, const f32& worldSizeX, const f32& worldSizeZ, 
	bool centered, const f32& thickness) 
	: Geometry(world, space),
    _sample_width(scale.x),
    _sample_height(scale.z),
    _max_height (scale.y),
    _halfWorldSizeX(worldSizeX * 0.5f),
    _halfWorldSizeZ(worldSizeZ * 0.5f),
    _centered(centered)
{
	dHeightfieldDataID heightid = dGeomHeightfieldDataCreate();
	dGeomHeightfieldDataBuildCallback(	heightid, //getSpaceID(space), 
										this, // pUserData ?
										TerrainGeometry::_heightCallback, 
										(dReal) (worldSizeX),	//X
										(dReal) (worldSizeZ),	//Z
										nodes_per_sideX,		// w // Vertex count along edge >= 2
										nodes_per_sideY,		// h // Vertex count along edge >= 2
										1.0f,					//scale
										0.0f,					// vOffset
										thickness,				// vThickness
										 0);					// nWrapMode


	// Give some very bounds which, while conservative,
	// makes AABB computation more accurate than +/-INF.
	dGeomHeightfieldDataSetBounds(heightid, 0.0f,  _max_height);
	_geom = dCreateHeightfield(getSpaceID(space), heightid, 1);

	_listener = nullptr;
	_ray = Ray (Vector3::ZERO, Vector3::NEGATIVE_UNIT_Y);
	_ray_query = _world->getSceneManager()->createRayQuery(_ray);

	_ray_query->setQueryTypeMask(SceneManager::WORLD_GEOMETRY_TYPE_MASK );
	_ray_query->setWorldFragmentType(SceneQuery::WFT_SINGLE_INTERSECTION); 

	registerGeometry();

	if (!_centered)
	{
		// TSM is not centered by default.	
		setPosition(Vector3(_halfWorldSizeX, 0, _halfWorldSizeZ));
	}

	setOrientation(Quaternion::ZERO);
}

dReal TerrainGeometry::_heightCallback(void* data, s32 x, s32 z)
{
	TerrainGeometry * const terrain = (TerrainGeometry*)data;    
	if (terrain->_listener)
	{
		return static_cast <dReal>(terrain->_listener->heightAt(Vector3((f32)x, terrain->_max_height, (f32)z)));
	}
    else
    {
        return static_cast <dReal>(terrain->getHeightAt(Vector3((f32)x, terrain->_max_height, (f32)z)));
    }
}

f32 TerrainGeometry::getPointDepth(const Vector3& point)
{
	//return (f32)dGeomTerrainCallbackPointDepth(_geom,(dReal)point.x,(dReal)point.y,(dReal)point.z); 
	//return (f32) dGeomHeightfieldPointDepth (_geom,(dReal)point.x,(dReal)point.y,(dReal)point.z);
	//dGetDepthFn(_geom,(dReal)point.x,(dReal)point.y,(dReal)point.z);
	return 0.0f;
}

void TerrainGeometry::setHeightListener(TerrainGeometryHeightListener* listener)
{
	_listener = listener;
}

bool TerrainGeometry::queryResult(MovableObject *obj, f32 distance)
{
	return false;
}

bool TerrainGeometry::queryResult(SceneQuery::WorldFragment *fragment, f32 distance)
{
	_distance_to_terrain = distance;
	return false;
}

const Vector3& TerrainGeometry::getPosition()
{
	return Vector3::ZERO;
}

const Quaternion& TerrainGeometry::getOrientation()
{
	return Quaternion::ZERO;
}

TerrainGeometry::~TerrainGeometry()
{
	_world->getSceneManager()->destroyQuery(_ray_query);
}

PagedTerrainGeometry::PagedTerrainGeometry(World *world, Space* space, Terrain* TerrainPage, TerrainGroup* Group) 
	: Geometry(world, space), maxHeight(0), m_TerrainGroup(Group)
{
	maxHeight = TerrainPage->getMaxHeight();
	auto data = TerrainPage->getHeightData();
	auto size = TerrainPage->getSize();
	const f32 minHeight = TerrainPage->getMinHeight();
	const f32 worldSize = TerrainPage->getWorldSize();
	auto convertedData = new f32[size * size];	// Ogre reorders the terrain data for faster rendering (http://www.ogre3d.org/forums/viewtopic.php?f=2&t=58756)

	for(auto i = 0; i < size; i++)
	{
		memcpy(convertedData + size * i, data + size * (size - i - 1), sizeof(f32) * size);
	}

	f32 scale = size / (size - 1.0f);
	dHeightfieldDataID heightid = dGeomHeightfieldDataCreate();
	dGeomHeightfieldDataBuildSingle (heightid,
                                convertedData,
                                0,					// bCopyHeightData 
                                worldSize, worldSize,
                                size, size,
                                scale,				// Scale
								0.0f,				//Offset
								10.0f,				// Thickness
								0);					// Wrap

	// Give some very bounds which, while conservative, makes AABB computation more accurate than +/-INF.
	dGeomHeightfieldDataSetBounds(heightid, minHeight,  maxHeight);
	_geom = dCreateHeightfield(getSpaceID(space), heightid, 1);
	dGeomSetPosition(_geom, TerrainPage->getPosition().x, TerrainPage->getPosition().y - 2.91f, TerrainPage->getPosition().z);

	_listener = nullptr;
	registerGeometry();
	setOrientation(Quaternion::ZERO);
}

f32 PagedTerrainGeometry::getHeightAt(const Vector3& position)
{
	return m_TerrainGroup->getHeightAtWorldPosition(position);
}

dReal PagedTerrainGeometry::_heightCallback(void* data, s32 x, s32 z)
{
	PagedTerrainGeometry * const terrain = (PagedTerrainGeometry*)data;    
	if (terrain->_listener)
	{
		return static_cast <dReal>(terrain->_listener->heightAt(Vector3((f32)x, terrain->maxHeight, (f32)z)));
	}
    else
    {
        return static_cast <dReal>(terrain->getHeightAt(Vector3((f32)x, terrain->maxHeight, (f32)z)));
    }
}

void PagedTerrainGeometry::setHeightListener(PagedTerrainGeometryHeightListener* listener)
{
	_listener = listener;
}

const Vector3& PagedTerrainGeometry::getPosition()
{
	return Vector3::ZERO;
}

const Quaternion& PagedTerrainGeometry::getOrientation()
{
	return Quaternion::ZERO;
}

Vector<Plane>* PlaneBoundedRegionGeometry::_planeCallback(void* data, s32 x, s32 z)
{
    PlaneBoundedRegionGeometry* terrain = (PlaneBoundedRegionGeometry*)data;

    if (terrain->_listener)
    {
        return terrain->_listener->planesAt(Vector3((f32)x, terrain->_max_height, (f32)z));
    }
    else
    {
        return  terrain->planesAt(Vector3((f32)x, terrain->_max_height, (f32)z));
    }
    return nullptr;
}

PlaneBoundedRegionGeometry::PlaneBoundedRegionGeometry (World *world, Space* space, const AxisAlignedBox &Size) 
	: Geometry(world,space)
{
    _ray = Ray (Vector3::ZERO, Vector3::NEGATIVE_UNIT_Y);
    _ray_query = _world->getSceneManager()->createRayQuery(_ray);

    _ray_query->setQueryTypeMask(SceneManager::WORLD_GEOMETRY_TYPE_MASK );
    _ray_query->setWorldFragmentType(SceneQuery::WFT_SINGLE_INTERSECTION); 
}

f32 PlaneBoundedRegionGeometry::getPointDepth(const Vector3& point)
{
    //dGetDepthFn(_geom,(dReal)point.x,(dReal)point.y,(dReal)point.z);
    return 0.0f;
}

void PlaneBoundedRegionGeometry::setPlaneListener(PlaneBoundedRegionGeometryPlaneListener* listener)
{
    _listener = listener;
}

bool PlaneBoundedRegionGeometry::queryResult(MovableObject *obj, const f32& distance)
{
    return false;
}

bool PlaneBoundedRegionGeometry::queryResult(SceneQuery::WorldFragment *fragment, const f32& distance)
{
    _distance_to_terrain = distance;
    return false;
}

const Vector3& PlaneBoundedRegionGeometry::getPosition()
{
    return Vector3::ZERO;
}

const Quaternion& PlaneBoundedRegionGeometry::getOrientation()
{
    return Quaternion::ZERO;
}

PlaneBoundedRegionGeometry::~PlaneBoundedRegionGeometry()
{
    _world->getSceneManager()->destroyQuery(_ray_query);
}
