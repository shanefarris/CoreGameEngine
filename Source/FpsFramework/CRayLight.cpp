#if 0
#include "CRayLight.h"
#include "CMaterialGenerator.h"
#include "CGameManager.h"

using namespace Core;
using namespace Core::Effects;

CRayLight::CRayLight(CMaterialGenerator *sys):
CMiniLight( sys )
{

	const MeshPtr mesh = MeshManager::getSingleton().load( "raylight.mesh", std::string("General") );
	SubMesh* submesh = mesh->getSubMesh( 0 );

	m_pLightNode = CGameManager::Instance()->GetSceneManager()->createSceneNode();
	m_pLightNode->setInheritOrientation(true);
	m_pLightNode->rotate( Vector3( 0.0f, 1.0f, 0.0f ), Radian(Math::PI) );
	m_pLightNode->setInheritScale(false);

	setListener( this );

	m_pSphereVertexData = submesh->vertexData;
	m_pIndexData  = submesh->indexData;
	m_rayLength  = 10.0f;

	setAttenuation(1.0f, 0.0f, 1.0f, 1.0f);

	globalLight = false;

}

CRayLight::~CRayLight()
{

	// Dont delete vetices there shared
	m_pSphereVertexData = nullptr;
	m_pIndexData = nullptr;

	if( m_pLightNode )
	{
		m_pLightNode->detachAllObjects();
		CGameManager::Instance()->GetSceneManager()->destroySceneNode(m_pLightNode->getName());
	}

}

void CRayLight::setAttenuation(float r, float c, float b, float a)
{

	setCustomParameter(3, Vector4(r, m_rayLength, b, a));

	m_sphereRadius = r*1.1f;

	if(r != 0.0f || c != 1.0f || b != 0.0f || a != 0.0f)
		mPermutation |= MI_ATTENUATED;
	else
		mPermutation &= ~MI_ATTENUATED;

	m_pLightNode->setScale( r*2.1f, r*2.1f, m_rayLength);
}

void CRayLight::setRayLength(float l )
{
	m_rayLength = l;
	
	Vector4 val = getCustomParameter(3);
	val.y = m_rayLength;

	m_pLightNode->setScale( val.x*2.1f, val.x*2.1f, m_rayLength*1.1f);

	setCustomParameter(3, val);
}

void CRayLight::updateGeometry( const Vector3& camPos )
{
	if( !mVisible )
		return;

	if(!m_pLightNode->getParentSceneNode())
	{
		mPermutation |= MI_QUAD;

		mRenderOp.vertexData = m_pQuadVertexData;
		mRenderOp.indexData = 0;
		mRenderOp.operationType = RenderOperation::OT_TRIANGLE_STRIP; 
		mRenderOp.useIndexes = false;

		setBoundingBox(AxisAlignedBox(-10000,-10000,-10000,10000,10000,10000));
		mRadius = 15000;
		bIgnoreWorld = true;
		globalLight = true;
	}
	else
	{
		if( lightDistance(camPos) > m_sphereRadius + 1.5f )
		{
			if(globalLight == true)
			{
				mPermutation &= ~MI_QUAD;

				mRenderOp.operationType = RenderOperation::OT_TRIANGLE_LIST;
				mRenderOp.indexData = m_pIndexData;
				mRenderOp.vertexData = m_pSphereVertexData;
				mRenderOp.useIndexes = true;

				setBoundingBox( AxisAlignedBox( Vector3(-m_sphereRadius, -m_sphereRadius, -m_sphereRadius), Vector3(m_sphereRadius, m_sphereRadius, m_sphereRadius) ) );
				mRadius = m_sphereRadius;
				bIgnoreWorld = false;
				globalLight = false;
			}
		}
		else
		{
			if(globalLight == false)
			{
				mPermutation |= MI_QUAD;

				mRenderOp.vertexData = m_pQuadVertexData;
				mRenderOp.indexData = 0;
				mRenderOp.operationType = RenderOperation::OT_TRIANGLE_STRIP; 
				mRenderOp.useIndexes = false;

				setBoundingBox(AxisAlignedBox(-10000,-10000,-10000,10000,10000,10000));
				mRadius = 15000;
				bIgnoreWorld = true;
				globalLight = true;
			}
		}
	}
}

float CRayLight::lightDistance(const Vector3 &pos )
{
	// Calculate light direction and distance
    Vector3 closestPoint;
	Vector3 lightPos = m_pLightNode->_getDerivedPosition();
	
	Vector3 rayVector = m_pLightNode->_getDerivedOrientation().zAxis() * m_rayLength*1.2f;
    lightPos += rayVector * -0.2f;
	Vector3 w = pos - lightPos;


	float proj = w.dotProduct(rayVector);
    if(proj <= 0 )	
   	{		
		closestPoint = lightPos;		
   	}	
   	else
   	{	
		float vsq = rayVector.dotProduct(rayVector);
   		if( proj >= vsq )
   		{
   			closestPoint = lightPos + rayVector;
   		}
   		else
   		{
   			closestPoint = lightPos + ((proj/vsq)*rayVector);
   		}
   	} 

	return Vector3(closestPoint - pos).length();
}

const MaterialPtr& CRayLight::getMaterial(void) const
{
	//return mGenerator->getMaterial(mPermutation);
	if( mPermutation & MI_QUAD )
		return MaterialManager::getSingleton().getByName("DeferredShading/CRayLight/Quad");
	else
		return MaterialManager::getSingleton().getByName("DeferredShading/CRayLight/Mini");
}


Real CRayLight::getBoundingRadius(void) const
{
	return mRadius;
}


Real CRayLight::getSquaredViewDepth(const Camera* cam) const
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

void CRayLight::objectAttached(MovableObject *obj)
{
	if( obj->getParentSceneNode() == m_pLightNode )
		return;

	SceneNode* parent = m_pLightNode->getParentSceneNode();
	if( parent )
		parent->removeChild( m_pLightNode );

	parent = obj->getParentSceneNode();
	
	parent->detachObject( this );
	parent->addChild( m_pLightNode );
	m_pLightNode->attachObject( this );
    
}


#endif