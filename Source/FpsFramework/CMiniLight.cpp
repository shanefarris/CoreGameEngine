#if 0
#include "CMiniLight.h"
#include "CMaterialGenerator.h"

using namespace Core::Effects;


CMiniLight::CMiniLight(CMaterialGenerator *sys): bIgnoreWorld(false), mGenerator(sys), mPermutation(0)
{
	// Set up geometry
	//setMaterial("DeferredShading/Post/LightMaterial");
	// Set render priority to high (just after normal postprocess)
	setRenderQueueGroup(RENDER_QUEUE_2);
	// Allocate render operation
	mRenderOp.operationType = RenderOperation::OT_TRIANGLE_LIST;
	mRenderOp.indexData = 0;
	mRenderOp.vertexData = 0;
	mRenderOp.useIndexes = true;
	m_pQuadVertexData = nullptr;
	m_pSphereVertexData = nullptr;
	m_pIndexData = nullptr;

	// Diffuse and specular colour
	setDiffuseColour(ColourValue(1,1,1));
	setSpecularColour(ColourValue(0,0,0));
	// Set Attenuation
	setAttenuation(1.0f, 1.0f,0.0f,0.0f);

	createRectangle2D();
	updateGeometry( Vector3::ZERO );
}

CMiniLight::~CMiniLight()
{
	// need to release IndexData and vertexData created for renderable
	CORE_DELETE(m_pQuadVertexData);
	CORE_DELETE(m_pSphereVertexData);
	CORE_DELETE(m_pIndexData);

	mRenderOp.vertexData = nullptr;
	mRenderOp.indexData = nullptr;

}

void CMiniLight::setAttenuation(float r, float c, float b, float a)
{

	setCustomParameter(3, Vector4(r, c, b, a));

	if(r != 0.0f || c != 1.0f || b != 0.0f || a != 0.0f)
		mPermutation |= MI_ATTENUATED;
	else
		mPermutation &= ~MI_ATTENUATED;



	// original calculation
	//b *= 100;
	//a *= 100;

	//// Set Attenuation parameter to shader
	//setCustomParameter(3, Vector4(c, b, a, 0));

	///// There is attenuation? Set material accordingly
	//if(c != 1.0f || b != 0.0f || a != 0.0f)
	//	mPermutation |= MI_ATTENUATED;
	//else
	//	mPermutation &= ~MI_ATTENUATED;

	//// Calculate radius from Attenuation
	//int threshold_level = 30;// differece of 10-15 levels deemed unnoticable
	//float threshold = 1.0f/((float)threshold_level/256.0f); 

	//// Use quadratic formula to determine outer radius
	//c = c-threshold;
	//float d=sqrt(b*b-4*a*c);
	//float x=(-2*c)/(b+d);



	rebuildGeometry(r*1.1f);
}

void CMiniLight::setDiffuseColour(const ColourValue &col)
{
	setCustomParameter(1, Vector4(col.r, col.g, col.b, col.a));
}

void CMiniLight::setSpecularColour(const ColourValue &col)
{
	setCustomParameter(2, Vector4(col.r, col.g, col.b, col.a));
	/// There is a specular component? Set material accordingly
	
	if(col.r != 0.0f || col.g != 0.0f || col.b != 0.0f)
		mPermutation |= MI_SPECULAR;
	else
		mPermutation &= ~MI_SPECULAR;
		
}

ColourValue CMiniLight::getDiffuseColour()
{
	Vector4 val = getCustomParameter(1);
	return ColourValue(val[0], val[1], val[2], val[3]);
}

ColourValue CMiniLight::getSpecularColour()
{
	Vector4 val = getCustomParameter(2);
	return ColourValue(val[0], val[1], val[2], val[3]);
}

void CMiniLight::rebuildGeometry(float radius)
{
	// Scale node to radius
	
	//if(radius > 10.0f)
	//{
	//	createRectangle2D();
	//	mPermutation |= MI_QUAD;
	//}
	//else
	//{
	//	/// XXX some more intelligent expression for rings and segments
	//	createSphere(radius, 5, 5);
	//	mPermutation &= ~MI_QUAD;
	//}

	createSphere(radius, 10, 10);
}

void CMiniLight::updateGeometry( const Vector3& camPos )
{
	SceneNode* sceneNode = getParentSceneNode();

	if(!sceneNode)
	{
		mPermutation |= MI_QUAD;

		mRenderOp.vertexData = m_pQuadVertexData;
		mRenderOp.indexData = 0;
		mRenderOp.operationType = RenderOperation::OT_TRIANGLE_STRIP; 
		mRenderOp.useIndexes = false;

		setBoundingBox(AxisAlignedBox(-10000,-10000,-10000,10000,10000,10000));
		mRadius = 15000;
		bIgnoreWorld = true;
	}
	else
	{
		Vector3 lengthVec = sceneNode->_getDerivedPosition() - camPos;
		float lengthFloat = lengthVec.length();

		if( lengthFloat > m_sphereRadius * 1.2f )
		{
			if(bIgnoreWorld == true)
			{
				mPermutation &= ~MI_QUAD;

				mRenderOp.operationType = RenderOperation::OT_TRIANGLE_LIST;
				mRenderOp.indexData = m_pIndexData;
				mRenderOp.vertexData = m_pSphereVertexData;
				mRenderOp.useIndexes = true;

				setBoundingBox( AxisAlignedBox( Vector3(-m_sphereRadius, -m_sphereRadius, -m_sphereRadius), Vector3(m_sphereRadius, m_sphereRadius, m_sphereRadius) ) );
				mRadius = m_sphereRadius;
				bIgnoreWorld = false;
				//setVisible(false);
			}
		}
		else
		{
			if(bIgnoreWorld == false)
			{
				mPermutation |= MI_QUAD;

				mRenderOp.vertexData = m_pQuadVertexData;
				mRenderOp.indexData = 0;
				mRenderOp.operationType = RenderOperation::OT_TRIANGLE_STRIP; 
				mRenderOp.useIndexes = false;

				setBoundingBox(AxisAlignedBox(-10000,-10000,-10000,10000,10000,10000));
				mRadius = 15000;
				bIgnoreWorld = true;
				//setVisible(true);
			}
		}
	}
}

void CMiniLight::createRectangle2D()
{
	/// XXX this RenderOp should really be re-used between CMiniLight objects,
	/// not generated every time
	//delete mRenderOp.vertexData; 
	//delete mRenderOp.indexData; 
	//mRenderOp.vertexData = new VertexData();
	m_pQuadVertexData = new VertexData();
    //mRenderOp.indexData = 0;

    m_pQuadVertexData->vertexCount = 4; 
    m_pQuadVertexData->vertexStart = 0; 
    //mRenderOp.operationType = RenderOperation::OT_TRIANGLE_STRIP; 
    //mRenderOp.useIndexes = false; 

    VertexDeclaration* decl = m_pQuadVertexData->vertexDeclaration;
    VertexBufferBinding* bind = m_pQuadVertexData->vertexBufferBinding;

    decl->addElement(0, 0, VET_FLOAT3, VES_POSITION);

    HardwareVertexBufferSharedPtr vbuf = 
        HardwareBufferManager::getSingleton().createVertexBuffer(
        decl->getVertexSize(0),
        m_pQuadVertexData->vertexCount,
        HardwareBuffer::HBU_STATIC_WRITE_ONLY);

    // Bind buffer
    bind->setBinding(0, vbuf);
	// Upload data
	float data[]={
		-1,1,-1,  // corner 1
		-1,-1,-1, // corner 2
		1,1,-1,   // corner 3
		1,-1,-1}; // corner 4
	vbuf->writeData(0, sizeof(data), data, true);

	// Set bounding

    //setBoundingBox(AxisAlignedBox(-10000,-10000,-10000,10000,10000,10000));
	//mRadius = 15000;
	//bIgnoreWorld = true;
}

void CMiniLight::createSphere(const float r, const int nRings, const int nSegments)
{
	CORE_DELETE(m_pSphereVertexData); 
	CORE_DELETE(m_pIndexData);

	m_pSphereVertexData = new VertexData();
	m_pIndexData = new IndexData();

	VertexData* vertexData = m_pSphereVertexData;
	IndexData* indexData = m_pIndexData;

	// define the vertex format
	VertexDeclaration* vertexDecl = vertexData->vertexDeclaration;
	size_t currOffset = 0;
	// only generate positions
	vertexDecl->addElement(0, currOffset, VET_FLOAT3, VES_POSITION);
	currOffset += VertexElement::getTypeSize(VET_FLOAT3);
	// allocate the vertex buffer
	vertexData->vertexCount = (nRings + 1) * (nSegments+1);
	HardwareVertexBufferSharedPtr vBuf = HardwareBufferManager::getSingleton().createVertexBuffer(vertexDecl->getVertexSize(0), vertexData->vertexCount, HardwareBuffer::HBU_STATIC_WRITE_ONLY, false);
	VertexBufferBinding* binding = vertexData->vertexBufferBinding;
	binding->setBinding(0, vBuf);
	float* pVertex = static_cast<float*>(vBuf->lock(HardwareBuffer::HBL_DISCARD));

	// allocate index buffer
	indexData->indexCount = 6 * nRings * (nSegments + 1);
	indexData->indexBuffer = HardwareBufferManager::getSingleton().createIndexBuffer(HardwareIndexBuffer::IT_16BIT, indexData->indexCount, HardwareBuffer::HBU_STATIC_WRITE_ONLY, false);
	HardwareIndexBufferSharedPtr iBuf = indexData->indexBuffer;
	unsigned short* pIndices = static_cast<unsigned short*>(iBuf->lock(HardwareBuffer::HBL_DISCARD));

	float fDeltaRingAngle = (Math::PI / nRings);
	float fDeltaSegAngle = (2 * Math::PI / nSegments);
	unsigned short wVerticeIndex = 0 ;

	// Generate the group of rings for the sphere
	for( int ring = 0; ring <= nRings; ring++ ) {
		float r0 = r * sinf (ring * fDeltaRingAngle);
		float y0 = r * cosf (ring * fDeltaRingAngle);

		// Generate the group of segments for the current ring
		for(int seg = 0; seg <= nSegments; seg++) {
			float x0 = r0 * sinf(seg * fDeltaSegAngle);
			float z0 = r0 * cosf(seg * fDeltaSegAngle);

			// Add one vertex to the strip which makes up the sphere
			*pVertex++ = x0;
			*pVertex++ = y0;
			*pVertex++ = z0;

			if (ring != nRings) 
			{
                // each vertex (except the last) has six indicies pointing to it
				*pIndices++ = wVerticeIndex + nSegments + 1;
				*pIndices++ = wVerticeIndex;               
				*pIndices++ = wVerticeIndex + nSegments;
				*pIndices++ = wVerticeIndex + nSegments + 1;
				*pIndices++ = wVerticeIndex + 1;
				*pIndices++ = wVerticeIndex;
				wVerticeIndex ++;
			}
		}; // end for seg
	} // end for ring

	// Unlock
	vBuf->unlock();
	iBuf->unlock();

	// Set bounding box and sphere
	//setBoundingBox( AxisAlignedBox( Vector3(-r, -r, -r), Vector3(r, r, r) ) );
	//mRadius = r;
	m_sphereRadius = r;
	//bIgnoreWorld = false;
}								 

Real CMiniLight::getBoundingRadius(void) const
{
	return mRadius;
}

Real CMiniLight::getSquaredViewDepth(const Camera* cam) const
{
	if(bIgnoreWorld)
	{
		return 0.0f;
	}
	else
	{
		Vector3 dist = cam->getDerivedPosition() - this->getParentNode()->_getDerivedPosition();                                                                     
		return dist.squaredLength();
	}
}

const MaterialPtr& CMiniLight::getMaterial(void) const
{
	return mGenerator->getMaterial(mPermutation);
}

#endif