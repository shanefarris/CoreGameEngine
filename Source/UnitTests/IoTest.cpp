#include "../UnitTest++/UnitTest++.h"
#include "RecordingReporter.h"

#include "IO/IFileSystem.h"
#include "IO/CFileSystem.h"

using namespace UnitTest;


namespace {

struct IoInitalizeFixture
{
	IO::IFileSystem* FileSystem;

	IoInitalizeFixture()
	{
		FileSystem = new IO::CFileSystem();
	}
};

TEST_FIXTURE(IoInitalizeFixture, IOFindConfigFileSuccess)
{
	bool test = FileSystem->ExistFile("config.xml");
	CHECK(test);
}

}