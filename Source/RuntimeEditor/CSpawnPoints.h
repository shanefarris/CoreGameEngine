#ifndef __CSPAWN_POINTS_H__
#define __CSPAWN_POINTS_H__

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
	class CSpawnPoints : public CInputKeyListener, public CInputMouseListener
	{
	public:
		CSpawnPoints(GUI::CGuiStrategy_MyGui* Strategy);
		~CSpawnPoints();
		
		void SetVisible(bool Visible);
		void SetVisible(bool Visible, const SELECTED& Selected, CGameObject* GameObject);
		MyGUI::Widget* GetForm() { return frmSpawnPoint; }
				
	private:
		bool MouseMoved(const CInputMouseEvent &arg);
		bool MousePressed(const CInputMouseEvent &arg, MouseButtonID id);
		bool MouseReleased(const CInputMouseEvent &arg, MouseButtonID id);

		bool KeyPressed(const CInputKeyEvent &arg);
		bool KeyReleased(const CInputKeyEvent &arg);

		void cmbSpawnPoints_ComboAccept(MyGUI::ComboBox* _sender, size_t _index);
		void btnSpawnPointPlace_Click(MyGUI::WidgetPtr _sender);
		void btnSpawnPointClose_Click(MyGUI::WidgetPtr _sender);
		void btnSpawnPointUpdate_Click(MyGUI::WidgetPtr _sender);
		
		void Close();
		void Save();
		void PlaceSpawnPoint(f32 Width, f32 Height);
		void PopulateControls();
		
		bool			  isPlaceSpawnPoint;	// Is the place point btn pressed and shift held down
		CGameObject*	  m_GameObject;			// Currently selected object
		SELECTED		  m_Selected;			// The selected object type
		GUI::CGuiStrategy_MyGui* m_Strategy;
	
		MyGUI::Widget*		frmSpawnPoint;
		MyGUI::ComboBoxPtr	cmbSpawnPoints;
		MyGUI::EditPtr		txtSpawnPointId;
		MyGUI::EditPtr		txtSpawnPointX;
		MyGUI::EditPtr		txtSpawnPointY;
		MyGUI::EditPtr		txtSpawnPointZ;
		MyGUI::ComboBoxPtr	cmbSpawnPointTeam;
		MyGUI::EditPtr		txtSpawnPointCoolDown;
		MyGUI::ButtonPtr	btnSpawnPointPlace;
		MyGUI::ButtonPtr	btnSpawnPointClose;
		MyGUI::ButtonPtr	btnSpawnPointUpdate;
	};
	
}
}

#endif // __CSPAWN_POINTS_H__