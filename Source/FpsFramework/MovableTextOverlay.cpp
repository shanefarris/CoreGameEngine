#include "MovableTextOverlay.h"

#include "OgreFontManager.h"
#include "OgreOverlayManager.h"
#include "OgreCamera.h"
#include "OgreStringConverter.h"
#include "OgreMaterialManager.h"

using namespace Core;
using namespace Core::OgreSpecific;
 
MovableTextOverlay::MovableTextOverlay(const char* name, const char* caption, const MovableObject *mov, MovableTextOverlayAttributes *attrs)
	: mpMov(mov),
	mpOv(nullptr),
	mpOvContainer(nullptr),
	mpOvText(nullptr),
	mAttrs(attrs),
	mName(name),
	mCaption(""),
	mUpdateFrequency(0.01f),
	mNeedUpdate(true),
	mOnScreen(false),
	mEnabled(false)
{
	if (String(name) == "")
		Exception(Exception::ERR_INVALIDPARAMS, "Trying to create MovableTextOverlay without name", "MovableTextOverlay::MovableTextOverlay");
 
    if (String(caption) == "")
        Exception(Exception::ERR_INVALIDPARAMS, "Trying to create MovableTextOverlay without caption", "MovableTextOverlay::MovableTextOverlay");
 
	if (mAttrs == nullptr)
		Exception(Exception::ERR_INVALIDPARAMS, "Trying to create MovableTextOverlay without Attributes", "MovableTextOverlay::MovableTextOverlay");

	// create an overlay that we can use for later
	mpOv = OverlayManager::getSingleton().getByName(mName +"_Ov");
	if(!mpOv) 
    { 
        mpOv = OverlayManager::getSingleton().create(mName +"_Ov");
    }
	mpOv->hide();

	if(OverlayManager::getSingleton().hasOverlayElement(mName + "_OvC"))
	{
		mpOvContainer = static_cast<OverlayContainer*>(OverlayManager::getSingleton().getOverlayElement(mName + "_OvC"));
	}
	else
	{
		mpOvContainer = static_cast<OverlayContainer*>(OverlayManager::getSingleton().createOverlayElement("Panel", mName +"_OvC"));
	}
	mpOvContainer->setDimensions(0.0, 0.0);
	mpOv->add2D(mpOvContainer);
 
	if(OverlayManager::getSingleton().hasOverlayElement(mName +"_OvTxt"))
	{
		mpOvText = OverlayManager::getSingleton().getOverlayElement(mName + "_OvTxt");
	}
	else
	{
		mpOvText = OverlayManager::getSingleton().createOverlayElement("TextArea", mName +"_OvTxt");
		mpOvContainer->addChild(mpOvText);
	}

	mpOvText->setMetricsMode(GMM_RELATIVE);
	mpOvText->setDimensions(1.0, 1.0);
	mpOvText->setMetricsMode(GMM_PIXELS);
	mpOvText->setPosition(0, 0);
 
	_updateOverlayAttrs();
 
	SetCaption(caption);
}
 
MovableTextOverlay::~MovableTextOverlay()
{
	// overlay cleanup -- Ogre would clean this up at app exit but if your app 
	// tends to create and delete these objects often it's a good idea to do it here.
 
	if(mpOv)
		mpOv->hide();
	//OverlayManager *overlayManager = OverlayManager::getSingletonPtr();
	//mpOvContainer->removeChild(mName+"_OvTxt");
	//mpOv->remove2D(mpOvContainer);
	//overlayManager->destroyOverlayElement(mpOvText);
	//overlayManager->destroyOverlayElement(mpOvContainer);
	//overlayManager->destroy(mpOv);

	CORE_DELETE(mAttrs);
}
 
void MovableTextOverlay::SetCaption(const char* caption)
{
    if (caption != mCaption)
    {
        mCaption = caption;
		mpOvText->setCaption(mCaption);
        mNeedUpdate = true;
    }
}
 
void MovableTextOverlay::_computeTextWidth()
{
	const Font *pFont = mAttrs->GetFont();
	mTextWidth = 0;
 
	for(String::iterator i = mCaption.begin(); i < mCaption.end();i++)
	{   
		if (*i == 0x0020)
			mTextWidth += pFont->getGlyphAspectRatio(0x0030);
		else
		{
			mTextWidth += pFont->getGlyphAspectRatio(*i);
		}
	}
 
	mTextWidth *= mAttrs->GetCharacterHeight();
}
 
void MovableTextOverlay::_getMinMaxEdgesOfTopAABBIn2D(f32& MinX, f32& MinY, f32& MaxX, f32& MaxY)
{
	const Camera* mpCam = mAttrs->GetCamera();
 
	MinX = 0;
	MinY = 0;
	MaxX = 0;
	MaxY = 0;
 
	f32 X[4];// the 2D dots of the AABB in screencoordinates
	f32 Y[4];
 
	if (!mpMov->isInScene())
	   return;
 
	const AxisAlignedBox &AABB = mpMov->getWorldBoundingBox(true);// the AABB of the target
	const Vector3 CornersOfTopAABB[4] = {	AABB.getCorner(AxisAlignedBox::FAR_LEFT_TOP),
										AABB.getCorner(AxisAlignedBox::FAR_RIGHT_TOP),
										AABB.getCorner(AxisAlignedBox::NEAR_LEFT_TOP),
										AABB.getCorner(AxisAlignedBox::NEAR_RIGHT_TOP)};
 
	Vector3 CameraPlainNormal = mpCam->getDerivedOrientation().zAxis();//The normal vector of the plaine.this points directly infront of the cam
 
	Plane CameraPlain = Plane(CameraPlainNormal,mpCam->getDerivedPosition());//the plaine that devides the space bevor and behin the cam
 
	for (int i = 0; i < 4; i++)
	{
	  X[i] = 0;
	  Y[i] = 0;
 
	  _getScreenCoordinates(CornersOfTopAABB[i],X[i],Y[i]);// transfor into 2d dots
 
 
	  if (CameraPlain.getSide(CornersOfTopAABB[i]) == Plane::NEGATIVE_SIDE)
	  {
 
		 if (i == 0)// accept the first Set of values, no matter how bad it might be.
		 {
			MinX = X[i];
			MinY = Y[i];
			MaxX = X[i];
			MaxY = Y[i];
		 }
		 else// now compare if you get "better" values
		 {
			if (MinX > X[i])// get the x minimum
			{
			   MinX = X[i];
			}
			if (MinY > Y[i])// get the y minimum
			{
			   MinY = Y[i];
			}
			if (MaxX < X[i])// get the x maximum
			{
			   MaxX = X[i];
			}
			if (MaxY < Y[i])// get the y maximum
			{
			   MaxY = Y[i];
			}
		 }
	  }
	  else
	  {
		MinX = 0;
		MinY = 0;
		MaxX = 0;
		MaxY = 0;
		break;
	  }
	}
} 
 
void MovableTextOverlay::_getScreenCoordinates(const Vector3& position, f32& x, f32& y)
{
	const Camera* mpCam = mAttrs->GetCamera();
	Vector3 hcsPosition = mpCam->getProjectionMatrix() * (mpCam->getViewMatrix() * position);
 
	x = 1.0f - ((hcsPosition.x * 0.5f) + 0.5f);// 0 <= x <= 1 // left := 0,right := 1
	y = ((hcsPosition.y * 0.5f) + 0.5f);// 0 <= y <= 1 // bottom := 0,top := 1
}
 
void MovableTextOverlay::Enable(bool Enable)
{
	if (mEnabled == Enable)
		return;
 
	mEnabled = Enable;
	if (mEnabled)
		mpOv->show();
	else
		mpOv->hide();
}
 
void MovableTextOverlay::Update(const f32& elapsedTime)
{
	static f32 timeTillUpdate = 0;
 
	timeTillUpdate -= elapsedTime;
	if (timeTillUpdate > 0)
		return;
	timeTillUpdate = mUpdateFrequency;
 
	f32 min_x, max_x, min_y, max_y;
	_getMinMaxEdgesOfTopAABBIn2D(min_x, min_y, max_x, max_y);
 
	if ((min_x>0.0) && (max_x<1.0) && (min_y>0.0) && (max_y<1.0))
	   mOnScreen = true;
	else
	   mOnScreen = false;
 
	if (mNeedUpdate)
	{
		_computeTextWidth();
		mNeedUpdate = false;
	}
 
	f32 relTextWidth = mTextWidth / OverlayManager::getSingleton().getViewportWidth();
	f32 relTextHeight = mAttrs->GetCharacterHeight() / OverlayManager::getSingleton().getViewportHeight();
 
	mpOvContainer->setPosition(1-(min_x + max_x + relTextWidth)/2, 1-max_y);
	mpOvContainer->setDimensions(relTextWidth, relTextHeight);
}
 
void MovableTextOverlay::_updateOverlayAttrs()
{
	const String &newMatName = mAttrs->GetMaterialName();
	const String &oldMatName = mpOvContainer->getMaterialName();
	if (oldMatName != newMatName)
	{
		if (oldMatName.length())
			mpOvContainer->getMaterial()->unload();
 
		if (newMatName.length())
			mpOvContainer->setMaterialName(newMatName);
 
	}
 
	mpOvText->setColour(mAttrs->GetColor());
 
	mpOvText->setParameter("font_name", mAttrs->GetFontName());
	mpOvText->setParameter("char_height", StringConverter::toString(mAttrs->GetCharacterHeight()));
	mpOvText->setParameter("horz_align", "left");
	mpOvText->setParameter("vert_align", "top");
}
 
 
MovableTextOverlayAttributes::MovableTextOverlayAttributes(const String & name, const Camera *cam, const String & fontName, const f32& charHeight, 
	const ColourValue & color, const String & materialName)
	: mpCam(cam),
	mpFont(nullptr),
	mName(name),
	mFontName(""),
	mMaterialName(""),
	mCharHeight(charHeight),
	mColor(ColourValue::ZERO)
{
	if (fontName.length() == 0)
        Exception(Exception::ERR_INVALIDPARAMS, "Invalid font name", "MovableTextOverlayAttributes::MovableTextOverlayAttributes");
 
	SetFontName(fontName);
	SetMaterialName(materialName);
	SetColor(color);
}

MovableTextOverlayAttributes::~MovableTextOverlayAttributes()
{
	SetFontName("");
	SetMaterialName("");
}
 
void MovableTextOverlayAttributes::SetFontName(const String & fontName)
{
    if (mFontName != fontName || !mpFont)
    {
		if (mpFont)
		{
			mpFont->unload();
			mpFont = nullptr;
		}
 
		mFontName = fontName;
		if (mFontName.length())
		{
			mpFont = dynamic_cast<Font*>(FontManager::getSingleton().getByName(mFontName).getPointer());
			if (!mpFont)
			{
				Exception(Exception::ERR_ITEM_NOT_FOUND, "Could not find font " + fontName, "MovableTextOverlay::SetFontName");
			}
			else
			{
				mpFont->load();
			}
		}
    }
}
 
void MovableTextOverlayAttributes::SetMaterialName(const String & materialName)
{
	if (mMaterialName != materialName)
	{
		if (mMaterialName.length())
			MaterialManager::getSingletonPtr()->getByName(mMaterialName).getPointer()->unload();
 
		mMaterialName = materialName;
		if (mMaterialName.length())
		{
			Material *mpMaterial = dynamic_cast<Material*>(MaterialManager::getSingletonPtr()->getByName(mMaterialName).getPointer());
			if (!mpMaterial)
				Exception(Exception::ERR_ITEM_NOT_FOUND, "Could not find font " + materialName, "MovableTextOverlay::SetMaterialName");
			else
				mpMaterial->load();
		}
	}
}
 
void MovableTextOverlayAttributes::SetColor(const ColourValue & color)
{
        mColor = color;
}
 
void MovableTextOverlayAttributes::SetCharacterHeight(u32 height)
{
        mCharHeight = (f32)height;
}