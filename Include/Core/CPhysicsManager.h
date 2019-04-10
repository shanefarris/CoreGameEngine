#ifndef __CPHYSICSMANAGER_H__
#define __CPHYSICSMANAGER_H__

#include "Defines.h"
#include "PhysicsStructures.h"

namespace Core
{
	namespace Plugin
	{
		class IPhysicsStrategyFactory;
	}

namespace Physics
{
	class CPhysicsProfile;
	class IPhysicsStrategy;

	typedef Map<String, CPhysicsProfile*> PhysicsProfileList;

	class CORE_EXPORT CPhysicsManager
	{
	private:
		CPhysicsManager();

		static CPhysicsManager*	PhysicsManager;
		IPhysicsStrategy*		m_CurrStrategy;
		PhysicsProfileList		m_PhysicsProfiles;

		Vector<Plugin::IPhysicsStrategyFactory*> m_Strategies;

	public:
		~CPhysicsManager();

		static CPhysicsManager* Instance();

		// Strategy
		IPhysicsStrategy* CreateStrategy(const char* Label);
		IPhysicsStrategy* GetStrategy() const;
		void			  DeleteStrategy();

		// Profiles
		void			 AddPhysicsProfile(const char* ProfileName, CPhysicsProfile* Profile);
		inline void		 GetPhysicsProfileList(PhysicsProfileList& ProfileList) const;
		CPhysicsProfile* GetPhysicsProfile(const char* ProfileName) const;

		void Update(const f32& elapsedTime) const;

		// Built-in profiles
		static const char* DEFAULT_LIGHT_CUBE;
		static const char* DEFAULT_MEDIUM_CUBE;
		static const char* DEFAULT_HEAVY_CUBE;
		static const char* DEFAULT_LIGHT_SPHERE;
		static const char* DEFAULT_MEDIUM_SPHERE;
		static const char* DEFAULT_HEAVY_SPHERE;
	};
}
}

#endif // __CPHYSICSMANAGER_H__
