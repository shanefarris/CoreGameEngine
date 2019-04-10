#ifndef __CENVIRONMENTOBSERVER_H__
#define __CENVIRONMENTOBSERVER_H__

#include "Defines.h"

namespace Core
{
	class CPlayer;

	namespace Physics
	{
		class CVolumeObject;
	}

	class CEnvironmentObserver
	{
	public:
		CEnvironmentObserver(const f32& Scale, CPlayer* Player);
		~CEnvironmentObserver();

		void SetScaleSize(const f32& Scale);
		void SetVolumeVisible(bool Visible) { }

		void Update();

	private:
		CPlayer*	m_Player;
		f32			ScaleSize;
		u32			LoopCount;
		
		Physics::CVolumeObject* m_Volume;

	};

}


#endif // __CENVIRONMENTOBSERVER_H__