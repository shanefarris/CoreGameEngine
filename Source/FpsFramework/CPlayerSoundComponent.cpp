#include "CPlayerSoundComponent.h"
#include "Audio/CSoundManager.h"

using namespace Core;
using namespace Sound;

CPlayerSoundComponent::CPlayerSoundComponent() 
	: m_Move(0), 
	m_Shot(0),
	m_HolsterIn(0),
	m_HolsterOut(0),
	m_Reload(0)
{
	m_SoundManager = Sound::CSoundManager::Instance();
}

CPlayerSoundComponent::~CPlayerSoundComponent()
{	
}

CSound* CPlayerSoundComponent::SetSound(const char* FileName)
{
	CSound* sound = nullptr;
	if(m_SoundManager->HasSound(FileName))
		sound = m_SoundManager->GetSound(FileName);
	else
		sound = m_SoundManager->CreateSound(FileName);

	return sound;
}

bool CPlayerSoundComponent::SetMove(const char* FileName)
{
	m_Move = SetSound(FileName);
	return m_Move != nullptr;
}

bool CPlayerSoundComponent::SetShot(const char* FileName)
{
	m_Shot = SetSound(FileName);
	return m_Shot != nullptr;
}

bool CPlayerSoundComponent::SetHolsterIn(const char* FileName)
{
	m_HolsterIn = SetSound(FileName);
	return m_HolsterIn != nullptr;
}

bool CPlayerSoundComponent::SetHolsterOut(const char* FileName)
{
	m_HolsterOut = SetSound(FileName);
	return m_HolsterOut != nullptr;
}

bool CPlayerSoundComponent::SetReload(const char* FileName)
{
	m_Reload = SetSound(FileName);
	return m_Reload != nullptr;
}

void CPlayerSoundComponent::PlayMove()
{
	if(m_Move)
		m_Move->Play();
}

void CPlayerSoundComponent::PlayShot()
{
	if(m_Shot)
		m_Shot->Play();
}

void CPlayerSoundComponent::PlayHolsterIn()
{
	if(m_HolsterIn)
		m_HolsterIn->Play();
}

void CPlayerSoundComponent::PlayHolsterOut()
{
	if(m_HolsterOut)
		m_HolsterOut->Play();
}

void CPlayerSoundComponent::PlayReload()
{
	if(m_Reload)
		m_Reload->Play();
}