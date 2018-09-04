#include <iostream>
#include "IScrollBar.h"

class MacScrollbar : public IScrollBar
{
public:
	void paint() override
	{
		std::cout << "Mac ScrollBar\n";
	}
};
