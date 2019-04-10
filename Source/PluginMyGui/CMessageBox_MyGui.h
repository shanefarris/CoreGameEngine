#ifndef __CMESSAGEBOX_MYGUI_H__
#define __CMESSAGEBOX_MYGUI_H__

#include <MyGUI.h>
#include "MessageBoxStyle.h"

using namespace MyGUI;

namespace Core
{
	namespace GUI
	{
		template <typename Type>
		struct DataHolder
		{
			~DataHolder()
			{
				for (typename Type::iterator item = data.begin(); item != data.end(); ++item)
					delete (*item).first;
			}

			Type data;
		};

		// интерфейс для обертки поля
		template <typename OwnerType, typename SetterType>
		struct Field
		{
			virtual bool set(OwnerType* _target, typename SetterType::BaseValueType* _value) = 0;
			virtual const std::string& getFieldTypeName() = 0;
		};

		// шаблон для обертки поля
		template <typename OwnerType, typename FieldType, typename SetterType>
		struct FieldHolder : public Field<OwnerType, SetterType>
		{
			FieldHolder(FieldType* OwnerType::* offset) : m_offset(offset) {  }
			FieldType* OwnerType::* const m_offset;

			virtual bool set(OwnerType* _target, typename SetterType::BaseValueType* _value)
			{
				_target->*m_offset = SetterType::template convert<FieldType>(_value);
				return _target->*m_offset != 0;
			}
			virtual const std::string& getFieldTypeName()
			{
				return FieldType::getClassTypeName();
			}
		};

		// шаблон для атрибута поля
		template <typename OwnerType, typename ValueType, typename SetterType>
		struct AttributeField
		{
			typedef std::pair<Field<OwnerType, SetterType>*, ValueType> BindPair;
			typedef std::vector<BindPair> VectorBindPair;

			template <typename FieldType>
			AttributeField(FieldType* OwnerType::* _offset, const ValueType& _value)
			{
				getData().push_back(BindPair(new FieldHolder<OwnerType, FieldType, SetterType>(_offset), _value));
			}
			static VectorBindPair& getData()
			{
				static DataHolder<VectorBindPair> data;
				return data.data;
			}
		};

		// макрос для инстансирования атрибута поля
#define DECLARE_ATTRIBUTE_FIELD(_name, _type, _setter) \
	template <typename OwnerType, typename ValueType = _type, typename SetterType = _setter> \
		struct _name : public AttributeField<OwnerType, ValueType, SetterType> \
		{ \
		template <typename FieldType> \
		_name(FieldType* OwnerType::* _offset, const ValueType& _value) : \
		AttributeField<OwnerType, ValueType, SetterType>(_offset, _value) { } \
		}

		// макрос для инстансирования экземпляра атрибута
#define ATTRIBUTE_FIELD(_attribute, _class, _field, _value) \
		struct _attribute##_##_field \
		{ \
		_attribute##_##_field() \
		{ \
		static _attribute<_class> bind(&_class::_field, _value); \
		} \
		} _attribute##_##_field


		// шаблон для атрибута класса
		template <typename Type, typename ValueType>
		struct ClassAttribute
		{
			ClassAttribute(const ValueType& _value)
			{
				getData() = _value;
			}
			static ValueType& getData()
			{
				static ValueType data;
				return data;
			}
		};

		// макрос для инстансирования атрибута класса
#define DECLARE_ATTRIBUTE_CLASS(_name, _type) \
	template <typename Type, typename ValueType = _type> \
		struct _name : public ClassAttribute<_name<Type>, ValueType> \
		{ \
		_name(const ValueType& _value) : \
		ClassAttribute<_name<Type>, ValueType>(_value) { } \
		}

		// макрос для инстансирования экземпляра класса
#define ATTRIBUTE_CLASS(_attribute, _class, _value) \
		class _class; \
		static _attribute<_class> _attribute##_##_class(_value)

		struct FieldSetterWidget
		{
			typedef MyGUI::Widget BaseValueType;

			template <typename Type>
			static Type* convert(BaseValueType* _value)
			{
				return _value == 0 ? 0 : _value->castType<Type>(false);
			}
		};

		DECLARE_ATTRIBUTE_FIELD(AttributeFieldWidgetName, std::string, FieldSetterWidget);

#define ATTRIBUTE_FIELD_WIDGET_NAME(_class, _field, _value) \
	ATTRIBUTE_FIELD(AttributeFieldWidgetName, _class, _field, _value)


		DECLARE_ATTRIBUTE_CLASS(AttributeSize, MyGUI::IntSize);

#define ATTRIBUTE_CLASS_SIZE(_class, _value) \
	ATTRIBUTE_CLASS(AttributeSize, _class, _value)


		DECLARE_ATTRIBUTE_CLASS(AttributeLayout, std::string);

#define ATTRIBUTE_CLASS_LAYOUT(_class, _value) \
	ATTRIBUTE_CLASS(AttributeLayout, _class, _value)


		class BaseLayout
		{
		protected:
			BaseLayout() : mMainWidget(nullptr)
			{
			}

			BaseLayout(const std::string& _layout, MyGUI::Widget* _parent = nullptr) : mMainWidget(nullptr)
			{
				initialise(_layout, _parent);
			}

			template <typename T>
			void assignWidget(T * & _widget, const std::string& _name, bool _throw = true, bool _createFakeWidgets = true)
			{
				_widget = nullptr;
				for (MyGUI::VectorWidgetPtr::iterator iter = mListWindowRoot.begin(); iter != mListWindowRoot.end(); ++iter)
				{
					MyGUI::Widget* find = (*iter)->findWidget(mPrefix + _name);
					if (nullptr != find)
					{
						T* cast = find->castType<T>(false);
						if (nullptr != cast)
						{
							_widget = cast;
						}
						else
						{
							MYGUI_LOG(Warning, "Widget with name '" << _name << "' have wrong type ('" <<
								find->getTypeName() << "instead of '" << T::getClassTypeName() << "'). [" << mLayoutName << "]");
							MYGUI_ASSERT( ! _throw, "Can't assign widget with name '" << _name << "'. [" << mLayoutName << "]");
							if (_createFakeWidgets)
								_widget = _createFakeWidget<T>(mMainWidget);
						}

						return;
					}
				}
				MYGUI_LOG(Warning, "Widget with name '" << _name << "' not found. [" << mLayoutName << "]");
				MYGUI_ASSERT( ! _throw, "Can't assign widget with name '" << _name << "'. [" << mLayoutName << "]");
				if (_createFakeWidgets)
					_widget = _createFakeWidget<T>(mMainWidget);
			}

			template <typename T>
			void assignBase(T * & _widget, const std::string& _name, bool _throw = true, bool _createFakeWidgets = true)
			{
				_widget = nullptr;
				for (MyGUI::VectorWidgetPtr::iterator iter = mListWindowRoot.begin(); iter != mListWindowRoot.end(); ++iter)
				{
					MyGUI::Widget* find = (*iter)->findWidget(mPrefix + _name);
					if (nullptr != find)
					{
						_widget = new T(find);
						mListBase.push_back(_widget);
						return;
					}
				}

				MYGUI_LOG(Warning, "Widget with name '" << _name << "' not found. [" << mLayoutName << "]");
				MYGUI_ASSERT( ! _throw, "Can't assign base widget with name '" << _name << "'. [" << mLayoutName << "]");
				if (_createFakeWidgets)
				{
					_widget = new T(_createFakeWidget<MyGUI::Widget>(mMainWidget));
					mListBase.push_back(_widget);
				}
			}

			void initialise(const std::string& _layout, MyGUI::Widget* _parent = nullptr, bool _throw = true, bool _createFakeWidgets = true)
			{
				const std::string MAIN_WINDOW1 = "_Main";
				const std::string MAIN_WINDOW2 = "Root";
				mLayoutName = _layout;

				// оборачиваем
				if (mLayoutName.empty())
				{
					mMainWidget = _parent;
				}
				// загружаем лейаут на виджет
				else
				{
					mPrefix = MyGUI::utility::toString(this, "_");
					mListWindowRoot = MyGUI::LayoutManager::getInstance().loadLayout(mLayoutName, mPrefix, _parent);

					const std::string mainName1 = mPrefix + MAIN_WINDOW1;
					const std::string mainName2 = mPrefix + MAIN_WINDOW2;
					for (MyGUI::VectorWidgetPtr::iterator iter = mListWindowRoot.begin(); iter != mListWindowRoot.end(); ++iter)
					{
						if ((*iter)->getName() == mainName1 || (*iter)->getName() == mainName2)
						{
							mMainWidget = (*iter);

							snapToParent(mMainWidget);

							break;
						}
					}

					if (mMainWidget == nullptr)
					{
						MYGUI_LOG(Warning, "Root widget with name '" << MAIN_WINDOW1 << "' or '" << MAIN_WINDOW2 << "'  not found. [" << mLayoutName << "]");
						MYGUI_ASSERT(!_throw, "No root widget. ['" << mLayoutName << "]");
						if (_createFakeWidgets)
							mMainWidget = _createFakeWidget<MyGUI::Widget>(_parent);
					}
				}
			}

			void shutdown()
			{
				// удаляем все классы
				for (VectorBasePtr::reverse_iterator iter = mListBase.rbegin(); iter != mListBase.rend(); ++iter)
					delete (*iter);
				mListBase.clear();

				// удаляем все рутовые виджеты
				MyGUI::LayoutManager::getInstance().unloadLayout(mListWindowRoot);
				mListWindowRoot.clear();
			}

			template <typename Type>
			void initialiseByAttributes(Type* _owner, MyGUI::Widget* _parent = nullptr, bool _throw = true, bool _createFakeWidgets = true)
			{
				initialise(AttributeLayout<Type>::getData(), _parent, _throw, _createFakeWidgets);

				typename AttributeFieldWidgetName<Type>::VectorBindPair& data = AttributeFieldWidgetName<Type>::getData();
				for (typename AttributeFieldWidgetName<Type>::VectorBindPair::iterator item = data.begin(); item != data.end(); ++item)
				{
					MyGUI::Widget* value = nullptr;
					assignWidget(value, item->second, _throw, false);

					bool result = item->first->set(_owner, value);

					if (!result && _createFakeWidgets)
					{
						value = _createFakeWidgetT(item->first->getFieldTypeName(), mMainWidget);
						item->first->set(_owner, value);
					}
				}
			}
		private:
			void snapToParent(MyGUI::Widget* _child)
			{
				if (_child->isUserString("SnapTo"))
				{
					MyGUI::Align align = MyGUI::Align::parse(_child->getUserString("SnapTo"));

					MyGUI::IntCoord coord = _child->getCoord();
					MyGUI::IntSize size = _child->getParentSize();

					if (align.isHStretch())
					{
						coord.left = 0;
						coord.width = size.width;
					}
					else if (align.isLeft())
					{
						coord.left = 0;
					}
					else if (align.isRight())
					{
						coord.left = size.width - coord.width;
					}
					else
					{
						coord.left = (size.width - coord.width) / 2;
					}

					if (align.isVStretch())
					{
						coord.top = 0;
						coord.height = size.height;
					}
					else if (align.isTop())
					{
						coord.top = 0;
					}
					else if (align.isBottom())
					{
						coord.top = size.height - coord.height;
					}
					else
					{
						coord.top = (size.height - coord.height) / 2;
					}

					_child->setCoord(coord);
				}
			}

			template <typename T>
			T* _createFakeWidget(MyGUI::Widget* _parent)
			{
				return static_cast<T*>(_createFakeWidgetT(T::getClassTypeName(), _parent));
			}

			MyGUI::Widget* _createFakeWidgetT(const std::string& _typeName, MyGUI::Widget* _parent)
			{
				if (_parent)
					return _parent->createWidgetT(_typeName, MyGUI::SkinManager::getInstance().getDefaultSkin(), MyGUI::IntCoord(), MyGUI::Align::Default);

				return MyGUI::Gui::getInstance().createWidgetT(_typeName, MyGUI::SkinManager::getInstance().getDefaultSkin(), MyGUI::IntCoord(), MyGUI::Align::Default, "");
			}

		public:
			virtual ~BaseLayout()
			{
				shutdown();
			}

		protected:
			MyGUI::Widget* mMainWidget;

		private:
			std::string mPrefix;
			std::string mLayoutName;
			MyGUI::VectorWidgetPtr mListWindowRoot;
			typedef std::vector<BaseLayout*> VectorBasePtr;
			VectorBasePtr mListBase;
		};



		class Message;

		typedef delegates::CMultiDelegate2<Message*, MessageBoxStyle> EventHandle_MessageBoxPtrMessageStyle;

		class Message :
			public BaseLayout
		{
		public:
			Message() :
				BaseLayout("MessageBox.layout"),
				mWidgetText(nullptr),
				mInfoOk(MessageBoxStyle::None),
				mInfoCancel(MessageBoxStyle::None),
				mSmoothShow(false),
				mIcon(nullptr),
				mLeftOffset1(0),
				mLeftOffset2(0)
			{
				assignWidget(mWidgetText, "Text", false);
				if (mWidgetText != nullptr)
				{
					mOffsetText.set(mMainWidget->getClientCoord().width - mWidgetText->getWidth(), mMainWidget->getClientCoord().height - mWidgetText->getHeight());
					mLeftOffset2 = mLeftOffset1 = mWidgetText->getLeft();
				}

				assignWidget(mIcon, "Icon", false);
				if (mIcon != nullptr)
				{
					mLeftOffset2 = mIcon->getRight() + 3;
				}

				mButtonType = Button::getClassTypeName();

				if (mMainWidget->isUserString("ButtonSkin"))
					mButtonSkin = mMainWidget->getUserString("ButtonSkin");

				Widget* widget = nullptr;
				assignWidget(widget, "ButtonPlace", false);
				if (widget != nullptr)
				{
					mButtonOffset.set(widget->getLeft(), mMainWidget->getClientCoord().height - widget->getTop());
					widget->setVisible(false);
				}

				assignWidget(widget, "ButtonTemplate", false);
				if (widget != nullptr)
				{
					mButtonSize = widget->getSize();
				}
			}

			virtual ~Message()
			{
				mWidgetText = nullptr;
				mIcon = nullptr;
			}

			/** Set caption text*/
			void setCaption(const UString& _value)
			{
				mMainWidget->castType<Window>()->setCaption(_value);
			}

			/** Set message text*/
			void setMessageText(const UString& _value)
			{
				if (mWidgetText != nullptr)
					mWidgetText->setCaption(_value);
				updateSize();
			}

			/** Create button with specific name*/
			MessageBoxStyle addButtonName(const UString& _name)
			{
				if (mVectorButton.size() >= MessageBoxStyle::_CountUserButtons)
				{
					MYGUI_LOG(Warning, "Too many buttons in message box, ignored");
					return MessageBoxStyle::None;
				}
				// бит, номер кнопки + смещение до Button1
				MessageBoxStyle info = MessageBoxStyle(MessageBoxStyle::Enum(MYGUI_FLAG(mVectorButton.size() + MessageBoxStyle::_IndexUserButton1)));

				// запоминаем кнопки для отмены и подтверждения
				if (mVectorButton.empty())
					mInfoOk = info;
				mInfoCancel = info;

				Widget* widget = mMainWidget->createWidgetT(mButtonType, mButtonSkin, IntCoord(), Align::Left | Align::Bottom);
				Button* button = widget->castType<Button>();
				button->eventMouseButtonClick += newDelegate(this, &Message::notifyButtonClick);
				button->setCaption(_name);
				button->_setInternalData(info);
				mVectorButton.push_back(button);

				updateSize();
				return info;
			}

			/** Set smooth message showing*/
			void setSmoothShow(bool _value)
			{
				mSmoothShow = _value;
				if (mSmoothShow)
				{
					mMainWidget->setAlpha(ALPHA_MIN);
					mMainWidget->setVisible(true);
					mMainWidget->castType<Window>()->setVisibleSmooth(true);
				}
			}

			/** Set message icon*/
			void setMessageIcon(MessageBoxStyle _value)
			{
				if (nullptr == mIcon)
					return;

				if (mIcon->getItemResource() != nullptr)
				{
					mIcon->setItemName(getIconName(_value.getIconIndex()));
				}
				else
				{
					mIcon->setImageIndex(_value.getIconIndex());
				}

				updateSize();
			}

			void endMessage(MessageBoxStyle _result)
			{
				_destroyMessage(_result);
			}

			void endMessage()
			{
				_destroyMessage(mInfoCancel);
			}

			/** Create button using MessageBoxStyle*/
			void setMessageButton(MessageBoxStyle _value)
			{
				clearButton();

				std::vector<MessageBoxStyle> buttons = _value.getButtons();

				for (size_t index = 0; index < buttons.size(); ++index)
				{
					// корректируем ее номер
					MessageBoxStyle info = buttons[index];

					// если бит есть то ставим кнопку
					addButtonName(getButtonName(info));

					// внутри адд сбрасывается
					mVectorButton.back()->_setInternalData(info);

					// первая кнопка
					if (mVectorButton.size() == 1)
						mInfoOk = info;
					// последняя кнопка
					mInfoCancel = info;
				}

				updateSize();
			}

			/** Set message style (button and icon)*/
			void setMessageStyle(MessageBoxStyle _value)
			{
				setMessageButton(_value);
				setMessageIcon(_value);
			}

			void setMessageModal(bool _value)
			{
				if (_value)
					InputManager::getInstance().addWidgetModal(mMainWidget);
				else
					InputManager::getInstance().removeWidgetModal(mMainWidget);
			}

			/** Static method for creating message with one command
			@param
			_modal if true all other GUI elements will be blocked untill message is closed
			@param
			_style any combination of flags from ViewValueInfo
			@param
			_button1 ... _button4 specific buttons names
			*/
			static Message* createMessageBox(
				const UString& _skinName,
				const UString& _caption,
				const UString& _message,
				MessageBoxStyle _style = MessageBoxStyle::Ok | MessageBoxStyle::IconDefault,
				const std::string& _layer = "",
				bool _modal = true,
				const std::string& _button1 = "",
				const std::string& _button2 = "",
				const std::string& _button3 = "",
				const std::string& _button4 = "")
			{
				Message* mess = new Message();

				mess->setCaption(_caption);
				mess->setMessageText(_message);

				mess->setSmoothShow(true);

				mess->setMessageStyle(_style);

				if (!_button1.empty())
				{
					mess->addButtonName(_button1);
					if (!_button2.empty())
					{
						mess->addButtonName(_button2);
						if (!_button3.empty())
						{
							mess->addButtonName(_button3);
						}
					}
				}

				if (_modal)
					InputManager::getInstance().addWidgetModal(mess->mMainWidget);

				return mess;
			}

			/*events:*/
			/** Event : button on message window pressed.\n
			signature : void method(tools::Message* _sender, MessageBoxStyle _result)\n
			@param _sender widget that called this event
			@param _result - id of pressed button
			*/
			EventHandle_MessageBoxPtrMessageStyle
				eventMessageBoxResult;

		protected:
			void updateSize()
			{
				ISubWidgetText* text = nullptr;
				if (mWidgetText != nullptr)
					text = mWidgetText->getSubWidgetText();
				IntSize size = text == nullptr ? IntSize() : text->getTextSize();
				// минимум высота иконки
				if ((nullptr != mIcon) && (mIcon->getImageIndex() != ITEM_NONE))
				{
					if (size.height < mIcon->getHeight())
						size.height = mIcon->getHeight();
					size.width += mIcon->getSize().width;
				}
				size += mOffsetText;
				size.width += 3;

				int width = ((int)mVectorButton.size() * mButtonSize.width) + (((int)mVectorButton.size() + 1) * mButtonOffset.width);
				if (size.width < width)
					size.width = width;

				int offset = (size.width - width) / 2;
				offset += mButtonOffset.width;

				size.width += mMainWidget->getWidth() - mMainWidget->getClientCoord().width;
				size.height += mMainWidget->getHeight() - mMainWidget->getClientCoord().height;

				const IntSize& view = RenderManager::getInstance().getViewSize();
				mMainWidget->setCoord((view.width - size.width) / 2, (view.height - size.height) / 2, size.width, size.height);

				if (nullptr != mIcon)
				{
					if (mWidgetText != nullptr)
					{
						if (mIcon->getImageIndex() != ITEM_NONE)
							mWidgetText->setCoord(mLeftOffset2, mWidgetText->getTop(), mWidgetText->getWidth(), mWidgetText->getHeight());
						else
							mWidgetText->setCoord(mLeftOffset1, mWidgetText->getTop(), mWidgetText->getWidth(), mWidgetText->getHeight());
					}
				}

				for (std::vector<Button*>::iterator iter = mVectorButton.begin(); iter != mVectorButton.end(); ++iter)
				{
					(*iter)->setCoord(offset, mMainWidget->getClientCoord().height - mButtonOffset.height, mButtonSize.width, mButtonSize.height);
					offset += mButtonOffset.width + mButtonSize.width;
				}
			}

			void notifyButtonClick(Widget* _sender)
			{
				_destroyMessage(*_sender->_getInternalData<MessageBoxStyle>());
			}

			void clearButton()
			{
				for (std::vector<Button*>::iterator iter = mVectorButton.begin(); iter != mVectorButton.end(); ++iter)
					WidgetManager::getInstance().destroyWidget(*iter);
				mVectorButton.clear();
			}

			/*void onKeyButtonPressed(KeyCode _key, Char _char)
			{
			Base::onKeyButtonPressed(_key, _char);

			if ((_key == KeyCode::Return) || (_key == KeyCode::NumpadEnter))
			_destroyMessage(mInfoOk);
			else if (_key == KeyCode::Escape)
			_destroyMessage(mInfoCancel);
			}*/

			void _destroyMessage(MessageBoxStyle _result)
			{
				eventMessageBoxResult(this, _result);

				delete this;
			}

			UString getButtonName(MessageBoxStyle _style) const
			{
				size_t index = _style.getButtonIndex();
				const char* tag = getButtonTag(index);
				UString result = LanguageManager::getInstance().replaceTags(utility::toString("#{", tag, "}"));
				if (result == tag)
					return getButtonName(index);
				return result;
			}

			const char* getIconName(size_t _index) const
			{
				static const size_t CountIcons = 4;
				static const char* IconNames[CountIcons + 1] = { "Info", "Quest", "Error", "Warning", "" };
				if (_index >= CountIcons)
					return IconNames[CountIcons];
				return IconNames[_index];
			}

			const char* getButtonName(size_t _index) const
			{
				static const size_t Count = 9;
				static const char * Names[Count + 1] = { "Ok", "Yes", "No", "Abort", "Retry", "Ignore", "Cancel", "Try", "Continue", "" };
				if (_index >= Count)
					return Names[Count];
				return Names[_index];
			}

			const char* getButtonTag(size_t _index) const
			{
				static const size_t Count = 9;
				static const char* Names[Count + 1] = { "MessageBox_Ok", "MessageBox_Yes", "MessageBox_No", "MessageBox_Abort", "MessageBox_Retry", "MessageBox_Ignore", "MessageBox_Cancel", "MessageBox_Try", "MessageBox_Continue", "" };
				if (_index >= Count)
					return Names[Count];
				return Names[_index];
			}

		private:
			IntSize mOffsetText;
			TextBox* mWidgetText;

			std::string mButtonSkin;
			std::string mButtonType;
			IntSize mButtonSize;
			IntSize mButtonOffset;

			std::vector<Button*> mVectorButton;
			MessageBoxStyle mInfoOk;
			MessageBoxStyle mInfoCancel;
			bool mSmoothShow;

			std::string mDefaultCaption;
			ImageBox* mIcon;
			int mLeftOffset1;
			int mLeftOffset2;
		};



	}
}
#endif // __CMESSAGEBOX_MYGUI_H__








//class CMessageBox_MyGui;
//
//		typedef delegates::CMultiDelegate2<CMessageBox_MyGui*, MessageBoxStyle> EventHandle_MessageBoxPtrMessageStyle;
//
//		class CMessageBox_MyGui
//		{
//		public:
//			CMessageBox_MyGui() :
//				mWidgetText(nullptr),
//				mInfoOk(MessageBoxStyle::None),
//				mInfoCancel(MessageBoxStyle::None),
//				mSmoothShow(false),
//				mIcon(nullptr),
//				mLeftOffset1(0),
//				mLeftOffset2(0),
//				mMainWidget(nullptr)
//			{
//				const std::string MAIN_WINDOW = "Root";
//				auto mLayoutName = "MessageBox.layout";
//
//				auto mPrefix = MyGUI::utility::toString(this, "_");
//				mListWindowRoot = MyGUI::LayoutManager::getInstance().loadLayout(mLayoutName, mPrefix, nullptr);
//				auto main_name = mPrefix + MAIN_WINDOW;
//				for (auto iter = mListWindowRoot.cbegin(); iter!=mListWindowRoot.cend(); ++iter)
//				{
//					if ((*iter)->getName() == main_name)
//					{
//						mMainWidget = (*iter);
//						break;
//					}
//				}
//				MYGUI_ASSERT(mMainWidget, "root widget name '" << MAIN_WINDOW << "' in layout '" << mLayoutName << "' not found.");
//
//
//				AssignWidget(mWidgetText, "Text", false);
//				if (mWidgetText != nullptr)
//				{
//					mOffsetText.set(mMainWidget->getClientCoord().width - mWidgetText->getWidth(), mMainWidget->getClientCoord().height - mWidgetText->getHeight());
//					mLeftOffset2 = mLeftOffset1 = mWidgetText->getLeft();
//				}
//
//				AssignWidget(mIcon, "Icon", false);
//				if (mIcon != nullptr)
//				{
//					mLeftOffset2 = mIcon->getRight() + 3;
//				}
//
//				mButtonType = Button::getClassTypeName();
//
//				if (mMainWidget->isUserString("ButtonSkin"))
//					mButtonSkin = mMainWidget->getUserString("ButtonSkin");
//
//				Widget* widget = nullptr;
//				AssignWidget(widget, "ButtonPlace", false);
//				if (widget != nullptr)
//				{
//					mButtonOffset.set(widget->getLeft(), mMainWidget->getClientCoord().height - widget->getTop());
//					widget->setVisible(false);
//				}
//
//				AssignWidget(widget, "ButtonTemplate", false);
//				if (widget != nullptr)
//				{
//					mButtonSize = widget->getSize();
//				}
//			}
//
//			virtual ~CMessageBox_MyGui()
//			{
//				shutdown();
//				mWidgetText = nullptr;
//				mIcon = nullptr;
//			}
//
//			/** Set caption text*/
//			void setCaption(const UString& _value)
//			{
//				mMainWidget->castType<Window>()->setCaption(_value);
//			}
//
//			/** Set message text*/
//			void setMessageText(const UString& _value)
//			{
//				if (mWidgetText != nullptr)
//					mWidgetText->setCaption(_value);
//				updateSize();
//			}
//
//			/** Create button with specific name*/
//			MessageBoxStyle addButtonName(const UString& _name)
//			{
//				if (mVectorButton.size() >= MessageBoxStyle::_CountUserButtons)
//				{
//					MYGUI_LOG(Warning, "Too many buttons in message box, ignored");
//					return MessageBoxStyle::None;
//				}
//				// бит, номер кнопки + смещение до Button1
//				MessageBoxStyle info = MessageBoxStyle(MessageBoxStyle::Enum(MYGUI_FLAG(mVectorButton.size() + MessageBoxStyle::_IndexUserButton1)));
//
//				// запоминаем кнопки для отмены и подтверждения
//				if (mVectorButton.empty())
//					mInfoOk = info;
//				mInfoCancel = info;
//
//				Widget* widget = mMainWidget->createWidgetT(mButtonType, mButtonSkin, IntCoord(), Align::Left | Align::Bottom);
//				Button* button = widget->castType<Button>();
//				button->eventMouseButtonClick += newDelegate(this, &CMessageBox_MyGui::notifyButtonClick);
//				button->setCaption(_name);
//				button->_setInternalData(info);
//				mVectorButton.push_back(button);
//
//				updateSize();
//				return info;
//			}
//
//			/** Set smooth message showing*/
//			void setSmoothShow(bool _value)
//			{
//				mSmoothShow = _value;
//				if (mSmoothShow)
//				{
//					mMainWidget->setAlpha(ALPHA_MIN);
//					mMainWidget->setVisible(true);
//					mMainWidget->castType<Window>()->setVisibleSmooth(true);
//				}
//			}
//
//			/** Set message icon*/
//			void setMessageIcon(MessageBoxStyle _value)
//			{
//				if (nullptr == mIcon)
//					return;
//
//				if (mIcon->getItemResource() != nullptr)
//				{
//					mIcon->setItemName(getIconName(_value.getIconIndex()));
//				}
//				else
//				{
//					mIcon->setImageIndex(_value.getIconIndex());
//				}
//
//				updateSize();
//			}
//
//			void endMessage(MessageBoxStyle _result)
//			{
//				_destroyMessage(_result);
//			}
//
//			void endMessage()
//			{
//				_destroyMessage(mInfoCancel);
//			}
//
//			/** Create button using MessageBoxStyle*/
//			void setMessageButton(MessageBoxStyle _value)
//			{
//				clearButton();
//
//				std::vector<MessageBoxStyle> buttons = _value.getButtons();
//
//				for (size_t index = 0; index < buttons.size(); ++index)
//				{
//					// корректируем ее номер
//					MessageBoxStyle info = buttons[index];
//
//					// если бит есть то ставим кнопку
//					addButtonName(getButtonName(info));
//
//					// внутри адд сбрасывается
//					mVectorButton.back()->_setInternalData(info);
//
//					// первая кнопка
//					if (mVectorButton.size() == 1)
//						mInfoOk = info;
//					// последняя кнопка
//					mInfoCancel = info;
//				}
//
//				updateSize();
//			}
//
//			/** Set message style (button and icon)*/
//			void setMessageStyle(MessageBoxStyle _value)
//			{
//				setMessageButton(_value);
//				setMessageIcon(_value);
//			}
//
//			void setMessageModal(bool _value)
//			{
//				if (_value)
//					InputManager::getInstance().addWidgetModal(mMainWidget);
//				else
//					InputManager::getInstance().removeWidgetModal(mMainWidget);
//			}
//
//			/** Static method for creating message with one command
//			@param
//			_modal if true all other GUI elements will be blocked untill message is closed
//			@param
//			_style any combination of flags from ViewValueInfo
//			@param
//			_button1 ... _button4 specific buttons names
//			*/
//			static CMessageBox_MyGui* createMessageBox(
//				const UString& _skinName,
//				const UString& _caption,
//				const UString& _message,
//				MessageBoxStyle _style = MessageBoxStyle::Ok | MessageBoxStyle::IconDefault,
//				const std::string& _layer = "",
//				bool _modal = true,
//				const std::string& _button1 = "",
//				const std::string& _button2 = "",
//				const std::string& _button3 = "",
//				const std::string& _button4 = "")
//			{
//				auto mess = new CMessageBox_MyGui();
//
//				mess->setCaption(_caption);
//				mess->setMessageText(_message);
//
//				mess->setSmoothShow(true);
//
//				mess->setMessageStyle(_style);
//
//				if (!_button1.empty())
//				{
//					mess->addButtonName(_button1);
//					if (!_button2.empty())
//					{
//						mess->addButtonName(_button2);
//						if (!_button3.empty())
//						{
//							mess->addButtonName(_button3);
//						}
//					}
//				}
//
//				if (_modal)
//					InputManager::getInstance().addWidgetModal(mess->mMainWidget);
//
//				return mess;
//			}
//
//			/*events:*/
//			/** Event : button on message window pressed.\n
//			signature : void method(tools::Message* _sender, MessageBoxStyle _result)\n
//			@param _sender widget that called this event
//			@param _result - id of pressed button
//			*/
//			EventHandle_MessageBoxPtrMessageStyle
//				eventMessageBoxResult;
//
//		protected:
//			template <typename T> void AssignWidget(T * & _widget, const std::string& _name, bool _throw = true)
//			{
//				_widget = nullptr;
//				for (auto iter = mListWindowRoot.cbegin(); iter!=mListWindowRoot.cend(); ++iter)
//				{
//					auto mPrefix = MyGUI::utility::toString(this, "_");
//					MyGUI::WidgetPtr find = (*iter)->findWidget(mPrefix + _name);
//					if (nullptr != find)
//					{
//						T * cast = find->castType<T>(false);
//						if (nullptr != cast)
//						{
//							_widget = cast;
//						}
//						else if (_throw)
//						{
//							MYGUI_EXCEPT("Error cast : dest type = '" << T::getClassTypeName()
//								<< "' source name = '" << find->getName()
//								<< "' source type = '" << find->getTypeName() << "'");
//						}
//						return;
//
//					}
//				}
//				MYGUI_ASSERT( ! _throw, "widget name '" << _name << "' not found.");
//			}
//
//			void shutdown()
//			{
//				//for (auto iter = mListWindowRoot.rbegin(); iter != mListWindowRoot.rend(); ++iter)
//				//	(*iter)->_shutdown();
//				mListWindowRoot.clear();
//
//				// удаляем все рутовые виджеты
//				MyGUI::LayoutManager::getInstance().unloadLayout(mListWindowRoot);
//				mListWindowRoot.clear();
//			}
//
//			void updateSize()
//			{
//				ISubWidgetText* text = nullptr;
//				if (mWidgetText != nullptr)
//					text = mWidgetText->getSubWidgetText();
//				IntSize size = text == nullptr ? IntSize() : text->getTextSize();
//				// минимум высота иконки
//				if ((nullptr != mIcon) && (mIcon->getImageIndex() != ITEM_NONE))
//				{
//					if (size.height < mIcon->getHeight())
//						size.height = mIcon->getHeight();
//					size.width += mIcon->getSize().width;
//				}
//				size += mOffsetText;
//				size.width += 3;
//
//				int width = ((int)mVectorButton.size() * mButtonSize.width) + (((int)mVectorButton.size() + 1) * mButtonOffset.width);
//				if (size.width < width)
//					size.width = width;
//
//				int offset = (size.width - width) / 2;
//				offset += mButtonOffset.width;
//
//				size.width += mMainWidget->getWidth() - mMainWidget->getClientCoord().width;
//				size.height += mMainWidget->getHeight() - mMainWidget->getClientCoord().height;
//
//				const IntSize& view = RenderManager::getInstance().getViewSize();
//				mMainWidget->setCoord((view.width - size.width) / 2, (view.height - size.height) / 2, size.width, size.height);
//
//				if (nullptr != mIcon)
//				{
//					if (mWidgetText != nullptr)
//					{
//						if (mIcon->getImageIndex() != ITEM_NONE)
//							mWidgetText->setCoord(mLeftOffset2, mWidgetText->getTop(), mWidgetText->getWidth(), mWidgetText->getHeight());
//						else
//							mWidgetText->setCoord(mLeftOffset1, mWidgetText->getTop(), mWidgetText->getWidth(), mWidgetText->getHeight());
//					}
//				}
//
//				for (std::vector<Button*>::iterator iter = mVectorButton.begin(); iter != mVectorButton.end(); ++iter)
//				{
//					(*iter)->setCoord(offset, mMainWidget->getClientCoord().height - mButtonOffset.height, mButtonSize.width, mButtonSize.height);
//					offset += mButtonOffset.width + mButtonSize.width;
//				}
//			}
//
//			void notifyButtonClick(Widget* _sender)
//			{
//				_destroyMessage(*_sender->_getInternalData<MessageBoxStyle>());
//			}
//
//			void clearButton()
//			{
//				for (std::vector<Button*>::iterator iter = mVectorButton.begin(); iter != mVectorButton.end(); ++iter)
//					WidgetManager::getInstance().destroyWidget(*iter);
//				mVectorButton.clear();
//			}
//
//			/*void onKeyButtonPressed(KeyCode _key, Char _char)
//			{
//			Base::onKeyButtonPressed(_key, _char);
//
//			if ((_key == KeyCode::Return) || (_key == KeyCode::NumpadEnter))
//			_destroyMessage(mInfoOk);
//			else if (_key == KeyCode::Escape)
//			_destroyMessage(mInfoCancel);
//			}*/
//
//			void _destroyMessage(MessageBoxStyle _result)
//			{
//				eventMessageBoxResult(this, _result);
//
//				delete this;
//			}
//
//			UString getButtonName(MessageBoxStyle _style) const
//			{
//				size_t index = _style.getButtonIndex();
//				const char* tag = getButtonTag(index);
//				UString result = LanguageManager::getInstance().replaceTags(utility::toString("#{", tag, "}"));
//				if (result == tag)
//					return getButtonName(index);
//				return result;
//			}
//
//			const char* getIconName(size_t _index) const
//			{
//				static const size_t CountIcons = 4;
//				static const char* IconNames[CountIcons + 1] = { "Info", "Quest", "Error", "Warning", "" };
//				if (_index >= CountIcons)
//					return IconNames[CountIcons];
//				return IconNames[_index];
//			}
//
//			const char* getButtonName(size_t _index) const
//			{
//				static const size_t Count = 9;
//				static const char * Names[Count + 1] = { "Ok", "Yes", "No", "Abort", "Retry", "Ignore", "Cancel", "Try", "Continue", "" };
//				if (_index >= Count)
//					return Names[Count];
//				return Names[_index];
//			}
//
//			const char* getButtonTag(size_t _index) const
//			{
//				static const size_t Count = 9;
//				static const char* Names[Count + 1] = { "MessageBox_Ok", "MessageBox_Yes", "MessageBox_No", "MessageBox_Abort", "MessageBox_Retry", "MessageBox_Ignore", "MessageBox_Cancel", "MessageBox_Try", "MessageBox_Continue", "" };
//				if (_index >= Count)
//					return Names[Count];
//				return Names[_index];
//			}
//
//		private:
//			Vector<MyGUI::Widget*> mListWindowRoot;
//			Widget* mMainWidget;
//			IntSize mOffsetText;
//			TextBox* mWidgetText;
//
//			std::string mButtonSkin;
//			std::string mButtonType;
//			IntSize mButtonSize;
//			IntSize mButtonOffset;
//
//			std::vector<Button*> mVectorButton;
//			MessageBoxStyle mInfoOk;
//			MessageBoxStyle mInfoCancel;
//			bool mSmoothShow;
//
//			std::string mDefaultCaption;
//			ImageBox* mIcon;
//			int mLeftOffset1;
//			int mLeftOffset2;
//		};
//
//	}
//}