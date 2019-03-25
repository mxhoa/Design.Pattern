#include "include\IButton.h"
#include "include\IScrollBar.h"

class GUIFactory
{
public:
	virtual IButton* createButton() = 0;
	virtual IScrollBar* createScrollBar() = 0;
};