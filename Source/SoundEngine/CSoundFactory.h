#ifndef __CSOUNDFACTORY_H__
#define __CSOUNDFACTORY_H__

#include "Defines.h"
#include "SoundEnginePrereqs.h"
#include "OgreMovableObject.h"

namespace Sound 
{
	class CMemberFunctionSlot;

	// Factory object for creating sounds 
	class CSoundFactory : public Ogre::MovableObjectFactory
	{
	public:
		CSoundFactory();
		~CSoundFactory();

		static String FACTORY_TYPE_NAME;

		const String& getType() const;
		void destroyInstance(Ogre::MovableObject* obj);

		void _RemoveBufferRef(const String& bufferName);
		void _AddBufferRef(const String& bufferName, BufferRef buffer);

	protected:
		typedef std::map<std::string, BufferRef> BufferMap;
		BufferMap m_BufferMap;

		MovableObject* createInstanceImpl(const String& name, const NameValuePairList* params = 0);
	};
}

#endif // __CSOUNDFACTORY_H__
