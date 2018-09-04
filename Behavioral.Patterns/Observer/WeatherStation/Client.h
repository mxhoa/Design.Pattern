#ifndef OBSERVER_PATTERN_CLIENT_1_HPP
#define OBSERVER_PATTERN_CLIENT_1_HPP 

#include <iostream>

#include "Observer.h"


class Client : public Observer
{
private:
    int id;
public:
    Client(int id);
    virtual void update(float temp, float humidity, float pressure) override;
};


#endif 