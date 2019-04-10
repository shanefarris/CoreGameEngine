#include "Collision.h"
#include "Space.h"
#include "Geometry.h"

using namespace Ode;
using namespace Ogre;

CollisionListener::CollisionListener()
{
}

CollisionListener::~CollisionListener()
{
}


CollisionCallback::CollisionCallback()
{
}


CollisionCallback::~CollisionCallback()
{
}


void CollisionCallback::collisionCallback(Space* spaceFirst, Space* spaceSecond)
{
	spaceFirst->collide(static_cast<CollisionCallback*>(this), spaceSecond);
}
	
void CollisionCallback::collisionCallback(Space* space, Geometry* geometry)
{
	space->collide(static_cast<CollisionCallback*>(this), geometry);
}
	
void CollisionCallback::collisionCallback(Space* space)
{
	space->collide(static_cast<CollisionCallback*>(this));
}
	
void CollisionCallback::collisionCallback(Geometry* geometryFirst, Geometry* geometrySecond)
{
	geometryFirst->collide(geometrySecond, static_cast<CollisionListener*>(this));
}

void CollisionCallback::collisionCallback(void *data, dGeomID geom_a, dGeomID geom_b)
{
	CollisionCallback* colCallback = (CollisionCallback*) data;

	const bool a_space = (dGeomIsSpace(geom_a)) ? true : false;
	const bool b_space = (dGeomIsSpace(geom_b)) ? true : false;
	
	void* const ptr_a = dGeomGetData(geom_a);
	void* const ptr_b = dGeomGetData(geom_b);

	if(a_space  || b_space )
	{
		// Collide a space with a space
		if(a_space && b_space) 
			colCallback->collisionCallback(static_cast<Space*>(ptr_a), static_cast<Space*>(ptr_b));
			//static_cast<Space*>(ptr_a)->collide(static_cast<Space*>(ptr_b), colCallback);
		else if(a_space) 
			colCallback->collisionCallback(static_cast<Space*>(ptr_a), static_cast<Geometry*>(ptr_b));
			//static_cast<Space*>(ptr_a)->collide(static_cast<Geometry*>(ptr_b), colCallback);
		else 
			colCallback->collisionCallback(static_cast<Space*>(ptr_b), static_cast<Geometry*>(ptr_a));
			//static_cast<Space*>(ptr_b)->collide(static_cast<Geometry*>(ptr_a), colCallback);

		// Collide geometries internal to the spaces
		if(a_space) 
            static_cast<Space*>(ptr_a)->collide(colCallback);

		if(b_space) 
            static_cast<Space*>(ptr_b)->collide(colCallback);
	}
    else
	{
		// Collide a geom with a geom, i.e. generate contacts
		colCallback->collisionCallback(static_cast<Geometry*>(ptr_a), static_cast<Geometry*>(ptr_b));
		//static_cast<Geometry*>(ptr_a)->collide(static_cast<Geometry*>(ptr_b), static_cast<CollisionListener*>(colCallback));
	}
}

Contact::Contact()
{
}

Contact::~Contact()
{
}

const Vector3& Contact::getPosition()
{
	_position.x = (f32)(_contact->geom.pos[0]);
	_position.y = (f32)(_contact->geom.pos[1]);
	_position.z = (f32)(_contact->geom.pos[2]);
	return _position;
}

const Vector3& Contact::getNormal()
{
	_normal.x = (f32)(_contact->geom.normal[0]);
	_normal.y = (f32)(_contact->geom.normal[1]);
	_normal.z = (f32)(_contact->geom.normal[2]);
	return _normal;
}

f32 Contact::getPenetrationDepth()
{
	return (f32)(_contact->geom.depth);
}

Geometry* Contact::getFirstGeometry()
{
	dGeomID g = _contact->geom.g1;
	if(!g) 
		return nullptr;

	return (Geometry*)dGeomGetData(g);
}

Geometry* Contact::getSecondGeometry()
{
	dGeomID g = _contact->geom.g2;
	if(!g) 
		return nullptr;

	return (Geometry*)dGeomGetData(g);
}

int Contact::getFirstSide()
{
   return _contact->geom.side1;
}

int Contact::getSecondSide()
{
   return _contact->geom.side2;
} 

void Contact::setFirstFrictionDirection(const Vector3& vector)
{
	_contact->fdir1[0] = (dReal)vector.x;
	_contact->fdir1[1] = (dReal)vector.y;
	_contact->fdir1[2] = (dReal)vector.z;

	_contact->surface.mode |= (int)Flag_UseFirstFrictionDirection;
}

void Contact::setCoulombFriction(const f32& mu, const f32& additional_mu)
{
	_contact->surface.mu = mu;
	
	if(additional_mu >= 0.0)
	{
		_contact->surface.mu2 = additional_mu;
		_contact->surface.mode |= (int)Flag_UseAdditionalFriction;
	}
}

void Contact::setBouncyness(const f32& bouncyness, const f32& velocity_threshold)
{
	_contact->surface.bounce = bouncyness;
	if(velocity_threshold >= 0.0f)
	{
		_contact->surface.bounce_vel = velocity_threshold;
	}
	_contact->surface.mode |= (int)Flag_SurfaceIsBouncy;
}

void Contact::setSoftness(const f32& ERP, const f32& CFM)
{
	_contact->surface.soft_erp = ERP;
	_contact->surface.soft_cfm = CFM;

	_contact->surface.mode |= (int)Flag_UseERP;
	_contact->surface.mode |= (int)Flag_UseCFM;
}

void Contact::setIndependentMotion(const f32& velocity, const f32& additional_velocity)
{
	_contact->surface.motion1 = velocity;
	_contact->surface.mode |= (int)Flag_IndependentMotion; 

	if(additional_velocity >= 0.0)
	{
		_contact->surface.motion2 = additional_velocity;
		_contact->surface.mode |= (int)Flag_AdditionalIndependentMotion;
	}
}

void Contact::setForceDependentSlip(const f32& FDS)
{
	_contact->surface.slip1 = FDS;
	_contact->surface.mode |= (int)Flag_UseFDS;
}

void Contact::setAdditionalFDS(const f32& FDS)
{
	_contact->surface.slip2 = FDS;
	_contact->surface.mode |= (int)Flag_UseAdditionalFDS;
}

void Contact::setFrictionMode(Contact::Flag flag)
{
	assert((flag == Flag_FrictionPyramid)||(flag == Flag_BothFrictionPyramids)||(flag == Flag_AdditionalFrictionPyramid));
	_contact->surface.mode |= (int)flag;			
}

ContactMapCollisionListener::ContactMapCollisionListener()
{
}

bool ContactMapCollisionListener::collision(Contact* contact)
{
	return false;
	/*
	size_t mt1 = contact->getFirstGeometry()->getMaterialType();
	if(!mt1) return false;
	
	size_t mt2 = contact->getSecondGeometry()->getMaterialType();
	if(!mt2) return false;

	Contact *c = getContactPtr(mt1,mt2);
	if(!c) return false;

	contact->_contact->fdir1[0] = c->_contact->fdir1[0];
	contact->_contact->fdir1[1] = c->_contact->fdir1[1];
	contact->_contact->fdir1[2] = c->_contact->fdir1[2];

	contact->_contact->surface.mu = c->_contact->surface.mu;
	contact->_contact->surface.mu2 = c->_contact->surface.mu2;

	contact->_contact->surface.bounce = c->_contact->surface.bounce;
	contact->_contact->surface.bounce_vel = c->_contact->surface.bounce_vel;

	contact->_contact->surface.soft_erp = c->_contact->surface.soft_erp;
	contact->_contact->surface.soft_cfm = c->_contact->surface.soft_cfm;

	contact->_contact->surface.motion1 = c->_contact->surface.motion1;
	contact->_contact->surface.motion2 = c->_contact->surface.motion2;

	contact->_contact->surface.slip1 = c->_contact->surface.slip1;
	contact->_contact->surface.slip2 = c->_contact->surface.slip2;

	contact->_contact->surface.mode = c->_contact->surface.mode;

	return true;
	*/
}

void ContactMapCollisionListener::createContact(MaterialID materialA, MaterialID materialB)
{
	auto i = _map.find(materialA);
	if(i == _map.end())
	{
		_map.insert(MaterialMapPair(materialA,new MaterialMap()));
		i = _map.find(materialA);
	}

	auto j = i->second->find(materialB);
	if(j == i->second->end())
	{
		Contact *c = new Contact();
		memset(c->_contact, 0, sizeof(dContact));

		i->second->insert(std::pair<MaterialID, Contact*>(materialB, c));
	}
}

Contact *ContactMapCollisionListener::getContactPtr(MaterialID materialA, MaterialID materialB)
{
	Contact *c = nullptr;
	MaterialID A = materialA;
	MaterialID B = materialB;

	auto i = _map.find(A);
	if(i == _map.end())
	{
		B = materialA;
		A = materialB;

		i = _map.find(A);
	}

	if(i != _map.end())
	{
		auto j = i->second->find(B);
		if(j != i->second->end())
		{
			c = j->second;
		}
	}

	return c;
}

ContactMapCollisionListener::~ContactMapCollisionListener()
{
	for(auto i = _map.cbegin(); i != _map.cend(); ++i)
	{
		MaterialMap::iterator j = i->second->begin();
		MaterialMap::iterator j_end = i->second->end();

		for(;j != j_end;++j) 
			delete j->second;

		delete i->second;
	}
}
