#include "CPlayerAttributesComponent.h"
#include "CGameManager.h"
#include "FileDatabase/CoreDal.h"
#include "QueryStrings.h"
#include "IO/CoreLogging.h"

#include "OgreStringConverter.h"

using namespace Core;
using namespace Core::DAL;

CPlayerAttributesComponent::CPlayerAttributesComponent() 
{
	ResetAttributesList();
	SetAttributes(EAT_LVL1_INFANTRY);
}

CPlayerAttributesComponent::CPlayerAttributesComponent(u32 PlayerID) 
{
	// We have a player id which means we have attributes saved in a db
	StderrLog log;
	Database* db = new Database(CGameManager::Instance()->GetDefaultDatabaseName(), &log); // sqlite3 specific

	if(!db)
	{
		CORE_LOG("Could not find database in CPlayerAttributesComponent");
		SetAttributes(EAT_LVL1_INFANTRY);
		return;
	}

	// read and display all records
	Query q(*db);

	q.get_result(PLAYER_ALL(StringConverter::toString(PlayerID)));
	while (q.fetch_row())
	{
		// spawns an object from Query object
		Players tbl(db,&q); 
		m_Attributes[RUN_SPEED] = (u32)tbl.GetRunspeed();
		m_Attributes[RELOAD_SPEED] = (u32)tbl.GetReloadspeed();
		m_Attributes[RIFLE_MARKSMAN] = (u32)tbl.GetRiflemarksman();
		m_Attributes[PHYSICAL_STRENGTH] = (u32)tbl.GetPhysicalstrength();
		break;
	}
	q.free_result();
}

CPlayerAttributesComponent::~CPlayerAttributesComponent()
{
}

void CPlayerAttributesComponent::SetAttributes(E_ATTRIBUTE_TEMPLATE Template)
{
	if(Template == EAT_CIVILIAN)
	{
		m_Attributes[RUN_SPEED] = 50;
		m_Attributes[RELOAD_SPEED] = 40;
		m_Attributes[RIFLE_MARKSMAN] = 30;
		m_Attributes[PHYSICAL_STRENGTH] = 40;
	}
	else if(Template == EAT_LVL1_INFANTRY)
	{
		m_Attributes[RUN_SPEED] = 50;
		m_Attributes[RELOAD_SPEED] = 50;
		m_Attributes[RIFLE_MARKSMAN] = 50;
		m_Attributes[PHYSICAL_STRENGTH] = 50;
	}
}

bool CPlayerAttributesComponent::operator==(const CPlayerAttributesComponent &right) const
{
	for(u32 i = 0; i < m_Attributes.size(); i++)
	{
		if(right.m_Attributes[i] != m_Attributes[i])
			return false;
	}

    return true;
}

bool CPlayerAttributesComponent::operator!=(const CPlayerAttributesComponent &right) const 
{
    return !(*this == right);
}

bool CPlayerAttributesComponent::operator>(const CPlayerAttributesComponent &right) const 
{
	for(u32 i = 0; i < m_Attributes.size(); i++)
	{
		if(right.m_Attributes[i] < m_Attributes[i])
			return false;
	}
    return true;
}

bool CPlayerAttributesComponent::operator<(const CPlayerAttributesComponent &right) const 
{
	for(u32 i = 0; i < m_Attributes.size(); i++)
	{
		if(right.m_Attributes[i] > m_Attributes[i])
			return false;
	}
    return true;
}

CPlayerAttributesComponent& CPlayerAttributesComponent::operator=(const CPlayerAttributesComponent &right) 
{
	for(u32 i = 0; i < m_Attributes.size(); i++)
		m_Attributes[i] = right.m_Attributes[i];

	return (*this);
}

CPlayerAttributesComponent& CPlayerAttributesComponent::operator+=(const CPlayerAttributesComponent &right) 
{
	for(u32 i = 0; i < m_Attributes.size(); i++)
	{
		if(right.m_Attributes[i] > m_Attributes[i])
			m_Attributes[i] = right.m_Attributes[i];
	}

	return (*this);
}

void CPlayerAttributesComponent::ResetAttributesList()
{
	// Reset the attributes
	m_Attributes.resize(SIZE);
	for(u32 i = 0; i < m_Attributes.size(); i++)
	{
		m_Attributes[i] = 0;
	}
}