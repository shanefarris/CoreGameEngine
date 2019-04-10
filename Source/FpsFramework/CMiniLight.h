#if 0
#ifndef __CMINI_LIGHT_H__
#define __CMINI_LIGHT_H__

#include "Defines.h"
#include "CMaterialGenerator.h"

// Renderable minilight. Do not create this directly, but use CDeferredShading::CreateMLight. XXX support other types of light other than point lights.
namespace Core
{
namespace Effects
{
	class CMiniLight: public SimpleRenderable
	{
	public:
		CMiniLight(CMaterialGenerator *gen);
		virtual ~CMiniLight();

		// Permutatation of light materials
		enum MaterialID
		{
			MI_QUAD			= 0x1, // Rendered as fullscreen quad
			MI_ATTENUATED	= 0x2, // Rendered attenuated
			MI_SPECULAR		= 0x4  // Specular component is calculated
		};

		virtual void setAttenuation(float r, float c, float b, float a);

		virtual void setDiffuseColour(const ColourValue &col);
		virtual void setDiffuseColour(float r=1.0f, float g=1.0f, float b=1.0f, float a=1.0f)
		{
			setDiffuseColour(ColourValue(r,g,b,a));
		}

		virtual void setSpecularColour(const ColourValue &col);
		virtual void setSpecularColour(float r=1.0f, float g=1.0f, float b=1.0f, float a=1.0f)
		{
			setSpecularColour(ColourValue(r,g,b,a));
		}

		virtual ColourValue getDiffuseColour();
		virtual ColourValue getSpecularColour();

		virtual void rebuildGeometry(float radius);		// Create geometry for this light.
		virtual void updateGeometry( const Vector3& camPos );

		void createSphere(const float r, const int nRings = 16, const int nSegments = 16);	// Create a sphere geometry.
		virtual void createRectangle2D();				// Create a rectangle.

		virtual Real getBoundingRadius(void) const;
		virtual Real getSquaredViewDepth(const Camera*) const;
		virtual const MaterialPtr& getMaterial(void) const;

	protected:
		bool bIgnoreWorld;				// Mode to ignore world orientation/position
		float mRadius;					// Bounding sphere radius
		CMaterialGenerator *mGenerator;	// Deferred shading system this minilight is part of
		size_t mPermutation;			// Material permutation

		VertexData* m_pQuadVertexData;
		VertexData* m_pSphereVertexData;
		IndexData* m_pIndexData;

		float m_sphereRadius;
	};
}
}

#endif // __CMINI_LIGHT_H__

#endif