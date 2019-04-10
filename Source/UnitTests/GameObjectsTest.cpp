#include "../UnitTest++/UnitTest++.h"
#include "RecordingReporter.h"
#include "Core/CoreEngine.h"

using namespace UnitTest;

namespace
{

struct GameObjectFixture
{
	CGameObjectManager* GameObjectManager;
	GameObjectFixture()
	{
		CGameManager::Instance();
		GameObjectManager = CGameObjectManager::Instance();
		auto physics = Core::Physics::CPhysicsManager::Instance()->CreateStrategy(DEFAULT_PHYSICS_STRATEGY);
		physics->InitWorld();
		physics->ShowDebug(true);
	}
};

TEST_FIXTURE(GameObjectFixture, GameObjectAdd_CGameObjectak47_1_Success)
{
	if(!GameObjectManager)
		CHECK(false);

	auto obj = GameObjectManager->CreateObject("AK47_1", "AK47_1", reVector3Df(0, 0, 0));
	CHECK(obj);

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 1);
}

TEST_FIXTURE(GameObjectFixture, GameObjectGet_CGameObjectak47_1_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	

	CHECK(GameObjectManager->GetGameObject("AK47_1"));
}

TEST_FIXTURE(GameObjectFixture, GameObjectRemove_CGameObjectak47_1_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	GameObjectManager->RemoveGameObject(GameObjectManager->GetGameObject("AK47_1"));

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 0);
}

TEST_FIXTURE(GameObjectFixture, GameObjectAdd_CGameObjectammobox1_Success)
{
	if(!GameObjectManager)
		CHECK(false);

	auto obj = GameObjectManager->CreateObject("AMMOBOX1", "AMMOBOX1", reVector3Df(0, 0, 0));
	CHECK(obj);

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 1);
}

TEST_FIXTURE(GameObjectFixture, GameObjectGet_CGameObjectammobox1_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	

	CHECK(GameObjectManager->GetGameObject("AMMOBOX1"));
}

TEST_FIXTURE(GameObjectFixture, GameObjectRemove_CGameObjectammobox1_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	GameObjectManager->RemoveGameObject(GameObjectManager->GetGameObject("AMMOBOX1"));

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 0);
}

TEST_FIXTURE(GameObjectFixture, GameObjectAdd_CGameObjectarmycolt_Success)
{
	if(!GameObjectManager)
		CHECK(false);

	auto obj = GameObjectManager->CreateObject("ARMYCOLT", "ARMYCOLT", reVector3Df(0, 0, 0));
	CHECK(obj);

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 1);
}

TEST_FIXTURE(GameObjectFixture, GameObjectGet_CGameObjectarmycolt_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	

	CHECK(GameObjectManager->GetGameObject("ARMYCOLT"));
}

TEST_FIXTURE(GameObjectFixture, GameObjectRemove_CGameObjectarmycolt_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	GameObjectManager->RemoveGameObject(GameObjectManager->GetGameObject("ARMYCOLT"));

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 0);
}

TEST_FIXTURE(GameObjectFixture, GameObjectAdd_CGameObjectAssaultrifleSig_Success)
{
	if(!GameObjectManager)
		CHECK(false);

	auto obj = GameObjectManager->CreateObject("ASSAULTRIFLESIG", "ASSAULTRIFLESIG", reVector3Df(0, 0, 0));
	CHECK(obj);

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 1);
}

TEST_FIXTURE(GameObjectFixture, GameObjectGet_CGameObjectAssaultrifleSig_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	

	CHECK(GameObjectManager->GetGameObject("ASSAULTRIFLESIG"));
}

TEST_FIXTURE(GameObjectFixture, GameObjectRemove_CGameObjectAssaultrifleSig_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	GameObjectManager->RemoveGameObject(GameObjectManager->GetGameObject("ASSAULTRIFLESIG"));

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 0);
}

TEST_FIXTURE(GameObjectFixture, GameObjectAdd_CGameObjectbarrel01_Success)
{
	if(!GameObjectManager)
		CHECK(false);

	auto obj = GameObjectManager->CreateObject("BARREL01", "BARREL01", reVector3Df(0, 0, 0));
	CHECK(obj);

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 1);
}

TEST_FIXTURE(GameObjectFixture, GameObjectGet_CGameObjectbarrel01_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	

	CHECK(GameObjectManager->GetGameObject("BARREL01"));
}

TEST_FIXTURE(GameObjectFixture, GameObjectRemove_CGameObjectbarrel01_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	GameObjectManager->RemoveGameObject(GameObjectManager->GetGameObject("BARREL01"));

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 0);
}

TEST_FIXTURE(GameObjectFixture, GameObjectAdd_CGameObjectbarrel2_Success)
{
	if(!GameObjectManager)
		CHECK(false);

	auto obj = GameObjectManager->CreateObject("BARREL2", "BARREL2", reVector3Df(0, 0, 0));
	CHECK(obj);

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 1);
}

TEST_FIXTURE(GameObjectFixture, GameObjectGet_CGameObjectbarrel2_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	

	CHECK(GameObjectManager->GetGameObject("BARREL2"));
}

TEST_FIXTURE(GameObjectFixture, GameObjectRemove_CGameObjectbarrel2_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	GameObjectManager->RemoveGameObject(GameObjectManager->GetGameObject("BARREL2"));

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 0);
}

TEST_FIXTURE(GameObjectFixture, GameObjectAdd_CGameObjectBigContainer1_Success)
{
	if(!GameObjectManager)
		CHECK(false);

	auto obj = GameObjectManager->CreateObject("BIGCONTAINER1", "BIGCONTAINER1", reVector3Df(0, 0, 0));
	CHECK(obj);

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 1);
}

TEST_FIXTURE(GameObjectFixture, GameObjectGet_CGameObjectBigContainer1_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	

	CHECK(GameObjectManager->GetGameObject("BIGCONTAINER1"));
}

TEST_FIXTURE(GameObjectFixture, GameObjectRemove_CGameObjectBigContainer1_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	GameObjectManager->RemoveGameObject(GameObjectManager->GetGameObject("BIGCONTAINER1"));

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 0);
}

TEST_FIXTURE(GameObjectFixture, GameObjectAdd_CGameObjectBigContainer2_Success)
{
	if(!GameObjectManager)
		CHECK(false);

	auto obj = GameObjectManager->CreateObject("BIGCONTAINER2", "BIGCONTAINER2", reVector3Df(0, 0, 0));
	CHECK(obj);

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 1);
}

TEST_FIXTURE(GameObjectFixture, GameObjectGet_CGameObjectBigContainer2_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	

	CHECK(GameObjectManager->GetGameObject("BIGCONTAINER2"));
}

TEST_FIXTURE(GameObjectFixture, GameObjectRemove_CGameObjectBigContainer2_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	GameObjectManager->RemoveGameObject(GameObjectManager->GetGameObject("BIGCONTAINER2"));

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 0);
}

TEST_FIXTURE(GameObjectFixture, GameObjectAdd_CGameObjectBox1_Success)
{
	if(!GameObjectManager)
		CHECK(false);

	auto obj = GameObjectManager->CreateObject("BOX1", "BOX1", reVector3Df(0, 0, 0));
	CHECK(obj);

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 1);
}

TEST_FIXTURE(GameObjectFixture, GameObjectGet_CGameObjectBox1_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	

	CHECK(GameObjectManager->GetGameObject("BOX1"));
}

TEST_FIXTURE(GameObjectFixture, GameObjectRemove_CGameObjectBox1_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	GameObjectManager->RemoveGameObject(GameObjectManager->GetGameObject("BOX1"));

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 0);
}

TEST_FIXTURE(GameObjectFixture, GameObjectAdd_CGameObjectBush_1_Success)
{
	if(!GameObjectManager)
		CHECK(false);

	auto obj = GameObjectManager->CreateObject("BUSH_1", "BUSH_1", reVector3Df(0, 0, 0));
	CHECK(obj);

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 1);
}

TEST_FIXTURE(GameObjectFixture, GameObjectGet_CGameObjectBush_1_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	

	CHECK(GameObjectManager->GetGameObject("BUSH_1"));
}

TEST_FIXTURE(GameObjectFixture, GameObjectRemove_CGameObjectBush_1_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	GameObjectManager->RemoveGameObject(GameObjectManager->GetGameObject("BUSH_1"));

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 0);
}

TEST_FIXTURE(GameObjectFixture, GameObjectAdd_CGameObjectBush2_Success)
{
	if(!GameObjectManager)
		CHECK(false);

	auto obj = GameObjectManager->CreateObject("BUSH2", "BUSH2", reVector3Df(0, 0, 0));
	CHECK(obj);

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 1);
}

TEST_FIXTURE(GameObjectFixture, GameObjectGet_CGameObjectBush2_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	

	CHECK(GameObjectManager->GetGameObject("BUSH2"));
}

TEST_FIXTURE(GameObjectFixture, GameObjectRemove_CGameObjectBush2_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	GameObjectManager->RemoveGameObject(GameObjectManager->GetGameObject("BUSH2"));

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 0);
}

TEST_FIXTURE(GameObjectFixture, GameObjectAdd_CGameObjectcattail_lod0_Success)
{
	if(!GameObjectManager)
		CHECK(false);

	auto obj = GameObjectManager->CreateObject("CATTAIL_LOD0", "CATTAIL_LOD0", reVector3Df(0, 0, 0));
	CHECK(obj);

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 1);
}

TEST_FIXTURE(GameObjectFixture, GameObjectGet_CGameObjectcattail_lod0_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	

	CHECK(GameObjectManager->GetGameObject("CATTAIL_LOD0"));
}

TEST_FIXTURE(GameObjectFixture, GameObjectRemove_CGameObjectcattail_lod0_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	GameObjectManager->RemoveGameObject(GameObjectManager->GetGameObject("CATTAIL_LOD0"));

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 0);
}

TEST_FIXTURE(GameObjectFixture, GameObjectAdd_CGameObjectcattail_lod1_Success)
{
	if(!GameObjectManager)
		CHECK(false);

	auto obj = GameObjectManager->CreateObject("CATTAIL_LOD1", "CATTAIL_LOD1", reVector3Df(0, 0, 0));
	CHECK(obj);

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 1);
}

TEST_FIXTURE(GameObjectFixture, GameObjectGet_CGameObjectcattail_lod1_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	

	CHECK(GameObjectManager->GetGameObject("CATTAIL_LOD1"));
}

TEST_FIXTURE(GameObjectFixture, GameObjectRemove_CGameObjectcattail_lod1_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	GameObjectManager->RemoveGameObject(GameObjectManager->GetGameObject("CATTAIL_LOD1"));

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 0);
}

TEST_FIXTURE(GameObjectFixture, GameObjectAdd_CGameObjectcattail_lod2_Success)
{
	if(!GameObjectManager)
		CHECK(false);

	auto obj = GameObjectManager->CreateObject("CATTAIL_LOD2", "CATTAIL_LOD2", reVector3Df(0, 0, 0));
	CHECK(obj);

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 1);
}

TEST_FIXTURE(GameObjectFixture, GameObjectGet_CGameObjectcattail_lod2_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	

	CHECK(GameObjectManager->GetGameObject("CATTAIL_LOD2"));
}

TEST_FIXTURE(GameObjectFixture, GameObjectRemove_CGameObjectcattail_lod2_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	GameObjectManager->RemoveGameObject(GameObjectManager->GetGameObject("CATTAIL_LOD2"));

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 0);
}

TEST_FIXTURE(GameObjectFixture, GameObjectAdd_CGameObjectConcrete_Success)
{
	if(!GameObjectManager)
		CHECK(false);

	auto obj = GameObjectManager->CreateObject("CONCRETE", "CONCRETE", reVector3Df(0, 0, 0));
	CHECK(obj);

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 1);
}

TEST_FIXTURE(GameObjectFixture, GameObjectGet_CGameObjectConcrete_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	

	CHECK(GameObjectManager->GetGameObject("CONCRETE"));
}

TEST_FIXTURE(GameObjectFixture, GameObjectRemove_CGameObjectConcrete_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	GameObjectManager->RemoveGameObject(GameObjectManager->GetGameObject("CONCRETE"));

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 0);
}

TEST_FIXTURE(GameObjectFixture, GameObjectAdd_CGameObjectconstruct_Success)
{
	if(!GameObjectManager)
		CHECK(false);

	auto obj = GameObjectManager->CreateObject("CONSTRUCT", "CONSTRUCT", reVector3Df(0, 0, 0));
	CHECK(obj);

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 1);
}

TEST_FIXTURE(GameObjectFixture, GameObjectGet_CGameObjectconstruct_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	

	CHECK(GameObjectManager->GetGameObject("CONSTRUCT"));
}

TEST_FIXTURE(GameObjectFixture, GameObjectRemove_CGameObjectconstruct_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	GameObjectManager->RemoveGameObject(GameObjectManager->GetGameObject("CONSTRUCT"));

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 0);
}

TEST_FIXTURE(GameObjectFixture, GameObjectAdd_CGameObjectcrate_Success)
{
	if(!GameObjectManager)
		CHECK(false);

	auto obj = GameObjectManager->CreateObject("CRATE", "CRATE", reVector3Df(0, 0, 0));
	CHECK(obj);

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 1);
}

TEST_FIXTURE(GameObjectFixture, GameObjectGet_CGameObjectcrate_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	

	CHECK(GameObjectManager->GetGameObject("CRATE"));
}

TEST_FIXTURE(GameObjectFixture, GameObjectRemove_CGameObjectcrate_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	GameObjectManager->RemoveGameObject(GameObjectManager->GetGameObject("CRATE"));

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 0);
}

TEST_FIXTURE(GameObjectFixture, GameObjectAdd_CGameObjectcrate01_Success)
{
	if(!GameObjectManager)
		CHECK(false);

	auto obj = GameObjectManager->CreateObject("CRATE01", "CRATE01", reVector3Df(0, 0, 0));
	CHECK(obj);

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 1);
}

TEST_FIXTURE(GameObjectFixture, GameObjectGet_CGameObjectcrate01_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	

	CHECK(GameObjectManager->GetGameObject("CRATE01"));
}

TEST_FIXTURE(GameObjectFixture, GameObjectRemove_CGameObjectcrate01_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	GameObjectManager->RemoveGameObject(GameObjectManager->GetGameObject("CRATE01"));

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 0);
}

TEST_FIXTURE(GameObjectFixture, GameObjectAdd_CGameObjectCrate3_Success)
{
	if(!GameObjectManager)
		CHECK(false);

	auto obj = GameObjectManager->CreateObject("CRATE3", "CRATE3", reVector3Df(0, 0, 0));
	CHECK(obj);

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 1);
}

TEST_FIXTURE(GameObjectFixture, GameObjectGet_CGameObjectCrate3_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	

	CHECK(GameObjectManager->GetGameObject("CRATE3"));
}

TEST_FIXTURE(GameObjectFixture, GameObjectRemove_CGameObjectCrate3_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	GameObjectManager->RemoveGameObject(GameObjectManager->GetGameObject("CRATE3"));

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 0);
}

TEST_FIXTURE(GameObjectFixture, GameObjectAdd_CGameObjectFirstaid1_Success)
{
	if(!GameObjectManager)
		CHECK(false);

	auto obj = GameObjectManager->CreateObject("FIRSTAID1", "FIRSTAID1", reVector3Df(0, 0, 0));
	CHECK(obj);

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 1);
}

TEST_FIXTURE(GameObjectFixture, GameObjectGet_CGameObjectFirstaid1_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	

	CHECK(GameObjectManager->GetGameObject("FIRSTAID1"));
}

TEST_FIXTURE(GameObjectFixture, GameObjectRemove_CGameObjectFirstaid1_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	GameObjectManager->RemoveGameObject(GameObjectManager->GetGameObject("FIRSTAID1"));

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 0);
}

TEST_FIXTURE(GameObjectFixture, GameObjectAdd_CGameObjectflower1_Success)
{
	if(!GameObjectManager)
		CHECK(false);

	auto obj = GameObjectManager->CreateObject("FLOWER1", "FLOWER1", reVector3Df(0, 0, 0));
	CHECK(obj);

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 1);
}

TEST_FIXTURE(GameObjectFixture, GameObjectGet_CGameObjectflower1_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	

	CHECK(GameObjectManager->GetGameObject("FLOWER1"));
}

TEST_FIXTURE(GameObjectFixture, GameObjectRemove_CGameObjectflower1_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	GameObjectManager->RemoveGameObject(GameObjectManager->GetGameObject("FLOWER1"));

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 0);
}

TEST_FIXTURE(GameObjectFixture, GameObjectAdd_CGameObjectflowerplant_lod0_Success)
{
	if(!GameObjectManager)
		CHECK(false);

	auto obj = GameObjectManager->CreateObject("FLOWERPLANT_LOD0", "FLOWERPLANT_LOD0", reVector3Df(0, 0, 0));
	CHECK(obj);

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 1);
}

TEST_FIXTURE(GameObjectFixture, GameObjectGet_CGameObjectflowerplant_lod0_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	

	CHECK(GameObjectManager->GetGameObject("FLOWERPLANT_LOD0"));
}

TEST_FIXTURE(GameObjectFixture, GameObjectRemove_CGameObjectflowerplant_lod0_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	GameObjectManager->RemoveGameObject(GameObjectManager->GetGameObject("FLOWERPLANT_LOD0"));

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 0);
}

TEST_FIXTURE(GameObjectFixture, GameObjectAdd_CGameObjectflowerplant2_lod1_Success)
{
	if(!GameObjectManager)
		CHECK(false);

	auto obj = GameObjectManager->CreateObject("FLOWERPLANT2_LOD1", "FLOWERPLANT2_LOD1", reVector3Df(0, 0, 0));
	CHECK(obj);

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 1);
}

TEST_FIXTURE(GameObjectFixture, GameObjectGet_CGameObjectflowerplant2_lod1_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	

	CHECK(GameObjectManager->GetGameObject("FLOWERPLANT2_LOD1"));
}

TEST_FIXTURE(GameObjectFixture, GameObjectRemove_CGameObjectflowerplant2_lod1_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	GameObjectManager->RemoveGameObject(GameObjectManager->GetGameObject("FLOWERPLANT2_LOD1"));

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 0);
}

TEST_FIXTURE(GameObjectFixture, GameObjectAdd_CGameObjectflowerplant3_lod0_Success)
{
	if(!GameObjectManager)
		CHECK(false);

	auto obj = GameObjectManager->CreateObject("FLOWERPLANT3_LOD0", "FLOWERPLANT3_LOD0", reVector3Df(0, 0, 0));
	CHECK(obj);

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 1);
}

TEST_FIXTURE(GameObjectFixture, GameObjectGet_CGameObjectflowerplant3_lod0_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	

	CHECK(GameObjectManager->GetGameObject("FLOWERPLANT3_LOD0"));
}

TEST_FIXTURE(GameObjectFixture, GameObjectRemove_CGameObjectflowerplant3_lod0_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	GameObjectManager->RemoveGameObject(GameObjectManager->GetGameObject("FLOWERPLANT3_LOD0"));

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 0);
}

TEST_FIXTURE(GameObjectFixture, GameObjectAdd_CGameObjectGenmarine_Success)
{
	if(!GameObjectManager)
		CHECK(false);

	auto obj = GameObjectManager->CreateObject("GEN-MARINE", "GEN-MARINE", reVector3Df(0, 0, 0));
	CHECK(obj);

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 1);
}

TEST_FIXTURE(GameObjectFixture, GameObjectGet_CGameObjectGenmarine_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	

	CHECK(GameObjectManager->GetGameObject("GEN-MARINE"));
}

TEST_FIXTURE(GameObjectFixture, GameObjectRemove_CGameObjectGenmarine_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	GameObjectManager->RemoveGameObject(GameObjectManager->GetGameObject("GEN-MARINE"));

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 0);
}

TEST_FIXTURE(GameObjectFixture, GameObjectAdd_CGameObjectHQMilitiaTentShape_Success)
{
	if(!GameObjectManager)
		CHECK(false);

	auto obj = GameObjectManager->CreateObject("HQMILITIATENTSHAPE", "HQMILITIATENTSHAPE", reVector3Df(0, 0, 0));
	CHECK(obj);

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 1);
}

TEST_FIXTURE(GameObjectFixture, GameObjectGet_CGameObjectHQMilitiaTentShape_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	

	CHECK(GameObjectManager->GetGameObject("HQMILITIATENTSHAPE"));
}

TEST_FIXTURE(GameObjectFixture, GameObjectRemove_CGameObjectHQMilitiaTentShape_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	GameObjectManager->RemoveGameObject(GameObjectManager->GetGameObject("HQMILITIATENTSHAPE"));

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 0);
}

TEST_FIXTURE(GameObjectFixture, GameObjectAdd_CGameObjecthumvee_1_Success)
{
	if(!GameObjectManager)
		CHECK(false);

	auto obj = GameObjectManager->CreateObject("HUMVEE_1", "HUMVEE_1", reVector3Df(0, 0, 0));
	CHECK(obj);

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 1);
}

TEST_FIXTURE(GameObjectFixture, GameObjectGet_CGameObjecthumvee_1_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	

	CHECK(GameObjectManager->GetGameObject("HUMVEE_1"));
}

TEST_FIXTURE(GameObjectFixture, GameObjectRemove_CGameObjecthumvee_1_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	GameObjectManager->RemoveGameObject(GameObjectManager->GetGameObject("HUMVEE_1"));

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 0);
}

TEST_FIXTURE(GameObjectFixture, GameObjectAdd_CGameObjectleaflarge_lod0_Success)
{
	if(!GameObjectManager)
		CHECK(false);

	auto obj = GameObjectManager->CreateObject("LEAFLARGE_LOD0", "LEAFLARGE_LOD0", reVector3Df(0, 0, 0));
	CHECK(obj);

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 1);
}

TEST_FIXTURE(GameObjectFixture, GameObjectGet_CGameObjectleaflarge_lod0_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	

	CHECK(GameObjectManager->GetGameObject("LEAFLARGE_LOD0"));
}

TEST_FIXTURE(GameObjectFixture, GameObjectRemove_CGameObjectleaflarge_lod0_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	GameObjectManager->RemoveGameObject(GameObjectManager->GetGameObject("LEAFLARGE_LOD0"));

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 0);
}

TEST_FIXTURE(GameObjectFixture, GameObjectAdd_CGameObjectleaflarge2_lod0_Success)
{
	if(!GameObjectManager)
		CHECK(false);

	auto obj = GameObjectManager->CreateObject("LEAFLARGE2_LOD0", "LEAFLARGE2_LOD0", reVector3Df(0, 0, 0));
	CHECK(obj);

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 1);
}

TEST_FIXTURE(GameObjectFixture, GameObjectGet_CGameObjectleaflarge2_lod0_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	

	CHECK(GameObjectManager->GetGameObject("LEAFLARGE2_LOD0"));
}

TEST_FIXTURE(GameObjectFixture, GameObjectRemove_CGameObjectleaflarge2_lod0_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	GameObjectManager->RemoveGameObject(GameObjectManager->GetGameObject("LEAFLARGE2_LOD0"));

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 0);
}

TEST_FIXTURE(GameObjectFixture, GameObjectAdd_CGameObjectleafplant2_purple_lod0_Success)
{
	if(!GameObjectManager)
		CHECK(false);

	auto obj = GameObjectManager->CreateObject("LEAFPLANT2_PURPLE_LOD0", "LEAFPLANT2_PURPLE_LOD0", reVector3Df(0, 0, 0));
	CHECK(obj);

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 1);
}

TEST_FIXTURE(GameObjectFixture, GameObjectGet_CGameObjectleafplant2_purple_lod0_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	

	CHECK(GameObjectManager->GetGameObject("LEAFPLANT2_PURPLE_LOD0"));
}

TEST_FIXTURE(GameObjectFixture, GameObjectRemove_CGameObjectleafplant2_purple_lod0_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	GameObjectManager->RemoveGameObject(GameObjectManager->GetGameObject("LEAFPLANT2_PURPLE_LOD0"));

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 0);
}

TEST_FIXTURE(GameObjectFixture, GameObjectAdd_CGameObjectleafplant3_lod0_Success)
{
	if(!GameObjectManager)
		CHECK(false);

	auto obj = GameObjectManager->CreateObject("LEAFPLANT3_LOD0", "LEAFPLANT3_LOD0", reVector3Df(0, 0, 0));
	CHECK(obj);

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 1);
}

TEST_FIXTURE(GameObjectFixture, GameObjectGet_CGameObjectleafplant3_lod0_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	

	CHECK(GameObjectManager->GetGameObject("LEAFPLANT3_LOD0"));
}

TEST_FIXTURE(GameObjectFixture, GameObjectRemove_CGameObjectleafplant3_lod0_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	GameObjectManager->RemoveGameObject(GameObjectManager->GetGameObject("LEAFPLANT3_LOD0"));

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 0);
}

TEST_FIXTURE(GameObjectFixture, GameObjectAdd_CGameObjectleafplant4_lod0_Success)
{
	if(!GameObjectManager)
		CHECK(false);

	auto obj = GameObjectManager->CreateObject("LEAFPLANT4_LOD0", "LEAFPLANT4_LOD0", reVector3Df(0, 0, 0));
	CHECK(obj);

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 1);
}

TEST_FIXTURE(GameObjectFixture, GameObjectGet_CGameObjectleafplant4_lod0_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	

	CHECK(GameObjectManager->GetGameObject("LEAFPLANT4_LOD0"));
}

TEST_FIXTURE(GameObjectFixture, GameObjectRemove_CGameObjectleafplant4_lod0_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	GameObjectManager->RemoveGameObject(GameObjectManager->GetGameObject("LEAFPLANT4_LOD0"));

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 0);
}

TEST_FIXTURE(GameObjectFixture, GameObjectAdd_CGameObjectLowPoly_Success)
{
	if(!GameObjectManager)
		CHECK(false);

	auto obj = GameObjectManager->CreateObject("LOWPOLY", "LOWPOLY", reVector3Df(0, 0, 0));
	CHECK(obj);

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 1);
}

TEST_FIXTURE(GameObjectFixture, GameObjectGet_CGameObjectLowPoly_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	

	CHECK(GameObjectManager->GetGameObject("LOWPOLY"));
}

TEST_FIXTURE(GameObjectFixture, GameObjectRemove_CGameObjectLowPoly_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	GameObjectManager->RemoveGameObject(GameObjectManager->GetGameObject("LOWPOLY"));

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 0);
}

TEST_FIXTURE(GameObjectFixture, GameObjectAdd_CGameObjectm4a1_1_Success)
{
	if(!GameObjectManager)
		CHECK(false);

	auto obj = GameObjectManager->CreateObject("M4A1_1", "M4A1_1", reVector3Df(0, 0, 0));
	CHECK(obj);

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 1);
}

TEST_FIXTURE(GameObjectFixture, GameObjectGet_CGameObjectm4a1_1_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	

	CHECK(GameObjectManager->GetGameObject("M4A1_1"));
}

TEST_FIXTURE(GameObjectFixture, GameObjectRemove_CGameObjectm4a1_1_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	GameObjectManager->RemoveGameObject(GameObjectManager->GetGameObject("M4A1_1"));

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 0);
}

TEST_FIXTURE(GameObjectFixture, GameObjectAdd_CGameObjectninja_Success)
{
	if(!GameObjectManager)
		CHECK(false);

	auto obj = GameObjectManager->CreateObject("NINJA", "NINJA", reVector3Df(0, 0, 0));
	CHECK(obj);

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 1);
}

TEST_FIXTURE(GameObjectFixture, GameObjectGet_CGameObjectninja_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	

	CHECK(GameObjectManager->GetGameObject("NINJA"));
}

TEST_FIXTURE(GameObjectFixture, GameObjectRemove_CGameObjectninja_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	GameObjectManager->RemoveGameObject(GameObjectManager->GetGameObject("NINJA"));

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 0);
}

TEST_FIXTURE(GameObjectFixture, GameObjectAdd_CGameObjectOilPump_Success)
{
	if(!GameObjectManager)
		CHECK(false);

	auto obj = GameObjectManager->CreateObject("OILPUMP", "OILPUMP", reVector3Df(0, 0, 0));
	CHECK(obj);

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 1);
}

TEST_FIXTURE(GameObjectFixture, GameObjectGet_CGameObjectOilPump_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	

	CHECK(GameObjectManager->GetGameObject("OILPUMP"));
}

TEST_FIXTURE(GameObjectFixture, GameObjectRemove_CGameObjectOilPump_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	GameObjectManager->RemoveGameObject(GameObjectManager->GetGameObject("OILPUMP"));

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 0);
}

TEST_FIXTURE(GameObjectFixture, GameObjectAdd_CGameObjectrazor_Success)
{
	if(!GameObjectManager)
		CHECK(false);

	auto obj = GameObjectManager->CreateObject("RAZOR", "RAZOR", reVector3Df(0, 0, 0));
	CHECK(obj);

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 1);
}

TEST_FIXTURE(GameObjectFixture, GameObjectGet_CGameObjectrazor_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	

	CHECK(GameObjectManager->GetGameObject("RAZOR"));
}

TEST_FIXTURE(GameObjectFixture, GameObjectRemove_CGameObjectrazor_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	GameObjectManager->RemoveGameObject(GameObjectManager->GetGameObject("RAZOR"));

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 0);
}

TEST_FIXTURE(GameObjectFixture, GameObjectAdd_CGameObjectrobot_Success)
{
	if(!GameObjectManager)
		CHECK(false);

	auto obj = GameObjectManager->CreateObject("ROBOT", "ROBOT", reVector3Df(0, 0, 0));
	CHECK(obj);

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 1);
}

TEST_FIXTURE(GameObjectFixture, GameObjectGet_CGameObjectrobot_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	

	CHECK(GameObjectManager->GetGameObject("ROBOT"));
}

TEST_FIXTURE(GameObjectFixture, GameObjectRemove_CGameObjectrobot_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	GameObjectManager->RemoveGameObject(GameObjectManager->GetGameObject("ROBOT"));

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 0);
}

TEST_FIXTURE(GameObjectFixture, GameObjectAdd_CGameObjectsas_Success)
{
	if(!GameObjectManager)
		CHECK(false);

	auto obj = GameObjectManager->CreateObject("SAS", "SAS", reVector3Df(0, 0, 0));
	CHECK(obj);

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 1);
}

TEST_FIXTURE(GameObjectFixture, GameObjectGet_CGameObjectsas_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	

	CHECK(GameObjectManager->GetGameObject("SAS"));
}

TEST_FIXTURE(GameObjectFixture, GameObjectRemove_CGameObjectsas_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	GameObjectManager->RemoveGameObject(GameObjectManager->GetGameObject("SAS"));

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 0);
}

TEST_FIXTURE(GameObjectFixture, GameObjectAdd_CGameObjectShootingPlace_Success)
{
	if(!GameObjectManager)
		CHECK(false);

	auto obj = GameObjectManager->CreateObject("SHOOTINGPLACE", "SHOOTINGPLACE", reVector3Df(0, 0, 0));
	CHECK(obj);

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 1);
}

TEST_FIXTURE(GameObjectFixture, GameObjectGet_CGameObjectShootingPlace_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	

	CHECK(GameObjectManager->GetGameObject("SHOOTINGPLACE"));
}

TEST_FIXTURE(GameObjectFixture, GameObjectRemove_CGameObjectShootingPlace_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	GameObjectManager->RemoveGameObject(GameObjectManager->GetGameObject("SHOOTINGPLACE"));

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 0);
}

TEST_FIXTURE(GameObjectFixture, GameObjectAdd_CGameObjectShootingRangeWall1_Success)
{
	if(!GameObjectManager)
		CHECK(false);

	auto obj = GameObjectManager->CreateObject("SHOOTINGRANGEWALL1", "SHOOTINGRANGEWALL1", reVector3Df(0, 0, 0));
	CHECK(obj);

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 1);
}

TEST_FIXTURE(GameObjectFixture, GameObjectGet_CGameObjectShootingRangeWall1_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	

	CHECK(GameObjectManager->GetGameObject("SHOOTINGRANGEWALL1"));
}

TEST_FIXTURE(GameObjectFixture, GameObjectRemove_CGameObjectShootingRangeWall1_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	GameObjectManager->RemoveGameObject(GameObjectManager->GetGameObject("SHOOTINGRANGEWALL1"));

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 0);
}

TEST_FIXTURE(GameObjectFixture, GameObjectAdd_CGameObjectSoldier_Success)
{
	if(!GameObjectManager)
		CHECK(false);

	auto obj = GameObjectManager->CreateObject("SOLDIER", "SOLDIER", reVector3Df(0, 0, 0));
	CHECK(obj);

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 1);
}

TEST_FIXTURE(GameObjectFixture, GameObjectGet_CGameObjectSoldier_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	

	CHECK(GameObjectManager->GetGameObject("SOLDIER"));
}

TEST_FIXTURE(GameObjectFixture, GameObjectRemove_CGameObjectSoldier_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	GameObjectManager->RemoveGameObject(GameObjectManager->GetGameObject("SOLDIER"));

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 0);
}

TEST_FIXTURE(GameObjectFixture, GameObjectAdd_CGameObjectstone_wall1_Success)
{
	if(!GameObjectManager)
		CHECK(false);

	auto obj = GameObjectManager->CreateObject("STONE_WALL1", "STONE_WALL1", reVector3Df(0, 0, 0));
	CHECK(obj);

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 1);
}

TEST_FIXTURE(GameObjectFixture, GameObjectGet_CGameObjectstone_wall1_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	

	CHECK(GameObjectManager->GetGameObject("STONE_WALL1"));
}

TEST_FIXTURE(GameObjectFixture, GameObjectRemove_CGameObjectstone_wall1_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	GameObjectManager->RemoveGameObject(GameObjectManager->GetGameObject("STONE_WALL1"));

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 0);
}

TEST_FIXTURE(GameObjectFixture, GameObjectAdd_CGameObjectstone_wall2_Success)
{
	if(!GameObjectManager)
		CHECK(false);

	auto obj = GameObjectManager->CreateObject("STONE_WALL2", "STONE_WALL2", reVector3Df(0, 0, 0));
	CHECK(obj);

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 1);
}

TEST_FIXTURE(GameObjectFixture, GameObjectGet_CGameObjectstone_wall2_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	

	CHECK(GameObjectManager->GetGameObject("STONE_WALL2"));
}

TEST_FIXTURE(GameObjectFixture, GameObjectRemove_CGameObjectstone_wall2_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	GameObjectManager->RemoveGameObject(GameObjectManager->GetGameObject("STONE_WALL2"));

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 0);
}

TEST_FIXTURE(GameObjectFixture, GameObjectAdd_CGameObjectstone_wall3_Success)
{
	if(!GameObjectManager)
		CHECK(false);

	auto obj = GameObjectManager->CreateObject("STONE_WALL3", "STONE_WALL3", reVector3Df(0, 0, 0));
	CHECK(obj);

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 1);
}

TEST_FIXTURE(GameObjectFixture, GameObjectGet_CGameObjectstone_wall3_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	

	CHECK(GameObjectManager->GetGameObject("STONE_WALL3"));
}

TEST_FIXTURE(GameObjectFixture, GameObjectRemove_CGameObjectstone_wall3_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	GameObjectManager->RemoveGameObject(GameObjectManager->GetGameObject("STONE_WALL3"));

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 0);
}

TEST_FIXTURE(GameObjectFixture, GameObjectAdd_CGameObjectstone_wall4_Success)
{
	if(!GameObjectManager)
		CHECK(false);

	auto obj = GameObjectManager->CreateObject("STONE_WALL4", "STONE_WALL4", reVector3Df(0, 0, 0));
	CHECK(obj);

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 1);
}

TEST_FIXTURE(GameObjectFixture, GameObjectGet_CGameObjectstone_wall4_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	

	CHECK(GameObjectManager->GetGameObject("STONE_WALL4"));
}

TEST_FIXTURE(GameObjectFixture, GameObjectRemove_CGameObjectstone_wall4_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	GameObjectManager->RemoveGameObject(GameObjectManager->GetGameObject("STONE_WALL4"));

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 0);
}

TEST_FIXTURE(GameObjectFixture, GameObjectAdd_CGameObjectstone1_Success)
{
	if(!GameObjectManager)
		CHECK(false);

	auto obj = GameObjectManager->CreateObject("STONE1", "STONE1", reVector3Df(0, 0, 0));
	CHECK(obj);

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 1);
}

TEST_FIXTURE(GameObjectFixture, GameObjectGet_CGameObjectstone1_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	

	CHECK(GameObjectManager->GetGameObject("STONE1"));
}

TEST_FIXTURE(GameObjectFixture, GameObjectRemove_CGameObjectstone1_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	GameObjectManager->RemoveGameObject(GameObjectManager->GetGameObject("STONE1"));

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 0);
}

TEST_FIXTURE(GameObjectFixture, GameObjectAdd_CGameObjectstone1_lod2_Success)
{
	if(!GameObjectManager)
		CHECK(false);

	auto obj = GameObjectManager->CreateObject("STONE1_LOD2", "STONE1_LOD2", reVector3Df(0, 0, 0));
	CHECK(obj);

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 1);
}

TEST_FIXTURE(GameObjectFixture, GameObjectGet_CGameObjectstone1_lod2_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	

	CHECK(GameObjectManager->GetGameObject("STONE1_LOD2"));
}

TEST_FIXTURE(GameObjectFixture, GameObjectRemove_CGameObjectstone1_lod2_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	GameObjectManager->RemoveGameObject(GameObjectManager->GetGameObject("STONE1_LOD2"));

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 0);
}

TEST_FIXTURE(GameObjectFixture, GameObjectAdd_CGameObjectstone2_Success)
{
	if(!GameObjectManager)
		CHECK(false);

	auto obj = GameObjectManager->CreateObject("STONE2", "STONE2", reVector3Df(0, 0, 0));
	CHECK(obj);

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 1);
}

TEST_FIXTURE(GameObjectFixture, GameObjectGet_CGameObjectstone2_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	

	CHECK(GameObjectManager->GetGameObject("STONE2"));
}

TEST_FIXTURE(GameObjectFixture, GameObjectRemove_CGameObjectstone2_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	GameObjectManager->RemoveGameObject(GameObjectManager->GetGameObject("STONE2"));

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 0);
}

TEST_FIXTURE(GameObjectFixture, GameObjectAdd_CGameObjectstone2_lod2_Success)
{
	if(!GameObjectManager)
		CHECK(false);

	auto obj = GameObjectManager->CreateObject("STONE2_LOD2", "STONE2_LOD2", reVector3Df(0, 0, 0));
	CHECK(obj);

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 1);
}

TEST_FIXTURE(GameObjectFixture, GameObjectGet_CGameObjectstone2_lod2_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	

	CHECK(GameObjectManager->GetGameObject("STONE2_LOD2"));
}

TEST_FIXTURE(GameObjectFixture, GameObjectRemove_CGameObjectstone2_lod2_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	GameObjectManager->RemoveGameObject(GameObjectManager->GetGameObject("STONE2_LOD2"));

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 0);
}

TEST_FIXTURE(GameObjectFixture, GameObjectAdd_CGameObjectstone3_Success)
{
	if(!GameObjectManager)
		CHECK(false);

	auto obj = GameObjectManager->CreateObject("STONE3", "STONE3", reVector3Df(0, 0, 0));
	CHECK(obj);

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 1);
}

TEST_FIXTURE(GameObjectFixture, GameObjectGet_CGameObjectstone3_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	

	CHECK(GameObjectManager->GetGameObject("STONE3"));
}

TEST_FIXTURE(GameObjectFixture, GameObjectRemove_CGameObjectstone3_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	GameObjectManager->RemoveGameObject(GameObjectManager->GetGameObject("STONE3"));

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 0);
}

TEST_FIXTURE(GameObjectFixture, GameObjectAdd_CGameObjectstone3_lod2_Success)
{
	if(!GameObjectManager)
		CHECK(false);

	auto obj = GameObjectManager->CreateObject("STONE3_LOD2", "STONE3_LOD2", reVector3Df(0, 0, 0));
	CHECK(obj);

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 1);
}

TEST_FIXTURE(GameObjectFixture, GameObjectGet_CGameObjectstone3_lod2_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	

	CHECK(GameObjectManager->GetGameObject("STONE3_LOD2"));
}

TEST_FIXTURE(GameObjectFixture, GameObjectRemove_CGameObjectstone3_lod2_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	GameObjectManager->RemoveGameObject(GameObjectManager->GetGameObject("STONE3_LOD2"));

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 0);
}

TEST_FIXTURE(GameObjectFixture, GameObjectAdd_CGameObjectstone4_Success)
{
	if(!GameObjectManager)
		CHECK(false);

	auto obj = GameObjectManager->CreateObject("STONE4", "STONE4", reVector3Df(0, 0, 0));
	CHECK(obj);

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 1);
}

TEST_FIXTURE(GameObjectFixture, GameObjectGet_CGameObjectstone4_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	

	CHECK(GameObjectManager->GetGameObject("STONE4"));
}

TEST_FIXTURE(GameObjectFixture, GameObjectRemove_CGameObjectstone4_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	GameObjectManager->RemoveGameObject(GameObjectManager->GetGameObject("STONE4"));

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 0);
}

TEST_FIXTURE(GameObjectFixture, GameObjectAdd_CGameObjectstone4_lod2_Success)
{
	if(!GameObjectManager)
		CHECK(false);

	auto obj = GameObjectManager->CreateObject("STONE4_LOD2", "STONE4_LOD2", reVector3Df(0, 0, 0));
	CHECK(obj);

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 1);
}

TEST_FIXTURE(GameObjectFixture, GameObjectGet_CGameObjectstone4_lod2_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	

	CHECK(GameObjectManager->GetGameObject("STONE4_LOD2"));
}

TEST_FIXTURE(GameObjectFixture, GameObjectRemove_CGameObjectstone4_lod2_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	GameObjectManager->RemoveGameObject(GameObjectManager->GetGameObject("STONE4_LOD2"));

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 0);
}

TEST_FIXTURE(GameObjectFixture, GameObjectAdd_CGameObjectstone5_Success)
{
	if(!GameObjectManager)
		CHECK(false);

	auto obj = GameObjectManager->CreateObject("STONE5", "STONE5", reVector3Df(0, 0, 0));
	CHECK(obj);

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 1);
}

TEST_FIXTURE(GameObjectFixture, GameObjectGet_CGameObjectstone5_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	

	CHECK(GameObjectManager->GetGameObject("STONE5"));
}

TEST_FIXTURE(GameObjectFixture, GameObjectRemove_CGameObjectstone5_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	GameObjectManager->RemoveGameObject(GameObjectManager->GetGameObject("STONE5"));

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 0);
}

TEST_FIXTURE(GameObjectFixture, GameObjectAdd_CGameObjectstone5_lod2_Success)
{
	if(!GameObjectManager)
		CHECK(false);

	auto obj = GameObjectManager->CreateObject("STONE5_LOD2", "STONE5_LOD2", reVector3Df(0, 0, 0));
	CHECK(obj);

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 1);
}

TEST_FIXTURE(GameObjectFixture, GameObjectGet_CGameObjectstone5_lod2_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	

	CHECK(GameObjectManager->GetGameObject("STONE5_LOD2"));
}

TEST_FIXTURE(GameObjectFixture, GameObjectRemove_CGameObjectstone5_lod2_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	GameObjectManager->RemoveGameObject(GameObjectManager->GetGameObject("STONE5_LOD2"));

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 0);
}

TEST_FIXTURE(GameObjectFixture, GameObjectAdd_CGameObjectstone6_Success)
{
	if(!GameObjectManager)
		CHECK(false);

	auto obj = GameObjectManager->CreateObject("STONE6", "STONE6", reVector3Df(0, 0, 0));
	CHECK(obj);

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 1);
}

TEST_FIXTURE(GameObjectFixture, GameObjectGet_CGameObjectstone6_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	

	CHECK(GameObjectManager->GetGameObject("STONE6"));
}

TEST_FIXTURE(GameObjectFixture, GameObjectRemove_CGameObjectstone6_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	GameObjectManager->RemoveGameObject(GameObjectManager->GetGameObject("STONE6"));

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 0);
}

TEST_FIXTURE(GameObjectFixture, GameObjectAdd_CGameObjectstone6_lod1_Success)
{
	if(!GameObjectManager)
		CHECK(false);

	auto obj = GameObjectManager->CreateObject("STONE6_LOD1", "STONE6_LOD1", reVector3Df(0, 0, 0));
	CHECK(obj);

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 1);
}

TEST_FIXTURE(GameObjectFixture, GameObjectGet_CGameObjectstone6_lod1_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	

	CHECK(GameObjectManager->GetGameObject("STONE6_LOD1"));
}

TEST_FIXTURE(GameObjectFixture, GameObjectRemove_CGameObjectstone6_lod1_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	GameObjectManager->RemoveGameObject(GameObjectManager->GetGameObject("STONE6_LOD1"));

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 0);
}

TEST_FIXTURE(GameObjectFixture, GameObjectAdd_CGameObjectTarget2_Success)
{
	if(!GameObjectManager)
		CHECK(false);

	auto obj = GameObjectManager->CreateObject("TARGET2", "TARGET2", reVector3Df(0, 0, 0));
	CHECK(obj);

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 1);
}

TEST_FIXTURE(GameObjectFixture, GameObjectGet_CGameObjectTarget2_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	

	CHECK(GameObjectManager->GetGameObject("TARGET2"));
}

TEST_FIXTURE(GameObjectFixture, GameObjectRemove_CGameObjectTarget2_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	GameObjectManager->RemoveGameObject(GameObjectManager->GetGameObject("TARGET2"));

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 0);
}

TEST_FIXTURE(GameObjectFixture, GameObjectAdd_CGameObjecttree1_Success)
{
	if(!GameObjectManager)
		CHECK(false);

	auto obj = GameObjectManager->CreateObject("TREE1", "TREE1", reVector3Df(0, 0, 0));
	CHECK(obj);

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 1);
}

TEST_FIXTURE(GameObjectFixture, GameObjectGet_CGameObjecttree1_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	

	CHECK(GameObjectManager->GetGameObject("TREE1"));
}

TEST_FIXTURE(GameObjectFixture, GameObjectRemove_CGameObjecttree1_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	GameObjectManager->RemoveGameObject(GameObjectManager->GetGameObject("TREE1"));

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 0);
}

TEST_FIXTURE(GameObjectFixture, GameObjectAdd_CGameObjecttree2_Success)
{
	if(!GameObjectManager)
		CHECK(false);

	auto obj = GameObjectManager->CreateObject("TREE2", "TREE2", reVector3Df(0, 0, 0));
	CHECK(obj);

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 1);
}

TEST_FIXTURE(GameObjectFixture, GameObjectGet_CGameObjecttree2_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	

	CHECK(GameObjectManager->GetGameObject("TREE2"));
}

TEST_FIXTURE(GameObjectFixture, GameObjectRemove_CGameObjecttree2_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	GameObjectManager->RemoveGameObject(GameObjectManager->GetGameObject("TREE2"));

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 0);
}

TEST_FIXTURE(GameObjectFixture, GameObjectAdd_CGameObjecttree3_Success)
{
	if(!GameObjectManager)
		CHECK(false);

	auto obj = GameObjectManager->CreateObject("TREE3", "TREE3", reVector3Df(0, 0, 0));
	CHECK(obj);

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 1);
}

TEST_FIXTURE(GameObjectFixture, GameObjectGet_CGameObjecttree3_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	

	CHECK(GameObjectManager->GetGameObject("TREE3"));
}

TEST_FIXTURE(GameObjectFixture, GameObjectRemove_CGameObjecttree3_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	GameObjectManager->RemoveGameObject(GameObjectManager->GetGameObject("TREE3"));

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 0);
}

TEST_FIXTURE(GameObjectFixture, GameObjectAdd_CGameObjectveg1_Success)
{
	if(!GameObjectManager)
		CHECK(false);

	auto obj = GameObjectManager->CreateObject("VEG1", "VEG1", reVector3Df(0, 0, 0));
	CHECK(obj);

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 1);
}

TEST_FIXTURE(GameObjectFixture, GameObjectGet_CGameObjectveg1_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	

	CHECK(GameObjectManager->GetGameObject("VEG1"));
}

TEST_FIXTURE(GameObjectFixture, GameObjectRemove_CGameObjectveg1_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	GameObjectManager->RemoveGameObject(GameObjectManager->GetGameObject("VEG1"));

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 0);
}

TEST_FIXTURE(GameObjectFixture, GameObjectAdd_CGameObjectveg1_lod2_Success)
{
	if(!GameObjectManager)
		CHECK(false);

	auto obj = GameObjectManager->CreateObject("VEG1_LOD2", "VEG1_LOD2", reVector3Df(0, 0, 0));
	CHECK(obj);

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 1);
}

TEST_FIXTURE(GameObjectFixture, GameObjectGet_CGameObjectveg1_lod2_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	

	CHECK(GameObjectManager->GetGameObject("VEG1_LOD2"));
}

TEST_FIXTURE(GameObjectFixture, GameObjectRemove_CGameObjectveg1_lod2_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	GameObjectManager->RemoveGameObject(GameObjectManager->GetGameObject("VEG1_LOD2"));

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 0);
}

TEST_FIXTURE(GameObjectFixture, GameObjectAdd_CGameObjectveg10_Success)
{
	if(!GameObjectManager)
		CHECK(false);

	auto obj = GameObjectManager->CreateObject("VEG10", "VEG10", reVector3Df(0, 0, 0));
	CHECK(obj);

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 1);
}

TEST_FIXTURE(GameObjectFixture, GameObjectGet_CGameObjectveg10_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	

	CHECK(GameObjectManager->GetGameObject("VEG10"));
}

TEST_FIXTURE(GameObjectFixture, GameObjectRemove_CGameObjectveg10_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	GameObjectManager->RemoveGameObject(GameObjectManager->GetGameObject("VEG10"));

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 0);
}

TEST_FIXTURE(GameObjectFixture, GameObjectAdd_CGameObjectveg2_Success)
{
	if(!GameObjectManager)
		CHECK(false);

	auto obj = GameObjectManager->CreateObject("VEG2", "VEG2", reVector3Df(0, 0, 0));
	CHECK(obj);

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 1);
}

TEST_FIXTURE(GameObjectFixture, GameObjectGet_CGameObjectveg2_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	

	CHECK(GameObjectManager->GetGameObject("VEG2"));
}

TEST_FIXTURE(GameObjectFixture, GameObjectRemove_CGameObjectveg2_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	GameObjectManager->RemoveGameObject(GameObjectManager->GetGameObject("VEG2"));

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 0);
}

TEST_FIXTURE(GameObjectFixture, GameObjectAdd_CGameObjectveg2_lod2_Success)
{
	if(!GameObjectManager)
		CHECK(false);

	auto obj = GameObjectManager->CreateObject("VEG2_LOD2", "VEG2_LOD2", reVector3Df(0, 0, 0));
	CHECK(obj);

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 1);
}

TEST_FIXTURE(GameObjectFixture, GameObjectGet_CGameObjectveg2_lod2_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	

	CHECK(GameObjectManager->GetGameObject("VEG2_LOD2"));
}

TEST_FIXTURE(GameObjectFixture, GameObjectRemove_CGameObjectveg2_lod2_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	GameObjectManager->RemoveGameObject(GameObjectManager->GetGameObject("VEG2_LOD2"));

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 0);
}

TEST_FIXTURE(GameObjectFixture, GameObjectAdd_CGameObjectveg4_Success)
{
	if(!GameObjectManager)
		CHECK(false);

	auto obj = GameObjectManager->CreateObject("VEG4", "VEG4", reVector3Df(0, 0, 0));
	CHECK(obj);

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 1);
}

TEST_FIXTURE(GameObjectFixture, GameObjectGet_CGameObjectveg4_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	

	CHECK(GameObjectManager->GetGameObject("VEG4"));
}

TEST_FIXTURE(GameObjectFixture, GameObjectRemove_CGameObjectveg4_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	GameObjectManager->RemoveGameObject(GameObjectManager->GetGameObject("VEG4"));

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 0);
}

TEST_FIXTURE(GameObjectFixture, GameObjectAdd_CGameObjectveg4_lod1_Success)
{
	if(!GameObjectManager)
		CHECK(false);

	auto obj = GameObjectManager->CreateObject("VEG4_LOD1", "VEG4_LOD1", reVector3Df(0, 0, 0));
	CHECK(obj);

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 1);
}

TEST_FIXTURE(GameObjectFixture, GameObjectGet_CGameObjectveg4_lod1_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	

	CHECK(GameObjectManager->GetGameObject("VEG4_LOD1"));
}

TEST_FIXTURE(GameObjectFixture, GameObjectRemove_CGameObjectveg4_lod1_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	GameObjectManager->RemoveGameObject(GameObjectManager->GetGameObject("VEG4_LOD1"));

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 0);
}

TEST_FIXTURE(GameObjectFixture, GameObjectAdd_CGameObjectveg4_lod2_Success)
{
	if(!GameObjectManager)
		CHECK(false);

	auto obj = GameObjectManager->CreateObject("VEG4_LOD2", "VEG4_LOD2", reVector3Df(0, 0, 0));
	CHECK(obj);

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 1);
}

TEST_FIXTURE(GameObjectFixture, GameObjectGet_CGameObjectveg4_lod2_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	

	CHECK(GameObjectManager->GetGameObject("VEG4_LOD2"));
}

TEST_FIXTURE(GameObjectFixture, GameObjectRemove_CGameObjectveg4_lod2_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	GameObjectManager->RemoveGameObject(GameObjectManager->GetGameObject("VEG4_LOD2"));

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 0);
}

TEST_FIXTURE(GameObjectFixture, GameObjectAdd_CGameObjectveg8_Success)
{
	if(!GameObjectManager)
		CHECK(false);

	auto obj = GameObjectManager->CreateObject("VEG8", "VEG8", reVector3Df(0, 0, 0));
	CHECK(obj);

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 1);
}

TEST_FIXTURE(GameObjectFixture, GameObjectGet_CGameObjectveg8_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	

	CHECK(GameObjectManager->GetGameObject("VEG8"));
}

TEST_FIXTURE(GameObjectFixture, GameObjectRemove_CGameObjectveg8_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	GameObjectManager->RemoveGameObject(GameObjectManager->GetGameObject("VEG8"));

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 0);
}

TEST_FIXTURE(GameObjectFixture, GameObjectAdd_CGameObjectveg8_lod2_Success)
{
	if(!GameObjectManager)
		CHECK(false);

	auto obj = GameObjectManager->CreateObject("VEG8_LOD2", "VEG8_LOD2", reVector3Df(0, 0, 0));
	CHECK(obj);

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 1);
}

TEST_FIXTURE(GameObjectFixture, GameObjectGet_CGameObjectveg8_lod2_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	

	CHECK(GameObjectManager->GetGameObject("VEG8_LOD2"));
}

TEST_FIXTURE(GameObjectFixture, GameObjectRemove_CGameObjectveg8_lod2_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	GameObjectManager->RemoveGameObject(GameObjectManager->GetGameObject("VEG8_LOD2"));

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 0);
}

TEST_FIXTURE(GameObjectFixture, GameObjectAdd_CGameObjectveg9_Success)
{
	if(!GameObjectManager)
		CHECK(false);

	auto obj = GameObjectManager->CreateObject("VEG9", "VEG9", reVector3Df(0, 0, 0));
	CHECK(obj);

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 1);
}

TEST_FIXTURE(GameObjectFixture, GameObjectGet_CGameObjectveg9_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	

	CHECK(GameObjectManager->GetGameObject("VEG9"));
}

TEST_FIXTURE(GameObjectFixture, GameObjectRemove_CGameObjectveg9_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	GameObjectManager->RemoveGameObject(GameObjectManager->GetGameObject("VEG9"));

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 0);
}

TEST_FIXTURE(GameObjectFixture, GameObjectAdd_CGameObjectveg9_lod2_Success)
{
	if(!GameObjectManager)
		CHECK(false);

	auto obj = GameObjectManager->CreateObject("VEG9_LOD2", "VEG9_LOD2", reVector3Df(0, 0, 0));
	CHECK(obj);

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 1);
}

TEST_FIXTURE(GameObjectFixture, GameObjectGet_CGameObjectveg9_lod2_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	

	CHECK(GameObjectManager->GetGameObject("VEG9_LOD2"));
}

TEST_FIXTURE(GameObjectFixture, GameObjectRemove_CGameObjectveg9_lod2_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	GameObjectManager->RemoveGameObject(GameObjectManager->GetGameObject("VEG9_LOD2"));

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 0);
}

TEST_FIXTURE(GameObjectFixture, GameObjectAdd_CGameObjectvillage_church_Success)
{
	if(!GameObjectManager)
		CHECK(false);

	auto obj = GameObjectManager->CreateObject("VILLAGE_CHURCH", "VILLAGE_CHURCH", reVector3Df(0, 0, 0));
	CHECK(obj);

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 1);
}

TEST_FIXTURE(GameObjectFixture, GameObjectGet_CGameObjectvillage_church_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	

	CHECK(GameObjectManager->GetGameObject("VILLAGE_CHURCH"));
}

TEST_FIXTURE(GameObjectFixture, GameObjectRemove_CGameObjectvillage_church_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	GameObjectManager->RemoveGameObject(GameObjectManager->GetGameObject("VILLAGE_CHURCH"));

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 0);
}

TEST_FIXTURE(GameObjectFixture, GameObjectAdd_CGameObjectvillage_fence1_Success)
{
	if(!GameObjectManager)
		CHECK(false);

	auto obj = GameObjectManager->CreateObject("VILLAGE_FENCE1", "VILLAGE_FENCE1", reVector3Df(0, 0, 0));
	CHECK(obj);

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 1);
}

TEST_FIXTURE(GameObjectFixture, GameObjectGet_CGameObjectvillage_fence1_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	

	CHECK(GameObjectManager->GetGameObject("VILLAGE_FENCE1"));
}

TEST_FIXTURE(GameObjectFixture, GameObjectRemove_CGameObjectvillage_fence1_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	GameObjectManager->RemoveGameObject(GameObjectManager->GetGameObject("VILLAGE_FENCE1"));

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 0);
}

TEST_FIXTURE(GameObjectFixture, GameObjectAdd_CGameObjectvillage_fence2_Success)
{
	if(!GameObjectManager)
		CHECK(false);

	auto obj = GameObjectManager->CreateObject("VILLAGE_FENCE2", "VILLAGE_FENCE2", reVector3Df(0, 0, 0));
	CHECK(obj);

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 1);
}

TEST_FIXTURE(GameObjectFixture, GameObjectGet_CGameObjectvillage_fence2_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	

	CHECK(GameObjectManager->GetGameObject("VILLAGE_FENCE2"));
}

TEST_FIXTURE(GameObjectFixture, GameObjectRemove_CGameObjectvillage_fence2_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	GameObjectManager->RemoveGameObject(GameObjectManager->GetGameObject("VILLAGE_FENCE2"));

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 0);
}

TEST_FIXTURE(GameObjectFixture, GameObjectAdd_CGameObjectvillage_fence3_Success)
{
	if(!GameObjectManager)
		CHECK(false);

	auto obj = GameObjectManager->CreateObject("VILLAGE_FENCE3", "VILLAGE_FENCE3", reVector3Df(0, 0, 0));
	CHECK(obj);

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 1);
}

TEST_FIXTURE(GameObjectFixture, GameObjectGet_CGameObjectvillage_fence3_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	

	CHECK(GameObjectManager->GetGameObject("VILLAGE_FENCE3"));
}

TEST_FIXTURE(GameObjectFixture, GameObjectRemove_CGameObjectvillage_fence3_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	GameObjectManager->RemoveGameObject(GameObjectManager->GetGameObject("VILLAGE_FENCE3"));

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 0);
}

TEST_FIXTURE(GameObjectFixture, GameObjectAdd_CGameObjectvillage_house1_Success)
{
	if(!GameObjectManager)
		CHECK(false);

	auto obj = GameObjectManager->CreateObject("VILLAGE_HOUSE1", "VILLAGE_HOUSE1", reVector3Df(0, 0, 0));
	CHECK(obj);

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 1);
}

TEST_FIXTURE(GameObjectFixture, GameObjectGet_CGameObjectvillage_house1_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	

	CHECK(GameObjectManager->GetGameObject("VILLAGE_HOUSE1"));
}

TEST_FIXTURE(GameObjectFixture, GameObjectRemove_CGameObjectvillage_house1_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	GameObjectManager->RemoveGameObject(GameObjectManager->GetGameObject("VILLAGE_HOUSE1"));

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 0);
}

TEST_FIXTURE(GameObjectFixture, GameObjectAdd_CGameObjectvillage_house2_Success)
{
	if(!GameObjectManager)
		CHECK(false);

	auto obj = GameObjectManager->CreateObject("VILLAGE_HOUSE2", "VILLAGE_HOUSE2", reVector3Df(0, 0, 0));
	CHECK(obj);

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 1);
}

TEST_FIXTURE(GameObjectFixture, GameObjectGet_CGameObjectvillage_house2_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	

	CHECK(GameObjectManager->GetGameObject("VILLAGE_HOUSE2"));
}

TEST_FIXTURE(GameObjectFixture, GameObjectRemove_CGameObjectvillage_house2_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	GameObjectManager->RemoveGameObject(GameObjectManager->GetGameObject("VILLAGE_HOUSE2"));

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 0);
}

TEST_FIXTURE(GameObjectFixture, GameObjectAdd_CGameObjectvillage_house3_Success)
{
	if(!GameObjectManager)
		CHECK(false);

	auto obj = GameObjectManager->CreateObject("VILLAGE_HOUSE3", "VILLAGE_HOUSE3", reVector3Df(0, 0, 0));
	CHECK(obj);

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 1);
}

TEST_FIXTURE(GameObjectFixture, GameObjectGet_CGameObjectvillage_house3_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	

	CHECK(GameObjectManager->GetGameObject("VILLAGE_HOUSE3"));
}

TEST_FIXTURE(GameObjectFixture, GameObjectRemove_CGameObjectvillage_house3_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	GameObjectManager->RemoveGameObject(GameObjectManager->GetGameObject("VILLAGE_HOUSE3"));

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 0);
}

TEST_FIXTURE(GameObjectFixture, GameObjectAdd_CGameObjectvillage_house4_Success)
{
	if(!GameObjectManager)
		CHECK(false);

	auto obj = GameObjectManager->CreateObject("VILLAGE_HOUSE4", "VILLAGE_HOUSE4", reVector3Df(0, 0, 0));
	CHECK(obj);

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 1);
}

TEST_FIXTURE(GameObjectFixture, GameObjectGet_CGameObjectvillage_house4_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	

	CHECK(GameObjectManager->GetGameObject("VILLAGE_HOUSE4"));
}

TEST_FIXTURE(GameObjectFixture, GameObjectRemove_CGameObjectvillage_house4_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	GameObjectManager->RemoveGameObject(GameObjectManager->GetGameObject("VILLAGE_HOUSE4"));

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 0);
}

TEST_FIXTURE(GameObjectFixture, GameObjectAdd_CGameObjectvillage_house5_Success)
{
	if(!GameObjectManager)
		CHECK(false);

	auto obj = GameObjectManager->CreateObject("VILLAGE_HOUSE5", "VILLAGE_HOUSE5", reVector3Df(0, 0, 0));
	CHECK(obj);

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 1);
}

TEST_FIXTURE(GameObjectFixture, GameObjectGet_CGameObjectvillage_house5_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	

	CHECK(GameObjectManager->GetGameObject("VILLAGE_HOUSE5"));
}

TEST_FIXTURE(GameObjectFixture, GameObjectRemove_CGameObjectvillage_house5_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	GameObjectManager->RemoveGameObject(GameObjectManager->GetGameObject("VILLAGE_HOUSE5"));

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 0);
}

TEST_FIXTURE(GameObjectFixture, GameObjectAdd_CGameObjectvillage_house6_Success)
{
	if(!GameObjectManager)
		CHECK(false);

	auto obj = GameObjectManager->CreateObject("VILLAGE_HOUSE6", "VILLAGE_HOUSE6", reVector3Df(0, 0, 0));
	CHECK(obj);

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 1);
}

TEST_FIXTURE(GameObjectFixture, GameObjectGet_CGameObjectvillage_house6_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	

	CHECK(GameObjectManager->GetGameObject("VILLAGE_HOUSE6"));
}

TEST_FIXTURE(GameObjectFixture, GameObjectRemove_CGameObjectvillage_house6_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	GameObjectManager->RemoveGameObject(GameObjectManager->GetGameObject("VILLAGE_HOUSE6"));

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 0);
}

TEST_FIXTURE(GameObjectFixture, GameObjectAdd_CGameObjectvillage_house7_Success)
{
	if(!GameObjectManager)
		CHECK(false);

	auto obj = GameObjectManager->CreateObject("VILLAGE_HOUSE7", "VILLAGE_HOUSE7", reVector3Df(0, 0, 0));
	CHECK(obj);

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 1);
}

TEST_FIXTURE(GameObjectFixture, GameObjectGet_CGameObjectvillage_house7_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	

	CHECK(GameObjectManager->GetGameObject("VILLAGE_HOUSE7"));
}

TEST_FIXTURE(GameObjectFixture, GameObjectRemove_CGameObjectvillage_house7_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	GameObjectManager->RemoveGameObject(GameObjectManager->GetGameObject("VILLAGE_HOUSE7"));

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 0);
}

TEST_FIXTURE(GameObjectFixture, GameObjectAdd_CGameObjectWall_Success)
{
	if(!GameObjectManager)
		CHECK(false);

	auto obj = GameObjectManager->CreateObject("WALL", "WALL", reVector3Df(0, 0, 0));
	CHECK(obj);

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 1);
}

TEST_FIXTURE(GameObjectFixture, GameObjectGet_CGameObjectWall_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	

	CHECK(GameObjectManager->GetGameObject("WALL"));
}

TEST_FIXTURE(GameObjectFixture, GameObjectRemove_CGameObjectWall_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	GameObjectManager->RemoveGameObject(GameObjectManager->GetGameObject("WALL"));

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 0);
}

TEST_FIXTURE(GameObjectFixture, GameObjectAdd_CGameObjectzombie_small_Success)
{
	if(!GameObjectManager)
		CHECK(false);

	auto obj = GameObjectManager->CreateObject("ZOMBIE_SMALL", "ZOMBIE_SMALL", reVector3Df(0, 0, 0));
	CHECK(obj);

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 1);
}

TEST_FIXTURE(GameObjectFixture, GameObjectGet_CGameObjectzombie_small_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	

	CHECK(GameObjectManager->GetGameObject("ZOMBIE_SMALL"));
}

TEST_FIXTURE(GameObjectFixture, GameObjectRemove_CGameObjectzombie_small_Success)
{
	if(!GameObjectManager)
		CHECK(false);
	GameObjectManager->RemoveGameObject(GameObjectManager->GetGameObject("ZOMBIE_SMALL"));

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 0);
}

}
