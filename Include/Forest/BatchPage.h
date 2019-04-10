#ifndef __BatchPage_H__
#define __BatchPage_H__

#include "PagedGeometry.h"

namespace Forests 
{
	class BatchedGeometry;

	class CORE_EXPORT BatchPage: public GeometryPage
	{
	public:
		inline BatchPage() { geom = nullptr; }
		virtual void init(PagedGeometry *geom, const Any &data);
		~BatchPage();
	
		void addEntity(Entity *ent, const Vector3 &position, const Quaternion &rotation, const Vector3 &scale, const ColourValue &color);
		void build();
		void removeEntities();

		void setVisible(bool visible);
		void setFade(bool enabled, f32 visibleDist, f32 invisibleDist);

		void addEntityToBoundingBox() {}
		void clearBoundingBox() {}
		const AxisAlignedBox &getBoundingBox();

	protected :
		virtual void _updateShaders();

		bool fadeEnabled, shadersSupported;
		f32 visibleDist, invisibleDist;
		std::vector<MaterialPtr> unfadedMaterials;

		SceneManager *sceneMgr;
		BatchedGeometry *batch;

		static unsigned long refCount;
		static unsigned long GUID;
		size_t mLODLevel;
		PagedGeometry *geom;

	private:
		static inline String getUniqueID(const String &prefix);

	};

}

#endif

/**
\brief The BatchPage class renders entities as StaticGeometry.

This is one of the geometry page types included in the StaticGeometry engine. These
page types should be added to a PagedGeometry object with PagedGeometry::addDetailLevel()
so the PagedGeometry will know how you want your geometry displayed.

To use this page type, use (the last parameter is optional):
\code
PagedGeometry::addDetailLevel<BatchPage>(farRange, transitionLength, Any(LODLevel));
\endcode

This page type uses batched geometry (StaticGeometry) to represent the entities.
Batched geometry is generally much faster than plain entities, since video card state
changes and transform calculations can be minimized. Batched geometry can be anywhere
from 2 to 20 times faster than plain entities.

"LODLevel" can be used to specify a certain LOD level to use from the added entities.
This would be useful, for example, if you wanted to add high-res batched trees near the camera,
and low-res batched trees farther away.
*/