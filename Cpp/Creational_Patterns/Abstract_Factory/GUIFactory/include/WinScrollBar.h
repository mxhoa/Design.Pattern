#include <iostream>
#include "IScrollBar.h"

class WinScrollBar : public IScrollBar
{
public:
	void paint() override
	{
		std::cout << "Win Scrollbar\n";
	}
};
