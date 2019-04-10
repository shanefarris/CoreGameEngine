#ifndef __CHUD_MENU_H__
#define __CHUD_MENU_H__

#include "Defines.h"
#include "MyGui/MyGUI.h"
#define OIS_DYNAMIC_LIB
#include <OIS/OIS.h>

namespace Core
{
	namespace GUI
	{
		class CBaseLayout_MyGui;
		class CGuiStrategy_MyGui;
	}
}

class CHud : public OIS::MouseListener, public OIS::KeyListener
{
public:
	CHud(Core::GUI::CGuiStrategy_MyGui* Strategy);
	~CHud();

private:
	void PlacePlayer(f32 Width, f32 Height);

	void btnPlaceSolider_Click(MyGUI::Widget* _sender);
	void btnPlaceMarine_Click(MyGUI::Widget* _sender);

	bool mouseMoved(const OIS::MouseEvent &arg);
	bool mousePressed(const OIS::MouseEvent &arg, OIS::MouseButtonID id);
	bool mouseReleased(const OIS::MouseEvent &arg, OIS::MouseButtonID id);
	bool keyPressed(const OIS::KeyEvent &arg);
	bool keyReleased(const OIS::KeyEvent &arg);
		
	bool isPlaceSolider;
	bool isPlaceMarine;

	MyGUI::Button*	btnPlaceSolider;
	MyGUI::Button*	btnPlaceMarine;
	MyGUI::EditPtr	txtMoney;
	MyGUI::EditPtr	txtMessages;

	MyGUI::Widget*	frm;
};

#endif // __CHUD_MENU_H__