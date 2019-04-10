#include "CEnvironmentObserver.h"
#include "CPlayer.h"
#include "CGameObject.h"
#include "CVolumeObject.h"
#include "CPhysicsProfile.h"

using namespace Core;

//typedef void (*OnCollisionFunc)(void);
//
//void OnEnterTest(const Physics::CPhysicsProfile* Profile)
//{
//	//std::cerr << "OnEnterTest name: " << obj->Name << std::endl;
//}
//
//void OnExitTest(const Physics::CPhysicsProfile* Profile)
//{
//	//std::cerr << "OnExitTest name: " << obj->Name << std::endl;
//}
//
//
//Physics::CVolumeObject::OnEnterFunc _OnEnterTest = &OnEnterTest;
//Physics::CVolumeObject::OnExitFunc _OnExitTest = &OnExitTest;

CEnvironmentObserver::CEnvironmentObserver(const f32& Scale, CPlayer* Player) 
{
	m_Player = Player;
	//Physics::VolumePackage pack;
	//pack.isRemoveCallback = true;
	//pack.Node = Player->GetPlayerNode();
	//pack.ObjEntity = Player->GetPlayerEntity();
	//pack.Strategy = Player->GetPhysicsStrategy();
	//pack.Scale = Scale;
	//m_Volume = Player->GetPhysicsStrategy()->CreateVolume(Physics::EVT_SPHERE, &pack);
	//m_Volume->SetEnterFunc(&_OnEnterTest);
	//m_Volume->SetExitFunc(&_OnExitTest);
	
	// Set our loop count
	LoopCount = 0;
}

CEnvironmentObserver::~CEnvironmentObserver()
{
	// Remove the volume
}

void CEnvironmentObserver::SetScaleSize(const f32& Size)
{
	ScaleSize = Size;
}

void CEnvironmentObserver::Update()
{
	//if(LoopCount >= 4)
	//{
	//	if(m_Volume && m_Player)
	//		m_Volume->SetPosition(m_Player->GetPosition());
	//		
	//	LoopCount = 0;
	//}
	//LoopCount++;
}