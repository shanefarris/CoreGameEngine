#include "CVolumeMenu.h"
#include "IO/CFileSystem.h"
#include "CEditorHelper.h"
#include "CGameManager.h"
#include "CMenuDirector.h"
#include "CInputListener.h"
#include "CInputEvent.h"
#include "VisualDebugger/Procedural.h"

// MyGUI specific plugin
#include "../PluginMyGui/CGuiStrategy_MyGui.h"

using namespace Core;
using namespace Core::Editor;

static u32 VolumeCount = 0;

CVolumeMenu::CVolumeMenu(GUI::CGuiStrategy_MyGui* Strategy) : m_Strategy(Strategy)
{
	Strategy->AssignWidget(frmVolume, "frmVolume");
	Strategy->AssignWidget(cmbVolShape, "cmbVolShape");
	Strategy->AssignWidget(txtVolPhyRadius, "txtVolPhyRadius");
	Strategy->AssignWidget(btnVolPhySave, "btnVolPhySave");
	Strategy->AssignWidget(btnVolPhyPlace, "btnVolPhyPlace");
	Strategy->AssignWidget(btnVolPhyClose, "btnVolPhyClose");
	Strategy->AssignWidget(txtVolPhySizeX, "txtVolPhySizeX");
	Strategy->AssignWidget(txtVolPhySizeY, "txtVolPhySizeY");
	Strategy->AssignWidget(txtVolPhySizeZ, "txtVolPhySizeZ");
	Strategy->AssignWidget(txtVolPosX, "txtVolPosX");
	Strategy->AssignWidget(txtVolPosY, "txtVolPosY");
	Strategy->AssignWidget(txtVolPosZ, "txtVolPosZ");
	Strategy->AssignWidget(txtVolName, "txtVolName");

	cmbVolShape->eventComboChangePosition = MyGUI::newDelegate(this, &CVolumeMenu::cmbVolShape_ComboAccept);
	btnVolPhySave->eventMouseButtonClick = MyGUI::newDelegate(this, &CVolumeMenu::btnVolPhySave_Click);
	btnVolPhyClose->eventMouseButtonClick = MyGUI::newDelegate(this, &CVolumeMenu::btnVolPhyClose_Click);
	btnVolPhyPlace->eventMouseButtonClick = MyGUI::newDelegate(this, &CVolumeMenu::btnVolPhyPlace_Click);

	isPlaceVolume = false;
}

CVolumeMenu::~CVolumeMenu()
{
}

void CVolumeMenu::SetVisible(bool Visible)
{
	if(!Visible)
	{
		txtVolPhySizeX->setCaption("");
	}
	frmVolume->setVisible(Visible);
}

void CVolumeMenu::SetVisible(bool Visible, SELECTE_TYPE& Selected)
{
	if(!Visible)
	{
		txtVolPhySizeX->setCaption("");
	}
	frmVolume->setVisible(Visible);
}

void CVolumeMenu::cmbVolShape_ComboAccept(MyGUI::ComboBox* _sender, size_t _index)
{
}

void CVolumeMenu::btnVolPhySave_Click(MyGUI::Widget* _sender)
{
}

void CVolumeMenu::btnVolPhyClose_Click(MyGUI::Widget* _sender)
{
}

void CVolumeMenu::btnVolPhyPlace_Click(MyGUI::Widget* _sender)
{
	isPlaceVolume = true;	
}

bool CVolumeMenu::MouseMoved(const CInputMouseEvent &arg)
{
	return true;
}

bool CVolumeMenu::MousePressed(const CInputMouseEvent &arg, MouseButtonID id)
{
	if(isPlaceVolume)
	{
		using namespace Procedural;

		// Name
		String name = txtVolName->getCaption();
		if(name.length() == 0)
		{
			m_Strategy->ShowMessageBox("Name is needed", "Error");
			isPlaceVolume = false;
			return true;
		}

		// Position
		Vector3 pos = CEditorHelper::FindY(f32(arg.width), f32(arg.height));

		// Shape type
		String shape = cmbVolShape->getCaption();
		if(shape == "Cube")
		{
		}
		else if(shape == "Sphere")
		{
			String radiusStr = txtVolPhyRadius->getCaption();
			f32 radius = StringConverter::parseReal(radiusStr);
			if(radius > 0)
			{
				String meshName = "icoSphereMesh_volume_" + name + StringConverter::toString(VolumeCount++);
				Procedural::Root::getInstance()->sceneManager = CGameManager::Instance()->GetSceneManager();
				IcoSphereGenerator().setRadius(radius).setNumIterations(1).setUTile(5.).setVTile(5.).realizeMesh(meshName, pos);
			}
			else
			{
				m_Strategy->ShowMessageBox("Invalid radius size", "Error");
			}
		}
		else if(shape == "Capsule")
		{
		}
		else
		{
			m_Strategy->ShowMessageBox("Select shape", "Error");
		}
		isPlaceVolume = false;
	}
	return true;
}

bool CVolumeMenu::MouseReleased(const CInputMouseEvent &arg, MouseButtonID id)
{
	return true;
}

bool CVolumeMenu::KeyPressed(const CInputKeyEvent &arg)
{
	return true;
}

bool CVolumeMenu::KeyReleased(const CInputKeyEvent &arg)
{
	return true;
}