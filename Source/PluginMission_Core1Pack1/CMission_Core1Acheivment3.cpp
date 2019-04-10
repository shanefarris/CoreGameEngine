#include "CMission_Core1Acheivment3.h"

using namespace Core;
using namespace Core::Plugin;
using namespace Core::Mission;

CMission_Core1Acheivment3::CMission_Core1Acheivment3()
{
	// Just kill enemy
	CompletionDefinition = MT_LOCATION;

	LableName = "Core1_Acheivment1";
}

CMission_Core1Acheivment3::~CMission_Core1Acheivment3()
{
}

// CMissionFactory_Core1_Acheivment3
void CMission_Core1Acheivment3::OnStart()
{
	std::cout << "CMission_Core1Acheivment3::OnStart()" << std::endl;
}

void CMission_Core1Acheivment3::OnFail()
{
	std::cout << "CMission_Core1Acheivment3::OnFail()" << std::endl;
}

void CMission_Core1Acheivment3::OnComplete()
{
	std::cout << "CMission_Core1Acheivment3::OnComplete()" << std::endl;
}

Core::Mission::MISSION_STATUS CMission_Core1Acheivment3::Update()
{
	return MS_SUCCESS;
}

void CMission_Core1Acheivment3::RegisterEvent(CMissionEvent* Event)
{
}

CMissionFactory_Core1_Acheivment3::CMissionFactory_Core1_Acheivment3()
{
	LabelName = "Core1_Acheivment3";
}

CMissionFactory_Core1_Acheivment3::~CMissionFactory_Core1_Acheivment3()
{
}

Core::Mission::IMission* CMissionFactory_Core1_Acheivment3::GetMission()
{
	return new CMission_Core1Acheivment3();
}