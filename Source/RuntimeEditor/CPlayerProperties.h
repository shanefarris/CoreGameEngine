#ifndef __CPLAYER_PROPERTIES_MENU_H__
#define __CPLAYER_PROPERTIES_MENU_H__

#include "EditorObjects.h"
#include "MyGui/MyGUI.h"

namespace Core
{
	class CPlayer;

	namespace GUI
	{
		class CGuiStrategy_MyGui;
	}

namespace Editor
{
	class CPlayerProperties
	{
	public:
		CPlayerProperties(GUI::CGuiStrategy_MyGui* Strategy);
		~CPlayerProperties();

		void SetVisible(bool Visible, CPlayer* Player = nullptr);
		MyGUI::Widget* GetForm() { return frmPlayerProperties; }

	private:
		void btnPlayerCancel_Click(MyGUI::Widget* _sender);
		void btnPlayerSave_Click(MyGUI::Widget* _sender);
		void chkPlayerShowLoS_Click(MyGUI::Widget* _sender);
		void chkPlayerShowBB_Click(MyGUI::Widget* _sender);
		void chkPlayerShowCC_Click(MyGUI::Widget* _sender);
		void cmbPlayerAllItems_ComboAccept(MyGUI::ComboBox* _sender, size_t _index);
		void btnPlayerAddItem_Click(MyGUI::Widget* _sender);
		void btnPlayerRemoveItem_Click(MyGUI::Widget* _sender);
		void cmbPlayerState_ComboAccept(MyGUI::ComboBox* _sender, size_t _index);
		void cmbPlayerTarget_ComboAccept(MyGUI::ComboBox* _sender, size_t _index);
		void cmbPlayerTeam_ComboAccept(MyGUI::ComboBox* _sender, size_t _index);
		void chkPlayerIsHuman_Click(MyGUI::Widget* _sender);

		void PoplatePlayerTargets();

		CPlayer*				m_Player;
		bool					isVisible;
		bool					isHuman;
		
		MyGUI::Widget*		frmPlayerProperties;
		MyGUI::EditPtr		txtPlayerName;
		MyGUI::Button*		chkPlayerShowLoS;
		MyGUI::Button*		chkPlayerShowBB;
		MyGUI::Button*		chkPlayerShowCC;
		MyGUI::ListPtr		lstPlayerItems;
		MyGUI::ComboBox*	cmbPlayerAllItems;
		MyGUI::Button*		btnPlayerAddItem;
		MyGUI::Button*		btnPlayerRemoveItem;
		MyGUI::ComboBox*	cmbPlayerState;
		MyGUI::ComboBox*	cmbPlayerTarget;
		MyGUI::ComboBox*	cmbPlayerTeam;
		MyGUI::Button*		btnPlayerCancel;
		MyGUI::Button*		btnPlayerSave;
		MyGUI::Button*		chkPlayerIsHuman;
		MyGUI::EditPtr		txtPlayerPosX;
		MyGUI::EditPtr		txtPlayerPosY;
		MyGUI::EditPtr		txtPlayerPosZ;

	};
}
}
#endif // __CPLAYER_PROPERTIES_MENU_H__