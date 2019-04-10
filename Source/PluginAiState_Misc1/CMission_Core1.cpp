#include "CMission_Core1.h"

using namespace Core;
using namespace Core::Plugin;
using namespace Core::Mission;

CMission_Core1::CMission_Core1()
{
	// Just kill enemy
	CompletionDefinition = EC_ELIMINATE;

	LableName = "Core1_Mission1";
}

CMission_Core1::~CMission_Core1()
{
}

void CMission_Core1::OnStart()
{
	std::cout << "CMission_Core1::OnStart()" << std::endl;
}

void CMission_Core1::OnFail()
{
	std::cout << "CMission_Core1::OnFail()" << std::endl;
}

void CMission_Core1::OnComplete()
{
	std::cout << "CMission_Core1::OnComplete()" << std::endl;
}

CMissionFactory_Core1::CMissionFactory_Core1()
{
	LabelName = "Core1_Mission1";
}

CMissionFactory_Core1::~CMissionFactory_Core1()
{
}

Core::Mission::IMission* CMissionFactory_Core1::GetMission()
{
	return new CMission_Core1();
}