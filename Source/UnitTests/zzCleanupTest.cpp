#include "../UnitTest++/UnitTest++.h"
#include "RecordingReporter.h"

#include "Core/CoreEngine.h"

using namespace UnitTest;


namespace {

struct zCleanupInitalizeFixture
{
	CGameManager* GameManager;

	zCleanupInitalizeFixture()
	{
		GameManager = CGameManager::Instance();
	}
};

TEST_FIXTURE(zCleanupInitalizeFixture, zCleanupAdvanceStateSuccess)
{
	GameManager->Shutdown();
	CHECK(true);
}

}