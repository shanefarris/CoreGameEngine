#ifndef __CVOLUMEMENU_H__
#define __CVOLUMEMENU_H__

#include "CoreEngine.h"
#include "EditorObjects.h"
#include "CEditorHelper.h"
#include "CInputListener.h"

#include "MyGui/MyGUI.h"

namespace Core
{
	class CInputKeyEvent;
	class CInputMouseEvent;
	enum MouseButtonID;

	namespace GUI
	{
		class CGuiStrategy_MyGui;
	}
	
namespace Editor
{
	class CVolumeMenu : public CInputKeyListener, public CInputMouseListener
	{
	public:
		CVolumeMenu(GUI::CGuiStrategy_MyGui* Strategy);
		~CVolumeMenu();
		
		void SetVisible(bool Visible);
		void SetVisible(bool Visible, SELECTE_TYPE& Selected);
		MyGUI::Widget* GetForm() { return frmVolume; }

	private:
		bool MouseMoved(const CInputMouseEvent &arg);
		bool MousePressed(const CInputMouseEvent &arg, MouseButtonID id);
		bool MouseReleased(const CInputMouseEvent &arg, MouseButtonID id);

		bool KeyPressed(const CInputKeyEvent &arg);
		bool KeyReleased(const CInputKeyEvent &arg);

		void cmbVolShape_ComboAccept(MyGUI::ComboBox* _sender, size_t _index);
		void btnVolPhySave_Click(MyGUI::Widget* _sender);
		void btnVolPhyClose_Click(MyGUI::Widget* _sender);
		void btnVolPhyPlace_Click(MyGUI::Widget* _sender);

		bool					 isPlaceVolume;
		GUI::CGuiStrategy_MyGui* m_Strategy;

		MyGUI::Widget*		frmVolume;
		MyGUI::ComboBox*	cmbVolShape;
		MyGUI::Edit*		txtVolPhyRadius;
		MyGUI::Edit*		txtVolPhySizeX;
		MyGUI::Button*		btnVolPhySave;
		MyGUI::Button*		btnVolPhyClose;
		MyGUI::Button*		btnVolPhyPlace;
		MyGUI::Edit*		txtVolPhySizeY;
		MyGUI::Edit*		txtVolPhySizeZ;
		MyGUI::Edit*		txtVolName;
		MyGUI::Edit*		txtVolPosX;
		MyGUI::Edit*		txtVolPosY;
		MyGUI::Edit*		txtVolPosZ;
	
	};
	
}
}

#endif // __CVOLUMEMENU_H__