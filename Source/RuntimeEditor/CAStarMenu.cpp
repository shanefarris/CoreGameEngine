#include "CAStarMenu.h"
#include "CEditorHelper.h"
#include "CUtility.h"
#include "CGameManager.h"

// MyGUI specific plugin
#include "../PluginMyGui/CGuiStrategy_MyGui.h"

// A* paths
#include "AI/CAStarGrid.h"
#include "AI/CAStarNode.h"
#include "CPrecisionTimer.h"

#include "OgreStringConverter.h"
#include "OgreSceneManager.h"
#include "OgreManualObject.h"

using namespace Core;
using namespace Core::AI;
using namespace Core::Editor;

CAStarMenu::CAStarMenu(GUI::CGuiStrategy_MyGui* Strategy) : m_AStarGrid(nullptr)
{
	Strategy->AssignWidget(frmAStar, "frmAStar");
	Strategy->AssignWidget(cmbASPSize, "cmbASPSize");
	Strategy->AssignWidget(btnASPSave, "btnASPSave");
	Strategy->AssignWidget(btnASPDelete, "btnASPDelete");
	Strategy->AssignWidget(btnASPClose, "btnASPClose");
	Strategy->AssignWidget(btnASPTest, "btnASPTest");
	Strategy->AssignWidget(btnASPRemove, "btnASPRemove");
	Strategy->AssignWidget(txtASPStartX, "txtASPStartX");
	Strategy->AssignWidget(txtASPStartZ, "txtASPStartZ");
	Strategy->AssignWidget(lstASPNodes, "lstASPNodes");
	Strategy->AssignWidget(chkASPShowGrid, "chkASPShowGrid");

	cmbASPSize->eventComboChangePosition = MyGUI::newDelegate(this, &CAStarMenu::cmbASPSize_ComboAccept);
	btnASPSave->eventMouseButtonClick = MyGUI::newDelegate(this, &CAStarMenu::btnASPSave_Click);
	btnASPDelete->eventMouseButtonClick = MyGUI::newDelegate(this, &CAStarMenu::btnASPDelete_Click);
	btnASPClose->eventMouseButtonClick = MyGUI::newDelegate(this, &CAStarMenu::btnASPClose_Click);
	btnASPTest->eventMouseButtonClick = MyGUI::newDelegate(this, &CAStarMenu::btnASPTest_Click);
	btnASPRemove->eventMouseButtonClick = MyGUI::newDelegate(this, &CAStarMenu::btnASPRemove_Click);
	chkASPShowGrid->eventMouseButtonClick = MyGUI::newDelegate(this, &CAStarMenu::chkASPShowGrid_Click);

	isCreated = false;
	isGraphics = false;
	m_Lines = nullptr;
	m_AStarGrid = CAStarGrid::Instance();

	cmbASPSize->removeAllItems();
	cmbASPSize->addItem("100x100");
	cmbASPSize->addItem("200x200");
	cmbASPSize->addItem("500x500");
	cmbASPSize->addItem("Full");

	chkASPShowGrid->setStateSelected(true);

	// Check if a grid is already created
	if(m_AStarGrid->GetNodes()->size() > 0)
	{
		CreateGrid();
	}
}

CAStarMenu::~CAStarMenu()
{
}

void CAStarMenu::SetVisible(bool Visible)
{
	frmAStar->setVisible(Visible);

	if(Visible)
	{
		PopulateNodeList();
	}
}

void CAStarMenu::SetVisible(bool Visible, const SELECTED& Selected)
{
	SetVisible(Visible);
}

void CAStarMenu::Close()
{
	frmAStar->setVisible(false);
}

void CAStarMenu::Save()
{
	CreateGrid();

	// Show the grid
	isGraphics = chkASPShowGrid->getStateSelected();
	if(isGraphics)
	{
		CreateGraphic();
	}
}

void CAStarMenu::PopulateNodeList()
{
	// Popluate inventory list
	lstASPNodes->removeAllItems();
	auto nodes = m_AStarGrid->GetNodes();
	for(auto it = nodes->cbegin(); it != nodes->cend(); it++)
	{
		String name = StringConverter::toString((*it)->GetNodeId()) + ": ";
		name += StringConverter::toString((*it)->GetPosition());
		lstASPNodes->addItem(name);
	}
}

void CAStarMenu::cmbASPSize_ComboAccept(MyGUI::ComboBox* _sender, size_t _index)
{
}

void CAStarMenu::btnASPSave_Click(MyGUI::WidgetPtr _sender)
{
	Save();
	Close();
}

void CAStarMenu::btnASPDelete_Click(MyGUI::WidgetPtr _sender)
{
}

void CAStarMenu::btnASPRemove_Click(MyGUI::WidgetPtr _sender)
{
	// Format (NodeId: Position)
	auto index = lstASPNodes->getIndexSelected();
	String name = lstASPNodes->getItemNameAt(index);
	Vector<String> subs;
	CUtility::StringSplit(name, ':', subs);
	if(subs.size() > 0)
	{
		int nodeId = StringConverter::parseInt(subs[0], -1);
		if(nodeId != -1)
		{
			// Remove the node from the grid
			m_AStarGrid->RemoveNode(nodeId);

			// Remove the grid mesh
			if(isGraphics)
			{
				CGameManager::Instance()->GetSceneManager()->destroyStaticGeometry("AStarGrid");

				if(m_Lines)
					CGameManager::Instance()->GetSceneManager()->destroyManualObject(m_Lines);

				CreateGraphic();
			}
		}
		lstASPNodes->removeItemAt(index);
	}
}

void CAStarMenu::btnASPClose_Click(MyGUI::WidgetPtr _sender)
{
	Close();
}

void CAStarMenu::btnASPTest_Click(MyGUI::WidgetPtr _sender)
{
	CreateGrid();
	CreateGraphic();
}

void CAStarMenu::chkASPShowGrid_Click(MyGUI::WidgetPtr _sender)
{
	auto checked = !chkASPShowGrid->getStateSelected();
	chkASPShowGrid->setStateSelected(checked);

	if(isCreated)
	{
		auto manualObject = CGameManager::Instance()->GetSceneManager()->getManualObject("AStarGrid");
		if(manualObject)
			manualObject->setVisible(checked);

		if(m_Lines)
			m_Lines->setVisible(checked);
	}
}

void CAStarMenu::CreateGrid()
{
	// Clear the grid
	m_AStarGrid->RemoveAllNodes();

	// Remove the grid mesh
	if(isGraphics)
	{
		CGameManager::Instance()->GetSceneManager()->destroyStaticGeometry("AStarGrid");

		if(m_Lines)
			CGameManager::Instance()->GetSceneManager()->destroyManualObject(m_Lines);
	}

	int startX = StringConverter::parseInt(txtASPStartX->getCaption());
	int startY = StringConverter::parseInt(txtASPStartZ->getCaption());

	int size = 0;
	auto value = cmbASPSize->getTextSelection();
	if(value == "100x100")
	{
		size = 100;
	}
	else if(value == "200x200")
	{
		size = 200;
	}
	else if(value == "500x500")
	{
		size = 500;
	}
	else
	{
		// TODO: find the size of support terrain
		size = 10;
	}
	size += startX;

	f32 spacing = 30.0f;

	// Node creation
	Vector<Vector3> positions;
	for(int x = startX; x < size; x++)
	{
		for(int y = startY; y < size; y++)
		{
			// Create the node
			Vector3 pos(x * spacing, 1, y * spacing);
			positions.push_back(pos);
		}
	}
	m_AStarGrid->AddNodes(positions);

	// Assigning neighbors
	for(auto it = m_AStarGrid->GetNodes()->begin(); it != m_AStarGrid->GetNodes()->end(); it++)
	{
		// Get south
		auto connection = m_AStarGrid->GetNode((*it)->GetPosition() + Vector3::UNIT_Z * spacing);
		if(connection)
			(*it)->AddConnection(connection);

		// Get north
		connection = m_AStarGrid->GetNode((*it)->GetPosition() + Vector3::UNIT_Z * -spacing);
		if(connection)
			(*it)->AddConnection(connection);

		// Get east
		connection = m_AStarGrid->GetNode((*it)->GetPosition() + Vector3::UNIT_X * spacing);
		if(connection)
			(*it)->AddConnection(connection);

		// Get west
		connection = m_AStarGrid->GetNode((*it)->GetPosition() + Vector3::UNIT_X * -spacing);
		if(connection)
			(*it)->AddConnection(connection);

		// Get south east
		connection = m_AStarGrid->GetNode((*it)->GetPosition() + Vector3(spacing, 0, spacing));
		if(connection)
			(*it)->AddConnection(connection);

		// Get south west
		connection = m_AStarGrid->GetNode((*it)->GetPosition() + Vector3(-spacing, 0, spacing));
		if(connection)
			(*it)->AddConnection(connection);

		// Get north east
		connection = m_AStarGrid->GetNode((*it)->GetPosition() + Vector3(spacing, 0, -spacing));
		if(connection)
			(*it)->AddConnection(connection);

		// Get north west
		connection = m_AStarGrid->GetNode((*it)->GetPosition() + Vector3(-spacing, 0, -spacing));
		if(connection)
			(*it)->AddConnection(connection);
	}

	isCreated = true;
}

void CAStarMenu::CreateGraphic()
{
	if(!isCreated)
		return;

	// Nodes
	auto nodes = m_AStarGrid->GetNodes();
	Vector<Vector3> positions;
	for(auto it = nodes->cbegin(); it != nodes->cend(); it++)
	{
		positions.push_back((*it)->GetPosition());
	}
	CEditorHelper::AddAStarNodeShapes(positions);

	// Connections
	Vector<Vector3> from;
	Vector<Vector3> to;
	for(auto it = m_AStarGrid->GetNodes()->begin(); it != m_AStarGrid->GetNodes()->end(); it++)
	{
		auto connection = (*it)->GetConnections();
		for(auto it2 = connection->cbegin(); it2 != connection->cend(); it2++)
		{
			from.push_back(Vector3((*it2)->GetPosition()));
			to.push_back((*it)->GetPosition());
		}
	}
	m_Lines = CEditorHelper::Draw3D_Lines(from, to, ColourValue::White, String(""));
}

