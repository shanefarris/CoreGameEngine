#ifndef __CPLAYERATTRIBUTESCOMPONENT_H__
#define __CPLAYERATTRIBUTESCOMPONENT_H__

#include "Defines.h"

namespace Core
{
	enum E_ATTRIBUTE_TEMPLATE
	{
		EAT_CIVILIAN		= 0,
		EAT_LVL1_INFANTRY	= 1,

	};

	class CORE_EXPORT CPlayerAttributesComponent
	{
		friend CPlayerAttributesComponent;

	public:
		CPlayerAttributesComponent();
		CPlayerAttributesComponent(u32 PlayerID);
		~CPlayerAttributesComponent();

		// Sets the attributes to a specified template
		void SetAttributes(E_ATTRIBUTE_TEMPLATE Template);

		// Operators
		bool operator==(const CPlayerAttributesComponent &right) const;
		bool operator!=(const CPlayerAttributesComponent &right) const;
		bool operator>(const CPlayerAttributesComponent &right) const;
		bool operator<(const CPlayerAttributesComponent &right) const;
		CPlayerAttributesComponent& operator=(const CPlayerAttributesComponent &right);
		CPlayerAttributesComponent& operator+=(const CPlayerAttributesComponent &right);

		inline u32 GetRunSpeed() { return m_Attributes[RUN_SPEED]; }
		inline u32 GetReloadSpeed() { return m_Attributes[RELOAD_SPEED]; }
		inline u32 GetRileMarksman() { return m_Attributes[RIFLE_MARKSMAN]; }
		inline u32 GetPhysicalStrenght() { return m_Attributes[PHYSICAL_STRENGTH]; }

	private:
		Vector<u32>	m_Attributes;

		enum ATTRIBUTES
		{
			RUN_SPEED,
			RELOAD_SPEED,
			RIFLE_MARKSMAN,
			PHYSICAL_STRENGTH,
			SIZE,
		};

		void ResetAttributesList();

	};
}

#endif // __CPLAYERATTRIBUTESCOMPONENT_H__