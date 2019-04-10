#include "CMeshHierarchy.h"
#include "EditorObjects.h"
#include "CGameObject.h"
#include "CInputListener.h"
#include "CInputEvent.h"

// MyGUI specific plugin
#include "../PluginMyGui/CGuiStrategy_MyGui.h"

using namespace Core;
using namespace Core::GUI;
using namespace Core::Editor;

CMeshHierarchy::CMeshHierarchy(GUI::CGuiStrategy_MyGui* Strategy)
{
	Strategy->AssignWidget(MeshHierarchy, "MeshHierarchy");
	Strategy->AssignWidget(lstHierarchy, "lstHierarchy");
	Strategy->AssignWidget(cmdHierarchyRemove, "cmdHierarchyRemove");
	Strategy->AssignWidget(cmdHierarchyMeshList, "cmdHierarchyMeshList");
	Strategy->AssignWidget(txtHierarchyChildName, "txtHierarchyChildName");
	Strategy->AssignWidget(txtHierarchyChildPosX, "txtHierarchyChildPosX");
	Strategy->AssignWidget(txtHierarchyChildPosY, "txtHierarchyChildPosY");
	Strategy->AssignWidget(txtHierarchyChildPosZ, "txtHierarchyChildPosZ");
	Strategy->AssignWidget(btnHierarchyChildAdd, "btnHierarchyChildAdd");
	Strategy->AssignWidget(btnHierarchySave, "btnHierarchySave");
	Strategy->AssignWidget(btnHierarchyClose, "btnHierarchyClose");

	cmdHierarchyRemove->eventMouseButtonClick = MyGUI::newDelegate(this, &CMeshHierarchy::cmdHierarchyRemove_Click);
	cmdHierarchyMeshList->eventComboChangePosition = MyGUI::newDelegate(this, &CMeshHierarchy::cmdHierarchyMeshList_ComboAccept);
	btnHierarchyChildAdd->eventMouseButtonClick = MyGUI::newDelegate(this, &CMeshHierarchy::btnHierarchyChildAdd_Click);
	btnHierarchySave->eventMouseButtonClick = MyGUI::newDelegate(this, &CMeshHierarchy::btnHierarchySave_Click);
	btnHierarchyClose->eventMouseButtonClick = MyGUI::newDelegate(this, &CMeshHierarchy::btnHierarchyClose_Click);
}

CMeshHierarchy::~CMeshHierarchy()
{
}

void CMeshHierarchy::cmdHierarchyRemove_Click(MyGUI::WidgetPtr _sender)
{
}
void CMeshHierarchy::cmdHierarchyMeshList_ComboAccept(MyGUI::ComboBox* _sender, size_t _index)
{
}
void CMeshHierarchy::btnHierarchyChildAdd_Click(MyGUI::WidgetPtr _sender)
{
}
void CMeshHierarchy::btnHierarchySave_Click(MyGUI::WidgetPtr _sender)
{
}
void CMeshHierarchy::btnHierarchyClose_Click(MyGUI::WidgetPtr _sender)
{
}

bool CMeshHierarchy::MouseMoved(const CInputMouseEvent &arg)
{
	return true;
}

bool CMeshHierarchy::MousePressed(const CInputMouseEvent &arg, MouseButtonID id)
{
	return true;
}

bool CMeshHierarchy::MouseReleased(const CInputMouseEvent &arg, MouseButtonID id)
{
	return true;
}

bool CMeshHierarchy::KeyPressed(const CInputKeyEvent &arg)
{
	return true;
}

bool CMeshHierarchy::KeyReleased(const CInputKeyEvent &arg)
{
	return true;
}

void CMeshHierarchy::SetVisible(bool Visible, const SELECTED& Selected, CGameObject* GameObject)
{
}

void CMeshHierarchy::SetVisible(bool Visible)
{
	MeshHierarchy->setVisible(Visible);
}