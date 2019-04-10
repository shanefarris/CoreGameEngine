#if 0

#ifndef __TEXTFILE_H__
#define __TEXTFILE_H__
 
#include "Defines.h"
 
namespace IO
{
	class COgreTextResource : public Ogre::Resource
	{
		Ogre::String mString;
 
	protected:
 
		// must implement these from the Ogre::Resource interface
		void loadImpl();
		void unloadImpl();
		size_t calculateSize() const;
 
	public:
 
		COgreTextResource(ResourceManager* Creator, const String& Name, ResourceHandle Handle, const String& Group, bool isManual = false, 
			ManualResourceLoader* Loader = 0);
 
		virtual ~COgreTextResource();
 
		void setString(const Ogre::String &str);
		const Ogre::String &getString() const;
	};
 
	class TextFilePtr : public Ogre::SharedPtr<COgreTextResource> 
	{
	public:
		TextFilePtr() : Ogre::SharedPtr<COgreTextResource>() {}
		explicit TextFilePtr(COgreTextResource *rep) : Ogre::SharedPtr<COgreTextResource>(rep) {}
		TextFilePtr(const TextFilePtr &r) : Ogre::SharedPtr<COgreTextResource>(r) {} 
		TextFilePtr(const Ogre::ResourcePtr &r) : Ogre::SharedPtr<COgreTextResource>()
		{
			if( r.isNull() )
				return;
			// lock & copy other mutex pointer
			OGRE_LOCK_MUTEX(*r.OGRE_AUTO_MUTEX_NAME)
			OGRE_COPY_AUTO_SHARED_MUTEX(r.OGRE_AUTO_MUTEX_NAME)
			pRep = static_cast<COgreTextResource*>(r.getPointer());
			pUseCount = r.useCountPointer();
			useFreeMethod = r.freeMethod();
			if (pUseCount)
			{
				++(*pUseCount);
			}
		}
 
		/// Operator used to convert a ResourcePtr to a TextFilePtr
		TextFilePtr& operator=(const Ogre::ResourcePtr& r)
		{
			if(pRep == static_cast<COgreTextResource*>(r.getPointer()))
				return *this;
			release();
			if( r.isNull() )
				return *this; // resource ptr is null, so the call to release above has done all we need to do.
			// lock & copy other mutex pointer
			OGRE_LOCK_MUTEX(*r.OGRE_AUTO_MUTEX_NAME)
			OGRE_COPY_AUTO_SHARED_MUTEX(r.OGRE_AUTO_MUTEX_NAME)
			pRep = static_cast<COgreTextResource*>(r.getPointer());
			pUseCount = r.useCountPointer();
			useFreeMethod = r.freeMethod();
			if (pUseCount)
			{
				++(*pUseCount);
			}
			return *this;
		}
	};

	class COgreTextSerializer : public Ogre::Serializer
	{
	public:
		COgreTextSerializer();
		virtual ~COgreTextSerializer();
 
		void exportTextFile(const COgreTextResource *pText, const String &fileName);
		void importTextFile(Ogre::DataStreamPtr &stream, COgreTextResource *pDest);
	};
}
 
#endif

#endif