#include "CLevelGeneric.h"
#include "CoreEngine.h"
#include "RuntimeEditor\CRuntimeEditorManager.h"

#include "OgreRoot.h"
#include "OgreFont.h"
#include "OgreFontManager.h"

#include "CGameManager.h"
#include "CGameObjectManager.h"
#include "CGameObject.h"

using namespace Ogre;
using namespace Core;
using namespace Core::Editor;
using namespace Core::Effects;
using namespace Core::Physics;

#define SERVERPORT 12123
#define CLIENTPORT 6001

void LoadFonts();
void LoadMaterials();

void CLevelGeneric::Update(const f32& deltaTime)
{
	if(!Editor::CRuntimeEditorManager::Instance()->IsRunning())
	{
		CGameManager::Instance()->UpdateGame(deltaTime);
	}

	//CNetworkManager::Instance()->Update();
}

bool CLevelGeneric::Load()
{
	try
	{
		m_RuntimeEditorManager = nullptr;

		CCameraManager::Instance()->SetCameraPos(Vector3(0, 10, 0));
		CCameraManager::Instance()->SetMoveSpeed(20.0f);

		// Create ODE physics strategy
		CPhysicsManager::Instance()->CreateStrategy("ODE");
		CPhysicsManager::Instance()->GetStrategy()->InitWorld();
		CPhysicsManager::Instance()->GetStrategy()->ShowDebug(false);

		LoadFonts();
		LoadMaterials();

		/*auto nm = CNetworkManager::Instance();
		auto test = nm->StartClient("127.0.0.1", SERVERPORT);
		nm->Login("test", "tester");*/

		//CGameManager::Instance()->GetSceneManager()->setAmbientLight(Ogre::ColourValue(0, 0, 0));
		//Ogre::Light* pointLight = CGameManager::Instance()->GetSceneManager()->createLight("pointLight");
		//pointLight->setType(Ogre::Light::LT_POINT);
		//pointLight->setPosition(Ogre::Vector3(0, 50, 0));

		//auto obj = CGameObjectManager::Instance()->CreateObject("AMMOBOX1", "obj_0", Vector3(0, 5, -10));
		//obj->Entity->setCastShadows(true);

		SceneImporterPackage sip;
		sip.SoundManager = Sound::CSoundManager::Instance();
		sip.PhysicsStrategy = CPhysicsManager::Instance()->GetStrategy();
		sip.GameManager = CGameManager::Instance();
		sip.CameraManager = CCameraManager::Instance();
		sip.ItemsManager = CItemsManager::Instance();
		sip.GameObjectManager = CGameObjectManager::Instance();
		sip.NatureManager = Nature::CNatureManager::Instance();
		sip.ResourceGroupName = "CLevelGeneric";

		m_RuntimeEditorManager = Editor::CRuntimeEditorManager::Instance();
		m_RuntimeEditorManager->InitEditor(sip);
		m_RuntimeEditorManager->CreatePlane();

		m_FrameListenerFramework = new CFpsFrameListener(m_GameManager->GetRenderWindow());
		m_GameManager->GetEngineDevice()->addFrameListener(m_FrameListenerFramework);
	}
	catch(char* e)
	{
		std::cerr << e << std::endl;
	}
	return true;
}

CLevelGeneric::~CLevelGeneric()
{
	m_GameManager->GetEngineDevice()->removeFrameListener(m_FrameListenerFramework);
	CORE_DELETE(m_FrameListenerFramework);
	CORE_DELETE(m_RuntimeEditorManager);
}

#include "CGame.h"

#ifdef WIN32
#define WIN32_LEAN_AND_MEAN
#include "windows.h"

INT WINAPI WinMain( HINSTANCE hInst, HINSTANCE, LPSTR strCmdLine, INT argc) 
{ 
	try 
	{
		Core::CGame game;
		game.AddGameState(new CLevelGeneric());
		game.Run();
	} 
	catch(Exception& e) 
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
	game.Run();

	return 0;
}

void LoadFonts()
{
	FontPtr font;
	int textureAspect = 10;

	// ============================ BerlinSans32 ============================================
	font = FontManager::getSingleton().create("VeraMono", "General");
	font->setSource("berlin_sans32.png");
	font->setType(FontType::FT_IMAGE);
	font->setGlyphTexCoords(33, 0.0859375, 0.125, 0.101563, 0.1875, textureAspect);
	font->setGlyphTexCoords(34, 0.146484, 0.125, 0.166016, 0.1875, textureAspect);
	font->setGlyphTexCoords(35, 0.201172, 0.125, 0.236328, 0.1875, textureAspect);
	font->setGlyphTexCoords(36, 0.269531, 0.125, 0.292969, 0.1875, textureAspect);
	font->setGlyphTexCoords(37, 0.324219, 0.125, 0.363281, 0.1875, textureAspect);
	font->setGlyphTexCoords(38, 0.386719, 0.125, 0.425781, 0.1875, textureAspect);
	font->setGlyphTexCoords(39, 0.460938, 0.125, 0.476563, 0.1875, textureAspect);
	font->setGlyphTexCoords(40, 0.519531, 0.125, 0.542969, 0.1875, textureAspect);
	font->setGlyphTexCoords(41, 0.582031, 0.125, 0.605469, 0.1875, textureAspect);
	font->setGlyphTexCoords(42, 0.644531, 0.125, 0.667969, 0.1875, textureAspect);
	font->setGlyphTexCoords(43, 0.707031, 0.125, 0.730469, 0.1875, textureAspect);
	font->setGlyphTexCoords(44, 0.773438, 0.125, 0.789063, 0.1875, textureAspect);
	font->setGlyphTexCoords(45, 0.832031, 0.125, 0.855469, 0.1875, textureAspect);
	font->setGlyphTexCoords(46, 0.898438, 0.125, 0.914063, 0.1875, textureAspect);
	font->setGlyphTexCoords(47, 0.958984, 0.125, 0.978516, 0.1875, textureAspect);
	font->setGlyphTexCoords(48, 0.0136719, 0.1875, 0.0488281, 0.25, textureAspect);
	font->setGlyphTexCoords(49, 0.0839844, 0.1875, 0.103516, 0.25, textureAspect);
	font->setGlyphTexCoords(50, 0.142578, 0.1875, 0.169922, 0.25, textureAspect);
	font->setGlyphTexCoords(51, 0.205078, 0.1875, 0.232422, 0.25, textureAspect);
	font->setGlyphTexCoords(52, 0.265625, 0.1875, 0.296875, 0.25, textureAspect);
	font->setGlyphTexCoords(53, 0.330078, 0.1875, 0.357422, 0.25, textureAspect);
	font->setGlyphTexCoords(54, 0.390625, 0.1875, 0.421875, 0.25, textureAspect);
	font->setGlyphTexCoords(55, 0.455078, 0.1875, 0.482422, 0.25, textureAspect);
	font->setGlyphTexCoords(56, 0.517578, 0.1875, 0.544922, 0.25, textureAspect);
	font->setGlyphTexCoords(57, 0.578125, 0.1875, 0.609375, 0.25, textureAspect);
	font->setGlyphTexCoords(58, 0.648438, 0.1875, 0.664063, 0.25, textureAspect);
	font->setGlyphTexCoords(59, 0.710938, 0.1875, 0.726563, 0.25, textureAspect);
	font->setGlyphTexCoords(60, 0.769531, 0.1875, 0.792969, 0.25, textureAspect);
	font->setGlyphTexCoords(61, 0.830078, 0.1875, 0.857422, 0.25, textureAspect);
	font->setGlyphTexCoords(62, 0.894531, 0.1875, 0.917969, 0.25, textureAspect);
	font->setGlyphTexCoords(63, 0.957031, 0.1875, 0.980469, 0.25, textureAspect);
	font->setGlyphTexCoords(64, 0.0136719, 0.25, 0.0488281, 0.3125, textureAspect);
	font->setGlyphTexCoords(65, 0.0761719, 0.25, 0.111328, 0.3125, textureAspect);
	font->setGlyphTexCoords(66, 0.138672, 0.25, 0.173828, 0.3125, textureAspect);
	font->setGlyphTexCoords(67, 0.201172, 0.25, 0.236328, 0.3125, textureAspect);
	font->setGlyphTexCoords(68, 0.261719, 0.25, 0.300781, 0.3125, textureAspect);
	font->setGlyphTexCoords(69, 0.328125, 0.25, 0.359375, 0.3125, textureAspect);
	font->setGlyphTexCoords(70, 0.390625, 0.25, 0.421875, 0.3125, textureAspect);
	font->setGlyphTexCoords(71, 0.449219, 0.25, 0.488281, 0.3125, textureAspect);
	font->setGlyphTexCoords(72, 0.511719, 0.25, 0.550781, 0.3125, textureAspect);
	font->setGlyphTexCoords(73, 0.585938, 0.25, 0.601563, 0.3125, textureAspect);
	font->setGlyphTexCoords(74, 0.646484, 0.25, 0.666016, 0.3125, textureAspect);
	font->setGlyphTexCoords(75, 0.701172, 0.25, 0.736328, 0.3125, textureAspect);
	font->setGlyphTexCoords(76, 0.765625, 0.25, 0.796875, 0.3125, textureAspect);
	font->setGlyphTexCoords(77, 0.824219, 0.25, 0.863281, 0.3125, textureAspect);
	font->setGlyphTexCoords(78, 0.886719, 0.25, 0.925781, 0.3125, textureAspect);
	font->setGlyphTexCoords(79, 0.949219, 0.25, 0.988281, 0.3125, textureAspect);
	font->setGlyphTexCoords(80, 0.0136719, 0.3125, 0.0488281, 0.375, textureAspect);
	font->setGlyphTexCoords(81, 0.0742188, 0.3125, 0.113281, 0.375, textureAspect);
	font->setGlyphTexCoords(82, 0.138672, 0.3125, 0.173828, 0.375, textureAspect);
	font->setGlyphTexCoords(83, 0.205078, 0.3125, 0.232422, 0.375, textureAspect);
	font->setGlyphTexCoords(84, 0.265625, 0.3125, 0.296875, 0.375, textureAspect);
	font->setGlyphTexCoords(85, 0.326172, 0.3125, 0.361328, 0.375, textureAspect);
	font->setGlyphTexCoords(86, 0.388672, 0.3125, 0.423828, 0.375, textureAspect);
	font->setGlyphTexCoords(87, 0.445313, 0.3125, 0.492188, 0.375, textureAspect);
	font->setGlyphTexCoords(88, 0.515625, 0.3125, 0.546875, 0.375, textureAspect);
	font->setGlyphTexCoords(89, 0.576172, 0.3125, 0.611328, 0.375, textureAspect);
	font->setGlyphTexCoords(90, 0.640625, 0.3125, 0.671875, 0.375, textureAspect);
	font->setGlyphTexCoords(91, 0.707031, 0.3125, 0.730469, 0.375, textureAspect);
	font->setGlyphTexCoords(92, 0.771484, 0.3125, 0.791016, 0.375, textureAspect);
	font->setGlyphTexCoords(93, 0.832031, 0.3125, 0.855469, 0.375, textureAspect);
	font->setGlyphTexCoords(94, 0.892578, 0.3125, 0.919922, 0.375, textureAspect);
	font->setGlyphTexCoords(95, 0.955078, 0.3125, 0.982422, 0.375, textureAspect);
	font->setGlyphTexCoords(96, 0.0195313, 0.375, 0.0429688, 0.4375, textureAspect);
	font->setGlyphTexCoords(97, 0.078125, 0.375, 0.109375, 0.4375, textureAspect);
	font->setGlyphTexCoords(98, 0.140625, 0.375, 0.171875, 0.4375, textureAspect);
	font->setGlyphTexCoords(99, 0.207031, 0.375, 0.230469, 0.4375, textureAspect);
	font->setGlyphTexCoords(100, 0.265625, 0.375, 0.296875, 0.4375, textureAspect);
	font->setGlyphTexCoords(101, 0.330078, 0.375, 0.357422, 0.4375, textureAspect);
	font->setGlyphTexCoords(102, 0.396484, 0.375, 0.416016, 0.4375, textureAspect);
	font->setGlyphTexCoords(103, 0.453125, 0.375, 0.484375, 0.4375, textureAspect);
	font->setGlyphTexCoords(104, 0.515625, 0.375, 0.546875, 0.4375, textureAspect);
	font->setGlyphTexCoords(105, 0.585938, 0.375, 0.601563, 0.4375, textureAspect);
	font->setGlyphTexCoords(106, 0.648438, 0.375, 0.664063, 0.4375, textureAspect);
	font->setGlyphTexCoords(107, 0.703125, 0.375, 0.734375, 0.4375, textureAspect);
	font->setGlyphTexCoords(108, 0.773438, 0.375, 0.789063, 0.4375, textureAspect);
	font->setGlyphTexCoords(109, 0.822266, 0.375, 0.865234, 0.4375, textureAspect);
	font->setGlyphTexCoords(110, 0.890625, 0.375, 0.921875, 0.4375, textureAspect);
	font->setGlyphTexCoords(111, 0.953125, 0.375, 0.984375, 0.4375, textureAspect);
	font->setGlyphTexCoords(112, 0.015625, 0.4375, 0.046875, 0.5, textureAspect);
	font->setGlyphTexCoords(113, 0.078125, 0.4375, 0.109375, 0.5, textureAspect);
	font->setGlyphTexCoords(114, 0.144531, 0.4375, 0.167969, 0.5, textureAspect);
	font->setGlyphTexCoords(115, 0.208984, 0.4375, 0.228516, 0.5, textureAspect);
	font->setGlyphTexCoords(116, 0.269531, 0.4375, 0.292969, 0.5, textureAspect);
	font->setGlyphTexCoords(117, 0.328125, 0.4375, 0.359375, 0.5, textureAspect);
	font->setGlyphTexCoords(118, 0.390625, 0.4375, 0.421875, 0.5, textureAspect);
	font->setGlyphTexCoords(119, 0.449219, 0.4375, 0.488281, 0.5, textureAspect);
	font->setGlyphTexCoords(120, 0.517578, 0.4375, 0.544922, 0.5, textureAspect);
	font->setGlyphTexCoords(121, 0.580078, 0.4375, 0.607422, 0.5, textureAspect);
	font->setGlyphTexCoords(122, 0.642578, 0.4375, 0.669922, 0.5, textureAspect);
	font->setGlyphTexCoords(123, 0.707031, 0.4375, 0.730469, 0.5, textureAspect);
	font->setGlyphTexCoords(124, 0.771484, 0.4375, 0.791016, 0.5, textureAspect);
	font->setGlyphTexCoords(125, 0.832031, 0.4375, 0.855469, 0.5, textureAspect);
	font->setGlyphTexCoords(126, 0.892578, 0.4375, 0.919922, 0.5, textureAspect);

	// ============================ BlueHigh ============================================
	font = FontManager::getSingleton().create("BlueHigh", "General");
	font->setSource("berlin_sans32.png");
	font->setType(FontType::FT_IMAGE);
	font->setGlyphTexCoords(33, 0.0859375, 0.125, 0.101563, 0.1875, textureAspect);
	font->setGlyphTexCoords(34, 0.146484, 0.125, 0.166016, 0.1875, textureAspect);
	font->setGlyphTexCoords(35, 0.201172, 0.125, 0.236328, 0.1875, textureAspect);
	font->setGlyphTexCoords(36, 0.269531, 0.125, 0.292969, 0.1875, textureAspect);
	font->setGlyphTexCoords(37, 0.324219, 0.125, 0.363281, 0.1875, textureAspect);
	font->setGlyphTexCoords(38, 0.386719, 0.125, 0.425781, 0.1875, textureAspect);
	font->setGlyphTexCoords(39, 0.460938, 0.125, 0.476563, 0.1875, textureAspect);
	font->setGlyphTexCoords(40, 0.519531, 0.125, 0.542969, 0.1875, textureAspect);
	font->setGlyphTexCoords(41, 0.582031, 0.125, 0.605469, 0.1875, textureAspect);
	font->setGlyphTexCoords(42, 0.644531, 0.125, 0.667969, 0.1875, textureAspect);
	font->setGlyphTexCoords(43, 0.707031, 0.125, 0.730469, 0.1875, textureAspect);
	font->setGlyphTexCoords(44, 0.773438, 0.125, 0.789063, 0.1875, textureAspect);
	font->setGlyphTexCoords(45, 0.832031, 0.125, 0.855469, 0.1875, textureAspect);
	font->setGlyphTexCoords(46, 0.898438, 0.125, 0.914063, 0.1875, textureAspect);
	font->setGlyphTexCoords(47, 0.958984, 0.125, 0.978516, 0.1875, textureAspect);
	font->setGlyphTexCoords(48, 0.0136719, 0.1875, 0.0488281, 0.25, textureAspect);
	font->setGlyphTexCoords(49, 0.0839844, 0.1875, 0.103516, 0.25, textureAspect);
	font->setGlyphTexCoords(50, 0.142578, 0.1875, 0.169922, 0.25, textureAspect);
	font->setGlyphTexCoords(51, 0.205078, 0.1875, 0.232422, 0.25, textureAspect);
	font->setGlyphTexCoords(52, 0.265625, 0.1875, 0.296875, 0.25, textureAspect);
	font->setGlyphTexCoords(53, 0.330078, 0.1875, 0.357422, 0.25, textureAspect);
	font->setGlyphTexCoords(54, 0.390625, 0.1875, 0.421875, 0.25, textureAspect);
	font->setGlyphTexCoords(55, 0.455078, 0.1875, 0.482422, 0.25, textureAspect);
	font->setGlyphTexCoords(56, 0.517578, 0.1875, 0.544922, 0.25, textureAspect);
	font->setGlyphTexCoords(57, 0.578125, 0.1875, 0.609375, 0.25, textureAspect);
	font->setGlyphTexCoords(58, 0.648438, 0.1875, 0.664063, 0.25, textureAspect);
	font->setGlyphTexCoords(59, 0.710938, 0.1875, 0.726563, 0.25, textureAspect);
	font->setGlyphTexCoords(60, 0.769531, 0.1875, 0.792969, 0.25, textureAspect);
	font->setGlyphTexCoords(61, 0.830078, 0.1875, 0.857422, 0.25, textureAspect);
	font->setGlyphTexCoords(62, 0.894531, 0.1875, 0.917969, 0.25, textureAspect);
	font->setGlyphTexCoords(63, 0.957031, 0.1875, 0.980469, 0.25, textureAspect);
	font->setGlyphTexCoords(64, 0.0136719, 0.25, 0.0488281, 0.3125, textureAspect);
	font->setGlyphTexCoords(65, 0.0761719, 0.25, 0.111328, 0.3125, textureAspect);
	font->setGlyphTexCoords(66, 0.138672, 0.25, 0.173828, 0.3125, textureAspect);
	font->setGlyphTexCoords(67, 0.201172, 0.25, 0.236328, 0.3125, textureAspect);
	font->setGlyphTexCoords(68, 0.261719, 0.25, 0.300781, 0.3125, textureAspect);
	font->setGlyphTexCoords(69, 0.328125, 0.25, 0.359375, 0.3125, textureAspect);
	font->setGlyphTexCoords(70, 0.390625, 0.25, 0.421875, 0.3125, textureAspect);
	font->setGlyphTexCoords(71, 0.449219, 0.25, 0.488281, 0.3125, textureAspect);
	font->setGlyphTexCoords(72, 0.511719, 0.25, 0.550781, 0.3125, textureAspect);
	font->setGlyphTexCoords(73, 0.585938, 0.25, 0.601563, 0.3125, textureAspect);
	font->setGlyphTexCoords(74, 0.646484, 0.25, 0.666016, 0.3125, textureAspect);
	font->setGlyphTexCoords(75, 0.701172, 0.25, 0.736328, 0.3125, textureAspect);
	font->setGlyphTexCoords(76, 0.765625, 0.25, 0.796875, 0.3125, textureAspect);
	font->setGlyphTexCoords(77, 0.824219, 0.25, 0.863281, 0.3125, textureAspect);
	font->setGlyphTexCoords(78, 0.886719, 0.25, 0.925781, 0.3125, textureAspect);
	font->setGlyphTexCoords(79, 0.949219, 0.25, 0.988281, 0.3125, textureAspect);
	font->setGlyphTexCoords(80, 0.0136719, 0.3125, 0.0488281, 0.375, textureAspect);
	font->setGlyphTexCoords(81, 0.0742188, 0.3125, 0.113281, 0.375, textureAspect);
	font->setGlyphTexCoords(82, 0.138672, 0.3125, 0.173828, 0.375, textureAspect);
	font->setGlyphTexCoords(83, 0.205078, 0.3125, 0.232422, 0.375, textureAspect);
	font->setGlyphTexCoords(84, 0.265625, 0.3125, 0.296875, 0.375, textureAspect);
	font->setGlyphTexCoords(85, 0.326172, 0.3125, 0.361328, 0.375, textureAspect);
	font->setGlyphTexCoords(86, 0.388672, 0.3125, 0.423828, 0.375, textureAspect);
	font->setGlyphTexCoords(87, 0.445313, 0.3125, 0.492188, 0.375, textureAspect);
	font->setGlyphTexCoords(88, 0.515625, 0.3125, 0.546875, 0.375, textureAspect);
	font->setGlyphTexCoords(89, 0.576172, 0.3125, 0.611328, 0.375, textureAspect);
	font->setGlyphTexCoords(90, 0.640625, 0.3125, 0.671875, 0.375, textureAspect);
	font->setGlyphTexCoords(91, 0.707031, 0.3125, 0.730469, 0.375, textureAspect);
	font->setGlyphTexCoords(92, 0.771484, 0.3125, 0.791016, 0.375, textureAspect);
	font->setGlyphTexCoords(93, 0.832031, 0.3125, 0.855469, 0.375, textureAspect);
	font->setGlyphTexCoords(94, 0.892578, 0.3125, 0.919922, 0.375, textureAspect);
	font->setGlyphTexCoords(95, 0.955078, 0.3125, 0.982422, 0.375, textureAspect);
	font->setGlyphTexCoords(96, 0.0195313, 0.375, 0.0429688, 0.4375, textureAspect);
	font->setGlyphTexCoords(97, 0.078125, 0.375, 0.109375, 0.4375, textureAspect);
	font->setGlyphTexCoords(98, 0.140625, 0.375, 0.171875, 0.4375, textureAspect);
	font->setGlyphTexCoords(99, 0.207031, 0.375, 0.230469, 0.4375, textureAspect);
	font->setGlyphTexCoords(100, 0.265625, 0.375, 0.296875, 0.4375, textureAspect);
	font->setGlyphTexCoords(101, 0.330078, 0.375, 0.357422, 0.4375, textureAspect);
	font->setGlyphTexCoords(102, 0.396484, 0.375, 0.416016, 0.4375, textureAspect);
	font->setGlyphTexCoords(103, 0.453125, 0.375, 0.484375, 0.4375, textureAspect);
	font->setGlyphTexCoords(104, 0.515625, 0.375, 0.546875, 0.4375, textureAspect);
	font->setGlyphTexCoords(105, 0.585938, 0.375, 0.601563, 0.4375, textureAspect);
	font->setGlyphTexCoords(106, 0.648438, 0.375, 0.664063, 0.4375, textureAspect);
	font->setGlyphTexCoords(107, 0.703125, 0.375, 0.734375, 0.4375, textureAspect);
	font->setGlyphTexCoords(108, 0.773438, 0.375, 0.789063, 0.4375, textureAspect);
	font->setGlyphTexCoords(109, 0.822266, 0.375, 0.865234, 0.4375, textureAspect);
	font->setGlyphTexCoords(110, 0.890625, 0.375, 0.921875, 0.4375, textureAspect);
	font->setGlyphTexCoords(111, 0.953125, 0.375, 0.984375, 0.4375, textureAspect);
	font->setGlyphTexCoords(112, 0.015625, 0.4375, 0.046875, 0.5, textureAspect);
	font->setGlyphTexCoords(113, 0.078125, 0.4375, 0.109375, 0.5, textureAspect);
	font->setGlyphTexCoords(114, 0.144531, 0.4375, 0.167969, 0.5, textureAspect);
	font->setGlyphTexCoords(115, 0.208984, 0.4375, 0.228516, 0.5, textureAspect);
	font->setGlyphTexCoords(116, 0.269531, 0.4375, 0.292969, 0.5, textureAspect);
	font->setGlyphTexCoords(117, 0.328125, 0.4375, 0.359375, 0.5, textureAspect);
	font->setGlyphTexCoords(118, 0.390625, 0.4375, 0.421875, 0.5, textureAspect);
	font->setGlyphTexCoords(119, 0.449219, 0.4375, 0.488281, 0.5, textureAspect);
	font->setGlyphTexCoords(120, 0.517578, 0.4375, 0.544922, 0.5, textureAspect);
	font->setGlyphTexCoords(121, 0.580078, 0.4375, 0.607422, 0.5, textureAspect);
	font->setGlyphTexCoords(122, 0.642578, 0.4375, 0.669922, 0.5, textureAspect);
	font->setGlyphTexCoords(123, 0.707031, 0.4375, 0.730469, 0.5, textureAspect);
	font->setGlyphTexCoords(124, 0.771484, 0.4375, 0.791016, 0.5, textureAspect);
	font->setGlyphTexCoords(125, 0.832031, 0.4375, 0.855469, 0.5, textureAspect);
	font->setGlyphTexCoords(126, 0.892578, 0.4375, 0.919922, 0.5, textureAspect);

}

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
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.588, 0.588, 0.588, 1));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.588, 0.588, 0.588, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0, 0, 0, 10));
	mat->getTechnique(0)->getPass(0)->setShininess(0);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("ak47_1_uvw.jpg");



	//// ============================ mat_ammo_box_5_1 ============================================
	//mat = MaterialManager::getSingleton().create("mat_ammo_box_5_1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	//mat->setReceiveShadows(true);
	//mat->setTransparencyCastsShadows(false);
	//mat->getTechnique(0)->setLightingEnabled(false);
	//mat->getTechnique(0)->setSchemeName("Default");
	//mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.8, 0.8, 0.8, 1));
	//mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.2, 0.2, 0.2, 1));
	//tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	//tus->setTextureName("ammobox1.bmp");
	//tus->setNumMipmaps(-1);



	// ============================ applegreenmat ============================================
	mat = MaterialManager::getSingleton().create("applegreenmat", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setShininess(60);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("applegreen_d.tga");



	// ============================ berreta ============================================
	mat = MaterialManager::getSingleton().create("berreta", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.588235, 0.588235, 0.588235, 1));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.588235, 0.588235, 0.588235, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.423, 0.423, 0.423, 1));
	mat->getTechnique(0)->getPass(0)->setShininess(28);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("beretta_color.tif");



	// ============================ appleredmat ============================================
	mat = MaterialManager::getSingleton().create("appleredmat", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setShininess(50);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("applered_d.tga");



	// ============================ armycolt1 ============================================
	mat = MaterialManager::getSingleton().create("armycolt1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.8, 0.8, 0.8, 1));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.2, 0.2, 0.2, 1));
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("armycolt.bmp");
	tus->setNumMipmaps(-1);



	// ============================ hand_01 ============================================
	mat = MaterialManager::getSingleton().create("hand_01", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.588, 0.588, 0.588, 1));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.588, 0.588, 0.588, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.072, 0.072, 0.072, 1));
	mat->getTechnique(0)->getPass(0)->setShininess(19);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("hand_color.tif");



	// ============================ assaultrifle ============================================
	mat = MaterialManager::getSingleton().create("assaultrifle", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(1, 1, 1, 1));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(1, 1, 1, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0, 0, 0, 128));
	mat->getTechnique(0)->getPass(0)->setShininess(0);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("riflediff.tga");
	tus->setTextureFiltering(FilterOptions::FO_POINT, FilterOptions::FO_POINT, FilterOptions::FO_POINT);



	// ============================ barrel ============================================
	mat = MaterialManager::getSingleton().create("barrel", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.498039, 0.498039, 0.498039, 1));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.752941, 0.752941, 0.752941, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0, 0, 0, 0));
	mat->getTechnique(0)->getPass(0)->setShininess(0);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("wilkob1.jpg");
	tus->setTextureFiltering(FilterOptions::FO_POINT, FilterOptions::FO_POINT, FilterOptions::FO_POINT);



	// ============================ mat_barrel01_5_1 ============================================
	mat = MaterialManager::getSingleton().create("mat_barrel01_5_1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.8, 0.8, 0.8, 1));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.2, 0.2, 0.2, 1));
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("barrel2.bmp");
	tus->setNumMipmaps(-1);



	// ============================ wood_rough_01 ============================================
	mat = MaterialManager::getSingleton().create("wood_rough_01", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.705882, 0.705882, 0.705882, 1));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0, 0, 0, 1));
	mat->getTechnique(0)->getPass(0)->setShininess(80);
	mat->getTechnique(0)->getPass(0)->setSceneBlending(SBF_ONE, SBF_ONE_MINUS_SOURCE_ALPHA);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("wood_rough_01.tga");



	// ============================ sas_torso ============================================
	mat = MaterialManager::getSingleton().create("sas_torso", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.588, 0.588, 0.588, 1));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.588, 0.588, 0.588, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0, 0, 0, 10));
	mat->getTechnique(0)->getPass(0)->setShininess(0);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("sas_1_d2.dds");



	// ============================ sas_main ============================================
	mat = MaterialManager::getSingleton().create("sas_main", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.588, 0.588, 0.588, 1));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.588, 0.588, 0.588, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0, 0, 0, 10));
	mat->getTechnique(0)->getPass(0)->setShininess(0);



	// ============================ mat_container_b5 ============================================
	mat = MaterialManager::getSingleton().create("mat_container_b5", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.8, 0.8, 0.8, 1));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.8, 0.8, 0.8, 1));
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("bigcontainer1.jpg");



	// ============================ mat_containter_l ============================================
	mat = MaterialManager::getSingleton().create("mat_containter_l", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.8, 0.8, 0.8, 1));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.8, 0.8, 0.8, 1));
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("bigcontainer2.jpg");



	// ============================ metal_stripes_d ============================================
	mat = MaterialManager::getSingleton().create("metal_stripes_d", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193);
	mat->getTechnique(0)->getPass(0)->setSceneBlending(SBF_ONE, SBF_ONE_MINUS_SOURCE_ALPHA);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("metal_stripes_d.tga");



	// ============================ metal01_d ============================================
	mat = MaterialManager::getSingleton().create("metal01_d", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("metal01_d.tga");



	// ============================ signs ============================================
	mat = MaterialManager::getSingleton().create("signs", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("signs.tga");



	// ============================ light_d ============================================
	mat = MaterialManager::getSingleton().create("light_d", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("light_d.tga");



	// ============================ foodbowlsoupmat ============================================
	mat = MaterialManager::getSingleton().create("foodbowlsoupmat", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.25, 0.25, 0.25, 1));
	mat->getTechnique(0)->getPass(0)->setShininess(60);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("foodbowl1_d.tga");



	// ============================ mat_gratebox5_1 ============================================
	mat = MaterialManager::getSingleton().create("mat_gratebox5_1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.8, 0.8, 0.8, 1));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.8, 0.8, 0.8, 1));
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("box1.bmp");



	// ============================ con4 ============================================
	mat = MaterialManager::getSingleton().create("con4", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("con04_d.tga");



	// ============================ bricks01 ============================================
	mat = MaterialManager::getSingleton().create("bricks01", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("bricks01_d.tga");



	// ============================ wood1 ============================================
	mat = MaterialManager::getSingleton().create("wood1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("wood01_d.tga");



	// ============================ rust06 ============================================
	mat = MaterialManager::getSingleton().create("rust06", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("rust06_d.tga");



	// ============================ #0 ============================================
	mat = MaterialManager::getSingleton().create("#0", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.588, 0.588, 0.588, 1));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.588, 0.588, 0.588, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0, 0, 0, 10));
	mat->getTechnique(0)->getPass(0)->setShininess(0);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("bush_1.png");



	// ============================ #25 ============================================
	mat = MaterialManager::getSingleton().create("#25", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.588, 0.588, 0.588, 1));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.588, 0.588, 0.588, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0, 0, 0, 10));
	mat->getTechnique(0)->getPass(0)->setShininess(0);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("bush_2.png");



	// ============================ cattail ============================================
	mat = MaterialManager::getSingleton().create("cattail", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.2, 0.2, 0.2, 43.2193));
	mat->getTechnique(0)->getPass(0)->setShininess(0);
	mat->getTechnique(0)->getPass(0)->setSceneBlending(SBT_TRANSPARENT_ALPHA);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("cattail_color.tga");



	// ============================ rust01_d ============================================
	mat = MaterialManager::getSingleton().create("rust01_d", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("rust01_d.tga");



	// ============================ clima_d ============================================
	mat = MaterialManager::getSingleton().create("clima_d", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("clima_d.tga");



	// ============================ #5 ============================================
	mat = MaterialManager::getSingleton().create("#5", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.588, 0.588, 0.588, 1));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.588, 0.588, 0.588, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0, 0, 0, 10));
	mat->getTechnique(0)->getPass(0)->setShininess(0);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("concrete.jpg");



	// ============================ #4 ============================================
	mat = MaterialManager::getSingleton().create("#4", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.588, 0.588, 0.588, 1));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.588, 0.588, 0.588, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0, 0, 0, 10));
	mat->getTechnique(0)->getPass(0)->setShininess(0);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("wood.jpg");



	// ============================ mat_woodbox_5_1 ============================================
	mat = MaterialManager::getSingleton().create("mat_woodbox_5_1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.8, 0.8, 0.8, 1));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.8, 0.8, 0.8, 1));
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("crate2.bmp");



	// ============================ ac3d/crate/mat001_tex00 ============================================
	mat = MaterialManager::getSingleton().create("ac3d/crate/mat001_tex00", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(1, 1, 1, 1));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(1, 1, 1, 1));
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("crate.png");



	// ============================ crate ============================================
	mat = MaterialManager::getSingleton().create("crate", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.498039, 0.498039, 0.498039, 1));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.752941, 0.752941, 0.752941, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0, 0, 0, 0));
	mat->getTechnique(0)->getPass(0)->setShininess(0);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("wilkoc1.jpg");
	tus->setTextureFiltering(FilterOptions::FO_POINT, FilterOptions::FO_POINT, FilterOptions::FO_POINT);



	// ============================ mat_woodbox4_5_1 ============================================
	mat = MaterialManager::getSingleton().create("mat_woodbox4_5_1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.8, 0.8, 0.8, 1));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.8, 0.8, 0.8, 1));
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("crate3.bmp");



	// ============================ road_village ============================================
	mat = MaterialManager::getSingleton().create("road_village", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.8, 0.8, 0.8, 1));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setShininess(80);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("road_village.tga");



	// ============================  ============================================
	mat = MaterialManager::getSingleton().create("", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setShininess(40);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("electric_box.tga");



	// ============================ con01_d ============================================
	mat = MaterialManager::getSingleton().create("con01_d", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("con01_d.tga");



	// ============================ metal5 ============================================
	mat = MaterialManager::getSingleton().create("metal5", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193);
	mat->getTechnique(0)->getPass(0)->setSceneBlending(SBF_ONE, SBF_ONE_MINUS_SOURCE_ALPHA);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("metal5_d.tga");



	// ============================ foodbowlmat ============================================
	mat = MaterialManager::getSingleton().create("foodbowlmat", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setShininess(50);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("foodbowl0_d.tga");



	// ============================ sign ============================================
	mat = MaterialManager::getSingleton().create("sign", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("signs.tga");



	// ============================ wire_d ============================================
	mat = MaterialManager::getSingleton().create("wire_d", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193);
	mat->getTechnique(0)->getPass(0)->setSceneBlending(SBF_ONE, SBF_ONE_MINUS_SOURCE_ALPHA);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("wire01_d.tga");



	// ============================ fence_wire ============================================
	mat = MaterialManager::getSingleton().create("fence_wire", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193);
	mat->getTechnique(0)->getPass(0)->setSceneBlending(SBF_ONE, SBF_ONE_MINUS_SOURCE_ALPHA);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("fence_wire_d.tga");



	// ============================ rust03_d ============================================
	mat = MaterialManager::getSingleton().create("rust03_d", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("rust03_d.tga");



	// ============================ firstaid1 ============================================
	mat = MaterialManager::getSingleton().create("firstaid1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.588, 0.588, 0.588, 1));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.588, 0.588, 0.588, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0, 0, 0, 10));
	mat->getTechnique(0)->getPass(0)->setShininess(0);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("firstaidboxtexture.jpg");



	// ============================ _flower1blossom1 ============================================
	mat = MaterialManager::getSingleton().create("_flower1blossom1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.784314, 0.784314, 0.784314, 1));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.784314, 0.784314, 0.784314, 1));
	mat->getTechnique(0)->getPass(0)->setSceneBlending(SBT_TRANSPARENT_ALPHA);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("blossom1.tga");



	// ============================ _flower1leaf33 ============================================
	mat = MaterialManager::getSingleton().create("_flower1leaf33", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.588235, 0.588235, 0.588235, 1));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.588235, 0.588235, 0.588235, 1));
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("leaf33.tga");



	// ============================ flowerplant ============================================
	mat = MaterialManager::getSingleton().create("flowerplant", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.2, 0.2, 0.2, 43.2193));
	mat->getTechnique(0)->getPass(0)->setShininess(0);
	mat->getTechnique(0)->getPass(0)->setSceneBlending(SBT_TRANSPARENT_ALPHA);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("flowerplant_color.tga");



	// ============================ flowerplant2 ============================================
	mat = MaterialManager::getSingleton().create("flowerplant2", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.2, 0.2, 0.2, 43.2193));
	mat->getTechnique(0)->getPass(0)->setShininess(0);
	mat->getTechnique(0)->getPass(0)->setSceneBlending(SBT_TRANSPARENT_ALPHA);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("flowerplant2_color.tga");



	// ============================ flowerplant3 ============================================
	mat = MaterialManager::getSingleton().create("flowerplant3", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.2, 0.2, 0.2, 43.2193));
	mat->getTechnique(0)->getPass(0)->setShininess(0);
	mat->getTechnique(0)->getPass(0)->setSceneBlending(SBT_TRANSPARENT_ALPHA);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("flowerplant3_color.tga");



	// ============================ cutlerymat ============================================
	mat = MaterialManager::getSingleton().create("cutlerymat", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.8, 0.8, 0.8, 1));
	mat->getTechnique(0)->getPass(0)->setShininess(45);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("cutlery_d.tga");



	// ============================ fryingpanmat ============================================
	mat = MaterialManager::getSingleton().create("fryingpanmat", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.8, 0.8, 0.8, 1));
	mat->getTechnique(0)->getPass(0)->setShininess(45);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("fryingpan_d.tga");



	// ============================ con1 ============================================
	mat = MaterialManager::getSingleton().create("con1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("con01_d.tga");



	// ============================ rusty2 ============================================
	mat = MaterialManager::getSingleton().create("rusty2", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("rust02_d.tga");



	// ============================ h9 ============================================
	mat = MaterialManager::getSingleton().create("h9", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.8, 0.8, 0.8, 1));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setShininess(40);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("h9.tga");



	// ============================ genmarine ============================================
	mat = MaterialManager::getSingleton().create("genmarine", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(1, 1, 1, 1));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(1, 1, 1, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0, 0, 0, 128));
	mat->getTechnique(0)->getPass(0)->setShininess(0);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("marinediffmap.tga");
	tus->setTextureFiltering(FilterOptions::FO_POINT, FilterOptions::FO_POINT, FilterOptions::FO_POINT);



	// ============================ genmarineglass ============================================
	mat = MaterialManager::getSingleton().create("genmarineglass", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("marinediffmap.tga");


	// ============================ glassmat ============================================
	mat = MaterialManager::getSingleton().create("glassmat", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.8, 0.8, 0.8, 1));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.8, 0.8, 0.8, 1));
	mat->getTechnique(0)->getPass(0)->setShininess(40);
	mat->getTechnique(0)->getPass(0)->setSceneBlending(SBF_ONE, SBF_ONE_MINUS_SOURCE_ALPHA);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("glass1_d.tga");



	// ============================ metalplates ============================================
	mat = MaterialManager::getSingleton().create("metalplates", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193);
	mat->getTechnique(0)->getPass(0)->setSceneBlending(SBF_ONE, SBF_ONE_MINUS_SOURCE_ALPHA);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("metalplates_d.tga");



	// ============================ floor03_d ============================================
	mat = MaterialManager::getSingleton().create("floor03_d", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("floor03_d.tga");



	// ============================ rust02_d ============================================
	mat = MaterialManager::getSingleton().create("rust02_d", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("rust02_d.tga");



	// ============================ door04_d ============================================
	mat = MaterialManager::getSingleton().create("door04_d", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("door04_d.tga");



	// ============================ cable_d ============================================
	mat = MaterialManager::getSingleton().create("cable_d", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("cable_d.tga");



	// ============================ roof01_d ============================================
	mat = MaterialManager::getSingleton().create("roof01_d", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("roof01_d.tga");



	// ============================ con2 ============================================
	mat = MaterialManager::getSingleton().create("con2", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193);
	mat->getTechnique(0)->getPass(0)->setSceneBlending(SBF_ONE, SBF_ONE_MINUS_SOURCE_ALPHA);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("con02_d.tga");



	// ============================ door1 ============================================
	mat = MaterialManager::getSingleton().create("door1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("door01_d.tga");



	// ============================ bricks3 ============================================
	mat = MaterialManager::getSingleton().create("bricks3", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("bricks03_d.tga");



	// ============================ door7 ============================================
	mat = MaterialManager::getSingleton().create("door7", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193);
	mat->getTechnique(0)->getPass(0)->setSceneBlending(SBF_ONE, SBF_ONE_MINUS_SOURCE_ALPHA);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("door07_d.tga");



	// ============================ con05 ============================================
	mat = MaterialManager::getSingleton().create("con05", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193);
	mat->getTechnique(0)->getPass(0)->setSceneBlending(SBF_ONE, SBF_ONE_MINUS_SOURCE_ALPHA);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("con05_d.tga");



	// ============================ door04 ============================================
	mat = MaterialManager::getSingleton().create("door04", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("door04_d.tga");



	// ============================ roof1 ============================================
	mat = MaterialManager::getSingleton().create("roof1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("roof01_d.tga");



	// ============================ door07 ============================================
	mat = MaterialManager::getSingleton().create("door07", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193);
	mat->getTechnique(0)->getPass(0)->setSceneBlending(SBF_ONE, SBF_ONE_MINUS_SOURCE_ALPHA);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("door07_d.tga");



	// ============================ rusty07 ============================================
	mat = MaterialManager::getSingleton().create("rusty07", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("rust07_d.tga");



	// ============================ floor1 ============================================
	mat = MaterialManager::getSingleton().create("floor1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("floor01_d.tga");



	// ============================ win01 ============================================
	mat = MaterialManager::getSingleton().create("win01", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("win01_d.tga");



	// ============================ door6 ============================================
	mat = MaterialManager::getSingleton().create("door6", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("door06_d.tga");



	// ============================ bricks03 ============================================
	mat = MaterialManager::getSingleton().create("bricks03", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("bricks01_d.tga");



	// ============================ blinn1 ============================================
	mat = MaterialManager::getSingleton().create("blinn1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0, 0, 0, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.5, 0.5, 0.5, 1));
	mat->getTechnique(0)->getPass(0)->setShininess(113.19);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("d_hqtent.tga");



	// ============================ humvee_1 ============================================
	mat = MaterialManager::getSingleton().create("humvee_1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.588, 0.588, 0.588, 1));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.588, 0.588, 0.588, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0, 0, 0, 10));
	mat->getTechnique(0)->getPass(0)->setShininess(0);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("humvee_d2.dds");



	// ============================ orig_signfirelane_smoothing ============================================
	mat = MaterialManager::getSingleton().create("orig_signfirelane_smoothing", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.588, 0.588, 0.588, 1));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.35, 0.35, 0.35, 1));
	mat->getTechnique(0)->getPass(0)->setShininess(45);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("lamppost_diffuse.tga");



	// ============================ leaflarge ============================================
	mat = MaterialManager::getSingleton().create("leaflarge", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.2, 0.2, 0.2, 43.2193));
	mat->getTechnique(0)->getPass(0)->setShininess(0);
	mat->getTechnique(0)->getPass(0)->setSceneBlending(SBT_TRANSPARENT_ALPHA);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("leaflarge_color.tga");



	// ============================ leafplant2 ============================================
	mat = MaterialManager::getSingleton().create("leafplant2", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.2, 0.2, 0.2, 43.2193));
	mat->getTechnique(0)->getPass(0)->setShininess(0);
	mat->getTechnique(0)->getPass(0)->setSceneBlending(SBT_TRANSPARENT_ALPHA);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("leafplant2_color.tga");



	// ============================ leafplant2_purple ============================================
	mat = MaterialManager::getSingleton().create("leafplant2_purple", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.2, 0.2, 0.2, 43.2193));
	mat->getTechnique(0)->getPass(0)->setShininess(0);
	mat->getTechnique(0)->getPass(0)->setSceneBlending(SBT_TRANSPARENT_ALPHA);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("leafplant2_purple_color.tga");



	// ============================ leafplant3 ============================================
	mat = MaterialManager::getSingleton().create("leafplant3", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.2, 0.2, 0.2, 43.2193));
	mat->getTechnique(0)->getPass(0)->setShininess(0);
	mat->getTechnique(0)->getPass(0)->setSceneBlending(SBT_TRANSPARENT_ALPHA);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("leafplant3_color.tga");



	// ============================ leafplant4 ============================================
	mat = MaterialManager::getSingleton().create("leafplant4", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.2, 0.2, 0.2, 43.2193));
	mat->getTechnique(0)->getPass(0)->setShininess(0);
	mat->getTechnique(0)->getPass(0)->setSceneBlending(SBT_TRANSPARENT_ALPHA);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("leafplant4_color.tga");



	// ============================ lemonmat ============================================
	mat = MaterialManager::getSingleton().create("lemonmat", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setShininess(50);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("lemon_d.tga");



	// ============================ standard_1 ============================================
	mat = MaterialManager::getSingleton().create("standard_1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.588, 0.588, 0.588, 1));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.588, 0.588, 0.588, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0, 0, 0, 10));
	mat->getTechnique(0)->getPass(0)->setShininess(0);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("oilbarrel_diffuseyellow.tga");



	// ============================ 03-default ============================================
	mat = MaterialManager::getSingleton().create("03-default", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.254902, 0.254902, 0.254902, 1));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.254902, 0.254902, 0.254902, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.225, 0.225, 0.225, 17));
	mat->getTechnique(0)->getPass(0)->setShininess(0);



	// ============================ 04-default ============================================
	mat = MaterialManager::getSingleton().create("04-default", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.341176, 0.341176, 0.341176, 1));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.341176, 0.341176, 0.341176, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0, 0, 0, 10));
	mat->getTechnique(0)->getPass(0)->setShininess(0);



	// ============================ #29 ============================================
	mat = MaterialManager::getSingleton().create("#29", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.588, 0.588, 0.588, 1));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.588, 0.588, 0.588, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0, 0, 0, 10));
	mat->getTechnique(0)->getPass(0)->setShininess(0);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("oilpump.png");



	// ============================ metal_leaking3 ============================================
	mat = MaterialManager::getSingleton().create("metal_leaking3", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("metal_leaking03.tga");



	// ============================ metal1 ============================================
	mat = MaterialManager::getSingleton().create("metal1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("metal01_d.tga");



	// ============================ floor3 ============================================
	mat = MaterialManager::getSingleton().create("floor3", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("floor03_d.tga");



	// ============================ rusty5 ============================================
	mat = MaterialManager::getSingleton().create("rusty5", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193);
	mat->getTechnique(0)->getPass(0)->setSceneBlending(SBF_ONE, SBF_ONE_MINUS_SOURCE_ALPHA);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("rust05_d.tga");



	// ============================ con5 ============================================
	mat = MaterialManager::getSingleton().create("con5", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193);
	mat->getTechnique(0)->getPass(0)->setSceneBlending(SBF_ONE, SBF_ONE_MINUS_SOURCE_ALPHA);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("con05_d.tga");



	// ============================ metal2 ============================================
	mat = MaterialManager::getSingleton().create("metal2", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193);
	mat->getTechnique(0)->getPass(0)->setSceneBlending(SBF_ONE, SBF_ONE_MINUS_SOURCE_ALPHA);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("metal02_d.tga");



	// ============================ h1_copy ============================================
	mat = MaterialManager::getSingleton().create("h1_copy", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setShininess(80);
	mat->getTechnique(0)->getPass(0)->setSceneBlending(SBF_ONE, SBF_ONE_MINUS_SOURCE_ALPHA);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("h1_copy.tga");



	// ============================ h10 ============================================
	mat = MaterialManager::getSingleton().create("h10", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.02, 0.02, 0.02, 1));
	mat->getTechnique(0)->getPass(0)->setShininess(40);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("h10.tga");



	// ============================ h11 ============================================
	mat = MaterialManager::getSingleton().create("h11", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setShininess(80);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("h11.tga");



	// ============================ h2 ============================================
	mat = MaterialManager::getSingleton().create("h2", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setShininess(40);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("h2.tga");



	// ============================ h3 ============================================
	mat = MaterialManager::getSingleton().create("h3", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setShininess(80);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("h3.tga");



	// ============================ h4 ============================================
	mat = MaterialManager::getSingleton().create("h4", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setShininess(40);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("h4.tga");



	// ============================ h5 ============================================
	mat = MaterialManager::getSingleton().create("h5", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.05, 0.05, 0.05, 1));
	mat->getTechnique(0)->getPass(0)->setShininess(40);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("h5.tga");



	// ============================ h6 ============================================
	mat = MaterialManager::getSingleton().create("h6", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setShininess(40);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("h6.tga");



	// ============================ h7 ============================================
	mat = MaterialManager::getSingleton().create("h7", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setShininess(80);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("h7.tga");



	// ============================ h8 ============================================
	mat = MaterialManager::getSingleton().create("h8", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setShininess(80);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("h8.tga");



	// ============================ rust03 ============================================
	mat = MaterialManager::getSingleton().create("rust03", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("rust03_d.tga");



	// ============================ orangemat ============================================
	mat = MaterialManager::getSingleton().create("orangemat", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setShininess(50);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("orange_d.tga");



	// ============================ platemat ============================================
	mat = MaterialManager::getSingleton().create("platemat", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.9, 0.9, 0.9, 1));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.7, 0.7, 0.7, 1));
	mat->getTechnique(0)->getPass(0)->setShininess(50);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("plate_d.tga");



	// ============================ __25 ============================================
	mat = MaterialManager::getSingleton().create("__25", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("texmap2.jpg");



	// ============================ rust01 ============================================
	mat = MaterialManager::getSingleton().create("rust01", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("rust03_d.tga");



	// ============================ #52 ============================================
	mat = MaterialManager::getSingleton().create("#52", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.588, 0.588, 0.588, 1));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.588, 0.588, 0.588, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0, 0, 0, 10));
	mat->getTechnique(0)->getPass(0)->setShininess(0);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("wallandssrange_bk.jpg");



	// ============================ shootingrangewall1 ============================================
	mat = MaterialManager::getSingleton().create("shootingrangewall1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.588, 0.588, 0.588, 1));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.588, 0.588, 0.588, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0, 0, 0, 10));
	mat->getTechnique(0)->getPass(0)->setShininess(0);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("shootingrangewall1.jpg");



	// ============================ metal03_d ============================================
	mat = MaterialManager::getSingleton().create("metal03_d", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("metal03_d.tga");



	// ============================ soldier01-default_ogremax ============================================
	mat = MaterialManager::getSingleton().create("soldier01-default_ogremax", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.588235, 0.588235, 0.588235, 1));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.588235, 0.588235, 0.588235, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0, 0, 0, 1));
	mat->getTechnique(0)->getPass(0)->setShininess(10);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("usmc_lowpoly.jpg");
	tus->setTextureFiltering(FilterOptions::FO_LINEAR, FilterOptions::FO_LINEAR, FilterOptions::FO_LINEAR);



	// ============================ soldierm4a1_ogremax ============================================
	mat = MaterialManager::getSingleton().create("soldierm4a1_ogremax", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.588, 0.588, 0.588, 1));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.588, 0.588, 0.588, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0, 0, 0, 1));
	mat->getTechnique(0)->getPass(0)->setShininess(10);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("m4a1.jpg");
	tus->setTextureFiltering(FilterOptions::FO_LINEAR, FilterOptions::FO_LINEAR, FilterOptions::FO_LINEAR);



	// ============================ spawn_point ============================================
	mat = MaterialManager::getSingleton().create("spawn_point", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.537, 0.341, 0.341, 1));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.537, 0.341, 0.341, 1));



	// ============================ meatsteakburntmat ============================================
	mat = MaterialManager::getSingleton().create("meatsteakburntmat", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.3, 0.3, 0.3, 1));
	mat->getTechnique(0)->getPass(0)->setShininess(50);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("meatsteakburnt_d.tga");



	// ============================ meatsteakcookedmat ============================================
	mat = MaterialManager::getSingleton().create("meatsteakcookedmat", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.3, 0.3, 0.3, 1));
	mat->getTechnique(0)->getPass(0)->setShininess(70);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("meatsteakcooked_d.tga");



	// ============================ stonewall1 ============================================
	mat = MaterialManager::getSingleton().create("stonewall1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.588, 0.588, 0.588, 1));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.588, 0.588, 0.588, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0, 0, 0, 10));
	mat->getTechnique(0)->getPass(0)->setShininess(0);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("r_wall1tex_d2.png");



	// ============================ stonewall2 ============================================
	mat = MaterialManager::getSingleton().create("stonewall2", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.588, 0.588, 0.588, 1));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.588, 0.588, 0.588, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0, 0, 0, 10));
	mat->getTechnique(0)->getPass(0)->setShininess(0);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("r_wall2tex_d2.png");



	// ============================ stonewall3 ============================================
	mat = MaterialManager::getSingleton().create("stonewall3", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.588, 0.588, 0.588, 1));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.588, 0.588, 0.588, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0, 0, 0, 10));
	mat->getTechnique(0)->getPass(0)->setShininess(0);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("r_wall3tex_d2.png");



	// ============================ stonewall4 ============================================
	mat = MaterialManager::getSingleton().create("stonewall4", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.588, 0.588, 0.588, 1));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.588, 0.588, 0.588, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0, 0, 0, 10));
	mat->getTechnique(0)->getPass(0)->setShininess(0);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("r_wall4tex_d2.png");



	// ============================ _stone1stones_df2 ============================================
	mat = MaterialManager::getSingleton().create("_stone1stones_df2", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.588235, 0.588235, 0.588235, 1));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.588235, 0.588235, 0.588235, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.05, 0.05, 0.05, 1));
	mat->getTechnique(0)->getPass(0)->setShininess(0);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("stones_df2.tga");



	// ============================ _stone1_lod2stones_df2 ============================================
	mat = MaterialManager::getSingleton().create("_stone1_lod2stones_df2", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.588235, 0.588235, 0.588235, 1));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.588235, 0.588235, 0.588235, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.05, 0.05, 0.05, 1));
	mat->getTechnique(0)->getPass(0)->setShininess(0);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("stones_df2.tga");



	// ============================ _stone2stones_df2 ============================================
	mat = MaterialManager::getSingleton().create("_stone2stones_df2", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.588235, 0.588235, 0.588235, 1));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.588235, 0.588235, 0.588235, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.1, 0.1, 0.1, 1));
	mat->getTechnique(0)->getPass(0)->setShininess(0);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("stones_df2.tga");



	// ============================ _stone2_lod2stones_df2 ============================================
	mat = MaterialManager::getSingleton().create("_stone2_lod2stones_df2", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.588235, 0.588235, 0.588235, 1));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.588235, 0.588235, 0.588235, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.05, 0.05, 0.05, 1));
	mat->getTechnique(0)->getPass(0)->setShininess(0);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("stones_df2.tga");



	// ============================ _stone3stones_df ============================================
	mat = MaterialManager::getSingleton().create("_stone3stones_df", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.588235, 0.588235, 0.588235, 1));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.588235, 0.588235, 0.588235, 1));
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("stones_df.tga");



	// ============================ _stone3_lod2stones_df ============================================
	mat = MaterialManager::getSingleton().create("_stone3_lod2stones_df", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.588235, 0.588235, 0.588235, 1));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.588235, 0.588235, 0.588235, 1));
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("stones_df.tga");



	// ============================ _stone4stones_df2 ============================================
	mat = MaterialManager::getSingleton().create("_stone4stones_df2", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.588235, 0.588235, 0.588235, 1));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.588235, 0.588235, 0.588235, 1));
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("stones_df2.tga");



	// ============================ _stone4_lod2stones_df2 ============================================
	mat = MaterialManager::getSingleton().create("_stone4_lod2stones_df2", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.588235, 0.588235, 0.588235, 1));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.588235, 0.588235, 0.588235, 1));
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("stones_df2.tga");



	// ============================ _stone5stones_df ============================================
	mat = MaterialManager::getSingleton().create("_stone5stones_df", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.588235, 0.588235, 0.588235, 1));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.588235, 0.588235, 0.588235, 1));
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("stones_df.tga");



	// ============================ _stone5_lod2stones_df ============================================
	mat = MaterialManager::getSingleton().create("_stone5_lod2stones_df", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.588235, 0.588235, 0.588235, 1));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.588235, 0.588235, 0.588235, 1));
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("stones_df.tga");



	// ============================ _stone6stones_df2 ============================================
	mat = MaterialManager::getSingleton().create("_stone6stones_df2", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.588235, 0.588235, 0.588235, 1));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.588235, 0.588235, 0.588235, 1));
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("stones_df2.tga");



	// ============================ _stone6_lod1stones_df2 ============================================
	mat = MaterialManager::getSingleton().create("_stone6_lod1stones_df2", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.588235, 0.588235, 0.588235, 1));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.588235, 0.588235, 0.588235, 1));
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("stones_df2.tga");



	// ============================ con02_d ============================================
	mat = MaterialManager::getSingleton().create("con02_d", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193);
	mat->getTechnique(0)->getPass(0)->setSceneBlending(SBF_ONE, SBF_ONE_MINUS_SOURCE_ALPHA);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("con02_d.tga");



	// ============================ metal_leaking02 ============================================
	mat = MaterialManager::getSingleton().create("metal_leaking02", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193);
	mat->getTechnique(0)->getPass(0)->setSceneBlending(SBF_ONE, SBF_ONE_MINUS_SOURCE_ALPHA);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("metal_leaking02_d.tga");



	// ============================ #41 ============================================
	mat = MaterialManager::getSingleton().create("#41", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.588, 0.588, 0.588, 1));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.588, 0.588, 0.588, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0, 0, 0, 10));
	mat->getTechnique(0)->getPass(0)->setShininess(0);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("range2.jpg");



	// ============================ tower ============================================
	mat = MaterialManager::getSingleton().create("tower", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setShininess(80);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("tower.tga");



	// ============================ metalstripes ============================================
	mat = MaterialManager::getSingleton().create("metalstripes", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193);
	mat->getTechnique(0)->getPass(0)->setSceneBlending(SBF_ONE, SBF_ONE_MINUS_SOURCE_ALPHA);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("metal_stripes_d.tga");



	// ============================ metal_cylinder01_d ============================================
	mat = MaterialManager::getSingleton().create("metal_cylinder01_d", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193);
	mat->getTechnique(0)->getPass(0)->setSceneBlending(SBF_ONE, SBF_ONE_MINUS_SOURCE_ALPHA);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("metal_cylinder01_d.tga");



	// ============================ train_d ============================================
	mat = MaterialManager::getSingleton().create("train_d", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("train_d.tga");



	// ============================ rails_d ============================================
	mat = MaterialManager::getSingleton().create("rails_d", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("rails_d.tga");



	// ============================ _tree1bigtreedf1 ============================================
	mat = MaterialManager::getSingleton().create("_tree1bigtreedf1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.588235, 0.588235, 0.588235, 1));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.588235, 0.588235, 0.588235, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.05, 0.05, 0.05, 1));
	mat->getTechnique(0)->getPass(0)->setShininess(0);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("bigtreedf1.tga");



	// ============================ _tree1bigtreedf2 ============================================
	mat = MaterialManager::getSingleton().create("_tree1bigtreedf2", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.588235, 0.588235, 0.588235, 1));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.588235, 0.588235, 0.588235, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.05, 0.05, 0.05, 1));
	mat->getTechnique(0)->getPass(0)->setShininess(0);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("bigtreedf2.tga");



	// ============================ _tree2bigtreedf1 ============================================
	mat = MaterialManager::getSingleton().create("_tree2bigtreedf1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.588235, 0.588235, 0.588235, 1));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.588235, 0.588235, 0.588235, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.05, 0.05, 0.05, 1));
	mat->getTechnique(0)->getPass(0)->setShininess(0);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("bigtreedf1.tga");



	// ============================ _tree2bigtreedf2 ============================================
	mat = MaterialManager::getSingleton().create("_tree2bigtreedf2", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.588235, 0.588235, 0.588235, 1));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.588235, 0.588235, 0.588235, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.05, 0.05, 0.05, 1));
	mat->getTechnique(0)->getPass(0)->setShininess(0);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("bigtreedf2.tga");



	// ============================ _tree2leaf_df ============================================
	mat = MaterialManager::getSingleton().create("_tree2leaf_df", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.588235, 0.588235, 0.588235, 1));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.588235, 0.588235, 0.588235, 1));
	mat->getTechnique(0)->getPass(0)->setSceneBlending(SBT_TRANSPARENT_ALPHA);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("leaf_df.tga");



	// ============================ _tree3bigtreedf1 ============================================
	mat = MaterialManager::getSingleton().create("_tree3bigtreedf1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.588235, 0.588235, 0.588235, 1));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.588235, 0.588235, 0.588235, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.05, 0.05, 0.05, 1));
	mat->getTechnique(0)->getPass(0)->setShininess(0);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("bigtreedf1.tga");



	// ============================ _tree3bigtreedf2 ============================================
	mat = MaterialManager::getSingleton().create("_tree3bigtreedf2", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.588235, 0.588235, 0.588235, 1));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.588235, 0.588235, 0.588235, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.05, 0.05, 0.05, 1));
	mat->getTechnique(0)->getPass(0)->setShininess(0);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("bigtreedf2.tga");



	// ============================ _tree3leaf_df ============================================
	mat = MaterialManager::getSingleton().create("_tree3leaf_df", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.588235, 0.588235, 0.588235, 1));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.588235, 0.588235, 0.588235, 1));
	mat->getTechnique(0)->getPass(0)->setSceneBlending(SBT_TRANSPARENT_ALPHA);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("leaf_df.tga");



	// ============================ _veg1leaf33 ============================================
	mat = MaterialManager::getSingleton().create("_veg1leaf33", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.588235, 0.588235, 0.588235, 1));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.588235, 0.588235, 0.588235, 1));
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("leaf33.tga");



	// ============================ _veg1_lod2leaf33 ============================================
	mat = MaterialManager::getSingleton().create("_veg1_lod2leaf33", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.588235, 0.588235, 0.588235, 1));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.588235, 0.588235, 0.588235, 1));
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("leaf33.tga");



	// ============================ _veg10palm2_trunk_df ============================================
	mat = MaterialManager::getSingleton().create("_veg10palm2_trunk_df", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.588235, 0.588235, 0.588235, 1));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.588235, 0.588235, 0.588235, 1));
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("palm2_trunk_df.tga");



	// ============================ _veg10palmleaf1_df ============================================
	mat = MaterialManager::getSingleton().create("_veg10palmleaf1_df", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.588235, 0.588235, 0.588235, 1));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.588235, 0.588235, 0.588235, 1));
	mat->getTechnique(0)->getPass(0)->setSceneBlending(SBT_TRANSPARENT_ALPHA);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("palmleaf1_df.tga");



	// ============================ _veg2leaf33 ============================================
	mat = MaterialManager::getSingleton().create("_veg2leaf33", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.588235, 0.588235, 0.588235, 1));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.588235, 0.588235, 0.588235, 1));
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("leaf33.tga");



	// ============================ _veg2_lod2leaf33 ============================================
	mat = MaterialManager::getSingleton().create("_veg2_lod2leaf33", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.588235, 0.588235, 0.588235, 1));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.588235, 0.588235, 0.588235, 1));
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("leaf33.tga");



	// ============================ _veg4leaf2_df ============================================
	mat = MaterialManager::getSingleton().create("_veg4leaf2_df", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.588235, 0.588235, 0.588235, 1));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.588235, 0.588235, 0.588235, 1));
	mat->getTechnique(0)->getPass(0)->setSceneBlending(SBT_TRANSPARENT_ALPHA);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("leaf2_df.tga");



	// ============================ _veg4_lod1leaf2_df ============================================
	mat = MaterialManager::getSingleton().create("_veg4_lod1leaf2_df", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.588235, 0.588235, 0.588235, 1));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.588235, 0.588235, 0.588235, 1));
	mat->getTechnique(0)->getPass(0)->setSceneBlending(SBT_TRANSPARENT_ALPHA);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("leaf2_df.tga");



	// ============================ _veg4_lod2leaf2_df ============================================
	mat = MaterialManager::getSingleton().create("_veg4_lod2leaf2_df", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.588235, 0.588235, 0.588235, 1));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.588235, 0.588235, 0.588235, 1));
	mat->getTechnique(0)->getPass(0)->setSceneBlending(SBT_TRANSPARENT_ALPHA);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("leaf2_df.tga");



	// ============================ _veg8palm3_trunk_df ============================================
	mat = MaterialManager::getSingleton().create("_veg8palm3_trunk_df", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.588235, 0.588235, 0.588235, 1));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.588235, 0.588235, 0.588235, 1));
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("palm3_trunk_df.tga");



	// ============================ _veg8_lod2palm3_trunk_df ============================================
	mat = MaterialManager::getSingleton().create("_veg8_lod2palm3_trunk_df", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.588235, 0.588235, 0.588235, 1));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.588235, 0.588235, 0.588235, 1));
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("palm3_trunk_df.tga");



	// ============================ _veg8_lod2palmleaf2_df ============================================
	mat = MaterialManager::getSingleton().create("_veg8_lod2palmleaf2_df", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.588235, 0.588235, 0.588235, 1));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.588235, 0.588235, 0.588235, 1));
	mat->getTechnique(0)->getPass(0)->setSceneBlending(SBT_TRANSPARENT_ALPHA);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("palmleaf2_df.tga");



	// ============================ _veg9palm1_trunk_df ============================================
	mat = MaterialManager::getSingleton().create("_veg9palm1_trunk_df", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.588235, 0.588235, 0.588235, 1));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.588235, 0.588235, 0.588235, 1));
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("palm1_trunk_df.tga");



	// ============================ _veg9palmleaf2_df ============================================
	mat = MaterialManager::getSingleton().create("_veg9palmleaf2_df", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.588235, 0.588235, 0.588235, 1));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.588235, 0.588235, 0.588235, 1));
	mat->getTechnique(0)->getPass(0)->setSceneBlending(SBT_TRANSPARENT_ALPHA);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("palmleaf2_df.tga");



	// ============================ _veg9_lod2palm1_trunk_df ============================================
	mat = MaterialManager::getSingleton().create("_veg9_lod2palm1_trunk_df", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.588235, 0.588235, 0.588235, 1));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.588235, 0.588235, 0.588235, 1));
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("palm1_trunk_df.tga");



	// ============================ _veg9_lod2palmleaf2_df ============================================
	mat = MaterialManager::getSingleton().create("_veg9_lod2palmleaf2_df", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.588235, 0.588235, 0.588235, 1));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.588235, 0.588235, 0.588235, 1));
	mat->getTechnique(0)->getPass(0)->setSceneBlending(SBT_TRANSPARENT_ALPHA);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("palmleaf2_df.tga");



	// ============================ villagechurch ============================================
	mat = MaterialManager::getSingleton().create("villagechurch", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setSceneBlending(SBF_DEST_COLOUR, SBF_ZERO);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("vchurch_fpsctex_d2.png");



	// ============================ villagefence1 ============================================
	mat = MaterialManager::getSingleton().create("villagefence1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.588, 0.588, 0.588, 1));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.588, 0.588, 0.588, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0, 0, 0, 10));
	mat->getTechnique(0)->getPass(0)->setShininess(0);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("panel_1tex_d2.png");



	// ============================ villagefence2 ============================================
	mat = MaterialManager::getSingleton().create("villagefence2", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.588, 0.588, 0.588, 1));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.588, 0.588, 0.588, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0, 0, 0, 10));
	mat->getTechnique(0)->getPass(0)->setShininess(0);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("panel_1tex_d2.png");



	// ============================ villagefence3 ============================================
	mat = MaterialManager::getSingleton().create("villagefence3", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.588, 0.588, 0.588, 1));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.588, 0.588, 0.588, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0, 0, 0, 10));
	mat->getTechnique(0)->getPass(0)->setShininess(0);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("panel_1tex_d2.png");



	// ============================ villagehouse1 ============================================
	mat = MaterialManager::getSingleton().create("villagehouse1", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.588, 0.588, 0.588, 1));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.588, 0.588, 0.588, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0, 0, 0, 10));
	mat->getTechnique(0)->getPass(0)->setShininess(0);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("vhs1_fpsctex_d2.png");



	// ============================ villagehouse2 ============================================
	mat = MaterialManager::getSingleton().create("villagehouse2", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.588, 0.588, 0.588, 1));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.588, 0.588, 0.588, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0, 0, 0, 10));
	mat->getTechnique(0)->getPass(0)->setShininess(0);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("vhs2_fpsctex_d2.png");



	// ============================ villagehouse3 ============================================
	mat = MaterialManager::getSingleton().create("villagehouse3", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.588, 0.588, 0.588, 1));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.588, 0.588, 0.588, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0, 0, 0, 10));
	mat->getTechnique(0)->getPass(0)->setShininess(0);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("vhs3_fpsctex_d2.png");



	// ============================ villagehouse4 ============================================
	mat = MaterialManager::getSingleton().create("villagehouse4", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.588, 0.588, 0.588, 1));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.588, 0.588, 0.588, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0, 0, 0, 10));
	mat->getTechnique(0)->getPass(0)->setShininess(0);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("vhs4_fpsctex_d2.png");



	// ============================ villagehouse5 ============================================
	mat = MaterialManager::getSingleton().create("villagehouse5", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.588, 0.588, 0.588, 1));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.588, 0.588, 0.588, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0, 0, 0, 10));
	mat->getTechnique(0)->getPass(0)->setShininess(0);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("vhs5_fpsctex_d2.png");



	// ============================ villagehouse6 ============================================
	mat = MaterialManager::getSingleton().create("villagehouse6", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.588, 0.588, 0.588, 1));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.588, 0.588, 0.588, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0, 0, 0, 10));
	mat->getTechnique(0)->getPass(0)->setShininess(0);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("vhs6_fpsctex_d2.png");



	// ============================ villagehouse7 ============================================
	mat = MaterialManager::getSingleton().create("villagehouse7", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.588, 0.588, 0.588, 1));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.588, 0.588, 0.588, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0, 0, 0, 10));
	mat->getTechnique(0)->getPass(0)->setShininess(0);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("vhs7_fpsctex_d2.png");



	// ============================ road_village_tcross ============================================
	mat = MaterialManager::getSingleton().create("road_village_tcross", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.8, 0.8, 0.8, 1));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setShininess(80);
	mat->getTechnique(0)->getPass(0)->setSceneBlending(SBF_ONE, SBF_ONE_MINUS_SOURCE_ALPHA);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("road_village_tcross.tga");



	// ============================ street_old ============================================
	mat = MaterialManager::getSingleton().create("street_old", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.8, 0.8, 0.8, 1));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setShininess(80);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("street_old.tga");



	// ============================ road_village_curve ============================================
	mat = MaterialManager::getSingleton().create("road_village_curve", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(0.8, 0.8, 0.8, 1));
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setShininess(80);
	mat->getTechnique(0)->getPass(0)->setSceneBlending(SBF_ONE, SBF_ONE_MINUS_SOURCE_ALPHA);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("road_village_curve.tga");



	// ============================ floor01_d ============================================
	mat = MaterialManager::getSingleton().create("floor01_d", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("floor05_d.tga");



	// ============================ metal_leaking ============================================
	mat = MaterialManager::getSingleton().create("metal_leaking", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("metal_leaking_d.tga");



	// ============================ floor03 ============================================
	mat = MaterialManager::getSingleton().create("floor03", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("floor03_d.tga");



	// ============================ con02 ============================================
	mat = MaterialManager::getSingleton().create("con02", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setSpecular(ColourValue(0.2, 0.2, 0.2, 1));
	mat->getTechnique(0)->getPass(0)->setShininess(43.2193);
	mat->getTechnique(0)->getPass(0)->setSceneBlending(SBF_ONE, SBF_ONE_MINUS_SOURCE_ALPHA);
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("con02_d.tga");



	// ============================ zombie ============================================
	mat = MaterialManager::getSingleton().create("zombie", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	mat->setReceiveShadows(true);
	mat->setTransparencyCastsShadows(false);
	mat->getTechnique(0)->setLightingEnabled(false);
	mat->getTechnique(0)->setSchemeName("Default");
	tus = mat->getTechnique(0)->getPass(0)->createTextureUnitState();
	tus->setTextureName("zombie.jpg");
	pass = mat->getTechnique(0)->createPass();
	tus = mat->getTechnique(0)->getPass(1)->createTextureUnitState();
	tus->setTextureName("zombie.jpg");

}