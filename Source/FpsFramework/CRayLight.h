#if 0
#ifndef __CRAYLIGHT_H__
#define __CRAYLIGHT_H__

#include "Defines.h"
#include "CMiniLight.h"

namespace Core
{
namespace Effects
{
	class CRayLight: public CMiniLight, MovableObject::Listener
	{
	public:
		CRayLight(CMaterialGenerator *gen);
		~CRayLight();

		virtual void setAttenuation(float r, float c, float b, float a);
		virtual void setRayLength(float l );

		virtual void updateGeometry( const Vector3& camPos );

		// MovableObject callback
		virtual void objectAttached(MovableObject *);

		virtual Real getBoundingRadius(void) const;
		virtual Real getSquaredViewDepth(const Camera*) const;
		virtual const MaterialPtr& getMaterial(void) const;

	protected:
		SceneNode* m_pLightNode;
		float m_rayLength;

		float lightDistance(const Vector3 &pos );
		bool globalLight;
	};
}
}

#endif // __CRAYLIGHT_H__

#endif