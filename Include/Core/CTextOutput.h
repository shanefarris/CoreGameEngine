#ifndef __CTEXTOUTPUT_H__
#define __CTEXTOUTPUT_H__

#include "Defines.h"

namespace Gorilla
{
	class Screen;
	class Layer;
	class Caption;
	class MarkupText;
	class Rectangle;
	class GlyphData;
}

namespace Ogre
{
	class ColourValue;
}

namespace Core
{
namespace OgreSpecific
{
	class CORE_EXPORT CTextOutput
	{
	private:
		static CTextOutput*	TextOutput;
		/*OverlayManager*		_overlayMgr;
		Overlay*			_overlay;
		OverlayContainer*	_panel;*/

		Gorilla::Screen*     m_Screen;
		Gorilla::Layer*      m_Layer;
		Gorilla::MarkupText* m_ConsoleText;

		u32	NumOfBoxes;

		struct TEXTBOX
		{
			TEXTBOX() { }
			TEXTBOX(String id, s32 order, Gorilla::Caption* c)
			{
				ID = id;
				Order = order;
				TextBox = c;
			}

			String			  ID;
			s32				  Order;
			Gorilla::Caption* TextBox;
		};

		Map<String, TEXTBOX> m_Textboxes;

		s32	FindTextBox(String Name);

	protected:
		CTextOutput();

	public:
		static CTextOutput* Instance();
		
		~CTextOutput();

		void AddTextBox(const String& ID, const String& text, f32 x, f32 y, f32 width, f32 height);
		void AddTextBox(const String& ID, const String& text, f32 x, f32 y, f32 width, f32 height, const ColourValue& color);
		void RemoveTextBox(const String& ID);
		void SetText(const String& ID, const String& Text);
		void Printf(const String& ID,  const char *fmt, /* args*/ ...);
		void SetVisible(bool Visible);
		bool IsVisible();
	};
}
}

#endif // __CTEXTOUTPUT_H__
