#if 0

#include "COgreTextManager.h"
 
using namespace IO;

template<> COgreTextManager *Ogre::Singleton<COgreTextManager>::ms_Singleton = 0;
 
COgreTextManager *COgreTextManager::getSingletonPtr()
{
    return ms_Singleton;
}
 
COgreTextManager &COgreTextManager::getSingleton()
{  
    assert(ms_Singleton);  
    return(*ms_Singleton);
}
 
COgreTextManager::COgreTextManager()
{
    mResourceType = "TextFile";
 
    // low, because it will likely reference other resources
    mLoadOrder = 30.0f;
 
    // this is how we register the ResourceManager with OGRE
    Ogre::ResourceGroupManager::getSingleton()._registerResourceManager(mResourceType, this);
}
 
COgreTextManager::~COgreTextManager()
{
    // and this is how we unregister it
    Ogre::ResourceGroupManager::getSingleton()._unregisterResourceManager(mResourceType);
}
 
TextFilePtr COgreTextManager::load(const Ogre::String &name, const Ogre::String &group)
{
    TextFilePtr textf = getByName(name);
 
    if (textf.isNull())
        textf = create(name, group);
 
    textf->load();
    return textf;
}
 
Ogre::Resource *COgreTextManager::createImpl(const Ogre::String &name, Ogre::ResourceHandle handle, 
                                            const Ogre::String &group, bool isManual, Ogre::ManualResourceLoader *loader, 
                                            const Ogre::NameValuePairList *createParams)
{
    return new COgreTextResource(this, name, handle, group, isManual, loader);
}

#endif