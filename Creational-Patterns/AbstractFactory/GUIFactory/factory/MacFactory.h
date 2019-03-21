#include "GUIFactory.h"
#include "include\MacButton.h"
#include "include\MacScrollBar.h"

class MacFactory : public GUIFactory
{
public:
	IButton * createButton()
	{
		return new MacButton;
	}
	IScrollBar* createScrollBar()
	{
		return new MacScrollbar;
	}
};
