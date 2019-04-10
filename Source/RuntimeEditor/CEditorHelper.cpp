#include "CEditorHelper.h"
#include "CGameObject.h"
#include "CGameManager.h"
#include "CNatureManager.h"
#include "CGameObjectManager.h"
#include "CCameraManager.h"
#include "CPlayer.h"
#include "CBuilding.h"
#include "CUtility.h"
#include "CGameObjectManager.h"
#include "CPhysicsManager.h"
#include "IPhysicsStrategy.h"
#include "CItemsManager.h"
#include "Audio/CSoundManager.h"
#include "SceneImporterPackage.h"
#include "CGuiManager.h"

// MyGUI specific plugin
#include "../PluginMyGui/CGuiStrategy_MyGui.h"

#include "RuntimeEditor/CRuntimeEditorManager.h"
#include "CMenuDirector.h"
#include "VisualDebugger/Procedural.h"
#include "MyGui/MyGUI.h"

#include "Terrain/OgreTerrainGroup.h"
#include "OgreQuaternion.h"

using namespace Core;
using namespace Core::Physics;
using namespace Core::Effects;
using namespace Core::Editor;

u32 counter = 0;

ManualObject* CEditorHelper::Draw3D_Line(const Vector3& from, const Vector3& to, const ColourValue& Color, String& matName)
{
	auto gm = CGameManager::Instance();
	auto sm = gm->GetSceneManager();

	auto myManualObject =  sm->createManualObject("obj_" + StringConverter::toString(counter)); 
	auto myManualObjectNode = sm->getRootSceneNode()->createChildSceneNode("node_" + StringConverter::toString(counter)); 

	if(matName == "")
		matName = "mat" + StringConverter::toString(counter);

	MaterialPtr mat = MaterialManager::getSingleton().create(matName, ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME); 
	mat->setReceiveShadows(false); 
	mat->getTechnique(0)->setLightingEnabled(true); 
	mat->getTechnique(0)->getPass(0)->setDiffuse(Color); 
	mat->getTechnique(0)->getPass(0)->setAmbient(Color); 
	mat->getTechnique(0)->getPass(0)->setSelfIllumination(Color); 
	//mat->dispose();  // dispose pointer, not the material

	myManualObject->begin(mat->getName(), RenderOperation::OT_LINE_LIST); 
	myManualObject->position(from); 
	myManualObject->position(to); 
	// etc 
	myManualObject->end(); 

	myManualObjectNode->attachObject(myManualObject);
	counter++;
	return myManualObject;
}

ManualObject* CEditorHelper::Draw3D_Lines(const Vector<Vector3>& from, const Vector<Vector3>& to, const ColourValue& Color, String& matName)
{
	if(from.size() != to.size())
		return nullptr;

	auto gm = CGameManager::Instance();
	auto sm = gm->GetSceneManager();

	auto myManualObject =  sm->createManualObject("obj_" + StringConverter::toString(counter)); 
	auto myManualObjectNode = sm->getRootSceneNode()->createChildSceneNode("node_" + StringConverter::toString(counter)); 

	if(matName == "")
		matName = "mat" + StringConverter::toString(counter);

	MaterialPtr mat = MaterialManager::getSingleton().create(matName, ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME); 
	mat->setReceiveShadows(false); 
	mat->getTechnique(0)->setLightingEnabled(true); 
	mat->getTechnique(0)->getPass(0)->setDiffuse(Color); 
	mat->getTechnique(0)->getPass(0)->setAmbient(Color); 
	mat->getTechnique(0)->getPass(0)->setSelfIllumination(Color); 
	//mat->dispose();  // dispose pointer, not the material

	for(u32 i = 0; i < from.size(); i++)
	{
		myManualObject->begin(mat->getName(), RenderOperation::OT_LINE_LIST); 
		myManualObject->position(from[i]); 
		myManualObject->position(to[i]); 
		myManualObject->end(); 
	}

	myManualObjectNode->attachObject(myManualObject);
	counter++;
	return myManualObject;
}

CGameObject* CEditorHelper::AddObstacleBox(const Vector3& Position)
{
	auto obj = CGameObjectManager::Instance()->CreateObject("CRATE_1");

	if(obj)
	{
		obj->Node->setPosition(Position);
		CGameObjectManager::Instance()->AddBoxObstacle(obj);
	}
	return obj;
}

CGameObject* CEditorHelper::AddObstacleSphere(const Vector3& Position)
{
	using namespace Procedural;

	auto obj = CGameObjectManager::Instance()->CreateObject("CRATE_1");

	if(obj)
	{
		obj->Node->setPosition(Position);
		CGameObjectManager::Instance()->AddSphereObstacle(obj);

		// Get radius
		auto radius = obj->Entity->getBoundingRadius();
		auto center = obj->Node->getPosition();

		// If its been scaled
		Vector3 scale = obj->Node->getScale();
		if(scale.x > scale.y && scale.x > scale.z)
			radius *= scale.x;
		if(scale.y > scale.x && scale.y > scale.z)
			radius *= scale.y;
		else
			radius *= scale.z;

		Procedural::Root::getInstance()->sceneManager = CGameManager::Instance()->GetSceneManager();
		IcoSphereGenerator().setRadius(radius).setNumIterations(1).setUTile(5.).setVTile(5.).realizeMesh("icoSphereMesh" + obj->Name, obj->Node->getPosition());
	}
	return obj;
}

void CEditorHelper::AddPathNodeShape(const Vector3& Position)
{
	auto obj = CGameObjectManager::Instance()->CreateObject(PATH_MESH);
	if(obj)
	{
		obj->Node->setPosition(Position);
		obj->EnvironmentType = EAT_EDITOR;
	}
}

void CEditorHelper::AddAStarNodeShapes(const Vector<Vector3>& Positions)
{
	String matName = "mat" + StringConverter::toString(counter);
	MaterialPtr mat = MaterialManager::getSingleton().create(matName, ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME); 
	mat->setReceiveShadows(false); 
	mat->getTechnique(0)->setLightingEnabled(true); 
	mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue::Blue); 
	mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue::Blue); 
	mat->getTechnique(0)->getPass(0)->setSelfIllumination(ColourValue::Blue); 

	for(u32 i = 0; i < Positions.size(); i++)
	{
		auto obj = CGameObjectManager::Instance()->CreateObject(PATH_MESH);
		if(obj)
		{
			obj->Entity->setMaterial(mat);
			obj->EnvironmentType = EAT_EDITOR;
			obj->Node->setPosition(Positions[i]);
		}
	}
}

void CEditorHelper::AddLightShape(Light* OgreLight)
{
	MaterialPtr mat;
	if(!MaterialManager::getSingleton().resourceExists("light_shape_editor"))
	{
		mat = MaterialManager::getSingleton().create("light_shape_editor", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME); 
		mat->setReceiveShadows(false); 
		mat->getTechnique(0)->setLightingEnabled(true); 
		mat->getTechnique(0)->getPass(0)->setDiffuse(ColourValue(1.0, 1.0, 0.0)); 
		mat->getTechnique(0)->getPass(0)->setAmbient(ColourValue(1.0, 1.0, 0.0)); 
		mat->getTechnique(0)->getPass(0)->setSelfIllumination(ColourValue(1.0, 1.0, 0.0)); 
	}

	auto obj = CGameObjectManager::Instance()->CreateObject(PATH_MESH);
	if(obj)
	{
		obj->Entity->setMaterialName("light_shape_editor", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
		obj->EnvironmentType = EAT_EDITOR;
		obj->Node->setPosition(OgreLight->getPosition());
		obj->GameObjectType = LIGHT_EDITOR_MESH;
		obj->AttachedData = OgreLight;
	}
}

CGameObject* CEditorHelper::FindObject(f32 Width, f32 Height)
{
	auto point = MyGUI::InputManager::getInstance().getMousePosition();
	auto mouseRay = CCameraManager::Instance()->GetCamera()->getCameraToViewportRay(point.left / Width, point.top / Height);

	// Plane test
	auto rayQuery = CGameManager::Instance()->GetSceneManager()->createRayQuery(mouseRay);
	//mRayScnQuery->setQueryTypeMask(SceneManager::ENTITY_TYPE_MASK);
	rayQuery->setSortByDistance(true);
	RaySceneQueryResult& result = rayQuery->execute();
	for(auto iter = result.begin(); iter != result.end(); iter++)
	{
		if(iter->movable)
		{ 
			auto obj = CGameObjectManager::Instance()->GetGameObjectByEntityName(iter->movable->getName().c_str());
			if(obj)
				return obj;
		}
	}
	return nullptr;
}

bool CEditorHelper::FindSelected(f32 Width, f32 Height, SELECTED& Selected)
{
	// Check if we are clicking on something in the scene
	auto obj = FindObject(Width, Height);
	if(obj)
	{
		if(obj->GameObjectType == PATH_MESH)
		{
			Selected.Type = ST_PATH;
		}
		else if(obj->GameObjectType == String(SPAWN_POINT_MESH))
		{
			Selected.Type = ST_SPAWN_POINT;
		}
		else if(obj->GameObjectType == String(LIGHT_EDITOR_MESH))
		{
			Selected.Type = ST_LIGHT;
			Selected.Selected = obj;
			return true;
		}
		else
		{
			Selected.Type = ST_OBJ;
		}

		Selected.Name = obj->Name;
		Selected.Selected = obj;
		return true;
	}

	auto player = FindPlayer(Width, Height);
	if(player)
	{
		Selected.Type = ST_PLAYER;
		Selected.Name = player->GetName();
		Selected.Selected = player;
		return true;
	}

	auto building = FindBuilding(Width, Height);
	if(building)
	{
		Selected.Type = ST_BUILDING;
		Selected.Name = building->GetName();
		Selected.Selected = building;
		return true;
	}

	auto sound_entity = FindSound(Width, Height);
	if(sound_entity)
	{
		Selected.Type = ST_SOUND_ENTITY;
		Selected.Name = sound_entity->getName();
		Selected.Selected = sound_entity;
		return true;
	}
	return false;
}

Entity* CEditorHelper::FindSound(f32 Width, f32 Height)
{
	auto point = MyGUI::InputManager::getInstance().getMousePosition();
	auto mouseRay = CCameraManager::Instance()->GetCamera()->getCameraToViewportRay(point.left / Width, point.top / Height);

	// Plane test
	auto mRayScnQuery = CGameManager::Instance()->GetSceneManager()->createRayQuery(Ray());
	mRayScnQuery->setRay(mouseRay);
	RaySceneQueryResult& result = mRayScnQuery->execute();
	for(auto iter = result.begin(); iter != result.end(); iter++)
	{
		if(iter->movable)
		{
			// Looking for something like 'node_SOUND_BILLBOARD_1'
			auto found = iter->movable->getName().find(SOUND_BILLBOARD);
			if(found == String("node_").length())
			{
				return static_cast<Entity*>(iter->movable);
			}
		}
	}
	return nullptr;
}

CPlayer* CEditorHelper::FindPlayer(f32 Width, f32 Height)
{
	auto point = MyGUI::InputManager::getInstance().getMousePosition();
	auto mouseRay = CCameraManager::Instance()->GetCamera()->getCameraToViewportRay(point.left / Width, point.top / Height);

	// Plane test
	auto query = CGameManager::Instance()->GetSceneManager()->createRayQuery(Ray());
	query->setSortByDistance(true, 20);
	query->setQueryMask(SQF_PLAYER);
	query->setRay(mouseRay);
	RaySceneQueryResult& result = query->execute();
	for(auto iter = result.begin(); iter != result.end(); iter++)
	{
		if(iter->movable)
		{ 
			auto player = CGameObjectManager::Instance()->GetPlayerByEntityName(iter->movable->getName().c_str());
			if(player)
				return player;
		}
	}
	return nullptr;
}

CBuilding* CEditorHelper::FindBuilding(f32 Width, f32 Height)
{
	auto point = MyGUI::InputManager::getInstance().getMousePosition();
	auto mouseRay = CCameraManager::Instance()->GetCamera()->getCameraToViewportRay(point.left / Width, point.top / Height);

	// Plane test
	auto query = CGameManager::Instance()->GetSceneManager()->createRayQuery(Ray());
	query->setSortByDistance(true, 20);
	query->setQueryMask(SQF_PLAYER);
	query->setRay(mouseRay);
	RaySceneQueryResult& result = query->execute();
	for(auto iter = result.begin(); iter != result.end(); iter++)
	{
		if(iter->movable)
		{ 
			auto building = CGameObjectManager::Instance()->GetBuildingByEntityName(iter->movable->getName().c_str());
			if(building)
				return building;
		}
	}
	return nullptr;
}

Vector3 CEditorHelper::FindY(f32 Width, f32 Height)
{
	auto point = MyGUI::InputManager::getInstance().getMousePosition();
	auto mouseRay = CCameraManager::Instance()->GetCamera()->getCameraToViewportRay(point.left / Width, point.top / Height);

	// Plane test
	auto mRayScnQuery = CGameManager::Instance()->GetSceneManager()->createRayQuery(Ray());
	mRayScnQuery->setRay(mouseRay);
	RaySceneQueryResult& result = mRayScnQuery->execute();
	for(auto iter = result.begin(); iter != result.end(); iter++)
	{
		if(iter->movable)
		{ 
			if(iter->movable->getName().find(PLANE_ENTITY_NAME) != String::npos)
			{
				return mouseRay.getPoint(iter->distance);
			}
		}
	}

	// Paged terrain test
	if(Nature::CNatureManager::Instance()->GetTerrainGroup())
	{
		auto rayResult = Nature::CNatureManager::Instance()->GetTerrainGroup()->rayIntersects(mouseRay);
		if (rayResult.hit)
			return rayResult.position;
	}

	// Height map test
	auto m_TerrainRaySceneQuery = CGameManager::Instance()->GetSceneManager()->createRayQuery(Ray(Vector3(0.0f, 0.0f, 0.0f), Vector3::NEGATIVE_UNIT_Y));
	m_TerrainRaySceneQuery->setRay(mouseRay);
	RaySceneQueryResult& qryResult = m_TerrainRaySceneQuery->execute();
	RaySceneQueryResult::iterator it = qryResult.begin();
	if (it != qryResult.end() && it->worldFragment)
	{
		return it->worldFragment->singleIntersection;
	}

	return Vector3::NEGATIVE_UNIT_Y;
}

void CEditorHelper::CreateSoundBillBoard(const Vector3& Position)
{
	auto myNode = static_cast<SceneNode*>(CGameManager::Instance()->GetSceneManager()->getRootSceneNode()->createChild());
	auto name = String(SOUND_BILLBOARD) + StringConverter::toString(counter);
	auto mySet = CGameManager::Instance()->GetSceneManager()->createBillboardSet(name);
	auto myBillboard = mySet->createBillboard(Position);
	mySet->setMaterialName("SoundBillBoard");

	auto entity = CGameManager::Instance()->GetSceneManager()->createEntity("test", SceneManager::PT_SPHERE);
	entity->setQueryFlags(SQF_EDITOR);
	entity->setVisible(true);
	entity->setMaterialName("SoundBillBoard");

	myNode->attachObject(entity);
	myNode->attachObject(mySet);
	myNode->setPosition(Position);
	myNode->setScale(.1f, .1f, .1f);

	counter++;
}

void CEditorHelper::CreateSoundObject(const Vector3& Position, SOUND_OBJ& SoundObj)
{
	auto myNode = static_cast<SceneNode*>(CGameManager::Instance()->GetSceneManager()->getRootSceneNode()->createChild());
	auto name = String(SOUND_BILLBOARD) + StringConverter::toString(counter);

	auto entity = CGameManager::Instance()->GetSceneManager()->createEntity("node_" + name, SceneManager::PT_CUBE);
	entity->setQueryFlags(SQF_EDITOR);
	entity->setMaterialName("SoundBillBoard");

	myNode->attachObject(entity);
	myNode->setPosition(Position);
	myNode->setScale(.01f, .01f, .01f);

	SoundObj.Node = myNode;
	SoundObj.Entity = entity;

	counter++;
}

Vector<Vector3> CEditorHelper::RandomMeshPlacerOnY_Terrain(String& GameObjectType, f32 Top, f32 Bottom, f32 Right, f32 Left, u32 Count)
{
	Vector<Vector3> list;
	for(; Count > 0; Count--)
	{
		auto obj = CGameObjectManager::Instance()->CreateObject(GameObjectType.c_str());

		if(obj)
		{
			Vector3 pos;
			pos.x = CUtility::frandom2(Left, Right);
			pos.z = CUtility::frandom2(Bottom, Top);
			pos.y = Nature::CNatureManager::Instance()->GetTerrainHeightAt(pos.x, pos.z);

			obj->Node->setPosition(pos);
			list.push_back(pos);
		}
	}
	return list;
}

void CEditorHelper::LoadSceneFile(String SceneFile)
{
	if(CUtility::FileExists(SceneFile.c_str()))
	{
		CRuntimeEditorManager::Instance()->Shutdown();

		SceneImporterPackage sip;
		sip.SoundManager = Sound::CSoundManager::Instance();
		sip.PhysicsStrategy = Physics::CPhysicsManager::Instance()->GetStrategy();
		sip.GameManager = CGameManager::Instance();
		sip.CameraManager = CCameraManager::Instance();
		sip.ItemsManager = CItemsManager::Instance();
		sip.GameObjectManager = CGameObjectManager::Instance();
		sip.NatureManager = Nature::CNatureManager::Instance();

		CGameManager::Instance()->LoadGame(SceneFile.c_str(), "CObjectsMenu");
		CRuntimeEditorManager::Instance()->InitEditor(sip);

		// Attach game objects to all lights
		auto it = CGameManager::Instance()->GetSceneManager()->getMovableObjectIterator("Light");
		while(it.hasMoreElements())
		{
			Light* light = static_cast<Light*>(it.current()->second);
			AddLightShape(light);
			it.moveNext();
		}
	}
	else
	{
		auto strategy = CMenuDirector::Instance()->GetGuiStrategy();
		if(strategy)
			strategy->ShowMessageBox("File not found.", "Error");
	}
}