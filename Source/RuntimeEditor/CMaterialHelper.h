#ifndef __CMATERIALHELPER__
#define __CMATERIALHELPER__

#include "Defines.h"

namespace Ogre
{
	class ResourceManager;
}

namespace Core
{
namespace Editor
{
	class CORE_EXPORT CMaterialHelper
	{
	public:
		static void UnloadResource(Ogre::ResourceManager* resMgr, const String& resourceName);
		static void LoadResource(Ogre::ResourceManager* resMgr, const String& resourceName, const String& resourceGroup);
		static void UnloadMaterials(const String& filename);
		static void UnloadVertexPrograms(const String& filename);
		static void UnloadFragmentPrograms(const String& filename);
		static void ReloadMaterial(const String& materialName, const String& groupName, const String& filename, bool parseMaterialScript = true);
		static bool DownloadMaterialFile(const String& materialName);
	};
}
}

#endif // __CMATERIALHELPER__