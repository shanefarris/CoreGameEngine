#include "DebugObject.h"

#include "OgreFont.h"
#include "OgreVertexIndexData.h"
#include "OgreMaterialManager.h"
#include "OgreTechnique.h"
#include "OgreHardwareBufferManager.h"
#include "OgreCamera.h"

using namespace Ode;
using namespace Ogre;

//------------------------------------------------------------------------------------------------
bool DebugLines::_materials_created = false;
//------------------------------------------------------------------------------------------------
DebugLines::DebugLines() : SimpleRenderable()
{
	mRenderOp.vertexData = new Ogre::VertexData();
   _drawn = false;

	if (!_materials_created)
	{
		MaterialPtr red = MaterialManager::getSingleton().create("OgreOdeDebugLines/Disabled","General");
		MaterialPtr green = MaterialManager::getSingleton().create("OgreOdeDebugLines/Enabled","General");
		MaterialPtr blue = MaterialManager::getSingleton().create("OgreOdeDebugLines/Static","General");

        red->setReceiveShadows(false);
		red->getTechnique(0)->setLightingEnabled(true);
		red->getTechnique(0)->getPass(0)->setSelfIllumination(1,0,0);

        green->setReceiveShadows(false);
		green->getTechnique(0)->setLightingEnabled(true);
		green->getTechnique(0)->getPass(0)->setSelfIllumination(0,1,0);

        blue->setReceiveShadows(false);
		blue->getTechnique(0)->setLightingEnabled(true);
		blue->getTechnique(0)->getPass(0)->setSelfIllumination(0,0,1);

		_materials_created = true;
	}
    setCastShadows (false);
	this->setMaterial("OgreOdeDebugLines/Enabled");
}


//------------------------------------------------------------------------------------------------
void DebugLines::clear()
{
	if (_drawn)
	{
		_drawn = false;
		_points.clear();
		delete mRenderOp.vertexData;

		mRenderOp.vertexData = new Ogre::VertexData();
	}
}
//------------------------------------------------------------------------------------------------
DebugLines::~DebugLines(void)
{
   clear();

   delete mRenderOp.vertexData;
}
//------------------------------------------------------------------------------------------------
void DebugLines::draw()
{
   if (_drawn) 
       return;
   else 
       _drawn = true;

   // Initialization stuff
   mRenderOp.indexData = 0;
   mRenderOp.vertexData->vertexCount = _points.size();
   mRenderOp.vertexData->vertexStart = 0;
   mRenderOp.operationType = RenderOperation::OT_LINE_LIST;
   mRenderOp.useIndexes = false;

   Ogre::VertexDeclaration *decl = mRenderOp.vertexData->vertexDeclaration;
   Ogre::VertexBufferBinding *bind = mRenderOp.vertexData->vertexBufferBinding;

   decl->addElement(0, 0, VET_FLOAT3, VES_POSITION);

   auto vbuf = HardwareBufferManager::getSingleton().createVertexBuffer(decl->getVertexSize(0), 
																		mRenderOp.vertexData->vertexCount, 
																		HardwareBuffer::HBU_STATIC_WRITE_ONLY);

   bind->setBinding(0, vbuf);

   // Drawing stuff
   unsigned int size = (unsigned int)_points.size();
   Vector3 vaabMin = _points[0];
   Vector3 vaabMax = _points[0];

   float *prPos = static_cast<float*>(vbuf->lock(HardwareBuffer::HBL_DISCARD));

   for(unsigned int i = 0; i < size; i++)
   {
      *prPos++ = _points[i].x;
      *prPos++ = _points[i].y;
      *prPos++ = _points[i].z;

      if (_points[i].x < vaabMin.x)
         vaabMin.x = _points[i].x;
      if (_points[i].y < vaabMin.y)
         vaabMin.y = _points[i].y;
      if (_points[i].z < vaabMin.z)
         vaabMin.z = _points[i].z;

      if (_points[i].x > vaabMax.x)
         vaabMax.x = _points[i].x;
      if (_points[i].y > vaabMax.y)
         vaabMax.y = _points[i].y;
      if (_points[i].z > vaabMax.z)
         vaabMax.z = _points[i].z;
   }

   vbuf->unlock();

   mBox.setExtents(vaabMin, vaabMax);
}
//------------------------------------------------------------------------------------------------
Real DebugLines::getSquaredViewDepth(const Camera *cam) const
{
	Vector3 vMin, vMax, vMid, vDist;
	vMin = mBox.getMinimum();
	vMax = mBox.getMaximum();
	vMid = ((vMin - vMax) * 0.5f) + vMin;
	vDist = cam->getDerivedPosition() - vMid;

	return vDist.squaredLength();
}
//------------------------------------------------------------------------------------------------
Real DebugLines::getBoundingRadius() const
{
	return Math::Sqrt(std::max(mBox.getMaximum().squaredLength(), mBox.getMinimum().squaredLength()));
}
//------------------------------------------------------------------------------------------------
DebugObject::DebugObject(DebugObject::Mode mode) 
{
	_mode = DebugObject::Mode_Unknown;
	setMode(mode);
}
//------------------------------------------------------------------------------------------------
void DebugObject::setMode(DebugObject::Mode mode)
{
	if (mode != _mode)
	{
		_mode = mode;
		switch(_mode)
		{
			case DebugObject::Mode_Enabled:
				setMaterial("OgreOdeDebugLines/Enabled");
			break;

			case DebugObject::Mode_Disabled:
				setMaterial("OgreOdeDebugLines/Disabled");

			break;

			case DebugObject::Mode_Static:
				setMaterial("OgreOdeDebugLines/Static");
			break;
		}
	}
}
//------------------------------------------------------------------------------------------------
DebugObject::~DebugObject() 
{
}
//------------------------------------------------------------------------------------------------
BoxDebugObject::BoxDebugObject(const Vector3& size):DebugObject()
{
	AxisAlignedBox aabb(-size.x * 0.5f, -size.y * 0.5f, -size.z * 0.5f,
						size.x * 0.5f, size.y * 0.5f, size.z * 0.5f);

	Vector3 vmax = aabb.getMaximum();
	Vector3 vmin = aabb.getMinimum();

	addLine(vmin.x,vmin.y,vmin.z,vmax.x,vmin.y,vmin.z);
	addLine(vmin.x,vmin.y,vmin.z,vmin.x,vmin.y,vmax.z);
	addLine(vmin.x,vmin.y,vmin.z,vmin.x,vmax.y,vmin.z);
	addLine(vmin.x,vmax.y,vmin.z,vmin.x,vmax.y,vmax.z);
	addLine(vmin.x,vmax.y,vmin.z,vmax.x,vmax.y,vmin.z);
	addLine(vmax.x,vmin.y,vmin.z,vmax.x,vmin.y,vmax.z);
	addLine(vmax.x,vmin.y,vmin.z,vmax.x,vmax.y,vmin.z);
	addLine(vmin.x,vmax.y,vmax.z,vmax.x,vmax.y,vmax.z);
	addLine(vmin.x,vmax.y,vmax.z,vmin.x,vmin.y,vmax.z);
	addLine(vmax.x,vmax.y,vmin.z,vmax.x,vmax.y,vmax.z);
	addLine(vmax.x,vmin.y,vmax.z,vmax.x,vmax.y,vmax.z);
	addLine(vmin.x,vmin.y,vmax.z,vmax.x,vmin.y,vmax.z);

	draw();
}
//------------------------------------------------------------------------------------------------
BoxDebugObject::~BoxDebugObject()
{
}
//------------------------------------------------------------------------------------------------
SphereDebugObject::SphereDebugObject(Real radius):DebugObject()
{
	// X/Y axis

	// NW quadrant
	addLine(-radius,			0.0f,				0.0f,
	-0.866f * radius,	0.5f * radius,		0.0f);

	addLine(-0.866f * radius,	0.5f * radius,		0.0f,
	-0.5f * radius,	0.866f * radius,	0.0f);

	addLine(-0.5f * radius,	0.866f * radius,	0.0f,
	0.0f,				radius,			0.0f);

	// NE quadrant
	addLine(0.0f,				radius,			0.0f,
	0.5f * radius,		0.866f * radius,	0.0f);

	addLine(0.5f * radius,		0.866f * radius,	0.0f,
	0.866f * radius,	0.5f * radius,		0.0f);

	addLine(0.866f * radius,	0.5f * radius,		0.0f,
	radius,			0.0f,				0.0f);

	// SW quadrant
	addLine(-radius,			0.0f,				0.0f,
	-0.866f * radius,	-0.5f * radius,	0.0f);

	addLine(-0.866f * radius,	-0.5f * radius,	0.0f,
	-0.5f * radius,	-0.866f * radius,	0.0f);

	addLine(-0.5f * radius,	-0.866f * radius,	0.0f,
	0.0f,				-radius,			0.0f);

	// SE quadrant
	addLine(0.0f,				-radius,			0.0f,
	0.5f * radius,		-0.866f * radius,	0.0f);

	addLine(0.5f * radius,		-0.866f * radius,	0.0f,
	0.866f * radius,	-0.5f * radius,	0.0f);

	addLine(0.866f * radius,	-0.5f * radius,	0.0f,
	radius,			0.0f,				0.0f);

	// X/Z axis

	// NW quadrant
	addLine(-radius,			0.0f,	0.0f,	
	-0.866f * radius,	0.0f,	0.5f * radius);

	addLine(-0.866f * radius,	0.0f,	0.5f * radius,
	-0.5f * radius,	0.0f,	0.866f * radius);

	addLine(-0.5f * radius,	0.0f,	0.866f * radius,
	0.0f,				0.0f,	radius);

	// NE quadrant
	addLine(0.0f,				0.0f,	radius,
	0.5f * radius,		0.0f,	0.866f * radius);

	addLine(0.5f * radius,		0.0f,	0.866f * radius,
	0.866f * radius,	0.0f,	0.5f * radius);

	addLine(0.866f * radius,	0.0f,	0.5f * radius,
	radius,			0.0f,	0.0f);

	// SW quadrant
	addLine(-radius,			0.0f,	0.0f,	
	-0.866f * radius,	0.0f,	-0.5f * radius);

	addLine(-0.866f * radius,	0.0f,	-0.5f * radius,
	-0.5f * radius,	0.0f,	-0.866f * radius);

	addLine(-0.5f * radius,	0.0f,	-0.866f * radius,
	0.0f,				0.0f,	-radius);

	// SE quadrant
	addLine(0.0f,				0.0f,	-radius,
	0.5f * radius,		0.0f,	-0.866f * radius);

	addLine(0.5f * radius,		0.0f,	-0.866f * radius,
	0.866f * radius,	0.0f,	-0.5f * radius);

	addLine(0.866f * radius,	0.0f,	-0.5f * radius,
	radius,			0.0f,	0.0f);

	// Y/Z axis

	// NW quadrant
	addLine(0.0f,	-radius,			0.0f,	
	0.0f,	-0.866f * radius,	0.5f * radius);

	addLine(0.0f,	-0.866f * radius,	0.5f * radius,
	0.0f,	-0.5f * radius,	0.866f * radius);

	addLine(0.0f,	-0.5f * radius,	0.866f * radius,
	0.0f,	0.0f,				radius);

	// NE quadrant
	addLine(0.0f,	0.0f,				radius,
	0.0f,	0.5f * radius,		0.866f * radius);

	addLine(0.0f,	0.5f * radius,		0.866f * radius,
	0.0f,	0.866f * radius,	0.5f * radius);

	addLine(0.0f,	0.866f * radius,	0.5f * radius,
	0.0f,	radius,			0.0f);

	// SW quadrant
	addLine(0.0f,	-radius,			0.0f,	
	0.0f,	-0.866f * radius,	-0.5f * radius);

	addLine(0.0f,	-0.866f * radius,	-0.5f * radius,
	0.0f,	-0.5f * radius,	-0.866f * radius);

	addLine(0.0f,	-0.5f * radius,	-0.866f * radius,
	0.0f,	0.0f,				-radius);

	// SE quadrant
	addLine(0.0f,	0.0f,				-radius,
	0.0f,	0.5f * radius,		-0.866f * radius);

	addLine(0.0f,	0.5f * radius,		-0.866f * radius,
	0.0f,	0.866f * radius,	-0.5f * radius);

	addLine(0.0f,	0.866f * radius,	-0.5f * radius,
	0.0f,	radius,			0.0f);

	draw();
}
//------------------------------------------------------------------------------------------------
SphereDebugObject::~SphereDebugObject()
{
}
//------------------------------------------------------------------------------------------------
CapsuleDebugObject::CapsuleDebugObject(Real radius,Real length):DebugObject()
{
	Real halflen = length * 0.5f;
	AxisAlignedBox aabb(-radius,-radius,-(halflen + radius),radius,radius,halflen + radius);

	// X/Y axis - Near

	// NW quadrant
	addLine(-radius,			0.0f,				halflen,
	-0.866f * radius,	0.5f * radius,		halflen);

	addLine(-0.866f * radius,	0.5f * radius,		halflen,
		-0.5f * radius,	0.866f * radius,	halflen);

	addLine(-0.5f * radius,	0.866f * radius,	halflen,
	0.0f,				radius,			halflen);

	// NE quadrant
	addLine(0.0f,				radius,			halflen,
		0.5f * radius,		0.866f * radius,	halflen);

	addLine(0.5f * radius,		0.866f * radius,	halflen,
	0.866f * radius,	0.5f * radius,		halflen);

	addLine(0.866f * radius,	0.5f * radius,		halflen,
	radius,			0.0f,				halflen);

	// SW quadrant
	addLine(-radius,			0.0f,				halflen,
	-0.866f * radius,	-0.5f * radius,	halflen);

	addLine(-0.866f * radius,	-0.5f * radius,	halflen,
	-0.5f * radius,	-0.866f * radius,	halflen);

	addLine(-0.5f * radius,	-0.866f * radius,	halflen,
	0.0f,				-radius,			halflen);

	// SE quadrant
	addLine(0.0f,				-radius,			halflen,
	0.5f * radius,		-0.866f * radius,	halflen);

	addLine(0.5f * radius,		-0.866f * radius,	halflen,
	0.866f * radius,	-0.5f * radius,	halflen);

	addLine(0.866f * radius,	-0.5f * radius,	halflen,
	radius,			0.0f,				halflen);
	
	// X/Y axis - Far

	// NW quadrant
	addLine(-radius,			0.0f,				-halflen,
	-0.866f * radius,	0.5f * radius,		-halflen);

	addLine(-0.866f * radius,	0.5f * radius,		-halflen,
	-0.5f * radius,	0.866f * radius,	-halflen);

	addLine(-0.5f * radius,	0.866f * radius,	-halflen,
	0.0f,				radius,			-halflen);

	// NE quadrant
	addLine(0.0f,				radius,			-halflen,
	0.5f * radius,		0.866f * radius,	-halflen);

	addLine(0.5f * radius,		0.866f * radius,	-halflen,
	0.866f * radius,	0.5f * radius,		-halflen);

	addLine(0.866f * radius,	0.5f * radius,		-halflen,
	radius,			0.0f,				-halflen);

	// SW quadrant
	addLine(-radius,			0.0f,				-halflen,
	-0.866f * radius,	-0.5f * radius,	-halflen);

	addLine(-0.866f * radius,	-0.5f * radius,	-halflen,
	-0.5f * radius,	-0.866f * radius,	-halflen);

	addLine(-0.5f * radius,	-0.866f * radius,	-halflen,
	0.0f,				-radius,			-halflen);

	// SE quadrant
	addLine(0.0f,				-radius,			-halflen,
	0.5f * radius,		-0.866f * radius,	-halflen);

	addLine(0.5f * radius,		-0.866f * radius,	-halflen,
	0.866f * radius,	-0.5f * radius,	-halflen);

	addLine(0.866f * radius,	-0.5f * radius,	-halflen,
	radius,			0.0f,				-halflen);

	// X/Z axis

	// NW quadrant
	addLine(-radius,			0.0f,	halflen,	
	-0.866f * radius,	0.0f,	(0.5f * radius) + halflen);

	addLine(-0.866f * radius,	0.0f,	(0.5f * radius) + halflen,
	-0.5f * radius,	0.0f,	(0.866f * radius) + halflen);

	addLine(-0.5f * radius,	0.0f,	(0.866f * radius) + halflen,
	0.0f,				0.0f,	radius + halflen);

	// NE quadrant
	addLine(0.0f,				0.0f,	radius + halflen,
	0.5f * radius,		0.0f,	(0.866f * radius) + halflen);

	addLine(0.5f * radius,		0.0f,	(0.866f * radius) + halflen,
	0.866f * radius,	0.0f,	(0.5f * radius) + halflen);

	addLine(0.866f * radius,	0.0f,	(0.5f * radius) + halflen,
	radius,			0.0f,	halflen);

	// SW quadrant
	addLine(-radius,			0.0f,	-halflen,	
	-0.866f * radius,	0.0f,	(-0.5f * radius) - halflen);

	addLine(-0.866f * radius,	0.0f,	(-0.5f * radius) - halflen,
	-0.5f * radius,	0.0f,	(-0.866f * radius) - halflen);

	addLine(-0.5f * radius,	0.0f,	(-0.866f * radius) - halflen,
	0.0f,				0.0f,	-radius - halflen);

	// SE quadrant
	addLine(0.0f,				0.0f,	-radius - halflen,
	0.5f * radius,		0.0f,	(-0.866f * radius) - halflen);

	addLine(0.5f * radius,		0.0f,	(-0.866f * radius) - halflen,
	0.866f * radius,	0.0f,	(-0.5f * radius) - halflen);

	addLine(0.866f * radius,	0.0f,	(-0.5f * radius) - halflen,
	radius,			0.0f,	- halflen);

	// Y/Z axis

	// NW quadrant
	addLine(0.0f,	-radius,			halflen,	
	0.0f,	-0.866f * radius,	(0.5f * radius) + halflen);

	addLine(0.0f,	-0.866f * radius,	(0.5f * radius) + halflen,
	0.0f,	-0.5f * radius,	(0.866f * radius) + halflen);

	addLine(0.0f,	-0.5f * radius,	(0.866f * radius) + halflen,
	0.0f,	0.0f,				radius + halflen);

	// NE quadrant
	addLine(0.0f,	0.0f,				radius + halflen,
	0.0f,	0.5f * radius,		(0.866f * radius) + halflen);

	addLine(0.0f,	0.5f * radius,		(0.866f * radius) + halflen,
	0.0f,	0.866f * radius,	(0.5f * radius) + halflen);

	addLine(0.0f,	0.866f * radius,	(0.5f * radius) + halflen,
	0.0f,	radius,			halflen);

	// SW quadrant
	addLine(0.0f,	-radius,			-halflen,	
	0.0f,	-0.866f * radius,	(-0.5f * radius) - halflen);

	addLine(0.0f,	-0.866f * radius,	(-0.5f * radius) - halflen,
	0.0f,	-0.5f * radius,	(-0.866f * radius) - halflen);

	addLine(0.0f,	-0.5f * radius,	(-0.866f * radius) - halflen,
	0.0f,	0.0f,				-radius - halflen);

	// SE quadrant
	addLine(0.0f,	0.0f,				-radius - halflen,
	0.0f,	0.5f * radius,		(-0.866f * radius) - halflen);

	addLine(0.0f,	0.5f * radius,		(-0.866f * radius) - halflen,
	0.0f,	0.866f * radius,	(-0.5f * radius) - halflen);

	addLine(0.0f,	0.866f * radius,	(-0.5f * radius) - halflen,
	0.0f,	radius,			-halflen);

	// Side lines
	addLine(-radius,	0.0f,		-halflen,
	-radius,	0.0f,		halflen);

	addLine(radius,	0.0f,		-halflen,
	radius,	0.0f,		halflen);

	addLine(0.0f,		radius,	-halflen,
	0.0f,		radius,	halflen);

	addLine(0.0f,		-radius,	-halflen,
	0.0f,		-radius,	halflen);

	draw();
}
//------------------------------------------------------------------------------------------------
CapsuleDebugObject::~CapsuleDebugObject()
{
}
//------------------------------------------------------------------------------------------------
CylinderDebugObject::CylinderDebugObject(Real radius,Real length):DebugObject()
{
	Real halflen = length * 0.5f;
	AxisAlignedBox aabb(-radius,-radius,-(halflen + radius),radius,radius,halflen + radius);

	// X/Y axis - Near

	// NW quadrant
	addLine(-radius,			0.0f,				halflen,
		-0.866f * radius,	0.5f * radius,		halflen);

	addLine(-0.866f * radius,	0.5f * radius,		halflen,
		-0.5f * radius,	0.866f * radius,	halflen);

	addLine(-0.5f * radius,	0.866f * radius,	halflen,
		0.0f,				radius,			halflen);

	// NE quadrant
	addLine(0.0f,				radius,			halflen,
		0.5f * radius,		0.866f * radius,	halflen);

	addLine(0.5f * radius,		0.866f * radius,	halflen,
		0.866f * radius,	0.5f * radius,		halflen);

	addLine(0.866f * radius,	0.5f * radius,		halflen,
		radius,			0.0f,				halflen);

	// SW quadrant
	addLine(-radius,			0.0f,				halflen,
		-0.866f * radius,	-0.5f * radius,	halflen);

	addLine(-0.866f * radius,	-0.5f * radius,	halflen,
		-0.5f * radius,	-0.866f * radius,	halflen);

	addLine(-0.5f * radius,	-0.866f * radius,	halflen,
		0.0f,				-radius,			halflen);

	// SE quadrant
	addLine(0.0f,				-radius,			halflen,
		0.5f * radius,		-0.866f * radius,	halflen);

	addLine(0.5f * radius,		-0.866f * radius,	halflen,
		0.866f * radius,	-0.5f * radius,	halflen);

	addLine(0.866f * radius,	-0.5f * radius,	halflen,
		radius,			0.0f,				halflen);

	// X/Y axis - Far

	// NW quadrant
	addLine(-radius,			0.0f,				-halflen,
		-0.866f * radius,	0.5f * radius,		-halflen);

	addLine(-0.866f * radius,	0.5f * radius,		-halflen,
		-0.5f * radius,	0.866f * radius,	-halflen);

	addLine(-0.5f * radius,	0.866f * radius,	-halflen,
		0.0f,				radius,			-halflen);

	// NE quadrant
	addLine(0.0f,				radius,			-halflen,
		0.5f * radius,		0.866f * radius,	-halflen);

	addLine(0.5f * radius,		0.866f * radius,	-halflen,
		0.866f * radius,	0.5f * radius,		-halflen);

	addLine(0.866f * radius,	0.5f * radius,		-halflen,
		radius,			0.0f,				-halflen);

	// SW quadrant
	addLine(-radius,			0.0f,				-halflen,
		-0.866f * radius,	-0.5f * radius,	-halflen);

	addLine(-0.866f * radius,	-0.5f * radius,	-halflen,
		-0.5f * radius,	-0.866f * radius,	-halflen);

	addLine(-0.5f * radius,	-0.866f * radius,	-halflen,
		0.0f,				-radius,			-halflen);

	// SE quadrant
	addLine(0.0f,				-radius,			-halflen,
		0.5f * radius,		-0.866f * radius,	-halflen);

	addLine(0.5f * radius,		-0.866f * radius,	-halflen,
		0.866f * radius,	-0.5f * radius,	-halflen);

	addLine(0.866f * radius,	-0.5f * radius,	-halflen,
		radius,			0.0f,				-halflen);

	// X/Z axis

	// NW quadrant
	addLine(-radius,			0.0f,	halflen,	
		-0.866f * radius,	0.0f,	(0.5f * radius) + halflen);

	addLine(-0.866f * radius,	0.0f,	(0.5f * radius) + halflen,
		-0.5f * radius,	0.0f,	(0.866f * radius) + halflen);

	addLine(-0.5f * radius,	0.0f,	(0.866f * radius) + halflen,
		0.0f,				0.0f,	radius + halflen);

	// NE quadrant
	addLine(0.0f,				0.0f,	radius + halflen,
		0.5f * radius,		0.0f,	(0.866f * radius) + halflen);

	addLine(0.5f * radius,		0.0f,	(0.866f * radius) + halflen,
		0.866f * radius,	0.0f,	(0.5f * radius) + halflen);

	addLine(0.866f * radius,	0.0f,	(0.5f * radius) + halflen,
		radius,			0.0f,	halflen);

	// SW quadrant
	addLine(-radius,			0.0f,	-halflen,	
		-0.866f * radius,	0.0f,	(-0.5f * radius) - halflen);

	addLine(-0.866f * radius,	0.0f,	(-0.5f * radius) - halflen,
		-0.5f * radius,	0.0f,	(-0.866f * radius) - halflen);

	addLine(-0.5f * radius,	0.0f,	(-0.866f * radius) - halflen,
		0.0f,				0.0f,	-radius - halflen);

	// SE quadrant
	addLine(0.0f,				0.0f,	-radius - halflen,
		0.5f * radius,		0.0f,	(-0.866f * radius) - halflen);

	addLine(0.5f * radius,		0.0f,	(-0.866f * radius) - halflen,
		0.866f * radius,	0.0f,	(-0.5f * radius) - halflen);

	addLine(0.866f * radius,	0.0f,	(-0.5f * radius) - halflen,
		radius,			0.0f,	- halflen);

	// Y/Z axis

	// NW quadrant
	addLine(0.0f,	-radius,			halflen,	
		0.0f,	-0.866f * radius,	(0.5f * radius) + halflen);

	addLine(0.0f,	-0.866f * radius,	(0.5f * radius) + halflen,
		0.0f,	-0.5f * radius,	(0.866f * radius) + halflen);

	addLine(0.0f,	-0.5f * radius,	(0.866f * radius) + halflen,
		0.0f,	0.0f,				radius + halflen);

	// NE quadrant
	addLine(0.0f,	0.0f,				radius + halflen,
		0.0f,	0.5f * radius,		(0.866f * radius) + halflen);

	addLine(0.0f,	0.5f * radius,		(0.866f * radius) + halflen,
		0.0f,	0.866f * radius,	(0.5f * radius) + halflen);

	addLine(0.0f,	0.866f * radius,	(0.5f * radius) + halflen,
		0.0f,	radius,			halflen);

	// SW quadrant
	addLine(0.0f,	-radius,			-halflen,	
		0.0f,	-0.866f * radius,	(-0.5f * radius) - halflen);

	addLine(0.0f,	-0.866f * radius,	(-0.5f * radius) - halflen,
		0.0f,	-0.5f * radius,	(-0.866f * radius) - halflen);

	addLine(0.0f,	-0.5f * radius,	(-0.866f * radius) - halflen,
		0.0f,	0.0f,				-radius - halflen);

	// SE quadrant
	addLine(0.0f,	0.0f,				-radius - halflen,
		0.0f,	0.5f * radius,		(-0.866f * radius) - halflen);

	addLine(0.0f,	0.5f * radius,		(-0.866f * radius) - halflen,
		0.0f,	0.866f * radius,	(-0.5f * radius) - halflen);

	addLine(0.0f,	0.866f * radius,	(-0.5f * radius) - halflen,
		0.0f,	radius,			-halflen);

	// Side lines
	addLine(-radius,	0.0f,		-halflen,
		-radius,	0.0f,		halflen);

	addLine(radius,	0.0f,		-halflen,
		radius,	0.0f,		halflen);

	addLine(0.0f,		radius,	-halflen,
		0.0f,		radius,	halflen);

	addLine(0.0f,		-radius,	-halflen,
		0.0f,		-radius,	halflen);

	draw();
}
//------------------------------------------------------------------------------------------------
CylinderDebugObject::~CylinderDebugObject()
{
}
//------------------------------------------------------------------------------------------------
TriangleMeshDebugObject::TriangleMeshDebugObject(int vertex_count):DebugObject()
{
    _points.reserve(vertex_count); 
    _points.resize(vertex_count); 
}
//------------------------------------------------------------------------------------------------
void TriangleMeshDebugObject::beginDefinition()
{
}
//------------------------------------------------------------------------------------------------
void TriangleMeshDebugObject::setVertex(int index,const Vector3& vertex)
{
    assert ((unsigned int)index < _points.size());
	_points[index] = vertex;
}
//------------------------------------------------------------------------------------------------
void TriangleMeshDebugObject::endDefinition()
{
	draw();
}
//------------------------------------------------------------------------------------------------
TriangleMeshDebugObject::~TriangleMeshDebugObject()
{
}
//------------------------------------------------------------------------------------------------
RayDebugObject::RayDebugObject(const Vector3& start,
							   const Vector3& direction,
							   const Ogre::Real length):
DebugObject()
{

	Vector3 end;

	if(length == Ogre::Math::POS_INFINITY)
	{
		end = (start + (direction.normalisedCopy() * 100000.0));
	}
	else
	{
		end = (start + (direction.normalisedCopy() * length));
	}

	addLine(start, end);

	draw();
} 
void RayDebugObject::setDefinition(const Vector3& start,
								   const Vector3& direction,
								   const Ogre::Real length)
{
	clear();

	Vector3 end;

	if(length == Ogre::Math::POS_INFINITY)
	{
		end = (start + (direction.normalisedCopy() * 100000.0));
	}
	else
	{
		end = (start + (direction.normalisedCopy() * length));
	}

	addLine(start, end);

	draw();
} 
//------------------------------------------------------------------------------------------------
RayDebugObject::~RayDebugObject()
{
}
//------------------------------------------------------------------------------------------------

