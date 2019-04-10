#if 0

#include "COgreTextResource.h"

using namespace IO;

COgreTextResource::COgreTextResource(ResourceManager* Creator, const String& Name, ResourceHandle Handle, const String& Group, 
	bool isManual, ManualResourceLoader* Loader) :
Ogre::Resource(Creator, Name, Handle, Group, isManual, Loader)
{
    /* If you were storing a pointer to an object, then you would set that pointer to NULL here.
    */
 
    /* For consistency with StringInterface, but we don't add any parameters here
    That's because the Resource implementation of StringInterface is to
    list all the options that need to be set before loading, of which 
    we have none as such. Full details can be set through scripts.
    */ 
    createParamDictionary("TextFile");
}
 
COgreTextResource::~COgreTextResource()
{
    unload();
}
 
// farm out to TextFileSerializer
void COgreTextResource::loadImpl()
{
    TextFileSerializer serializer;
    Ogre::DataStreamPtr stream = Ogre::ResourceGroupManager::getSingleton().openResource(mName, mGroup, true, this);
    serializer.importTextFile(stream, this);
}
 
void COgreTextResource::unloadImpl()
{
    /* If you were storing a pointer to an object, then you would check the pointer here,
    and if it is not NULL, you would destruct the object and set its pointer to NULL again.
    */
 
    mString.clear();
}
 
size_t COgreTextResource::calculateSize() const
{
    return mString.length();
}
 
void COgreTextResource::setString(const Ogre::String &str)
{
    mString = str;
}
 
const Ogre::String &COgreTextResource::getString() const
{
    return mString;
}

COgreTextSerializer::COgreTextSerializer()
{
}
 
COgreTextSerializer::~COgreTextSerializer()
{
}
 
void COgreTextSerializer::exportTextFile(const COgreTextResource *pText, const Ogre::String &fileName)
{
    std::ofstream outFile;
    outFile.open(fileName.c_str(), std::ios::out);
    outFile << pText->getString();
    outFile.close();
}
 
void COgreTextSerializer::importTextFile(Ogre::DataStreamPtr &stream, COgreTextResource *pDest)
{
    pDest->setString(stream->getAsString());
}

#endif