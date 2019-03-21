#ifndef OBSERVER_PATTERN_WEATHER_HPP
#define OBSERVER_PATTERN_WEATHER_HPP

#include <vector>
#include <algorithm>
#include <iostream>

#include "Subject.h"
#include "Observer.h"



class WeatherData : public Subject
{
private:
    /* data */
    std::vector<Observer *> observers;

    float temp = 0.0f;
    float humidity = 0.0f;
    float pressure = 0.0f;
public:
    
    void registerObserver(Observer *observer) override;
    void removeObserver(Observer *observer) override;
    void notifyObservers() override;

    /**
     * @brief Set the new state of the weather station
     * 
     * @param temp      - new temperature
     * @param humidity  - new humidity
     * @param pressure  - new pressure
     */
    void setState(float temp, float humidity, float pressure);
};


#endif