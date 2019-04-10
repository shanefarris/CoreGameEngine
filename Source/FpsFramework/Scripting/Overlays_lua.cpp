#ifdef COMPILE_SCRIPT
#ifdef COMPILE_OVERLAYS
/*
** Lua binding: Overlays
** Generated automatically by tolua++-1.0.92 on 08/22/11 16:46:06.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"


#include "Overlays/BigTitleWidget.h"
#include "Overlays/ButtonWidget.h"
#include "Overlays/EntryWidget.h"
#include "Overlays/ImageWidget.h"
#include "Overlays/LabelWidget.h"
#include "Overlays/MouseCursor.h"
#include "Overlays/TextEntryWidget.h"
#include "Overlays/Notifications.h"
#include "Overlays/MiniMap.h"
#include "Overlays/Compass.h"
#include "Overlays/FileBrowserWidget.h"
#include "Overlays/YesNoBoxWidget.h"
#include "Overlays/Fader.h"

using namespace Core;
using namespace Core::Overlays;
/* Exported function */
TOLUA_API int  tolua_Overlays_open (lua_State* tolua_S);


/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_Core__Overlays__ImageWidget (lua_State* tolua_S)
{
 Core::Overlays::ImageWidget* self = (Core::Overlays::ImageWidget*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Core__Overlays__YesNoBoxWidget (lua_State* tolua_S)
{
 Core::Overlays::YesNoBoxWidget* self = (Core::Overlays::YesNoBoxWidget*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Core__Overlays__EntryWidget (lua_State* tolua_S)
{
 Core::Overlays::EntryWidget* self = (Core::Overlays::EntryWidget*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Core__Overlays__TextEntryWidget (lua_State* tolua_S)
{
 Core::Overlays::TextEntryWidget* self = (Core::Overlays::TextEntryWidget*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Core__Overlays__FileBrowserWidget (lua_State* tolua_S)
{
 Core::Overlays::FileBrowserWidget* self = (Core::Overlays::FileBrowserWidget*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_FileScanner (lua_State* tolua_S)
{
 FileScanner* self = (FileScanner*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Core__Overlays__Fader (lua_State* tolua_S)
{
 Core::Overlays::Fader* self = (Core::Overlays::Fader*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Core__Overlays__MiniMap (lua_State* tolua_S)
{
 Core::Overlays::MiniMap* self = (Core::Overlays::MiniMap*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Core__Overlays__ButtonWidget (lua_State* tolua_S)
{
 Core::Overlays::ButtonWidget* self = (Core::Overlays::ButtonWidget*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Core__Overlays__LabelWidget (lua_State* tolua_S)
{
 Core::Overlays::LabelWidget* self = (Core::Overlays::LabelWidget*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Core__Overlays__BigTitleWidget (lua_State* tolua_S)
{
 Core::Overlays::BigTitleWidget* self = (Core::Overlays::BigTitleWidget*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Core__Overlays__Compass (lua_State* tolua_S)
{
 Core::Overlays::Compass* self = (Core::Overlays::Compass*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Core__Overlays__Notifications (lua_State* tolua_S)
{
 Core::Overlays::Notifications* self = (Core::Overlays::Notifications*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"Core::Overlays::ImageWidget");
 tolua_usertype(tolua_S,"ColourValue");
 tolua_usertype(tolua_S,"OverlayElement");
 tolua_usertype(tolua_S,"Core::Overlays::EntryWidget");
 tolua_usertype(tolua_S,"FileScanner");
 tolua_usertype(tolua_S,"Core::Overlays::Fader");
 tolua_usertype(tolua_S,"Core::Overlays::ButtonWidget");
 tolua_usertype(tolua_S,"Core::Overlays::LabelWidget");
 tolua_usertype(tolua_S,"Core::Overlays::YesNoBoxWidget");
 tolua_usertype(tolua_S,"Core::Overlays::Compass");
 tolua_usertype(tolua_S,"Core::Overlays::TextEntryWidget");
 tolua_usertype(tolua_S,"SceneNode");
 tolua_usertype(tolua_S,"Ogre::Overlay");
 tolua_usertype(tolua_S,"Real");
 tolua_usertype(tolua_S,"Core::Overlays::FileBrowserWidget");
 tolua_usertype(tolua_S,"String");
 tolua_usertype(tolua_S,"Core::Overlays::MiniMap");
 tolua_usertype(tolua_S,"Ogre::TextureUnitState");
 tolua_usertype(tolua_S,"Core::Overlays::MouseCursor");
 tolua_usertype(tolua_S,"Core::Overlays::BigTitleWidget");
 tolua_usertype(tolua_S,"Core::Overlays::FaderCallback");
 tolua_usertype(tolua_S,"Core::Overlays::Notifications");
}

/* method: new of class  Core::Overlays::BigTitleWidget */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_BigTitleWidget_new00
static int tolua_Overlays_Core_Overlays_BigTitleWidget_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Core::Overlays::BigTitleWidget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Core::Overlays::BigTitleWidget* tolua_ret = (Core::Overlays::BigTitleWidget*)  Mtolua_new((Core::Overlays::BigTitleWidget)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::Overlays::BigTitleWidget");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Core::Overlays::BigTitleWidget */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_BigTitleWidget_new00_local
static int tolua_Overlays_Core_Overlays_BigTitleWidget_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Core::Overlays::BigTitleWidget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Core::Overlays::BigTitleWidget* tolua_ret = (Core::Overlays::BigTitleWidget*)  Mtolua_new((Core::Overlays::BigTitleWidget)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::Overlays::BigTitleWidget");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: init of class  Core::Overlays::BigTitleWidget */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_BigTitleWidget_init00
static int tolua_Overlays_Core_Overlays_BigTitleWidget_init00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::BigTitleWidget",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isstring(tolua_S,7,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,8,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::BigTitleWidget* self = (Core::Overlays::BigTitleWidget*)  tolua_tousertype(tolua_S,1,0);
  const char* uniqueName = ((const char*)  tolua_tostring(tolua_S,2,0));
  float parentLeft = ((float)  tolua_tonumber(tolua_S,3,0));
  float parentTop = ((float)  tolua_tonumber(tolua_S,4,0));
  float parentRight = ((float)  tolua_tonumber(tolua_S,5,0));
  float parentBottom = ((float)  tolua_tonumber(tolua_S,6,0));
  const char* text = ((const char*)  tolua_tostring(tolua_S,7,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'init'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->init(uniqueName,parentLeft,parentTop,parentRight,parentBottom,text);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'init'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: free of class  Core::Overlays::BigTitleWidget */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_BigTitleWidget_free00
static int tolua_Overlays_Core_Overlays_BigTitleWidget_free00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::BigTitleWidget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::BigTitleWidget* self = (Core::Overlays::BigTitleWidget*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'free'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->free();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'free'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: defineParentBounds of class  Core::Overlays::BigTitleWidget */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_BigTitleWidget_defineParentBounds00
static int tolua_Overlays_Core_Overlays_BigTitleWidget_defineParentBounds00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::BigTitleWidget",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::BigTitleWidget* self = (Core::Overlays::BigTitleWidget*)  tolua_tousertype(tolua_S,1,0);
  float left = ((float)  tolua_tonumber(tolua_S,2,0));
  float top = ((float)  tolua_tonumber(tolua_S,3,0));
  float right = ((float)  tolua_tonumber(tolua_S,4,0));
  float bottom = ((float)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'defineParentBounds'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->defineParentBounds(left,top,right,bottom);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'defineParentBounds'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getElement of class  Core::Overlays::BigTitleWidget */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_BigTitleWidget_getElement00
static int tolua_Overlays_Core_Overlays_BigTitleWidget_getElement00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::BigTitleWidget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::BigTitleWidget* self = (Core::Overlays::BigTitleWidget*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getElement'", NULL);
#endif
  {
   OverlayElement* tolua_ret = (OverlayElement*)  self->getElement();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"OverlayElement");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getElement'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: show of class  Core::Overlays::BigTitleWidget */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_BigTitleWidget_show00
static int tolua_Overlays_Core_Overlays_BigTitleWidget_show00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::BigTitleWidget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::BigTitleWidget* self = (Core::Overlays::BigTitleWidget*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'show'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->show();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'show'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: hide of class  Core::Overlays::BigTitleWidget */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_BigTitleWidget_hide00
static int tolua_Overlays_Core_Overlays_BigTitleWidget_hide00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::BigTitleWidget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::BigTitleWidget* self = (Core::Overlays::BigTitleWidget*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'hide'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->hide();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'hide'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: moveWidget of class  Core::Overlays::BigTitleWidget */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_BigTitleWidget_moveWidget00
static int tolua_Overlays_Core_Overlays_BigTitleWidget_moveWidget00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::BigTitleWidget",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::BigTitleWidget* self = (Core::Overlays::BigTitleWidget*)  tolua_tousertype(tolua_S,1,0);
  float pixelX = ((float)  tolua_tonumber(tolua_S,2,0));
  float pixelY = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'moveWidget'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->moveWidget(pixelX,pixelY);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'moveWidget'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setText of class  Core::Overlays::BigTitleWidget */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_BigTitleWidget_setText00
static int tolua_Overlays_Core_Overlays_BigTitleWidget_setText00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::BigTitleWidget",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::BigTitleWidget* self = (Core::Overlays::BigTitleWidget*)  tolua_tousertype(tolua_S,1,0);
  const char* text = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setText'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->setText(text);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setText'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Core::Overlays::ButtonWidget */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_ButtonWidget_new00
static int tolua_Overlays_Core_Overlays_ButtonWidget_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Core::Overlays::ButtonWidget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Core::Overlays::ButtonWidget* tolua_ret = (Core::Overlays::ButtonWidget*)  Mtolua_new((Core::Overlays::ButtonWidget)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::Overlays::ButtonWidget");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Core::Overlays::ButtonWidget */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_ButtonWidget_new00_local
static int tolua_Overlays_Core_Overlays_ButtonWidget_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Core::Overlays::ButtonWidget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Core::Overlays::ButtonWidget* tolua_ret = (Core::Overlays::ButtonWidget*)  Mtolua_new((Core::Overlays::ButtonWidget)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::Overlays::ButtonWidget");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: init of class  Core::Overlays::ButtonWidget */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_ButtonWidget_init00
static int tolua_Overlays_Core_Overlays_ButtonWidget_init00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::ButtonWidget",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,7,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,8,0,&tolua_err) ||
     !tolua_isstring(tolua_S,9,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,10,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,11,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::ButtonWidget* self = (Core::Overlays::ButtonWidget*)  tolua_tousertype(tolua_S,1,0);
  const char* uniqueName = ((const char*)  tolua_tostring(tolua_S,2,0));
  float parentLeft = ((float)  tolua_tonumber(tolua_S,3,0));
  float parentTop = ((float)  tolua_tonumber(tolua_S,4,0));
  float parentRight = ((float)  tolua_tonumber(tolua_S,5,0));
  float parentBottom = ((float)  tolua_tonumber(tolua_S,6,0));
  float xprop = ((float)  tolua_tonumber(tolua_S,7,0));
  float yprop = ((float)  tolua_tonumber(tolua_S,8,0));
  const char* text = ((const char*)  tolua_tostring(tolua_S,9,0));
  bool toggleType = ((bool)  tolua_toboolean(tolua_S,10,false));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'init'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->init(uniqueName,parentLeft,parentTop,parentRight,parentBottom,xprop,yprop,text,toggleType);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'init'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: free of class  Core::Overlays::ButtonWidget */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_ButtonWidget_free00
static int tolua_Overlays_Core_Overlays_ButtonWidget_free00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::ButtonWidget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::ButtonWidget* self = (Core::Overlays::ButtonWidget*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'free'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->free();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'free'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: defineParentBounds of class  Core::Overlays::ButtonWidget */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_ButtonWidget_defineParentBounds00
static int tolua_Overlays_Core_Overlays_ButtonWidget_defineParentBounds00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::ButtonWidget",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::ButtonWidget* self = (Core::Overlays::ButtonWidget*)  tolua_tousertype(tolua_S,1,0);
  float left = ((float)  tolua_tonumber(tolua_S,2,0));
  float top = ((float)  tolua_tonumber(tolua_S,3,0));
  float right = ((float)  tolua_tonumber(tolua_S,4,0));
  float bottom = ((float)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'defineParentBounds'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->defineParentBounds(left,top,right,bottom);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'defineParentBounds'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getElement of class  Core::Overlays::ButtonWidget */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_ButtonWidget_getElement00
static int tolua_Overlays_Core_Overlays_ButtonWidget_getElement00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::ButtonWidget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::ButtonWidget* self = (Core::Overlays::ButtonWidget*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getElement'", NULL);
#endif
  {
   OverlayElement* tolua_ret = (OverlayElement*)  self->getElement();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"OverlayElement");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getElement'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: show of class  Core::Overlays::ButtonWidget */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_ButtonWidget_show00
static int tolua_Overlays_Core_Overlays_ButtonWidget_show00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::ButtonWidget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::ButtonWidget* self = (Core::Overlays::ButtonWidget*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'show'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->show();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'show'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: hide of class  Core::Overlays::ButtonWidget */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_ButtonWidget_hide00
static int tolua_Overlays_Core_Overlays_ButtonWidget_hide00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::ButtonWidget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::ButtonWidget* self = (Core::Overlays::ButtonWidget*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'hide'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->hide();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'hide'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: moveWidget of class  Core::Overlays::ButtonWidget */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_ButtonWidget_moveWidget00
static int tolua_Overlays_Core_Overlays_ButtonWidget_moveWidget00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::ButtonWidget",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::ButtonWidget* self = (Core::Overlays::ButtonWidget*)  tolua_tousertype(tolua_S,1,0);
  float xprop = ((float)  tolua_tonumber(tolua_S,2,0));
  float yprop = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'moveWidget'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->moveWidget(xprop,yprop);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'moveWidget'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setText of class  Core::Overlays::ButtonWidget */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_ButtonWidget_setText00
static int tolua_Overlays_Core_Overlays_ButtonWidget_setText00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::ButtonWidget",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::ButtonWidget* self = (Core::Overlays::ButtonWidget*)  tolua_tousertype(tolua_S,1,0);
  const char* text = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setText'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->setText(text);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setText'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: update of class  Core::Overlays::ButtonWidget */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_ButtonWidget_update00
static int tolua_Overlays_Core_Overlays_ButtonWidget_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::ButtonWidget",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::ButtonWidget* self = (Core::Overlays::ButtonWidget*)  tolua_tousertype(tolua_S,1,0);
  unsigned int mousex = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
  unsigned int mousey = ((unsigned int)  tolua_tonumber(tolua_S,3,0));
  bool lmb = ((bool)  tolua_toboolean(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'update'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->update(mousex,mousey,lmb);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'update'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isHighlighted of class  Core::Overlays::ButtonWidget */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_ButtonWidget_isHighlighted00
static int tolua_Overlays_Core_Overlays_ButtonWidget_isHighlighted00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::ButtonWidget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::ButtonWidget* self = (Core::Overlays::ButtonWidget*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isHighlighted'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isHighlighted();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isHighlighted'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isClicked of class  Core::Overlays::ButtonWidget */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_ButtonWidget_isClicked00
static int tolua_Overlays_Core_Overlays_ButtonWidget_isClicked00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::ButtonWidget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::ButtonWidget* self = (Core::Overlays::ButtonWidget*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isClicked'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isClicked();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isClicked'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isSelected of class  Core::Overlays::ButtonWidget */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_ButtonWidget_isSelected00
static int tolua_Overlays_Core_Overlays_ButtonWidget_isSelected00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::ButtonWidget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::ButtonWidget* self = (Core::Overlays::ButtonWidget*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isSelected'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isSelected();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isSelected'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setSelected of class  Core::Overlays::ButtonWidget */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_ButtonWidget_setSelected00
static int tolua_Overlays_Core_Overlays_ButtonWidget_setSelected00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::ButtonWidget",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::ButtonWidget* self = (Core::Overlays::ButtonWidget*)  tolua_tousertype(tolua_S,1,0);
  bool selected = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setSelected'", NULL);
#endif
  {
   self->setSelected(selected);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setSelected'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: deactivate of class  Core::Overlays::ButtonWidget */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_ButtonWidget_deactivate00
static int tolua_Overlays_Core_Overlays_ButtonWidget_deactivate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::ButtonWidget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::ButtonWidget* self = (Core::Overlays::ButtonWidget*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'deactivate'", NULL);
#endif
  {
   self->deactivate();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'deactivate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: activate of class  Core::Overlays::ButtonWidget */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_ButtonWidget_activate00
static int tolua_Overlays_Core_Overlays_ButtonWidget_activate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::ButtonWidget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::ButtonWidget* self = (Core::Overlays::ButtonWidget*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'activate'", NULL);
#endif
  {
   self->activate();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'activate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Core::Overlays::Compass */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_Compass_new00
static int tolua_Overlays_Core_Overlays_Compass_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Core::Overlays::Compass",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Real",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"Real",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Real worldWidthX = *((Real*)  tolua_tousertype(tolua_S,2,0));
  Real worldWidthZ = *((Real*)  tolua_tousertype(tolua_S,3,0));
  {
   Core::Overlays::Compass* tolua_ret = (Core::Overlays::Compass*)  Mtolua_new((Core::Overlays::Compass)(worldWidthX,worldWidthZ));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::Overlays::Compass");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Core::Overlays::Compass */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_Compass_new00_local
static int tolua_Overlays_Core_Overlays_Compass_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Core::Overlays::Compass",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Real",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"Real",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Real worldWidthX = *((Real*)  tolua_tousertype(tolua_S,2,0));
  Real worldWidthZ = *((Real*)  tolua_tousertype(tolua_S,3,0));
  {
   Core::Overlays::Compass* tolua_ret = (Core::Overlays::Compass*)  Mtolua_new((Core::Overlays::Compass)(worldWidthX,worldWidthZ));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::Overlays::Compass");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Core::Overlays::Compass */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_Compass_delete00
static int tolua_Overlays_Core_Overlays_Compass_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::Compass",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::Compass* self = (Core::Overlays::Compass*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: show of class  Core::Overlays::Compass */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_Compass_show00
static int tolua_Overlays_Core_Overlays_Compass_show00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::Compass",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::Compass* self = (Core::Overlays::Compass*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'show'", NULL);
#endif
  {
   self->show();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'show'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: hide of class  Core::Overlays::Compass */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_Compass_hide00
static int tolua_Overlays_Core_Overlays_Compass_hide00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::Compass",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::Compass* self = (Core::Overlays::Compass*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'hide'", NULL);
#endif
  {
   self->hide();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'hide'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: FrameStarted of class  Core::Overlays::Compass */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_Compass_FrameStarted00
static int tolua_Overlays_Core_Overlays_Compass_FrameStarted00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::Compass",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"SceneNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::Compass* self = (Core::Overlays::Compass*)  tolua_tousertype(tolua_S,1,0);
  SceneNode* playerCameraNode = ((SceneNode*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'FrameStarted'", NULL);
#endif
  {
   self->FrameStarted(playerCameraNode);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'FrameStarted'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Core::Overlays::EntryWidget */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_EntryWidget_new00
static int tolua_Overlays_Core_Overlays_EntryWidget_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Core::Overlays::EntryWidget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Core::Overlays::EntryWidget* tolua_ret = (Core::Overlays::EntryWidget*)  Mtolua_new((Core::Overlays::EntryWidget)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::Overlays::EntryWidget");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Core::Overlays::EntryWidget */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_EntryWidget_new00_local
static int tolua_Overlays_Core_Overlays_EntryWidget_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Core::Overlays::EntryWidget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Core::Overlays::EntryWidget* tolua_ret = (Core::Overlays::EntryWidget*)  Mtolua_new((Core::Overlays::EntryWidget)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::Overlays::EntryWidget");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: init of class  Core::Overlays::EntryWidget */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_EntryWidget_init00
static int tolua_Overlays_Core_Overlays_EntryWidget_init00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::EntryWidget",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,7,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,8,0,&tolua_err) ||
     !tolua_isstring(tolua_S,9,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,10,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,11,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::EntryWidget* self = (Core::Overlays::EntryWidget*)  tolua_tousertype(tolua_S,1,0);
  const char* uniqueName = ((const char*)  tolua_tostring(tolua_S,2,0));
  float parentLeft = ((float)  tolua_tonumber(tolua_S,3,0));
  float parentTop = ((float)  tolua_tonumber(tolua_S,4,0));
  float parentRight = ((float)  tolua_tonumber(tolua_S,5,0));
  float parentBottom = ((float)  tolua_tonumber(tolua_S,6,0));
  float xprop = ((float)  tolua_tonumber(tolua_S,7,0));
  float yprop = ((float)  tolua_tonumber(tolua_S,8,0));
  const char* text = ((const char*)  tolua_tostring(tolua_S,9,0));
  bool toggleType = ((bool)  tolua_toboolean(tolua_S,10,true));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'init'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->init(uniqueName,parentLeft,parentTop,parentRight,parentBottom,xprop,yprop,text,toggleType);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'init'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setText of class  Core::Overlays::EntryWidget */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_EntryWidget_setText00
static int tolua_Overlays_Core_Overlays_EntryWidget_setText00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::EntryWidget",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::EntryWidget* self = (Core::Overlays::EntryWidget*)  tolua_tousertype(tolua_S,1,0);
  const char* text = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setText'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->setText(text);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setText'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: fadeInCallback of class  Core::Overlays::FaderCallback */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_FaderCallback_fadeInCallback00
static int tolua_Overlays_Core_Overlays_FaderCallback_fadeInCallback00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::FaderCallback",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::FaderCallback* self = (Core::Overlays::FaderCallback*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'fadeInCallback'", NULL);
#endif
  {
   self->fadeInCallback();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'fadeInCallback'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: fadeOutCallback of class  Core::Overlays::FaderCallback */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_FaderCallback_fadeOutCallback00
static int tolua_Overlays_Core_Overlays_FaderCallback_fadeOutCallback00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::FaderCallback",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::FaderCallback* self = (Core::Overlays::FaderCallback*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'fadeOutCallback'", NULL);
#endif
  {
   self->fadeOutCallback();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'fadeOutCallback'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Core::Overlays::Fader */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_Fader_new00
static int tolua_Overlays_Core_Overlays_Fader_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Core::Overlays::Fader",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"Core::Overlays::FaderCallback",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* OverlayName = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* MaterialName = ((const char*)  tolua_tostring(tolua_S,3,0));
  Core::Overlays::FaderCallback* instance = ((Core::Overlays::FaderCallback*)  tolua_tousertype(tolua_S,4,0));
  {
   Core::Overlays::Fader* tolua_ret = (Core::Overlays::Fader*)  Mtolua_new((Core::Overlays::Fader)(OverlayName,MaterialName,instance));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::Overlays::Fader");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Core::Overlays::Fader */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_Fader_new00_local
static int tolua_Overlays_Core_Overlays_Fader_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Core::Overlays::Fader",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"Core::Overlays::FaderCallback",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* OverlayName = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* MaterialName = ((const char*)  tolua_tostring(tolua_S,3,0));
  Core::Overlays::FaderCallback* instance = ((Core::Overlays::FaderCallback*)  tolua_tousertype(tolua_S,4,0));
  {
   Core::Overlays::Fader* tolua_ret = (Core::Overlays::Fader*)  Mtolua_new((Core::Overlays::Fader)(OverlayName,MaterialName,instance));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::Overlays::Fader");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Core::Overlays::Fader */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_Fader_delete00
static int tolua_Overlays_Core_Overlays_Fader_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::Fader",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::Fader* self = (Core::Overlays::Fader*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: startFadeIn of class  Core::Overlays::Fader */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_Fader_startFadeIn00
static int tolua_Overlays_Core_Overlays_Fader_startFadeIn00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::Fader",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::Fader* self = (Core::Overlays::Fader*)  tolua_tousertype(tolua_S,1,0);
  double duration = ((double)  tolua_tonumber(tolua_S,2,1.0f));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'startFadeIn'", NULL);
#endif
  {
   self->startFadeIn(duration);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'startFadeIn'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: startFadeOut of class  Core::Overlays::Fader */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_Fader_startFadeOut00
static int tolua_Overlays_Core_Overlays_Fader_startFadeOut00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::Fader",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::Fader* self = (Core::Overlays::Fader*)  tolua_tousertype(tolua_S,1,0);
  double duration = ((double)  tolua_tonumber(tolua_S,2,1.0f));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'startFadeOut'", NULL);
#endif
  {
   self->startFadeOut(duration);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'startFadeOut'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: fade of class  Core::Overlays::Fader */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_Fader_fade00
static int tolua_Overlays_Core_Overlays_Fader_fade00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::Fader",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::Fader* self = (Core::Overlays::Fader*)  tolua_tousertype(tolua_S,1,0);
  double timeSinceLastFrame = ((double)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'fade'", NULL);
#endif
  {
   self->fade(timeSinceLastFrame);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'fade'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Core::Overlays::FileBrowserWidget */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_FileBrowserWidget_new00
static int tolua_Overlays_Core_Overlays_FileBrowserWidget_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Core::Overlays::FileBrowserWidget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Core::Overlays::FileBrowserWidget* tolua_ret = (Core::Overlays::FileBrowserWidget*)  Mtolua_new((Core::Overlays::FileBrowserWidget)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::Overlays::FileBrowserWidget");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Core::Overlays::FileBrowserWidget */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_FileBrowserWidget_new00_local
static int tolua_Overlays_Core_Overlays_FileBrowserWidget_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Core::Overlays::FileBrowserWidget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Core::Overlays::FileBrowserWidget* tolua_ret = (Core::Overlays::FileBrowserWidget*)  Mtolua_new((Core::Overlays::FileBrowserWidget)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::Overlays::FileBrowserWidget");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: init of class  Core::Overlays::FileBrowserWidget */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_FileBrowserWidget_init00
static int tolua_Overlays_Core_Overlays_FileBrowserWidget_init00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::FileBrowserWidget",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,7,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,8,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,9,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::FileBrowserWidget* self = (Core::Overlays::FileBrowserWidget*)  tolua_tousertype(tolua_S,1,0);
  const char* uniqueName = ((const char*)  tolua_tostring(tolua_S,2,0));
  float parentLeft = ((float)  tolua_tonumber(tolua_S,3,0));
  float parentRight = ((float)  tolua_tonumber(tolua_S,4,0));
  float parentTop = ((float)  tolua_tonumber(tolua_S,5,0));
  float parentBottom = ((float)  tolua_tonumber(tolua_S,6,0));
  float xProp = ((float)  tolua_tonumber(tolua_S,7,0));
  float yProp = ((float)  tolua_tonumber(tolua_S,8,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'init'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->init(uniqueName,parentLeft,parentRight,parentTop,parentBottom,xProp,yProp);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'init'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: free of class  Core::Overlays::FileBrowserWidget */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_FileBrowserWidget_free00
static int tolua_Overlays_Core_Overlays_FileBrowserWidget_free00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::FileBrowserWidget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::FileBrowserWidget* self = (Core::Overlays::FileBrowserWidget*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'free'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->free();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'free'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: defineParentBounds of class  Core::Overlays::FileBrowserWidget */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_FileBrowserWidget_defineParentBounds00
static int tolua_Overlays_Core_Overlays_FileBrowserWidget_defineParentBounds00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::FileBrowserWidget",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::FileBrowserWidget* self = (Core::Overlays::FileBrowserWidget*)  tolua_tousertype(tolua_S,1,0);
  float left = ((float)  tolua_tonumber(tolua_S,2,0));
  float top = ((float)  tolua_tonumber(tolua_S,3,0));
  float right = ((float)  tolua_tonumber(tolua_S,4,0));
  float bottom = ((float)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'defineParentBounds'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->defineParentBounds(left,top,right,bottom);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'defineParentBounds'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: scan of class  Core::Overlays::FileBrowserWidget */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_FileBrowserWidget_scan00
static int tolua_Overlays_Core_Overlays_FileBrowserWidget_scan00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::FileBrowserWidget",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,4,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::FileBrowserWidget* self = (Core::Overlays::FileBrowserWidget*)  tolua_tousertype(tolua_S,1,0);
  const char* subdir = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* extension = ((const char*)  tolua_tostring(tolua_S,3,0));
  bool recursive = ((bool)  tolua_toboolean(tolua_S,4,false));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'scan'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->scan(subdir,extension,recursive);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'scan'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: show of class  Core::Overlays::FileBrowserWidget */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_FileBrowserWidget_show00
static int tolua_Overlays_Core_Overlays_FileBrowserWidget_show00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::FileBrowserWidget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::FileBrowserWidget* self = (Core::Overlays::FileBrowserWidget*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'show'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->show();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'show'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: hide of class  Core::Overlays::FileBrowserWidget */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_FileBrowserWidget_hide00
static int tolua_Overlays_Core_Overlays_FileBrowserWidget_hide00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::FileBrowserWidget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::FileBrowserWidget* self = (Core::Overlays::FileBrowserWidget*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'hide'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->hide();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'hide'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: moveWidget of class  Core::Overlays::FileBrowserWidget */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_FileBrowserWidget_moveWidget00
static int tolua_Overlays_Core_Overlays_FileBrowserWidget_moveWidget00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::FileBrowserWidget",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::FileBrowserWidget* self = (Core::Overlays::FileBrowserWidget*)  tolua_tousertype(tolua_S,1,0);
  float xProp = ((float)  tolua_tonumber(tolua_S,2,0));
  float yProp = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'moveWidget'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->moveWidget(xProp,yProp);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'moveWidget'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: moveAbsWidget of class  Core::Overlays::FileBrowserWidget */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_FileBrowserWidget_moveAbsWidget00
static int tolua_Overlays_Core_Overlays_FileBrowserWidget_moveAbsWidget00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::FileBrowserWidget",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::FileBrowserWidget* self = (Core::Overlays::FileBrowserWidget*)  tolua_tousertype(tolua_S,1,0);
  float xprop = ((float)  tolua_tonumber(tolua_S,2,0));
  float yprop = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'moveAbsWidget'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->moveAbsWidget(xprop,yprop);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'moveAbsWidget'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: update of class  Core::Overlays::FileBrowserWidget */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_FileBrowserWidget_update00
static int tolua_Overlays_Core_Overlays_FileBrowserWidget_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::FileBrowserWidget",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::FileBrowserWidget* self = (Core::Overlays::FileBrowserWidget*)  tolua_tousertype(tolua_S,1,0);
  unsigned int mousex = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
  unsigned int mousey = ((unsigned int)  tolua_tonumber(tolua_S,3,0));
  bool lmb = ((bool)  tolua_toboolean(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'update'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->update(mousex,mousey,lmb);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'update'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: populatePage of class  Core::Overlays::FileBrowserWidget */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_FileBrowserWidget_populatePage00
static int tolua_Overlays_Core_Overlays_FileBrowserWidget_populatePage00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::FileBrowserWidget",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::FileBrowserWidget* self = (Core::Overlays::FileBrowserWidget*)  tolua_tousertype(tolua_S,1,0);
  int pageNumber = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'populatePage'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->populatePage(pageNumber);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'populatePage'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getSelectedEntryName of class  Core::Overlays::FileBrowserWidget */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_FileBrowserWidget_getSelectedEntryName00
static int tolua_Overlays_Core_Overlays_FileBrowserWidget_getSelectedEntryName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::FileBrowserWidget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::FileBrowserWidget* self = (Core::Overlays::FileBrowserWidget*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getSelectedEntryName'", NULL);
#endif
  {
   char* tolua_ret = (char*)  self->getSelectedEntryName();
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getSelectedEntryName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isOKClicked of class  Core::Overlays::FileBrowserWidget */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_FileBrowserWidget_isOKClicked00
static int tolua_Overlays_Core_Overlays_FileBrowserWidget_isOKClicked00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::FileBrowserWidget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::FileBrowserWidget* self = (Core::Overlays::FileBrowserWidget*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isOKClicked'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isOKClicked();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isOKClicked'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isCancelClicked of class  Core::Overlays::FileBrowserWidget */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_FileBrowserWidget_isCancelClicked00
static int tolua_Overlays_Core_Overlays_FileBrowserWidget_isCancelClicked00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::FileBrowserWidget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::FileBrowserWidget* self = (Core::Overlays::FileBrowserWidget*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isCancelClicked'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isCancelClicked();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isCancelClicked'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsVisible of class  Core::Overlays::FileBrowserWidget */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_FileBrowserWidget_IsVisible00
static int tolua_Overlays_Core_Overlays_FileBrowserWidget_IsVisible00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::FileBrowserWidget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::FileBrowserWidget* self = (Core::Overlays::FileBrowserWidget*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsVisible'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->IsVisible();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsVisible'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: mSelectedEntry of class  Core::Overlays::FileBrowserWidget */
#ifndef TOLUA_DISABLE_tolua_get_Core__Overlays__FileBrowserWidget_mSelectedEntry
static int tolua_get_Core__Overlays__FileBrowserWidget_mSelectedEntry(lua_State* tolua_S)
{
  Core::Overlays::FileBrowserWidget* self = (Core::Overlays::FileBrowserWidget*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mSelectedEntry'",NULL);
#endif
  tolua_pushstring(tolua_S,(const char*)self->mSelectedEntry);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: mSelectedEntry of class  Core::Overlays::FileBrowserWidget */
#ifndef TOLUA_DISABLE_tolua_set_Core__Overlays__FileBrowserWidget_mSelectedEntry
static int tolua_set_Core__Overlays__FileBrowserWidget_mSelectedEntry(lua_State* tolua_S)
{
  Core::Overlays::FileBrowserWidget* self = (Core::Overlays::FileBrowserWidget*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mSelectedEntry'",NULL);
  if (!tolua_istable(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
 strncpy((char*)
self->mSelectedEntry,(const char*)tolua_tostring(tolua_S,2,0),256-1);
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  FileScanner */
#ifndef TOLUA_DISABLE_tolua_Overlays_FileScanner_new00
static int tolua_Overlays_FileScanner_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"FileScanner",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   FileScanner* tolua_ret = (FileScanner*)  Mtolua_new((FileScanner)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"FileScanner");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  FileScanner */
#ifndef TOLUA_DISABLE_tolua_Overlays_FileScanner_new00_local
static int tolua_Overlays_FileScanner_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"FileScanner",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   FileScanner* tolua_ret = (FileScanner*)  Mtolua_new((FileScanner)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"FileScanner");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: scan of class  FileScanner */
#ifndef TOLUA_DISABLE_tolua_Overlays_FileScanner_scan00
static int tolua_Overlays_FileScanner_scan00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FileScanner",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,4,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FileScanner* self = (FileScanner*)  tolua_tousertype(tolua_S,1,0);
  const char* subdir = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* extension = ((const char*)  tolua_tostring(tolua_S,3,0));
  bool recursive = ((bool)  tolua_toboolean(tolua_S,4,false));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'scan'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->scan(subdir,extension,recursive);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'scan'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getFileCount of class  FileScanner */
#ifndef TOLUA_DISABLE_tolua_Overlays_FileScanner_getFileCount00
static int tolua_Overlays_FileScanner_getFileCount00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FileScanner",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FileScanner* self = (FileScanner*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getFileCount'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getFileCount();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getFileCount'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getFileName of class  FileScanner */
#ifndef TOLUA_DISABLE_tolua_Overlays_FileScanner_getFileName00
static int tolua_Overlays_FileScanner_getFileName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FileScanner",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FileScanner* self = (FileScanner*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getFileName'", NULL);
#endif
  {
   char* tolua_ret = (char*)  self->getFileName(i);
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getFileName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: doesFileExist of class  FileScanner */
#ifndef TOLUA_DISABLE_tolua_Overlays_FileScanner_doesFileExist00
static int tolua_Overlays_FileScanner_doesFileExist00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FileScanner",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FileScanner* self = (FileScanner*)  tolua_tousertype(tolua_S,1,0);
  const char* filename = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'doesFileExist'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->doesFileExist(filename);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'doesFileExist'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Core::Overlays::ImageWidget */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_ImageWidget_new00
static int tolua_Overlays_Core_Overlays_ImageWidget_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Core::Overlays::ImageWidget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Core::Overlays::ImageWidget* tolua_ret = (Core::Overlays::ImageWidget*)  Mtolua_new((Core::Overlays::ImageWidget)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::Overlays::ImageWidget");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Core::Overlays::ImageWidget */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_ImageWidget_new00_local
static int tolua_Overlays_Core_Overlays_ImageWidget_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Core::Overlays::ImageWidget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Core::Overlays::ImageWidget* tolua_ret = (Core::Overlays::ImageWidget*)  Mtolua_new((Core::Overlays::ImageWidget)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::Overlays::ImageWidget");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: init of class  Core::Overlays::ImageWidget */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_ImageWidget_init00
static int tolua_Overlays_Core_Overlays_ImageWidget_init00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::ImageWidget",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,7,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,8,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,9,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,10,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,11,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,12,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::ImageWidget* self = (Core::Overlays::ImageWidget*)  tolua_tousertype(tolua_S,1,0);
  const char* uniqueName = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* materialName = ((const char*)  tolua_tostring(tolua_S,3,0));
  float picWidth = ((float)  tolua_tonumber(tolua_S,4,0));
  float picHeight = ((float)  tolua_tonumber(tolua_S,5,0));
  float xProp = ((float)  tolua_tonumber(tolua_S,6,0));
  float yProp = ((float)  tolua_tonumber(tolua_S,7,0));
  float parentLeft = ((float)  tolua_tonumber(tolua_S,8,0));
  float parentTop = ((float)  tolua_tonumber(tolua_S,9,0));
  float parentRight = ((float)  tolua_tonumber(tolua_S,10,0));
  float parentBottom = ((float)  tolua_tonumber(tolua_S,11,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'init'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->init(uniqueName,materialName,picWidth,picHeight,xProp,yProp,parentLeft,parentTop,parentRight,parentBottom);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'init'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: free of class  Core::Overlays::ImageWidget */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_ImageWidget_free00
static int tolua_Overlays_Core_Overlays_ImageWidget_free00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::ImageWidget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::ImageWidget* self = (Core::Overlays::ImageWidget*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'free'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->free();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'free'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getElement of class  Core::Overlays::ImageWidget */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_ImageWidget_getElement00
static int tolua_Overlays_Core_Overlays_ImageWidget_getElement00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::ImageWidget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::ImageWidget* self = (Core::Overlays::ImageWidget*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getElement'", NULL);
#endif
  {
   OverlayElement* tolua_ret = (OverlayElement*)  self->getElement();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"OverlayElement");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getElement'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: show of class  Core::Overlays::ImageWidget */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_ImageWidget_show00
static int tolua_Overlays_Core_Overlays_ImageWidget_show00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::ImageWidget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::ImageWidget* self = (Core::Overlays::ImageWidget*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'show'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->show();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'show'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: hide of class  Core::Overlays::ImageWidget */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_ImageWidget_hide00
static int tolua_Overlays_Core_Overlays_ImageWidget_hide00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::ImageWidget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::ImageWidget* self = (Core::Overlays::ImageWidget*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'hide'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->hide();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'hide'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setAlignment of class  Core::Overlays::ImageWidget */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_ImageWidget_setAlignment00
static int tolua_Overlays_Core_Overlays_ImageWidget_setAlignment00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::ImageWidget",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::ImageWidget* self = (Core::Overlays::ImageWidget*)  tolua_tousertype(tolua_S,1,0);
  const char* top = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* left = ((const char*)  tolua_tostring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setAlignment'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->setAlignment(top,left);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setAlignment'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: moveWidget of class  Core::Overlays::ImageWidget */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_ImageWidget_moveWidget00
static int tolua_Overlays_Core_Overlays_ImageWidget_moveWidget00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::ImageWidget",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::ImageWidget* self = (Core::Overlays::ImageWidget*)  tolua_tousertype(tolua_S,1,0);
  float xprop = ((float)  tolua_tonumber(tolua_S,2,0));
  float yprop = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'moveWidget'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->moveWidget(xprop,yprop);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'moveWidget'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: defineParentBounds of class  Core::Overlays::ImageWidget */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_ImageWidget_defineParentBounds00
static int tolua_Overlays_Core_Overlays_ImageWidget_defineParentBounds00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::ImageWidget",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::ImageWidget* self = (Core::Overlays::ImageWidget*)  tolua_tousertype(tolua_S,1,0);
  float left = ((float)  tolua_tonumber(tolua_S,2,0));
  float top = ((float)  tolua_tonumber(tolua_S,3,0));
  float right = ((float)  tolua_tonumber(tolua_S,4,0));
  float bottom = ((float)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'defineParentBounds'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->defineParentBounds(left,top,right,bottom);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'defineParentBounds'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Core::Overlays::LabelWidget */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_LabelWidget_new00
static int tolua_Overlays_Core_Overlays_LabelWidget_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Core::Overlays::LabelWidget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Core::Overlays::LabelWidget* tolua_ret = (Core::Overlays::LabelWidget*)  Mtolua_new((Core::Overlays::LabelWidget)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::Overlays::LabelWidget");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Core::Overlays::LabelWidget */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_LabelWidget_new00_local
static int tolua_Overlays_Core_Overlays_LabelWidget_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Core::Overlays::LabelWidget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Core::Overlays::LabelWidget* tolua_ret = (Core::Overlays::LabelWidget*)  Mtolua_new((Core::Overlays::LabelWidget)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::Overlays::LabelWidget");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: init of class  Core::Overlays::LabelWidget */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_LabelWidget_init00
static int tolua_Overlays_Core_Overlays_LabelWidget_init00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::LabelWidget",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,7,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,8,0,&tolua_err) ||
     !tolua_isstring(tolua_S,9,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,10,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::LabelWidget* self = (Core::Overlays::LabelWidget*)  tolua_tousertype(tolua_S,1,0);
  const char* uniqueName = ((const char*)  tolua_tostring(tolua_S,2,0));
  float parentLeft = ((float)  tolua_tonumber(tolua_S,3,0));
  float parentTop = ((float)  tolua_tonumber(tolua_S,4,0));
  float parentRight = ((float)  tolua_tonumber(tolua_S,5,0));
  float parentBottom = ((float)  tolua_tonumber(tolua_S,6,0));
  float xprop = ((float)  tolua_tonumber(tolua_S,7,0));
  float yprop = ((float)  tolua_tonumber(tolua_S,8,0));
  const char* text = ((const char*)  tolua_tostring(tolua_S,9,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'init'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->init(uniqueName,parentLeft,parentTop,parentRight,parentBottom,xprop,yprop,text);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'init'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: free of class  Core::Overlays::LabelWidget */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_LabelWidget_free00
static int tolua_Overlays_Core_Overlays_LabelWidget_free00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::LabelWidget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::LabelWidget* self = (Core::Overlays::LabelWidget*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'free'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->free();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'free'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: defineParentBounds of class  Core::Overlays::LabelWidget */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_LabelWidget_defineParentBounds00
static int tolua_Overlays_Core_Overlays_LabelWidget_defineParentBounds00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::LabelWidget",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::LabelWidget* self = (Core::Overlays::LabelWidget*)  tolua_tousertype(tolua_S,1,0);
  float left = ((float)  tolua_tonumber(tolua_S,2,0));
  float top = ((float)  tolua_tonumber(tolua_S,3,0));
  float right = ((float)  tolua_tonumber(tolua_S,4,0));
  float bottom = ((float)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'defineParentBounds'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->defineParentBounds(left,top,right,bottom);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'defineParentBounds'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getElement of class  Core::Overlays::LabelWidget */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_LabelWidget_getElement00
static int tolua_Overlays_Core_Overlays_LabelWidget_getElement00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::LabelWidget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::LabelWidget* self = (Core::Overlays::LabelWidget*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getElement'", NULL);
#endif
  {
   OverlayElement* tolua_ret = (OverlayElement*)  self->getElement();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"OverlayElement");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getElement'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: show of class  Core::Overlays::LabelWidget */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_LabelWidget_show00
static int tolua_Overlays_Core_Overlays_LabelWidget_show00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::LabelWidget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::LabelWidget* self = (Core::Overlays::LabelWidget*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'show'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->show();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'show'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: hide of class  Core::Overlays::LabelWidget */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_LabelWidget_hide00
static int tolua_Overlays_Core_Overlays_LabelWidget_hide00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::LabelWidget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::LabelWidget* self = (Core::Overlays::LabelWidget*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'hide'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->hide();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'hide'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: moveWidget of class  Core::Overlays::LabelWidget */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_LabelWidget_moveWidget00
static int tolua_Overlays_Core_Overlays_LabelWidget_moveWidget00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::LabelWidget",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::LabelWidget* self = (Core::Overlays::LabelWidget*)  tolua_tousertype(tolua_S,1,0);
  float xprop = ((float)  tolua_tonumber(tolua_S,2,0));
  float yprop = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'moveWidget'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->moveWidget(xprop,yprop);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'moveWidget'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: moveAbsWidget of class  Core::Overlays::LabelWidget */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_LabelWidget_moveAbsWidget00
static int tolua_Overlays_Core_Overlays_LabelWidget_moveAbsWidget00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::LabelWidget",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::LabelWidget* self = (Core::Overlays::LabelWidget*)  tolua_tousertype(tolua_S,1,0);
  float xprop = ((float)  tolua_tonumber(tolua_S,2,0));
  float yprop = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'moveAbsWidget'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->moveAbsWidget(xprop,yprop);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'moveAbsWidget'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setAlignment of class  Core::Overlays::LabelWidget */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_LabelWidget_setAlignment00
static int tolua_Overlays_Core_Overlays_LabelWidget_setAlignment00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::LabelWidget",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::LabelWidget* self = (Core::Overlays::LabelWidget*)  tolua_tousertype(tolua_S,1,0);
  const char* top = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* left = ((const char*)  tolua_tostring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setAlignment'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->setAlignment(top,left);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setAlignment'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setColour of class  Core::Overlays::LabelWidget */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_LabelWidget_setColour00
static int tolua_Overlays_Core_Overlays_LabelWidget_setColour00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::LabelWidget",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::LabelWidget* self = (Core::Overlays::LabelWidget*)  tolua_tousertype(tolua_S,1,0);
  float r = ((float)  tolua_tonumber(tolua_S,2,0));
  float g = ((float)  tolua_tonumber(tolua_S,3,0));
  float b = ((float)  tolua_tonumber(tolua_S,4,0));
  float a = ((float)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setColour'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->setColour(r,g,b,a);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setColour'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setSize of class  Core::Overlays::LabelWidget */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_LabelWidget_setSize00
static int tolua_Overlays_Core_Overlays_LabelWidget_setSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::LabelWidget",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::LabelWidget* self = (Core::Overlays::LabelWidget*)  tolua_tousertype(tolua_S,1,0);
  int charHeight = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setSize'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->setSize(charHeight);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setFont of class  Core::Overlays::LabelWidget */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_LabelWidget_setFont00
static int tolua_Overlays_Core_Overlays_LabelWidget_setFont00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::LabelWidget",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::LabelWidget* self = (Core::Overlays::LabelWidget*)  tolua_tousertype(tolua_S,1,0);
  const char* fontName = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setFont'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->setFont(fontName);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setFont'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: centreText of class  Core::Overlays::LabelWidget */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_LabelWidget_centreText00
static int tolua_Overlays_Core_Overlays_LabelWidget_centreText00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::LabelWidget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::LabelWidget* self = (Core::Overlays::LabelWidget*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'centreText'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->centreText();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'centreText'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setText of class  Core::Overlays::LabelWidget */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_LabelWidget_setText00
static int tolua_Overlays_Core_Overlays_LabelWidget_setText00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::LabelWidget",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::LabelWidget* self = (Core::Overlays::LabelWidget*)  tolua_tousertype(tolua_S,1,0);
  const char* text = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setText'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->setText(text);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setText'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getText of class  Core::Overlays::LabelWidget */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_LabelWidget_getText00
static int tolua_Overlays_Core_Overlays_LabelWidget_getText00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::LabelWidget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::LabelWidget* self = (Core::Overlays::LabelWidget*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getText'", NULL);
#endif
  {
   char* tolua_ret = (char*)  self->getText();
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getText'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Core::Overlays::MiniMap */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_MiniMap_new00
static int tolua_Overlays_Core_Overlays_MiniMap_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Core::Overlays::MiniMap",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,1,&tolua_err) ||
     !tolua_isstring(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* Overlay = ((const char*)  tolua_tostring(tolua_S,2,nullptr));
  const char* OverlayImage = ((const char*)  tolua_tostring(tolua_S,3,nullptr));
  {
   Core::Overlays::MiniMap* tolua_ret = (Core::Overlays::MiniMap*)  Mtolua_new((Core::Overlays::MiniMap)(Overlay,OverlayImage));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::Overlays::MiniMap");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Core::Overlays::MiniMap */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_MiniMap_new00_local
static int tolua_Overlays_Core_Overlays_MiniMap_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Core::Overlays::MiniMap",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,1,&tolua_err) ||
     !tolua_isstring(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* Overlay = ((const char*)  tolua_tostring(tolua_S,2,nullptr));
  const char* OverlayImage = ((const char*)  tolua_tostring(tolua_S,3,nullptr));
  {
   Core::Overlays::MiniMap* tolua_ret = (Core::Overlays::MiniMap*)  Mtolua_new((Core::Overlays::MiniMap)(Overlay,OverlayImage));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::Overlays::MiniMap");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Core::Overlays::MiniMap */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_MiniMap_delete00
static int tolua_Overlays_Core_Overlays_MiniMap_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::MiniMap",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::MiniMap* self = (Core::Overlays::MiniMap*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Update of class  Core::Overlays::MiniMap */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_MiniMap_Update00
static int tolua_Overlays_Core_Overlays_MiniMap_Update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::MiniMap",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::MiniMap* self = (Core::Overlays::MiniMap*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Update'", NULL);
#endif
  {
   self->Update();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Update'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: init of class  Core::Overlays::MouseCursor */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_MouseCursor_init00
static int tolua_Overlays_Core_Overlays_MouseCursor_init00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::MouseCursor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::MouseCursor* self = (Core::Overlays::MouseCursor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'init'", NULL);
#endif
  {
   self->init();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'init'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setImage of class  Core::Overlays::MouseCursor */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_MouseCursor_setImage00
static int tolua_Overlays_Core_Overlays_MouseCursor_setImage00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::MouseCursor",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const String",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::MouseCursor* self = (Core::Overlays::MouseCursor*)  tolua_tousertype(tolua_S,1,0);
  const String* filename = ((const String*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setImage'", NULL);
#endif
  {
   self->setImage(*filename);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setImage'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setWindowDimensions of class  Core::Overlays::MouseCursor */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_MouseCursor_setWindowDimensions00
static int tolua_Overlays_Core_Overlays_MouseCursor_setWindowDimensions00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::MouseCursor",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::MouseCursor* self = (Core::Overlays::MouseCursor*)  tolua_tousertype(tolua_S,1,0);
  unsigned int width = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
  unsigned int height = ((unsigned int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setWindowDimensions'", NULL);
#endif
  {
   self->setWindowDimensions(width,height);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setWindowDimensions'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setVisible of class  Core::Overlays::MouseCursor */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_MouseCursor_setVisible00
static int tolua_Overlays_Core_Overlays_MouseCursor_setVisible00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::MouseCursor",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::MouseCursor* self = (Core::Overlays::MouseCursor*)  tolua_tousertype(tolua_S,1,0);
  bool visible = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setVisible'", NULL);
#endif
  {
   self->setVisible(visible);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setVisible'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: updatePosition of class  Core::Overlays::MouseCursor */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_MouseCursor_updatePosition00
static int tolua_Overlays_Core_Overlays_MouseCursor_updatePosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::MouseCursor",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::MouseCursor* self = (Core::Overlays::MouseCursor*)  tolua_tousertype(tolua_S,1,0);
  int x = ((int)  tolua_tonumber(tolua_S,2,0));
  int y = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'updatePosition'", NULL);
#endif
  {
   self->updatePosition(x,y);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'updatePosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: clamp of class  Core::Overlays::MouseCursor */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_MouseCursor_clamp00
static int tolua_Overlays_Core_Overlays_MouseCursor_clamp00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::MouseCursor",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::MouseCursor* self = (Core::Overlays::MouseCursor*)  tolua_tousertype(tolua_S,1,0);
  float a = ((float)  tolua_tonumber(tolua_S,2,0));
  float min = ((float)  tolua_tonumber(tolua_S,3,0));
  float max = ((float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'clamp'", NULL);
#endif
  {
   float tolua_ret = (float)  self->clamp(a,min,max);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'clamp'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Core::Overlays::Notifications */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_Notifications_new00
static int tolua_Overlays_Core_Overlays_Notifications_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Core::Overlays::Notifications",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Core::Overlays::Notifications* tolua_ret = (Core::Overlays::Notifications*)  Mtolua_new((Core::Overlays::Notifications)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::Overlays::Notifications");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Core::Overlays::Notifications */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_Notifications_new00_local
static int tolua_Overlays_Core_Overlays_Notifications_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Core::Overlays::Notifications",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Core::Overlays::Notifications* tolua_ret = (Core::Overlays::Notifications*)  Mtolua_new((Core::Overlays::Notifications)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::Overlays::Notifications");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Core::Overlays::Notifications */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_Notifications_delete00
static int tolua_Overlays_Core_Overlays_Notifications_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::Notifications",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::Notifications* self = (Core::Overlays::Notifications*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: FrameStarted of class  Core::Overlays::Notifications */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_Notifications_FrameStarted00
static int tolua_Overlays_Core_Overlays_Notifications_FrameStarted00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::Notifications",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Real",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::Notifications* self = (Core::Overlays::Notifications*)  tolua_tousertype(tolua_S,1,0);
  Real timeElapsed = *((Real*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'FrameStarted'", NULL);
#endif
  {
   self->FrameStarted(timeElapsed);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'FrameStarted'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddNotification of class  Core::Overlays::Notifications */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_Notifications_AddNotification00
static int tolua_Overlays_Core_Overlays_Notifications_AddNotification00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::Notifications",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"String",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::Notifications* self = (Core::Overlays::Notifications*)  tolua_tousertype(tolua_S,1,0);
  String theNotification = *((String*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddNotification'", NULL);
#endif
  {
   self->AddNotification(theNotification);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddNotification'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddNotification of class  Core::Overlays::Notifications */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_Notifications_AddNotification01
static int tolua_Overlays_Core_Overlays_Notifications_AddNotification01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::Notifications",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"String",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"ColourValue",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Core::Overlays::Notifications* self = (Core::Overlays::Notifications*)  tolua_tousertype(tolua_S,1,0);
  String theNotification = *((String*)  tolua_tousertype(tolua_S,2,0));
  ColourValue* textColor = ((ColourValue*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddNotification'", NULL);
#endif
  {
   self->AddNotification(theNotification,*textColor);
  }
 }
 return 0;
tolua_lerror:
 return tolua_Overlays_Core_Overlays_Notifications_AddNotification00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Show of class  Core::Overlays::Notifications */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_Notifications_Show00
static int tolua_Overlays_Core_Overlays_Notifications_Show00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::Notifications",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::Notifications* self = (Core::Overlays::Notifications*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Show'", NULL);
#endif
  {
   self->Show();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Show'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Hide of class  Core::Overlays::Notifications */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_Notifications_Hide00
static int tolua_Overlays_Core_Overlays_Notifications_Hide00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::Notifications",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::Notifications* self = (Core::Overlays::Notifications*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Hide'", NULL);
#endif
  {
   self->Hide();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Hide'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Core::Overlays::TextEntryWidget */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_TextEntryWidget_new00
static int tolua_Overlays_Core_Overlays_TextEntryWidget_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Core::Overlays::TextEntryWidget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Core::Overlays::TextEntryWidget* tolua_ret = (Core::Overlays::TextEntryWidget*)  Mtolua_new((Core::Overlays::TextEntryWidget)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::Overlays::TextEntryWidget");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Core::Overlays::TextEntryWidget */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_TextEntryWidget_new00_local
static int tolua_Overlays_Core_Overlays_TextEntryWidget_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Core::Overlays::TextEntryWidget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Core::Overlays::TextEntryWidget* tolua_ret = (Core::Overlays::TextEntryWidget*)  Mtolua_new((Core::Overlays::TextEntryWidget)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::Overlays::TextEntryWidget");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: init of class  Core::Overlays::TextEntryWidget */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_TextEntryWidget_init00
static int tolua_Overlays_Core_Overlays_TextEntryWidget_init00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::TextEntryWidget",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,7,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,8,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,9,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::TextEntryWidget* self = (Core::Overlays::TextEntryWidget*)  tolua_tousertype(tolua_S,1,0);
  const char* uniqueName = ((const char*)  tolua_tostring(tolua_S,2,0));
  float parentLeft = ((float)  tolua_tonumber(tolua_S,3,0));
  float parentTop = ((float)  tolua_tonumber(tolua_S,4,0));
  float parentRight = ((float)  tolua_tonumber(tolua_S,5,0));
  float parentBottom = ((float)  tolua_tonumber(tolua_S,6,0));
  float xprop = ((float)  tolua_tonumber(tolua_S,7,0));
  float yprop = ((float)  tolua_tonumber(tolua_S,8,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'init'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->init(uniqueName,parentLeft,parentTop,parentRight,parentBottom,xprop,yprop);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'init'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: free of class  Core::Overlays::TextEntryWidget */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_TextEntryWidget_free00
static int tolua_Overlays_Core_Overlays_TextEntryWidget_free00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::TextEntryWidget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::TextEntryWidget* self = (Core::Overlays::TextEntryWidget*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'free'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->free();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'free'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: defineParentBounds of class  Core::Overlays::TextEntryWidget */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_TextEntryWidget_defineParentBounds00
static int tolua_Overlays_Core_Overlays_TextEntryWidget_defineParentBounds00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::TextEntryWidget",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::TextEntryWidget* self = (Core::Overlays::TextEntryWidget*)  tolua_tousertype(tolua_S,1,0);
  float left = ((float)  tolua_tonumber(tolua_S,2,0));
  float top = ((float)  tolua_tonumber(tolua_S,3,0));
  float right = ((float)  tolua_tonumber(tolua_S,4,0));
  float bottom = ((float)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'defineParentBounds'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->defineParentBounds(left,top,right,bottom);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'defineParentBounds'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getElement of class  Core::Overlays::TextEntryWidget */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_TextEntryWidget_getElement00
static int tolua_Overlays_Core_Overlays_TextEntryWidget_getElement00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::TextEntryWidget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::TextEntryWidget* self = (Core::Overlays::TextEntryWidget*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getElement'", NULL);
#endif
  {
   OverlayElement* tolua_ret = (OverlayElement*)  self->getElement();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"OverlayElement");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getElement'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: show of class  Core::Overlays::TextEntryWidget */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_TextEntryWidget_show00
static int tolua_Overlays_Core_Overlays_TextEntryWidget_show00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::TextEntryWidget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::TextEntryWidget* self = (Core::Overlays::TextEntryWidget*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'show'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->show();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'show'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: hide of class  Core::Overlays::TextEntryWidget */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_TextEntryWidget_hide00
static int tolua_Overlays_Core_Overlays_TextEntryWidget_hide00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::TextEntryWidget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::TextEntryWidget* self = (Core::Overlays::TextEntryWidget*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'hide'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->hide();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'hide'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: moveWidget of class  Core::Overlays::TextEntryWidget */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_TextEntryWidget_moveWidget00
static int tolua_Overlays_Core_Overlays_TextEntryWidget_moveWidget00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::TextEntryWidget",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::TextEntryWidget* self = (Core::Overlays::TextEntryWidget*)  tolua_tousertype(tolua_S,1,0);
  float xprop = ((float)  tolua_tonumber(tolua_S,2,0));
  float yprop = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'moveWidget'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->moveWidget(xprop,yprop);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'moveWidget'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setTitleText of class  Core::Overlays::TextEntryWidget */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_TextEntryWidget_setTitleText00
static int tolua_Overlays_Core_Overlays_TextEntryWidget_setTitleText00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::TextEntryWidget",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::TextEntryWidget* self = (Core::Overlays::TextEntryWidget*)  tolua_tousertype(tolua_S,1,0);
  const char* text = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setTitleText'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->setTitleText(text);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setTitleText'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setTypedText of class  Core::Overlays::TextEntryWidget */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_TextEntryWidget_setTypedText00
static int tolua_Overlays_Core_Overlays_TextEntryWidget_setTypedText00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::TextEntryWidget",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::TextEntryWidget* self = (Core::Overlays::TextEntryWidget*)  tolua_tousertype(tolua_S,1,0);
  const char* text = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setTypedText'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->setTypedText(text);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setTypedText'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getTypedText of class  Core::Overlays::TextEntryWidget */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_TextEntryWidget_getTypedText00
static int tolua_Overlays_Core_Overlays_TextEntryWidget_getTypedText00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::TextEntryWidget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::TextEntryWidget* self = (Core::Overlays::TextEntryWidget*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getTypedText'", NULL);
#endif
  {
   char* tolua_ret = (char*)  self->getTypedText();
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getTypedText'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: update of class  Core::Overlays::TextEntryWidget */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_TextEntryWidget_update00
static int tolua_Overlays_Core_Overlays_TextEntryWidget_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::TextEntryWidget",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::TextEntryWidget* self = (Core::Overlays::TextEntryWidget*)  tolua_tousertype(tolua_S,1,0);
  unsigned int mousex = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
  unsigned int mousey = ((unsigned int)  tolua_tonumber(tolua_S,3,0));
  bool lmb = ((bool)  tolua_toboolean(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'update'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->update(mousex,mousey,lmb);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'update'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isHighlighted of class  Core::Overlays::TextEntryWidget */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_TextEntryWidget_isHighlighted00
static int tolua_Overlays_Core_Overlays_TextEntryWidget_isHighlighted00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::TextEntryWidget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::TextEntryWidget* self = (Core::Overlays::TextEntryWidget*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isHighlighted'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isHighlighted();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isHighlighted'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isClicked of class  Core::Overlays::TextEntryWidget */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_TextEntryWidget_isClicked00
static int tolua_Overlays_Core_Overlays_TextEntryWidget_isClicked00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::TextEntryWidget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::TextEntryWidget* self = (Core::Overlays::TextEntryWidget*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isClicked'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isClicked();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isClicked'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isSelected of class  Core::Overlays::TextEntryWidget */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_TextEntryWidget_isSelected00
static int tolua_Overlays_Core_Overlays_TextEntryWidget_isSelected00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::TextEntryWidget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::TextEntryWidget* self = (Core::Overlays::TextEntryWidget*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isSelected'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isSelected();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isSelected'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setSelected of class  Core::Overlays::TextEntryWidget */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_TextEntryWidget_setSelected00
static int tolua_Overlays_Core_Overlays_TextEntryWidget_setSelected00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::TextEntryWidget",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::TextEntryWidget* self = (Core::Overlays::TextEntryWidget*)  tolua_tousertype(tolua_S,1,0);
  bool selected = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setSelected'", NULL);
#endif
  {
   self->setSelected(selected);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setSelected'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: deactivate of class  Core::Overlays::TextEntryWidget */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_TextEntryWidget_deactivate00
static int tolua_Overlays_Core_Overlays_TextEntryWidget_deactivate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::TextEntryWidget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::TextEntryWidget* self = (Core::Overlays::TextEntryWidget*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'deactivate'", NULL);
#endif
  {
   self->deactivate();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'deactivate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: activate of class  Core::Overlays::TextEntryWidget */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_TextEntryWidget_activate00
static int tolua_Overlays_Core_Overlays_TextEntryWidget_activate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::TextEntryWidget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::TextEntryWidget* self = (Core::Overlays::TextEntryWidget*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'activate'", NULL);
#endif
  {
   self->activate();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'activate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Core::Overlays::YesNoBoxWidget */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_YesNoBoxWidget_new00
static int tolua_Overlays_Core_Overlays_YesNoBoxWidget_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Core::Overlays::YesNoBoxWidget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Core::Overlays::YesNoBoxWidget* tolua_ret = (Core::Overlays::YesNoBoxWidget*)  Mtolua_new((Core::Overlays::YesNoBoxWidget)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::Overlays::YesNoBoxWidget");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Core::Overlays::YesNoBoxWidget */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_YesNoBoxWidget_new00_local
static int tolua_Overlays_Core_Overlays_YesNoBoxWidget_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Core::Overlays::YesNoBoxWidget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Core::Overlays::YesNoBoxWidget* tolua_ret = (Core::Overlays::YesNoBoxWidget*)  Mtolua_new((Core::Overlays::YesNoBoxWidget)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::Overlays::YesNoBoxWidget");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: init of class  Core::Overlays::YesNoBoxWidget */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_YesNoBoxWidget_init00
static int tolua_Overlays_Core_Overlays_YesNoBoxWidget_init00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::YesNoBoxWidget",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,7,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,8,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,9,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::YesNoBoxWidget* self = (Core::Overlays::YesNoBoxWidget*)  tolua_tousertype(tolua_S,1,0);
  const char* uniqueName = ((const char*)  tolua_tostring(tolua_S,2,0));
  float parentLeft = ((float)  tolua_tonumber(tolua_S,3,0));
  float parentTop = ((float)  tolua_tonumber(tolua_S,4,0));
  float parentRight = ((float)  tolua_tonumber(tolua_S,5,0));
  float parentBottom = ((float)  tolua_tonumber(tolua_S,6,0));
  float xProp = ((float)  tolua_tonumber(tolua_S,7,0));
  float yProp = ((float)  tolua_tonumber(tolua_S,8,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'init'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->init(uniqueName,parentLeft,parentTop,parentRight,parentBottom,xProp,yProp);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'init'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: free of class  Core::Overlays::YesNoBoxWidget */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_YesNoBoxWidget_free00
static int tolua_Overlays_Core_Overlays_YesNoBoxWidget_free00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::YesNoBoxWidget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::YesNoBoxWidget* self = (Core::Overlays::YesNoBoxWidget*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'free'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->free();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'free'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: defineParentBounds of class  Core::Overlays::YesNoBoxWidget */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_YesNoBoxWidget_defineParentBounds00
static int tolua_Overlays_Core_Overlays_YesNoBoxWidget_defineParentBounds00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::YesNoBoxWidget",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::YesNoBoxWidget* self = (Core::Overlays::YesNoBoxWidget*)  tolua_tousertype(tolua_S,1,0);
  float left = ((float)  tolua_tonumber(tolua_S,2,0));
  float top = ((float)  tolua_tonumber(tolua_S,3,0));
  float right = ((float)  tolua_tonumber(tolua_S,4,0));
  float bottom = ((float)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'defineParentBounds'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->defineParentBounds(left,top,right,bottom);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'defineParentBounds'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: show of class  Core::Overlays::YesNoBoxWidget */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_YesNoBoxWidget_show00
static int tolua_Overlays_Core_Overlays_YesNoBoxWidget_show00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::YesNoBoxWidget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::YesNoBoxWidget* self = (Core::Overlays::YesNoBoxWidget*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'show'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->show();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'show'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: hide of class  Core::Overlays::YesNoBoxWidget */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_YesNoBoxWidget_hide00
static int tolua_Overlays_Core_Overlays_YesNoBoxWidget_hide00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::YesNoBoxWidget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::YesNoBoxWidget* self = (Core::Overlays::YesNoBoxWidget*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'hide'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->hide();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'hide'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: moveWidget of class  Core::Overlays::YesNoBoxWidget */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_YesNoBoxWidget_moveWidget00
static int tolua_Overlays_Core_Overlays_YesNoBoxWidget_moveWidget00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::YesNoBoxWidget",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::YesNoBoxWidget* self = (Core::Overlays::YesNoBoxWidget*)  tolua_tousertype(tolua_S,1,0);
  float xProp = ((float)  tolua_tonumber(tolua_S,2,0));
  float yProp = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'moveWidget'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->moveWidget(xProp,yProp);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'moveWidget'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: update of class  Core::Overlays::YesNoBoxWidget */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_YesNoBoxWidget_update00
static int tolua_Overlays_Core_Overlays_YesNoBoxWidget_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::YesNoBoxWidget",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::YesNoBoxWidget* self = (Core::Overlays::YesNoBoxWidget*)  tolua_tousertype(tolua_S,1,0);
  unsigned int mousex = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
  unsigned int mousey = ((unsigned int)  tolua_tonumber(tolua_S,3,0));
  bool lmb = ((bool)  tolua_toboolean(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'update'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->update(mousex,mousey,lmb);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'update'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isOKClicked of class  Core::Overlays::YesNoBoxWidget */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_YesNoBoxWidget_isOKClicked00
static int tolua_Overlays_Core_Overlays_YesNoBoxWidget_isOKClicked00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::YesNoBoxWidget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::YesNoBoxWidget* self = (Core::Overlays::YesNoBoxWidget*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isOKClicked'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isOKClicked();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isOKClicked'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isCancelClicked of class  Core::Overlays::YesNoBoxWidget */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_YesNoBoxWidget_isCancelClicked00
static int tolua_Overlays_Core_Overlays_YesNoBoxWidget_isCancelClicked00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::YesNoBoxWidget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::YesNoBoxWidget* self = (Core::Overlays::YesNoBoxWidget*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isCancelClicked'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isCancelClicked();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isCancelClicked'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isShowing of class  Core::Overlays::YesNoBoxWidget */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_YesNoBoxWidget_isShowing00
static int tolua_Overlays_Core_Overlays_YesNoBoxWidget_isShowing00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::YesNoBoxWidget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::YesNoBoxWidget* self = (Core::Overlays::YesNoBoxWidget*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isShowing'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isShowing();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isShowing'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setQuestion of class  Core::Overlays::YesNoBoxWidget */
#ifndef TOLUA_DISABLE_tolua_Overlays_Core_Overlays_YesNoBoxWidget_setQuestion00
static int tolua_Overlays_Core_Overlays_YesNoBoxWidget_setQuestion00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Overlays::YesNoBoxWidget",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Overlays::YesNoBoxWidget* self = (Core::Overlays::YesNoBoxWidget*)  tolua_tousertype(tolua_S,1,0);
  const char* questionText = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setQuestion'", NULL);
#endif
  {
   self->setQuestion(questionText);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setQuestion'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_Overlays_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_module(tolua_S,"Core",0);
  tolua_beginmodule(tolua_S,"Core");
   tolua_module(tolua_S,"Overlays",0);
   tolua_beginmodule(tolua_S,"Overlays");
    #ifdef __cplusplus
    tolua_cclass(tolua_S,"BigTitleWidget","Core::Overlays::BigTitleWidget","",tolua_collect_Core__Overlays__BigTitleWidget);
    #else
    tolua_cclass(tolua_S,"BigTitleWidget","Core::Overlays::BigTitleWidget","",NULL);
    #endif
    tolua_beginmodule(tolua_S,"BigTitleWidget");
     tolua_function(tolua_S,"new",tolua_Overlays_Core_Overlays_BigTitleWidget_new00);
     tolua_function(tolua_S,"new_local",tolua_Overlays_Core_Overlays_BigTitleWidget_new00_local);
     tolua_function(tolua_S,".call",tolua_Overlays_Core_Overlays_BigTitleWidget_new00_local);
     tolua_function(tolua_S,"init",tolua_Overlays_Core_Overlays_BigTitleWidget_init00);
     tolua_function(tolua_S,"free",tolua_Overlays_Core_Overlays_BigTitleWidget_free00);
     tolua_function(tolua_S,"defineParentBounds",tolua_Overlays_Core_Overlays_BigTitleWidget_defineParentBounds00);
     tolua_function(tolua_S,"getElement",tolua_Overlays_Core_Overlays_BigTitleWidget_getElement00);
     tolua_function(tolua_S,"show",tolua_Overlays_Core_Overlays_BigTitleWidget_show00);
     tolua_function(tolua_S,"hide",tolua_Overlays_Core_Overlays_BigTitleWidget_hide00);
     tolua_function(tolua_S,"moveWidget",tolua_Overlays_Core_Overlays_BigTitleWidget_moveWidget00);
     tolua_function(tolua_S,"setText",tolua_Overlays_Core_Overlays_BigTitleWidget_setText00);
    tolua_endmodule(tolua_S);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"Core",0);
  tolua_beginmodule(tolua_S,"Core");
   tolua_module(tolua_S,"Overlays",0);
   tolua_beginmodule(tolua_S,"Overlays");
    #ifdef __cplusplus
    tolua_cclass(tolua_S,"ButtonWidget","Core::Overlays::ButtonWidget","",tolua_collect_Core__Overlays__ButtonWidget);
    #else
    tolua_cclass(tolua_S,"ButtonWidget","Core::Overlays::ButtonWidget","",NULL);
    #endif
    tolua_beginmodule(tolua_S,"ButtonWidget");
     tolua_function(tolua_S,"new",tolua_Overlays_Core_Overlays_ButtonWidget_new00);
     tolua_function(tolua_S,"new_local",tolua_Overlays_Core_Overlays_ButtonWidget_new00_local);
     tolua_function(tolua_S,".call",tolua_Overlays_Core_Overlays_ButtonWidget_new00_local);
     tolua_function(tolua_S,"init",tolua_Overlays_Core_Overlays_ButtonWidget_init00);
     tolua_function(tolua_S,"free",tolua_Overlays_Core_Overlays_ButtonWidget_free00);
     tolua_function(tolua_S,"defineParentBounds",tolua_Overlays_Core_Overlays_ButtonWidget_defineParentBounds00);
     tolua_function(tolua_S,"getElement",tolua_Overlays_Core_Overlays_ButtonWidget_getElement00);
     tolua_function(tolua_S,"show",tolua_Overlays_Core_Overlays_ButtonWidget_show00);
     tolua_function(tolua_S,"hide",tolua_Overlays_Core_Overlays_ButtonWidget_hide00);
     tolua_function(tolua_S,"moveWidget",tolua_Overlays_Core_Overlays_ButtonWidget_moveWidget00);
     tolua_function(tolua_S,"setText",tolua_Overlays_Core_Overlays_ButtonWidget_setText00);
     tolua_function(tolua_S,"update",tolua_Overlays_Core_Overlays_ButtonWidget_update00);
     tolua_function(tolua_S,"isHighlighted",tolua_Overlays_Core_Overlays_ButtonWidget_isHighlighted00);
     tolua_function(tolua_S,"isClicked",tolua_Overlays_Core_Overlays_ButtonWidget_isClicked00);
     tolua_function(tolua_S,"isSelected",tolua_Overlays_Core_Overlays_ButtonWidget_isSelected00);
     tolua_function(tolua_S,"setSelected",tolua_Overlays_Core_Overlays_ButtonWidget_setSelected00);
     tolua_function(tolua_S,"deactivate",tolua_Overlays_Core_Overlays_ButtonWidget_deactivate00);
     tolua_function(tolua_S,"activate",tolua_Overlays_Core_Overlays_ButtonWidget_activate00);
    tolua_endmodule(tolua_S);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"Core",0);
  tolua_beginmodule(tolua_S,"Core");
   tolua_module(tolua_S,"Overlays",0);
   tolua_beginmodule(tolua_S,"Overlays");
    #ifdef __cplusplus
    tolua_cclass(tolua_S,"Compass","Core::Overlays::Compass","",tolua_collect_Core__Overlays__Compass);
    #else
    tolua_cclass(tolua_S,"Compass","Core::Overlays::Compass","",NULL);
    #endif
    tolua_beginmodule(tolua_S,"Compass");
     tolua_function(tolua_S,"new",tolua_Overlays_Core_Overlays_Compass_new00);
     tolua_function(tolua_S,"new_local",tolua_Overlays_Core_Overlays_Compass_new00_local);
     tolua_function(tolua_S,".call",tolua_Overlays_Core_Overlays_Compass_new00_local);
     tolua_function(tolua_S,"delete",tolua_Overlays_Core_Overlays_Compass_delete00);
     tolua_function(tolua_S,"show",tolua_Overlays_Core_Overlays_Compass_show00);
     tolua_function(tolua_S,"hide",tolua_Overlays_Core_Overlays_Compass_hide00);
     tolua_function(tolua_S,"FrameStarted",tolua_Overlays_Core_Overlays_Compass_FrameStarted00);
    tolua_endmodule(tolua_S);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"Core",0);
  tolua_beginmodule(tolua_S,"Core");
   tolua_module(tolua_S,"Overlays",0);
   tolua_beginmodule(tolua_S,"Overlays");
    #ifdef __cplusplus
    tolua_cclass(tolua_S,"EntryWidget","Core::Overlays::EntryWidget","Core::Overlays::ButtonWidget",tolua_collect_Core__Overlays__EntryWidget);
    #else
    tolua_cclass(tolua_S,"EntryWidget","Core::Overlays::EntryWidget","Core::Overlays::ButtonWidget",NULL);
    #endif
    tolua_beginmodule(tolua_S,"EntryWidget");
     tolua_function(tolua_S,"new",tolua_Overlays_Core_Overlays_EntryWidget_new00);
     tolua_function(tolua_S,"new_local",tolua_Overlays_Core_Overlays_EntryWidget_new00_local);
     tolua_function(tolua_S,".call",tolua_Overlays_Core_Overlays_EntryWidget_new00_local);
     tolua_function(tolua_S,"init",tolua_Overlays_Core_Overlays_EntryWidget_init00);
     tolua_function(tolua_S,"setText",tolua_Overlays_Core_Overlays_EntryWidget_setText00);
    tolua_endmodule(tolua_S);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"Ogre",0);
  tolua_beginmodule(tolua_S,"Ogre");
   tolua_cclass(tolua_S,"TextureUnitState","Ogre::TextureUnitState","",NULL);
   tolua_beginmodule(tolua_S,"TextureUnitState");
   tolua_endmodule(tolua_S);
   tolua_cclass(tolua_S,"Overlay","Ogre::Overlay","",NULL);
   tolua_beginmodule(tolua_S,"Overlay");
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"Core",0);
  tolua_beginmodule(tolua_S,"Core");
   tolua_module(tolua_S,"Overlays",0);
   tolua_beginmodule(tolua_S,"Overlays");
    tolua_cclass(tolua_S,"FaderCallback","Core::Overlays::FaderCallback","",NULL);
    tolua_beginmodule(tolua_S,"FaderCallback");
     tolua_function(tolua_S,"fadeInCallback",tolua_Overlays_Core_Overlays_FaderCallback_fadeInCallback00);
     tolua_function(tolua_S,"fadeOutCallback",tolua_Overlays_Core_Overlays_FaderCallback_fadeOutCallback00);
    tolua_endmodule(tolua_S);
    #ifdef __cplusplus
    tolua_cclass(tolua_S,"Fader","Core::Overlays::Fader","",tolua_collect_Core__Overlays__Fader);
    #else
    tolua_cclass(tolua_S,"Fader","Core::Overlays::Fader","",NULL);
    #endif
    tolua_beginmodule(tolua_S,"Fader");
     tolua_function(tolua_S,"new",tolua_Overlays_Core_Overlays_Fader_new00);
     tolua_function(tolua_S,"new_local",tolua_Overlays_Core_Overlays_Fader_new00_local);
     tolua_function(tolua_S,".call",tolua_Overlays_Core_Overlays_Fader_new00_local);
     tolua_function(tolua_S,"delete",tolua_Overlays_Core_Overlays_Fader_delete00);
     tolua_function(tolua_S,"startFadeIn",tolua_Overlays_Core_Overlays_Fader_startFadeIn00);
     tolua_function(tolua_S,"startFadeOut",tolua_Overlays_Core_Overlays_Fader_startFadeOut00);
     tolua_function(tolua_S,"fade",tolua_Overlays_Core_Overlays_Fader_fade00);
    tolua_endmodule(tolua_S);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"Core",0);
  tolua_beginmodule(tolua_S,"Core");
   tolua_module(tolua_S,"Overlays",0);
   tolua_beginmodule(tolua_S,"Overlays");
    #ifdef __cplusplus
    tolua_cclass(tolua_S,"FileBrowserWidget","Core::Overlays::FileBrowserWidget","",tolua_collect_Core__Overlays__FileBrowserWidget);
    #else
    tolua_cclass(tolua_S,"FileBrowserWidget","Core::Overlays::FileBrowserWidget","",NULL);
    #endif
    tolua_beginmodule(tolua_S,"FileBrowserWidget");
     tolua_function(tolua_S,"new",tolua_Overlays_Core_Overlays_FileBrowserWidget_new00);
     tolua_function(tolua_S,"new_local",tolua_Overlays_Core_Overlays_FileBrowserWidget_new00_local);
     tolua_function(tolua_S,".call",tolua_Overlays_Core_Overlays_FileBrowserWidget_new00_local);
     tolua_function(tolua_S,"init",tolua_Overlays_Core_Overlays_FileBrowserWidget_init00);
     tolua_function(tolua_S,"free",tolua_Overlays_Core_Overlays_FileBrowserWidget_free00);
     tolua_function(tolua_S,"defineParentBounds",tolua_Overlays_Core_Overlays_FileBrowserWidget_defineParentBounds00);
     tolua_function(tolua_S,"scan",tolua_Overlays_Core_Overlays_FileBrowserWidget_scan00);
     tolua_function(tolua_S,"show",tolua_Overlays_Core_Overlays_FileBrowserWidget_show00);
     tolua_function(tolua_S,"hide",tolua_Overlays_Core_Overlays_FileBrowserWidget_hide00);
     tolua_function(tolua_S,"moveWidget",tolua_Overlays_Core_Overlays_FileBrowserWidget_moveWidget00);
     tolua_function(tolua_S,"moveAbsWidget",tolua_Overlays_Core_Overlays_FileBrowserWidget_moveAbsWidget00);
     tolua_function(tolua_S,"update",tolua_Overlays_Core_Overlays_FileBrowserWidget_update00);
     tolua_function(tolua_S,"populatePage",tolua_Overlays_Core_Overlays_FileBrowserWidget_populatePage00);
     tolua_function(tolua_S,"getSelectedEntryName",tolua_Overlays_Core_Overlays_FileBrowserWidget_getSelectedEntryName00);
     tolua_function(tolua_S,"isOKClicked",tolua_Overlays_Core_Overlays_FileBrowserWidget_isOKClicked00);
     tolua_function(tolua_S,"isCancelClicked",tolua_Overlays_Core_Overlays_FileBrowserWidget_isCancelClicked00);
     tolua_function(tolua_S,"IsVisible",tolua_Overlays_Core_Overlays_FileBrowserWidget_IsVisible00);
     tolua_variable(tolua_S,"mSelectedEntry",tolua_get_Core__Overlays__FileBrowserWidget_mSelectedEntry,tolua_set_Core__Overlays__FileBrowserWidget_mSelectedEntry);
    tolua_endmodule(tolua_S);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"FileScanner","FileScanner","",tolua_collect_FileScanner);
  #else
  tolua_cclass(tolua_S,"FileScanner","FileScanner","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"FileScanner");
   tolua_function(tolua_S,"new",tolua_Overlays_FileScanner_new00);
   tolua_function(tolua_S,"new_local",tolua_Overlays_FileScanner_new00_local);
   tolua_function(tolua_S,".call",tolua_Overlays_FileScanner_new00_local);
   tolua_function(tolua_S,"scan",tolua_Overlays_FileScanner_scan00);
   tolua_function(tolua_S,"getFileCount",tolua_Overlays_FileScanner_getFileCount00);
   tolua_function(tolua_S,"getFileName",tolua_Overlays_FileScanner_getFileName00);
   tolua_function(tolua_S,"doesFileExist",tolua_Overlays_FileScanner_doesFileExist00);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"Core",0);
  tolua_beginmodule(tolua_S,"Core");
   tolua_module(tolua_S,"Overlays",0);
   tolua_beginmodule(tolua_S,"Overlays");
    #ifdef __cplusplus
    tolua_cclass(tolua_S,"ImageWidget","Core::Overlays::ImageWidget","",tolua_collect_Core__Overlays__ImageWidget);
    #else
    tolua_cclass(tolua_S,"ImageWidget","Core::Overlays::ImageWidget","",NULL);
    #endif
    tolua_beginmodule(tolua_S,"ImageWidget");
     tolua_function(tolua_S,"new",tolua_Overlays_Core_Overlays_ImageWidget_new00);
     tolua_function(tolua_S,"new_local",tolua_Overlays_Core_Overlays_ImageWidget_new00_local);
     tolua_function(tolua_S,".call",tolua_Overlays_Core_Overlays_ImageWidget_new00_local);
     tolua_function(tolua_S,"init",tolua_Overlays_Core_Overlays_ImageWidget_init00);
     tolua_function(tolua_S,"free",tolua_Overlays_Core_Overlays_ImageWidget_free00);
     tolua_function(tolua_S,"getElement",tolua_Overlays_Core_Overlays_ImageWidget_getElement00);
     tolua_function(tolua_S,"show",tolua_Overlays_Core_Overlays_ImageWidget_show00);
     tolua_function(tolua_S,"hide",tolua_Overlays_Core_Overlays_ImageWidget_hide00);
     tolua_function(tolua_S,"setAlignment",tolua_Overlays_Core_Overlays_ImageWidget_setAlignment00);
     tolua_function(tolua_S,"moveWidget",tolua_Overlays_Core_Overlays_ImageWidget_moveWidget00);
     tolua_function(tolua_S,"defineParentBounds",tolua_Overlays_Core_Overlays_ImageWidget_defineParentBounds00);
    tolua_endmodule(tolua_S);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"Core",0);
  tolua_beginmodule(tolua_S,"Core");
   tolua_module(tolua_S,"Overlays",0);
   tolua_beginmodule(tolua_S,"Overlays");
    #ifdef __cplusplus
    tolua_cclass(tolua_S,"LabelWidget","Core::Overlays::LabelWidget","",tolua_collect_Core__Overlays__LabelWidget);
    #else
    tolua_cclass(tolua_S,"LabelWidget","Core::Overlays::LabelWidget","",NULL);
    #endif
    tolua_beginmodule(tolua_S,"LabelWidget");
     tolua_function(tolua_S,"new",tolua_Overlays_Core_Overlays_LabelWidget_new00);
     tolua_function(tolua_S,"new_local",tolua_Overlays_Core_Overlays_LabelWidget_new00_local);
     tolua_function(tolua_S,".call",tolua_Overlays_Core_Overlays_LabelWidget_new00_local);
     tolua_function(tolua_S,"init",tolua_Overlays_Core_Overlays_LabelWidget_init00);
     tolua_function(tolua_S,"free",tolua_Overlays_Core_Overlays_LabelWidget_free00);
     tolua_function(tolua_S,"defineParentBounds",tolua_Overlays_Core_Overlays_LabelWidget_defineParentBounds00);
     tolua_function(tolua_S,"getElement",tolua_Overlays_Core_Overlays_LabelWidget_getElement00);
     tolua_function(tolua_S,"show",tolua_Overlays_Core_Overlays_LabelWidget_show00);
     tolua_function(tolua_S,"hide",tolua_Overlays_Core_Overlays_LabelWidget_hide00);
     tolua_function(tolua_S,"moveWidget",tolua_Overlays_Core_Overlays_LabelWidget_moveWidget00);
     tolua_function(tolua_S,"moveAbsWidget",tolua_Overlays_Core_Overlays_LabelWidget_moveAbsWidget00);
     tolua_function(tolua_S,"setAlignment",tolua_Overlays_Core_Overlays_LabelWidget_setAlignment00);
     tolua_function(tolua_S,"setColour",tolua_Overlays_Core_Overlays_LabelWidget_setColour00);
     tolua_function(tolua_S,"setSize",tolua_Overlays_Core_Overlays_LabelWidget_setSize00);
     tolua_function(tolua_S,"setFont",tolua_Overlays_Core_Overlays_LabelWidget_setFont00);
     tolua_function(tolua_S,"centreText",tolua_Overlays_Core_Overlays_LabelWidget_centreText00);
     tolua_function(tolua_S,"setText",tolua_Overlays_Core_Overlays_LabelWidget_setText00);
     tolua_function(tolua_S,"getText",tolua_Overlays_Core_Overlays_LabelWidget_getText00);
    tolua_endmodule(tolua_S);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"Core",0);
  tolua_beginmodule(tolua_S,"Core");
   tolua_module(tolua_S,"Overlays",0);
   tolua_beginmodule(tolua_S,"Overlays");
    #ifdef __cplusplus
    tolua_cclass(tolua_S,"MiniMap","Core::Overlays::MiniMap","",tolua_collect_Core__Overlays__MiniMap);
    #else
    tolua_cclass(tolua_S,"MiniMap","Core::Overlays::MiniMap","",NULL);
    #endif
    tolua_beginmodule(tolua_S,"MiniMap");
     tolua_function(tolua_S,"new",tolua_Overlays_Core_Overlays_MiniMap_new00);
     tolua_function(tolua_S,"new_local",tolua_Overlays_Core_Overlays_MiniMap_new00_local);
     tolua_function(tolua_S,".call",tolua_Overlays_Core_Overlays_MiniMap_new00_local);
     tolua_function(tolua_S,"delete",tolua_Overlays_Core_Overlays_MiniMap_delete00);
     tolua_function(tolua_S,"Update",tolua_Overlays_Core_Overlays_MiniMap_Update00);
    tolua_endmodule(tolua_S);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"Core",0);
  tolua_beginmodule(tolua_S,"Core");
   tolua_module(tolua_S,"Overlays",0);
   tolua_beginmodule(tolua_S,"Overlays");
    tolua_cclass(tolua_S,"MouseCursor","Core::Overlays::MouseCursor","",NULL);
    tolua_beginmodule(tolua_S,"MouseCursor");
     tolua_function(tolua_S,"init",tolua_Overlays_Core_Overlays_MouseCursor_init00);
     tolua_function(tolua_S,"setImage",tolua_Overlays_Core_Overlays_MouseCursor_setImage00);
     tolua_function(tolua_S,"setWindowDimensions",tolua_Overlays_Core_Overlays_MouseCursor_setWindowDimensions00);
     tolua_function(tolua_S,"setVisible",tolua_Overlays_Core_Overlays_MouseCursor_setVisible00);
     tolua_function(tolua_S,"updatePosition",tolua_Overlays_Core_Overlays_MouseCursor_updatePosition00);
     tolua_function(tolua_S,"clamp",tolua_Overlays_Core_Overlays_MouseCursor_clamp00);
    tolua_endmodule(tolua_S);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"Core",0);
  tolua_beginmodule(tolua_S,"Core");
   tolua_module(tolua_S,"Overlays",0);
   tolua_beginmodule(tolua_S,"Overlays");
    #ifdef __cplusplus
    tolua_cclass(tolua_S,"Notifications","Core::Overlays::Notifications","",tolua_collect_Core__Overlays__Notifications);
    #else
    tolua_cclass(tolua_S,"Notifications","Core::Overlays::Notifications","",NULL);
    #endif
    tolua_beginmodule(tolua_S,"Notifications");
     tolua_function(tolua_S,"new",tolua_Overlays_Core_Overlays_Notifications_new00);
     tolua_function(tolua_S,"new_local",tolua_Overlays_Core_Overlays_Notifications_new00_local);
     tolua_function(tolua_S,".call",tolua_Overlays_Core_Overlays_Notifications_new00_local);
     tolua_function(tolua_S,"delete",tolua_Overlays_Core_Overlays_Notifications_delete00);
     tolua_function(tolua_S,"FrameStarted",tolua_Overlays_Core_Overlays_Notifications_FrameStarted00);
     tolua_function(tolua_S,"AddNotification",tolua_Overlays_Core_Overlays_Notifications_AddNotification00);
     tolua_function(tolua_S,"AddNotification",tolua_Overlays_Core_Overlays_Notifications_AddNotification01);
     tolua_function(tolua_S,"Show",tolua_Overlays_Core_Overlays_Notifications_Show00);
     tolua_function(tolua_S,"Hide",tolua_Overlays_Core_Overlays_Notifications_Hide00);
    tolua_endmodule(tolua_S);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"Core",0);
  tolua_beginmodule(tolua_S,"Core");
   tolua_module(tolua_S,"Overlays",0);
   tolua_beginmodule(tolua_S,"Overlays");
    #ifdef __cplusplus
    tolua_cclass(tolua_S,"TextEntryWidget","Core::Overlays::TextEntryWidget","",tolua_collect_Core__Overlays__TextEntryWidget);
    #else
    tolua_cclass(tolua_S,"TextEntryWidget","Core::Overlays::TextEntryWidget","",NULL);
    #endif
    tolua_beginmodule(tolua_S,"TextEntryWidget");
     tolua_function(tolua_S,"new",tolua_Overlays_Core_Overlays_TextEntryWidget_new00);
     tolua_function(tolua_S,"new_local",tolua_Overlays_Core_Overlays_TextEntryWidget_new00_local);
     tolua_function(tolua_S,".call",tolua_Overlays_Core_Overlays_TextEntryWidget_new00_local);
     tolua_function(tolua_S,"init",tolua_Overlays_Core_Overlays_TextEntryWidget_init00);
     tolua_function(tolua_S,"free",tolua_Overlays_Core_Overlays_TextEntryWidget_free00);
     tolua_function(tolua_S,"defineParentBounds",tolua_Overlays_Core_Overlays_TextEntryWidget_defineParentBounds00);
     tolua_function(tolua_S,"getElement",tolua_Overlays_Core_Overlays_TextEntryWidget_getElement00);
     tolua_function(tolua_S,"show",tolua_Overlays_Core_Overlays_TextEntryWidget_show00);
     tolua_function(tolua_S,"hide",tolua_Overlays_Core_Overlays_TextEntryWidget_hide00);
     tolua_function(tolua_S,"moveWidget",tolua_Overlays_Core_Overlays_TextEntryWidget_moveWidget00);
     tolua_function(tolua_S,"setTitleText",tolua_Overlays_Core_Overlays_TextEntryWidget_setTitleText00);
     tolua_function(tolua_S,"setTypedText",tolua_Overlays_Core_Overlays_TextEntryWidget_setTypedText00);
     tolua_function(tolua_S,"getTypedText",tolua_Overlays_Core_Overlays_TextEntryWidget_getTypedText00);
     tolua_function(tolua_S,"update",tolua_Overlays_Core_Overlays_TextEntryWidget_update00);
     tolua_function(tolua_S,"isHighlighted",tolua_Overlays_Core_Overlays_TextEntryWidget_isHighlighted00);
     tolua_function(tolua_S,"isClicked",tolua_Overlays_Core_Overlays_TextEntryWidget_isClicked00);
     tolua_function(tolua_S,"isSelected",tolua_Overlays_Core_Overlays_TextEntryWidget_isSelected00);
     tolua_function(tolua_S,"setSelected",tolua_Overlays_Core_Overlays_TextEntryWidget_setSelected00);
     tolua_function(tolua_S,"deactivate",tolua_Overlays_Core_Overlays_TextEntryWidget_deactivate00);
     tolua_function(tolua_S,"activate",tolua_Overlays_Core_Overlays_TextEntryWidget_activate00);
    tolua_endmodule(tolua_S);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"Core",0);
  tolua_beginmodule(tolua_S,"Core");
   tolua_module(tolua_S,"Overlays",0);
   tolua_beginmodule(tolua_S,"Overlays");
    #ifdef __cplusplus
    tolua_cclass(tolua_S,"YesNoBoxWidget","Core::Overlays::YesNoBoxWidget","",tolua_collect_Core__Overlays__YesNoBoxWidget);
    #else
    tolua_cclass(tolua_S,"YesNoBoxWidget","Core::Overlays::YesNoBoxWidget","",NULL);
    #endif
    tolua_beginmodule(tolua_S,"YesNoBoxWidget");
     tolua_function(tolua_S,"new",tolua_Overlays_Core_Overlays_YesNoBoxWidget_new00);
     tolua_function(tolua_S,"new_local",tolua_Overlays_Core_Overlays_YesNoBoxWidget_new00_local);
     tolua_function(tolua_S,".call",tolua_Overlays_Core_Overlays_YesNoBoxWidget_new00_local);
     tolua_function(tolua_S,"init",tolua_Overlays_Core_Overlays_YesNoBoxWidget_init00);
     tolua_function(tolua_S,"free",tolua_Overlays_Core_Overlays_YesNoBoxWidget_free00);
     tolua_function(tolua_S,"defineParentBounds",tolua_Overlays_Core_Overlays_YesNoBoxWidget_defineParentBounds00);
     tolua_function(tolua_S,"show",tolua_Overlays_Core_Overlays_YesNoBoxWidget_show00);
     tolua_function(tolua_S,"hide",tolua_Overlays_Core_Overlays_YesNoBoxWidget_hide00);
     tolua_function(tolua_S,"moveWidget",tolua_Overlays_Core_Overlays_YesNoBoxWidget_moveWidget00);
     tolua_function(tolua_S,"update",tolua_Overlays_Core_Overlays_YesNoBoxWidget_update00);
     tolua_function(tolua_S,"isOKClicked",tolua_Overlays_Core_Overlays_YesNoBoxWidget_isOKClicked00);
     tolua_function(tolua_S,"isCancelClicked",tolua_Overlays_Core_Overlays_YesNoBoxWidget_isCancelClicked00);
     tolua_function(tolua_S,"isShowing",tolua_Overlays_Core_Overlays_YesNoBoxWidget_isShowing00);
     tolua_function(tolua_S,"setQuestion",tolua_Overlays_Core_Overlays_YesNoBoxWidget_setQuestion00);
    tolua_endmodule(tolua_S);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_Overlays (lua_State* tolua_S) {
 return tolua_Overlays_open(tolua_S);
};
#endif

#endif
#endif