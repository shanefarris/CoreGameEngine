#ifndef __CBUILDINGMENU_H__
#define __CBUILDINGMENU_H__

#include "Defines.h"
#include "EditorObjects.h"
#include "CInputListener.h"
#include "MyGui/MyGUI.h"

namespace Core
{
	class CBuilding;
	class CGameObject;
	class CInputKeyEvent;
	class CInputMouseEvent;
	enum MouseButtonID;

	namespace GUI
	{
		class CGuiStrategy_MyGui;
	}
	
namespace Editor
{
	class CBuildingMenu : public CInputKeyListener, public CInputMouseListener
	{
	public:
		CBuildingMenu(GUI::CGuiStrategy_MyGui* Strategy);
		~CBuildingMenu();
		
		void SetVisible(bool Visible);
		void SetVisible(bool Visible, const SELECTED& Selected, CBuilding* Building = nullptr);
		MyGUI::Widget* GetForm() { return frmBuilding; }
				
	private:
		bool MouseMoved(const CInputMouseEvent &arg);
		bool MousePressed(const CInputMouseEvent &arg, MouseButtonID id);
		bool MouseReleased(const CInputMouseEvent &arg, MouseButtonID id);

		bool KeyPressed(const CInputKeyEvent &arg);
		bool KeyReleased(const CInputKeyEvent &arg);

		void cmbBuildingList_ComboAccept(MyGUI::ComboBox* _sender, size_t _index);
		void rdoBuildingSphereObstacle_Click(MyGUI::WidgetPtr _sender);
		void rdoBuildingBoxObstacle_Click(MyGUI::WidgetPtr _sender);
		void btnBuildingPlace_Click(MyGUI::WidgetPtr _sender);
		void btnBuildingClose_Click(MyGUI::WidgetPtr _sender);
		void cmbBuildingType_ComboAccept(MyGUI::ComboBox* _sender, size_t _index);
		void btnBuildingCancel_Click(MyGUI::WidgetPtr _sender);
		void btnBuildingSave_Click(MyGUI::WidgetPtr _sender);
		void cmbBuildingTeam_ComboAccept(MyGUI::ComboBox* _sender, size_t _index);
		
		void Close();
		void Save();
		void PopulateMeshList();
		void PopulateTypeList();
		void PlaceMesh(f32 Width, f32 Height);
		void ResetControls();
		
		bool	   isPlaceMesh;			// Is the place mesh btn pressed and shift held down
		CBuilding* m_Building;			// Currently selected object
		SELECTED   m_Selected;			// The selected object type

		GUI::CGuiStrategy_MyGui* m_Strategy;
	
		MyGUI::Widget*		frmBuilding;
		MyGUI::ComboBoxPtr	cmbBuildingList;
		MyGUI::ButtonPtr	rdoBuildingSphereObstacle;
		MyGUI::ButtonPtr	rdoBuildingBoxObstacle;
		MyGUI::ButtonPtr	btnBuildingPlace;
		MyGUI::ButtonPtr	btnBuildingClose;
		MyGUI::ComboBoxPtr	cmbBuildingType;
		MyGUI::EditPtr		txtBuildingName;
		MyGUI::ButtonPtr	btnBuildingCancel;
		MyGUI::ButtonPtr	btnBuildingSave;
		MyGUI::EditPtr		txtBuildingPosX;
		MyGUI::EditPtr		txtBuildingPosY;
		MyGUI::EditPtr		txtBuildingPosZ;
		MyGUI::EditPtr		txtBuildingScaleX;
		MyGUI::EditPtr		txtBuildingScaleY;
		MyGUI::EditPtr		txtBuildingScaleZ;
		MyGUI::ComboBoxPtr	cmbBuildingTeam;
	};
	
}
}

#endif // __CBUILDINGMENU_H__