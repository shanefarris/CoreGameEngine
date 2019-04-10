#include "../UnitTest++/UnitTest++.h"
#include "RecordingReporter.h"

#include "Core/CoreEngine.h"

using namespace UnitTest;


namespace {

struct GameObjectmanagerInitializationFixture
{
	Ogre::Timer m_Timer;
	CGameState*	m_ActiveState;
	f32	LastTime;

	CGameObjectManager* GameObjectManager;

	GameObjectmanagerInitializationFixture()
	{
		CGameManager::Instance();
		CInputManager::Instance();
		CPluginManager::Instance();
		GameObjectManager = CGameObjectManager::Instance();
		LastTime = m_Timer.getMilliseconds();
		m_ActiveState = nullptr;
	}
};

TEST_FIXTURE(GameObjectmanagerInitializationFixture, GameObjectManagerInitializeSuccess)
{
    CHECK_EQUAL(GameObjectManager, CGameObjectManager::Instance());
}

TEST_FIXTURE(GameObjectmanagerInitializationFixture, GameObjectManagerAddPlayersSuccess)
{
	if(!GameObjectManager)
		CHECK(false);

	GameObjectManager->CreatePlayer("SOLDIER1", EPT_TEAM_1, "player1");
	GameObjectManager->CreatePlayer("SOLDIER1", EPT_TEAM_1, "player2");

	Vector<CPlayer*> players;
	GameObjectManager->GetAllPlayers(players);

    CHECK_EQUAL(players.size(), 2);
}

TEST_FIXTURE(GameObjectmanagerInitializationFixture, GameObjectManagerGetPlayersSuccess)
{
	if(!GameObjectManager)
		CHECK(false);

	CHECK(GameObjectManager->GetPlayerByName("player1"));
	CHECK(GameObjectManager->GetPlayerByName("player2"));

}

TEST_FIXTURE(GameObjectmanagerInitializationFixture, GameObjectManagerRemovePlayersSuccess)
{
	if(!GameObjectManager)
		CHECK(false);

	GameObjectManager->RemoveAllPlayers();

	Vector<CPlayer*> players;
	GameObjectManager->GetAllPlayers(players);

    CHECK_EQUAL(players.size(), 0);

	GameObjectManager->GetTeam(EPT_TEAM_1, players);

	CHECK_EQUAL(players.size(), 0);
}

TEST_FIXTURE(GameObjectmanagerInitializationFixture, GameObjectManagerAddObjectsSuccess)
{
	if(!GameObjectManager)
		CHECK(false);

	GameObjectManager->CreateObject("CRATE_1", "crate1", reVector3Df(0, 0, 0));
	GameObjectManager->CreateObject("CRATE_1", "crate2", reVector3Df(0, 20, 0));
	GameObjectManager->CreateObject("CRATE_1", "crate3", reVector3Df(0, 40, 0));

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);

	CHECK_EQUAL(gameObjects.size(), 3);
}

TEST_FIXTURE(GameObjectmanagerInitializationFixture, GameObjectManagerGetObjectsSuccess)
{
	if(!GameObjectManager)
		CHECK(false);

	CHECK(GameObjectManager->GetGameObject("crate1"));
	CHECK(GameObjectManager->GetGameObject("crate2"));
	CHECK(GameObjectManager->GetGameObject("crate3"));
}

TEST_FIXTURE(GameObjectmanagerInitializationFixture, GameObjectManagerRemoveObjectsSuccess)
{
	if(!GameObjectManager)
		CHECK(false);

	GameObjectManager->RemoveGameObject(GameObjectManager->GetGameObject("crate1"));
	GameObjectManager->RemoveGameObject(GameObjectManager->GetGameObject("crate2"));
	GameObjectManager->RemoveGameObject(GameObjectManager->GetGameObject("crate3"));

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);

	CHECK_EQUAL(gameObjects.size(), 0);
}

TEST_FIXTURE(GameObjectmanagerInitializationFixture, GameObjectManagerAddSphereObstaclesSuccess)
{
	if(!GameObjectManager)
		CHECK(false);

	GameObjectManager->AddSphereObstacle(GameObjectManager->CreateObject("CRATE_1", "crate1", reVector3Df(0, 0, 0)));
	GameObjectManager->AddSphereObstacle(GameObjectManager->CreateObject("CRATE_1", "crate2", reVector3Df(0, 20, 0)));
	GameObjectManager->AddSphereObstacle(GameObjectManager->CreateObject("CRATE_1", "crate3", reVector3Df(0, 40, 0)));

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 3);

	Vector<AI::Obstacle*> obstacles;
	GameObjectManager->GetObstacles(obstacles);
	CHECK_EQUAL(obstacles.size(), 3);
}

TEST_FIXTURE(GameObjectmanagerInitializationFixture, GameObjectManagerRemoveSphereObstaclesSuccess)
{
	if(!GameObjectManager)
		CHECK(false);

	Vector<AI::Obstacle*> obstacles;
	GameObjectManager->GetObstacles(obstacles);
	CHECK_EQUAL(obstacles.size(), 3);

	GameObjectManager->RemoveGameObject(GameObjectManager->GetGameObject("crate1"));
	GameObjectManager->RemoveGameObject(GameObjectManager->GetGameObject("crate2"));
	GameObjectManager->RemoveGameObject(GameObjectManager->GetGameObject("crate3"));

	GameObjectManager->GetObstacles(obstacles);
	CHECK_EQUAL(obstacles.size(), 0);
}

TEST_FIXTURE(GameObjectmanagerInitializationFixture, GameObjectManageShutdownRestartSuccess)
{
	if(!GameObjectManager)
		CHECK(false);

	GameObjectManager->AddSphereObstacle(GameObjectManager->CreateObject("CRATE_1", "crate1", reVector3Df(0, 0, 0)));
	GameObjectManager->AddSphereObstacle(GameObjectManager->CreateObject("CRATE_1", "crate2", reVector3Df(0, 20, 0)));
	GameObjectManager->AddSphereObstacle(GameObjectManager->CreateObject("CRATE_1", "crate3", reVector3Df(0, 40, 0)));

	Vector<CGameObject*> gameObjects;
	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 3);

	Vector<AI::Obstacle*> obstacles;
	GameObjectManager->GetObstacles(obstacles);
	CHECK_EQUAL(obstacles.size(), 3);

	GameObjectManager->Shutdown();

	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 0);

	GameObjectManager->GetObstacles(obstacles);
	CHECK_EQUAL(obstacles.size(), 0);

	GameObjectManager->Restart();

	GameObjectManager->AddSphereObstacle(GameObjectManager->CreateObject("CRATE_1", "crate1", reVector3Df(0, 0, 0)));
	GameObjectManager->AddSphereObstacle(GameObjectManager->CreateObject("CRATE_1", "crate2", reVector3Df(0, 20, 0)));
	GameObjectManager->AddSphereObstacle(GameObjectManager->CreateObject("CRATE_1", "crate3", reVector3Df(0, 40, 0)));

	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 3);

	GameObjectManager->GetObstacles(obstacles);
	CHECK_EQUAL(obstacles.size(), 3);

	GameObjectManager->Shutdown();

	GameObjectManager->GetGameObjects(gameObjects);
	CHECK_EQUAL(gameObjects.size(), 0);

	GameObjectManager->GetObstacles(obstacles);
	CHECK_EQUAL(obstacles.size(), 0);
}


}