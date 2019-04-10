#ifndef __MOVABLETEXTOVERLAY_H__
#define __MOVABLETEXTOVERLAY_H__
 
#include "Defines.h"
#include "OgreOverlayManager.h"
#include "OgreOverlayContainer.h"
 
namespace Core
{
namespace OgreSpecific
{
	class MovableTextOverlayAttributes
	{
	public:
		MovableTextOverlayAttributes(const String& name, const Camera *cam, const String& fontName = "BlueHighway", const f32& charHeight = 16.0f, 
			const ColourValue& color = ColourValue::White, const String& materialName = "");
		~MovableTextOverlayAttributes();
	 
		void SetFontName(const String& fontName);
		void SetMaterialName(const String& materialName);
		void SetColor(const ColourValue& color);
		void SetCharacterHeight(u32 height);
	 
		const String&	GetName() const {return mName;}
		const Camera*	GetCamera() const {return mpCam;}
		const Font*		GetFont() const {return mpFont;}
		const String&	GetFontName() const {return mFontName;}
		const String&	GetMaterialName() const {return mMaterialName;}
		const ColourValue& GetColor() const {return mColor;}
		const f32		GetCharacterHeight() const {return mCharHeight;}
	 
		const String	mName;
		const Camera*	mpCam;
		Font*			mpFont;
		String			mFontName;
		String			mMaterialName;
		ColourValue		mColor;
		f32				mCharHeight;
	};
	 
	class MovableTextOverlay 
	{
	public:
		MovableTextOverlay(const char* name, const char* caption, const MovableObject *mov, MovableTextOverlayAttributes *attrs);
		virtual ~MovableTextOverlay();
	 
		void SetCaption(const char* caption);
		void SetUpdateFrequency(f32 updateFrequency) {mUpdateFrequency = updateFrequency;}
		void SetAttributes(MovableTextOverlayAttributes *attrs)
		{
			mAttrs = attrs;
			_updateOverlayAttrs();
		}
	 
		inline const String&	GetName() const {return mName;}
		inline const String&	GetCaption() const {return mCaption;}
		inline const f32		GetUpdateFrequency() const {return mUpdateFrequency;}
		inline const bool		IsOnScreen() const {return mOnScreen;}
		inline const bool		IsEnabled() const {return mEnabled;}
		inline const			MovableTextOverlayAttributes* getAttributes() const {return mAttrs;}
	 
		void Enable(bool Enable);
		void Update(const f32& elapsedTime);
	 
		// Needed for RectLayoutManager.
		inline f32 GetPixelsTop() {return OverlayManager::getSingleton().getViewportHeight() * (mpOvContainer->getTop());}
		inline f32 GetPixelsBottom() {return OverlayManager::getSingleton().getViewportHeight() * (mpOvContainer->getTop() + mpOvContainer->getHeight());}
		inline f32 GetPixelsLeft() {return OverlayManager::getSingleton().getViewportWidth() * mpOvContainer->getLeft();}
		inline f32 GetPixelsRight() {return OverlayManager::getSingleton().getViewportWidth() * (mpOvContainer->getLeft() + mpOvContainer->getWidth());}
		inline void SetPixelsTop(f32 px) {mpOvContainer->setTop(px / OverlayManager::getSingleton().getViewportHeight());}

	protected:
		void _computeTextWidth();
		void _updateOverlayAttrs();
		void _getMinMaxEdgesOfTopAABBIn2D(f32& MinX, f32& MinY, f32& MaxX, f32& MaxY);
		void _getScreenCoordinates(const Vector3& position, f32& x, f32& y);
	 
		Overlay* mpOv;
		OverlayContainer* mpOvContainer;
		OverlayElement* mpOvText;
	 
		const String mName;
		const MovableObject* mpMov;
		bool mEnabled;								// true if mpOvContainer is visible, false otherwise
		bool mNeedUpdate;							// true if mTextWidth needs to be recalculated
		f32 mTextWidth;								// Text width in pixels
		String mCaption;							// the Text
		bool mOnScreen;								// true if the upper vertices projections of the -MovableObject are on screen
		f32 mUpdateFrequency;						// the Update frequency in seconds mpOvContainer coordinates get updated each mUpdateFrequency seconds.
		MovableTextOverlayAttributes *mAttrs;		// the Font/Material/Color text attributes
	};

}
}
#endif //__MOVABLETEXTOVERLAY_H__

