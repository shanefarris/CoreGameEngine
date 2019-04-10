#ifndef __CLIGHT_MENU_H__
#define __CLIGHT_MENU_H__

#include "Defines.h"
#include "MyGui/MyGUI.h"

namespace Core
{
	class CGameObject;

	namespace Editor
	{
		struct SELECTED;
	}

	namespace GUI
	{
		class IGuiStrategy;
		class CGuiStrategy_MyGui;
	}

namespace Editor
{
	class CLightMenu
	{
	public:
		CLightMenu(GUI::CGuiStrategy_MyGui* Strategy);
		~CLightMenu();

		void SetVisible(bool Visible);
		void SetVisible(bool Visible, const SELECTED& Selected, CGameObject* GameObject);
		MyGUI::Widget* GetForm() { return frmLight; }

	private:
		void btnLightCancel_Click(MyGUI::WidgetPtr _sender);
		void btnLightSave_Click(MyGUI::WidgetPtr _sender);

		bool Save();
		
		GUI::IGuiStrategy*  m_Strategy;
		CGameObject*		m_GameObject;

		MyGUI::Widget*		frmLight;
		MyGUI::ComboBoxPtr	cmbLightType;
		MyGUI::ButtonPtr	chkLightVisible;
		MyGUI::Edit*		txtLightName;
		MyGUI::Edit*		txtLightDiffuseX;
		MyGUI::Edit*		txtLightDiffuseY;
		MyGUI::Edit*		txtLightDiffuseZ;
		MyGUI::Edit*		txtLightDiffuseA;
		MyGUI::Edit*		txtLightSpecularX;
		MyGUI::Edit*		txtLightSpecularY;
		MyGUI::Edit*		txtLightSpecularZ;
		MyGUI::Edit*		txtLightSpecularA;
		MyGUI::Edit*		txtLightAttRange;
		MyGUI::Edit*		txtLightAttConstant;
		MyGUI::Edit*		txtLightAttLinear;
		MyGUI::Edit*		txtLightAttQuadratic;
		MyGUI::Edit*		txtLightPosX;
		MyGUI::Edit*		txtLightPosY;
		MyGUI::Edit*		txtLightPosZ;
		MyGUI::Edit*		txtLightDirX;
		MyGUI::Edit*		txtLightDirY;
		MyGUI::Edit*		txtLightDirZ;
		MyGUI::Edit*		txtLightPower;
		MyGUI::Edit*		txtLightShadNearClipDis;
		MyGUI::Edit*		txtShadFarClipDis;
		MyGUI::Edit*		txtLightShadFarDis;
		MyGUI::Edit*		txtLightInner;
		MyGUI::Edit*		txtLightOutter;
		MyGUI::Edit*		txtLightFalloff;
		MyGUI::ButtonPtr	btnLightCancel;
		MyGUI::ButtonPtr	btnLightSave;
	};
}
}
#endif // __CLIGHT_MENU_H__