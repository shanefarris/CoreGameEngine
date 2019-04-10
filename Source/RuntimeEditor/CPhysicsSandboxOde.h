#ifdef COMPILE_ODE
#ifndef __CPHYSICSSANDBOX_ODE_H__
#define __CPHYSICSSANDBOX_ODE_H__

#include "EditorObjects.h"
#include "MyGui/MyGUI.h"

namespace Core
{
	class CGameObject;
	namespace GUI
	{
		class CGuiStrategy_MyGui;
	}
	
namespace Editor
{
	class CPhysicsSandboxOde
	{
	public:
		CPhysicsSandboxOde(GUI::CGuiStrategy_MyGui* Strategy);
		~CPhysicsSandboxOde();
		
		void SetVisible(bool Visible);
		void SetVisible(bool Visible, const SELECTED& Selected, CGameObject* GameObject = nullptr);
		MyGUI::Widget* GetForm() { return frmOdeTest; }
				
	private:
		void chkOdeRDynamic_Click(MyGUI::Widget* _sender);
		void chkOdeRKinematic_Click(MyGUI::Widget* _sender);
		void chkOdeREnabled_Click(MyGUI::Widget* _sender);
		void chkOdeRAutoDisableFlag_Click(MyGUI::Widget* _sender);
		void btnOdeGClearOffset_Click(MyGUI::Widget* _sender);
		void chkOdeGEnabled_Click(MyGUI::Widget* _sender);
		void btnOdeSave_Click(MyGUI::Widget* _sender);
		void btnOdeClose_Click(MyGUI::Widget* _sender);
		
		void Close();
		void Save();
		void PopulateControls();

		SELECTED		  m_Selected;			// The selected object type
		CGameObject*	  m_GameObject;

		GUI::CGuiStrategy_MyGui* m_Strategy;

		MyGUI::Widget*		frmOdeTest;
		MyGUI::EditPtr		txtOdeWLinearDamping;
		MyGUI::EditPtr		txtOdeWAngularDamping;
		MyGUI::EditPtr		txtOdeWLinearDampingThreshold;
		MyGUI::EditPtr		txtOdeWAngularDampingThreshold;
		MyGUI::EditPtr		txtOdeWMaxAngularSpeed;
		MyGUI::EditPtr		txtOdeWContactMaxCorrectingVel;
		MyGUI::EditPtr		txtOdeWContactSurfaceLayer;
		MyGUI::Button*		chkOdeRDynamic;
		MyGUI::Button*		chkOdeRKinematic;
		MyGUI::Button*		chkOdeREnabled;
		MyGUI::Button*		chkOdeRAutoDisableFlag;
		MyGUI::EditPtr		txtOdeRAutoDisableLinearThreshold;
		MyGUI::EditPtr		txtOdeRAutoDisableAngularThreshold;
		MyGUI::EditPtr		txtOdeRAutoDisableSteps;
		MyGUI::EditPtr		txtOdeRAutoDisableTime;
		MyGUI::EditPtr		txtOdeRAutoDisableAvgSampleCnt;
		MyGUI::EditPtr		txtOdeRPosX;
		MyGUI::EditPtr		txtOdeRPosY;
		MyGUI::EditPtr		txtOdeRPosZ;
		MyGUI::EditPtr		txtOdeRLinearVelX;
		MyGUI::EditPtr		txtOdeRLinearVelY;
		MyGUI::EditPtr		txtOdeRLinearVelZ;
		MyGUI::EditPtr		txtOdeRAngularVelX;
		MyGUI::EditPtr		txtOdeRAngularVelY;
		MyGUI::EditPtr		txtOdeRAngularVelZ;
		MyGUI::EditPtr		txtOdeRAddForceX;
		MyGUI::EditPtr		txtOdeRAddForceY;
		MyGUI::EditPtr		txtOdeRAddForceZ;
		MyGUI::EditPtr		txtOdeRAddTorqueX;
		MyGUI::EditPtr		txtOdeRAddTorqueY;
		MyGUI::EditPtr		txtOdeRAddTorqueZ;
		MyGUI::EditPtr		txtOdeRRelForceX;
		MyGUI::EditPtr		txtOdeRRelForceY;
		MyGUI::EditPtr		txtOdeRRelForceZ;
		MyGUI::EditPtr		txtOdeRForceX;
		MyGUI::EditPtr		txtOdeRForceY;
		MyGUI::EditPtr		txtOdeRForceZ;
		MyGUI::EditPtr		txtOdeRTorqueX;
		MyGUI::EditPtr		txtOdeRTorqueY;
		MyGUI::EditPtr		txtOdeRTorqueZ;
		MyGUI::EditPtr		txtOdeRAddRelTorqueX;
		MyGUI::EditPtr		txtOdeRAddRelTorqueY;
		MyGUI::EditPtr		txtOdeRAddRelTorqueZ;
		MyGUI::EditPtr		txtOdeRAddForcePosX;
		MyGUI::EditPtr		txtOdeRAddForcePosY;
		MyGUI::EditPtr		txtOdeRAddForcePosZ;
		MyGUI::EditPtr		txtOdeRAddForceRelPosX;
		MyGUI::EditPtr		txtOdeRAddForceRelPosY;
		MyGUI::EditPtr		txtOdeRAddForceRelPosZ;
		MyGUI::EditPtr		txtOdeRAddRelForcePosX;
		MyGUI::EditPtr		txtOdeRAddRelForcePosY;
		MyGUI::EditPtr		txtOdeRAddRelForcePosZ;
		MyGUI::EditPtr		txtOdeRAddRelForceRelX;
		MyGUI::EditPtr		txtOdeRAddRelForceRelY;
		MyGUI::EditPtr		txtOdeRAddRelForceRelZ;
		MyGUI::EditPtr		txtOdeRUtilityPosX;
		MyGUI::EditPtr		txtOdeRUtilityPosY;
		MyGUI::EditPtr		txtOdeRUtilityPosZ;
		MyGUI::EditPtr		txtOdeRLinearDamping;
		MyGUI::EditPtr		txtOdeRAngularDamping;
		MyGUI::EditPtr		txtOdeRLinearDampingThreshold;
		MyGUI::EditPtr		txtOdeRAngularDampingThreshold;
		MyGUI::EditPtr		txtOdeRMaxAngularSpeed;
		MyGUI::Button*		btnOdeGClearOffset;
		MyGUI::Button*		chkOdeGEnabled;
		MyGUI::Button*		btnOdeSave;
		MyGUI::Button*		btnOdeClose;
	};
	
}
}

#endif // __CPHYSICSSANDBOX_ODE_H__

#endif // COMPILE_ODE