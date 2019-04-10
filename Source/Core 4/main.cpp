#include "CGame.h"
#include "CLevelGeneric.h"

#include "OgreException.h"

using namespace Core;

void LoadMaterials();

#ifdef WIN32
#define WIN32_LEAN_AND_MEAN
#include "windows.h"

INT WINAPI WinMain( HINSTANCE hInst, HINSTANCE, LPSTR strCmdLine, INT argc) 
{ 
	try 
	{
		Core::CGame game;
		game.AddGameState(new CLevelGeneric());
		LoadMaterials();
		game.Run();
	} 
	catch(Ogre::Exception& e) 
	{
		std::cerr << "An exception has occurred: " << e.what() << std::endl;
		MessageBox(NULL, e.what(), "An exception has occurred", MB_OK);
	}
	catch(...) 
	{
		std::cerr << "An exception has occurred" << std::endl;
		MessageBox(NULL, "Oops", "An exception has occurred", MB_OK);
	}
	return 0;
}

#endif

#include "OgreMaterialManager.h"
#include "OgreTechnique.h"

int main(int argc, char **argv)
{
	Core::CGame game;
	game.AddGameState(new CLevelGeneric());
	LoadMaterials();
	game.Run();

	return 0;
}

#include "OgreMaterialManager.h"
#include "OgreTechnique.h"

using namespace Ogre;

void LoadMaterials()
{
	MaterialPtr mat;
	Pass* pass = nullptr;
	Technique* tech = nullptr;
	TextureUnitState* tus = nullptr;

	// ============================ ak47_1 ============================================
	mat = MaterialManager::getSingleton().create("ak47_1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.00f, 0.00f, 0.00f, 10.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("ak47_1_uvw.dds");

	// ============================ mat_ammo_box_5_1 ============================================
	mat = MaterialManager::getSingleton().create("mat_ammo_box_5_1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("ammobox1.dds");
	tus->setNumMipmaps(-1);

	// ============================ hand_01 ============================================
	mat = MaterialManager::getSingleton().create("hand_01", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("hand_color.dds");

	// ============================ AppleGreenMat ============================================
	mat = MaterialManager::getSingleton().create("AppleGreenMat", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(60.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("applegreen_d.dds");

	// ============================ Genmarine ============================================
	mat = MaterialManager::getSingleton().create("Genmarine", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.00f, 0.00f, 0.00f, 128.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("marinediffmap.dds");
	tus->setTextureFiltering(FilterOptions::FO_POINT, FilterOptions::FO_POINT, FilterOptions::FO_POINT);

	// ============================ Genmarineglass ============================================
	mat = MaterialManager::getSingleton().create("Genmarineglass", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("marinediffmap.dds");

	// ============================ Assaultrifle ============================================
	mat = MaterialManager::getSingleton().create("Assaultrifle", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.00f, 0.00f, 0.00f, 128.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("riflediff.dds");
	tus->setTextureFiltering(FilterOptions::FO_POINT, FilterOptions::FO_POINT, FilterOptions::FO_POINT);

	// ============================ castle_sectionized_lwo#4 ============================================
	mat = MaterialManager::getSingleton().create("castle_sectionized_lwo#4", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("f2_win_d.dds");

	// ============================ castle_sectionized_lwo#3 ============================================
	mat = MaterialManager::getSingleton().create("castle_sectionized_lwo#3", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("curtains.dds");

	// ============================ castle_sectionized_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("castle_sectionized_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("f2_h1.dds");

	// ============================ castle_sectionized_lwo#1 ============================================
	mat = MaterialManager::getSingleton().create("castle_sectionized_lwo#1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("f2_h2.dds");

	// ============================ castle_sectionized_lwo#2 ============================================
	mat = MaterialManager::getSingleton().create("castle_sectionized_lwo#2", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("ivy1_df.dds");

	// ============================ AppleRedMat ============================================
	mat = MaterialManager::getSingleton().create("AppleRedMat", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(50.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("applered_d.dds");

	// ============================ ArmyColt1 ============================================
	mat = MaterialManager::getSingleton().create("ArmyColt1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("armycolt.dds");
	tus->setNumMipmaps(-1);

	// ============================ Barrel_1_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("Barrel_1_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("metalbase_d.dds");

	// ============================ Barrel_1_lwo#1 ============================================
	mat = MaterialManager::getSingleton().create("Barrel_1_lwo#1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodplanks_d.dds");

	// ============================ Barrel_1_lwo#2 ============================================
	mat = MaterialManager::getSingleton().create("Barrel_1_lwo#2", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("wooddetail2_d.dds");

	// ============================ Barrel_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("Barrel_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("metalbase_d.dds");

	// ============================ Barrel_lwo#1 ============================================
	mat = MaterialManager::getSingleton().create("Barrel_lwo#1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodplanks_d.dds");

	// ============================ Barrel_lwo#2 ============================================
	mat = MaterialManager::getSingleton().create("Barrel_lwo#2", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("wooddetail2_d.dds");

	// ============================ barrel ============================================
	mat = MaterialManager::getSingleton().create("barrel", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.50f, 0.50f, 0.50f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.75f, 0.75f, 0.75f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.00f, 0.00f, 0.00f, 0.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("wilkob1.dds");
	tus->setTextureFiltering(FilterOptions::FO_POINT, FilterOptions::FO_POINT, FilterOptions::FO_POINT);

	// ============================ mat_barrel01_5_1 ============================================
	mat = MaterialManager::getSingleton().create("mat_barrel01_5_1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("barrel2.dds");
	tus->setNumMipmaps(-1);

	// ============================ wood_rough_01 ============================================
	mat = MaterialManager::getSingleton().create("wood_rough_01", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.71f, 0.71f, 0.71f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.00f, 0.00f, 0.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(80.0000f);
	mat->getTechnique(0)->getPass(0)->setSceneBlending(SBF_ONE, SBF_ONE_MINUS_SOURCE_ALPHA);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("wood_rough_01.dds");

	// ============================ berreta ============================================
	mat = MaterialManager::getSingleton().create("berreta", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.42f, 0.42f, 0.42f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(28.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("beretta_color.dds");

	// ============================ mat_container_b5 ============================================
	mat = MaterialManager::getSingleton().create("mat_container_b5", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("bigcontainer1.dds");

	// ============================ mat_containter_l ============================================
	mat = MaterialManager::getSingleton().create("mat_containter_l", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("bigcontainer2.dds");

	// ============================ metal_stripes_d ============================================
	mat = MaterialManager::getSingleton().create("metal_stripes_d", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193f);
	mat->getTechnique(0)->getPass(0)->setSceneBlending(SBF_ONE, SBF_ONE_MINUS_SOURCE_ALPHA);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("metal_stripes_d.dds");

	// ============================ metal01_d ============================================
	mat = MaterialManager::getSingleton().create("metal01_d", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("metal01_d.dds");

	// ============================ signs ============================================
	mat = MaterialManager::getSingleton().create("signs", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("signs.dds");

	// ============================ light_d ============================================
	mat = MaterialManager::getSingleton().create("light_d", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("light_d.dds");

	// ============================ FoodBowlSoupMat ============================================
	mat = MaterialManager::getSingleton().create("FoodBowlSoupMat", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.25f, 0.25f, 0.25f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(60.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("foodbowl1_d.dds");

	// ============================ mat_gratebox5_1 ============================================
	mat = MaterialManager::getSingleton().create("mat_gratebox5_1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("box1.dds");

	// ============================ con4 ============================================
	mat = MaterialManager::getSingleton().create("con4", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("con04_d.dds");

	// ============================ bricks01 ============================================
	mat = MaterialManager::getSingleton().create("bricks01", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("bricks01_d.dds");

	// ============================ wood1 ============================================
	mat = MaterialManager::getSingleton().create("wood1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("wood01_d.dds");

	// ============================ rust06 ============================================
	mat = MaterialManager::getSingleton().create("rust06", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("rust06_d.dds");

	// ============================ Material#0 ============================================
	mat = MaterialManager::getSingleton().create("Material#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.00f, 0.00f, 0.00f, 10.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("bush_1.dds");

	// ============================ Material#25 ============================================
	mat = MaterialManager::getSingleton().create("Material#25", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.00f, 0.00f, 0.00f, 10.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("bush_2.dds");

	// ============================ castle_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("castle_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("f2_h1.dds");

	// ============================ castle_lwo#1 ============================================
	mat = MaterialManager::getSingleton().create("castle_lwo#1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("f2_h2.dds");

	// ============================ castle_lwo#2 ============================================
	mat = MaterialManager::getSingleton().create("castle_lwo#2", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("f2_win_d.dds");

	// ============================ castle_lwo#3 ============================================
	mat = MaterialManager::getSingleton().create("castle_lwo#3", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("curtains.dds");

	// ============================ castle_lwo#4 ============================================
	mat = MaterialManager::getSingleton().create("castle_lwo#4", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("ivy1_df.dds");

	// ============================ castle_curtain_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("castle_curtain_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("curtains.dds");

	// ============================ castle_LOD1_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("castle_LOD1_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("f2_h1.dds");

	// ============================ castle_LOD1_lwo#1 ============================================
	mat = MaterialManager::getSingleton().create("castle_LOD1_lwo#1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("f2_h2.dds");

	// ============================ castle_LOD2_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("castle_LOD2_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("f2_h1.dds");

	// ============================ castle_LOD2_lwo#1 ============================================
	mat = MaterialManager::getSingleton().create("castle_LOD2_lwo#1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("f2_h2.dds");

	// ============================ cattail ============================================
	mat = MaterialManager::getSingleton().create("cattail", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.20f, 0.20f, 0.20f, 43.22f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	mat->getTechnique(0)->getPass(0)->setSceneBlending(SBT_TRANSPARENT_ALPHA);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("cattail_color.dds");

	// ============================ CellarEntrance_1_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("CellarEntrance_1_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("brickmessy_d.dds");

	// ============================ CellarEntrance_1_lwo#1 ============================================
	mat = MaterialManager::getSingleton().create("CellarEntrance_1_lwo#1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodplaindark_d.dds");

	// ============================ CellarEntrance_1_lwo#2 ============================================
	mat = MaterialManager::getSingleton().create("CellarEntrance_1_lwo#2", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodplain_d.dds");

	// ============================ CellarEntrance_1_lwo#3 ============================================
	mat = MaterialManager::getSingleton().create("CellarEntrance_1_lwo#3", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("wooddetail2_d.dds");

	// ============================ CellarEntrance_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("CellarEntrance_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("brickmessy_d.dds");

	// ============================ CellarEntrance_lwo#1 ============================================
	mat = MaterialManager::getSingleton().create("CellarEntrance_lwo#1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodplaindark_d.dds");

	// ============================ CellarEntrance_lwo#2 ============================================
	mat = MaterialManager::getSingleton().create("CellarEntrance_lwo#2", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodplain_d.dds");

	// ============================ CellarEntrance_lwo#3 ============================================
	mat = MaterialManager::getSingleton().create("CellarEntrance_lwo#3", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("wooddetail2_d.dds");

	// ============================ rust01_d ============================================
	mat = MaterialManager::getSingleton().create("rust01_d", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("rust01_d.dds");

	// ============================ clima_d ============================================
	mat = MaterialManager::getSingleton().create("clima_d", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("clima_d.dds");

	// ============================ Chimney1_1_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("Chimney1_1_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("brickold_d.dds");

	// ============================ Chimney1_1_lwo#1 ============================================
	mat = MaterialManager::getSingleton().create("Chimney1_1_lwo#1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("metalbase_d.dds");

	// ============================ Chimney1_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("Chimney1_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("brickold_d.dds");

	// ============================ Chimney1_lwo#1 ============================================
	mat = MaterialManager::getSingleton().create("Chimney1_lwo#1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("metalbase_d.dds");

	// ============================ Chimney2_1_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("Chimney2_1_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("brickmessy_d.dds");

	// ============================ Chimney2_1_lwo#1 ============================================
	mat = MaterialManager::getSingleton().create("Chimney2_1_lwo#1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("metalbase_d.dds");

	// ============================ Chimney2_1_lwo#2 ============================================
	mat = MaterialManager::getSingleton().create("Chimney2_1_lwo#2", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("rockrough_d.dds");

	// ============================ Chimney2_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("Chimney2_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("brickmessy_d.dds");

	// ============================ Chimney2_lwo#1 ============================================
	mat = MaterialManager::getSingleton().create("Chimney2_lwo#1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("metalbase_d.dds");

	// ============================ Chimney2_lwo#2 ============================================
	mat = MaterialManager::getSingleton().create("Chimney2_lwo#2", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("rockrough_d.dds");

	// ============================ Chimney3_1_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("Chimney3_1_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("brickold_d.dds");

	// ============================ Chimney3_1_lwo#1 ============================================
	mat = MaterialManager::getSingleton().create("Chimney3_1_lwo#1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("metalbase_d.dds");

	// ============================ Chimney3_1_lwo#2 ============================================
	mat = MaterialManager::getSingleton().create("Chimney3_1_lwo#2", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("rockrough_d.dds");

	// ============================ Chimney3_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("Chimney3_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("brickold_d.dds");

	// ============================ Chimney3_lwo#1 ============================================
	mat = MaterialManager::getSingleton().create("Chimney3_lwo#1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("metalbase_d.dds");

	// ============================ Chimney3_lwo#2 ============================================
	mat = MaterialManager::getSingleton().create("Chimney3_lwo#2", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("rockrough_d.dds");

	// ============================ Chimney4_1_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("Chimney4_1_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("metalbase_d.dds");

	// ============================ Chimney4_1_lwo#1 ============================================
	mat = MaterialManager::getSingleton().create("Chimney4_1_lwo#1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("rockrough_d.dds");

	// ============================ Chimney4_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("Chimney4_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("metalbase_d.dds");

	// ============================ Chimney4_lwo#1 ============================================
	mat = MaterialManager::getSingleton().create("Chimney4_lwo#1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("rockrough_d.dds");

	// ============================ ChimneyBase_1_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("ChimneyBase_1_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("brickold_d.dds");

	// ============================ ChimneyBase_1_lwo#1 ============================================
	mat = MaterialManager::getSingleton().create("ChimneyBase_1_lwo#1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("brickmessy_d.dds");

	// ============================ ChimneyBase_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("ChimneyBase_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("brickold_d.dds");

	// ============================ ChimneyBase_lwo#1 ============================================
	mat = MaterialManager::getSingleton().create("ChimneyBase_lwo#1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("brickmessy_d.dds");

	// ============================ Material#5 ============================================
	mat = MaterialManager::getSingleton().create("Material#5", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.00f, 0.00f, 0.00f, 10.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("concrete.dds");

	// ============================ Material#4 ============================================
	mat = MaterialManager::getSingleton().create("Material#4", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.00f, 0.00f, 0.00f, 10.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("wood.dds");

	// ============================ mat_woodbox_5_1 ============================================
	mat = MaterialManager::getSingleton().create("mat_woodbox_5_1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("crate2.dds");

	// ============================ crate ============================================
	mat = MaterialManager::getSingleton().create("crate", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.50f, 0.50f, 0.50f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.75f, 0.75f, 0.75f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.00f, 0.00f, 0.00f, 0.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("wilkoc1.dds");
	tus->setTextureFiltering(FilterOptions::FO_POINT, FilterOptions::FO_POINT, FilterOptions::FO_POINT);

	// ============================ mat_woodbox4_5_1 ============================================
	mat = MaterialManager::getSingleton().create("mat_woodbox4_5_1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("crate3.dds");

	// ============================ CrateLong_1_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("CrateLong_1_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodcrates_d.dds");

	// ============================ CrateLong_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("CrateLong_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodcrates_d.dds");

	// ============================ CrateLongB_1_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("CrateLongB_1_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodcrates_d.dds");

	// ============================ CrateLongB_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("CrateLongB_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodcrates_d.dds");

	// ============================ CrateSquare_1_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("CrateSquare_1_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodcrates_d.dds");

	// ============================ CrateSquare_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("CrateSquare_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodcrates_d.dds");

	// ============================ CrateSquareB_1_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("CrateSquareB_1_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodcrates_d.dds");

	// ============================ CrateSquareB_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("CrateSquareB_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodcrates_d.dds");

	// ============================ road_village ============================================
	mat = MaterialManager::getSingleton().create("road_village", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(80.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("road_village.dds");

	// ============================ DoorStone_1_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("DoorStone_1_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("rockrough_d.dds");

	// ============================ DoorStone_1_lwo#1 ============================================
	mat = MaterialManager::getSingleton().create("DoorStone_1_lwo#1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("wooddetail2_d.dds");

	// ============================ DoorStone_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("DoorStone_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("rockrough_d.dds");

	// ============================ DoorStone_lwo#1 ============================================
	mat = MaterialManager::getSingleton().create("DoorStone_lwo#1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("wooddetail2_d.dds");

	// ============================ DoorStoneLarge_1_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("DoorStoneLarge_1_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("rockrough_d.dds");

	// ============================ DoorStoneLarge_1_lwo#1 ============================================
	mat = MaterialManager::getSingleton().create("DoorStoneLarge_1_lwo#1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("wooddetail2_d.dds");

	// ============================ DoorStoneLarge_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("DoorStoneLarge_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodplaindark_d.dds");

	// ============================ DoorStoneLarge_lwo#1 ============================================
	mat = MaterialManager::getSingleton().create("DoorStoneLarge_lwo#1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("rockrough_d.dds");

	// ============================ DoorStoneLarge_lwo#2 ============================================
	mat = MaterialManager::getSingleton().create("DoorStoneLarge_lwo#2", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("wooddetail2_d.dds");

	// ============================ DoorWood_1_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("DoorWood_1_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodplaindark_d.dds");

	// ============================ DoorWood_1_lwo#1 ============================================
	mat = MaterialManager::getSingleton().create("DoorWood_1_lwo#1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodplain_d.dds");

	// ============================ DoorWood_1_lwo#2 ============================================
	mat = MaterialManager::getSingleton().create("DoorWood_1_lwo#2", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("wooddetail2_d.dds");

	// ============================ DoorWood_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("DoorWood_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodplaindark_d.dds");

	// ============================ DoorWood_lwo#1 ============================================
	mat = MaterialManager::getSingleton().create("DoorWood_lwo#1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodplain_d.dds");

	// ============================ DoorWood_lwo#2 ============================================
	mat = MaterialManager::getSingleton().create("DoorWood_lwo#2", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("wooddetail2_d.dds");

	// ============================ Material ============================================
	mat = MaterialManager::getSingleton().create("Material", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(40.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("electric_box.dds");

	// ============================ con01_d ============================================
	mat = MaterialManager::getSingleton().create("con01_d", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("con01_d.dds");

	// ============================ metal5 ============================================
	mat = MaterialManager::getSingleton().create("metal5", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193f);
	mat->getTechnique(0)->getPass(0)->setSceneBlending(SBF_ONE, SBF_ONE_MINUS_SOURCE_ALPHA);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("metal5_d.dds");

	// ============================ ElevatorBeam_1_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("ElevatorBeam_1_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("metalbase_d.dds");

	// ============================ ElevatorBeam_1_lwo#1 ============================================
	mat = MaterialManager::getSingleton().create("ElevatorBeam_1_lwo#1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodplain_d.dds");

	// ============================ ElevatorBeam_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("ElevatorBeam_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("metalbase_d.dds");

	// ============================ ElevatorBeam_lwo#1 ============================================
	mat = MaterialManager::getSingleton().create("ElevatorBeam_lwo#1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodplain_d.dds");

	// ============================ FoodBowlMat ============================================
	mat = MaterialManager::getSingleton().create("FoodBowlMat", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(50.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("foodbowl0_d.dds");

	// ============================ sign ============================================
	mat = MaterialManager::getSingleton().create("sign", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("signs.dds");

	// ============================ wire_d ============================================
	mat = MaterialManager::getSingleton().create("wire_d", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193f);
	mat->getTechnique(0)->getPass(0)->setSceneBlending(SBF_ONE, SBF_ONE_MINUS_SOURCE_ALPHA);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("wire01_d.dds");

	// ============================ fence_wire ============================================
	mat = MaterialManager::getSingleton().create("fence_wire", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193f);
	mat->getTechnique(0)->getPass(0)->setSceneBlending(SBF_ONE, SBF_ONE_MINUS_SOURCE_ALPHA);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("fence_wire_d.dds");

	// ============================ rust03_d ============================================
	mat = MaterialManager::getSingleton().create("rust03_d", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("rust03_d.dds");

	// ============================ FirstAid1 ============================================
	mat = MaterialManager::getSingleton().create("FirstAid1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.00f, 0.00f, 0.00f, 10.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("firstaidboxtexture.dds");

	// ============================ _flower1blossom1 ============================================
	mat = MaterialManager::getSingleton().create("_flower1blossom1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.78f, 0.78f, 0.78f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.78f, 0.78f, 0.78f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSceneBlending(SBT_TRANSPARENT_ALPHA);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("blossom1.dds");

	// ============================ _flower1Leaf33 ============================================
	mat = MaterialManager::getSingleton().create("_flower1Leaf33", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("leaf33.dds");

	// ============================ flowerplant ============================================
	mat = MaterialManager::getSingleton().create("flowerplant", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.20f, 0.20f, 0.20f, 43.22f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	mat->getTechnique(0)->getPass(0)->setSceneBlending(SBT_TRANSPARENT_ALPHA);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("flowerplant_color.dds");

	// ============================ flowerplant2 ============================================
	mat = MaterialManager::getSingleton().create("flowerplant2", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.20f, 0.20f, 0.20f, 43.22f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	mat->getTechnique(0)->getPass(0)->setSceneBlending(SBT_TRANSPARENT_ALPHA);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("flowerplant2_color.dds");

	// ============================ flowerplant3 ============================================
	mat = MaterialManager::getSingleton().create("flowerplant3", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.20f, 0.20f, 0.20f, 43.22f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	mat->getTechnique(0)->getPass(0)->setSceneBlending(SBT_TRANSPARENT_ALPHA);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("flowerplant3_color.dds");

	// ============================ CutleryMat ============================================
	mat = MaterialManager::getSingleton().create("CutleryMat", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(45.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("cutlery_d.dds");

	// ============================ FryingPanMat ============================================
	mat = MaterialManager::getSingleton().create("FryingPanMat", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(45.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("fryingpan_d.dds");

	// ============================ con1 ============================================
	mat = MaterialManager::getSingleton().create("con1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("con01_d.dds");

	// ============================ rusty2 ============================================
	mat = MaterialManager::getSingleton().create("rusty2", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("rust02_d.dds");

	// ============================ h9 ============================================
	mat = MaterialManager::getSingleton().create("h9", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(40.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("h9.dds");

	// ============================ GlassMat ============================================
	mat = MaterialManager::getSingleton().create("GlassMat", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(40.0000f);
	mat->getTechnique(0)->getPass(0)->setSceneBlending(SBF_ONE, SBF_ONE_MINUS_SOURCE_ALPHA);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("glass1_d.dds");

	// ============================ metalplates ============================================
	mat = MaterialManager::getSingleton().create("metalplates", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193f);
	mat->getTechnique(0)->getPass(0)->setSceneBlending(SBF_ONE, SBF_ONE_MINUS_SOURCE_ALPHA);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("metalplates_d.dds");

	// ============================ floor03_d ============================================
	mat = MaterialManager::getSingleton().create("floor03_d", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("floor03_d.dds");

	// ============================ rust02_d ============================================
	mat = MaterialManager::getSingleton().create("rust02_d", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("rust02_d.dds");

	// ============================ door04_d ============================================
	mat = MaterialManager::getSingleton().create("door04_d", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("door04_d.dds");

	// ============================ cable_d ============================================
	mat = MaterialManager::getSingleton().create("cable_d", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("cable_d.dds");

	// ============================ roof01_d ============================================
	mat = MaterialManager::getSingleton().create("roof01_d", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("roof01_d.dds");

	// ============================ con2 ============================================
	mat = MaterialManager::getSingleton().create("con2", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193f);
	mat->getTechnique(0)->getPass(0)->setSceneBlending(SBF_ONE, SBF_ONE_MINUS_SOURCE_ALPHA);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("con02_d.dds");

	// ============================ door1 ============================================
	mat = MaterialManager::getSingleton().create("door1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("door01_d.dds");

	// ============================ bricks3 ============================================
	mat = MaterialManager::getSingleton().create("bricks3", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("bricks03_d.dds");

	// ============================ door7 ============================================
	mat = MaterialManager::getSingleton().create("door7", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193f);
	mat->getTechnique(0)->getPass(0)->setSceneBlending(SBF_ONE, SBF_ONE_MINUS_SOURCE_ALPHA);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("door07_d.dds");

	// ============================ con05 ============================================
	mat = MaterialManager::getSingleton().create("con05", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193f);
	mat->getTechnique(0)->getPass(0)->setSceneBlending(SBF_ONE, SBF_ONE_MINUS_SOURCE_ALPHA);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("con05_d.dds");

	// ============================ door04 ============================================
	mat = MaterialManager::getSingleton().create("door04", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("door04_d.dds");

	// ============================ roof1 ============================================
	mat = MaterialManager::getSingleton().create("roof1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("roof01_d.dds");

	// ============================ door07 ============================================
	mat = MaterialManager::getSingleton().create("door07", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193f);
	mat->getTechnique(0)->getPass(0)->setSceneBlending(SBF_ONE, SBF_ONE_MINUS_SOURCE_ALPHA);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("door07_d.dds");

	// ============================ rusty07 ============================================
	mat = MaterialManager::getSingleton().create("rusty07", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("rust07_d.dds");

	// ============================ floor1 ============================================
	mat = MaterialManager::getSingleton().create("floor1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("floor01_d.dds");

	// ============================ win01 ============================================
	mat = MaterialManager::getSingleton().create("win01", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("win01_d.dds");

	// ============================ door6 ============================================
	mat = MaterialManager::getSingleton().create("door6", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("door06_d.dds");

	// ============================ bricks03 ============================================
	mat = MaterialManager::getSingleton().create("bricks03", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("bricks01_d.dds");

	// ============================ HouseAttic_1_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("HouseAttic_1_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("plasterold_d.dds");

	// ============================ HouseAttic_1_lwo#1 ============================================
	mat = MaterialManager::getSingleton().create("HouseAttic_1_lwo#1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodbars_d.dds");

	// ============================ HouseAttic_1_lwo#2 ============================================
	mat = MaterialManager::getSingleton().create("HouseAttic_1_lwo#2", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("rooftilesold_d.dds");

	// ============================ HouseAttic_1_lwo#3 ============================================
	mat = MaterialManager::getSingleton().create("HouseAttic_1_lwo#3", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodplaindark_d.dds");

	// ============================ HouseAttic_1_lwo#4 ============================================
	mat = MaterialManager::getSingleton().create("HouseAttic_1_lwo#4", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodplain_d.dds");

	// ============================ HouseAttic_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("HouseAttic_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("plasterold_d.dds");

	// ============================ HouseAttic_lwo#1 ============================================
	mat = MaterialManager::getSingleton().create("HouseAttic_lwo#1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodbars_d.dds");

	// ============================ HouseAttic_lwo#2 ============================================
	mat = MaterialManager::getSingleton().create("HouseAttic_lwo#2", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("rooftilesold_d.dds");

	// ============================ HouseAttic_lwo#3 ============================================
	mat = MaterialManager::getSingleton().create("HouseAttic_lwo#3", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodplaindark_d.dds");

	// ============================ HouseAttic_lwo#4 ============================================
	mat = MaterialManager::getSingleton().create("HouseAttic_lwo#4", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodplain_d.dds");

	// ============================ HouseAtticSmall_1_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("HouseAtticSmall_1_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("plasterold_d.dds");

	// ============================ HouseAtticSmall_1_lwo#1 ============================================
	mat = MaterialManager::getSingleton().create("HouseAtticSmall_1_lwo#1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodbars_d.dds");

	// ============================ HouseAtticSmall_1_lwo#2 ============================================
	mat = MaterialManager::getSingleton().create("HouseAtticSmall_1_lwo#2", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("rooftilesold_d.dds");

	// ============================ HouseAtticSmall_1_lwo#3 ============================================
	mat = MaterialManager::getSingleton().create("HouseAtticSmall_1_lwo#3", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodplaindark_d.dds");

	// ============================ HouseAtticSmall_1_lwo#4 ============================================
	mat = MaterialManager::getSingleton().create("HouseAtticSmall_1_lwo#4", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodplain_d.dds");

	// ============================ HouseAtticSmall_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("HouseAtticSmall_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("plasterold_d.dds");

	// ============================ HouseAtticSmall_lwo#1 ============================================
	mat = MaterialManager::getSingleton().create("HouseAtticSmall_lwo#1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodbars_d.dds");

	// ============================ HouseAtticSmall_lwo#2 ============================================
	mat = MaterialManager::getSingleton().create("HouseAtticSmall_lwo#2", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("rooftilesold_d.dds");

	// ============================ HouseAtticSmall_lwo#3 ============================================
	mat = MaterialManager::getSingleton().create("HouseAtticSmall_lwo#3", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodplaindark_d.dds");

	// ============================ HouseAtticSmall_lwo#4 ============================================
	mat = MaterialManager::getSingleton().create("HouseAtticSmall_lwo#4", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodplain_d.dds");

	// ============================ HouseBricksLarge_1_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("HouseBricksLarge_1_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("brickold_d.dds");

	// ============================ HouseBricksLarge_1_lwo#1 ============================================
	mat = MaterialManager::getSingleton().create("HouseBricksLarge_1_lwo#1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("brickmessy_d.dds");

	// ============================ HouseBricksLarge_1_lwo#2 ============================================
	mat = MaterialManager::getSingleton().create("HouseBricksLarge_1_lwo#2", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("plasterold_d.dds");

	// ============================ HouseBricksLarge_1_lwo#3 ============================================
	mat = MaterialManager::getSingleton().create("HouseBricksLarge_1_lwo#3", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodbars_d.dds");

	// ============================ HouseBricksLarge_1_lwo#4 ============================================
	mat = MaterialManager::getSingleton().create("HouseBricksLarge_1_lwo#4", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("rooftilesold_d.dds");

	// ============================ HouseBricksLarge_1_lwo#5 ============================================
	mat = MaterialManager::getSingleton().create("HouseBricksLarge_1_lwo#5", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodplain_d.dds");

	// ============================ HouseBricksLarge_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("HouseBricksLarge_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("brickold_d.dds");

	// ============================ HouseBricksLarge_lwo#1 ============================================
	mat = MaterialManager::getSingleton().create("HouseBricksLarge_lwo#1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("brickmessy_d.dds");

	// ============================ HouseBricksLarge_lwo#2 ============================================
	mat = MaterialManager::getSingleton().create("HouseBricksLarge_lwo#2", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("plasterold_d.dds");

	// ============================ HouseBricksLarge_lwo#3 ============================================
	mat = MaterialManager::getSingleton().create("HouseBricksLarge_lwo#3", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodbars_d.dds");

	// ============================ HouseBricksLarge_lwo#4 ============================================
	mat = MaterialManager::getSingleton().create("HouseBricksLarge_lwo#4", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("rooftilesold_d.dds");

	// ============================ HouseBricksLarge_lwo#5 ============================================
	mat = MaterialManager::getSingleton().create("HouseBricksLarge_lwo#5", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodplain_d.dds");

	// ============================ HouseBricksNormal_1_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("HouseBricksNormal_1_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("brickold_d.dds");

	// ============================ HouseBricksNormal_1_lwo#1 ============================================
	mat = MaterialManager::getSingleton().create("HouseBricksNormal_1_lwo#1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("brickmessy_d.dds");

	// ============================ HouseBricksNormal_1_lwo#2 ============================================
	mat = MaterialManager::getSingleton().create("HouseBricksNormal_1_lwo#2", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("plasterold_d.dds");

	// ============================ HouseBricksNormal_1_lwo#3 ============================================
	mat = MaterialManager::getSingleton().create("HouseBricksNormal_1_lwo#3", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodbars_d.dds");

	// ============================ HouseBricksNormal_1_lwo#4 ============================================
	mat = MaterialManager::getSingleton().create("HouseBricksNormal_1_lwo#4", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("rooftilesold_d.dds");

	// ============================ HouseBricksNormal_1_lwo#5 ============================================
	mat = MaterialManager::getSingleton().create("HouseBricksNormal_1_lwo#5", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodplaindark_d.dds");

	// ============================ HouseBricksNormal_1_lwo#6 ============================================
	mat = MaterialManager::getSingleton().create("HouseBricksNormal_1_lwo#6", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodplain_d.dds");

	// ============================ HouseBricksNormal_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("HouseBricksNormal_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("brickold_d.dds");

	// ============================ HouseBricksNormal_lwo#1 ============================================
	mat = MaterialManager::getSingleton().create("HouseBricksNormal_lwo#1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("brickmessy_d.dds");

	// ============================ HouseBricksNormal_lwo#2 ============================================
	mat = MaterialManager::getSingleton().create("HouseBricksNormal_lwo#2", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("plasterold_d.dds");

	// ============================ HouseBricksNormal_lwo#3 ============================================
	mat = MaterialManager::getSingleton().create("HouseBricksNormal_lwo#3", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodbars_d.dds");

	// ============================ HouseBricksNormal_lwo#4 ============================================
	mat = MaterialManager::getSingleton().create("HouseBricksNormal_lwo#4", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("rooftilesold_d.dds");

	// ============================ HouseBricksNormal_lwo#5 ============================================
	mat = MaterialManager::getSingleton().create("HouseBricksNormal_lwo#5", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodplaindark_d.dds");

	// ============================ HouseBricksNormal_lwo#6 ============================================
	mat = MaterialManager::getSingleton().create("HouseBricksNormal_lwo#6", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodplain_d.dds");

	// ============================ HouseBricksThin_1_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("HouseBricksThin_1_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("brickold_d.dds");

	// ============================ HouseBricksThin_1_lwo#1 ============================================
	mat = MaterialManager::getSingleton().create("HouseBricksThin_1_lwo#1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("brickmessy_d.dds");

	// ============================ HouseBricksThin_1_lwo#2 ============================================
	mat = MaterialManager::getSingleton().create("HouseBricksThin_1_lwo#2", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("plasterold_d.dds");

	// ============================ HouseBricksThin_1_lwo#3 ============================================
	mat = MaterialManager::getSingleton().create("HouseBricksThin_1_lwo#3", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodbars_d.dds");

	// ============================ HouseBricksThin_1_lwo#4 ============================================
	mat = MaterialManager::getSingleton().create("HouseBricksThin_1_lwo#4", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("rooftilesold_d.dds");

	// ============================ HouseBricksThin_1_lwo#5 ============================================
	mat = MaterialManager::getSingleton().create("HouseBricksThin_1_lwo#5", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodplaindark_d.dds");

	// ============================ HouseBricksThin_1_lwo#6 ============================================
	mat = MaterialManager::getSingleton().create("HouseBricksThin_1_lwo#6", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodplain_d.dds");

	// ============================ HouseBricksThin_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("HouseBricksThin_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("brickold_d.dds");

	// ============================ HouseBricksThin_lwo#1 ============================================
	mat = MaterialManager::getSingleton().create("HouseBricksThin_lwo#1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("brickmessy_d.dds");

	// ============================ HouseBricksThin_lwo#2 ============================================
	mat = MaterialManager::getSingleton().create("HouseBricksThin_lwo#2", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("plasterold_d.dds");

	// ============================ HouseBricksThin_lwo#3 ============================================
	mat = MaterialManager::getSingleton().create("HouseBricksThin_lwo#3", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodbars_d.dds");

	// ============================ HouseBricksThin_lwo#4 ============================================
	mat = MaterialManager::getSingleton().create("HouseBricksThin_lwo#4", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("rooftilesold_d.dds");

	// ============================ HouseBricksThin_lwo#5 ============================================
	mat = MaterialManager::getSingleton().create("HouseBricksThin_lwo#5", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodplaindark_d.dds");

	// ============================ HouseBricksThin_lwo#6 ============================================
	mat = MaterialManager::getSingleton().create("HouseBricksThin_lwo#6", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodplain_d.dds");

	// ============================ HouseExtensionRoof_1_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("HouseExtensionRoof_1_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("plasterold_d.dds");

	// ============================ HouseExtensionRoof_1_lwo#1 ============================================
	mat = MaterialManager::getSingleton().create("HouseExtensionRoof_1_lwo#1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodbars_d.dds");

	// ============================ HouseExtensionRoof_1_lwo#2 ============================================
	mat = MaterialManager::getSingleton().create("HouseExtensionRoof_1_lwo#2", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("rooftilesold_d.dds");

	// ============================ HouseExtensionRoof_1_lwo#3 ============================================
	mat = MaterialManager::getSingleton().create("HouseExtensionRoof_1_lwo#3", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodplain_d.dds");

	// ============================ HouseExtensionRoof_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("HouseExtensionRoof_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("plasterold_d.dds");

	// ============================ HouseExtensionRoof_lwo#1 ============================================
	mat = MaterialManager::getSingleton().create("HouseExtensionRoof_lwo#1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodbars_d.dds");

	// ============================ HouseExtensionRoof_lwo#2 ============================================
	mat = MaterialManager::getSingleton().create("HouseExtensionRoof_lwo#2", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("rooftilesold_d.dds");

	// ============================ HouseExtensionRoof_lwo#3 ============================================
	mat = MaterialManager::getSingleton().create("HouseExtensionRoof_lwo#3", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodplain_d.dds");

	// ============================ HouseStuccoNormal_1_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("HouseStuccoNormal_1_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("brickmessy_d.dds");

	// ============================ HouseStuccoNormal_1_lwo#1 ============================================
	mat = MaterialManager::getSingleton().create("HouseStuccoNormal_1_lwo#1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("plasterold_d.dds");

	// ============================ HouseStuccoNormal_1_lwo#2 ============================================
	mat = MaterialManager::getSingleton().create("HouseStuccoNormal_1_lwo#2", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodbars_d.dds");

	// ============================ HouseStuccoNormal_1_lwo#3 ============================================
	mat = MaterialManager::getSingleton().create("HouseStuccoNormal_1_lwo#3", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("rooftilesold_d.dds");

	// ============================ HouseStuccoNormal_1_lwo#4 ============================================
	mat = MaterialManager::getSingleton().create("HouseStuccoNormal_1_lwo#4", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodplaindark_d.dds");

	// ============================ HouseStuccoNormal_1_lwo#5 ============================================
	mat = MaterialManager::getSingleton().create("HouseStuccoNormal_1_lwo#5", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodplain_d.dds");

	// ============================ HouseStuccoNormal_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("HouseStuccoNormal_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("brickmessy_d.dds");

	// ============================ HouseStuccoNormal_lwo#1 ============================================
	mat = MaterialManager::getSingleton().create("HouseStuccoNormal_lwo#1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("plasterold_d.dds");

	// ============================ HouseStuccoNormal_lwo#2 ============================================
	mat = MaterialManager::getSingleton().create("HouseStuccoNormal_lwo#2", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodbars_d.dds");

	// ============================ HouseStuccoNormal_lwo#3 ============================================
	mat = MaterialManager::getSingleton().create("HouseStuccoNormal_lwo#3", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("rooftilesold_d.dds");

	// ============================ HouseStuccoNormal_lwo#4 ============================================
	mat = MaterialManager::getSingleton().create("HouseStuccoNormal_lwo#4", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodplaindark_d.dds");

	// ============================ HouseStuccoNormal_lwo#5 ============================================
	mat = MaterialManager::getSingleton().create("HouseStuccoNormal_lwo#5", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodplain_d.dds");

	// ============================ HouseTower_1_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("HouseTower_1_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("plasterold_d.dds");

	// ============================ HouseTower_1_lwo#1 ============================================
	mat = MaterialManager::getSingleton().create("HouseTower_1_lwo#1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodbars_d.dds");

	// ============================ HouseTower_1_lwo#2 ============================================
	mat = MaterialManager::getSingleton().create("HouseTower_1_lwo#2", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("rooftilesold_d.dds");

	// ============================ HouseTower_1_lwo#3 ============================================
	mat = MaterialManager::getSingleton().create("HouseTower_1_lwo#3", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodplanks_d.dds");

	// ============================ HouseTower_1_lwo#4 ============================================
	mat = MaterialManager::getSingleton().create("HouseTower_1_lwo#4", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodplaindark_d.dds");

	// ============================ HouseTower_1_lwo#5 ============================================
	mat = MaterialManager::getSingleton().create("HouseTower_1_lwo#5", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodplain_d.dds");

	// ============================ HouseTower_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("HouseTower_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("plasterold_d.dds");

	// ============================ HouseTower_lwo#1 ============================================
	mat = MaterialManager::getSingleton().create("HouseTower_lwo#1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodbars_d.dds");

	// ============================ HouseTower_lwo#2 ============================================
	mat = MaterialManager::getSingleton().create("HouseTower_lwo#2", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("rooftilesold_d.dds");

	// ============================ HouseTower_lwo#3 ============================================
	mat = MaterialManager::getSingleton().create("HouseTower_lwo#3", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodplanks_d.dds");

	// ============================ HouseTower_lwo#4 ============================================
	mat = MaterialManager::getSingleton().create("HouseTower_lwo#4", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodplaindark_d.dds");

	// ============================ HouseTower_lwo#5 ============================================
	mat = MaterialManager::getSingleton().create("HouseTower_lwo#5", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodplain_d.dds");

	// ============================ blinn1 ============================================
	mat = MaterialManager::getSingleton().create("blinn1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.00f, 0.00f, 0.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.50f, 0.50f, 0.50f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(113.1900f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("d_hqtent.dds");

	// ============================ humvee_1 ============================================
	mat = MaterialManager::getSingleton().create("humvee_1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.00f, 0.00f, 0.00f, 10.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("humvee_d2.dds");

	// ============================ orig_signfirelane_Smoothing ============================================
	mat = MaterialManager::getSingleton().create("orig_signfirelane_Smoothing", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.35f, 0.35f, 0.35f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(45.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("lamppost_diffuse.dds");

	// ============================ leaflarge ============================================
	mat = MaterialManager::getSingleton().create("leaflarge", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.20f, 0.20f, 0.20f, 43.22f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	mat->getTechnique(0)->getPass(0)->setSceneBlending(SBT_TRANSPARENT_ALPHA);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("leaflarge_color.dds");

	// ============================ leafplant2 ============================================
	mat = MaterialManager::getSingleton().create("leafplant2", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.20f, 0.20f, 0.20f, 43.22f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	mat->getTechnique(0)->getPass(0)->setSceneBlending(SBT_TRANSPARENT_ALPHA);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("leafplant2_color.dds");

	// ============================ leafplant2_purple ============================================
	mat = MaterialManager::getSingleton().create("leafplant2_purple", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.20f, 0.20f, 0.20f, 43.22f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	mat->getTechnique(0)->getPass(0)->setSceneBlending(SBT_TRANSPARENT_ALPHA);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("leafplant2_purple_color.dds");

	// ============================ leafplant3 ============================================
	mat = MaterialManager::getSingleton().create("leafplant3", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.20f, 0.20f, 0.20f, 43.22f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	mat->getTechnique(0)->getPass(0)->setSceneBlending(SBT_TRANSPARENT_ALPHA);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("leafplant3_color.dds");

	// ============================ leafplant4 ============================================
	mat = MaterialManager::getSingleton().create("leafplant4", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.20f, 0.20f, 0.20f, 43.22f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	mat->getTechnique(0)->getPass(0)->setSceneBlending(SBT_TRANSPARENT_ALPHA);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("leafplant4_color.dds");

	// ============================ LemonMat ============================================
	mat = MaterialManager::getSingleton().create("LemonMat", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(50.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("lemon_d.dds");

	// ============================ Standard_1 ============================================
	mat = MaterialManager::getSingleton().create("Standard_1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.00f, 0.00f, 0.00f, 10.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("oilbarrel_diffuseyellow.dds");

	// ============================ 03-Default ============================================
	mat = MaterialManager::getSingleton().create("03-Default", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.25f, 0.25f, 0.25f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.25f, 0.25f, 0.25f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.23f, 0.23f, 0.23f, 17.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);

	// ============================ 04-Default ============================================
	mat = MaterialManager::getSingleton().create("04-Default", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.34f, 0.34f, 0.34f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.34f, 0.34f, 0.34f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.00f, 0.00f, 0.00f, 10.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);

	// ============================ Examples/Ninja ============================================
	mat = MaterialManager::getSingleton().create("Examples/Ninja", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("nskingr.dds");

	// ============================ Note_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("Note_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("paperposters_d.dds");

	// ============================ Material#29 ============================================
	mat = MaterialManager::getSingleton().create("Material#29", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.00f, 0.00f, 0.00f, 10.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("oilpump.dds");

	// ============================ metal_leaking3 ============================================
	mat = MaterialManager::getSingleton().create("metal_leaking3", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("metal_leaking03.dds");

	// ============================ metal1 ============================================
	mat = MaterialManager::getSingleton().create("metal1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("metal01_d.dds");

	// ============================ floor3 ============================================
	mat = MaterialManager::getSingleton().create("floor3", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("floor03_d.dds");

	// ============================ rusty5 ============================================
	mat = MaterialManager::getSingleton().create("rusty5", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193f);
	mat->getTechnique(0)->getPass(0)->setSceneBlending(SBF_ONE, SBF_ONE_MINUS_SOURCE_ALPHA);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("rust05_d.dds");

	// ============================ con5 ============================================
	mat = MaterialManager::getSingleton().create("con5", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193f);
	mat->getTechnique(0)->getPass(0)->setSceneBlending(SBF_ONE, SBF_ONE_MINUS_SOURCE_ALPHA);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("con05_d.dds");

	// ============================ metal2 ============================================
	mat = MaterialManager::getSingleton().create("metal2", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193f);
	mat->getTechnique(0)->getPass(0)->setSceneBlending(SBF_ONE, SBF_ONE_MINUS_SOURCE_ALPHA);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("metal02_d.dds");

	// ============================ h1_copy ============================================
	mat = MaterialManager::getSingleton().create("h1_copy", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(80.0000f);
	mat->getTechnique(0)->getPass(0)->setSceneBlending(SBF_ONE, SBF_ONE_MINUS_SOURCE_ALPHA);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("h1_copy.dds");

	// ============================ h10 ============================================
	mat = MaterialManager::getSingleton().create("h10", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.02f, 0.02f, 0.02f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(40.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("h10.dds");

	// ============================ h11 ============================================
	mat = MaterialManager::getSingleton().create("h11", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(80.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("h11.dds");

	// ============================ h2 ============================================
	mat = MaterialManager::getSingleton().create("h2", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(40.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("h2.dds");

	// ============================ h3 ============================================
	mat = MaterialManager::getSingleton().create("h3", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(80.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("h3.dds");

	// ============================ h4 ============================================
	mat = MaterialManager::getSingleton().create("h4", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(40.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("h4.dds");

	// ============================ h5 ============================================
	mat = MaterialManager::getSingleton().create("h5", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.05f, 0.05f, 0.05f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(40.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("h5.dds");

	// ============================ h6 ============================================
	mat = MaterialManager::getSingleton().create("h6", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(40.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("h6.dds");

	// ============================ h7 ============================================
	mat = MaterialManager::getSingleton().create("h7", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(80.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("h7.dds");

	// ============================ h8 ============================================
	mat = MaterialManager::getSingleton().create("h8", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(80.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("h8.dds");

	// ============================ rust03 ============================================
	mat = MaterialManager::getSingleton().create("rust03", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("rust03_d.dds");

	// ============================ OrangeMat ============================================
	mat = MaterialManager::getSingleton().create("OrangeMat", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(50.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("orange_d.dds");

	// ============================ PlantA_1_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("PlantA_1_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("treebranch1_d.dds");

	// ============================ PlantA_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("PlantA_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("treebranch1_d.dds");

	// ============================ PlantB_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("PlantB_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("treeleaves_d.dds");

	// ============================ PlantB_lwo#1 ============================================
	mat = MaterialManager::getSingleton().create("PlantB_lwo#1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("treebranch1_d.dds");

	// ============================ PlantC_1_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("PlantC_1_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("planta_d.dds");

	// ============================ PlantC_2_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("PlantC_2_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("planta_d.dds");

	// ============================ PlantC_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("PlantC_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("planta_d.dds");

	// ============================ PlantD_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("PlantD_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("flowera_d.dds");

	// ============================ PlateMat ============================================
	mat = MaterialManager::getSingleton().create("PlateMat", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.90f, 0.90f, 0.90f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.70f, 0.70f, 0.70f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(50.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("plate_d.dds");

	// ============================ PosterBoard_1_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("PosterBoard_1_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodbars_d.dds");

	// ============================ PosterBoard_1_lwo#1 ============================================
	mat = MaterialManager::getSingleton().create("PosterBoard_1_lwo#1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodplanks_d.dds");

	// ============================ PosterBoard_1_lwo#2 ============================================
	mat = MaterialManager::getSingleton().create("PosterBoard_1_lwo#2", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodplaindark_d.dds");

	// ============================ PosterBoard_1_lwo#3 ============================================
	mat = MaterialManager::getSingleton().create("PosterBoard_1_lwo#3", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("paperposters_d.dds");

	// ============================ PosterBoard_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("PosterBoard_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodbars_d.dds");

	// ============================ PosterBoard_lwo#1 ============================================
	mat = MaterialManager::getSingleton().create("PosterBoard_lwo#1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodplanks_d.dds");

	// ============================ PosterBoard_lwo#2 ============================================
	mat = MaterialManager::getSingleton().create("PosterBoard_lwo#2", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodplaindark_d.dds");

	// ============================ PosterBoard_lwo#3 ============================================
	mat = MaterialManager::getSingleton().create("PosterBoard_lwo#3", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("paperposters_d.dds");

	// ============================ PosterBoard_lwo#4 ============================================
	mat = MaterialManager::getSingleton().create("PosterBoard_lwo#4", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodplain_d.dds");

	// ============================ Material__25 ============================================
	mat = MaterialManager::getSingleton().create("Material__25", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("texmap2.dds");

	// ============================ rust01 ============================================
	mat = MaterialManager::getSingleton().create("rust01", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("rust03_d.dds");

	// ============================ sas_torso ============================================
	mat = MaterialManager::getSingleton().create("sas_torso", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.00f, 0.00f, 0.00f, 10.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("sas_1_d2.dds");

	// ============================ sas_main ============================================
	mat = MaterialManager::getSingleton().create("sas_main", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.00f, 0.00f, 0.00f, 10.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);

	// ============================ SewerDrain_1_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("SewerDrain_1_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("metalbase_d.dds");

	// ============================ SewerDrain_1_lwo#1 ============================================
	mat = MaterialManager::getSingleton().create("SewerDrain_1_lwo#1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.00f, 0.00f, 0.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);

	// ============================ SewerDrain_1_lwo#2 ============================================
	mat = MaterialManager::getSingleton().create("SewerDrain_1_lwo#2", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("rockrough_d.dds");

	// ============================ SewerDrain_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("SewerDrain_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("metalbase_d.dds");

	// ============================ SewerDrain_lwo#1 ============================================
	mat = MaterialManager::getSingleton().create("SewerDrain_lwo#1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodplaindark_d.dds");

	// ============================ SewerDrain_lwo#2 ============================================
	mat = MaterialManager::getSingleton().create("SewerDrain_lwo#2", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("rockrough_d.dds");

	// ============================ Material#52 ============================================
	mat = MaterialManager::getSingleton().create("Material#52", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.00f, 0.00f, 0.00f, 10.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("wallandssrange_bk.dds");

	// ============================ ShootingRangeWall1 ============================================
	mat = MaterialManager::getSingleton().create("ShootingRangeWall1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.00f, 0.00f, 0.00f, 10.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("shootingrangewall1.dds");

	// ============================ ShopSign_1_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("ShopSign_1_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("metalbase_d.dds");

	// ============================ ShopSign_1_lwo#1 ============================================
	mat = MaterialManager::getSingleton().create("ShopSign_1_lwo#1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodplain_d.dds");

	// ============================ ShopSign_1_lwo#2 ============================================
	mat = MaterialManager::getSingleton().create("ShopSign_1_lwo#2", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("wooddetail1_d.dds");

	// ============================ ShopSign_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("ShopSign_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("metalbase_d.dds");

	// ============================ ShopSign_lwo#1 ============================================
	mat = MaterialManager::getSingleton().create("ShopSign_lwo#1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodplain_d.dds");

	// ============================ ShopSign_lwo#2 ============================================
	mat = MaterialManager::getSingleton().create("ShopSign_lwo#2", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("wooddetail1_d.dds");

	// ============================ SignPost_1_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("SignPost_1_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodbars_d.dds");

	// ============================ SignPost_1_lwo#1 ============================================
	mat = MaterialManager::getSingleton().create("SignPost_1_lwo#1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodplaindark_d.dds");

	// ============================ SignPost_1_lwo#2 ============================================
	mat = MaterialManager::getSingleton().create("SignPost_1_lwo#2", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("rockroughdetails_d.dds");

	// ============================ SignPost_1_lwo#3 ============================================
	mat = MaterialManager::getSingleton().create("SignPost_1_lwo#3", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("rockrough_d.dds");

	// ============================ SignPost_1_lwo#4 ============================================
	mat = MaterialManager::getSingleton().create("SignPost_1_lwo#4", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("wooddetail2_d.dds");

	// ============================ SignPost_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("SignPost_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodbars_d.dds");

	// ============================ SignPost_lwo#1 ============================================
	mat = MaterialManager::getSingleton().create("SignPost_lwo#1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodplaindark_d.dds");

	// ============================ SignPost_lwo#2 ============================================
	mat = MaterialManager::getSingleton().create("SignPost_lwo#2", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("rockroughdetails_d.dds");

	// ============================ SignPost_lwo#3 ============================================
	mat = MaterialManager::getSingleton().create("SignPost_lwo#3", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("rockrough_d.dds");

	// ============================ SignPost_lwo#4 ============================================
	mat = MaterialManager::getSingleton().create("SignPost_lwo#4", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("wooddetail2_d.dds");

	// ============================ metal03_d ============================================
	mat = MaterialManager::getSingleton().create("metal03_d", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("metal03_d.dds");

	// ============================ Soldierm4a1_OgreMax ============================================
	mat = MaterialManager::getSingleton().create("Soldierm4a1_OgreMax", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.00f, 0.00f, 0.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(10.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("m4a1.dds");
	tus->setTextureFiltering(FilterOptions::FO_LINEAR, FilterOptions::FO_LINEAR, FilterOptions::FO_LINEAR);

	// ============================ StaircaseLarge_1_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("StaircaseLarge_1_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("brickssmooth_d.dds");

	// ============================ StaircaseLarge_1_lwo#1 ============================================
	mat = MaterialManager::getSingleton().create("StaircaseLarge_1_lwo#1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("rockrough_d.dds");

	// ============================ StaircaseLarge_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("StaircaseLarge_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("brickssmooth_d.dds");

	// ============================ StaircaseLarge_lwo#1 ============================================
	mat = MaterialManager::getSingleton().create("StaircaseLarge_lwo#1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("rockrough_d.dds");

	// ============================ StaircaseMedium_1_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("StaircaseMedium_1_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("brickssmooth_d.dds");

	// ============================ StaircaseMedium_1_lwo#1 ============================================
	mat = MaterialManager::getSingleton().create("StaircaseMedium_1_lwo#1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("rockrough_d.dds");

	// ============================ StaircaseMedium_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("StaircaseMedium_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("brickssmooth_d.dds");

	// ============================ StaircaseMedium_lwo#1 ============================================
	mat = MaterialManager::getSingleton().create("StaircaseMedium_lwo#1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("rockrough_d.dds");

	// ============================ StaircaseSmall_1_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("StaircaseSmall_1_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("brickssmooth_d.dds");

	// ============================ StaircaseSmall_1_lwo#1 ============================================
	mat = MaterialManager::getSingleton().create("StaircaseSmall_1_lwo#1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("rockrough_d.dds");

	// ============================ StaircaseSmall_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("StaircaseSmall_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("brickssmooth_d.dds");

	// ============================ StaircaseSmall_lwo#1 ============================================
	mat = MaterialManager::getSingleton().create("StaircaseSmall_lwo#1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("rockrough_d.dds");

	// ============================ MeatSteakBurntMat ============================================
	mat = MaterialManager::getSingleton().create("MeatSteakBurntMat", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.30f, 0.30f, 0.30f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(50.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("meatsteakburnt_d.dds");

	// ============================ MeatSteakCookedMat ============================================
	mat = MaterialManager::getSingleton().create("MeatSteakCookedMat", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.30f, 0.30f, 0.30f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(70.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("meatsteakcooked_d.dds");

	// ============================ StoneWall1 ============================================
	mat = MaterialManager::getSingleton().create("StoneWall1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.00f, 0.00f, 0.00f, 10.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("r_wall1tex_d2.dds");

	// ============================ StoneWall2 ============================================
	mat = MaterialManager::getSingleton().create("StoneWall2", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.00f, 0.00f, 0.00f, 10.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("r_wall2tex_d2.dds");

	// ============================ StoneWall3 ============================================
	mat = MaterialManager::getSingleton().create("StoneWall3", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.00f, 0.00f, 0.00f, 10.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("r_wall3tex_d2.dds");

	// ============================ StoneWall4 ============================================
	mat = MaterialManager::getSingleton().create("StoneWall4", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.00f, 0.00f, 0.00f, 10.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("r_wall4tex_d2.dds");

	// ============================ StoneBench_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("StoneBench_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("rockroughdetails_d.dds");

	// ============================ StoneBench_lwo#1 ============================================
	mat = MaterialManager::getSingleton().create("StoneBench_lwo#1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("rockrough_d.dds");

	// ============================ StoneFence_1_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("StoneFence_1_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("rockroughdetails_d.dds");

	// ============================ StoneFence_1_lwo#1 ============================================
	mat = MaterialManager::getSingleton().create("StoneFence_1_lwo#1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("rockrough_d.dds");

	// ============================ StoneFence_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("StoneFence_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("rockroughdetails_d.dds");

	// ============================ StoneFence_lwo#1 ============================================
	mat = MaterialManager::getSingleton().create("StoneFence_lwo#1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("rockrough_d.dds");

	// ============================ StonePillar_1_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("StonePillar_1_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("brickold_d.dds");

	// ============================ StonePillar_1_lwo#1 ============================================
	mat = MaterialManager::getSingleton().create("StonePillar_1_lwo#1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("rockrough_d.dds");

	// ============================ StonePillar_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("StonePillar_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("brickold_d.dds");

	// ============================ StonePillar_lwo#1 ============================================
	mat = MaterialManager::getSingleton().create("StonePillar_lwo#1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("rockrough_d.dds");

	// ============================ StonePlatform_1_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("StonePlatform_1_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("brickssmooth_d.dds");

	// ============================ StonePlatform_1_lwo#1 ============================================
	mat = MaterialManager::getSingleton().create("StonePlatform_1_lwo#1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("rockrough_d.dds");

	// ============================ StonePlatform_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("StonePlatform_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("brickssmooth_d.dds");

	// ============================ StonePlatform_lwo#1 ============================================
	mat = MaterialManager::getSingleton().create("StonePlatform_lwo#1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("rockrough_d.dds");

	// ============================ StonePlatformArches_1_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("StonePlatformArches_1_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("brickold_d.dds");

	// ============================ StonePlatformArches_1_lwo#1 ============================================
	mat = MaterialManager::getSingleton().create("StonePlatformArches_1_lwo#1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("brickssmooth_d.dds");

	// ============================ StonePlatformArches_1_lwo#2 ============================================
	mat = MaterialManager::getSingleton().create("StonePlatformArches_1_lwo#2", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("rockrough_d.dds");

	// ============================ StonePlatformArches_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("StonePlatformArches_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("brickold_d.dds");

	// ============================ StonePlatformArches_lwo#1 ============================================
	mat = MaterialManager::getSingleton().create("StonePlatformArches_lwo#1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("brickssmooth_d.dds");

	// ============================ StonePlatformArches_lwo#2 ============================================
	mat = MaterialManager::getSingleton().create("StonePlatformArches_lwo#2", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("rockrough_d.dds");

	// ============================ StoneWall_1_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("StoneWall_1_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("brickold_d.dds");

	// ============================ StoneWall_1_lwo#1 ============================================
	mat = MaterialManager::getSingleton().create("StoneWall_1_lwo#1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("brickmessy_d.dds");

	// ============================ StoneWall_1_lwo#2 ============================================
	mat = MaterialManager::getSingleton().create("StoneWall_1_lwo#2", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("rockroughdetails_d.dds");

	// ============================ StoneWall_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("StoneWall_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("brickold_d.dds");

	// ============================ StoneWall_lwo#1 ============================================
	mat = MaterialManager::getSingleton().create("StoneWall_lwo#1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("brickmessy_d.dds");

	// ============================ StoneWall_lwo#2 ============================================
	mat = MaterialManager::getSingleton().create("StoneWall_lwo#2", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("rockroughdetails_d.dds");

	// ============================ StoneWall_lwo#3 ============================================
	mat = MaterialManager::getSingleton().create("StoneWall_lwo#3", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("rockrough_d.dds");

	// ============================ StreetLightSmall_1_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("StreetLightSmall_1_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("window1_d.dds");

	// ============================ StreetLightSmall_1_lwo#1 ============================================
	mat = MaterialManager::getSingleton().create("StreetLightSmall_1_lwo#1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("metalbase_d.dds");

	// ============================ StreetLightSmall_1_lwo#2 ============================================
	mat = MaterialManager::getSingleton().create("StreetLightSmall_1_lwo#2", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodplain_d.dds");

	// ============================ StreetLightSmall_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("StreetLightSmall_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("window1_d.dds");

	// ============================ StreetLightSmall_lwo#1 ============================================
	mat = MaterialManager::getSingleton().create("StreetLightSmall_lwo#1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("metalbase_d.dds");

	// ============================ StreetLightSmall_lwo#2 ============================================
	mat = MaterialManager::getSingleton().create("StreetLightSmall_lwo#2", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodplain_d.dds");

	// ============================ StreetLightTall_1_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("StreetLightTall_1_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("window1_d.dds");

	// ============================ StreetLightTall_1_lwo#1 ============================================
	mat = MaterialManager::getSingleton().create("StreetLightTall_1_lwo#1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("metalbase_d.dds");

	// ============================ StreetLightTall_1_lwo#2 ============================================
	mat = MaterialManager::getSingleton().create("StreetLightTall_1_lwo#2", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("rockroughdetails_d.dds");

	// ============================ StreetLightTall_1_lwo#3 ============================================
	mat = MaterialManager::getSingleton().create("StreetLightTall_1_lwo#3", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("rockrough_d.dds");

	// ============================ StreetLightTall_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("StreetLightTall_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("window1_d.dds");

	// ============================ StreetLightTall_lwo#1 ============================================
	mat = MaterialManager::getSingleton().create("StreetLightTall_lwo#1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("metalbase_d.dds");

	// ============================ StreetLightTall_lwo#2 ============================================
	mat = MaterialManager::getSingleton().create("StreetLightTall_lwo#2", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("rockroughdetails_d.dds");

	// ============================ StreetLightTall_lwo#3 ============================================
	mat = MaterialManager::getSingleton().create("StreetLightTall_lwo#3", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("rockrough_d.dds");

	// ============================ con02_d ============================================
	mat = MaterialManager::getSingleton().create("con02_d", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193f);
	mat->getTechnique(0)->getPass(0)->setSceneBlending(SBF_ONE, SBF_ONE_MINUS_SOURCE_ALPHA);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("con02_d.dds");

	// ============================ metal_leaking02 ============================================
	mat = MaterialManager::getSingleton().create("metal_leaking02", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193f);
	mat->getTechnique(0)->getPass(0)->setSceneBlending(SBF_ONE, SBF_ONE_MINUS_SOURCE_ALPHA);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("metal_leaking02_d.dds");

	// ============================ Material#41 ============================================
	mat = MaterialManager::getSingleton().create("Material#41", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.00f, 0.00f, 0.00f, 10.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("range2.dds");

	// ============================ tower ============================================
	mat = MaterialManager::getSingleton().create("tower", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(80.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("tower.dds");

	// ============================ metalstripes ============================================
	mat = MaterialManager::getSingleton().create("metalstripes", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193f);
	mat->getTechnique(0)->getPass(0)->setSceneBlending(SBF_ONE, SBF_ONE_MINUS_SOURCE_ALPHA);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("metal_stripes_d.dds");

	// ============================ metal_cylinder01_d ============================================
	mat = MaterialManager::getSingleton().create("metal_cylinder01_d", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193f);
	mat->getTechnique(0)->getPass(0)->setSceneBlending(SBF_ONE, SBF_ONE_MINUS_SOURCE_ALPHA);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("metal_cylinder01_d.dds");

	// ============================ train_d ============================================
	mat = MaterialManager::getSingleton().create("train_d", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("train_d.dds");

	// ============================ rails_d ============================================
	mat = MaterialManager::getSingleton().create("rails_d", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("rails_d.dds");

	// ============================ Tree_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("Tree_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("treeleaves_d.dds");

	// ============================ Tree_lwo#1 ============================================
	mat = MaterialManager::getSingleton().create("Tree_lwo#1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("treelarge_d.dds");

	// ============================ Tree_lwo#2 ============================================
	mat = MaterialManager::getSingleton().create("Tree_lwo#2", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("treebranch1_d.dds");

	// ============================ _tree1bigtreeDF1 ============================================
	mat = MaterialManager::getSingleton().create("_tree1bigtreeDF1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.05f, 0.05f, 0.05f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("bigtreedf1.dds");

	// ============================ _tree1bigtreeDF2 ============================================
	mat = MaterialManager::getSingleton().create("_tree1bigtreeDF2", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.05f, 0.05f, 0.05f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("bigtreedf2.dds");

	// ============================ _tree1Leaf_DF ============================================
	mat = MaterialManager::getSingleton().create("_tree1Leaf_DF", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSceneBlending(SBT_TRANSPARENT_ALPHA);
	mat->getTechnique(0)->getPass(0)->setAlphaRejectSettings(CompareFunction::CMPF_GREATER_EQUAL, 128);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("leaf_df.dds");

	// ============================ _tree2bigtreeDF1 ============================================
	mat = MaterialManager::getSingleton().create("_tree2bigtreeDF1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.05f, 0.05f, 0.05f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("bigtreedf1.dds");

	// ============================ _tree2bigtreeDF2 ============================================
	mat = MaterialManager::getSingleton().create("_tree2bigtreeDF2", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.05f, 0.05f, 0.05f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("bigtreedf2.dds");

	// ============================ _tree2Leaf_DF ============================================
	mat = MaterialManager::getSingleton().create("_tree2Leaf_DF", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSceneBlending(SBT_TRANSPARENT_ALPHA);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("leaf_df.dds");

	// ============================ _tree3bigtreeDF1 ============================================
	mat = MaterialManager::getSingleton().create("_tree3bigtreeDF1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.05f, 0.05f, 0.05f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("bigtreedf1.dds");

	// ============================ _tree3bigtreeDF2 ============================================
	mat = MaterialManager::getSingleton().create("_tree3bigtreeDF2", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.05f, 0.05f, 0.05f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("bigtreedf2.dds");

	// ============================ _tree3Leaf_DF ============================================
	mat = MaterialManager::getSingleton().create("_tree3Leaf_DF", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSceneBlending(SBT_TRANSPARENT_ALPHA);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("leaf_df.dds");

	// ============================ TreeLog_1_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("TreeLog_1_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("treelogs_d.dds");

	// ============================ TreeLog_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("TreeLog_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("treelogs_d.dds");

	// ============================ TreeLogPile_1_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("TreeLogPile_1_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("treelogs_d.dds");

	// ============================ TreeLogPile_2_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("TreeLogPile_2_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("treelogs_d.dds");

	// ============================ TreeLogPile_3_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("TreeLogPile_3_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("treelogs_d.dds");

	// ============================ TreeLogPile_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("TreeLogPile_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("treelogs_d.dds");

	// ============================ _veg1Leaf33 ============================================
	mat = MaterialManager::getSingleton().create("_veg1Leaf33", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("leaf33.dds");

	// ============================ _veg1_lod2Leaf33 ============================================
	mat = MaterialManager::getSingleton().create("_veg1_lod2Leaf33", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("leaf33.dds");

	// ============================ _veg10Palm2_trunk_DF ============================================
	mat = MaterialManager::getSingleton().create("_veg10Palm2_trunk_DF", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("palm2_trunk_df.dds");

	// ============================ _veg10palmleaf1_df ============================================
	mat = MaterialManager::getSingleton().create("_veg10palmleaf1_df", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSceneBlending(SBT_TRANSPARENT_ALPHA);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("palmleaf1_df.dds");

	// ============================ _veg2Leaf33 ============================================
	mat = MaterialManager::getSingleton().create("_veg2Leaf33", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("leaf33.dds");

	// ============================ _veg2_lod2Leaf33 ============================================
	mat = MaterialManager::getSingleton().create("_veg2_lod2Leaf33", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("leaf33.dds");

	// ============================ _veg4Leaf2_df ============================================
	mat = MaterialManager::getSingleton().create("_veg4Leaf2_df", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSceneBlending(SBT_TRANSPARENT_ALPHA);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("leaf2_df.dds");

	// ============================ _veg4_lod1Leaf2_df ============================================
	mat = MaterialManager::getSingleton().create("_veg4_lod1Leaf2_df", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSceneBlending(SBT_TRANSPARENT_ALPHA);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("leaf2_df.dds");

	// ============================ _veg4_lod2Leaf2_df ============================================
	mat = MaterialManager::getSingleton().create("_veg4_lod2Leaf2_df", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSceneBlending(SBT_TRANSPARENT_ALPHA);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("leaf2_df.dds");

	// ============================ _veg8palm3_trunk_DF ============================================
	mat = MaterialManager::getSingleton().create("_veg8palm3_trunk_DF", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("palm3_trunk_df.dds");

	// ============================ _veg8palmleaf2_df ============================================
	mat = MaterialManager::getSingleton().create("_veg8palmleaf2_df", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSceneBlending(SBT_TRANSPARENT_ALPHA);
	mat->getTechnique(0)->getPass(0)->setAlphaRejectSettings(CompareFunction::CMPF_GREATER_EQUAL, 128);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("palmleaf2_df.dds");

	// ============================ _veg8_lod2palm3_trunk_DF ============================================
	mat = MaterialManager::getSingleton().create("_veg8_lod2palm3_trunk_DF", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("palm3_trunk_df.dds");

	// ============================ _veg8_lod2palmleaf2_df ============================================
	mat = MaterialManager::getSingleton().create("_veg8_lod2palmleaf2_df", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSceneBlending(SBT_TRANSPARENT_ALPHA);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("palmleaf2_df.dds");

	// ============================ _veg9Palm1_trunk_DF ============================================
	mat = MaterialManager::getSingleton().create("_veg9Palm1_trunk_DF", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("palm1_trunk_df.dds");

	// ============================ _veg9palmleaf2_df ============================================
	mat = MaterialManager::getSingleton().create("_veg9palmleaf2_df", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSceneBlending(SBT_TRANSPARENT_ALPHA);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("palmleaf2_df.dds");

	// ============================ _veg9_lod2Palm1_trunk_DF ============================================
	mat = MaterialManager::getSingleton().create("_veg9_lod2Palm1_trunk_DF", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("palm1_trunk_df.dds");

	// ============================ _veg9_lod2palmleaf2_df ============================================
	mat = MaterialManager::getSingleton().create("_veg9_lod2palmleaf2_df", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSceneBlending(SBT_TRANSPARENT_ALPHA);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("palmleaf2_df.dds");

	// ============================ VillageChurch ============================================
	mat = MaterialManager::getSingleton().create("VillageChurch", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setSceneBlending(SBF_DEST_COLOUR, SBF_ZERO);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("vchurch_fpsctex_d2.dds");

	// ============================ VillageFence1 ============================================
	mat = MaterialManager::getSingleton().create("VillageFence1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.00f, 0.00f, 0.00f, 10.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("panel_1tex_d2.dds");

	// ============================ VillageFence2 ============================================
	mat = MaterialManager::getSingleton().create("VillageFence2", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.00f, 0.00f, 0.00f, 10.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("panel_1tex_d2.dds");

	// ============================ VillageFence3 ============================================
	mat = MaterialManager::getSingleton().create("VillageFence3", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.00f, 0.00f, 0.00f, 10.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("panel_1tex_d2.dds");

	// ============================ VillageHouse1 ============================================
	mat = MaterialManager::getSingleton().create("VillageHouse1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.00f, 0.00f, 0.00f, 10.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("vhs1_fpsctex_d2.dds");

	// ============================ VillageHouse2 ============================================
	mat = MaterialManager::getSingleton().create("VillageHouse2", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.00f, 0.00f, 0.00f, 10.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("vhs2_fpsctex_d2.dds");

	// ============================ VillageHouse3 ============================================
	mat = MaterialManager::getSingleton().create("VillageHouse3", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.00f, 0.00f, 0.00f, 10.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("vhs3_fpsctex_d2.dds");

	// ============================ VillageHouse4 ============================================
	mat = MaterialManager::getSingleton().create("VillageHouse4", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.00f, 0.00f, 0.00f, 10.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("vhs4_fpsctex_d2.dds");

	// ============================ VillageHouse5 ============================================
	mat = MaterialManager::getSingleton().create("VillageHouse5", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.00f, 0.00f, 0.00f, 10.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("vhs5_fpsctex_d2.dds");

	// ============================ VillageHouse6 ============================================
	mat = MaterialManager::getSingleton().create("VillageHouse6", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.00f, 0.00f, 0.00f, 10.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("vhs6_fpsctex_d2.dds");

	// ============================ VillageHouse7 ============================================
	mat = MaterialManager::getSingleton().create("VillageHouse7", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.00f, 0.00f, 0.00f, 10.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("vhs7_fpsctex_d2.dds");

	// ============================ road_village_tcross ============================================
	mat = MaterialManager::getSingleton().create("road_village_tcross", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(80.0000f);
	mat->getTechnique(0)->getPass(0)->setSceneBlending(SBF_ONE, SBF_ONE_MINUS_SOURCE_ALPHA);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("road_village_tcross.dds");

	// ============================ street_old ============================================
	mat = MaterialManager::getSingleton().create("street_old", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(80.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("street_old.dds");

	// ============================ road_village_curve ============================================
	mat = MaterialManager::getSingleton().create("road_village_curve", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(80.0000f);
	mat->getTechnique(0)->getPass(0)->setSceneBlending(SBF_ONE, SBF_ONE_MINUS_SOURCE_ALPHA);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("road_village_curve.dds");

	// ============================ floor01_d ============================================
	mat = MaterialManager::getSingleton().create("floor01_d", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("floor05_d.dds");

	// ============================ metal_leaking ============================================
	mat = MaterialManager::getSingleton().create("metal_leaking", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("metal_leaking_d.dds");

	// ============================ floor03 ============================================
	mat = MaterialManager::getSingleton().create("floor03", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("floor03_d.dds");

	// ============================ con02 ============================================
	mat = MaterialManager::getSingleton().create("con02", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193f);
	mat->getTechnique(0)->getPass(0)->setSceneBlending(SBF_ONE, SBF_ONE_MINUS_SOURCE_ALPHA);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("con02_d.dds");

	// ============================ Well_1_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("Well_1_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("brickold_d.dds");

	// ============================ Well_1_lwo#1 ============================================
	mat = MaterialManager::getSingleton().create("Well_1_lwo#1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodplanks_d.dds");

	// ============================ Well_1_lwo#2 ============================================
	mat = MaterialManager::getSingleton().create("Well_1_lwo#2", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodplaindark_d.dds");

	// ============================ Well_1_lwo#3 ============================================
	mat = MaterialManager::getSingleton().create("Well_1_lwo#3", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodplain_d.dds");

	// ============================ Well_1_lwo#4 ============================================
	mat = MaterialManager::getSingleton().create("Well_1_lwo#4", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("rockrough_d.dds");

	// ============================ Well_1_lwo#5 ============================================
	mat = MaterialManager::getSingleton().create("Well_1_lwo#5", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("wooddetail2_d.dds");

	// ============================ Well_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("Well_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("brickold_d.dds");

	// ============================ Well_lwo#1 ============================================
	mat = MaterialManager::getSingleton().create("Well_lwo#1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodplanks_d.dds");

	// ============================ Well_lwo#2 ============================================
	mat = MaterialManager::getSingleton().create("Well_lwo#2", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodplaindark_d.dds");

	// ============================ Well_lwo#3 ============================================
	mat = MaterialManager::getSingleton().create("Well_lwo#3", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("rope_d.dds");

	// ============================ Well_lwo#4 ============================================
	mat = MaterialManager::getSingleton().create("Well_lwo#4", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodplain_d.dds");

	// ============================ Well_lwo#5 ============================================
	mat = MaterialManager::getSingleton().create("Well_lwo#5", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("rockrough_d.dds");

	// ============================ Well_lwo#6 ============================================
	mat = MaterialManager::getSingleton().create("Well_lwo#6", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("wooddetail2_d.dds");

	// ============================ Wheel_1_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("Wheel_1_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("metalbase_d.dds");

	// ============================ Wheel_1_lwo#1 ============================================
	mat = MaterialManager::getSingleton().create("Wheel_1_lwo#1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodplaindark_d.dds");

	// ============================ Wheel_1_lwo#2 ============================================
	mat = MaterialManager::getSingleton().create("Wheel_1_lwo#2", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("wooddetail2_d.dds");

	// ============================ Wheel_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("Wheel_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("metalbase_d.dds");

	// ============================ Wheel_lwo#1 ============================================
	mat = MaterialManager::getSingleton().create("Wheel_lwo#1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodplaindark_d.dds");

	// ============================ Wheel_lwo#2 ============================================
	mat = MaterialManager::getSingleton().create("Wheel_lwo#2", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("wooddetail2_d.dds");

	// ============================ WindowA_1_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("WindowA_1_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("window1_d.dds");

	// ============================ WindowA_1_lwo#1 ============================================
	mat = MaterialManager::getSingleton().create("WindowA_1_lwo#1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodplain_d.dds");

	// ============================ WindowA_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("WindowA_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("window1_d.dds");

	// ============================ WindowA_lwo#1 ============================================
	mat = MaterialManager::getSingleton().create("WindowA_lwo#1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodplain_d.dds");

	// ============================ WindowB_1_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("WindowB_1_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("window1_d.dds");

	// ============================ WindowB_1_lwo#1 ============================================
	mat = MaterialManager::getSingleton().create("WindowB_1_lwo#1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodbars_d.dds");

	// ============================ WindowB_1_lwo#2 ============================================
	mat = MaterialManager::getSingleton().create("WindowB_1_lwo#2", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodplain_d.dds");

	// ============================ WindowB_1_lwo#3 ============================================
	mat = MaterialManager::getSingleton().create("WindowB_1_lwo#3", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("wooddetail2_d.dds");

	// ============================ WindowB_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("WindowB_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("window1_d.dds");

	// ============================ WindowB_lwo#1 ============================================
	mat = MaterialManager::getSingleton().create("WindowB_lwo#1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodbars_d.dds");

	// ============================ WindowB_lwo#2 ============================================
	mat = MaterialManager::getSingleton().create("WindowB_lwo#2", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodplain_d.dds");

	// ============================ WindowB_lwo#3 ============================================
	mat = MaterialManager::getSingleton().create("WindowB_lwo#3", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("wooddetail2_d.dds");

	// ============================ WindowC_1_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("WindowC_1_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("window1_d.dds");

	// ============================ WindowC_1_lwo#1 ============================================
	mat = MaterialManager::getSingleton().create("WindowC_1_lwo#1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodbars_d.dds");

	// ============================ WindowC_1_lwo#2 ============================================
	mat = MaterialManager::getSingleton().create("WindowC_1_lwo#2", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodplain_d.dds");

	// ============================ WindowC_1_lwo#3 ============================================
	mat = MaterialManager::getSingleton().create("WindowC_1_lwo#3", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("wooddetail2_d.dds");

	// ============================ WindowC_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("WindowC_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("window1_d.dds");

	// ============================ WindowC_lwo#1 ============================================
	mat = MaterialManager::getSingleton().create("WindowC_lwo#1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodbars_d.dds");

	// ============================ WindowC_lwo#2 ============================================
	mat = MaterialManager::getSingleton().create("WindowC_lwo#2", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodplain_d.dds");

	// ============================ WindowC_lwo#3 ============================================
	mat = MaterialManager::getSingleton().create("WindowC_lwo#3", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("wooddetail2_d.dds");

	// ============================ WindowD_1_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("WindowD_1_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("window1_d.dds");

	// ============================ WindowD_1_lwo#1 ============================================
	mat = MaterialManager::getSingleton().create("WindowD_1_lwo#1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodbars_d.dds");

	// ============================ WindowD_1_lwo#2 ============================================
	mat = MaterialManager::getSingleton().create("WindowD_1_lwo#2", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodplain_d.dds");

	// ============================ WindowD_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("WindowD_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("window1_d.dds");

	// ============================ WindowD_lwo#1 ============================================
	mat = MaterialManager::getSingleton().create("WindowD_lwo#1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodbars_d.dds");

	// ============================ WindowD_lwo#2 ============================================
	mat = MaterialManager::getSingleton().create("WindowD_lwo#2", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodplain_d.dds");

	// ============================ WindowE_1_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("WindowE_1_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("window1_d.dds");

	// ============================ WindowE_1_lwo#1 ============================================
	mat = MaterialManager::getSingleton().create("WindowE_1_lwo#1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodplain_d.dds");

	// ============================ WindowE_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("WindowE_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("window1_d.dds");

	// ============================ WindowE_lwo#1 ============================================
	mat = MaterialManager::getSingleton().create("WindowE_lwo#1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodplain_d.dds");

	// ============================ WindowF_1_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("WindowF_1_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("window1_d.dds");

	// ============================ WindowF_1_lwo#1 ============================================
	mat = MaterialManager::getSingleton().create("WindowF_1_lwo#1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("rockrough_d.dds");

	// ============================ WindowF_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("WindowF_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("window1_d.dds");

	// ============================ WindowF_lwo#1 ============================================
	mat = MaterialManager::getSingleton().create("WindowF_lwo#1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("rockrough_d.dds");

	// ============================ WindowG_1_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("WindowG_1_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("window1_d.dds");

	// ============================ WindowG_1_lwo#1 ============================================
	mat = MaterialManager::getSingleton().create("WindowG_1_lwo#1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("rockrough_d.dds");

	// ============================ WindowG_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("WindowG_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("window1_d.dds");

	// ============================ WindowG_lwo#1 ============================================
	mat = MaterialManager::getSingleton().create("WindowG_lwo#1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("rockrough_d.dds");

	// ============================ WoodBench_1_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("WoodBench_1_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodplaindark_d.dds");

	// ============================ WoodBench_1_lwo#1 ============================================
	mat = MaterialManager::getSingleton().create("WoodBench_1_lwo#1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodplain_d.dds");

	// ============================ WoodBench_lwo#0 ============================================
	mat = MaterialManager::getSingleton().create("WoodBench_lwo#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodplaindark_d.dds");

	// ============================ WoodBench_lwo#1 ============================================
	mat = MaterialManager::getSingleton().create("WoodBench_lwo#1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.80f, 0.80f, 0.80f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(1.00f, 1.00f, 1.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("woodplain_d.dds");

	// ============================ blue_bullet ============================================
	mat = MaterialManager::getSingleton().create("blue_bullet", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("bullet5.dds");

	// ============================ blue_bullet_source ============================================
	mat = MaterialManager::getSingleton().create("blue_bullet_source", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setSceneBlending(SBT_TRANSPARENT_ALPHA);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("bullet5_s.dds");

	// ============================ light_D ============================================
	mat = MaterialManager::getSingleton().create("light_D", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.20f, 0.20f, 0.20f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("light_d.dds");

	// ============================ Material#40 ============================================
	mat = MaterialManager::getSingleton().create("Material#40", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.00f, 0.00f, 0.00f, 10.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("range1.dds");

	// ============================ Material#42 ============================================
	mat = MaterialManager::getSingleton().create("Material#42", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.00f, 0.00f, 0.00f, 10.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("range3.dds");

	// ============================ Material#43 ============================================
	mat = MaterialManager::getSingleton().create("Material#43", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.00f, 0.00f, 0.00f, 10.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("range4.dds");

	// ============================ Material#44 ============================================
	mat = MaterialManager::getSingleton().create("Material#44", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.00f, 0.00f, 0.00f, 10.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(0.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("range5.dds");

	// ============================ modulate ============================================
	mat = MaterialManager::getSingleton().create("modulate", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("white.dds");
	tus->setTextureFiltering(FilterOptions::FO_ANISOTROPIC, FilterOptions::FO_ANISOTROPIC, FilterOptions::FO_ANISOTROPIC);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("white.dds");
	tus->setTextureFiltering(FilterOptions::FO_ANISOTROPIC, FilterOptions::FO_ANISOTROPIC, FilterOptions::FO_ANISOTROPIC);

	// ============================ Soldier01-Default_OgreMax_bk ============================================
	mat = MaterialManager::getSingleton().create("Soldier01-Default_OgreMax_bk", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.00f, 0.00f, 0.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(10.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("usmc_lowpoly.dds");
	tus->setTextureFiltering(FilterOptions::FO_LINEAR, FilterOptions::FO_LINEAR, FilterOptions::FO_LINEAR);

	// ============================ Soldier01-Default_OgreMax_brown ============================================
	mat = MaterialManager::getSingleton().create("Soldier01-Default_OgreMax_brown", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.00f, 0.00f, 0.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(10.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("usmc_brown_lowpoly.dds");
	tus->setTextureFiltering(FilterOptions::FO_LINEAR, FilterOptions::FO_LINEAR, FilterOptions::FO_LINEAR);

	// ============================ Soldier01-Default_OgreMax_green ============================================
	mat = MaterialManager::getSingleton().create("Soldier01-Default_OgreMax_green", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.59f, 0.59f, 0.59f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.00f, 0.00f, 0.00f, 1.00f));
	mat->getTechnique(0)->getPass(0)->setShininess(10.0000f);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("usmc_green_lowpoly.dds");
	tus->setTextureFiltering(FilterOptions::FO_LINEAR, FilterOptions::FO_LINEAR, FilterOptions::FO_LINEAR);

}
