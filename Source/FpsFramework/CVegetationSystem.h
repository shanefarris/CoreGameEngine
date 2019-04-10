#ifndef __NATURE_VEGETAIONSYSTEM_H__
#define __NATURE_VEGETAIONSYSTEM_H__

#include "Defines.h"
#include "IEnvironment.h"

namespace Forests
{
	class PagedGeometry;
	class PageLoader;
}

namespace Core
{
	struct GEO_SET;

	namespace Physics
	{
		class IPhysicsStrategy;
	}

	namespace Nature
	{
		struct TREE_SET;

		class CVegetationSystem : public IEnvironment
		{
		public:
			CVegetationSystem(CTerrainSystem* Terrain);
			~CVegetationSystem();

			void Initialise();
			void Shutdown();
			void Pause();
			void Resume();
			void Update(const f32& elapsedTime);

			void AddPagedGeometry(Core::GEO_SET* TreeSet, Core::Physics::IPhysicsStrategy* PhysicsStrategy = nullptr);

		private:
			// Paged Geometry
			Map<Forests::PagedGeometry*, Forests::PageLoader*> m_Geometry;
			CTerrainSystem* m_TerrainSystem;
		};
	}
}

#endif // __NATURE_VEGETAIONSYSTEM_H__
