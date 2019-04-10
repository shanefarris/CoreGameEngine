#ifndef __OgreBulletCollisionsDebugContact_H__
#define __OgreBulletCollisionsDebugContact_H__

#include "OgreBulletCollisionsPreRequisites.h"
#include "Debug/OgreBulletCollisionsDebugLines.h"

namespace OgreBulletCollisions 
{
    //------------------------------------------------------------------------------------------------
    class CORE_EXPORT DebugContact
    {
    public:
        DebugContact(const Ogre::String &name, CollisionsWorld *world);
         ~DebugContact();

         bool isEnabled () const;
         void setEnabled (bool enable);

         void update(const Ogre::Vector3 &normal, const Ogre::Vector3 &pt, const Ogre::Real depth);

    private:
        DebugNormal         *_normal;
        DebugContactText    *_text;
        Ogre::Entity        *_point;
        bool                _enabled;
        Ogre::String        _name;
        Ogre::SceneNode     *_node;
        Ogre::SceneNode     *_point_node;
        CollisionsWorld               *_world;
    };

    //------------------------------------------------------------------------------------------------
    class DebugNormal : public DebugLines
    {
    public:
        DebugNormal() : DebugLines(){};
        ~DebugNormal(){};

        void update (const Ogre::Vector3 &normal, const Ogre::Vector3 &pt, const Ogre::Real depth);
    };

    //------------------------------------------------------------------------------------------------
    class DebugContactText : public Ogre::MovableObject, public Ogre::Renderable
    {
    public:
        enum HorizontalAlignment    {H_LEFT, H_CENTER};
        enum VerticalAlignment      {V_BELOW, V_ABOVE};
        /******************************** public methods ******************************/
    public:
        DebugContactText(const Ogre::String &name, 
                         Ogre::SceneNode *node,
                         const Ogre::String &caption = "", 
                         const Ogre::String &fontName = "BlueHighway", 
                         int charHeight = 32, 
                         const Ogre::ColourValue &color = Ogre::ColourValue::White);


         ~DebugContactText();

#if (OGRE_VERSION >=  ((1 << 16) | (5 << 8) | 0)) // must have at least shoggoth (1.5.0)
		void visitRenderables(Renderable::Visitor* visitor, bool debugRenderables);
#endif
        // Set settings
        void    setPosition(const Ogre::Vector3 &pos);

        void    setFontName(const Ogre::String &fontName);
        void    setCaption(const Ogre::String &caption);
        void    setColor(const Ogre::ColourValue &color);
        void    setCharacterHeight(unsigned int height);
        void    setSpaceWidth(unsigned int width);
        void    setTextAlignment(const HorizontalAlignment& horizontalAlignment, 
                                const VerticalAlignment& verticalAlignment);
        void    setAdditionalHeight( Ogre::Real height );
        void    showOnTop(bool show=true);

        // Get settings
        const   Ogre::String          &getFontName() const {return mFontName;}
        const   Ogre::String          &getCaption() const {return mCaption;}
        const   Ogre::ColourValue     &getColor() const {return mColor;}

        unsigned int    getCharacterHeight() const {return mCharHeight;}
        unsigned int    getSpaceWidth() const {return mSpaceWidth;}
        Ogre::Real                  getAdditionalHeight() const {return mAdditionalHeight;}
        bool                    getShowOnTop() const {return mOnTop;}
        Ogre::AxisAlignedBox	        GetAABB(void) { return mAABB; }

        /******************************** protected methods and overload **************/
    protected:

        // from OgreBulletCollisionsDebugContact, create the object
        void	_setupGeometry();
        void	_updateColors();

        // from MovableObject
        void                            getWorldTransforms(Ogre::Matrix4 *xform) const;
        Ogre::Real                      getBoundingRadius(void) const {return mRadius;};
        Ogre::Real                      getSquaredViewDepth(const Ogre::Camera *cam) const {return 0;};
        const   Ogre::Quaternion        &getWorldOrientation(void) const;
        const   Ogre::Vector3           &getWorldPosition(void) const;
        const   Ogre::AxisAlignedBox    &getBoundingBox(void) const {return mAABB;};
        const   Ogre::String            &getName(void) const {return mName;};
        const   Ogre::String            &getMovableType(void) const {static Ogre::String movType = "MovableText"; return movType;};

        void                            _notifyCurrentCamera(Ogre::Camera *cam);
        void                            _updateRenderQueue(Ogre::RenderQueue* queue);

        // from renderable
        void                            getRenderOperation(Ogre::RenderOperation &op);
        const   Ogre::MaterialPtr       &getMaterial(void) const {assert(!mpMaterial.isNull());return mpMaterial;};
        const   Ogre::LightList         &getLights(void) const {return mLList;};

        /******************************** OgreBulletCollisionsDebugContact data ****************************/
  

    protected:
        Ogre::String			mFontName;
        Ogre::String			mType;
        Ogre::String			mName;
        Ogre::String			mCaption;
        HorizontalAlignment	    mHorizontalAlignment;
        VerticalAlignment	    mVerticalAlignment;

        Ogre::ColourValue		mColor;
        Ogre::RenderOperation	mRenderOp;
        Ogre::AxisAlignedBox	mAABB;
        Ogre::LightList		    mLList;

        unsigned int			mCharHeight;
        unsigned int			mSpaceWidth;

        bool			        mNeedUpdate;
        bool			        mUpdateColors;
        bool			        mOnTop;

        Ogre::Real			    mTimeUntilNextToggle;
        Ogre::Real			    mRadius;
        Ogre::Real              mAdditionalHeight;

        Ogre::Camera			*mpCam;
        Ogre::RenderWindow	    *mpWin;
        Ogre::Font			    *mpFont;
        Ogre::MaterialPtr		mpMaterial;
        Ogre::MaterialPtr		mpBackgroundMaterial;

        Ogre::SceneNode         *mNode;
    };
}

#endif //__OgreBulletCollisionsDebugContact_H__

