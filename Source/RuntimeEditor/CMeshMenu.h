#ifndef __CMESHMENU_H__
#define __CMESHMENU_H__

#include "Defines.h"
#include "EditorObjects.h"
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
	class CMeshMenu : public CInputKeyListener, public CInputMouseListener
	{
	public:
		CMeshMenu(GUI::CGuiStrategy_MyGui* Strategy);
		~CMeshMenu();
		
		void SetVisible(bool Visible);
		void SetVisible(bool Visible, const SELECTED& Selected, CGameObject* GameObject = nullptr);
		MyGUI::Widget* GetForm() { return frmMesh; }
		void SavePagedGeometry();
				
	private:
		bool MouseMoved(const CInputMouseEvent &arg);
		bool MousePressed(const CInputMouseEvent &arg, MouseButtonID id);
		bool MouseReleased(const CInputMouseEvent &arg, MouseButtonID id);

		bool KeyPressed(const CInputKeyEvent &arg);
		bool KeyReleased(const CInputKeyEvent &arg);

		void cmbMeshList_ComboAccept(MyGUI::ComboBox* _sender, size_t _index);
		void rdoMeshSphereObstacle_Click(MyGUI::Widget* _sender);
		void rdoMeshBoxObstacle_Click(MyGUI::Widget* _sender);
		void chkMeshRandom_Click(MyGUI::Widget* _sender);
		void btnMeshPlace_Click(MyGUI::Widget* _sender);
		void btnMeshClose_Click(MyGUI::Widget* _sender);
		void cmbMeshEnvAtt_ComboAccept(MyGUI::ComboBox* _sender, size_t _index);

		void btnPropertiesCancel_Click(MyGUI::Widget* _sender);
		void btnPropertiesSave_Click(MyGUI::Widget* _sender);
		
		void Close();
		void Save();
		void PopulateMeshList();
		void PopulationPhysicsProfiles();
		void PlaceMesh(f32 Width, f32 Height);
		void PlaceRandomMesh(f32 Width, f32 Height);
		ENVIRONMENT_ATTRIBUTE_TYPE GetEnvironmentAttributeType();
		String GetEnvironmentAttributeType(ENVIRONMENT_ATTRIBUTE_TYPE Type);
		void ResetControls();
		
		bool isPlaceMesh;						// Is the place mesh btn pressed and shift held down
		Vector<PAGED_GEO> m_PagedGeos;			// List of all the paged geometry made
		CGameObject*	  m_GameObject;			// Currently selected object
		SELECTED		  m_Selected;			// The selected object type

		GUI::CGuiStrategy_MyGui* m_Strategy;
	
		MyGUI::Widget*		frmMesh;
		MyGUI::ComboBox*	cmbMeshList;
		MyGUI::Button*		rdoMeshSphereObstacle;
		MyGUI::Button*		rdoMeshBoxObstacle;
		MyGUI::Button*		chkMeshRandom;
		MyGUI::EditPtr		txtMeshCount;
		MyGUI::Button*		btnMeshPlace;
		MyGUI::Button*		btnMeshClose;
		MyGUI::EditPtr		txtMeshMinX;
		MyGUI::EditPtr		txtMeshMinZ;
		MyGUI::EditPtr		txtMeshMaxX;
		MyGUI::EditPtr		txtMeshMaxZ;
		MyGUI::ComboBox*	cmbMeshEnvAtt;
		MyGUI::EditPtr		txtGameObjectName;

		MyGUI::EditPtr		txtGenPropPosX;
		MyGUI::EditPtr		txtGenPropPosY;
		MyGUI::EditPtr		txtGenPropPosZ;
		MyGUI::EditPtr		txtGenPropScaleX;
		MyGUI::EditPtr		txtGenPropScaleY;
		MyGUI::EditPtr		txtGenPropScaleZ;
		MyGUI::Button*		btnPropertiesCancel;
		MyGUI::Button*		btnPropertiesSave;
		MyGUI::ComboBox*	cmbGOPhysicsProfile;
	
	};
	
}
}

#endif // __CMESHMENU_H__