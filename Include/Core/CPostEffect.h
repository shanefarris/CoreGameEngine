#ifndef __CPOSEEFFECT_H__
#define __CPOSEEFFECT_H__

#include "Defines.h"

namespace Core
{
	namespace Effects
	{
		class CORE_EXPORT CPostEffect
		{
		public:
			CPostEffect(const String& compName);

			virtual void RegisterPostEffect() = 0;
			void SetEnabled(bool flag);
			const char* GetName() { return mCompName.c_str(); }

		protected:
			Camera*		m_Camera;
			Viewport*	m_Viewport;
			String		mCompName;
			bool		mEnabled;
		};
	}
}

#endif // __CPOSEEFFECT_H__
