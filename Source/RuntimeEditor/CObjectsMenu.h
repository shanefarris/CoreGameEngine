#ifndef __COBJECTS_MENU_H__
#define __COBJECTS_MENU_H__

#include "Defines.h"
#include "EditorObjects.h"
#include "CInputListener.h"
#include "MyGui/MyGUI.h"

namespace Core
{
	class CInputKeyEvent;
	class CInputMouseEvent;
	enum MouseButtonID;

	namespace AI
	{
		class Wall;
	}

	namespace GUI
	{
		class CGuiStrategy_MyGui;
	}

namespace Editor
{
	class CObjectsMenu : public CInputKeyListener, public CInputMouseListener
	{
	public:
		CObjectsMenu(GUI::CGuiStrategy_MyGui* Strategy);
		~CObjectsMenu();

		void SetVisible(bool Visible);
		MyGUI::Widget* GetForm() { return frm; }
		void PopulateInventoryItemList();
		
		String  SceneFileName;							// Loading a new scene from the scene importer

	private:
		void PopulatePathsList();
		void PopulateSoundsList();
		void PopulatePlayerList();
		void DrawDynamicLine(f32 width, f32 height);	// Used to move the manual object line
		void DrawSelectionBox();
		void DrawTerrainLine(Vector3 lineEnd1, Vector3 lineEnd2, BillboardChain* billboardChain, f32 elementWidth);
		void PlaceObsBox(f32 Width, f32 Height);
		void PlaceObsSphere(f32 Width, f32 Height);
		void PlaceInventoryItem(f32 Width, f32 Height);
		void PlacePlayer(f32 Width, f32 Height);
		void AddPathPoint(f32 Width, f32 Height);
		void AddWall(f32 Width, f32 Height);
		void AddSound(f32 Width, f32 Height);

		void btnAddPlayer_Click(MyGUI::Widget* _sender);
		void btnAddEnemy_Click(MyGUI::Widget* _sender);
		void btnPhysAddBox_Click(MyGUI::Widget* _sender);
		void btnPhysAddSphere_Click(MyGUI::Widget* _sender);
		void btnObsAddBox_Click(MyGUI::Widget* _sender);
		void btnObsAddSphere_Click(MyGUI::Widget* _sender);
		void btnPlaceObsBox_Click(MyGUI::Widget* _sender);
		void btnPlaceObsSphere_Click(MyGUI::Widget* _sender);
		void btnAddPathPoint_Click(MyGUI::Widget* _sender);
		void btnAddAStarNodes_Click(MyGUI::Widget* _sender);
		void btnPhysicsProfile_Click(MyGUI::Widget* _sender);
		void btnAddWall_Click(MyGUI::Widget* _sender);
		void btnSave_Click(MyGUI::Widget* _sender);
		void btnLoadSceneFile_Click(MyGUI::Widget* _sender);
		void btnPlaceItem_Click(MyGUI::Widget* _sender);
		void btnPlacePlane_Click(MyGUI::Widget* _sender);
		void btnAddSound_Click(MyGUI::Widget* _sender);
		void btnAddMesh_Click(MyGUI::Widget* _sender);
		void btnAddVolume_Click(MyGUI::Widget* _sender);
		void chkShowPhyDebug_Click(MyGUI::Widget* _sender);
		void btnPhysSandbox_Click(MyGUI::Widget* _sender);
		void btnSpawnPoints_Click(MyGUI::Widget* _sender);
		void btnAddBuilding_Click(MyGUI::Widget* _sender);
		void btnHierarchy_Click(MyGUI::Widget* _sender);
		void btnAddLight_Click(MyGUI::WidgetPtr _sender);
		void cmbShadowTechnique_ComboAccept(MyGUI::ComboBox* _sender, size_t _index);
		void cmdSaveLight_Click(MyGUI::WidgetPtr _sender);

		bool MouseMoved(const CInputMouseEvent &arg);
		bool MousePressed(const CInputMouseEvent &arg, MouseButtonID id);
		bool MouseReleased(const CInputMouseEvent &arg, MouseButtonID id);

		bool KeyPressed(const CInputKeyEvent &arg);
		bool KeyReleased(const CInputKeyEvent &arg);
		
		bool isPlacePlayer;							// placing a player down
		bool isPlaceObsBox_Click;					// is the place obstacle button clicked BOX
		bool isPlaceObsSphere_Click;				// is the place obstacle button clicked SPHERE
		bool isAddPathPoint_Click;					// is the add path point clicked
		bool isAddWall_Click;						// is the add wall button clicked
		bool isPlaceInventoryItem;					// is the place inventory item clicked
		bool isAddSound;							// Adding a sound object
		bool isMouseReleased;

		Physics::IPhysicsStrategy*	m_Physics;
		Vector<CPlayer*>			m_Players;
		CPlayer*					curr_player;
		String						ItemName;
		String						SoundFile;
		Vector<Vector3>				PathPoints;		// points for a path
		u32							path_count;		// how many paths we've created
		Vector<AI::Wall*>			m_Walls;		// list of walls
		Vector<ManualObject*>		m_WallManObjs;	// lines as final walls
		u32							m_WallCounter;	// how many times have we clicked since we added a wall
		Vector3						m_CurrWallFrom;	// pos of "from" wall
		String						m_WallMatNameRed;
		String						m_WallMatNameWhite;
		ManualObject*				m_WallManObj;	// current line for the wall
		SELECTED					m_Selected;		// Currently selected object

		SceneNode *					selectionCircleSceneNode;
		BillboardChain *			selectionCircleBillboard;
		BillboardChain *			rayLine1;
		BillboardChain *			rayLine2;
		BillboardChain *			rayLine3;
		BillboardChain *			rayLine4;
		Vector3						dragBeginPoint;
		Vector3						dragEndPoint;
		bool						keepRunning;

		MyGUI::Button*		btnAddPlayer;
		MyGUI::Button*		btnPlaceObsBox;
		MyGUI::Button*		btnPlaceObsSphere;
		MyGUI::Button*		btnAddPathPoint;
		MyGUI::Button*		btnAddAStarNodes;
		MyGUI::Button*		btnPhysicsProfile;
		MyGUI::Button*		btnAddWall;
		MyGUI::ComboBox*	cmbPlayers;
		MyGUI::Button*		btnSave;
		MyGUI::ComboBox*	cmbFileType;
		MyGUI::Button*		btnLoadSceneFile;
		MyGUI::Button*		btnPlaceItem;
		MyGUI::ComboBox*	cmbItemsInventory;
		MyGUI::EditPtr		txtSceneFile;
		MyGUI::Button*		btnPlacePlane;
		MyGUI::ComboBox*	cmbPaths;
		MyGUI::ComboBox*	cmbSoundFiles;
		MyGUI::Button*		btnAddSound;
		MyGUI::Button*		btnAddMesh;
		MyGUI::Button*		btnAddVolume;
		MyGUI::Button*		chkShowPhyDebug;
		MyGUI::Button*		btnPhysSandbox;
		MyGUI::EditPtr		txtFirstRayTest;
		MyGUI::ListPtr		lstRayTestAll;
		MyGUI::Button*		btnSpawnPoints;
		MyGUI::Button*		btnAddBuilding;
		MyGUI::Button*		btnHierarchy;
		MyGUI::ButtonPtr	btnAddLight;
		MyGUI::ComboBoxPtr	cmbShadowTechnique;
		MyGUI::Edit*		txtAmbientX;
		MyGUI::Edit*		txtAmbientY;
		MyGUI::Edit*		txtAmbientZ;
		MyGUI::ButtonPtr	cmdSaveLight;

		MyGUI::Widget*		frm;
	};
}
}
#endif // __COBJECTS_MENU_H__