#include "Singleton.h"
#include <iostream>

Singleton* Singleton::_instance = 0;

Singleton::Singleton()
{
    std::cout << "Singleton Constructor\n";
}
Singleton* Singleton::Instance()
{
    if (_instance == 0)
    {
        std::cout << "Singleton Object - NO INSTANCE\n";
        _instance = new Singleton();
    }
    else
    {
        std::cout << "Singleton Object - EXIST INSTANCE\n";
    }
    
    return _instance;
}


