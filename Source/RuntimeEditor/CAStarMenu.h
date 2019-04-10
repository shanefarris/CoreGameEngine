#ifndef __CASTARMENU_H___
#define __CASTARMENU_H___

#include "Defines.h"
#include "EditorObjects.h"
#include "MyGui/MyGUI.h"

namespace Core
{
	class CGameObject;

	namespace AI
	{
		class CAStarGrid;
	}

	namespace GUI
	{
		class CGuiStrategy_MyGui;
	}
	
namespace Editor
{
	class CAStarMenu
	{
	public:
		CAStarMenu(GUI::CGuiStrategy_MyGui* Strategy);
		~CAStarMenu();
		
		void SetVisible(bool Visible);
		void SetVisible(bool Visible, const SELECTED& Selected);
		MyGUI::Widget* GetForm() { return frmAStar; }
				
		void cmbASPSize_ComboAccept(MyGUI::ComboBox* _sender, size_t _index);
		void btnASPSave_Click(MyGUI::WidgetPtr _sender);
		void btnASPDelete_Click(MyGUI::WidgetPtr _sender);
		void btnASPClose_Click(MyGUI::WidgetPtr _sender);
		void btnASPTest_Click(MyGUI::WidgetPtr _sender);
		void btnASPRemove_Click(MyGUI::WidgetPtr _sender);
		void chkASPShowGrid_Click(MyGUI::WidgetPtr _sender);

	private:
		
		void Close();
		void Save();
		void PopulateNodeList();
		void CreateGrid();
		void CreateGraphic();

		bool				isCreated;
		bool				isGraphics;
		ManualObject*		m_Lines;
		AI::CAStarGrid*		m_AStarGrid;
	
		MyGUI::Widget*		frmAStar;
		MyGUI::EditPtr		txtASPStartX;
		MyGUI::EditPtr		txtASPStartZ;
		MyGUI::ComboBoxPtr	cmbASPSize;
		MyGUI::ButtonPtr	btnASPSave;
		MyGUI::ButtonPtr	btnASPDelete;
		MyGUI::ButtonPtr	btnASPClose;
		MyGUI::ButtonPtr	btnASPTest;
		MyGUI::ButtonPtr	btnASPRemove;
		MyGUI::ListPtr		lstASPNodes;
		MyGUI::ButtonPtr	chkASPShowGrid;
	};
	
}
}

#endif // __CASTARMENU_H___