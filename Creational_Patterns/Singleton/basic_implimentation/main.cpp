#include "Singleton.h"
#include <iostream>

int main()
{
    std::cout << "call singleton 1st\n";
    Singleton* singleton = Singleton::Instance();

    std::cout << "Call singleton 2st\n";
    singleton = Singleton::Instance();
    
    return 0;
}