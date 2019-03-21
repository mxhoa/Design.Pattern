#include "WeatherData.h"

void WeatherData::registerObserver(Observer *observer) 
{
    observers.push_back(observer);
}

void WeatherData::removeObserver(Observer *observer)
{
    // Find the observer
    auto iterator = std::find(observers.begin(), observers.end(), observer);
    if (iterator != observers.end())
    {
        // Remove the observer
        observers.erase(iterator);
    }
}

void WeatherData::notifyObservers()
{
    for (Observer *observer : observers)
    {
        observer->update(temp, humidity, pressure);
    }
}


void WeatherData::setState(float temp, float humidity, float pressure)
{
    this->temp = temp;
    this->humidity = humidity;
    this->pressure = pressure;

    std::cout << std::endl;
    notifyObservers();
}