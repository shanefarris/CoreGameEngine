// http://www.ogre3d.org/tikiwiki/Resources+and+ResourceManagers
#if 0
#ifndef __COGRETEXTMANAGER_H__
#define __COGRETEXTMANAGER_H__
 
#include "COgreTextResource.h"
 
namespace IO
{
	class COgreTextManager : public Ogre::ResourceManager, public Ogre::Singleton<COgreTextManager>
	{
	protected:
 
		// must implement this from ResourceManager's interface
		Ogre::Resource *createImpl(const Ogre::String &name, Ogre::ResourceHandle handle, 
			const Ogre::String &group, bool isManual, Ogre::ManualResourceLoader *loader, 
			const Ogre::NameValuePairList *createParams);
 
	public:
 
		COgreTextManager();
		virtual ~COgreTextManager();
 
		virtual TextFilePtr load(const Ogre::String &name, const Ogre::String &group);
 
		static COgreTextManager &getSingleton();
		static COgreTextManager *getSingletonPtr();
	};
}
 
#endif  // __COGRETEXTMANAGER_H__

#endif