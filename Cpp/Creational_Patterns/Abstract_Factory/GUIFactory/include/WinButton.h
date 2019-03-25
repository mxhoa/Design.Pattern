#include <iostream>
#include "IButton.h"
class WinButton : public IButton
{
public:
	void paint() override
	{
		std::cout << "Window Button\n";
	}
};
