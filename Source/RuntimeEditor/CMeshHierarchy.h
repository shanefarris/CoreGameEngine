#ifndef __CMESH_HIERARCHY_MENU_H__
#define __CMESH_HIERARCHY_MENU_H__

#include "Defines.h"
#include "CInputListener.h"
#include "MyGui/MyGUI.h"

namespace Core
{
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
	struct SELECTED;

	class CMeshHierarchy : public CInputKeyListener, public CInputMouseListener
	{
	public:
		CMeshHierarchy(GUI::CGuiStrategy_MyGui* Strategy);
		~CMeshHierarchy();

		void SetVisible(bool Visible);
		void SetVisible(bool Visible, const SELECTED& Selected, CGameObject* GameObject);
		inline MyGUI::Widget* GetForm() { return MeshHierarchy; }

	private:
		bool MouseMoved(const CInputMouseEvent &arg);
		bool MousePressed(const CInputMouseEvent &arg, MouseButtonID id);
		bool MouseReleased(const CInputMouseEvent &arg, MouseButtonID id);

		bool KeyPressed(const CInputKeyEvent &arg);
		bool KeyReleased(const CInputKeyEvent &arg);

		void cmdHierarchyRemove_Click(MyGUI::WidgetPtr _sender);
		void cmdHierarchyMeshList_ComboAccept(MyGUI::ComboBox* _sender, size_t _index);
		void btnHierarchyChildAdd_Click(MyGUI::WidgetPtr _sender);
		void btnHierarchySave_Click(MyGUI::WidgetPtr _sender);
		void btnHierarchyClose_Click(MyGUI::WidgetPtr _sender);
		
		MyGUI::Widget*		MeshHierarchy;
		MyGUI::ItemBoxPtr	lstHierarchy;
		MyGUI::ButtonPtr	cmdHierarchyRemove;
		MyGUI::ComboBoxPtr	cmdHierarchyMeshList;
		MyGUI::EditPtr		txtHierarchyChildName;
		MyGUI::EditPtr		txtHierarchyChildPosX;
		MyGUI::EditPtr		txtHierarchyChildPosY;
		MyGUI::EditPtr		txtHierarchyChildPosZ;
		MyGUI::ButtonPtr	btnHierarchyChildAdd;
		MyGUI::ButtonPtr	btnHierarchySave;
		MyGUI::ButtonPtr	btnHierarchyClose;

	};
}
}
#endif // __CMESH_HIERARCHY_MENU_H__