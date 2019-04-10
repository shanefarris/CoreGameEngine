//#ifdef 1

#include "Overlays/MiniMap.h"
#include "CGameObjectManager.h"
#include "CPlayer.h"

#include "OgreOverlayManager.h"
#include "OgreOverlay.h"
#include "OgreSceneNode.h"
#include "OgreStringConverter.h"
#include "OgreOverlayElement.h"

using namespace Core;
using namespace Core::Overlays;

MiniMap::MiniMap(const char* Overlay, const char* OverlayImage)
{
	String overlay;
	String overlayImage;

	if(Overlay)
		overlay = Overlay;
	else
		overlay = "Core/MiniMap";

	if(OverlayImage)
		overlayImage = OverlayImage;
	else
		overlayImage = "Core/MiniMapImage";

	//Initiate the MiniMap
	mvpMiniMapLayer = OverlayManager::getSingleton().getByName(overlay);
	mvpMiniMapLayer->show();
	mvpMiniMap = OverlayManager::getSingleton().getOverlayElement(overlayImage); 
}

MiniMap::~MiniMap()
{
	CORE_DELETE(mvpMiniMapLayer);
	CORE_DELETE(mvpMiniMap);
}

void MiniMap::Update()
{
	f32 globalX = CGameObjectManager::Instance()->GetHumanPlayer()->GetPlayerNode()->getPosition().x;
	f32 globalZ = CGameObjectManager::Instance()->GetHumanPlayer()->GetPlayerNode()->getPosition().z;

	//In the future: Read World Size from the Settings class.
	#define WORLDSIZE 600

	//New coordinate system where x and z can have values between (-1) and (1).
	f32 x = (globalX) / (WORLDSIZE / 2);
	f32 z = (globalZ) / (WORLDSIZE / 2);

	#define MINIMAPWIDTH 0.24f
	/* On each side of the minimap there is 12% of the picture.
		________________________
	12% |	_________________   |
		|	|XXXXXXXXXXXXXXX|	|
	76%	|	|XXXXXXXXXXXXXXX|	|
		|	|XXXXXXXXXXXXXXX|	|
		|	|XXXXXXXXXXXXXXX|	|
	12%	|_______________________|
		12%        76%		 12%

	XXX = minimap
	the white space = black empty space on the minimap

	Scales the coordinate system so x and z can have values from (0) to (1-MINIMAPWIDTH=0.76)	*/
	x = (x + 1.0f) / (2.0f / (1.0f - MINIMAPWIDTH));
	z = (z + 1.0f) / (2.0f / (1.0f - MINIMAPWIDTH));

	//Set new UV coordinates on the minimap texture
	Ogre::Real uvXstart = 0.76f - z;
	Ogre::Real uvXend = uvXstart + 0.24f;
	Ogre::Real uvYstart = x;
	Ogre::Real uvYend = uvYstart + 0.24f;

	//Changes the UV coordinates of the MiniMap layer.
	Ogre::String value = Ogre::StringConverter::toString(uvXstart);
	value += " ";
	value += Ogre::StringConverter::toString(uvYstart);
	value += " ";
	value += Ogre::StringConverter::toString(uvXend);
	value += " ";
	value += Ogre::StringConverter::toString(uvYend);
	mvpMiniMap->setParameter("uv_coords" ,value );
}

//#endif