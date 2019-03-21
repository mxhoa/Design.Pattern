#include <iostream>
#include "IButton.h"

class MacButton : public IButton
{
public:
	void paint() override
	{
		std::cout << "Mac Button\n";
	}
};