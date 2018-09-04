#include "GUIFactory.h"
#include "include\WinButton.h"
#include "include\WinScrollBar.h"

class WinFactory : public GUIFactory
{
public:
	IButton* createButton()
	{
		return new WinButton;
	}

	IScrollBar* createScrollBar()
	{
		return new WinScrollBar;
	}
};