#include "CLightMenu.h"
#include "CGameObject.h"
#include "CGameManager.h"

// MyGUI specific plugin
#include "../PluginMyGui/CGuiStrategy_MyGui.h"

#include "CMenuDirector.h"
#include "EditorObjects.h"
#include "CEditorHelper.h"

#include "OgreLight.h"
#include "OgreSceneManager.h"
#include "OgreStringConverter.h"

using namespace Core;
using namespace Core::Editor;

CLightMenu::CLightMenu(GUI::CGuiStrategy_MyGui* Strategy) : m_GameObject(nullptr), m_Strategy(Strategy)
{
	Strategy->AssignWidget(frmLight, "frmLight");
	Strategy->AssignWidget(cmbLightType, "cmbLightType");
	Strategy->AssignWidget(chkLightVisible, "chkLightVisible");
	Strategy->AssignWidget(txtLightName, "txtLightName");
	Strategy->AssignWidget(txtLightDiffuseX, "txtLightDiffuseX");
	Strategy->AssignWidget(txtLightDiffuseY, "txtLightDiffuseY");
	Strategy->AssignWidget(txtLightDiffuseZ, "txtLightDiffuseZ");
	Strategy->AssignWidget(txtLightDiffuseA, "txtLightDiffuseA");
	Strategy->AssignWidget(txtLightSpecularX, "txtLightSpecularX");
	Strategy->AssignWidget(txtLightSpecularY, "txtLightSpecularY");
	Strategy->AssignWidget(txtLightSpecularZ, "txtLightSpecularZ");
	Strategy->AssignWidget(txtLightSpecularA, "txtLightSpecularA");
	Strategy->AssignWidget(txtLightAttRange, "txtLightAttRange");
	Strategy->AssignWidget(txtLightAttConstant, "txtLightAttConstant");
	Strategy->AssignWidget(txtLightAttLinear, "txtLightAttLinear");
	Strategy->AssignWidget(txtLightAttQuadratic, "txtLightAttQuadratic");
	Strategy->AssignWidget(txtLightPosX, "txtLightPosX");
	Strategy->AssignWidget(txtLightPosY, "txtLightPosY");
	Strategy->AssignWidget(txtLightPosZ, "txtLightPosZ");
	Strategy->AssignWidget(txtLightDirX, "txtLightDirX");
	Strategy->AssignWidget(txtLightDirY, "txtLightDirY");
	Strategy->AssignWidget(txtLightDirZ, "txtLightDirZ");
	Strategy->AssignWidget(txtLightPower, "txtLightPower");
	Strategy->AssignWidget(txtLightShadNearClipDis, "txtLightShadNearClipDis");
	Strategy->AssignWidget(txtShadFarClipDis, "txtShadFarClipDis");
	Strategy->AssignWidget(txtLightShadFarDis, "txtLightShadFarDis");
	Strategy->AssignWidget(txtLightInner, "txtLightInner");
	Strategy->AssignWidget(txtLightOutter, "txtLightOutter");
	Strategy->AssignWidget(txtLightFalloff, "txtLightFalloff");
	Strategy->AssignWidget(btnLightCancel, "btnLightCancel");
	Strategy->AssignWidget(btnLightSave, "btnLightSave");

	btnLightCancel->eventMouseButtonClick = MyGUI::newDelegate(this, &CLightMenu::btnLightCancel_Click);
	btnLightSave->eventMouseButtonClick = MyGUI::newDelegate(this, &CLightMenu::btnLightSave_Click);
}

CLightMenu::~CLightMenu()
{
}

void CLightMenu::btnLightCancel_Click(MyGUI::WidgetPtr _sender)
{
	SetVisible(false);
}

void CLightMenu::btnLightSave_Click(MyGUI::WidgetPtr _sender)
{
	if(Save())
		SetVisible(false);
}

void CLightMenu::SetVisible(bool Visible)
{
	frmLight->setVisible(Visible);
	if(!Visible)
		return;

	chkLightVisible->setStateSelected(true);
	txtLightName->setCaption("");
	txtLightName->setEnabled(true);

	txtLightDiffuseX->setCaption("1.0");
	txtLightDiffuseY->setCaption("1.0");
	txtLightDiffuseZ->setCaption("1.0");
	txtLightDiffuseA->setCaption("1.0");

	txtLightSpecularX->setCaption("0.0");
	txtLightSpecularY->setCaption("0.0");
	txtLightSpecularZ->setCaption("0.0");
	txtLightSpecularA->setCaption("1.0");

	txtLightAttRange->setCaption("10000.0");
	txtLightAttConstant->setCaption("1.0");
	txtLightAttLinear->setCaption("0.0");
	txtLightAttQuadratic->setCaption("0.0");

	txtLightPosX->setCaption("0.0");
	txtLightPosY->setCaption("50.0");
	txtLightPosZ->setCaption("0.0");

	txtLightDirX->setCaption("0.0");
	txtLightDirY->setCaption("0.0");
	txtLightDirZ->setCaption("0.0");

	txtLightPower->setCaption("1.0");
	txtLightShadNearClipDis->setCaption("-1.0");
	txtShadFarClipDis->setCaption("-1.0");
	txtLightShadFarDis->setCaption("0.0");
	txtLightInner->setCaption("0.5");
	txtLightOutter->setCaption("0.7");
	txtLightFalloff->setCaption("1.0");
}

void CLightMenu::SetVisible(bool Visible, const SELECTED& Selected, CGameObject* GameObject)
{
	frmLight->setVisible(Visible);
	if(!Visible)
		return;

	if(Selected.Type != ST_LIGHT)
		return;

	if(!GameObject)
		return;

	if(!GameObject->AttachedData)
		return;

	m_GameObject = GameObject;
	auto light = static_cast<Light*>(GameObject->AttachedData);
	if(!light)
		return;

	chkLightVisible->setStateSelected(true);
	txtLightName->setCaption(light->getName());
	txtLightName->setEnabled(false);

	txtLightDiffuseX->setCaption(StringConverter::toString(light->getDiffuseColour().r));
	txtLightDiffuseY->setCaption(StringConverter::toString(light->getDiffuseColour().g));
	txtLightDiffuseZ->setCaption(StringConverter::toString(light->getDiffuseColour().b));
	txtLightDiffuseA->setCaption(StringConverter::toString(light->getDiffuseColour().a));

	txtLightSpecularX->setCaption(StringConverter::toString(light->getDiffuseColour().r));
	txtLightSpecularY->setCaption(StringConverter::toString(light->getDiffuseColour().g));
	txtLightSpecularZ->setCaption(StringConverter::toString(light->getDiffuseColour().b));
	txtLightSpecularA->setCaption(StringConverter::toString(light->getDiffuseColour().a));

	txtLightAttRange->setCaption(StringConverter::toString(light->getAttenuationRange()));
	txtLightAttConstant->setCaption(StringConverter::toString(light->getAttenuationConstant()));
	txtLightAttLinear->setCaption(StringConverter::toString(light->getAttenuationLinear()));
	txtLightAttQuadratic->setCaption(StringConverter::toString(light->getAttenuationQuadric()));

	txtLightPosX->setCaption(StringConverter::toString(light->getPosition().x));
	txtLightPosY->setCaption(StringConverter::toString(light->getPosition().y));
	txtLightPosZ->setCaption(StringConverter::toString(light->getPosition().z));

	txtLightDirX->setCaption(StringConverter::toString(light->getPosition().x));
	txtLightDirY->setCaption(StringConverter::toString(light->getPosition().y));
	txtLightDirZ->setCaption(StringConverter::toString(light->getPosition().z));

	txtLightPower->setCaption(StringConverter::toString(light->getPowerScale()));
	txtLightShadNearClipDis->setCaption(StringConverter::toString(light->getShadowNearClipDistance()));
	txtShadFarClipDis->setCaption(StringConverter::toString(light->getShadowFarClipDistance()));
	txtLightShadFarDis->setCaption(StringConverter::toString(light->getShadowFarDistance()));
	txtLightInner->setCaption(StringConverter::toString(light->getSpotlightInnerAngle()));
	txtLightOutter->setCaption(StringConverter::toString(light->getSpotlightOuterAngle()));
	txtLightFalloff->setCaption(StringConverter::toString(light->getSpotlightFalloff()));
}

bool CLightMenu::Save()
{
	// If we have a game object that is not null, then we are saving to an existing light.
	Light* light = nullptr;

	// Validation
	if(txtLightPosX->getCaption().length() == 0 ||
		txtLightPosY->getCaption().length() == 0 ||
		txtLightPosZ->getCaption().length() == 0)
	{
		m_Strategy->ShowMessageBox("Position required dummy", "Why you so stupid?");
		return false;
	}

	if(cmbLightType->getOnlyText().length() == 0)
	{
		m_Strategy->ShowMessageBox("Light type is required stupid.", "Moron");
		return false;
	}

	if(m_GameObject)
	{
		light = CGameManager::Instance()->GetSceneManager()->getLight(txtLightName->getCaption());
	}
	else
	{
		if(CGameManager::Instance()->GetSceneManager()->hasLight(txtLightName->getCaption()))
		{
			m_Strategy->ShowMessageBox("Light with this name already exists.", "Duh");
			return false;
		}

		light = CGameManager::Instance()->GetSceneManager()->createLight(txtLightName->getCaption());
		if(!light)
		{
			m_Strategy->ShowMessageBox("Error creating light.", "Error");
			return false;
		}
	}



	// Type
	Light::LightTypes type;
	if(cmbLightType->getOnlyText() == "Point")
		type = Ogre::Light::LT_POINT;
	else if(cmbLightType->getOnlyText() == "Directional")
		type = Ogre::Light::LT_DIRECTIONAL;
	else
		type = Ogre::Light::LT_SPOTLIGHT;
	light->setType(type);

	// Visible
	light->setVisible(chkLightVisible->getStateSelected());

	// Diffuse
	auto diffuse = ColourValue(StringConverter::parseReal(txtLightDiffuseX->getCaption()),
		StringConverter::parseReal(txtLightDiffuseY->getCaption()),
		StringConverter::parseReal(txtLightDiffuseZ->getCaption()),
		StringConverter::parseReal(txtLightDiffuseA->getCaption()));
	light->setDiffuseColour(diffuse);

	// Specular
	auto specular = ColourValue(StringConverter::parseReal(txtLightSpecularX->getCaption()),
		StringConverter::parseReal(txtLightSpecularY->getCaption()),
		StringConverter::parseReal(txtLightSpecularZ->getCaption()),
		StringConverter::parseReal(txtLightSpecularA->getCaption()));
	light->setSpecularColour(specular);

	// Attenuation
	auto range = StringConverter::parseReal(txtLightAttRange->getCaption());
	auto constant = StringConverter::parseReal(txtLightAttConstant->getCaption());
	auto linear = StringConverter::parseReal(txtLightAttLinear->getCaption());
	auto quadratic = StringConverter::parseReal(txtLightAttQuadratic->getCaption());
	light->setAttenuation(range, constant, linear, quadratic);

	// Position
	Vector3 pos(StringConverter::parseReal(txtLightPosX->getCaption()),
		StringConverter::parseReal(txtLightPosY->getCaption()),
		StringConverter::parseReal(txtLightPosZ->getCaption()));
	light->setPosition(pos);

	// Direction
	Vector3 dir(StringConverter::parseReal(txtLightDirX->getCaption()),
		StringConverter::parseReal(txtLightDirY->getCaption()),
		StringConverter::parseReal(txtLightDirZ->getCaption()));
	light->setDirection(dir);

	// Shadow Far Distance
	if(txtLightShadFarDis->getCaption().length() > 0)
		light->setShadowFarDistance(StringConverter::parseReal(txtLightShadFarDis->getCaption()));

	// Shadow Near Clip Distance
	if(txtLightShadNearClipDis->getCaption().length() > 0)
		light->setShadowNearClipDistance(StringConverter::parseReal(txtLightShadNearClipDis->getCaption()));

	// Shadow Far Clip Distance
	if(txtShadFarClipDis->getCaption().length() > 0)
		light->setShadowFarClipDistance(StringConverter::parseReal(txtShadFarClipDis->getCaption()));

	// Spotlight Inner Angle
	if(txtLightInner->getCaption().length() > 0)
		light->setSpotlightInnerAngle(Radian(StringConverter::parseReal(txtLightInner->getCaption())));

	// Spotlight Outer Angle
	if(txtLightOutter->getCaption().length() > 0)
		light->setSpotlightOuterAngle(Radian(StringConverter::parseReal(txtLightOutter->getCaption())));

	// Spotlight Falloff
	if(txtLightFalloff->getCaption().length() > 0)
		light->setSpotlightFalloff(StringConverter::parseReal(txtLightFalloff->getCaption()));

	// Show light and bind to a game object
	if(!m_GameObject)
	{
		CEditorHelper::AddLightShape(light);
		m_GameObject = nullptr;
	}
	else
	{
		m_GameObject->SetPosition(pos);
	}

	return true;
}