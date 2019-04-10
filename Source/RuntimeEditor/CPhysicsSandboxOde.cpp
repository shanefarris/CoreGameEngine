#ifdef COMPILE_ODE

#ifdef _DEBUG
#pragma comment(lib, "../../Bin/Debug/Plugins/PluginPhysics_Ode.lib")
#else
#pragma comment(lib, "../../Bin/Release/Plugins/PluginPhysics_Ode.lib")
#endif

#include "CPhysicsSandboxOde.h"
#include "CEditorHelper.h"
#include "CGameManager.h"
#include "CMenuDirector.h"
#include "CPhysicsManager.h"
#include "IPhysicsStrategy.h"
#include "CWorldProfile.h"
#include "CGameObject.h"
#include "CPhysicsProfile.h"

// MyGUI specific plugin
#include "../PluginMyGui/CGuiStrategy_MyGui.h"

// Ode specific
#include "../PluginPhysics_Ode/CPhysicsStrategy_Ode.h"

// Ogre
#include "OgreSceneNode.h"
#include "OgreStringConverter.h"

using namespace Core;
using namespace Core::Editor;

CPhysicsSandboxOde::CPhysicsSandboxOde(GUI::CGuiStrategy_MyGui* Strategy) : m_Strategy(Strategy), m_GameObject(nullptr)
{
	Strategy->AssignWidget(frmOdeTest, "frmOdeTest");
	Strategy->AssignWidget(txtOdeWLinearDamping, "txtOdeWLinearDamping");
	Strategy->AssignWidget(txtOdeWAngularDamping, "txtOdeWAngularDamping");
	Strategy->AssignWidget(txtOdeWLinearDampingThreshold, "txtOdeWLinearDampingThreshold");
	Strategy->AssignWidget(txtOdeWAngularDampingThreshold, "txtOdeWAngularDampingThreshold");
	Strategy->AssignWidget(txtOdeWMaxAngularSpeed, "txtOdeWMaxAngularSpeed");
	Strategy->AssignWidget(txtOdeWContactMaxCorrectingVel, "txtOdeWContactMaxCorrectingVel");
	Strategy->AssignWidget(txtOdeWContactSurfaceLayer, "txtOdeWContactSurfaceLayer");
	Strategy->AssignWidget(chkOdeRDynamic, "chkOdeRDynamic");
	Strategy->AssignWidget(chkOdeRKinematic, "chkOdeRKinematic");
	Strategy->AssignWidget(chkOdeREnabled, "chkOdeREnabled");
	Strategy->AssignWidget(chkOdeRAutoDisableFlag, "chkOdeRAutoDisableFlag");
	Strategy->AssignWidget(txtOdeRAutoDisableLinearThreshold, "txtOdeRAutoDisableLinearThreshold");
	Strategy->AssignWidget(txtOdeRAutoDisableAngularThreshold, "txtOdeRAutoDisableAngularThreshold");
	Strategy->AssignWidget(txtOdeRAutoDisableSteps, "txtOdeRAutoDisableSteps");
	Strategy->AssignWidget(txtOdeRAutoDisableTime, "txtOdeRAutoDisableTime");
	Strategy->AssignWidget(txtOdeRAutoDisableAvgSampleCnt, "txtOdeRAutoDisableAvgSampleCnt");
	Strategy->AssignWidget(txtOdeRPosX, "txtOdeRPosX");
	Strategy->AssignWidget(txtOdeRPosY, "txtOdeRPosY");
	Strategy->AssignWidget(txtOdeRPosZ, "txtOdeRPosZ");
	Strategy->AssignWidget(txtOdeRLinearVelX, "txtOdeRLinearVelX");
	Strategy->AssignWidget(txtOdeRLinearVelY, "txtOdeRLinearVelY");
	Strategy->AssignWidget(txtOdeRLinearVelZ, "txtOdeRLinearVelZ");
	Strategy->AssignWidget(txtOdeRAngularVelX, "txtOdeRAngularVelX");
	Strategy->AssignWidget(txtOdeRAngularVelY, "txtOdeRAngularVelY");
	Strategy->AssignWidget(txtOdeRAngularVelZ, "txtOdeRAngularVelZ");
	Strategy->AssignWidget(txtOdeRAddForceX, "txtOdeRAddForceX");
	Strategy->AssignWidget(txtOdeRAddForceY, "txtOdeRAddForceY");
	Strategy->AssignWidget(txtOdeRAddForceZ, "txtOdeRAddForceZ");
	Strategy->AssignWidget(txtOdeRAddTorqueX, "txtOdeRAddTorqueX");
	Strategy->AssignWidget(txtOdeRAddTorqueY, "txtOdeRAddTorqueY");
	Strategy->AssignWidget(txtOdeRAddTorqueZ, "txtOdeRAddTorqueZ");
	Strategy->AssignWidget(txtOdeRRelForceX, "txtOdeRRelForceX");
	Strategy->AssignWidget(txtOdeRRelForceY, "txtOdeRRelForceY");
	Strategy->AssignWidget(txtOdeRRelForceZ, "txtOdeRRelForceZ");
	Strategy->AssignWidget(txtOdeRForceX, "txtOdeRForceX");
	Strategy->AssignWidget(txtOdeRForceY, "txtOdeRForceY");
	Strategy->AssignWidget(txtOdeRForceZ, "txtOdeRForceZ");
	Strategy->AssignWidget(txtOdeRTorqueX, "txtOdeRTorqueX");
	Strategy->AssignWidget(txtOdeRTorqueY, "txtOdeRTorqueY");
	Strategy->AssignWidget(txtOdeRTorqueZ, "txtOdeRTorqueZ");
	Strategy->AssignWidget(txtOdeRAddRelTorqueX, "txtOdeRAddRelTorqueX");
	Strategy->AssignWidget(txtOdeRAddRelTorqueY, "txtOdeRAddRelTorqueY");
	Strategy->AssignWidget(txtOdeRAddRelTorqueZ, "txtOdeRAddRelTorqueZ");
	Strategy->AssignWidget(txtOdeRAddForcePosX, "txtOdeRAddForcePosX");
	Strategy->AssignWidget(txtOdeRAddForcePosY, "txtOdeRAddForcePosY");
	Strategy->AssignWidget(txtOdeRAddForcePosZ, "txtOdeRAddForcePosZ");
	Strategy->AssignWidget(txtOdeRAddForceRelPosX, "txtOdeRAddForceRelPosX");
	Strategy->AssignWidget(txtOdeRAddForceRelPosY, "txtOdeRAddForceRelPosY");
	Strategy->AssignWidget(txtOdeRAddForceRelPosZ, "txtOdeRAddForceRelPosZ");
	Strategy->AssignWidget(txtOdeRAddRelForcePosX, "txtOdeRAddRelForcePosX");
	Strategy->AssignWidget(txtOdeRAddRelForcePosY, "txtOdeRAddRelForcePosY");
	Strategy->AssignWidget(txtOdeRAddRelForcePosZ, "txtOdeRAddRelForcePosZ");
	Strategy->AssignWidget(txtOdeRAddRelForceRelX, "txtOdeRAddRelForceRelX");
	Strategy->AssignWidget(txtOdeRAddRelForceRelY, "txtOdeRAddRelForceRelY");
	Strategy->AssignWidget(txtOdeRAddRelForceRelZ, "txtOdeRAddRelForceRelZ");
	Strategy->AssignWidget(txtOdeRUtilityPosX, "txtOdeRUtilityPosX");
	Strategy->AssignWidget(txtOdeRUtilityPosY, "txtOdeRUtilityPosY");
	Strategy->AssignWidget(txtOdeRUtilityPosZ, "txtOdeRUtilityPosZ");
	Strategy->AssignWidget(txtOdeRLinearDamping, "txtOdeRLinearDamping");
	Strategy->AssignWidget(txtOdeRAngularDamping, "txtOdeRAngularDamping");
	Strategy->AssignWidget(txtOdeRLinearDampingThreshold, "txtOdeRLinearDampingThreshold");
	Strategy->AssignWidget(txtOdeRAngularDampingThreshold, "txtOdeRAngularDampingThreshold");
	Strategy->AssignWidget(txtOdeRMaxAngularSpeed, "txtOdeRMaxAngularSpeed");
	Strategy->AssignWidget(btnOdeGClearOffset, "btnOdeGClearOffset");
	Strategy->AssignWidget(chkOdeGEnabled, "chkOdeGEnabled");
	Strategy->AssignWidget(btnOdeSave, "btnOdeSave");
	Strategy->AssignWidget(btnOdeClose, "btnOdeClose");

	chkOdeRDynamic->eventMouseButtonClick = MyGUI::newDelegate(this, &CPhysicsSandboxOde::chkOdeRDynamic_Click);
	chkOdeRKinematic->eventMouseButtonClick = MyGUI::newDelegate(this, &CPhysicsSandboxOde::chkOdeRKinematic_Click);
	chkOdeREnabled->eventMouseButtonClick = MyGUI::newDelegate(this, &CPhysicsSandboxOde::chkOdeREnabled_Click);
	chkOdeRAutoDisableFlag->eventMouseButtonClick = MyGUI::newDelegate(this, &CPhysicsSandboxOde::chkOdeRAutoDisableFlag_Click);
	btnOdeGClearOffset->eventMouseButtonClick = MyGUI::newDelegate(this, &CPhysicsSandboxOde::btnOdeGClearOffset_Click);
	chkOdeGEnabled->eventMouseButtonClick = MyGUI::newDelegate(this, &CPhysicsSandboxOde::chkOdeGEnabled_Click);
	btnOdeSave->eventMouseButtonClick = MyGUI::newDelegate(this, &CPhysicsSandboxOde::btnOdeSave_Click);
	btnOdeClose->eventMouseButtonClick = MyGUI::newDelegate(this, &CPhysicsSandboxOde::btnOdeClose_Click);

	PopulateControls();

	// Not used yet
	txtOdeWLinearDampingThreshold->setEnabled(false);
	txtOdeWAngularDampingThreshold->setEnabled(false);
	btnOdeGClearOffset->setEnabled(false);
	txtOdeRForceX->setEnabled(false);
	txtOdeRForceY->setEnabled(false);
	txtOdeRForceZ->setEnabled(false);
	txtOdeRTorqueX->setEnabled(false);
	txtOdeRTorqueY->setEnabled(false);
	txtOdeRTorqueZ->setEnabled(false);
	txtOdeRAddForcePosX->setEnabled(false);
	txtOdeRAddForcePosY->setEnabled(false);
	txtOdeRAddForcePosZ->setEnabled(false);
	txtOdeRAddForceRelPosX->setEnabled(false);
	txtOdeRAddForceRelPosY->setEnabled(false);
	txtOdeRAddForceRelPosZ->setEnabled(false);
	txtOdeRAddRelForcePosX->setEnabled(false);
	txtOdeRAddRelForcePosY->setEnabled(false);
	txtOdeRAddRelForcePosZ->setEnabled(false);
	txtOdeRAddRelForceRelX->setEnabled(false);
	txtOdeRAddRelForceRelY->setEnabled(false);
	txtOdeRAddRelForceRelZ->setEnabled(false);
	txtOdeRUtilityPosX->setEnabled(false);
	txtOdeRUtilityPosY->setEnabled(false);
	txtOdeRUtilityPosZ->setEnabled(false);
}

CPhysicsSandboxOde::~CPhysicsSandboxOde()
{
}

void CPhysicsSandboxOde::SetVisible(bool Visible)
{
	frmOdeTest->setVisible(Visible);
	m_GameObject = nullptr;
	PopulateControls();
}

void CPhysicsSandboxOde::SetVisible(bool Visible, const SELECTED& Selected, CGameObject* GameObject)
{
	if(!Visible)
	{
		frmOdeTest->setVisible(false);
		m_GameObject = nullptr;
	}
	else
	{
		frmOdeTest->setVisible(true);
		m_Selected = Selected;
		m_GameObject = GameObject;
		PopulateControls();
	}
}

void CPhysicsSandboxOde::Close()
{
	frmOdeTest->setVisible(false);
	m_GameObject = nullptr;
}

void CPhysicsSandboxOde::Save()
{
	// Get physics Ode strategy
	using namespace Core::Physics;
	CPhysicsStrategy_Ode* ode = nullptr;
	auto strategy = CPhysicsManager::Instance()->GetStrategy();

	if(strategy)
	{
		if(String(strategy->GetStrategyType()) == "ODE")
		{
			ode = (CPhysicsStrategy_Ode*)strategy;
		}
	}

	if(!ode)
	{
		m_Strategy->ShowMessageBox("Error getting physics strategy.", "Error");
		return;
	}

	// Get the physics profile of the game object
	CPhysicsProfile* profile = nullptr;
	if(m_GameObject)
	{
		profile = m_GameObject->PhysicsProfile;
	}

	// World
	auto worldProfile = strategy->GetWorldProfile();

	// Damping (linear and angular)
	worldProfile->LinearDamping = StringConverter::parseReal(txtOdeWLinearDamping->getCaption());
	worldProfile->AngularDamping = StringConverter::parseReal(txtOdeWAngularDamping->getCaption());

	// Max Angular Speed
	worldProfile->MaxAngularSpeed = StringConverter::parseReal(txtOdeWMaxAngularSpeed->getCaption());

	// Contact Correction Velocity
	worldProfile->ContactCorrectionVelocity = StringConverter::parseReal(txtOdeWContactMaxCorrectingVel->getCaption());

	// Contact Surface Layer
	worldProfile->ContactSurfaceLayer = StringConverter::parseReal(txtOdeWContactSurfaceLayer->getCaption());

	// Update world
	strategy->UpdateWorld(worldProfile);

	// Rigid Body
	if(profile)
	{
		// Auto Disable Linear Threshold (dBodyGetAutoDisableAngularThreshold)
		auto value = StringConverter::parseReal(txtOdeRAutoDisableLinearThreshold->getCaption());
		profile->SetAutoDisableLinearThreshold(value);

		// Auto Disable Angular Threshold  (dBodyGetAutoDisableAngularThreshold)
		value = StringConverter::parseReal(txtOdeRAutoDisableAngularThreshold->getCaption());
		profile->SetAutoDisableAngularThreshold(value);

		// Auto Disable Steps (dBodySetAutoDisableSteps)
		auto caption = StringConverter::parseUnsignedInt(txtOdeRAutoDisableSteps->getCaption());
		profile->SetAutoDisableSteps(caption);

		// Auto Disable Time
		value = StringConverter::parseReal(txtOdeRAutoDisableTime->getCaption());
		profile->SetAutoDisableTime(value);

		// Auto Disable Average Samples Count (not enabled for now)
		txtOdeRAutoDisableAvgSampleCnt->setEnabled(false);

		// Position TODO: finish (move shape, or node?)
		auto x = StringConverter::parseReal(txtOdeRPosX->getCaption());
		auto y = StringConverter::parseReal(txtOdeRPosY->getCaption());
		auto z = StringConverter::parseReal(txtOdeRPosZ->getCaption());

		// Linear Vel (dBodyGetLinearVel)
		x = StringConverter::parseReal(txtOdeRLinearVelX->getCaption());
		y = StringConverter::parseReal(txtOdeRLinearVelY->getCaption());
		z = StringConverter::parseReal(txtOdeRLinearVelZ->getCaption());
		profile->SetLinearVelocity(Vector3(x, y, z));

		// Force at position (dBodyGetLinearVel)
		x = StringConverter::parseReal(txtOdeRAddForceX->getCaption());
		y = StringConverter::parseReal(txtOdeRAddForceY->getCaption());
		z = StringConverter::parseReal(txtOdeRAddForceZ->getCaption());
		profile->SetForce(Vector3(x, y, z));

		// Angular Vel (dBodyGetAngularVel)
		x = StringConverter::parseReal(txtOdeRAngularVelX->getCaption());
		y = StringConverter::parseReal(txtOdeRAngularVelY->getCaption());
		z = StringConverter::parseReal(txtOdeRAngularVelZ->getCaption());
		profile->SetAngularVelocity(Vector3(x, y, z));

		// Torque
		x = StringConverter::parseReal(txtOdeRAddTorqueX->getCaption());
		y = StringConverter::parseReal(txtOdeRAddTorqueY->getCaption());
		z = StringConverter::parseReal(txtOdeRAddTorqueZ->getCaption());
		profile->SetTorque(Vector3(x, y, z));

		// Relative force
		x = StringConverter::parseReal(txtOdeRRelForceX->getCaption());
		y = StringConverter::parseReal(txtOdeRRelForceY->getCaption());
		z = StringConverter::parseReal(txtOdeRRelForceZ->getCaption());
		profile->SetRelativeForce(Vector3(x, y, z));

		// Relative torque
		x = StringConverter::parseReal(txtOdeRAddRelTorqueX->getCaption());
		y = StringConverter::parseReal(txtOdeRAddRelTorqueY->getCaption());
		z = StringConverter::parseReal(txtOdeRAddRelTorqueZ->getCaption());
		profile->SetRelativeTorque(Vector3(x, y, z));

		// Linear Damping (dBodySetLinearDamping)
		value = StringConverter::parseReal(txtOdeRLinearDamping->getCaption());
		profile->SetLinearDamping(value);

		// Angular Damping (dBodySetAngularDamping)
		value = StringConverter::parseReal(txtOdeRAngularDamping->getCaption());
		profile->SetAngularDamping(value);

		// Linear Damping Threshold
		value = StringConverter::parseReal(txtOdeRLinearDampingThreshold->getCaption());
		profile->SetLinearDampingThreshold(value);

		// Angular Damping Threshold
		value = StringConverter::parseReal(txtOdeRAngularDampingThreshold->getCaption());
		profile->SetAngularDampingThreshold(value);

		// Max Angular Speed (dBodyGetMaxAngularSpeed)
		value = StringConverter::parseReal(txtOdeRMaxAngularSpeed->getCaption());
		profile->SetMaxAngularSpeed(value);

		// Update the physics body
		strategy->UpdatePhysicsBody(m_GameObject);
	}
}

void CPhysicsSandboxOde::PopulateControls()
{
	// Get physics Ode strategy
	using namespace Core::Physics;
	CPhysicsStrategy_Ode* ode = nullptr;
	auto strategy = CPhysicsManager::Instance()->GetStrategy();
	if(strncmp(strategy->GetStrategyType(), "ODE", 3))
	{
		m_Strategy->ShowMessageBox("Physics strategy is not ODE.", "Not ODE");
		return;
	}
	else
	{
		ode = dynamic_cast<CPhysicsStrategy_Ode*>(strategy);
	}

	// Get the physics profile of the game object
	CPhysicsProfile* profile = nullptr;
	if(m_GameObject)
	{
		profile = m_GameObject->PhysicsProfile;
	}

	// World
	auto worldProfile = strategy->GetWorldProfile();

	// Linear damping
	txtOdeWLinearDamping->setCaption(StringConverter::toString(worldProfile->LinearDamping));

	// Angualar damping
	txtOdeWAngularDamping->setCaption(StringConverter::toString(worldProfile->AngularDamping));

	// Max Angular Speed
	txtOdeWMaxAngularSpeed->setCaption(StringConverter::toString(worldProfile->MaxAngularSpeed));

	// Contact Correction Velocity
	txtOdeWContactMaxCorrectingVel->setCaption(StringConverter::toString(worldProfile->ContactCorrectionVelocity));

	// Contact Surface Layer
	txtOdeWContactSurfaceLayer->setCaption(StringConverter::toString(worldProfile->ContactSurfaceLayer));

	// Rigid Body
	if(profile)
	{
		// Generic vecotor
		Vector3 vec;

		// Auto Disable Linear Threshold (dBodyGetAutoDisableLinearThreshold)
		txtOdeRAutoDisableLinearThreshold->setCaption(StringConverter::toString(profile->GetAutoDisableAngularThreshold()));

		// Auto Disable Angular Threshold  (dBodyGetAutoDisableAngularThreshold)
		txtOdeRAutoDisableAngularThreshold->setCaption(StringConverter::toString(profile->GetAutoDisableLinearThreshold()));

		// Auto Disable Steps (dBodySetAutoDisableSteps)
		txtOdeRAutoDisableSteps->setCaption(StringConverter::toString(profile->GetAutoDisableSteps()));

		// Auto Disable Time
		txtOdeRAutoDisableTime->setCaption(StringConverter::toString(profile->GetAutoDisableTime()));

		// Auto Disable Average Samples Count (not enabled for now)
		txtOdeRAutoDisableAvgSampleCnt->setEnabled(false);

		// Position
		txtOdeRPosX->setCaption(StringConverter::toString(m_GameObject->Node->getPosition().x));
		txtOdeRPosY->setCaption(StringConverter::toString(m_GameObject->Node->getPosition().y));
		txtOdeRPosZ->setCaption(StringConverter::toString(m_GameObject->Node->getPosition().z));

		// Linear Vel (dBodyGetLinearVel)
		txtOdeRLinearVelX->setCaption(StringConverter::toString(profile->GetLinearVelocity().x));
		txtOdeRLinearVelY->setCaption(StringConverter::toString(profile->GetLinearVelocity().y));
		txtOdeRLinearVelZ->setCaption(StringConverter::toString(profile->GetLinearVelocity().z));

		// Angular Vel (dBodyGetAngularVel)
		txtOdeRAngularVelX->setCaption(StringConverter::toString(profile->GetAngularVelocity().x));
		txtOdeRAngularVelY->setCaption(StringConverter::toString(profile->GetAngularVelocity().y));
		txtOdeRAngularVelZ->setCaption(StringConverter::toString(profile->GetAngularVelocity().z));

		// Force
		profile->GetForce(vec);
		txtOdeRAddForceX->setCaption(StringConverter::toString(vec.x));
		txtOdeRAddForceY->setCaption(StringConverter::toString(vec.y));
		txtOdeRAddForceZ->setCaption(StringConverter::toString(vec.z));

		// Torque
		profile->GetTorque(vec);
		txtOdeRAddTorqueX->setCaption(StringConverter::toString(vec.x));
		txtOdeRAddTorqueY->setCaption(StringConverter::toString(vec.y));
		txtOdeRAddTorqueZ->setCaption(StringConverter::toString(vec.z));

		// Relative force
		profile->GetRelativeForce(vec);
		txtOdeRRelForceX->setCaption(StringConverter::toString(vec.x));
		txtOdeRRelForceY->setCaption(StringConverter::toString(vec.y));
		txtOdeRRelForceZ->setCaption(StringConverter::toString(vec.z));

		// Relative torque
		profile->GetRelativeTorque(vec);
		txtOdeRAddRelTorqueX->setCaption(StringConverter::toString(vec.x));
		txtOdeRAddRelTorqueY->setCaption(StringConverter::toString(vec.y));
		txtOdeRAddRelTorqueZ->setCaption(StringConverter::toString(vec.z));

		// Linear Damping (dBodySetLinearDamping)
		txtOdeRLinearDamping->setCaption(StringConverter::toString(profile->GetLinearDamping()));

		// Angular Damping (dBodySetAngularDamping)
		txtOdeRAngularDamping->setCaption(StringConverter::toString(profile->GetAngularDamping()));

		// Linear Damping Threshold
		txtOdeRLinearDampingThreshold->setCaption(StringConverter::toString(profile->GetLinearDampingThreshold()));

		// Angular Damping Threshold
		txtOdeRAngularDampingThreshold->setCaption(StringConverter::toString(profile->GetAngularDampingThreshold()));

		// Max Angular Speed (dBodyGetMaxAngularSpeed)
		txtOdeRMaxAngularSpeed->setCaption(StringConverter::toString(profile->GetMaxAngularSpeed()));
	}

}

void CPhysicsSandboxOde::chkOdeRDynamic_Click(MyGUI::Widget* _sender)
{
	chkOdeRDynamic->setStateSelected(!chkOdeRDynamic->getStateSelected());
}

void CPhysicsSandboxOde::chkOdeRKinematic_Click(MyGUI::Widget* _sender)
{
	chkOdeRKinematic->setStateSelected(!chkOdeRKinematic->getStateSelected());
}

void CPhysicsSandboxOde::chkOdeREnabled_Click(MyGUI::Widget* _sender)
{
	chkOdeREnabled->setStateSelected(!chkOdeREnabled->getStateSelected());
}

void CPhysicsSandboxOde::chkOdeRAutoDisableFlag_Click(MyGUI::Widget* _sender)
{
	chkOdeRAutoDisableFlag->setStateSelected(!chkOdeRAutoDisableFlag->getStateSelected());
}

void CPhysicsSandboxOde::btnOdeGClearOffset_Click(MyGUI::Widget* _sender)
{
}

void CPhysicsSandboxOde::chkOdeGEnabled_Click(MyGUI::Widget* _sender)
{
	chkOdeGEnabled->setStateSelected(!chkOdeGEnabled->getStateSelected());
}

void CPhysicsSandboxOde::btnOdeSave_Click(MyGUI::Widget* _sender)
{
	Save();
}

void CPhysicsSandboxOde::btnOdeClose_Click(MyGUI::Widget* _sender)
{
	SetVisible(false);
}

#endif // COMPILE_ODE

// TODO:
//void dWorldImpulseToForce (dWorldID, dReal stepsize, dReal ix, dReal iy, dReal iz, dVector3 force);
//If you want to apply a linear or angular impulse to a rigid body, instead of a force or a torque, then you can use 
//	this function to convert the desired impulse into a force/torque vector before calling the dBodyAdd... function.

