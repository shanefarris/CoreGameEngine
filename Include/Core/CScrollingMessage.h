#ifndef __CSCROLLING_MESSAGE_H__
#define __CSCROLLING_MESSAGE_H__
 
#include "Defines.h"

namespace Ogre
{
	class Overlay;
	class OverlayElement;
	class OverlayContainer;
}

namespace Core
{
	class CGameManager;

namespace OgreSpecific
{
	class CORE_EXPORT CScrollingMessage
	{
	protected:
		OverlayContainer*	mPanel;
		Overlay*			mOverlay;
		OverlayElement*		mTextBox[5];
		f32					mTimeToGo;
		bool				mJustAdded;
		f32					PosX;			// Left side of X
		f32					PosY;			// Top of the panel
		f32					Spacing;
		Core::CGameManager* m_GameManager;
	 
	public:
		CScrollingMessage();
		void Init();
		void AddText(const String& text);
		void Update(const f32& elapsedTime);
	};
}
}

#endif // __CSCROLLING_MESSAGE_H__