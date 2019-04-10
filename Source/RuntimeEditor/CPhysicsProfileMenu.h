#ifndef __CPHYSICSPROFILEMENU_H__
#define __CPHYSICSPROFILEMENU_H__

#include "Defines.h"
#include "EditorObjects.h"
#include "MyGui/MyGUI.h"

namespace Core
{
	namespace GUI
	{
		class CGuiStrategy_MyGui;
	}
	
namespace Editor
{
	class CPhysicsProfileMenu
	{
	public:
		CPhysicsProfileMenu(GUI::CGuiStrategy_MyGui* Strategy);
		~CPhysicsProfileMenu();
		
		void SetVisible(bool Visible);
		MyGUI::Widget* GetForm() { return frmPhysicsProfiles; }
				
	private:
		void cmbGOPhyShape_ComboAccept(MyGUI::ComboBox* _sender, size_t _index);
		void cmbGOPhyBodyType_ComboAccept(MyGUI::ComboBox* _sender, size_t _index);
		void btnGOPhySave_Click(MyGUI::Widget* _sender);
		void btnGOPhyClose_Click(MyGUI::Widget* _sender);
		
		void Close();
		void ResetControls();

		GUI::CGuiStrategy_MyGui* m_Strategy;

		MyGUI::ComboBox*	cmbGOPhyShape;
		MyGUI::EditPtr		txtGOPhyMass;
		MyGUI::EditPtr		txtGOPhyDensity;
		MyGUI::EditPtr		txtGOPhyRes;
		MyGUI::EditPtr		txtGOPhyFriction;
		MyGUI::EditPtr		txtGOPhyRadius;
		MyGUI::EditPtr		txtGOPhySizeX;
		MyGUI::ComboBox*	cmbGOPhyBodyType;
		MyGUI::Button*		btnGOPhySave;
		MyGUI::Button*		btnGOPhyClose;
		MyGUI::EditPtr		txtGOPhySizeY;
		MyGUI::EditPtr		txtGOPhySizeZ;
		MyGUI::EditPtr		txtGOPhysProfileName;
		MyGUI::Widget*		frmPhysicsProfiles;
	};
	
}
}

#endif // __CPHYSICSPROFILEMENU_H__