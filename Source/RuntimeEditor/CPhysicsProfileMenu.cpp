#include "CPhysicsProfileMenu.h"
#include "IO/CFileSystem.h"
#include "CEditorHelper.h"
#include "CGameManager.h"
#include "CMenuDirector.h"
#include "CPhysicsManager.h"
#include "IPhysicsStrategy.h"
#include "CPhysicsProfile.h"

// MyGUI specific plugin
#include "../PluginMyGui/CGuiStrategy_MyGui.h"

#include "OgreStringConverter.h"

using namespace Core;
using namespace Core::Editor;

CPhysicsProfileMenu::CPhysicsProfileMenu(GUI::CGuiStrategy_MyGui* Strategy) : m_Strategy(Strategy)
{
	Strategy->AssignWidget(frmPhysicsProfiles, "frmPhysicsProfiles");
	Strategy->AssignWidget(cmbGOPhyShape, "cmbGOPhyShape");
	Strategy->AssignWidget(txtGOPhyMass, "txtGOPhyMass");
	Strategy->AssignWidget(txtGOPhyDensity, "txtGOPhyDensity");
	Strategy->AssignWidget(txtGOPhyRes, "txtGOPhyRes");
	Strategy->AssignWidget(txtGOPhyFriction, "txtGOPhyFriction");
	Strategy->AssignWidget(txtGOPhyRadius, "txtGOPhyRadius");
	Strategy->AssignWidget(txtGOPhySizeX, "txtGOPhySizeX");
	Strategy->AssignWidget(cmbGOPhyBodyType, "cmbGOPhyBodyType");
	Strategy->AssignWidget(btnGOPhySave, "btnGOPhySave");
	Strategy->AssignWidget(btnGOPhyClose, "btnGOPhyClose");
	Strategy->AssignWidget(txtGOPhySizeY, "txtGOPhySizeY");
	Strategy->AssignWidget(txtGOPhySizeZ, "txtGOPhySizeZ");
	Strategy->AssignWidget(txtGOPhysProfileName, "txtGOPhysProfileName");
	
	cmbGOPhyShape->eventComboChangePosition = MyGUI::newDelegate(this, &CPhysicsProfileMenu::cmbGOPhyShape_ComboAccept);
	cmbGOPhyBodyType->eventComboChangePosition = MyGUI::newDelegate(this, &CPhysicsProfileMenu::cmbGOPhyBodyType_ComboAccept);
	btnGOPhySave->eventMouseButtonClick = MyGUI::newDelegate(this, &CPhysicsProfileMenu::btnGOPhySave_Click);
	btnGOPhyClose->eventMouseButtonClick = MyGUI::newDelegate(this, &CPhysicsProfileMenu::btnGOPhyClose_Click);
}

CPhysicsProfileMenu::~CPhysicsProfileMenu()
{
}

void CPhysicsProfileMenu::SetVisible(bool Visible)
{
	frmPhysicsProfiles->setVisible(Visible);
}

void CPhysicsProfileMenu::cmbGOPhyShape_ComboAccept(MyGUI::ComboBox* _sender, size_t _index)
{
}

void CPhysicsProfileMenu::cmbGOPhyBodyType_ComboAccept(MyGUI::ComboBox* _sender, size_t _index)
{
}

void CPhysicsProfileMenu::btnGOPhySave_Click(MyGUI::Widget* _sender)
{
	using namespace Core::Physics;

	CPhysicsProfile* profile = new CPhysicsProfile();

	String name = txtGOPhysProfileName->getCaption();
	if(name.length() == 0)
	{
		m_Strategy->ShowMessageBox("Profile name required.", "Warning");
		return;
	}
			
	// Body type
	String value = cmbGOPhyBodyType->getOnlyText();
	E_BODY_TYPE bodyType;
	if(value == "Building")
		bodyType = Physics::BUILDING;
	else if(value == "Player")
		bodyType = Physics::PLAYER;
	else if(value == "GameObject")
		bodyType = Physics::GAME_OBJECT;
	else if(value == "Vehicle")
		bodyType = Physics::VEHICLE;
	else if(value == "Volume")
		bodyType = Physics::VOLUME;
	else if(value == "Terrain")
		bodyType = Physics::TERRAIN;
	else
		bodyType = NONE;
	profile->SetBodyType(bodyType);

	// Mass
	value = txtGOPhyMass->getOnlyText();
	profile->SetMass(StringConverter::parseReal(value));

	// Density
	value = txtGOPhyDensity->getOnlyText();
	profile->SetDensity(StringConverter::parseReal(value));

	// Friction
	value = txtGOPhyFriction->getOnlyText();
	profile->SetFriction(StringConverter::parseReal(value));

	// Shape
	value = cmbGOPhyShape->getOnlyText();
	if(value == "Cube")
	{
		profile->SetShape(SHAPE_CUBE);
	}
	else if(value == "Sphere")
	{
		profile->SetShape(SHAPE_SPHERE);
	}
	else if(value == "Capsule")
	{
		profile->SetShape(SHAPE_CAPSULE);
	}

	// Size or Radius
	if(txtGOPhyRadius->getOnlyText().length() > 0)
	{
		value = txtGOPhyRadius->getOnlyText();
		profile->SetRadius(StringConverter::parseReal(value));
	}
	else if(txtGOPhySizeX->getOnlyText().length() > 0 &&
			txtGOPhySizeY->getOnlyText().length() > 0 &&
			txtGOPhySizeZ->getOnlyText().length() > 0)
	{
		Vector3 size;
		size.x = StringConverter::parseReal(txtGOPhySizeX->getOnlyText());
		size.y = StringConverter::parseReal(txtGOPhySizeY->getOnlyText());
		size.z = StringConverter::parseReal(txtGOPhySizeZ->getOnlyText());
		profile->SetSize(size);
	}

	// Add the profile to the physics manager
	CPhysicsManager::Instance()->AddPhysicsProfile(name.c_str(), profile);
	m_Strategy->ShowMessageBox("Physics profile added.", "Done");
}

void CPhysicsProfileMenu::btnGOPhyClose_Click(MyGUI::Widget* _sender)
{
	Close();
}

void CPhysicsProfileMenu::Close()
{
	CMenuDirector::Instance()->SetPhysicsProfileMenuView(false);
}